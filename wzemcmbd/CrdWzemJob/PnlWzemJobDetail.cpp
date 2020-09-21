/**
	* \file PnlWzemJobDetail.cpp
	* job handler for job PnlWzemJobDetail (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemJobDetail.h"

#include "PnlWzemJobDetail_blks.cpp"
#include "PnlWzemJobDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemJobDetail
 ******************************************************************************/

PnlWzemJobDetail::PnlWzemJobDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMJOBDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMJOB_SUPEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMJOB_PRDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFJOB, jref);
};

PnlWzemJobDetail::~PnlWzemJobDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemJobDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemJobDetail::refreshRecJob(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMJob* _recJob = NULL;

	if (dbswzem->tblwzemmjob->loadRecByRef(recJob.ref, &_recJob)) {
		recJob = *_recJob;
		delete _recJob;
	} else recJob = WzemMJob();

	dirty = false;

	continf.TxtPrd = StubWzem::getStubPrdStd(dbswzem, recJob.refWzemMPeriod, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfJob = recJob.srefIxVJob;
	contiac.TxfXjr = to_string(recJob.xjref);
	contiac.TxfSta = to_string(recJob.x1Startu);
	contiac.TxfSto = to_string(recJob.x1Stopu);
	continf.TxtSup = StubWzem::getStubJobStd(dbswzem, recJob.supRefWzemMJob, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.ChkCls = recJob.Clisrv;
	contiac.ChkSnc = recJob.srvNotCli;
	contiac.ChkDcl = recJob.Dcol;
	contiac.ChkStm = recJob.Stmgr;

	statshr.TxtPrdActive = evalTxtPrdActive(dbswzem);
	statshr.ButPrdViewAvail = evalButPrdViewAvail(dbswzem);
	statshr.ButPrdViewActive = evalButPrdViewActive(dbswzem);
	statshr.TxfJobActive = evalTxfJobActive(dbswzem);
	statshr.TxfXjrActive = evalTxfXjrActive(dbswzem);
	statshr.TxfStaActive = evalTxfStaActive(dbswzem);
	statshr.TxfStoActive = evalTxfStoActive(dbswzem);
	statshr.TxtSupActive = evalTxtSupActive(dbswzem);
	statshr.ButSupViewAvail = evalButSupViewAvail(dbswzem);
	statshr.ButSupViewActive = evalButSupViewActive(dbswzem);
	statshr.ChkClsActive = evalChkClsActive(dbswzem);
	statshr.ChkSncActive = evalChkSncActive(dbswzem);
	statshr.ChkDclActive = evalChkDclActive(dbswzem);
	statshr.ChkStmActive = evalChkStmActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemJobDetail::refreshRecJobJdcl(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemJMJobDcol* _recJobJdcl = NULL;

	if (dbswzem->tblwzemjmjobdcol->loadRecByRef(recJobJdcl.ref, &_recJobJdcl)) {
		recJobJdcl = *_recJobJdcl;
		delete _recJobJdcl;
	} else recJobJdcl = WzemJMJobDcol();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemJobDetail::refreshRecJobJstm(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemJMJobStmgr* _recJobJstm = NULL;

	if (dbswzem->tblwzemjmjobstmgr->loadRecByRef(recJobJstm.ref, &_recJobJstm)) {
		recJobJstm = *_recJobJstm;
		delete _recJobJstm;
	} else recJobJstm = WzemJMJobStmgr();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemJobDetail::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswzem);
	statshr.ButSaveActive = evalButSaveActive(dbswzem);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzemJobDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFJOB) {
		recJob.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFJOB, jref);
		refreshRecJob(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemJobDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDVIEWCLICK) {
					handleDpchAppDoButPrdViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUPVIEWCLICK) {
					handleDpchAppDoButSupViewClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemJobDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemJobDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFJOB, ContIac::TXFXJR, ContIac::TXFSTA, ContIac::TXFSTO, ContIac::CHKCLS, ContIac::CHKSNC, ContIac::CHKDCL, ContIac::CHKSTM})) {
		if (has(diffitems, ContIac::TXFJOB)) contiac.TxfJob = _contiac->TxfJob;
		if (has(diffitems, ContIac::TXFXJR)) contiac.TxfXjr = _contiac->TxfXjr;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::CHKCLS)) contiac.ChkCls = _contiac->ChkCls;
		if (has(diffitems, ContIac::CHKSNC)) contiac.ChkSnc = _contiac->ChkSnc;
		if (has(diffitems, ContIac::CHKDCL)) contiac.ChkDcl = _contiac->ChkDcl;
		if (has(diffitems, ContIac::CHKSTM)) contiac.ChkStm = _contiac->ChkStm;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemJobDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemJobDetail::handleDpchAppDoButPrdViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrdViewAvail && statshr.ButPrdViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref)) {
			sref = "CrdWzemPrd";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recJob.refWzemMPeriod, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemJobDetail::handleDpchAppDoButSupViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButSupViewAvail && statshr.ButSupViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref)) {
			sref = "CrdWzemJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recJob.supRefWzemMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemJobDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMJOBJDCLMOD_JOBEQ) {
		call->abort = handleCallWzemJobJdclMod_jobEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOBJSTMMOD_JOBEQ) {
		call->abort = handleCallWzemJobJstmMod_jobEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOBUPD_REFEQ) {
		call->abort = handleCallWzemJobUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOB_SUPEQ) {
		call->abort = handleCallWzemJob_supEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOB_PRDEQ) {
		call->abort = handleCallWzemJob_prdEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemJobDetail::handleCallWzemJobJdclMod_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemJobJdclMod_jobEq --- INSERT
	return retval;
};

bool PnlWzemJobDetail::handleCallWzemJobJstmMod_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemJobJstmMod_jobEq --- INSERT
	return retval;
};

bool PnlWzemJobDetail::handleCallWzemJobUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemJobUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemJobDetail::handleCallWzemJob_supEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.supRefWzemMJob == refInv); // IP handleCallWzemJob_supEq --- LINE
	return retval;
};

bool PnlWzemJobDetail::handleCallWzemJob_prdEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recJob.refWzemMPeriod == refInv); // IP handleCallWzemJob_prdEq --- LINE
	return retval;
};

