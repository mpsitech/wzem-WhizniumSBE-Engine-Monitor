/**
	* \file PnlWzemPrdRec.cpp
	* job handler for job PnlWzemPrdRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemPrdRec.h"

#include "PnlWzemPrdRec_blks.cpp"
#include "PnlWzemPrdRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemPrdRec
 ******************************************************************************/

PnlWzemPrdRec::PnlWzemPrdRec(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMPRDREC, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	pnl1nevent = NULL;
	pnl1nnode = NULL;
	pnl1njob = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFPRD, jref);
};

PnlWzemPrdRec::~PnlWzemPrdRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemPrdRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemPrdRec::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWzem::getStubPrdStd(dbswzem, recPrd.ref, ixWzemVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recPrd.ref == 0) statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzem);

	if (statshr.ixWzemVExpstate == VecWzemVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1njob) {delete pnl1njob; pnl1njob = NULL;};
		if (pnl1nnode) {delete pnl1nnode; pnl1nnode = NULL;};
		if (pnl1nevent) {delete pnl1nevent; pnl1nevent = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzemPrdDetail(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1njob) pnl1njob = new PnlWzemPrd1NJob(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1nnode) pnl1nnode = new PnlWzemPrd1NNode(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1nevent) pnl1nevent = new PnlWzemPrd1NEvent(xchg, dbswzem, jref, ixWzemVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NJob = ((pnl1njob) ? pnl1njob->jref : 0);
	statshr.jref1NNode = ((pnl1nnode) ? pnl1nnode->jref : 0);
	statshr.jref1NEvent = ((pnl1nevent) ? pnl1nevent->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemPrdRec::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFPRD) {
		WzemMPeriod* _recPrd = NULL;

		if (dbswzem->tblwzemmperiod->loadRecByRef(xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref), &_recPrd)) {
			recPrd = *_recPrd;
			delete _recPrd;
		} else recPrd = WzemMPeriod();

		if (recPrd.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1njob) pnl1njob->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1nnode) pnl1nnode->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1nevent) pnl1nevent->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
		};

		refresh(dbswzem, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemPrdRec::minimize(
			DbsWzem* dbswzem
			, const bool notif
			, DpchEngWzem** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWzemVExpstate != VecWzemVExpstate::MIND) {
		statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswzem, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWzemPrdRec::regularize(
			DbsWzem* dbswzem
			, const bool notif
			, DpchEngWzem** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWzemVExpstate != VecWzemVExpstate::REGD) {
		statshr.ixWzemVExpstate = VecWzemVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbswzem, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWzemPrdRec::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
	if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMINIT) {
			handleDpchAppWzemInit(dbswzem, (DpchAppWzemInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemPrdRec::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemPrdRec::handleDpchAppDoButMinimizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	minimize(dbswzem, true, dpcheng);
};

void PnlWzemPrdRec::handleDpchAppDoButRegularizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	regularize(dbswzem, true, dpcheng);
};

void PnlWzemPrdRec::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMPRDUPD_REFEQ) {
		call->abort = handleCallWzemPrdUpd_refEq(dbswzem, call->jref);
	};
};

bool PnlWzemPrdRec::handleCallWzemPrdUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemPrdUpd_refEq --- INSERT
	return retval;
};

