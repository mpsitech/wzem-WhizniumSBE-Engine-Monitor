/**
	* \file WzemcmbdJobprc.cpp
	* job processor for Wzem combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "Wzemcmbd.h"

#include "WzemcmbdJobprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzemcmbdJobprc
 ******************************************************************************/

void* WzemcmbdJobprc::run(
			void* arg
		) {
	XchgWzemcmbd* xchg = (XchgWzemcmbd*) arg;

	ReqWzem* req = NULL;
	JobWzem* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWzem dbswzem;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswzem.init(xchg->stgwzemdatabase.ixDbsVDbstype, xchg->stgwzemdatabase.dbspath, xchg->stgwzemdatabase.dbsname, xchg->stgwzemdatabase.ip,
						xchg->stgwzemdatabase.port, xchg->stgwzemdatabase.username, xchg->stgwzemdatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WzemcmbdJobprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WzemcmbdJobprc", "run");

	try {
		// main loop: wait for requests
		while (true) {
			xchg->cJobprcs.lockMutex("WzemcmbdJobprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cJobprcs.wait("WzemcmbdJobprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cJobprcs.unlockMutex("WzemcmbdJobprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cJobprcs.signal("WzemcmbdJobprc", "run");

			// --- handle request
			if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
				xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

				// pass on to job
				accessJob(xchg, &dbswzem, req);

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
				if (req->dpchapp) {
					//cout << "WzemcmbdJobprc::run() DPCHAPP request:'" << VecWzemVDpch::getSref(req->dpchapp->ixWzemVDpch) << "'" << endl;
					eref = xchg->mon.eventHandleReqDpchapp(req->jref, VecWzemVDpch::getSref(req->dpchapp->ixWzemVDpch), req->dpchapp->getSrefsMask(), "");

					// pass on to job
					accessJob(xchg, &dbswzem, req);
				};

				if (!req->dpcheng) req->dpcheng = new DpchEngWzemAck(req->jref);
				xchg->mon.eventReplyReqDpchapp(eref, req->jref, VecWzemVDpch::getSref(req->dpcheng->ixWzemVDpch), req->dpcheng->getSrefsMask(), "");

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::UPLOAD) {
				//cout << "WzemcmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
				xchg->mon.eventHandleReqUpload(req->jref, req->filename);

				// pass on to job
				accessJob(xchg, &dbswzem, req);

				// usually the job leaves req unchanged

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DOWNLOAD) {
				eref = xchg->mon.eventHandleReqDownload(req->jref);

				// pass on to job
				accessJob(xchg, &dbswzem, req);

				xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHRET) {
				if (req->dpchret) {
					//cout << "WzemcmbdJobprc::run() DPCHRET request: '" << VecWzemVDpch::getSref(req->dpchret->ixWzemVDpch) << "'" << endl;

					job = xchg->getJobByJref(req->jref);
					if (job) job->removeOp(req->dpchret->oref);

					xchg->mon.eventHandleReqDpchret(req->jref, VecWzemVDpch::getSref(req->dpchret->ixWzemVDpch), "", req->dpchret->oref);

					accessJob(xchg, &dbswzem, req);
				};

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::METHOD) {
				if (req->method) {
					//cout << "WzemcmbdJobprc::run() METHOD request: '" << VecWzemVFeatgroup::getSref(req->method->ixVFeatgroup) << "." << req->method->srefIxVMethod << "'" << endl;
					xchg->mon.eventHandleReqMethod(req->jref, VecWzemVFeatgroup::getSref(req->method->ixVFeatgroup), req->method->srefIxVMethod);

					// pass on to job
					accessJob(xchg, &dbswzem, req);
				};

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::TIMER) {
				// pass on to job
				job = xchg->getJobByJref(req->jref);

				if (job) if (req->wref >= job->wrefMin) {
					xchg->mon.eventHandleReqTimer(req->jref, req->sref);
					accessJob(xchg, &dbswzem, req);
				};

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::EXTCALL) {
				xchg->triggerCall(&dbswzem, req->call);
			};

			if ((req->ixVBasetype == ReqWzem::VecVBasetype::DPCHRET) || (req->ixVBasetype == ReqWzem::VecVBasetype::TIMER) || (req->ixVBasetype == ReqWzem::VecVBasetype::EXTCALL)) {
				// ret, timer and extcall requests can be deleted here
				delete req;

			} else {
				// all other requests are being waited for for further processing
				if (!(req->retain)) req->setStateReply();
			};
		};

	} catch (WzemException& e) {
		cout << e.getSquawk(VecWzemVError::getIx, VecWzemVError::getTitle, VecWzemVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWzemVError::getIx, VecWzemVError::getTitle, VecWzemVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void WzemcmbdJobprc::cleanup(
			void* arg
		) {
	XchgWzemcmbd* xchg = (XchgWzemcmbd*) arg;

	xchg->cJobprcs.unlockMutex("WzemcmbdJobprc", "cleanup");
};

void WzemcmbdJobprc::accessJob(
			XchgWzemcmbd* xchg
			, DbsWzem* dbswzem
			, ReqWzem* req
		) {
	JobWzem* job = NULL;
	
	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("WzemcmbdJobprc", "accessJob");

		req->ixWzemVLocale = job->ixWzemVLocale;
		job->handleRequest(dbswzem, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("WzemcmbdJobprc", "accessJob");
	};
};
