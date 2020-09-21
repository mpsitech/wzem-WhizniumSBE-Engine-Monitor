/**
	* \file QryWzemPrd1NNode.cpp
	* job handler for job QryWzemPrd1NNode (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "QryWzemPrd1NNode.h"

#include "QryWzemPrd1NNode_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemPrd1NNode
 ******************************************************************************/

QryWzemPrd1NNode::QryWzemPrd1NNode(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMPRD1NNODE, jrefSup, ixWzemVLocale)
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

QryWzemPrd1NNode::~QryWzemPrd1NNode() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemPrd1NNode::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzemPrd1NNode::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefPrd = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref);
	double preX1 = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMPRD1NNODE_X1, jref);

	xchg->removeClstns(VecWzemVCall::CALLWZEMNDEMOD_PRDEQ, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqprd1nnode->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemMNode.ref)";
	sqlstr += " FROM TblWzemMNode";
	sqlstr += " WHERE TblWzemMNode.refWzemMPeriod = " + to_string(preRefPrd) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQPrd1NNode(jref, jnum, ref)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMNode.ref";
	sqlstr += " FROM TblWzemMNode";
	sqlstr += " WHERE TblWzemMNode.refWzemMPeriod = " + to_string(preRefPrd) + "";
	rerun_filtSQL(sqlstr, preX1, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQPrd1NNode SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

	xchg->addRefClstn(VecWzemVCall::CALLWZEMNDEMOD_PRDEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefPrd);
};

void QryWzemPrd1NNode::rerun_filtSQL(
			string& sqlstr
			, const double preX1
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMNode.x1Startu <= " + to_string(preX1) + "";
	};

	if (preX1 != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMNode.x1Stopu >= " + to_string(preX1) + "";
	};
};

void QryWzemPrd1NNode::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemPrd1NNode::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQPrd1NNode* rec = NULL;

	dbswzem->tblwzemqprd1nnode->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->stubRef = StubWzem::getStubNdeStd(dbswzem, rec->ref, ixWzemVLocale, Stub::VecVNonetype::SHORT, stcch);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemPrd1NNode", "fetch");
	};

	refreshJnum();
};

uint QryWzemPrd1NNode::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQPrd1NNode* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemPrd1NNode::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQPrd1NNode* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQPrd1NNode* QryWzemPrd1NNode::getRecByJnum(
			const uint jnum
		) {
	WzemQPrd1NNode* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemPrd1NNode::handleRequest(
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

bool QryWzemPrd1NNode::handleRerun(
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

bool QryWzemPrd1NNode::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQPrd1NNode* rec = NULL;

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

void QryWzemPrd1NNode::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMNDEMOD_PRDEQ) {
		call->abort = handleCallWzemNdeMod_prdEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemPrd1NNode::handleCallWzemNdeMod_prdEq(
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

bool QryWzemPrd1NNode::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};

