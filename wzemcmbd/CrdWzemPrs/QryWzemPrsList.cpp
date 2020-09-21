/**
	* \file QryWzemPrsList.cpp
	* job handler for job QryWzemPrsList (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "QryWzemPrsList.h"

#include "QryWzemPrsList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemPrsList
 ******************************************************************************/

QryWzemPrsList::QryWzemPrsList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMPRSLIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMPRSMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemPrsList::~QryWzemPrsList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemPrsList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMPRSUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMPRSUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzemPrsList::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	bool preNoadm = xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMNOADM, jref);
	ubigint preOwner = xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref);
	ubigint preJrefSess = xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);
	ubigint preGrp = xchg->getRefPreset(VecWzemVPreset::PREWZEMPRSLIST_GRP, jref);
	ubigint preOwn = xchg->getRefPreset(VecWzemVPreset::PREWZEMPRSLIST_OWN, jref);
	string preLnm = xchg->getTxtvalPreset(VecWzemVPreset::PREWZEMPRSLIST_LNM, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqprslist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMPerson.ref)";
	sqlstr += " FROM TblWzemMPerson, TblWzemQSelect";
	sqlstr += " WHERE TblWzemQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzemMPerson.grp = TblWzemQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzemMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQPrsList(jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMPerson.ref, TblWzemMPerson.grp, TblWzemMPerson.own, TblWzemMPerson.Title, TblWzemMPerson.Firstname, TblWzemMPerson.Lastname, TblWzemMPerson.ixVSex, TblWzemMPerson.telVal, TblWzemMPerson.emlVal";
	sqlstr += " FROM TblWzemMPerson, TblWzemQSelect";
	sqlstr += " WHERE TblWzemQSelect.jref = " + to_string(preJrefSess) + "";
	sqlstr += " AND TblWzemMPerson.grp = TblWzemQSelect.ref";
	sqlstr += " AND " + [preNoadm,preOwner](){if (preNoadm) return("TblWzemMPerson.own = " + to_string(preOwner) + ""); else return(string("1"));}() + "";
	rerun_filtSQL(sqlstr, preGrp, preOwn, preLnm, false);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQPrsList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

};

void QryWzemPrsList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preGrp
			, const ubigint preOwn
			, const string& preLnm
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preGrp != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMPerson.grp = " + to_string(preGrp) + "";
	};

	if (preOwn != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMPerson.own = " + to_string(preOwn) + "";
	};

	if (preLnm.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMPerson.Lastname LIKE '" + preLnm + "'";
	};
};

void QryWzemPrsList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemPrsList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::LNM) sqlstr += " ORDER BY TblWzemMPerson.Lastname ASC";
	else if (preIxOrd == VecVOrd::OWN) sqlstr += " ORDER BY TblWzemMPerson.own ASC";
	else if (preIxOrd == VecVOrd::GRP) sqlstr += " ORDER BY TblWzemMPerson.grp ASC";
};

void QryWzemPrsList::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQPrsList* rec = NULL;

	dbswzem->tblwzemqprslist->loadRstByJref(jref, false, rst);
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
			rec->srefIxVSex = VecWzemVMPersonSex::getSref(rec->ixVSex);
			rec->titIxVSex = VecWzemVMPersonSex::getTitle(rec->ixVSex, ixWzemVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemPrsList", "fetch");
	};

	refreshJnum();
};

uint QryWzemPrsList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemPrsList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQPrsList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQPrsList* QryWzemPrsList::getRecByJnum(
			const uint jnum
		) {
	WzemQPrsList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemPrsList::handleRequest(
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

bool QryWzemPrsList::handleRerun(
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

bool QryWzemPrsList::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQPrsList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tgrp";
	cout << "\tstubGrp";
	cout << "\town";
	cout << "\tstubOwn";
	cout << "\tTitle";
	cout << "\tFirstname";
	cout << "\tLastname";
	cout << "\tixVSex";
	cout << "\tsrefIxVSex";
	cout << "\ttitIxVSex";
	cout << "\ttelVal";
	cout << "\temlVal";
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
		cout << "\t" << rec->Title;
		cout << "\t" << rec->Firstname;
		cout << "\t" << rec->Lastname;
		cout << "\t" << rec->ixVSex;
		cout << "\t" << rec->srefIxVSex;
		cout << "\t" << rec->titIxVSex;
		cout << "\t" << rec->telVal;
		cout << "\t" << rec->emlVal;
		cout << endl;
	};
	return retval;
};

void QryWzemPrsList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMPRSUPD_REFEQ) {
		call->abort = handleCallWzemPrsUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPRSMOD) {
		call->abort = handleCallWzemPrsMod(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemPrsList::handleCallWzemPrsUpd_refEq(
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

bool QryWzemPrsList::handleCallWzemPrsMod(
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

bool QryWzemPrsList::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};

