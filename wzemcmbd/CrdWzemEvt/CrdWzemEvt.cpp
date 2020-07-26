/**
	* \file CrdWzemEvt.cpp
	* job handler for job CrdWzemEvt (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "CrdWzemEvt.h"

#include "CrdWzemEvt_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzemEvt
 ******************************************************************************/

CrdWzemEvt::CrdWzemEvt(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
			, const ubigint ref
		) :
			JobWzem(xchg, VecWzemVJob::CRDWZEMEVT, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnllist = NULL;
	pnlheadbar = NULL;
	pnlrec = NULL;

	// IP constructor.cust1 --- INSERT

	// initialize according to ref
	changeRef(dbswzem, jref, ((ref+1) == 0) ? 0 : ref, false);

	pnllist = new PnlWzemEvtList(xchg, dbswzem, jref, ixWzemVLocale);
	pnlheadbar = new PnlWzemEvtHeadbar(xchg, dbswzem, jref, ixWzemVLocale);
	pnlrec = new PnlWzemEvtRec(xchg, dbswzem, jref, ixWzemVLocale);

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

CrdWzemEvt::~CrdWzemEvt() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* CrdWzemEvt::getNewDpchEng(
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

void CrdWzemEvt::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzemEvt/" + VecWzemVLocale::getSref(ixWzemVLocale);
	continf.MtxCrdEvt = StubWzem::getStubEvtStd(dbswzem, xchg->getRefPreset(VecWzemVPreset::PREWZEMREFEVT, jref), ixWzemVLocale, Stub::VecVNonetype::FULL);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void CrdWzemEvt::changeRef(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint ref
			, const bool notif
		) {
	set<uint> moditems;

	WzemMEvent* rec = NULL;

	if (ref != 0) xchg->triggerIxRefSrefIntvalCall(dbswzem, VecWzemVCall::CALLWZEMLOG, jref, VecWzemVPreset::VOID, 0, "CrdWzemEvt", ref);
	xchg->addRefPreset(VecWzemVPreset::PREWZEMREFEVT, jref, ref);

	if (dbswzem->tblwzemmevent->loadRecByRef(ref, &rec)) {
		xchg->addRefPreset(VecWzemVPreset::PREWZEMREFDCH, jref, rec->refWzemMDpch);

		delete rec;
	};

	if (pnllist) pnllist->updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFEVT, jrefTrig, notif);
	if (pnlrec) pnlrec->updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFEVT, jrefTrig, notif);

	refresh(dbswzem, moditems);
	if (notif) xchg->submitDpch(getNewDpchEng(moditems));
};

void CrdWzemEvt::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- INSERT
};

void CrdWzemEvt::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDO) {
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

void CrdWzemEvt::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzemEvt::handleDpchAppDoClose(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzemConfirm(true, jref, "");
	xchg->triggerIxCall(dbswzem, VecWzemVCall::CALLWZEMCRDCLOSE, jref, VecWzemVCard::CRDWZEMEVT);
};

void CrdWzemEvt::handleDpchAppDoMitAppAbtClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzem, VecVSge::ALRWZEMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzemEvt::handleDpchAppWzemAlert(
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

void CrdWzemEvt::handleCall(
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

bool CrdWzemEvt::handleCallWzemRefPreSet(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzemVPreset::PREWZEMREFEVT) {
		changeRef(dbswzem, jrefTrig, refInv, true);

		if (refInv == 0) pnlrec->minimize(dbswzem, true);
	};

	return retval;
};

bool CrdWzemEvt::handleCallWzemStatChg(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	if (jrefTrig == pnlrec->jref) if ((pnllist->statshr.ixWzemVExpstate == VecWzemVExpstate::REGD) && (pnlrec->statshr.ixWzemVExpstate == VecWzemVExpstate::REGD)) pnllist->minimize(dbswzem, true);
	return retval;
};

bool CrdWzemEvt::handleCallWzemDlgClose(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemDlgClose --- INSERT
	return retval;
};

void CrdWzemEvt::changeStage(
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
			if (!muteRefresh) refreshWithDpchEng(dbswzem, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzem, reenter); break;
			case VecVSge::ALRWZEMABT: _ixVSge = enterSgeAlrwzemabt(dbswzem, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string CrdWzemEvt::getSquawk(
			DbsWzem* dbswzem
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzemEvt::enterSgeIdle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzemEvt::leaveSgeIdle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzemEvt::enterSgeAlrwzemabt(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZEMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzem::prepareAlrAbt(jref, ixWzemVLocale, feedFMcbAlert)); // IP enterSgeAlrwzemabt --- LINE

	return retval;
};

void CrdWzemEvt::leaveSgeAlrwzemabt(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeAlrwzemabt --- INSERT
};

