/**
	* \file PnlWzemUsrDetail.cpp
	* job handler for job PnlWzemUsrDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "PnlWzemUsrDetail.h"

#include "PnlWzemUsrDetail_blks.cpp"
#include "PnlWzemUsrDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemUsrDetail
 ******************************************************************************/

PnlWzemUsrDetail::PnlWzemUsrDetail(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMUSRDETAIL, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFPupLcl.tag = "FeedFPupLcl";
	VecWzemVLocale::fillFeed(ixWzemVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecWzemVMUserState::fillFeed(ixWzemVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecWzemVUserlevel::fillFeed(ixWzemVLocale, feedFPupUlv);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMUSR_USGEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMUSR_PRSEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	updatePreset(dbswzem, VecWzemVPreset::PREWZEMREFUSR, jref);
};

PnlWzemUsrDetail::~PnlWzemUsrDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemUsrDetail::refreshRecUsr(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemMUser* _recUsr = NULL;

	if (dbswzem->tblwzemmuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = WzemMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	if (recUsr.ref == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMUSRJSTEMOD_USREQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, true, recUsr.ref);

	continf.TxtPrs = StubWzem::getStubPrsStd(dbswzem, recUsr.refWzemMPerson, ixWzemVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubWzem::getStubUsgStd(dbswzem, recUsr.refWzemMUsergroup, ixWzemVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsr.ixVState);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixWzemVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixWzemVUserlevel);
	contiac.TxfPwd = recUsr.Password;
	contiac.TxfFky = recUsr.Fullkey;
	contiac.TxfCmt = recUsr.Comment;

	statshr.TxtPrsActive = evalTxtPrsActive(dbswzem);
	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbswzem);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbswzem);
	statshr.TxtSrfActive = evalTxtSrfActive(dbswzem);
	statshr.TxtUsgActive = evalTxtUsgActive(dbswzem);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbswzem);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbswzem);
	statshr.PupSteActive = evalPupSteActive(dbswzem);
	statshr.PupLclActive = evalPupLclActive(dbswzem);
	statshr.PupUlvActive = evalPupUlvActive(dbswzem);
	statshr.TxfPwdActive = evalTxfPwdActive(dbswzem);
	statshr.TxfFkyActive = evalTxfFkyActive(dbswzem);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswzem);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemUsrDetail::refreshRecUsrJste(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WzemJMUserState* _recUsrJste = NULL;

	if (dbswzem->tblwzemjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = WzemJMUserState();

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlWzemUsrDetail::refresh(
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

void PnlWzemUsrDetail::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSR, jref);
		refreshRecUsr(dbswzem, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemUsrDetail::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemUsrDetail::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD, ContIac::TXFFKY, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
		if (has(diffitems, ContIac::TXFFKY)) contiac.TxfFky = _contiac->TxfFky;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemUsrDetail::handleDpchAppDoButSaveClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWzemUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButPrsViewAvail && statshr.ButPrsViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref)) {
			sref = "CrdWzemPrs";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recUsr.refWzemMPerson, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButUsgViewAvail && statshr.ButUsgViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref)) {
			sref = "CrdWzemUsg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recUsr.refWzemMUsergroup, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemUsrDetail::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSRJSTEMOD_USREQ) {
		call->abort = handleCallWzemUsrJsteMod_usrEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSRUPD_REFEQ) {
		call->abort = handleCallWzemUsrUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSR_USGEQ) {
		call->abort = handleCallWzemUsr_usgEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSR_PRSEQ) {
		call->abort = handleCallWzemUsr_prsEq(dbswzem, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWzemUsrDetail::handleCallWzemUsrJsteMod_usrEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemUsrJsteMod_usrEq --- INSERT
	return retval;
};

bool PnlWzemUsrDetail::handleCallWzemUsrUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlWzemUsrDetail::handleCallWzemUsr_usgEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWzemMUsergroup == refInv); // IP handleCallWzemUsr_usgEq --- LINE
	return retval;
};

bool PnlWzemUsrDetail::handleCallWzemUsr_prsEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recUsr.refWzemMPerson == refInv); // IP handleCallWzemUsr_prsEq --- LINE
	return retval;
};

