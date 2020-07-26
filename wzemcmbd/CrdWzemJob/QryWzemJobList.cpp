/**
	* \file QryWzemJobList.cpp
	* job handler for job QryWzemJobList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "QryWzemJobList.h"

#include "QryWzemJobList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemJobList
 ******************************************************************************/

QryWzemJobList::QryWzemJobList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMJOBLIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMJOBMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemJobList::~QryWzemJobList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemJobList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMJOBUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMJOBUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzemJobList::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	uint preIxOrd = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);
	ubigint prePrd = xchg->getRefPreset(VecWzemVPreset::PREWZEMJOBLIST_PRD, jref);
	double preSta = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMJOBLIST_STA, jref);
	double preSto = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMJOBLIST_STO, jref);
	ubigint preSup = xchg->getRefPreset(VecWzemVPreset::PREWZEMJOBLIST_SUP, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqjoblist->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMJob.ref)";
	sqlstr += " FROM TblWzemMJob";
	rerun_filtSQL(sqlstr, prePrd, preSta, preSto, preSup, true);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQJobList(jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMJob.ref, TblWzemMJob.refWzemMPeriod, TblWzemMJob.srefIxVJob, TblWzemMJob.xjref, TblWzemMJob.x1Startu, TblWzemMJob.x1Stopu, TblWzemMJob.supRefWzemMJob";
	sqlstr += " FROM TblWzemMJob";
	rerun_filtSQL(sqlstr, prePrd, preSta, preSto, preSup, true);
	rerun_orderSQL(sqlstr, preIxOrd);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQJobList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

};

void QryWzemJobList::rerun_filtSQL(
			string& sqlstr
			, const ubigint prePrd
			, const double preSta
			, const double preSto
			, const ubigint preSup
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePrd != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMJob.refWzemMPeriod = " + to_string(prePrd) + "";
	};

	if (preSta != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMJob.x1Startu = " + to_string(preSta) + "";
	};

	if (preSto != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMJob.x1Stopu = " + to_string(preSto) + "";
	};

	if (preSup != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMJob.supRefWzemMJob = " + to_string(preSup) + "";
	};
};

void QryWzemJobList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemJobList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::SUP) sqlstr += " ORDER BY TblWzemMJob.supRefWzemMJob ASC";
	else if (preIxOrd == VecVOrd::STO) sqlstr += " ORDER BY TblWzemMJob.x1Stopu ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblWzemMJob.x1Startu ASC";
	else if (preIxOrd == VecVOrd::PRD) sqlstr += " ORDER BY TblWzemMJob.refWzemMPeriod ASC";
};

void QryWzemJobList::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQJobList* rec = NULL;

	dbswzem->tblwzemqjoblist->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRefWzemMPeriod = StubWzem::getStubPrdStd(dbswzem, rec->refWzemMPeriod, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
			rec->stubSupRefWzemMJob = StubWzem::getStubJobStd(dbswzem, rec->supRefWzemMJob, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemJobList", "fetch");
	};

	refreshJnum();
};

uint QryWzemJobList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQJobList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemJobList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQJobList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQJobList* QryWzemJobList::getRecByJnum(
			const uint jnum
		) {
	WzemQJobList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemJobList::handleRequest(
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

bool QryWzemJobList::handleRerun(
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

bool QryWzemJobList::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQJobList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefWzemMPeriod";
	cout << "\tstubRefWzemMPeriod";
	cout << "\tsrefIxVJob";
	cout << "\txjref";
	cout << "\tx1Startu";
	cout << "\tx1Stopu";
	cout << "\tsupRefWzemMJob";
	cout << "\tstubSupRefWzemMJob";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->refWzemMPeriod;
		cout << "\t" << rec->stubRefWzemMPeriod;
		cout << "\t" << rec->srefIxVJob;
		cout << "\t" << rec->xjref;
		cout << "\t" << rec->x1Startu;
		cout << "\t" << rec->x1Stopu;
		cout << "\t" << rec->supRefWzemMJob;
		cout << "\t" << rec->stubSupRefWzemMJob;
		cout << endl;
	};
	return retval;
};

void QryWzemJobList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMJOBUPD_REFEQ) {
		call->abort = handleCallWzemJobUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOBMOD) {
		call->abort = handleCallWzemJobMod(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemJobList::handleCallWzemJobUpd_refEq(
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

bool QryWzemJobList::handleCallWzemJobMod(
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

bool QryWzemJobList::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};

