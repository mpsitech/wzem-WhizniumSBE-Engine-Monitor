/**
	* \file PnlWzemUsrRec.cpp
	* job handler for job PnlWzemUsrRec (implementation)
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

#include "PnlWzemUsrRec.h"

#include "PnlWzemUsrRec_blks.cpp"
#include "PnlWzemUsrRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemUsrRec
 ******************************************************************************/

PnlWzemUsrRec::PnlWzemUsrRec(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMUSRREC, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	pnlmnusergroup = NULL;
	pnl1nsession = NULL;
	pnlaaccess = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFUSR, jref);
};

PnlWzemUsrRec::~PnlWzemUsrRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemUsrRec::getNewDpchEng(
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

void PnlWzemUsrRec::refresh(
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
	continf.TxtRef = StubWzem::getStubUsrStd(dbswzem, recUsr.ref, ixWzemVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recUsr.ref == 0) statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzem);

	if (statshr.ixWzemVExpstate == VecWzemVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlaaccess) {delete pnlaaccess; pnlaaccess = NULL;};
		if (pnl1nsession) {delete pnl1nsession; pnl1nsession = NULL;};
		if (pnlmnusergroup) {delete pnlmnusergroup; pnlmnusergroup = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzemUsrDetail(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnlaaccess) pnlaaccess = new PnlWzemUsrAAccess(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1nsession) pnl1nsession = new PnlWzemUsr1NSession(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnlmnusergroup) pnlmnusergroup = new PnlWzemUsrMNUsergroup(xchg, dbswzem, jref, ixWzemVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefAAccess = ((pnlaaccess) ? pnlaaccess->jref : 0);
	statshr.jref1NSession = ((pnl1nsession) ? pnl1nsession->jref : 0);
	statshr.jrefMNUsergroup = ((pnlmnusergroup) ? pnlmnusergroup->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzemUsrRec::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFUSR) {
		WzemMUser* _recUsr = NULL;

		if (dbswzem->tblwzemmuser->loadRecByRef(xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSR, jref), &_recUsr)) {
			recUsr = *_recUsr;
			delete _recUsr;
		} else recUsr = WzemMUser();

		if (recUsr.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnlaaccess) pnlaaccess->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1nsession) pnl1nsession->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnlmnusergroup) pnlmnusergroup->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
		};

		refresh(dbswzem, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemUsrRec::minimize(
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

void PnlWzemUsrRec::regularize(
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

void PnlWzemUsrRec::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRRECDO) {
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

void PnlWzemUsrRec::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemUsrRec::handleDpchAppDoButMinimizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	minimize(dbswzem, true, dpcheng);
};

void PnlWzemUsrRec::handleDpchAppDoButRegularizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	regularize(dbswzem, true, dpcheng);
};

void PnlWzemUsrRec::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSRUPD_REFEQ) {
		call->abort = handleCallWzemUsrUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSR_PRSEQ) {
		call->abort = handleCallWzemUsr_prsEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSR_USGEQ) {
		call->abort = handleCallWzemUsr_usgEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemUsrRec::handleCallWzemUsrUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemUsrRec::handleCallWzemUsr_prsEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWzemMPerson == refInv); // IP handleCallWzemUsr_prsEq --- LINE
	return retval;
};

bool PnlWzemUsrRec::handleCallWzemUsr_usgEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWzemMUsergroup == refInv); // IP handleCallWzemUsr_usgEq --- LINE
	return retval;
};
