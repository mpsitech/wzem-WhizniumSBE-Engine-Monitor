/**
	* \file PnlWzemOpxRec.cpp
	* job handler for job PnlWzemOpxRec (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemOpxRec.h"

#include "PnlWzemOpxRec_blks.cpp"
#include "PnlWzemOpxRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemOpxRec
 ******************************************************************************/

PnlWzemOpxRec::PnlWzemOpxRec(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMOPXREC, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMOPX_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFOPX, jref);
};

PnlWzemOpxRec::~PnlWzemOpxRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemOpxRec::getNewDpchEng(
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

void PnlWzemOpxRec::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWzem::getStubOpxStd(dbswzem, recOpx.ref, ixWzemVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recOpx.ref == 0) statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzem);

	if (statshr.ixWzemVExpstate == VecWzemVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzemOpxDetail(xchg, dbswzem, jref, ixWzemVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzemOpxRec::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFOPX) {
		WzemMOp* _recOpx = NULL;

		if (dbswzem->tblwzemmop->loadRecByRef(xchg->getRefPreset(VecWzemVPreset::PREWZEMREFOPX, jref), &_recOpx)) {
			recOpx = *_recOpx;
			delete _recOpx;
		} else recOpx = WzemMOp();

		if (recOpx.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
		};

		refresh(dbswzem, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemOpxRec::minimize(
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

void PnlWzemOpxRec::regularize(
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

void PnlWzemOpxRec::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXRECDO) {
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

void PnlWzemOpxRec::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemOpxRec::handleDpchAppDoButMinimizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	minimize(dbswzem, true, dpcheng);
};

void PnlWzemOpxRec::handleDpchAppDoButRegularizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	regularize(dbswzem, true, dpcheng);
};

void PnlWzemOpxRec::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMOPXUPD_REFEQ) {
		call->abort = handleCallWzemOpxUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMOPX_JOBEQ) {
		call->abort = handleCallWzemOpx_jobEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemOpxRec::handleCallWzemOpxUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemOpxUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemOpxRec::handleCallWzemOpx_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpx.refWzemMJob == refInv); // IP handleCallWzemOpx_jobEq --- LINE
	return retval;
};

