/**
	* \file WzemcmbdOpprc.cpp
	* operation processor for Wzem combined daemon (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "Wzemcmbd.h"

#include "WzemcmbdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzemcmbdOpprc
 ******************************************************************************/

void* WzemcmbdOpprc::run(
			void* arg
		) {
	XchgWzemcmbd* xchg = (XchgWzemcmbd*) arg;

	ReqWzem* req = NULL;
	DpchInvWzem* inv = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWzem dbswzem;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswzem.init(xchg->stgwzemdatabase.ixDbsVDbstype, xchg->stgwzemdatabase.dbspath, xchg->stgwzemdatabase.dbsname, xchg->stgwzemdatabase.ip
						, xchg->stgwzemdatabase.port, xchg->stgwzemdatabase.username, xchg->stgwzemdatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WzemcmbdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WzemcmbdOpprc", "run");

	try {
		// main loop: wait for operation invocations
		while (true) {
			xchg->cOpprcs.lockMutex("WzemcmbdOpprc", "run");
			inv = xchg->pullFirstInv();

			while (!inv) {
				xchg->cOpprcs.wait("WzemcmbdOpprc", "run");
				inv = xchg->pullFirstInv();
			};

			xchg->cOpprcs.unlockMutex("WzemcmbdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("WzemcmbdOpprc", "run");

			// prepare request
			req = new ReqWzem(ReqWzem::VecVBasetype::DPCHRET);

			req->jref = inv->jref;
			req->dpchinv = inv;

			// perform op

			if (req->dpchret) {
				req->dpchret->oref = req->dpchinv->oref;
				req->dpchret->jref = req->dpchinv->jref;

				xchg->addReq(req);

			} else {
				delete req;
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

void WzemcmbdOpprc::cleanup(
			void* arg
		) {
	XchgWzemcmbd* xchg = (XchgWzemcmbd*) arg;

	xchg->cOpprcs.unlockMutex("WzemcmbdOpprc", "cleanup");
};

