/**
	* \file PnlWzemNavMon.cpp
	* job handler for job PnlWzemNavMon (implementation)
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

#include "PnlWzemNavMon.h"

#include "PnlWzemNavMon_blks.cpp"
#include "PnlWzemNavMon_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemNavMon
 ******************************************************************************/

PnlWzemNavMon::PnlWzemNavMon(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMNAVMON, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFLstCal.tag = "FeedFLstCal";
	feedFLstCln.tag = "FeedFLstCln";
	feedFLstEvt.tag = "FeedFLstEvt";
	feedFLstJob.tag = "FeedFLstJob";
	feedFLstNde.tag = "FeedFLstNde";
	feedFLstOpx.tag = "FeedFLstOpx";
	feedFLstPrd.tag = "FeedFLstPrd";
	feedFLstPst.tag = "FeedFLstPst";

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refreshPrd(dbswzem, moditems);
	refreshEvt(dbswzem, moditems);
	refreshJob(dbswzem, moditems);
	refreshCal(dbswzem, moditems);
	refreshCln(dbswzem, moditems);
	refreshOpx(dbswzem, moditems);
	refreshPst(dbswzem, moditems);
	refreshNde(dbswzem, moditems);
	refresh(dbswzem, moditems);

	xchg->addClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMPRD, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMEVT, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMJOB, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMCAL, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMCLN, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMOPX, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMPST, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
	xchg->addIxRefClstn(VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWzemVCard::CRDWZEMNDE, xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref));
};

PnlWzemNavMon::~PnlWzemNavMon() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemNavMon::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &feedFLstCal, &feedFLstCln, &feedFLstEvt, &feedFLstJob, &feedFLstNde, &feedFLstOpx, &feedFLstPrd, &feedFLstPst, &statshr, items);
	};

	return dpcheng;
};

void PnlWzemNavMon::refreshLstPrd(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPrdAvail = evalLstPrdAvail(dbswzem);
	statshr.ButPrdViewActive = evalButPrdViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshPrd(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPrd = 0;

	// feedFLstPrd
	feedFLstPrd.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMPRD, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPrd.appendRefTitles(rec->ref, StubWzem::getStubPrdStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPRD);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPrd(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstEvt(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstEvtAvail = evalLstEvtAvail(dbswzem);
	statshr.ButEvtViewActive = evalButEvtViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshEvt(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstEvt = 0;

	// feedFLstEvt
	feedFLstEvt.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMEVT, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstEvt.appendRefTitles(rec->ref, StubWzem::getStubEvtStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTEVT);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstEvt(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstJob(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstJobAvail = evalLstJobAvail(dbswzem);
	statshr.ButJobViewActive = evalButJobViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshJob(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstJob = 0;

	// feedFLstJob
	feedFLstJob.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMJOB, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstJob.appendRefTitles(rec->ref, StubWzem::getStubJobStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTJOB);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstJob(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstCal(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCalAvail = evalLstCalAvail(dbswzem);
	statshr.ButCalViewActive = evalButCalViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshCal(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCal = 0;

	// feedFLstCal
	feedFLstCal.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMCAL, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCal.appendRefTitles(rec->ref, StubWzem::getStubCalStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCAL);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCal(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstCln(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstClnAvail = evalLstClnAvail(dbswzem);
	statshr.ButClnViewActive = evalButClnViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshCln(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstCln = 0;

	// feedFLstCln
	feedFLstCln.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMCLN, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstCln.appendRefTitles(rec->ref, StubWzem::getStubClnStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTCLN);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstCln(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstOpx(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstOpxAvail = evalLstOpxAvail(dbswzem);
	statshr.ButOpxViewActive = evalButOpxViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshOpx(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstOpx = 0;

	// feedFLstOpx
	feedFLstOpx.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMOPX, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstOpx.appendRefTitles(rec->ref, StubWzem::getStubOpxStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTOPX);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstOpx(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstPst(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstPstAvail = evalLstPstAvail(dbswzem);
	statshr.ButPstViewActive = evalButPstViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshPst(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstPst = 0;

	// feedFLstPst
	feedFLstPst.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMPST, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstPst.appendRefTitles(rec->ref, StubWzem::getStubPstStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTPST);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstPst(dbswzem, moditems);
};

void PnlWzemNavMon::refreshLstNde(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstNdeAvail = evalLstNdeAvail(dbswzem);
	statshr.ButNdeViewActive = evalButNdeViewActive(dbswzem);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWzemNavMon::refreshNde(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);

	ListWzemHistRMUserUniversal rst;
	WzemHistRMUserUniversal* rec = NULL;

	// contiac
	contiac.numFLstNde = 0;

	// feedFLstNde
	feedFLstNde.clear();

	dbswzem->tblwzemhistrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref), VecWzemVCard::CRDWZEMNDE, false, rst);

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		feedFLstNde.appendRefTitles(rec->ref, StubWzem::getStubNdeStd(dbswzem, rec->unvUref, ixWzemVLocale));
	};

	insert(moditems, DpchEngData::FEEDFLSTNDE);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshLstNde(dbswzem, moditems);
};

void PnlWzemNavMon::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- INSERT

	muteRefresh = false;
};

void PnlWzemNavMon::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	refresh(dbswzem, moditems);

	refreshLstPrd(dbswzem, moditems);
	refreshLstEvt(dbswzem, moditems);
	refreshLstJob(dbswzem, moditems);
	refreshLstCal(dbswzem, moditems);
	refreshLstCln(dbswzem, moditems);
	refreshLstOpx(dbswzem, moditems);
	refreshLstPst(dbswzem, moditems);
	refreshLstNde(dbswzem, moditems);
	if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP updatePreset --- END
};

void PnlWzemNavMon::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVMONDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVMONDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTPRDVIEWCLICK) {
					handleDpchAppDoButPrdViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRDNEWCRDCLICK) {
					handleDpchAppDoButPrdNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEVTVIEWCLICK) {
					handleDpchAppDoButEvtViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTEVTNEWCRDCLICK) {
					handleDpchAppDoButEvtNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBVIEWCLICK) {
					handleDpchAppDoButJobViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJOBNEWCRDCLICK) {
					handleDpchAppDoButJobNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCALVIEWCLICK) {
					handleDpchAppDoButCalViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCALNEWCRDCLICK) {
					handleDpchAppDoButCalNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLNVIEWCLICK) {
					handleDpchAppDoButClnViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLNNEWCRDCLICK) {
					handleDpchAppDoButClnNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPXVIEWCLICK) {
					handleDpchAppDoButOpxViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTOPXNEWCRDCLICK) {
					handleDpchAppDoButOpxNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTVIEWCLICK) {
					handleDpchAppDoButPstViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPSTNEWCRDCLICK) {
					handleDpchAppDoButPstNewcrdClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNDEVIEWCLICK) {
					handleDpchAppDoButNdeViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNDENEWCRDCLICK) {
					handleDpchAppDoButNdeNewcrdClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemNavMon::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemNavMon::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	ubigint ref;

	if (has(diffitems, ContIac::NUMFLSTPRD)) {
		contiac.numFLstPrd = _contiac->numFLstPrd;
		if (dbswzem->tblwzemhistrmuseruniversal->loadUnuByRef(feedFLstPrd.getRefByNum(contiac.numFLstPrd), ref)) xchg->triggerIxRefCall(dbswzem, VecWzemVCall::CALLWZEMREFPRESET, jref, VecWzemVPreset::PREWZEMREFPRD, ref);
		refreshLstPrd(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTEVT)) {
		contiac.numFLstEvt = _contiac->numFLstEvt;
		refreshLstEvt(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTJOB)) {
		contiac.numFLstJob = _contiac->numFLstJob;
		refreshLstJob(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCAL)) {
		contiac.numFLstCal = _contiac->numFLstCal;
		refreshLstCal(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTCLN)) {
		contiac.numFLstCln = _contiac->numFLstCln;
		refreshLstCln(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTOPX)) {
		contiac.numFLstOpx = _contiac->numFLstOpx;
		refreshLstOpx(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTPST)) {
		contiac.numFLstPst = _contiac->numFLstPst;
		refreshLstPst(dbswzem, moditems);
	};

	if (has(diffitems, ContIac::NUMFLSTNDE)) {
		contiac.numFLstNde = _contiac->numFLstNde;
		refreshLstNde(dbswzem, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemNavMon::handleDpchAppDoButPrdViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPrdAvail && statshr.ButPrdViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstPrd.getRefByNum(contiac.numFLstPrd), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemPrd", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPrd");
	};
};

void PnlWzemNavMon::handleDpchAppDoButPrdNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemPrd", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPrd");
};

void PnlWzemNavMon::handleDpchAppDoButEvtViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstEvtAvail && statshr.ButEvtViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstEvt.getRefByNum(contiac.numFLstEvt), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemEvt", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemEvt");
	};
};

void PnlWzemNavMon::handleDpchAppDoButEvtNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemEvt", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemEvt");
};

void PnlWzemNavMon::handleDpchAppDoButJobViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstJobAvail && statshr.ButJobViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstJob.getRefByNum(contiac.numFLstJob), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemJob", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemJob");
	};
};

void PnlWzemNavMon::handleDpchAppDoButJobNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemJob", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemJob");
};

void PnlWzemNavMon::handleDpchAppDoButCalViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstCalAvail && statshr.ButCalViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstCal.getRefByNum(contiac.numFLstCal), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemCal", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemCal");
	};
};

void PnlWzemNavMon::handleDpchAppDoButCalNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemCal", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemCal");
};

void PnlWzemNavMon::handleDpchAppDoButClnViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstClnAvail && statshr.ButClnViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstCln.getRefByNum(contiac.numFLstCln), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemCln", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemCln");
	};
};

void PnlWzemNavMon::handleDpchAppDoButClnNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemCln", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemCln");
};

void PnlWzemNavMon::handleDpchAppDoButOpxViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstOpxAvail && statshr.ButOpxViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstOpx.getRefByNum(contiac.numFLstOpx), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemOpx", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemOpx");
	};
};

void PnlWzemNavMon::handleDpchAppDoButOpxNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemOpx", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemOpx");
};

void PnlWzemNavMon::handleDpchAppDoButPstViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstPstAvail && statshr.ButPstViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstPst.getRefByNum(contiac.numFLstPst), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemPst", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPst");
	};
};

void PnlWzemNavMon::handleDpchAppDoButPstNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemPst", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemPst");
};

void PnlWzemNavMon::handleDpchAppDoButNdeViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	WzemHistRMUserUniversal* husrRunv = NULL;
	ubigint jrefNew = 0;

	if (statshr.LstNdeAvail && statshr.ButNdeViewActive) {
		if (dbswzem->tblwzemhistrmuseruniversal->loadRecByRef(feedFLstNde.getRefByNum(contiac.numFLstNde), &husrRunv)) {
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, husrRunv->ixWzemVPreset, husrRunv->preUref, "CrdWzemNde", husrRunv->unvUref, jrefNew);
			delete husrRunv;
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemNde");
	};
};

void PnlWzemNavMon::handleDpchAppDoButNdeNewcrdClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;

	xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, "CrdWzemNde", 0, jrefNew);

	if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
	else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, "CrdWzemNde");
};

void PnlWzemNavMon::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ) {
		call->abort = handleCallWzemHusrRunvMod_crdUsrEq(dbswzem, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool PnlWzemNavMon::handleCallWzemHusrRunvMod_crdUsrEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWzemVCard::CRDWZEMPRD) {
		refreshPrd(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMEVT) {
		refreshEvt(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMJOB) {
		refreshJob(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMCAL) {
		refreshCal(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMCLN) {
		refreshCln(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMOPX) {
		refreshOpx(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMPST) {
		refreshPst(dbswzem, moditems);
	} else if (ixInv == VecWzemVCard::CRDWZEMNDE) {
		refreshNde(dbswzem, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};
