/**
	* \file QryWzemUsrList.cpp
	* job handler for job QryWzemUsrList (implementation)
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

#include "QryWzemUsrList.h"

#include "QryWzemUsrList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemUsrList
 ******************************************************************************/

QryWzemUsrList::QryWzemUsrList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMUSRLIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMUSRMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemUsrList::~QryWzemUsrList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemUsrList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMUSRUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMUSRUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzemUsrList::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWzemVPreset::PREWZEMUSRLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWzemVPreset::PREWZEMUSRLIST_OWN, jref);
	ubigint prePrs = xchg->getRefPreset(VecWzemVPreset::PREWZEMUSRLIST_PRS, jref);
	string preSrf = xchg->getSrefPreset(VecWzemVPreset::PREWZEMUSRLIST_SRF, jref);
	ubigint preUsg = xchg->getRefPreset(VecWzemVPreset::PREWZEMUSRLIST_USG, jref);
	uint preSte = xchg->getIxPreset(VecWzemVPreset::PREWZEMUSRLIST_STE, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqusrlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMUser.ref)";
	sqlstr += " FROM TblWzemMUser, TblWzemQSelect";
	sqlstr += " WHERE TblWzemQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzemMUser.grp = TblWzemQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzemMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQUsrList(jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMUser.ref, TblWzemMUser.grp, TblWzemMUser.own, TblWzemMUser.refWzemMPerson, TblWzemMUser.sref, TblWzemMUser.refWzemMUsergroup, TblWzemMUser.ixVState, TblWzemMUser.ixWzemVLocale, TblWzemMUser.ixWzemVUserlevel";
	sqlstr += " FROM TblWzemMUser, TblWzemQSelect";
	sqlstr += " WHERE TblWzemQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzemMUser.grp = TblWzemQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzemMUser.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, prePrs, preSrf, preUsg, preSte, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQUsrList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

};

void QryWzemUsrList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const ubigint prePrs
			, const string& preSrf
			, const ubigint preUsg
			, const uint preSte
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMUser.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMUser.own = " + to_string(preOwn) + "";
	};

	if (prePrs != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMUser.refWzemMPerson = " + to_string(prePrs) + "";
	};

	if (preSrf.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMUser.sref = '" + preSrf + "'";
	};

	if (preUsg != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMUser.refWzemMUsergroup = " + to_string(preUsg) + "";
	};

	if (preSte != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMUser.ixVState = " + to_string(preSte) + "";
	};
};

void QryWzemUsrList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemUsrList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STE) sqlstr += " ORDER BY TblWzemMUser.ixVState ASC";
	else if (preIxOrd == VecVOrd::USG) sqlstr += " ORDER BY TblWzemMUser.refWzemMUsergroup ASC";
	else if (preIxOrd == VecVOrd::SRF) sqlstr += " ORDER BY TblWzemMUser.sref ASC";
	else if (preIxOrd == VecVOrd::PRS) sqlstr += " ORDER BY TblWzemMUser.refWzemMPerson ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWzemMUser.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWzemMUser.grp ASC";
};

void QryWzemUsrList::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQUsrList* rec = NULL;

	dbswzem->tblwzemqusrlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubGrp = StubWzem::getStubGroup(dbswzem, rec->grp, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubOwn = StubWzem::getStubOwner(dbswzem, rec->own, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWzemMPerson = StubWzem::getStubPrsStd(dbswzem, rec->refWzemMPerson, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubRefWzemMUsergroup = StubWzem::getStubUsgStd(dbswzem, rec->refWzemMUsergroup, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxVState = VecWzemVMUserState::getSref(rec->ixVState);
			rec->titIxVState = VecWzemVMUserState::getTitle(rec->ixVState, ixWzemVLocale);
			rec->srefIxWzemVLocale = VecWzemVLocale::getSref(rec->ixWzemVLocale);
			rec->titIxWzemVLocale = VecWzemVLocale::getTitle(rec->ixWzemVLocale, ixWzemVLocale);
			rec->srefIxWzemVUserlevel = VecWzemVUserlevel::getSref(rec->ixWzemVUserlevel);
			rec->titIxWzemVUserlevel = VecWzemVUserlevel::getTitle(rec->ixWzemVUserlevel, ixWzemVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemUsrList", "fetch");
	};

	refreshJnum();
};

uint QryWzemUsrList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemUsrList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQUsrList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQUsrList* QryWzemUsrList::getRecByJnum(
			const uint jnum
		) {
	WzemQUsrList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemUsrList::handleRequest(
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

bool QryWzemUsrList::handleRerun(
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

bool QryWzemUsrList::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQUsrList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\trefWzemMPerson";
	cout << "\tstubRefWzemMPerson";
	cout << "\tsref";
	cout << "\trefWzemMUsergroup";
	cout << "\tstubRefWzemMUsergroup";
	cout << "\tixVState";
	cout << "\tsrefIxVState";
	cout << "\ttitIxVState";
	cout << "\tixWzemVLocale";
	cout << "\tsrefIxWzemVLocale";
	cout << "\ttitIxWzemVLocale";
	cout << "\tixWzemVUserlevel";
	cout << "\tsrefIxWzemVUserlevel";
	cout << "\ttitIxWzemVUserlevel";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->grp;
		cout << "\t" << rec->stubGrp;
		cout << "\t" << rec->own;
		cout << "\t" << rec->stubOwn;
		cout << "\t" << rec->refWzemMPerson;
		cout << "\t" << rec->stubRefWzemMPerson;
		cout << "\t" << rec->sref;
		cout << "\t" << rec->refWzemMUsergroup;
		cout << "\t" << rec->stubRefWzemMUsergroup;
		cout << "\t" << rec->ixVState;
		cout << "\t" << rec->srefIxVState;
		cout << "\t" << rec->titIxVState;
		cout << "\t" << rec->ixWzemVLocale;
		cout << "\t" << rec->srefIxWzemVLocale;
		cout << "\t" << rec->titIxWzemVLocale;
		cout << "\t" << rec->ixWzemVUserlevel;
		cout << "\t" << rec->srefIxWzemVUserlevel;
		cout << "\t" << rec->titIxWzemVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWzemUsrList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSRUPD_REFEQ) {
		call->abort = handleCallWzemUsrUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSRMOD) {
		call->abort = handleCallWzemUsrMod(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemUsrList::handleCallWzemUsrUpd_refEq(
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

bool QryWzemUsrList::handleCallWzemUsrMod(
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

bool QryWzemUsrList::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};
