/**
	* \file PnlWzemOpxDetail.cpp
	* job handler for job PnlWzemOpxDetail (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemOpxDetail.h"

#include "PnlWzemOpxDetail_blks.cpp"
#include "PnlWzemOpxDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemOpxDetail
 ******************************************************************************/

PnlWzemOpxDetail::PnlWzemOpxDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMOPXDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMOPX_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFOPX, jref);
};

PnlWzemOpxDetail::~PnlWzemOpxDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemOpxDetail::getNewDpchEng(
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

void PnlWzemOpxDetail::refreshRecOpx(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMOp* _recOpx = NULL;

	if (dbswzem->tblwzemmop->loadRecByRef(recOpx.ref, &_recOpx)) {
		recOpx = *_recOpx;
		delete _recOpx;
	} else recOpx = WzemMOp();

	dirty = false;

	continf.TxtJob = StubWzem::getStubJobStd(dbswzem, recOpx.refWzemMJob, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfXor = to_string(recOpx.xoref);
	contiac.TxfSta = to_string(recOpx.x1Startu);
	contiac.TxfSto = to_string(recOpx.x1Stopu);

	statshr.TxtJobActive = evalTxtJobActive(dbswzem);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswzem);
	statshr.ButJobViewActive = evalButJobViewActive(dbswzem);
	statshr.TxfXorActive = evalTxfXorActive(dbswzem);
	statshr.TxfStaActive = evalTxfStaActive(dbswzem);
	statshr.TxfStoActive = evalTxfStoActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemOpxDetail::refresh(
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

void PnlWzemOpxDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFOPX) {
		recOpx.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFOPX, jref);
		refreshRecOpx(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemOpxDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemOpxDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemOpxDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFXOR, ContIac::TXFSTA, ContIac::TXFSTO})) {
		if (has(diffitems, ContIac::TXFXOR)) contiac.TxfXor = _contiac->TxfXor;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemOpxDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemOpxDetail::handleDpchAppDoButJobViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButJobViewAvail && statshr.ButJobViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref)) {
			sref = "CrdWzemJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recOpx.refWzemMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemOpxDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMOPXUPD_REFEQ) {
		call->abort = handleCallWzemOpxUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMOPX_JOBEQ) {
		call->abort = handleCallWzemOpx_jobEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemOpxDetail::handleCallWzemOpxUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemOpxUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemOpxDetail::handleCallWzemOpx_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recOpx.refWzemMJob == refInv); // IP handleCallWzemOpx_jobEq --- LINE
	return retval;
};

