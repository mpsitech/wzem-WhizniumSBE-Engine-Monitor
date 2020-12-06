/**
	* \file QryWzemUsrAAccess.cpp
	* job handler for job QryWzemUsrAAccess (implementation)
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

#include "QryWzemUsrAAccess.h"

#include "QryWzemUsrAAccess_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemUsrAAccess
 ******************************************************************************/

QryWzemUsrAAccess::QryWzemUsrAAccess(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMUSRAACCESS, jrefSup, ixWzemVLocale)
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

QryWzemUsrAAccess::~QryWzemUsrAAccess() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemUsrAAccess::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);
};

void QryWzemUsrAAccess::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	uint cnt;

	ubigint preRefUsr = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSR, jref);
	uint preX1 = xchg->getIxPreset(VecWzemVPreset::PREWZEMUSRAACCESS_X1, jref);
	string preX2 = xchg->getSrefPreset(VecWzemVPreset::PREWZEMUSRAACCESS_X2, jref);

	xchg->removeClstns(VecWzemVCall::CALLWZEMUSRAACCMOD_USREQ, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqusraaccess->removeRstByJref(jref);

	sqlstr = "SELECT COUNT(TblWzemAMUserAccess.ref)";
	sqlstr += " FROM TblWzemAMUserAccess";
	sqlstr += " WHERE TblWzemAMUserAccess.refWzemMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	dbswzem->loadUintBySQL(sqlstr, cnt);

	statshr.ntot = cnt;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cnt) {
		if (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	sqlstr = "INSERT INTO TblWzemQUsrAAccess(jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemAMUserAccess.ref, TblWzemAMUserAccess.x1IxWzemVFeatgroup, TblWzemAMUserAccess.x2FeaSrefUix, TblWzemAMUserAccess.ixWzemWAccess";
	sqlstr += " FROM TblWzemAMUserAccess";
	sqlstr += " WHERE TblWzemAMUserAccess.refWzemMUser = " + to_string(preRefUsr) + "";
	rerun_filtSQL(sqlstr, preX1, preX2, false);
	sqlstr += " LIMIT " + to_string(stgiac.nload) + " OFFSET " + to_string(stgiac.jnumFirstload-1);
	dbswzem->executeQuery(sqlstr);

	sqlstr = "UPDATE TblWzemQUsrAAccess SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

	xchg->addRefClstn(VecWzemVCall::CALLWZEMUSRAACCMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, false, preRefUsr);
};

void QryWzemUsrAAccess::rerun_filtSQL(
			string& sqlstr
			, const uint preX1
			, const string& preX2
			, const bool addwhere
		) {
	bool first = addwhere;

	if (preX1 != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemAMUserAccess.x1IxWzemVFeatgroup = " + to_string(preX1) + "";
	};

	if (preX2.length() > 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemAMUserAccess.x2FeaSrefUix = " + preX2 + "";
	};
};

void QryWzemUsrAAccess::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemUsrAAccess::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQUsrAAccess* rec = NULL;

	dbswzem->tblwzemqusraaccess->loadRstByJref(jref, false, rst);
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
		stmgr->unlockAccess("QryWzemUsrAAccess", "fetch");
	};

	refreshJnum();
};

uint QryWzemUsrAAccess::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemUsrAAccess::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQUsrAAccess* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQUsrAAccess* QryWzemUsrAAccess::getRecByJnum(
			const uint jnum
		) {
	WzemQUsrAAccess* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemUsrAAccess::handleRequest(
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

bool QryWzemUsrAAccess::handleRerun(
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

bool QryWzemUsrAAccess::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQUsrAAccess* rec = NULL;

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

void QryWzemUsrAAccess::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMUSRAACCMOD_USREQ) {
		call->abort = handleCallWzemUsrAaccMod_usrEq(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemUsrAAccess::handleCallWzemUsrAaccMod_usrEq(
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

bool QryWzemUsrAAccess::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};







