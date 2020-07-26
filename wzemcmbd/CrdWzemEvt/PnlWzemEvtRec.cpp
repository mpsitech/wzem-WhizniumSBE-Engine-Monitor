/**
	* \file PnlWzemEvtRec.cpp
	* job handler for job PnlWzemEvtRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemEvtRec.h"

#include "PnlWzemEvtRec_blks.cpp"
#include "PnlWzemEvtRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemEvtRec
 ******************************************************************************/

PnlWzemEvtRec::PnlWzemEvtRec(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMEVTREC, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_PSTEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_PRDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_OPXEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_NDEEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_DCHEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_CLNEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMEVT_CALEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFEVT, jref);
};

PnlWzemEvtRec::~PnlWzemEvtRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemEvtRec::getNewDpchEng(
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

void PnlWzemEvtRec::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubWzem::getStubEvtStd(dbswzem, recEvt.ref, ixWzemVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recEvt.ref == 0) statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzem);

	if (statshr.ixWzemVExpstate == VecWzemVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzemEvtDetail(xchg, dbswzem, jref, ixWzemVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemEvtRec::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFEVT) {
		WzemMEvent* _recEvt = NULL;
		WzemMDpch* _recDch = NULL;

		if (dbswzem->tblwzemmevent->loadRecByRef(xchg->getRefPreset(VecWzemVPreset::PREWZEMREFEVT, jref), &_recEvt)) {
			recEvt = *_recEvt;
			delete _recEvt;
		} else recEvt = WzemMEvent();

		if (dbswzem->tblwzemmdpch->loadRecByRef(recEvt.refWzemMDpch, &_recDch)) {
			recDch = *_recDch;
			delete _recDch;
		} else recDch = WzemMDpch();

		if (recEvt.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
		};

		refresh(dbswzem, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemEvtRec::minimize(
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

void PnlWzemEvtRec::regularize(
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

void PnlWzemEvtRec::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTRECDO) {
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

void PnlWzemEvtRec::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemEvtRec::handleDpchAppDoButMinimizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	minimize(dbswzem, true, dpcheng);
};

void PnlWzemEvtRec::handleDpchAppDoButRegularizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	regularize(dbswzem, true, dpcheng);
};

void PnlWzemEvtRec::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMEVTUPD_REFEQ) {
		call->abort = handleCallWzemEvtUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMDCHUPD_REFEQ) {
		call->abort = handleCallWzemDchUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_PSTEQ) {
		call->abort = handleCallWzemEvt_pstEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_PRDEQ) {
		call->abort = handleCallWzemEvt_prdEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_OPXEQ) {
		call->abort = handleCallWzemEvt_opxEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_NDEEQ) {
		call->abort = handleCallWzemEvt_ndeEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_JOBEQ) {
		call->abort = handleCallWzemEvt_jobEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_DCHEQ) {
		call->abort = handleCallWzemEvt_dchEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_CLUEQ) {
		call->abort = handleCallWzemEvt_cluEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_CLNEQ) {
		call->abort = handleCallWzemEvt_clnEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVT_CALEQ) {
		call->abort = handleCallWzemEvt_calEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemEvtRec::handleCallWzemEvtUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemEvtUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemDchUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemDchUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_pstEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMPreset == refInv); // IP handleCallWzemEvt_pstEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_prdEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMPeriod == refInv); // IP handleCallWzemEvt_prdEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_opxEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMOp == refInv); // IP handleCallWzemEvt_opxEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_ndeEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMNode == refInv); // IP handleCallWzemEvt_ndeEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMJob == refInv); // IP handleCallWzemEvt_jobEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_dchEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMDpch == refInv); // IP handleCallWzemEvt_dchEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_cluEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemCEvent == refInv); // IP handleCallWzemEvt_cluEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_clnEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMClstn == refInv); // IP handleCallWzemEvt_clnEq --- LINE
	return retval;
};

bool PnlWzemEvtRec::handleCallWzemEvt_calEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMCall == refInv); // IP handleCallWzemEvt_calEq --- LINE
	return retval;
};

