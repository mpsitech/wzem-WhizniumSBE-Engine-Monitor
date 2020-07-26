/**
	* \file QryWzemOpxList.cpp
	* job handler for job QryWzemOpxList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "QryWzemOpxList.h"

#include "QryWzemOpxList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemOpxList
 ******************************************************************************/

QryWzemOpxList::QryWzemOpxList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMOPXLIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMOPXMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemOpxList::~QryWzemOpxList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemOpxList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMOPXUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMOPXUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzemOpxList::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);
	ubigint preJob = xchg->getRefPreset(VecWzemVPreset::PREWZEMOPXLIST_JOB, jref);
	double preSta = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMOPXLIST_STA, jref);
	double preSto = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMOPXLIST_STO, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqopxlist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMOp.ref)";
	sqlstr += " FROM TblWzemMOp";
	rerun_filtSQL(sqlstr, preJob, preSta, preSto, true);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQOpxList(jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMOp.ref, TblWzemMOp.refWzemMJob, TblWzemMOp.xoref, TblWzemMOp.x1Startu, TblWzemMOp.x1Stopu";
	sqlstr += " FROM TblWzemMOp";
	rerun_filtSQL(sqlstr, preJob, preSta, preSto, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQOpxList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

};

void QryWzemOpxList::rerun_filtSQL(
			string& sqlstr
			, const ubigint preJob
			, const double preSta
			, const double preSto
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preJob != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMOp.refWzemMJob = " + to_string(preJob) + "";
	};

	if (preSta != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMOp.x1Startu = " + to_string(preSta) + "";
	};

	if (preSto != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMOp.x1Stopu = " + to_string(preSto) + "";
	};
};

void QryWzemOpxList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemOpxList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STO) sqlstr += " ORDER BY TblWzemMOp.x1Stopu ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblWzemMOp.x1Startu ASC";
	else if (preIxOrd == VecVOrd::JOB) sqlstr += " ORDER BY TblWzemMOp.refWzemMJob ASC";
};

void QryWzemOpxList::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQOpxList* rec = NULL;

	dbswzem->tblwzemqopxlist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWzemMJob = StubWzem::getStubJobStd(dbswzem, rec->refWzemMJob, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemOpxList", "fetch");
	};

	refreshJnum();
};

uint QryWzemOpxList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQOpxList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemOpxList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQOpxList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQOpxList* QryWzemOpxList::getRecByJnum(
			const uint jnum
		) {
	WzemQOpxList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemOpxList::handleRequest(
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

bool QryWzemOpxList::handleRerun(
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

bool QryWzemOpxList::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQOpxList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefWzemMJob";
	cout << "\tstubRefWzemMJob";
	cout << "\txoref";
	cout << "\tx1Startu";
	cout << "\tx1Stopu";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refWzemMJob;
		cout << "\t" << rec->stubRefWzemMJob;
		cout << "\t" << rec->xoref;
		cout << "\t" << rec->x1Startu;
		cout << "\t" << rec->x1Stopu;
		cout << endl;
	};
	return retval;
};

void QryWzemOpxList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMOPXMOD) {
		call->abort = handleCallWzemOpxMod(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMOPXUPD_REFEQ) {
		call->abort = handleCallWzemOpxUpd_refEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemOpxList::handleCallWzemOpxMod(
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

bool QryWzemOpxList::handleCallWzemOpxUpd_refEq(
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

bool QryWzemOpxList::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};

