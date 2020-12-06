/**
	* \file PnlWzemNavAdmin.cpp
	* job handler for job PnlWzemNavAdmin (implementation)
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

#include "PnlWzemNavAdmin.h"

#include "PnlWzemNavAdmin_blks.cpp"
#include "PnlWzemNavAdmin_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemNavAdmin
 ******************************************************************************/

PnlWzemNavAdmin::PnlWzemNavAdmin(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMNAVADMIN, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshUsg(dbswzem, moditems);
	refreshUsr(dbswzem, moditems);
	refreshPrs(dbswzem, moditems);
	refresh(dbswzem, moditems);

	xchg->addClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMUSG, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMUSR, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMPRS, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
};

PnlWzemNavAdmin::~PnlWzemNavAdmin() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemNavAdmin::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstPrs, &feedFLstUsg, &feedFLstUsr, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemNavAdmin::refreshLstUsg(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsgAvail = evalLstUsgAvail(dbswzem);
	statshr.ButUsgViewActive = evalButUsgViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavAdmin::refreshUsg(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsg = 0;

	// feedFLstUsg
	feedFLstUsg.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMUSG, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUsg.appendRefTitles(rec->ref, StubWzem::getStubUsgStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSG);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsg(dbswzem, moditems);
};

void PnlWzemNavAdmin::refreshLstUsr(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstUsrAvail = evalLstUsrAvail(dbswzem);
	statshr.ButUsrViewActive = evalButUsrViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavAdmin::refreshUsr(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstUsr = 0;

	// feedFLstUsr
	feedFLstUsr.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMUSR, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstUsr.appendRefTitles(rec->ref, StubWzem::getStubUsrStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTUSR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstUsr(dbswzem, moditems);
};

void PnlWzemNavAdmin::refreshLstPrs(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrsAvail = evalLstPrsAvail(dbswzem);
	statshr.ButPrsViewActive = evalButPrsViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavAdmin::refreshPrs(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrs = 0;

	// feedFLstPrs
	feedFLstPrs.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMPRS, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrs.appendRefTitles(rec->ref, StubWzem::getStubPrsStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRS);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrs(dbswzem, moditems);
};

void PnlWzemNavAdmin::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWzemNavAdmin::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzem, moditems);

	refreshLstUsg(dbswzem, moditems);
	refreshLstUsr(dbswzem, moditems);
	refreshLstPrs(dbswzem, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWzemNavAdmin::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVADMINDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVADMINDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGNEWCRDCLICK) {
					handleDpchAppDoButUsgNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRVIEWCLICK) {
					handleDpchAppDoButUsrViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSRNEWCRDCLICK) {
					handleDpchAppDoButUsrNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSNEWCRDCLICK) {
					handleDpchAppDoButPrsNewcrdClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemNavAdmin::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemNavAdmin::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFLSTUSG)) {
		contiac.numFLstUsg = _contiac->numFLstUsg;
		refreshLstUsg(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTUSR)) {
		contiac.numFLstUsr = _contiac->numFLstUsr;
		refreshLstUsr(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPRS)) {
		contiac.numFLstPrs = _contiac->numFLstPrs;
		refreshLstPrs(dbswzem, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemNavAdmin::handleDpchAppDoButUsgViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsgAvail && statshr.ButUsgViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstUsg.getRefByNum(contiac.numFLstUsg), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemUsg", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemUsg");
	};
};

void PnlWzemNavAdmin::handleDpchAppDoButUsgNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemUsg", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemUsg");
};

void PnlWzemNavAdmin::handleDpchAppDoButUsrViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstUsrAvail && statshr.ButUsrViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstUsr.getRefByNum(contiac.numFLstUsr), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemUsr", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemUsr");
	};
};

void PnlWzemNavAdmin::handleDpchAppDoButUsrNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemUsr", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemUsr");
};

void PnlWzemNavAdmin::handleDpchAppDoButPrsViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrsAvail && statshr.ButPrsViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstPrs.getRefByNum(contiac.numFLstPrs), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemPrs", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPrs");
	};
};

void PnlWzemNavAdmin::handleDpchAppDoButPrsNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemPrs", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPrs");
};

void PnlWzemNavAdmin::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWzemHusrRunvMod_crdUsrEq(dbswzem, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWzemNavAdmin::handleCallWzemHusrRunvMod_crdUsrEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWzemVCard::CRDWZEMUSG) {
		refreshUsg(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMUSR) {
		refreshUsr(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMPRS) {
		refreshPrs(dbswzem, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};







