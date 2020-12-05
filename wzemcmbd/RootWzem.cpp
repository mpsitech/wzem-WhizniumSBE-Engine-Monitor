/**
	* \file RootWzem.cpp
	* job handler for job RootWzem (implementation)
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

#include "RootWzem.h"

#include "RootWzem_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class RootWzem
 ******************************************************************************/

RootWzem::RootWzem(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const bool _clearAll
		) :
			JobWzem(xchg, VecWzemVJob::ROOTWZEM, jrefSup, VecWzemVLocale::ENUS)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbswzem);
	else clearQtb(dbswzem);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecWzemVCall::CALLWZEMSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

RootWzem::~RootWzem() {
	// log
	xchg->appendToLogfile("root job deleted");

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void RootWzem::clearAll(
			DbsWzem* dbswzem
		) {
	WzemMUsergroup* usg = NULL;
	WzemRMUserMUsergroup* uru = NULL;
	WzemMUser* usr = NULL;
	WzemMPerson* prs = NULL;

	time_t now;

	string s;

	// empty out tables
	dbswzem->executeQuery("DELETE FROM TblWzemAccRMUserUniversal");
	dbswzem->executeQuery("DELETE FROM TblWzemAMPersonDetail");
	dbswzem->executeQuery("DELETE FROM TblWzemAMUserAccess");
	dbswzem->executeQuery("DELETE FROM TblWzemAMUsergroupAccess");
	dbswzem->executeQuery("DELETE FROM TblWzemAVControlPar");
	dbswzem->executeQuery("DELETE FROM TblWzemAVKeylistKey");
	dbswzem->executeQuery("DELETE FROM TblWzemAVValuelistVal");
	if (dbswzem->ixDbsVDbstype == VecDbsVDbstype::MY) dbswzem->executeQuery("DELETE FROM TblWzemCEvent");
	else if (dbswzem->ixDbsVDbstype == VecDbsVDbstype::PG) dbswzem->executeQuery("ALTER SEQUENCE TblWzemCEvent RESTART WITH 1");
	dbswzem->executeQuery("DELETE FROM TblWzemHistRMUserUniversal");
	dbswzem->executeQuery("DELETE FROM TblWzemJAVKeylistKey");
	dbswzem->executeQuery("DELETE FROM TblWzemJMCallArgRet");
	dbswzem->executeQuery("DELETE FROM TblWzemJMClstn");
	dbswzem->executeQuery("DELETE FROM TblWzemJMJobDcol");
	dbswzem->executeQuery("DELETE FROM TblWzemJMJobStmgr");
	dbswzem->executeQuery("DELETE FROM TblWzemJMPersonLastname");
	dbswzem->executeQuery("DELETE FROM TblWzemJMPresetArg");
	dbswzem->executeQuery("DELETE FROM TblWzemJMUserState");
	dbswzem->executeQuery("DELETE FROM TblWzemMCall");
	dbswzem->executeQuery("DELETE FROM TblWzemMClstn");
	dbswzem->executeQuery("DELETE FROM TblWzemMDpch");
	dbswzem->executeQuery("DELETE FROM TblWzemMEvent");
	dbswzem->executeQuery("DELETE FROM TblWzemMJob");
	dbswzem->executeQuery("DELETE FROM TblWzemMNode");
	dbswzem->executeQuery("DELETE FROM TblWzemMOp");
	dbswzem->executeQuery("DELETE FROM TblWzemMPeriod");
	dbswzem->executeQuery("DELETE FROM TblWzemMPerson");
	dbswzem->executeQuery("DELETE FROM TblWzemMPreset");
	dbswzem->executeQuery("DELETE FROM TblWzemMSession");
	dbswzem->executeQuery("DELETE FROM TblWzemMUser");
	dbswzem->executeQuery("DELETE FROM TblWzemMUsergroup");
	dbswzem->executeQuery("DELETE FROM TblWzemRMUsergroupUniversal");
	dbswzem->executeQuery("DELETE FROM TblWzemRMUserMUsergroup");

	clearQtb(dbswzem);

	// generate a temporary user such that a session can be generated
	time(&now);

	dbswzem->tblwzemmusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbswzem->tblwzemamusergroupaccess->insertNewRec(NULL, usg->ref, VecWzemVFeatgroup::VECWZEMVCARD, "CrdWzemNav", VecWzemWAccess::EDIT + VecWzemWAccess::EXEC + VecWzemWAccess::VIEW);
	dbswzem->tblwzemrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecWzemVUserlevel::GADM);
	dbswzem->tblwzemmuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecWzemVMUserState::DUE, VecWzemVLocale::ENUS, VecWzemVUserlevel::GADM, "asdf1234", "", "temporary user for system initialization");
	usr->refJState = dbswzem->tblwzemjmuserstate->insertNewRec(NULL, usr->ref, 0, VecWzemVMUserState::DUE);
	dbswzem->tblwzemjmuserstate->insertNewRec(NULL, usr->ref, now + 24*3600, VecWzemVMUserState::EXP);
	usr->refWzemMPerson = dbswzem->tblwzemmperson->insertNewRec(&prs, usg->ref, usr->ref, VecWzemWMPersonDerivate::USR, VecWzemVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	prs->refJLastname = dbswzem->tblwzemjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbswzem->tblwzemmusergroup->updateRec(usg);

	uru->refWzemMUser = usr->ref;
	dbswzem->tblwzemrmusermusergroup->updateRec(uru);

	dbswzem->tblwzemmuser->updateRec(usr);

	dbswzem->tblwzemmperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::stamp(now + 24*3600) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootWzem::clearQtb(
			DbsWzem* dbswzem
		) {
	dbswzem->executeQuery("DELETE FROM TblWzemQCalList");
	dbswzem->executeQuery("DELETE FROM TblWzemQClnList");
	dbswzem->executeQuery("DELETE FROM TblWzemQEvtList");
	dbswzem->executeQuery("DELETE FROM TblWzemQJob1NCall");
	dbswzem->executeQuery("DELETE FROM TblWzemQJob1NClstn");
	dbswzem->executeQuery("DELETE FROM TblWzemQJob1NOp");
	dbswzem->executeQuery("DELETE FROM TblWzemQJob1NPreset");
	dbswzem->executeQuery("DELETE FROM TblWzemQJobList");
	dbswzem->executeQuery("DELETE FROM TblWzemQJobSup1NJob");
	dbswzem->executeQuery("DELETE FROM TblWzemQNdeList");
	dbswzem->executeQuery("DELETE FROM TblWzemQOpxList");
	dbswzem->executeQuery("DELETE FROM TblWzemQPrd1NEvent");
	dbswzem->executeQuery("DELETE FROM TblWzemQPrd1NJob");
	dbswzem->executeQuery("DELETE FROM TblWzemQPrd1NNode");
	dbswzem->executeQuery("DELETE FROM TblWzemQPrdList");
	dbswzem->executeQuery("DELETE FROM TblWzemQPreselect");
	dbswzem->executeQuery("DELETE FROM TblWzemQPrsADetail");
	dbswzem->executeQuery("DELETE FROM TblWzemQPrsList");
	dbswzem->executeQuery("DELETE FROM TblWzemQPstList");
	dbswzem->executeQuery("DELETE FROM TblWzemQSelect");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsgAAccess");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsgList");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsgMNUser");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsr1NSession");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsrAAccess");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsrList");
	dbswzem->executeQuery("DELETE FROM TblWzemQUsrMNUsergroup");
};

bool RootWzem::authenticate(
			DbsWzem* dbswzem
			, const string& username
			, const string& password
			, ubigint& refWzemMUser
		) {
	bool valid = false;

	ubigint ref;

	WzemMUser* usr = NULL;

	time_t now;

	refWzemMUser = 0;

	if (dbswzem->tblwzemmuser->loadRecBySrfPwd(username, password, &usr)) {
		if ((usr->ixVState == VecWzemVMUserState::DSG) || (usr->ixVState == VecWzemVMUserState::DUE)) {
			// check if expired
			time(&now);

			if (dbswzem->loadRefBySQL("SELECT ref FROM TblWzemJMUserState WHERE refWzemMUser = " + to_string(usr->ref) + " AND x1Start < " + to_string(now) + " AND ixVState = " + to_string(VecWzemVMUserState::EXP) + " ORDER BY x1Start DESC LIMIT 1", ref)) {
				usr->refJState = ref;
				usr->ixVState = VecWzemVMUserState::EXP;
				dbswzem->tblwzemmuser->updateRec(usr);
			};
		};

		valid = ((usr->ixVState == VecWzemVMUserState::ACT) || (usr->ixVState == VecWzemVMUserState::DUE));

		if (valid) refWzemMUser = usr->ref;

		delete usr;
	};

	return valid;
};

void RootWzem::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
	if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbswzem);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbswzem);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbswzem);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPROOTWZEMLOGIN) {
			handleDpchAppLogin(dbswzem, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};
	};
};

bool RootWzem::handleClearAll(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	clearAll(dbswzem);
	return retval;
};

bool RootWzem::handleCreateSess(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	SessWzem* sess = NULL;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbswzem, input, input2, refUsr)) {
		sess = new SessWzem(xchg, dbswzem, jref, refUsr, "127.0.0.1");
		sesss.push_back(sess);

		cout << "\tjob reference: " << sess->jref << endl;
		xchg->jrefCmd = sess->jref;

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return retval;
};

bool RootWzem::handleEraseSess(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	string input;
	uint iinput;

	SessWzem* sess = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = sesss.begin(); it != sesss.end();) {
		sess = *it;
		if (sess->jref == iinput) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};

	return false;
	return retval;
};

void RootWzem::handleDpchAppLogin(
			DbsWzem* dbswzem
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngWzem** dpcheng
		) {
	ubigint refUsr;

	SessWzem* sess = NULL;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbswzem, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgwzemappearance.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					sess = *it;

					if (xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, sess->jref) == refUsr) {
						if (xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMSUSPSESS, sess->jref)) {
							xchg->addTxtvalPreset(VecWzemVPreset::PREWZEMIP, sess->jref, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(sess->jref), StubWzem::getStubSesStd(dbswzem, xchg->getRefPreset(VecWzemVPreset::PREWZEMSESS, sess->jref)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				sess = new SessWzem(xchg, dbswzem, jref, refUsr, ip);
				sesss.push_back(sess);

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngWzemConfirm(true, sess->jref, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngWzemConfirm(false, 0, "");
	};
};

void RootWzem::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMSUSPSESS) {
		call->abort = handleCallWzemSuspsess(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMLOGOUT) {
		call->abort = handleCallWzemLogout(dbswzem, call->jref, call->argInv.boolval);
	};
};

bool RootWzem::handleCallWzemSuspsess(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
		) {
	bool retval = false;

	xchg->addBoolvalPreset(VecWzemVPreset::PREWZEMSUSPSESS, jrefTrig, true);
	xchg->removeDcolsByJref(jrefTrig);

	return retval;
};

bool RootWzem::handleCallWzemLogout(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	SessWzem* sess = NULL;

	if (!boolvalInv) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = *it;
			if (sess->jref == jrefTrig) {
				sess->term(dbswzem);
				it = sesss.erase(it);

				delete sess;
				break;
			} else it++;
		};
	};

	return retval;
};

