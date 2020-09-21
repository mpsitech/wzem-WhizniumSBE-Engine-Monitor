/**
	* \file PnlWzemPstDetail.cpp
	* job handler for job PnlWzemPstDetail (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemPstDetail.h"

#include "PnlWzemPstDetail_blks.cpp"
#include "PnlWzemPstDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemPstDetail
 ******************************************************************************/

PnlWzemPstDetail::PnlWzemPstDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMPSTDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMPST_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFPST, jref);
};

PnlWzemPstDetail::~PnlWzemPstDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemPstDetail::getNewDpchEng(
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

void PnlWzemPstDetail::refreshRecPst(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMPreset* _recPst = NULL;

	if (dbswzem->tblwzemmpreset->loadRecByRef(recPst.ref, &_recPst)) {
		recPst = *_recPst;
		delete _recPst;
	} else recPst = WzemMPreset();

	dirty = false;

	continf.TxtJob = StubWzem::getStubJobStd(dbswzem, recPst.refWzemMJob, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfPst = recPst.srefIxVPreset;
	contiac.TxfSta = to_string(recPst.x1Startu);
	contiac.TxfSto = to_string(recPst.x1Stopu);
	contiac.TxfArg = recPst.arg;

	statshr.TxtJobActive = evalTxtJobActive(dbswzem);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswzem);
	statshr.ButJobViewActive = evalButJobViewActive(dbswzem);
	statshr.TxfPstActive = evalTxfPstActive(dbswzem);
	statshr.TxfStaActive = evalTxfStaActive(dbswzem);
	statshr.TxfStoActive = evalTxfStoActive(dbswzem);
	statshr.TxfArgActive = evalTxfArgActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemPstDetail::refreshRecPstJarg(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemJMPresetArg* _recPstJarg = NULL;

	if (dbswzem->tblwzemjmpresetarg->loadRecByRef(recPstJarg.ref, &_recPstJarg)) {
		recPstJarg = *_recPstJarg;
		delete _recPstJarg;
	} else recPstJarg = WzemJMPresetArg();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemPstDetail::refresh(
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

void PnlWzemPstDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFPST) {
		recPst.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPST, jref);
		refreshRecPst(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemPstDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDETAILDO) {
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

void PnlWzemPstDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemPstDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFPST, ContIac::TXFSTA, ContIac::TXFSTO, ContIac::TXFARG})) {
		if (has(diffitems, ContIac::TXFPST)) contiac.TxfPst = _contiac->TxfPst;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::TXFARG)) contiac.TxfArg = _contiac->TxfArg;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemPstDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemPstDetail::handleDpchAppDoButJobViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButJobViewAvail && statshr.ButJobViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref)) {
			sref = "CrdWzemJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recPst.refWzemMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemPstDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMPSTJARGMOD_PSTEQ) {
		call->abort = handleCallWzemPstJargMod_pstEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPSTUPD_REFEQ) {
		call->abort = handleCallWzemPstUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPST_JOBEQ) {
		call->abort = handleCallWzemPst_jobEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemPstDetail::handleCallWzemPstJargMod_pstEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemPstJargMod_pstEq --- INSERT
	return retval;
};

bool PnlWzemPstDetail::handleCallWzemPstUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemPstUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemPstDetail::handleCallWzemPst_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recPst.refWzemMJob == refInv); // IP handleCallWzemPst_jobEq --- LINE
	return retval;
};

