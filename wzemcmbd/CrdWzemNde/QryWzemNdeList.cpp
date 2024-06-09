/**
	* \file QryWzemNdeList.cpp
	* job handler for job QryWzemNdeList (implementation)
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

#include "QryWzemNdeList.h"

#include "QryWzemNdeList_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class QryWzemNdeList
 ******************************************************************************/

QryWzemNdeList::QryWzemNdeList(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::QRYWZEMNDELIST, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	xchg->addStmgr(jref, Stub::VecVNonetype::SHORT);
	ixWzemVQrystate = VecWzemVQrystate::OOD;

	// IP constructor.cust2 --- INSERT

	rerun(dbswzem);

	xchg->addClstn(VecWzemVCall::CALLWZEMNDEMOD, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSTUBCHG, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

QryWzemNdeList::~QryWzemNdeList() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void QryWzemNdeList::refreshJnum() {
	ubigint preRefSel = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFSEL, jref);

	stgiac.jnum = getJnumByRef(preRefSel);

	if (preRefSel == 0) xchg->removeClstns(VecWzemVCall::CALLWZEMNDEUPD_REFEQ, jref);
	else xchg->addRefClstn(VecWzemVCall::CALLWZEMNDEUPD_REFEQ, jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);
};

void QryWzemNdeList::rerun(
			DbsWzem* dbswzem
			, const bool call
		) {
	string sqlstr;

	vector<ubigint> cnts;
	uint cnt, cntsum;

	vector<ubigint> lims;
	vector<ubigint> ofss;

	uint preIxPre = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXPRE, jref);
	uint preIxOrd = xchg->getIxPreset(VecWzemVPreset::PREWZEMIXORD, jref);
	ubigint preRefPrd = xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref);
	ubigint prePrd = xchg->getRefPreset(VecWzemVPreset::PREWZEMNDELIST_PRD, jref);
	double preSta = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMNDELIST_STA, jref);
	double preSto = xchg->getDblvalPreset(VecWzemVPreset::PREWZEMNDELIST_STO, jref);

	dbswzem->tblwzemqselect->removeRstByJref(jref);
	dbswzem->tblwzemqndelist->removeRstByJref(jref);

	cntsum = 0;

	if (preIxPre == VecWzemVPreset::PREWZEMREFPRD) {
		sqlstr = "SELECT COUNT(TblWzemMNode.ref)";
		sqlstr += " FROM TblWzemMNode";
		sqlstr += " WHERE TblWzemMNode.refWzemMPeriod = " + to_string(preRefPrd) + "";
		rerun_filtSQL(sqlstr, prePrd, preSta, preSto, false);
		dbswzem->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;

	} else {
		sqlstr = "SELECT COUNT(TblWzemMNode.ref)";
		sqlstr += " FROM TblWzemMNode";
		rerun_filtSQL(sqlstr, prePrd, preSta, preSto, true);
		dbswzem->loadUintBySQL(sqlstr, cnt);
		cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);
		cntsum += cnt;
	};

	statshr.ntot = 0;
	statshr.nload = 0;

	if (stgiac.jnumFirstload > cntsum) {
		if (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;
		else stgiac.jnumFirstload = 1;
	};

	for (unsigned int i = 0; i < cnts.size(); i++) {
		if (statshr.nload < stgiac.nload) {
			if ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {
				if (statshr.ntot >= stgiac.jnumFirstload) {
					ofss[i] = 0;
				} else {
					ofss[i] = stgiac.jnumFirstload-statshr.ntot-1;
				};

				if ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;
				else lims[i] = cnts[i]-ofss[i];
			};
		};

		statshr.ntot += cnts[i];
		statshr.nload += lims[i];
	};

	if (preIxPre == VecWzemVPreset::PREWZEMREFPRD) {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWzemMNode";
		sqlstr += " WHERE TblWzemMNode.refWzemMPeriod = " + to_string(preRefPrd) + "";
		rerun_filtSQL(sqlstr, prePrd, preSta, preSto, false);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswzem->executeQuery(sqlstr);

	} else {
		rerun_baseSQL(sqlstr);
		sqlstr += " FROM TblWzemMNode";
		rerun_filtSQL(sqlstr, prePrd, preSta, preSto, true);
		rerun_orderSQL(sqlstr, preIxOrd);
		sqlstr += " LIMIT " + to_string(lims[0]) + " OFFSET " + to_string(ofss[0]);
		dbswzem->executeQuery(sqlstr);
	};

	sqlstr = "UPDATE TblWzemQNdeList SET jnum = qref WHERE jref = " + to_string(jref);
	dbswzem->executeQuery(sqlstr);

	ixWzemVQrystate = VecWzemVQrystate::UTD;
	statshr.jnumFirstload = stgiac.jnumFirstload;

	fetch(dbswzem);

	if (call) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTATCHG, jref);

};

void QryWzemNdeList::rerun_baseSQL(
			string& sqlstr
		) {
	sqlstr = "INSERT INTO TblWzemQNdeList(jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn)";
	sqlstr += " SELECT " + to_string(jref) + ", 0, TblWzemMNode.ref, TblWzemMNode.refWzemMPeriod, TblWzemMNode.xnref, TblWzemMNode.Ip, TblWzemMNode.x1Startu, TblWzemMNode.x1Stopu, TblWzemMNode.Port, TblWzemMNode.Opprcn";
};

void QryWzemNdeList::rerun_filtSQL(
			string& sqlstr
			, const ubigint prePrd
			, const double preSta
			, const double preSto
			, const bool addwhere
		) {
	bool first = addwhere;

	if (prePrd != 0) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMNode.refWzemMPeriod = " + to_string(prePrd) + "";
	};

	if (preSta != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMNode.x1Startu = " + to_string(preSta) + "";
	};

	if (preSto != -numeric_limits<double>::infinity()) {
		rerun_filtSQL_append(sqlstr, first);
		sqlstr += "TblWzemMNode.x1Stopu = " + to_string(preSto) + "";
	};
};

void QryWzemNdeList::rerun_filtSQL_append(
			string& sqlstr
			, bool& first
		) {
	if (first) {
		sqlstr += " WHERE ";
		first = false;
	} else sqlstr += " AND ";
};

void QryWzemNdeList::rerun_orderSQL(
			string& sqlstr
			, const uint preIxOrd
		) {
	if (preIxOrd == VecVOrd::STO) sqlstr += " ORDER BY TblWzemMNode.x1Stopu ASC";
	else if (preIxOrd == VecVOrd::STA) sqlstr += " ORDER BY TblWzemMNode.x1Startu ASC";
	else if (preIxOrd == VecVOrd::PRD) sqlstr += " ORDER BY TblWzemMNode.refWzemMPeriod ASC";
};

void QryWzemNdeList::fetch(
			DbsWzem* dbswzem
		) {
	string sqlstr;

	StmgrWzem* stmgr = NULL;
	Stcch* stcch = NULL;

	WzemQNdeList* rec = NULL;

	dbswzem->tblwzemqndelist->loadRstByJref(jref, false, rst);
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
		};

		stmgr->commit();
		stmgr->unlockAccess("QryWzemNdeList", "fetch");
	};

	refreshJnum();
};

uint QryWzemNdeList::getJnumByRef(
			const ubigint ref
		) {
	uint retval = 0;

	WzemQNdeList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];

		if (rec->ref == ref) {
			retval = rec->jnum;
			break;
		};
	};

	return retval;
};

ubigint QryWzemNdeList::getRefByJnum(
			const uint jnum
		) {
	uint ref = 0;

	WzemQNdeList* rec = getRecByJnum(jnum);
	if (rec) ref = rec->ref;
	return ref;
};

WzemQNdeList* QryWzemNdeList::getRecByJnum(
			const uint jnum
		) {
	WzemQNdeList* rec = NULL;

	for (unsigned int i = 0; i < rst.nodes.size(); i++) {
		rec = rst.nodes[i];
		if (rec->jnum == jnum) break;
	};

	if (rec) if (rec->jnum != jnum) rec = NULL;
	return rec;
};

void QryWzemNdeList::handleRequest(
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

bool QryWzemNdeList::handleRerun(
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

bool QryWzemNdeList::handleShow(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	WzemQNdeList* rec = NULL;

	// header row
	cout << "\tqref";
	cout << "\tjref";
	cout << "\tjnum";
	cout << "\tref";
	cout << "\trefWzemMPeriod";
	cout << "\tstubRefWzemMPeriod";
	cout << "\txnref";
	cout << "\tIp";
	cout << "\tx1Startu";
	cout << "\tx1Stopu";
	cout << "\tPort";
	cout << "\tOpprcn";
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
		cout << "\t" << rec->xnref;
		cout << "\t" << rec->Ip;
		cout << "\t" << rec->x1Startu;
		cout << "\t" << rec->x1Stopu;
		cout << "\t" << rec->Port;
		cout << "\t" << rec->Opprcn;
		cout << endl;
	};
	return retval;
};

void QryWzemNdeList::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMNDEUPD_REFEQ) {
		call->abort = handleCallWzemNdeUpd_refEq(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMNDEMOD) {
		call->abort = handleCallWzemNdeMod(dbswzem, call->jref);
	} else if ((call->ixVCall == VecWzemVCall::CALLWZEMSTUBCHG) && (call->jref == jref)) {
		call->abort = handleCallWzemStubChgFromSelf(dbswzem);
	};
};

bool QryWzemNdeList::handleCallWzemNdeUpd_refEq(
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

bool QryWzemNdeList::handleCallWzemNdeMod(
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

bool QryWzemNdeList::handleCallWzemStubChgFromSelf(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	// IP handleCallWzemStubChgFromSelf --- INSERT
	return retval;
};
