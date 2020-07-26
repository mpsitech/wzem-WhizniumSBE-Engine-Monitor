/**
	* \file PnlWzemNdeDetail.cpp
	* job handler for job PnlWzemNdeDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemNdeDetail.h"

#include "PnlWzemNdeDetail_blks.cpp"
#include "PnlWzemNdeDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemNdeDetail
 ******************************************************************************/

PnlWzemNdeDetail::PnlWzemNdeDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMNDEDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMNDE_PRDEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFNDE, jref);
};

PnlWzemNdeDetail::~PnlWzemNdeDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemNdeDetail::getNewDpchEng(
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

void PnlWzemNdeDetail::refreshRecNde(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMNode* _recNde = NULL;

	if (dbswzem->tblwzemmnode->loadRecByRef(recNde.ref, &_recNde)) {
		recNde = *_recNde;
		delete _recNde;
	} else recNde = WzemMNode();

	dirty = false;

	continf.TxtPrd = StubWzem::getStubPrdStd(dbswzem, recNde.refWzemMPeriod, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfXnr = to_string(recNde.xnref);
	contiac.TxfIp = recNde.Ip;
	contiac.TxfSta = to_string(recNde.x1Startu);
	contiac.TxfSto = to_string(recNde.x1Stopu);
	contiac.TxfPrt = to_string(recNde.Port);
	contiac.TxfOrn = to_string(recNde.Opprcn);

	statshr.TxtPrdActive = evalTxtPrdActive(dbswzem);
	statshr.ButPrdViewAvail = evalButPrdViewAvail(dbswzem);
	statshr.ButPrdViewActive = evalButPrdViewActive(dbswzem);
	statshr.TxfXnrActive = evalTxfXnrActive(dbswzem);
	statshr.TxfIpActive = evalTxfIpActive(dbswzem);
	statshr.TxfStaActive = evalTxfStaActive(dbswzem);
	statshr.TxfStoActive = evalTxfStoActive(dbswzem);
	statshr.TxfPrtActive = evalTxfPrtActive(dbswzem);
	statshr.TxfOrnActive = evalTxfOrnActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemNdeDetail::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswzem);
	statshr.ButSaveActive = evalButSaveActive(dbswzem);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNdeDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFNDE) {
		recNde.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFNDE, jref);
		refreshRecNde(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemNdeDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDVIEWCLICK) {
					handleDpchAppDoButPrdViewClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemNdeDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemNdeDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFXNR, ContIac::TXFIP, ContIac::TXFSTA, ContIac::TXFSTO, ContIac::TXFPRT, ContIac::TXFORN})) {
		if (has(diffitems, ContIac::TXFXNR)) contiac.TxfXnr = _contiac->TxfXnr;
		if (has(diffitems, ContIac::TXFIP)) contiac.TxfIp = _contiac->TxfIp;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::TXFPRT)) contiac.TxfPrt = _contiac->TxfPrt;
		if (has(diffitems, ContIac::TXFORN)) contiac.TxfOrn = _contiac->TxfOrn;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemNdeDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemNdeDetail::handleDpchAppDoButPrdViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrdViewAvail && statshr.ButPrdViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref)) {
			sref = "CrdWzemPrd";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recNde.refWzemMPeriod, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemNdeDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMNDEUPD_REFEQ) {
		call->abort = handleCallWzemNdeUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMNDE_PRDEQ) {
		call->abort = handleCallWzemNde_prdEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemNdeDetail::handleCallWzemNdeUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemNdeUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemNdeDetail::handleCallWzemNde_prdEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recNde.refWzemMPeriod == refInv); // IP handleCallWzemNde_prdEq --- LINE
	return retval;
};

