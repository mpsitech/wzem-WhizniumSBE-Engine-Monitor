/**
	* \file PnlWzemCalList.cpp
	* job handler for job PnlWzemCalList (implementation)
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

#include "PnlWzemCalList.h"

#include "PnlWzemCalList_blks.cpp"
#include "PnlWzemCalList_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemCalList
 ******************************************************************************/

PnlWzemCalList::PnlWzemCalList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMCALLIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::MNR, "ong", VecWzemVQrystate::getTitle(VecWzemVQrystate::MNR, ixWzemVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::OOD, "red", VecWzemVQrystate::getTitle(VecWzemVQrystate::OOD, ixWzemVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::SLM, "yel", VecWzemVQrystate::getTitle(VecWzemVQrystate::SLM, ixWzemVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::UTD, "grn", VecWzemVQrystate::getTitle(VecWzemVQrystate::UTD, ixWzemVLocale));
	feedFTos.tag = "FeedFTos";
	QryWzemCalList::VecVOrd::fillFeed(feedFTos);

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref, xchg->getRefPreset(VecWzemVPreset::PREWZEMREFCAL, jref));
	xchg->addIxPreset(VecWzemVPreset::PREWZEMIXORD, jref, QryWzemCalList::VecVOrd::JOB);

	qry = new QryWzemCalList(xchg, dbswzem, jref, ixWzemVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	statshr.ixWzemVExpstate = ((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFCAL, jref)) ? VecWzemVExpstate::MIND : VecWzemVExpstate::REGD);
	refresh(dbswzem, moditems);

	xchg->addClstn(VecWzemVCall::CALLWZEMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWzemCalList::~PnlWzemCalList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemCalList::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFCsiQst, &feedFTos, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlWzemCalList::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWzemVQrystate);

	uint ixPre = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXPRE, jref);
	if ((ixPre != 0) && (ixPre != VecWzemVPreset::VOID)) {
		continf.TxtFor = VecWzemVPreset::getTitle(ixPre, ixWzemVLocale);

		if (ixPre == VecWzemVPreset::PREWZEMREFPRD) continf.TxtPre = StubWzem::getStubPrdStd(dbswzem, xchg->getRefPreset(ixPre, jref), ixWzemVLocale, Stub::VecVNonetype::FULL);

	} else {
		continf.TxtFor = "";
	};

	// contiac
	contiac.numFTos = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	muteRefresh = false;
};

void PnlWzemCalList::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFCAL) {
		xchg->addRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref, xchg->getRefPreset(VecWzemVPreset::PREWZEMREFCAL, jref));
		qry->refreshJnum();
		refresh(dbswzem, moditems);

		insert(moditems, DpchEngData::STGIACQRY);

		if ((jrefTrig != jref) && notif) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWzemCalList::minimize(
			DbsWzem* dbswzem
			, const bool notif
			, DpchEngWzem** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWzemVExpstate != VecWzemVExpstate::MIND) {
		statshr.ixWzemVExpstate = VecWzemVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWzemCalList::regularize(
			DbsWzem* dbswzem
			, const bool notif
			, DpchEngWzem** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixWzemVExpstate != VecWzemVExpstate::REGD) {
		statshr.ixWzemVExpstate = VecWzemVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlWzemCalList::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALLISTDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswzem, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswzem, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALLISTDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTNEWCLICK) {
					handleDpchAppDoButNewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDELETECLICK) {
					handleDpchAppDoButDeleteClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTFILTERCLICK) {
					handleDpchAppDoButFilterClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemCalList::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemCalList::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFTOS)) {
		if ((_contiac->numFTos >= QryWzemCalList::VecVOrd::STO) && (_contiac->numFTos <= QryWzemCalList::VecVOrd::JOB)) {
			muteRefresh = true;

			xchg->addIxPreset(VecWzemVPreset::PREWZEMIXORD, jref, _contiac->numFTos);

			qry->rerun(dbswzem);

			refresh(dbswzem, moditems, true);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
		};
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemCalList::handleDpchAppDataStgiac(
			DbsWzem* dbswzem
			, StgIac* _stgiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiac->diff(&stgiac);
	// IP handleDpchAppDataStgiac --- INSERT
	insert(moditems, DpchEngData::STGIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemCalList::handleDpchAppDataStgiacqry(
			DbsWzem* dbswzem
			, QryWzemCalList::StgIac* _stgiacqry
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	ubigint refSelNew = 0;

	if (!diffitems.empty()) {
		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWzemCalList::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWzemCalList::StgIac::JNUM) || (diffitems.size() > 1)) {
			muteRefresh = true;

			qry->rerun(dbswzem);

			refresh(dbswzem, moditems, true);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWzemCalList::StgIac::JNUM)) {
			if (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);
			xchg->triggerIxRefCall(dbswzem, VecWzemVCall::CALLWZEMREFPRESET, jref, VecWzemVPreset::PREWZEMREFCAL, refSelNew);
		};
	};

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemCalList::handleDpchAppDoButMinimizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	minimize(dbswzem, true, dpcheng);
};

void PnlWzemCalList::handleDpchAppDoButRegularizeClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	regularize(dbswzem, true, dpcheng);
};

void PnlWzemCalList::handleDpchAppDoButNewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButNewClick --- INSERT
};

void PnlWzemCalList::handleDpchAppDoButDeleteClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButDeleteClick --- INSERT
};

void PnlWzemCalList::handleDpchAppDoButFilterClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButFilterClick --- INSERT
};

void PnlWzemCalList::handleDpchAppDoButRefreshClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	set<uint> moditems;

	muteRefresh = true;

	qry->rerun(dbswzem, false);

	refresh(dbswzem, moditems, true);

	insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemCalList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMSTATCHG) {
		call->abort = handleCallWzemStatChg(dbswzem, call->jref);
	};
};

bool PnlWzemCalList::handleCallWzemStatChg(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzemStatChg --- BEGIN

	set<uint> moditems;

	if (jrefTrig == qry->jref) {
		if (!muteRefresh) {
			refresh(dbswzem, moditems);
			if (qry->ixWzemVQrystate == VecWzemVQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
		};
	};

	// IP handleCallWzemStatChg --- END
	return retval;
};
