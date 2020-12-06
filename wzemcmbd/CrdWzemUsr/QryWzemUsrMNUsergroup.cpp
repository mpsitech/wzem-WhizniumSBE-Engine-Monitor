/**
	* \file QryWzemUsrMNUsergroup.cpp
	* job handler for job QryWzemUsrMNUsergroup (implementation)
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

#include "QryWzemUsrMNUsergroup.h"

#include "QryWzemUsrMNUsergroup_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemUsrMNUsergroup
 ******************************************************************************/

QryWzemUsrMNUsergroup::QryWzemUsrMNUsergroup(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMUSRMNUSERGROUP, jrefSup, ixWzemVLocale)
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

QryWzemUsrMNUsergroup::~QryWzemUsrMNUsergroup() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemUsrMNUsergroup::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzemUsrMNUsergroup::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSR, jref);

	xchg->removeClstns(VecWzemVCall::CALLWZEMUSRRUSGMOD_USREQ, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqusrmnusergroup->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemRMUserMUsergroup.ref)";
	sqlstr += " FROM TblWzemMUsergroup, TblWzemRMUserMUsergroup";
	sqlstr += " WHERE TblWzemRMUserMUsergroup.refWzemMUsergroup = TblWzemMUsergroup.ref";
	sqlstr += " AND TblWzemRMUserMUsergroup.refWzemMUser = " + to_string(preRefUsr) + "";
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQUsrMNUsergroup(jref, jnum, mref, ref, ixWzemVUserlevel)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMUsergroup.ref, TblWzemRMUserMUsergroup.ref, TblWzemRMUserMUsergroup.ixWzemVUserlevel";
	sqlstr += " FROM TblWzemMUsergroup, TblWzemRMUserMUsergroup";
	sqlstr += " WHERE TblWzemRMUserMUsergroup.refWzemMUsergroup = TblWzemMUsergroup.ref";
	sqlstr += " AND TblWzemRMUserMUsergroup.refWzemMUser = " + to_string(preRefUsr) + "";
	sqlstr += " ORDER BY TblWzemMUsergroup.sref ASC";
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQUsrMNUsergroup SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

	xchg->addRefClstn(VecWzemVCall::CALLWZEMUSRRUSGMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWzemUsrMNUsergroup::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQUsrMNUsergroup* rec = NULL;

	dbswzem->tblwzemqusrmnusergroup->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubMref = StubWzem::getStubUsgStd(dbswzem, rec->mref, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->srefIxWzemVUserlevel = VecWzemVUserlevel::getSref(rec->ixWzemVUserlevel);
			rec->titIxWzemVUserlevel = VecWzemVUserlevel::getTitle(rec->ixWzemVUserlevel, ixWzemVLocale);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemUsrMNUsergroup", "fetch");
	};

	refreshJnum();
};

uint QryWzemUsrMNUsergroup::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemUsrMNUsergroup::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQUsrMNUsergroup* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQUsrMNUsergroup* QryWzemUsrMNUsergroup::getRecByJnum(
			const uint jnum
		) {
	WzemQUsrMNUsergroup* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemUsrMNUsergroup::handleRequest(
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

bool QryWzemUsrMNUsergroup::handleRerun(
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

bool QryWzemUsrMNUsergroup::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQUsrMNUsergroup* rec = NULL;

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

void QryWzemUsrMNUsergroup::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSRRUSGMOD_USREQ) {
		call->abort = handleCallWzemUsrRusgMod_usrEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemUsrMNUsergroup::handleCallWzemUsrRusgMod_usrEq(
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

bool QryWzemUsrMNUsergroup::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};
