/**
	* \file PnlWzemPrsDetail.cpp
	* job handler for job PnlWzemPrsDetail (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemPrsDetail.h"

#include "PnlWzemPrsDetail_blks.cpp"
#include "PnlWzemPrsDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemPrsDetail
 ******************************************************************************/

PnlWzemPrsDetail::PnlWzemPrsDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMPRSDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFLstDrv.tag = "FeedFLstDrv";
	VecWzemWMPersonDerivate::fillFeed(ixWzemVLocale, feedFLstDrv);
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSex.tag = "FeedFPupSex";
	VecWzemVMPersonSex::fillFeed(ixWzemVLocale, feedFPupSex);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFPRS, jref);
};

PnlWzemPrsDetail::~PnlWzemPrsDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemPrsDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstDrv, &feedFPupJ, &feedFPupSex, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemPrsDetail::refreshJ(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ListWzemJMPersonLastname prsJlnms;
	WzemJMPersonLastname* prsJlnm = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbswzem->tblwzemjmpersonlastname->loadRstByPrs(recPrs.ref, false, prsJlnms);

	for (unsigned int i = 0; i < prsJlnms.nodes.size(); i++) {
		prsJlnm = prsJlnms.nodes[i];

		s = "";
		if (prsJlnm->x1Startd != 0) {
			s = Ftm::date(prsJlnm->x1Startd) + " -";
			if ((i+2) < prsJlnms.nodes.size()) if (prsJlnms.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(prsJlnms.nodes[i+1]->x1Startd);
		} else s = "(" + VecWzemVTag::getTitle(VecWzemVTag::ALWAYS, ixWzemVLocale) + ")";
		feedFPupJ.appendRefTitles(prsJlnm->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecPrsJlnm(dbswzem, moditems);

};

void PnlWzemPrsDetail::refreshTxtDrv(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);

	uint ix = 0;
	for (unsigned int i = 0; i < contiac.numsFLstDrv.size(); i++) ix |= feedFLstDrv.getIxByNum(contiac.numsFLstDrv[i]);
	continf.TxtDrv = VecWzemWMPersonDerivate::getSrefs(ix);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void PnlWzemPrsDetail::refreshRecPrs(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WzemMPerson* _recPrs = NULL;

	if (dbswzem->tblwzemmperson->loadRecByRef(recPrs.ref, &_recPrs)) {
		recPrs = *_recPrs;
		delete _recPrs;
	} else recPrs = WzemMPerson();

	dirty = false;

	recPrsJlnm.ref = recPrs.refJLastname;
	if (recPrs.ref == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMPRSJLNMMOD_PRSEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMPRSJLNMMOD_PRSEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recPrs.ref);

	contiac.TxfTit = recPrs.Title;
	contiac.TxfFnm = recPrs.Firstname;
	contiac.numsFLstDrv.clear();
	VecWzemWMPersonDerivate::getIcs(recPrs.ixWDerivate, ics);
	for (auto it = ics.begin(); it != ics.end(); it++) contiac.numsFLstDrv.push_back(feedFLstDrv.getNumByIx(*it));
	contiac.numFPupSex = feedFPupSex.getNumByIx(recPrs.ixVSex);
	contiac.TxfTel = recPrs.telVal;
	contiac.TxfEml = recPrs.emlVal;
	contiac.TxfSal = recPrs.Salutation;

	statshr.TxfTitActive = evalTxfTitActive(dbswzem);
	statshr.TxfFnmActive = evalTxfFnmActive(dbswzem);
	statshr.LstDrvActive = evalLstDrvActive(dbswzem);
	statshr.PupSexActive = evalPupSexActive(dbswzem);
	statshr.TxfTelActive = evalTxfTelActive(dbswzem);
	statshr.TxfEmlActive = evalTxfEmlActive(dbswzem);
	statshr.TxfSalActive = evalTxfSalActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbswzem, moditems);
	refreshTxtDrv(dbswzem, moditems);

};

void PnlWzemPrsDetail::refreshRecPrsJlnm(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	set<uint> ics;

	WzemJMPersonLastname* _recPrsJlnm = NULL;

	if (dbswzem->tblwzemjmpersonlastname->loadRecByRef(recPrsJlnm.ref, &_recPrsJlnm)) {
		recPrsJlnm = *_recPrsJlnm;
		delete _recPrsJlnm;
	} else recPrsJlnm = WzemJMPersonLastname();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recPrsJlnm.ref);
	continf.TxtLnm = recPrsJlnm.Lastname;

	statshr.PupJActive = evalPupJActive(dbswzem);
	statshr.ButJEditAvail = evalButJEditAvail(dbswzem);
	statshr.TxtLnmActive = evalTxtLnmActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemPrsDetail::refresh(
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

void PnlWzemPrsDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFPRS) {
		recPrs.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRS, jref);
		refreshRecPrs(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemPrsDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemPrsDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemPrsDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFTIT, ContIac::TXFFNM, ContIac::NUMFPUPSEX, ContIac::TXFTEL, ContIac::TXFEML, ContIac::TXFSAL})) {
		if (has(diffitems, ContIac::TXFTIT)) contiac.TxfTit = _contiac->TxfTit;
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::NUMFPUPSEX)) contiac.numFPupSex = _contiac->numFPupSex;
		if (has(diffitems, ContIac::TXFTEL)) contiac.TxfTel = _contiac->TxfTel;
		if (has(diffitems, ContIac::TXFEML)) contiac.TxfEml = _contiac->TxfEml;
		if (has(diffitems, ContIac::TXFSAL)) contiac.TxfSal = _contiac->TxfSal;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recPrsJlnm.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecPrsJlnm(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMSFLSTDRV)) {
		contiac.numsFLstDrv = _contiac->numsFLstDrv;
		refreshTxtDrv(dbswzem, moditems);
		refresh(dbswzem, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemPrsDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemPrsDetail::handleDpchAppDoButJEditClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlWzemPrsDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMPRSJLNMMOD_PRSEQ) {
		call->abort = handleCallWzemPrsJlnmMod_prsEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPRSUPD_REFEQ) {
		call->abort = handleCallWzemPrsUpd_refEq(dbswzem, call->jref);
	};
};

bool PnlWzemPrsDetail::handleCallWzemPrsJlnmMod_prsEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbswzem, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWzemPrsDetail::handleCallWzemPrsUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemPrsUpd_refEq --- INSERT
	return retval;
};

