/**
	* \file PnlWzemUsrMNUsergroup.cpp
	* job handler for job PnlWzemUsrMNUsergroup (implementation)
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

#include "PnlWzemUsrMNUsergroup.h"

#include "PnlWzemUsrMNUsergroup_blks.cpp"
#include "PnlWzemUsrMNUsergroup_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzemUsrMNUsergroup
 ******************************************************************************/

PnlWzemUsrMNUsergroup::PnlWzemUsrMNUsergroup(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::PNLWZEMUSRMNUSERGROUP, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFCsiQst.tag = "FeedFCsiQst";
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::MNR, "ong", VecWzemVQrystate::getTitle(VecWzemVQrystate::MNR, ixWzemVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::OOD, "red", VecWzemVQrystate::getTitle(VecWzemVQrystate::OOD, ixWzemVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::SLM, "yel", VecWzemVQrystate::getTitle(VecWzemVQrystate::SLM, ixWzemVLocale));
	feedFCsiQst.appendIxSrefTitles(VecWzemVQrystate::UTD, "grn", VecWzemVQrystate::getTitle(VecWzemVQrystate::UTD, ixWzemVLocale));

	qry = NULL;

	// IP constructor.cust1 --- INSERT

	xchg->addRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref, 0);

	qry = new QryWzemUsrMNUsergroup(xchg, dbswzem, jref, ixWzemVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzem, moditems);

	xchg->addClstn(VecWzemVCall::CALLWZEMSTATCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

};

PnlWzemUsrMNUsergroup::~PnlWzemUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* PnlWzemUsrMNUsergroup::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFCsiQst, &statshr, &stgiac, &(qry->rst), &(qry->statshr), &(qry->stgiac), items);
	};

	return dpcheng;
};

void PnlWzemUsrMNUsergroup::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ixWzemVQrystate);

	// statshr
	statshr.ButViewAvail = evalButViewAvail(dbswzem);
	statshr.ButViewActive = evalButViewActive(dbswzem);
	statshr.ButAddAvail = evalButAddAvail(dbswzem);
	statshr.ButSubAvail = evalButSubAvail(dbswzem);
	statshr.ButSubActive = evalButSubActive(dbswzem);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzemUsrMNUsergroup::updatePreset(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFUSR) {
		recUsrRusg = WzemRMUserMUsergroup();

		recUsg = WzemMUsergroup();

		xchg->addRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref, 0);

		qry->stgiac.jnumFirstload = 1;

		qry->rerun(dbswzem);
		refresh(dbswzem, moditems);

		if (notif) {
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});
			xchg->submitDpch(getNewDpchEng(moditems));
		};
	};
	// IP updatePreset --- END
};

void PnlWzemUsrMNUsergroup::handleRequest(
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

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRMNUSERGROUPDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::STGIAC)) {
				handleDpchAppDataStgiac(dbswzem, &(dpchappdata->stgiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::STGIACQRY)) {
				handleDpchAppDataStgiacqry(dbswzem, &(dpchappdata->stgiacqry), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRMNUSERGROUPDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTVIEWCLICK) {
					handleDpchAppDoButViewClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTADDCLICK) {
					handleDpchAppDoButAddClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSUBCLICK) {
					handleDpchAppDoButSubClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREFRESHCLICK) {
					handleDpchAppDoButRefreshClick(dbswzem, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzemUsrMNUsergroup::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzemUsrMNUsergroup::handleDpchAppDataStgiac(
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

void PnlWzemUsrMNUsergroup::handleDpchAppDataStgiacqry(
			DbsWzem* dbswzem
			, QryWzemUsrMNUsergroup::StgIac* _stgiacqry
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _stgiacqry->diff(&(qry->stgiac));

	WzemQUsrMNUsergroup* recSelNew = NULL;

	WzemRMUserMUsergroup* _recUsrRusg = NULL;
	WzemMUsergroup* _recUsg = NULL;

	if (!diffitems.empty()) {
		muteRefresh = true;

		qry->stgiac = *_stgiacqry;

		if (has(diffitems, QryWzemUsrMNUsergroup::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

		if (!has(diffitems, QryWzemUsrMNUsergroup::StgIac::JNUM) || (diffitems.size() > 1)) {
			qry->rerun(dbswzem);
			insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});
		};

		if (has(diffitems, QryWzemUsrMNUsergroup::StgIac::JNUM)) {
			if (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);

			recUsrRusg = WzemRMUserMUsergroup();

			recUsg = WzemMUsergroup();

			if (recSelNew) {
				if (dbswzem->tblwzemrmusermusergroup->loadRecByRef(recSelNew->ref, &_recUsrRusg)) {
					recUsrRusg = *_recUsrRusg;
					delete _recUsrRusg;
				};
				if (dbswzem->tblwzemmusergroup->loadRecByRef(recSelNew->mref, &_recUsg)) {
					recUsg = *_recUsg;
					delete _recUsg;
				};
			};

			xchg->addRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));
			qry->refreshJnum();
		};

		refresh(dbswzem, moditems, true);
	};

	insert(moditems, DpchEngData::STGIACQRY);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzemUsrMNUsergroup::handleDpchAppDoButViewClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButViewAvail && statshr.ButViewActive) {
		if (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref)) {
			sref = "CrdWzemUsg";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswzem, VecWzemVCall::CALLWZEMCRDOPEN, jref, 0, 0, sref, recUsg.ref, jrefNew);
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWzemConfirm(false, 0, "");
		else *dpcheng = new DpchEngWzemConfirm(true, jrefNew, sref);
	};
};

void PnlWzemUsrMNUsergroup::handleDpchAppDoButAddClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButAddClick --- INSERT
};

void PnlWzemUsrMNUsergroup::handleDpchAppDoButSubClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButSubClick --- INSERT
};

void PnlWzemUsrMNUsergroup::handleDpchAppDoButRefreshClick(
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

void PnlWzemUsrMNUsergroup::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMSTATCHG) {
		call->abort = handleCallWzemStatChg(dbswzem, call->jref);
	};
};

bool PnlWzemUsrMNUsergroup::handleCallWzemStatChg(
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







