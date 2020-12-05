/**
	* \file QryWzemUsgMNUser.cpp
	* job handler for job QryWzemUsgMNUser (implementation)
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

#include "QryWzemUsgMNUser.h"

#include "QryWzemUsgMNUser_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemUsgMNUser
 ******************************************************************************/

QryWzemUsgMNUser::QryWzemUsgMNUser(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMUSGMNUSER, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemUsgMNUser::~QryWzemUsgMNUser() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemUsgMNUser::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzemUsgMNUser::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSG, jref);

	xchg->removeClstns(VecWzemVCall::CALLWZEMUSRRUSGMOD_USGEQ, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqusgmnuser->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemRMUserMUsergroup.ref)";
	sqlstr += " FROM TblWzemMUser, TblWzemRMUserMUsergroup";
	sqlstr += " WHERE TblWzemRMUserMUsergroup.refWzemMUser = TblWzemMUser.ref";
	sqlstr += " AND TblWzemRMUserMUsergroup.refWzemMUsergroup = " + to_string(preRefUsg) + "";
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQUsgMNUser(jref, jnum, mref, ref, ixWzemVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMUser.ref, TblWzemRMUserMUsergroup.ref, TblWzemRMUserMUsergroup.ixWzemVUserlevel";
	sqlstr += " FROM TblWzemMUser, TblWzemRMUserMUsergroup";
	sqlstr += " WHERE TblWzemRMUserMUsergroup.refWzemMUser = TblWzemMUser.ref";
	sqlstr += " AND TblWzemRMUserMUsergroup.refWzemMUsergroup = " + to_string(preRefUsg) + "";
	sqlstr += " ORDER BY TblWzemMUser.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQUsgMNUser SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

	xchg->addRefClstn(VecWzemVCall::CALLWZEMUSRRUSGMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsg);
};

void QryWzemUsgMNUser::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQUsgMNUser* rec = NULL;

	dbswzem->tblwzemqusgmnuser->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWzem::getStubUsrStd(dbswzem, rec->mref, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWzemVUserlevel = VecWzemVUserlevel::getSref(rec->ixWzemVUserlevel);
			rec->titIxWzemVUserlevel = VecWzemVUserlevel::getTitle(rec->ixWzemVUserlevel, ixWzemVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemUsgMNUser", "fetch");
	};

	refreshJnum();
};

uint QryWzemUsgMNUser::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQUsgMNUser* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemUsgMNUser::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQUsgMNUser* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQUsgMNUser* QryWzemUsgMNUser::getRecByJnum(
			const uint jnum
		) {
	WzemQUsgMNUser* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemUsgMNUser::handleRequest(
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

bool QryWzemUsgMNUser::handleRerun(
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

bool QryWzemUsgMNUser::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQUsgMNUser* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tmref";
	cout << "\tstubMref";
	cout << "\tref";
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
		cout << "\t" << rec->mref;
		cout << "\t" << rec->stubMref;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->ixWzemVUserlevel;
		cout << "\t" << rec->srefIxWzemVUserlevel;
		cout << "\t" << rec->titIxWzemVUserlevel;
		cout << endl;
	};
	return retval;
};

void QryWzemUsgMNUser::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSRRUSGMOD_USGEQ) {
		call->abort = handleCallWzemUsrRusgMod_usgEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemUsgMNUser::handleCallWzemUsrRusgMod_usgEq(
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

bool QryWzemUsgMNUser::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};

