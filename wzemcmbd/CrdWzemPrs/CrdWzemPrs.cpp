/**
	* \file CrdWzemPrs.cpp
	* job handler for job CrdWzemPrs (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "CrdWzemPrs.h"

#include "CrdWzemPrs_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzemPrs
 ******************************************************************************/

CrdWzemPrs::CrdWzemPrs(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
			, const ubigint ref
		) :
			JobWzem(xchg, VecWzemVJob::CRDWZEMPRS, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;

	// IP constructor.cust1 --- INSERT

	if ((ref + 1) != 0) xchg->triggerIxRefCall(dbswzem, VecWzemVCall::CALLWZEMREFPRESET, jref, VecWzemVPreset::PREWZEMREFPRS, ref);

	// initialize according to ref
	changeRef(dbswzem, jref, ((ref + 1) == 0) ? 0 : ref, false);

	pnllist = new PnlWzemPrsList(xchg, dbswzem, jref, ixWzemVLocale);
	pnlheadbar = new PnlWzemPrsHeadbar(xchg, dbswzem, jref, ixWzemVLocale);
	pnlrec = new PnlWzemPrsRec(xchg, dbswzem, jref, ixWzemVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefList = pnllist->jref;
	statshr.jrefRec = pnlrec->jref;

	set<uint> moditems;
	refresh(dbswzem, moditems);

	changeStage(dbswzem, VecVSge::IDLE);

	xchg->addClstn(VecWzemVCall::CALLWZEMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzemPrs::~CrdWzemPrs() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* CrdWzemPrs::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void CrdWzemPrs::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzemPrs/" + VecWzemVLocale::getSref(ixWzemVLocale);
	continf.MtxCrdPrs = StubWzem::getStubPrsStd(dbswzem, xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRS, jref), ixWzemVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void CrdWzemPrs::changeRef(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	uint ixWzemVRecaccess;
	xchg->triggerIxRefToIxCall(dbswzem, VecWzemVCall::CALLWZEMRECACCESS, jref, VecWzemVCard::CRDWZEMPRS, ref, ixWzemVRecaccess);

	if (ixWzemVRecaccess != VecWzemVRecaccess::NONE) {
		xchg->addIxPreset(VecWzemVPreset::PREWZEMIXRECACC, jref, ixWzemVRecaccess);

		if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswzem, VecWzemVCall::CALLWZEMLOG, jref, VecWzemVPreset::VOID, 0, "CrdWzemPrs", ref);
		xchg->addRefPreset(VecWzemVPreset::PREWZEMREFPRS, jref, ref);

		if (pnllist) pnllist->updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFPRS, jrefTrig, notif);
		if (pnlrec) pnlrec->updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFPRS, jrefTrig, notif);

		refresh(dbswzem, moditems);
		if (notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void CrdWzemPrs::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzemPrs::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzem, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMALERT) {
			handleDpchAppWzemAlert(dbswzem, (DpchAppWzemAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzemPrs::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzemPrs::handleDpchAppDoClose(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzemConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzem, VecWzemVCall::CALLWZEMCRDCLOSE, jref, VecWzemVCard::CRDWZEMPRS);
};

void CrdWzemPrs::handleDpchAppDoMitAppAbtClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzem, VecVSge::ALRWZEMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzemPrs::handleDpchAppWzemAlert(
			DbsWzem* dbswzem
			, DpchAppWzemAlert* dpchappwzemalert
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppWzemAlert --- BEGIN
	if (ixVSge == VecVSge::ALRWZEMABT) {
		changeStage(dbswzem, nextIxVSgeSuccess);
	};

	*dpcheng = new DpchEngWzemConfirm(true, jref, "");
	// IP handleDpchAppWzemAlert --- END
};

void CrdWzemPrs::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMREFPRESET) {
		call->abort = handleCallWzemRefPreSet(dbswzem, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMSTATCHG) {
		call->abort = handleCallWzemStatChg(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMDLGCLOSE) {
		call->abort = handleCallWzemDlgClose(dbswzem, call->jref);
	};
};

bool CrdWzemPrs::handleCallWzemRefPreSet(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzemVPreset::PREWZEMREFPRS) {
		changeRef(dbswzem, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswzem, true);
	};

	return retval;
};

bool CrdWzemPrs::handleCallWzemStatChg(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWzemVExpstate == VecWzemVExpstate::REGD) && (pnlrec->statshr.ixWzemVExpstate == VecWzemVExpstate::REGD)) pnllist->minimize(dbswzem, true);
	return retval;
};

bool CrdWzemPrs::handleCallWzemDlgClose(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemDlgClose --- INSERT
	return retval;
};

void CrdWzemPrs::changeStage(
			DbsWzem* dbswzem
			, uint _ixVSge
			, DpchEngWzem** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzem); break;
				case VecVSge::ALRWZEMABT: leaveSgeAlrwzemabt(dbswzem); break;
			};

			setStage(dbswzem, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswzem, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzem, reenter); break;
			case VecVSge::ALRWZEMABT: _ixVSge = enterSgeAlrwzemabt(dbswzem, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWzemPrs::getSquawk(
			DbsWzem* dbswzem
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzemPrs::enterSgeIdle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzemPrs::leaveSgeIdle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzemPrs::enterSgeAlrwzemabt(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZEMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzem::prepareAlrAbt(jref, ixWzemVLocale, feedFMcbAlert)); // IP enterSgeAlrwzemabt --- LINE

	return retval;
};

void CrdWzemPrs::leaveSgeAlrwzemabt(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeAlrwzemabt --- INSERT
};







