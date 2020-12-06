/**
	* \file PnlWzemClnDetail.cpp
	* job handler for job PnlWzemClnDetail (implementation)
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

#include "PnlWzemClnDetail.h"

#include "PnlWzemClnDetail_blks.cpp"
#include "PnlWzemClnDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemClnDetail
 ******************************************************************************/

PnlWzemClnDetail::PnlWzemClnDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMCLNDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFLstAms.tag = "FeedFLstAms";
	VecWzemWMClstnArgmask::fillFeed(feedFLstAms);
	feedFPupJat.tag = "FeedFPupJat";
	VecWzemVMClstnJactype::fillFeed(feedFPupJat);
	feedFPupJms.tag = "FeedFPupJms";
	VecWzemVMClstnJobmask::fillFeed(feedFPupJms);
	feedFPupTrg.tag = "FeedFPupTrg";
	VecWzemVMClstnTarget::fillFeed(feedFPupTrg);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMCLN_TJBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMCLN_JOBEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFCLN, jref);
};

PnlWzemClnDetail::~PnlWzemClnDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemClnDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstAms, &feedFPupJat, &feedFPupJms, &feedFPupTrg, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemClnDetail::refreshTxtAms(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstAms.size(); i++) ix |= feedFLstAms.getIxByNum(contiac.numsFLstAms[i]);
	continf.TxtAms = VecWzemWMClstnArgmask::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWzemClnDetail::refreshRecCln(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WzemMClstn* _recCln = NULL;

	if (dbswzem->tblwzemmclstn->loadRecByRef(recCln.ref, &_recCln)) {
		recCln = *_recCln;
		delete _recCln;
	} else recCln = WzemMClstn();

	dirty = false;

	continf.TxtJob = StubWzem::getStubJobStd(dbswzem, recCln.refWzemMJob, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.TxfCal = recCln.srefIxVCall;
	contiac.TxfSge = recCln.srefIxVSge;
	contiac.TxfSta = to_string(recCln.x1Startu);
	contiac.TxfSto = to_string(recCln.x1Stopu);
	contiac.numFPupTrg = feedFPupTrg.getNumByIx(recCln.ixVTarget);
	contiac.numFPupJms = feedFPupJms.getNumByIx(recCln.ixVJobmask);
	continf.TxtTjb = StubWzem::getStubJobStd(dbswzem, recCln.tjbRefWzemMJob, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.numsFLstAms.clear();
	VecWzemWMClstnArgmask::getIcs(recCln.ixVArgmask, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstAms.push_back(feedFLstAms.getNumByIx(*it));
	contiac.TxfArg = recCln.arg;
	contiac.numFPupJat = feedFPupJat.getNumByIx(recCln.ixVJactype);

	statshr.TxtJobActive = evalTxtJobActive(dbswzem);
	statshr.ButJobViewAvail = evalButJobViewAvail(dbswzem);
	statshr.ButJobViewActive = evalButJobViewActive(dbswzem);
	statshr.TxfCalActive = evalTxfCalActive(dbswzem);
	statshr.TxfSgeActive = evalTxfSgeActive(dbswzem);
	statshr.TxfStaActive = evalTxfStaActive(dbswzem);
	statshr.TxfStoActive = evalTxfStoActive(dbswzem);
	statshr.PupTrgActive = evalPupTrgActive(dbswzem);
	statshr.PupJmsActive = evalPupJmsActive(dbswzem);
	statshr.TxtTjbActive = evalTxtTjbActive(dbswzem);
	statshr.ButTjbViewAvail = evalButTjbViewAvail(dbswzem);
	statshr.ButTjbViewActive = evalButTjbViewActive(dbswzem);
	statshr.LstAmsActive = evalLstAmsActive(dbswzem);
	statshr.TxfArgActive = evalTxfArgActive(dbswzem);
	statshr.PupJatActive = evalPupJatActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshTxtAms(dbswzem, moditems);

};

void PnlWzemClnDetail::refreshRecClnJ(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WzemJMClstn* _recClnJ = NULL;

	if (dbswzem->tblwzemjmclstn->loadRecByRef(recClnJ.ref, &_recClnJ)) {
		recClnJ = *_recClnJ;
		delete _recClnJ;
	} else recClnJ = WzemJMClstn();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemClnDetail::refresh(
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

void PnlWzemClnDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFCLN) {
		recCln.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFCLN, jref);
		refreshRecCln(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemClnDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTJBVIEWCLICK) {
					handleDpchAppDoButTjbViewClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemClnDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemClnDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFCAL, ContIac::TXFSGE, ContIac::TXFSTA, ContIac::TXFSTO, ContIac::NUMFPUPTRG, ContIac::NUMFPUPJMS, ContIac::TXFARG, ContIac::NUMFPUPJAT})) {
		if (has(diffitems, ContIac::TXFCAL)) contiac.TxfCal = _contiac->TxfCal;
		if (has(diffitems, ContIac::TXFSGE)) contiac.TxfSge = _contiac->TxfSge;
		if (has(diffitems, ContIac::TXFSTA)) contiac.TxfSta = _contiac->TxfSta;
		if (has(diffitems, ContIac::TXFSTO)) contiac.TxfSto = _contiac->TxfSto;
		if (has(diffitems, ContIac::NUMFPUPTRG)) contiac.numFPupTrg = _contiac->numFPupTrg;
		if (has(diffitems, ContIac::NUMFPUPJMS)) contiac.numFPupJms = _contiac->numFPupJms;
		if (has(diffitems, ContIac::TXFARG)) contiac.TxfArg = _contiac->TxfArg;
		if (has(diffitems, ContIac::NUMFPUPJAT)) contiac.numFPupJat = _contiac->numFPupJat;
	};

	if (has(diffitems, ContIac::NUMSFLSTAMS)) {
		contiac.numsFLstAms = _contiac->numsFLstAms;
		refreshTxtAms(dbswzem, moditems);
		refresh(dbswzem, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemClnDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemClnDetail::handleDpchAppDoButJobViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButJobViewAvail && statshr.ButJobViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref)) {
			sref = "CrdWzemJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recCln.refWzemMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemClnDetail::handleDpchAppDoButTjbViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButTjbViewAvail && statshr.ButTjbViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref)) {
			sref = "CrdWzemJob";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recCln.tjbRefWzemMJob, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemClnDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMCLNJMOD_CLNEQ) {
		call->abort = handleCallWzemClnJMod_clnEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCLNUPD_REFEQ) {
		call->abort = handleCallWzemClnUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCLN_TJBEQ) {
		call->abort = handleCallWzemCln_tjbEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCLN_JOBEQ) {
		call->abort = handleCallWzemCln_jobEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemClnDetail::handleCallWzemClnJMod_clnEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemClnJMod_clnEq --- INSERT
	return retval;
};

bool PnlWzemClnDetail::handleCallWzemClnUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemClnUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemClnDetail::handleCallWzemCln_tjbEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCln.tjbRefWzemMJob == refInv); // IP handleCallWzemCln_tjbEq --- LINE
	return retval;
};

bool PnlWzemClnDetail::handleCallWzemCln_jobEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recCln.refWzemMJob == refInv); // IP handleCallWzemCln_jobEq --- LINE
	return retval;
};







