/**
	* \file QryWzemEvtList.cpp
	* job handler for job QryWzemEvtList (implementation)
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

#include "QryWzemEvtList.h"

#include "QryWzemEvtList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemEvtList
 ******************************************************************************/

QryWzemEvtList::QryWzemEvtList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMEVTLIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMEVTMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemEvtList::~QryWzemEvtList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemEvtList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMEVTUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMEVTUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzemEvtList::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);
	uint preTyp = xchg->getIxPreset(VecWzemVPreset::PREWZEMEVTLIST_TYP, jref);
	ubigint prePrd = xchg->getRefPreset(VecWzemVPreset::PREWZEMEVTLIST_PRD, jref);
	double preSta = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMEVTLIST_STA, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqevtlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMEvent.ref)";
	sqlstr += " FROM TblWzemMEvent";
	rerun_filtSQL(sqlstr, preTyp, prePrd, preSta, true);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQEvtList(jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMEvent.ref, TblWzemMEvent.ixVBasetype, TblWzemMEvent.refWzemMPeriod, TblWzemMEvent.startu, TblWzemMEvent.refWzemMDpch, TblWzemMEvent.Cmd, TblWzemMEvent.srefIxVFeatgroup, TblWzemMEvent.srefIxVMethod, TblWzemMEvent.xsref";
	sqlstr += " FROM TblWzemMEvent";
	rerun_filtSQL(sqlstr, preTyp, prePrd, preSta, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQEvtList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

};

void QryWzemEvtList::rerun_filtSQL(
			string& sqlstr
			, const uint preTyp
			, const ubigint prePrd
			, const double preSta
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preTyp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMEvent.ixVBasetype = " + to_string(preTyp) + "";
	};

	if (prePrd != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMEvent.refWzemMPeriod = " + to_string(prePrd) + "";
	};

	if (preSta != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMEvent.startu = " + to_string(preSta) + "";
	};
};

void QryWzemEvtList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemEvtList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblWzemMEvent.startu ASC";
	else if (preIxOrd == VecVOrd::PRD) sqlstr += " ORDER BY TblWzemMEvent.refWzemMPeriod ASC";
	else if (preIxOrd == VecVOrd::TYP) sqlstr += " ORDER BY TblWzemMEvent.ixVBasetype ASC";
};

void QryWzemEvtList::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQEvtList* rec = NULL;

	dbswzem->tblwzemqevtlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefIxVBasetype = VecWzemVMEventBasetype::getSref(rec->ixVBasetype);
			rec->stubRefWzemMPeriod = StubWzem::getStubPrdStd(dbswzem, rec->refWzemMPeriod, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemEvtList", "fetch");
	};

	refreshJnum();
};

uint QryWzemEvtList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQEvtList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemEvtList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQEvtList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQEvtList* QryWzemEvtList::getRecByJnum(
			const uint jnum
		) {
	WzemQEvtList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemEvtList::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
	if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\trerun" << endl;
			cout << "\tshow" << endl;
		} else if (req->cmd == "rerun") {
			req->retain = handleRerun(dbswzem);

		} else if (req->cmd == "show") {
			req->retain = handleShow(dbswzem);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool QryWzemEvtList::handleRerun(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	string input;

	cout << "\tjnumFirstload (" << stgiac.jnumFirstload << "): ";
	cin >> input;
	stgiac.jnumFirstload = atol(input.c_str());
	cout << "\tnload (" << stgiac.nload << "): ";
	cin >> input;
	stgiac.nload = atol(input.c_str());

	rerun(dbswzem);
	return retval;
};

bool QryWzemEvtList::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQEvtList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tixVBasetype";
	cout << "\tsrefIxVBasetype";
	cout << "\trefWzemMPeriod";
	cout << "\tstubRefWzemMPeriod";
	cout << "\tstartu";
	cout << "\trefWzemMDpch";
	cout << "\tCmd";
	cout << "\tsrefIxVFeatgroup";
	cout << "\tsrefIxVMethod";
	cout << "\txsref";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixVBasetype;
		cout << "\t" << rec->srefIxVBasetype;
		cout << "\t" << rec->refWzemMPeriod;
		cout << "\t" << rec->stubRefWzemMPeriod;
		cout << "\t" << rec->startu;
		cout << "\t" << rec->refWzemMDpch;
		cout << "\t" << rec->Cmd;
		cout << "\t" << rec->srefIxVFeatgroup;
		cout << "\t" << rec->srefIxVMethod;
		cout << "\t" << rec->xsref;
		cout << endl;
	};
	return retval;
};

void QryWzemEvtList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMEVTUPD_REFEQ) {
		call->abort = handleCallWzemEvtUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVTMOD) {
		call->abort = handleCallWzemEvtMod(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemEvtList::handleCallWzemEvtUpd_refEq(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if (ixWzemVQrystate != VecWzemVQrystate::OOD) {
		ixWzemVQrystate = VecWzemVQrystate::OOD;
		xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);
	};

	return retval;
};

bool QryWzemEvtList::handleCallWzemEvtMod(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;

	if ((ixWzemVQrystate == VecWzemVQrystate::UTD) || (ixWzemVQrystate == VecWzemVQrystate::SLM)) {
		ixWzemVQrystate = VecWzemVQrystate::MNR;
		xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);
	};

	return retval;
};

bool QryWzemEvtList::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};







