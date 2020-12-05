/**
	* \file QryWzemUsgAAccess.cpp
	* job handler for job QryWzemUsgAAccess (implementation)
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

#include "QryWzemUsgAAccess.h"

#include "QryWzemUsgAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemUsgAAccess
 ******************************************************************************/

QryWzemUsgAAccess::QryWzemUsgAAccess(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMUSGAACCESS, jrefSup, ixWzemVLocale)
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

QryWzemUsgAAccess::~QryWzemUsgAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemUsgAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzemUsgAAccess::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsg = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSG, jref);
	uint preX1 = xchg->getIxPreset(VecWzemVPreset::PREWZEMUSGAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWzemVPreset::PREWZEMUSGAACCESS_X2, jref);

	xchg->removeClstns(VecWzemVCall::CALLWZEMUSGAACCMOD_USGEQ, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqusgaaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemAMUsergroupAccess.ref)";
	sqlstr += " FROM TblWzemAMUsergroupAccess";
	sqlstr += " WHERE TblWzemAMUsergroupAccess.refWzemMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQUsgAAccess(jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemAMUsergroupAccess.ref, TblWzemAMUsergroupAccess.x1IxWzemVFeatgroup, TblWzemAMUsergroupAccess.x2FeaSrefUix, TblWzemAMUsergroupAccess.ixWzemWAccess";
	sqlstr += " FROM TblWzemAMUsergroupAccess";
	sqlstr += " WHERE TblWzemAMUsergroupAccess.refWzemMUsergroup = " + to_string(preRefUsg) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQUsgAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

	xchg->addRefClstn(VecWzemVCall::CALLWZEMUSGAACCMOD_USGEQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsg);
};

void QryWzemUsgAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemAMUsergroupAccess.x1IxWzemVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemAMUsergroupAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWzemUsgAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemUsgAAccess::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQUsgAAccess* rec = NULL;

	dbswzem->tblwzemqusgaaccess->loadRstByJref(jref, false, rst);
	statshr.nload = rst.nodes.size();

	stmgr = xchg->getStmgrByJref(jref);

	if (stmgr) {
		stmgr->begin();

		stcch = stmgr->stcch;
		stcch->clear();

		for (unsigned int i = 0; i < rst.nodes.size(); i++) {
			rec = rst.nodes[i];

			rec->jnum = statshr.jnumFirstload + i;
			rec->srefX1IxWzemVFeatgroup = VecWzemVFeatgroup::getSref(rec->x1IxWzemVFeatgroup);
			rec->titX1IxWzemVFeatgroup = VecWzemVFeatgroup::getTitle(rec->x1IxWzemVFeatgroup, ixWzemVLocale);
			rec->srefsIxWzemWAccess = VecWzemWAccess::getSrefs(rec->ixWzemWAccess);
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemUsgAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWzemUsgAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemUsgAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQUsgAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQUsgAAccess* QryWzemUsgAAccess::getRecByJnum(
			const uint jnum
		) {
	WzemQUsgAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemUsgAAccess::handleRequest(
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

bool QryWzemUsgAAccess::handleRerun(
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

bool QryWzemUsgAAccess::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQUsgAAccess* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\tx1IxWzemVFeatgroup";
	cout << "\tsrefX1IxWzemVFeatgroup";
	cout << "\ttitX1IxWzemVFeatgroup";
	cout << "\tx2FeaSrefUix";
	cout << "\tixWzemWAccess";
	cout << "\tsrefsIxWzemWAccess";
	cout << "\ttitsIxWzemWAccess";
	cout << endl;

	// record rows
	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		cout << "\t" << rec->qref;
		cout << "\t" << rec->jref;
		cout << "\t" << rec->jnum;
		cout << "\t" << rec->ref;
		cout << "\t" << rec->x1IxWzemVFeatgroup;
		cout << "\t" << rec->srefX1IxWzemVFeatgroup;
		cout << "\t" << rec->titX1IxWzemVFeatgroup;
		cout << "\t" << rec->x2FeaSrefUix;
		cout << "\t" << rec->ixWzemWAccess;
		cout << "\t" << rec->srefsIxWzemWAccess;
		cout << "\t" << rec->titsIxWzemWAccess;
		cout << endl;
	};
	return retval;
};

void QryWzemUsgAAccess::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSGAACCMOD_USGEQ) {
		call->abort = handleCallWzemUsgAaccMod_usgEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemUsgAAccess::handleCallWzemUsgAaccMod_usgEq(
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

bool QryWzemUsgAAccess::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};

