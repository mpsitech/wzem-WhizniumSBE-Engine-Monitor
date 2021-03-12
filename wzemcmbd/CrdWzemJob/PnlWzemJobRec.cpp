/**
	* \file PnlWzemJobRec.cpp
	* job handler for job PnlWzemJobRec (implementation)
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

#include "PnlWzemJobRec.h"

#include "PnlWzemJobRec_blks.cpp"
#include "PnlWzemJobRec_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemJobRec
 ******************************************************************************/

PnlWzemJobRec::PnlWzemJobRec(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMJOBREC, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	pnlsup1njob = NULL;
	pnl1nop = NULL;
	pnl1npreset = NULL;
	pnl1ncall = NULL;
	pnl1nclstn = NULL;
	pnldetail = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMJOB_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMJOB_PRDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFJOB, jref);
};

PnlWzemJobRec::~PnlWzemJobRec() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemJobRec::getNewDpchEng(
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

void PnlWzemJobRec::refresh(
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
	continf.TxtRef = StubWzem::getStubJobStd(dbswzem, recJob.ref, ixWzemVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recJob.ref == 0) statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;

	statshr.ButRegularizeActive = evalButRegularizeActive(dbswzem);

	if (statshr.ixWzemVExpstate == VecWzemVExpstate::MIND) {
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnl1nclstn) {delete pnl1nclstn; pnl1nclstn = NULL;};
		if (pnl1npreset) {delete pnl1npreset; pnl1npreset = NULL;};
		if (pnl1ncall) {delete pnl1ncall; pnl1ncall = NULL;};
		if (pnl1nop) {delete pnl1nop; pnl1nop = NULL;};
		if (pnlsup1njob) {delete pnlsup1njob; pnlsup1njob = NULL;};
	} else {
		if (!pnldetail) pnldetail = new PnlWzemJobDetail(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1nclstn) pnl1nclstn = new PnlWzemJob1NClstn(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1npreset) pnl1npreset = new PnlWzemJob1NPreset(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1ncall) pnl1ncall = new PnlWzemJob1NCall(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnl1nop) pnl1nop = new PnlWzemJob1NOp(xchg, dbswzem, jref, ixWzemVLocale);
		if (!pnlsup1njob) pnlsup1njob = new PnlWzemJobSup1NJob(xchg, dbswzem, jref, ixWzemVLocale);
	};

	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jref1NClstn = ((pnl1nclstn) ? pnl1nclstn->jref : 0);
	statshr.jref1NPreset = ((pnl1npreset) ? pnl1npreset->jref : 0);
	statshr.jref1NCall = ((pnl1ncall) ? pnl1ncall->jref : 0);
	statshr.jref1NOp = ((pnl1nop) ? pnl1nop->jref : 0);
	statshr.jrefSup1NJob = ((pnlsup1njob) ? pnlsup1njob->jref : 0);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzemJobRec::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFJOB) {
		WzemMJob* _recJob = NULL;

		if (dbswzem->tblwzemmjob->loadRecByRef(xchg->getRefPreset(VecWzemVPreset::PREWZEMREFJOB, jref), &_recJob)) {
			recJob = *_recJob;
			delete _recJob;
		} else recJob = WzemMJob();

		if (recJob.ref != 0) {
			if (pnldetail) pnldetail->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1nclstn) pnl1nclstn->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1npreset) pnl1npreset->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1ncall) pnl1ncall->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnl1nop) pnl1nop->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
			if (pnlsup1njob) pnlsup1njob->updatePreset(dbswzem, ixWzemVPreset, jrefTrig, notif);
		};

		refresh(dbswzem, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemJobRec::minimize(
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

void PnlWzemJobRec::regularize(
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

void PnlWzemJobRec::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBRECDO) {
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

void PnlWzemJobRec::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemJobRec::handleDpchAppDoButMinimizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	minimize(dbswzem, true, dpcheng);
};

void PnlWzemJobRec::handleDpchAppDoButRegularizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	regularize(dbswzem, true, dpcheng);
};

void PnlWzemJobRec::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMJOBUPD_REFEQ) {
		call->abort = handleCallWzemJobUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOB_SUPEQ) {
		call->abort = handleCallWzemJob_supEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOB_PRDEQ) {
		call->abort = handleCallWzemJob_prdEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemJobRec::handleCallWzemJobUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemJobUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemJobRec::handleCallWzemJob_supEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.supRefWzemMJob == refInv); // IP handleCallWzemJob_supEq --- LINE
	return retval;
};

bool PnlWzemJobRec::handleCallWzemJob_prdEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.refWzemMPeriod == refInv); // IP handleCallWzemJob_prdEq --- LINE
	return retval;
};
