/**
	* \file PnlWzemEvtDetail.cpp
	* job handler for job PnlWzemEvtDetail (implementation)
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

#include "PnlWzemEvtDetail.h"

#include "PnlWzemEvtDetail_blks.cpp"
#include "PnlWzemEvtDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemEvtDetail
 ******************************************************************************/

PnlWzemEvtDetail::PnlWzemEvtDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMEVTDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupTyp.tag = "FeedFPupTyp";
	VecWzemVMEventBasetype::fillFeed(feedFPupTyp);

	// IP constructor.cust1 --- INSERT

	dirty = false;

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

PnlWzemEvtDetail::~PnlWzemEvtDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemEvtDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupTyp, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemEvtDetail::refreshLstClu(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbswzem);
	statshr.ButCluViewActive = evalButCluViewActive(dbswzem);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbswzem);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemEvtDetail::refreshClu(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recEvt.refWzemCEvent != 0) dbswzem->tblwzemmevent->loadRefsByClu(recEvt.refWzemCEvent, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recEvt.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWzem::getStubEvtStd(dbswzem, refs[i], ixWzemVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWzem::getStubEvtStd(dbswzem, refs[i], ixWzemVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswzem, moditems);
};

void PnlWzemEvtDetail::refreshRecEvt(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMEvent* _recEvt = NULL;

	if (dbswzem->tblwzemmevent->loadRecByRef(recEvt.ref, &_recEvt)) {
		recEvt = *_recEvt;
		delete _recEvt;
	} else recEvt = WzemMEvent();

	dirty = false;

	recDch.ref = recEvt.refWzemMDpch;

	if (recEvt.refWzemCEvent == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMEVTMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMEVTMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recEvt.refWzemCEvent);

	contiac.numFPupTyp = feedFPupTyp.getNumByIx(recEvt.ixVBasetype);
	continf.TxtPrd = StubWzem::getStubPrdStd(dbswzem, recEvt.refWzemMPeriod, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfSta = to_string(recEvt.startu);
	continf.TxtCal = StubWzem::getStubCalStd(dbswzem, recEvt.refWzemMCall, ixWzemVLocale, Stub::VecVNonetype::FULL);
	continf.TxtCln = StubWzem::getStubClnStd(dbswzem, recEvt.refWzemMClstn, ixWzemVLocale, Stub::VecVNonetype::FULL);
	continf.TxtJob = StubWzem::getStubJobStd(dbswzem, recEvt.refWzemMJob, ixWzemVLocale, Stub::VecVNonetype::FULL);
	continf.TxtNde = StubWzem::getStubNdeStd(dbswzem, recEvt.refWzemMNode, ixWzemVLocale, Stub::VecVNonetype::FULL);
	continf.TxtOpx = StubWzem::getStubOpxStd(dbswzem, recEvt.refWzemMOp, ixWzemVLocale, Stub::VecVNonetype::FULL);
	continf.TxtPst = StubWzem::getStubPstStd(dbswzem, recEvt.refWzemMPreset, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCmd = recEvt.Cmd;
	contiac.TxfFnm = recEvt.Filename;
	contiac.TxfFeg = recEvt.srefIxVFeatgroup;
	contiac.TxfMtd = recEvt.srefIxVMethod;
	contiac.TxfXsr = recEvt.xsref;

	statshr.PupTypActive = evalPupTypActive(dbswzem);
	statshr.TxtPrdActive = evalTxtPrdActive(dbswzem);
	statshr.ButPrdViewAvail = evalButPrdViewAvail(dbswzem);
	statshr.ButPrdViewActive = evalButPrdViewActive(dbswzem);
	statshr.TxfStaActive = evalTxfStaActive(dbswzem);
	statshr.TxtCalActive = evalTxtCalActive(dbswzem);
	statshr.ButCalViewAvail = evalButCalViewAvail(dbswzem);
	statshr.ButCalViewActive = evalButCalViewActive(dbswzem);
	statshr.TxtClnActive = evalTxtClnActive(dbswzem);
	statshr.ButClnViewAvail = evalButClnViewAvail(dbswzem);
	statshr.ButClnViewActive = evalButClnViewActive(dbswzem);
	statshr.TxtJobActive = evalTxtJobActive(dbswzem);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswzem);
	statshr.ButJobViewActive = evalButJobViewActive(dbswzem);
	statshr.TxtNdeActive = evalTxtNdeActive(dbswzem);
	statshr.ButNdeViewAvail = evalButNdeViewAvail(dbswzem);
	statshr.ButNdeViewActive = evalButNdeViewActive(dbswzem);
	statshr.TxtOpxActive = evalTxtOpxActive(dbswzem);
	statshr.ButOpxViewAvail = evalButOpxViewAvail(dbswzem);
	statshr.ButOpxViewActive = evalButOpxViewActive(dbswzem);
	statshr.TxtPstActive = evalTxtPstActive(dbswzem);
	statshr.ButPstViewAvail = evalButPstViewAvail(dbswzem);
	statshr.ButPstViewActive = evalButPstViewActive(dbswzem);
	statshr.TxfCmdActive = evalTxfCmdActive(dbswzem);
	statshr.TxfFnmActive = evalTxfFnmActive(dbswzem);
	statshr.TxfFegActive = evalTxfFegActive(dbswzem);
	statshr.TxfMtdActive = evalTxfMtdActive(dbswzem);
	statshr.TxfXsrActive = evalTxfXsrActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshRecDch(dbswzem, moditems);

	refreshClu(dbswzem, moditems);

};

void PnlWzemEvtDetail::refreshRecDch(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMDpch* _recDch = NULL;

	if (dbswzem->tblwzemmdpch->loadRecByRef(recDch.ref, &_recDch)) {
		recDch = *_recDch;
		delete _recDch;
	} else recDch = WzemMDpch();

	contiac.TxfDchDch = recDch.srefIxVDpch;
	contiac.TxfDchMsk = recDch.srefsMask;
	contiac.TxfDchCnt = recDch.Content;

	statshr.ButDchNewAvail = evalButDchNewAvail(dbswzem);
	statshr.ButDchDeleteAvail = evalButDchDeleteAvail(dbswzem);
	statshr.TxfDchDchAvail = evalTxfDchDchAvail(dbswzem);
	statshr.TxfDchDchActive = evalTxfDchDchActive(dbswzem);
	statshr.TxfDchMskAvail = evalTxfDchMskAvail(dbswzem);
	statshr.TxfDchMskActive = evalTxfDchMskActive(dbswzem);
	statshr.TxfDchCntAvail = evalTxfDchCntAvail(dbswzem);
	statshr.TxfDchCntActive = evalTxfDchCntActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemEvtDetail::refresh(
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

void PnlWzemEvtDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFEVT) {
		recEvt.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFEVT, jref);
		refreshRecEvt(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemEvtDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDVIEWCLICK) {
					handleDpchAppDoButPrdViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCALVIEWCLICK) {
					handleDpchAppDoButCalViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLNVIEWCLICK) {
					handleDpchAppDoButClnViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNDEVIEWCLICK) {
					handleDpchAppDoButNdeViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPXVIEWCLICK) {
					handleDpchAppDoButOpxViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTVIEWCLICK) {
					handleDpchAppDoButPstViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDCHNEWCLICK) {
					handleDpchAppDoButDchNewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDCHDELETECLICK) {
					handleDpchAppDoButDchDeleteClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemEvtDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemEvtDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPTYP, ContIac::TXFSTA, ContIac::TXFCMD, ContIac::TXFFNM, ContIac::TXFFEG, ContIac::TXFMTD, ContIac::TXFXSR, ContIac::TXFDCHDCH, ContIac::TXFDCHMSK, ContIac::TXFDCHCNT})) {
		if (has(diffitems, ContIac::NUMFPUPTYP)) contiac.numFPupTyp = _contiac->numFPupTyp;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFCMD)) contiac.TxfCmd = _contiac->TxfCmd;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::TXFFEG)) contiac.TxfFeg = _contiac->TxfFeg;
		if (has(diffitems, ContIac::TXFMTD)) contiac.TxfMtd = _contiac->TxfMtd;
		if (has(diffitems, ContIac::TXFXSR)) contiac.TxfXsr = _contiac->TxfXsr;
		if (has(diffitems, ContIac::TXFDCHDCH)) contiac.TxfDchDch = _contiac->TxfDchDch;
		if (has(diffitems, ContIac::TXFDCHMSK)) contiac.TxfDchMsk = _contiac->TxfDchMsk;
		if (has(diffitems, ContIac::TXFDCHCNT)) contiac.TxfDchCnt = _contiac->TxfDchCnt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswzem, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemEvtDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemEvtDetail::handleDpchAppDoButPrdViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrdViewAvail && statshr.ButPrdViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref)) {
			sref = "CrdWzemPrd";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMPeriod, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButCluViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWzemEvtDetail::handleDpchAppDoButCluClusterClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWzemEvtDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWzemEvtDetail::handleDpchAppDoButCalViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButCalViewAvail && statshr.ButCalViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref)) {
			sref = "CrdWzemCal";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMCall, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButClnViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButClnViewAvail && statshr.ButClnViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref)) {
			sref = "CrdWzemCln";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMClstn, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButJobViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButJobViewAvail && statshr.ButJobViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref)) {
			sref = "CrdWzemJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButNdeViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButNdeViewAvail && statshr.ButNdeViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref)) {
			sref = "CrdWzemNde";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMNode, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButOpxViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButOpxViewAvail && statshr.ButOpxViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref)) {
			sref = "CrdWzemOpx";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMOp, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButPstViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPstViewAvail && statshr.ButPstViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref)) {
			sref = "CrdWzemPst";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recEvt.refWzemMPreset, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemEvtDetail::handleDpchAppDoButDchNewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButDchNewClick --- INSERT
};

void PnlWzemEvtDetail::handleDpchAppDoButDchDeleteClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButDchDeleteClick --- INSERT
};

void PnlWzemEvtDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMEVTMOD_CLUEQ) {
		call->abort = handleCallWzemEvtMod_cluEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVTUPD_REFEQ) {
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

bool PnlWzemEvtDetail::handleCallWzemEvtMod_cluEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswzem, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvtUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemEvtUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemDchUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemDchUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_pstEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMPreset == refInv); // IP handleCallWzemEvt_pstEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_prdEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMPeriod == refInv); // IP handleCallWzemEvt_prdEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_opxEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMOp == refInv); // IP handleCallWzemEvt_opxEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_ndeEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMNode == refInv); // IP handleCallWzemEvt_ndeEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMJob == refInv); // IP handleCallWzemEvt_jobEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_dchEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMDpch == refInv); // IP handleCallWzemEvt_dchEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_cluEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemCEvent == refInv); // IP handleCallWzemEvt_cluEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_clnEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMClstn == refInv); // IP handleCallWzemEvt_clnEq --- LINE
	return retval;
};

bool PnlWzemEvtDetail::handleCallWzemEvt_calEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recEvt.refWzemMCall == refInv); // IP handleCallWzemEvt_calEq --- LINE
	return retval;
};
