/**
	* \file CrdWzemNav.cpp
	* job handler for job CrdWzemNav (implementation)
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

#include "CrdWzemNav.h"

#include "CrdWzemNav_blks.cpp"
#include "CrdWzemNav_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class CrdWzemNav
 ******************************************************************************/

CrdWzemNav::CrdWzemNav(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::CRDWZEMNAV, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	pnlmon = NULL;
	pnladmin = NULL;
	pnlpre = NULL;
	pnlheadbar = NULL;
	dlgloaini = NULL;

	// IP constructor.cust1 --- INSERT

	set<uint> moditems;
	refresh(dbswzem, moditems);

	pnlmon = new PnlWzemNavMon(xchg, dbswzem, jref, ixWzemVLocale);
	pnladmin = new PnlWzemNavAdmin(xchg, dbswzem, jref, ixWzemVLocale);
	pnlpre = new PnlWzemNavPre(xchg, dbswzem, jref, ixWzemVLocale);
	pnlheadbar = new PnlWzemNavHeadbar(xchg, dbswzem, jref, ixWzemVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefHeadbar = pnlheadbar->jref;
	statshr.jrefPre = pnlpre->jref;
	statshr.jrefAdmin = pnladmin->jref;
	statshr.jrefMon = pnlmon->jref;

	changeStage(dbswzem, VecVSge::IDLE);

	xchg->addClstn(VecWzemVCall::CALLWZEMDLGCLOSE, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

CrdWzemNav::~CrdWzemNav() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* CrdWzemNav::getNewDpchEng(
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

void CrdWzemNav::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	string s;
	vector<string> ss;

	// continf
	continf.MrlAppHlp = xchg->helpurl + "/CrdWzemNav/" + VecWzemVLocale::getSref(ixWzemVLocale);

	s = StubWzem::getStubSesMenu(dbswzem, xchg->getRefPreset(VecWzemVPreset::PREWZEMSESS, jref), ixWzemVLocale, Stub::VecVNonetype::DASH);
	StrMod::stringToVector(s, ss);

	if (ss.size() == 3) {
		continf.MtxSesSes1 = ss[0];
		continf.MtxSesSes2 = ss[1];
		continf.MtxSesSes3 = ss[2];
	};

	// statshr
	statshr.pnlpreAvail = evalPnlpreAvail(dbswzem);
	statshr.pnladminAvail = evalPnladminAvail(dbswzem);
	statshr.pnlmonAvail = evalPnlmonAvail(dbswzem);
	statshr.MitSesSpsAvail = evalMitSesSpsAvail(dbswzem);
	statshr.MspCrd1Avail = evalMspCrd1Avail(dbswzem);
	statshr.MitCrdUsgAvail = evalMitCrdUsgAvail(dbswzem);
	statshr.MitCrdUsrAvail = evalMitCrdUsrAvail(dbswzem);
	statshr.MitCrdPrsAvail = evalMitCrdPrsAvail(dbswzem);
	statshr.MspCrd2Avail = evalMspCrd2Avail(dbswzem);
	statshr.MitCrdPrdAvail = evalMitCrdPrdAvail(dbswzem);
	statshr.MitCrdEvtAvail = evalMitCrdEvtAvail(dbswzem);
	statshr.MitCrdJobAvail = evalMitCrdJobAvail(dbswzem);
	statshr.MitCrdCalAvail = evalMitCrdCalAvail(dbswzem);
	statshr.MitCrdClnAvail = evalMitCrdClnAvail(dbswzem);
	statshr.MitCrdOpxAvail = evalMitCrdOpxAvail(dbswzem);
	statshr.MitCrdPstAvail = evalMitCrdPstAvail(dbswzem);
	statshr.MitCrdNdeAvail = evalMitCrdNdeAvail(dbswzem);
	statshr.MspApp2Avail = evalMspApp2Avail(dbswzem);
	statshr.MitAppLoiAvail = evalMitAppLoiAvail(dbswzem);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void CrdWzemNav::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzem, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	if (pnlpre) if (jrefTrig != pnlpre->jref) pnlpre->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
	if (pnladmin) pnladmin->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
	if (pnlmon) pnlmon->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
	// IP updatePreset --- END
};

void CrdWzemNav::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::CLOSE) {
					handleDpchAppDoClose(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPABTCLICK) {
					handleDpchAppDoMitAppAbtClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESSPSCLICK) {
					handleDpchAppDoMitSesSpsClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITSESTRMCLICK) {
					handleDpchAppDoMitSesTrmClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSGCLICK) {
					handleDpchAppDoMitCrdUsgClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDUSRCLICK) {
					handleDpchAppDoMitCrdUsrClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRSCLICK) {
					handleDpchAppDoMitCrdPrsClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPRDCLICK) {
					handleDpchAppDoMitCrdPrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDEVTCLICK) {
					handleDpchAppDoMitCrdEvtClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDJOBCLICK) {
					handleDpchAppDoMitCrdJobClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCALCLICK) {
					handleDpchAppDoMitCrdCalClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDCLNCLICK) {
					handleDpchAppDoMitCrdClnClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDOPXCLICK) {
					handleDpchAppDoMitCrdOpxClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDPSTCLICK) {
					handleDpchAppDoMitCrdPstClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITCRDNDECLICK) {
					handleDpchAppDoMitCrdNdeClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::MITAPPLOICLICK) {
					handleDpchAppDoMitAppLoiClick(dbswzem, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMALERT) {
			handleDpchAppWzemAlert(dbswzem, (DpchAppWzemAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void CrdWzemNav::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void CrdWzemNav::handleDpchAppDoClose(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzemConfirm(true, jref, "");

	if (xchg->stgwzemappearance.suspsess) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSUSPSESS, xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref));
	else xchg->triggerBoolvalCall(dbswzem, VecWzemVCall::CALLWZEMLOGOUT, xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref), false);
};

void CrdWzemNav::handleDpchAppDoMitAppAbtClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoMitAppAbtClick --- BEGIN
	changeStage(dbswzem, VecVSge::ALRWZEMABT, dpcheng);
	// IP handleDpchAppDoMitAppAbtClick --- END
};

void CrdWzemNav::handleDpchAppDoMitSesSpsClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzemConfirm(true, jref, "");

	xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSUSPSESS, xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref));
};

void CrdWzemNav::handleDpchAppDoMitSesTrmClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	muteRefresh = true;

	*dpcheng = new DpchEngWzemConfirm(true, jref, "");

	xchg->triggerBoolvalCall(dbswzem, VecWzemVCall::CALLWZEMLOGOUT, xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref), false);
};

void CrdWzemNav::handleDpchAppDoMitCrdUsgClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemUsg");
};

void CrdWzemNav::handleDpchAppDoMitCrdUsrClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemUsr");
};

void CrdWzemNav::handleDpchAppDoMitCrdPrsClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPrs");
};

void CrdWzemNav::handleDpchAppDoMitCrdPrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemPrd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPrd");
};

void CrdWzemNav::handleDpchAppDoMitCrdEvtClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemEvt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemEvt");
};

void CrdWzemNav::handleDpchAppDoMitCrdJobClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemJob", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemJob");
};

void CrdWzemNav::handleDpchAppDoMitCrdCalClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemCal", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemCal");
};

void CrdWzemNav::handleDpchAppDoMitCrdClnClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemCln", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemCln");
};

void CrdWzemNav::handleDpchAppDoMitCrdOpxClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemOpx", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemOpx");
};

void CrdWzemNav::handleDpchAppDoMitCrdPstClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemPst", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPst");
};

void CrdWzemNav::handleDpchAppDoMitCrdNdeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemNde", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemNde");
};

void CrdWzemNav::handleDpchAppDoMitAppLoiClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	if (!dlgloaini) {
		dlgloaini = new DlgWzemNavLoaini(xchg, dbswzem, jref, ixWzemVLocale);
		statshr.jrefDlgloaini = dlgloaini->jref;

		*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	};
};

void CrdWzemNav::handleDpchAppWzemAlert(
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

void CrdWzemNav::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMDLGCLOSE) {
		call->abort = handleCallWzemDlgClose(dbswzem, call->jref);
	};
};

bool CrdWzemNav::handleCallWzemDlgClose(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (dlgloaini) {
		delete dlgloaini;
		dlgloaini = NULL;
		statshr.jrefDlgloaini = 0;

		xchg->submitDpch(getNewDpchEng({DpchEngData::STATSHR}));
	};

	return retval;
};

void CrdWzemNav::changeStage(
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

string CrdWzemNav::getSquawk(
			DbsWzem* dbswzem
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint CrdWzemNav::enterSgeIdle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void CrdWzemNav::leaveSgeIdle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeIdle --- INSERT
};

uint CrdWzemNav::enterSgeAlrwzemabt(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZEMABT;
	nextIxVSgeSuccess = VecVSge::IDLE;

	xchg->submitDpch(AlrWzem::prepareAlrAbt(jref, ixWzemVLocale, feedFMcbAlert)); // IP enterSgeAlrwzemabt --- LINE

	return retval;
};

void CrdWzemNav::leaveSgeAlrwzemabt(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeAlrwzemabt --- INSERT
};

