/**
	* \file QryWzemJob1NClstn.cpp
	* job handler for job QryWzemJob1NClstn (implementation)
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

#include "QryWzemJob1NClstn.h"

#include "QryWzemJob1NClstn_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemJob1NClstn
 ******************************************************************************/

QryWzemJob1NClstn::QryWzemJob1NClstn(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMJOB1NCLSTN, jrefSup, ixWzemVLocale)
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

QryWzemJob1NClstn::~QryWzemJob1NClstn() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemJob1NClstn::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzemJob1NClstn::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefJob = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFJOB, jref);
	double preX1 = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMJOB1NCLSTN_X1, jref);

	xchg->removeClstns(VecWzemVCall::CALLWZEMCLNMOD_JOBEQ, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqjob1nclstn->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMClstn.ref)";
	sqlstr += " FROM TblWzemMClstn";
	sqlstr += " WHERE TblWzemMClstn.refWzemMJob = " + to_string(preRefJob) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQJob1NClstn(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMClstn.ref";
	sqlstr += " FROM TblWzemMClstn";
	sqlstr += " WHERE TblWzemMClstn.refWzemMJob = " + to_string(preRefJob) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQJob1NClstn SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

	xchg->addRefClstn(VecWzemVCall::CALLWZEMCLNMOD_JOBEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefJob);
};

void QryWzemJob1NClstn::rerun_filtSQL(
			string& sqlstr
			, const double preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMClstn.x1Startu <= " + to_string(preX1) + "";
	};

	if (preX1 != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMClstn.x1Stopu >= " + to_string(preX1) + "";
	};
};

void QryWzemJob1NClstn::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemJob1NClstn::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQJob1NClstn* rec = NULL;

	dbswzem->tblwzemqjob1nclstn->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWzem::getStubClnStd(dbswzem, rec->ref, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemJob1NClstn", "fetch");
	};

	refreshJnum();
};

uint QryWzemJob1NClstn::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQJob1NClstn* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemJob1NClstn::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQJob1NClstn* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQJob1NClstn* QryWzemJob1NClstn::getRecByJnum(
			const uint jnum
		) {
	WzemQJob1NClstn* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemJob1NClstn::handleRequest(
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

bool QryWzemJob1NClstn::handleRerun(
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

bool QryWzemJob1NClstn::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQJob1NClstn* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tstubRef";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->stubRef;
		cout << endl;
	};
	return retval;
};

void QryWzemJob1NClstn::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMCLNMOD_JOBEQ) {
		call->abort = handleCallWzemClnMod_jobEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemJob1NClstn::handleCallWzemClnMod_jobEq(
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

bool QryWzemJob1NClstn::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};







