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

	xchg->addClstn(VecWzemVCall::CALLWZEMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	if (xchg->stgwzemappearance.roottterm != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * xchg->stgwzemappearance.roottterm);
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

void RootWzem::termSess(
			DbsWzem* dbswzem
			, const ubigint jref
		) {
	JobWzem* job = NULL;

	job = xchg->getJobByJref(jref);

	if (job) {
		if (job->ixWzemVJob == VecWzemVJob::SESSWZEM) ((SessWzem*) job)->term(dbswzem);
	};
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

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::TIMER) {
		if (req->sref == "warnterm") handleTimerWithSrefWarnterm(dbswzem);
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

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbswzem, input, input2, refUsr)) {
		xchg->jrefCmd = insertSubjob(sesss, new SessWzem(xchg, dbswzem, jref, refUsr, "127.0.0.1"));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;

		if ((xchg->stgwzemappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwzemappearance.sesstterm - xchg->stgwzemappearance.sesstwarn));

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
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	termSess(dbswzem, iinput);

	if (!eraseSubjobByJref(sesss, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tsession erased." << endl;

	return retval;
};

void RootWzem::handleDpchAppLogin(
			DbsWzem* dbswzem
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngWzem** dpcheng
		) {
	ubigint refUsr;

	ubigint jrefSess;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbswzem, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgwzemappearance.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					jrefSess = it->second->jref;

					if (xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jrefSess) == refUsr) {
						if (xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMSUSPSESS, jrefSess)) {
							xchg->addTxtvalPreset(VecWzemVPreset::PREWZEMIP, jrefSess, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(jrefSess), StubWzem::getStubSesStd(dbswzem, xchg->getRefPreset(VecWzemVPreset::PREWZEMSESS, jrefSess)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				jrefSess = insertSubjob(sesss, new SessWzem(xchg, dbswzem, jref, refUsr, ip));

				if ((xchg->stgwzemappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwzemappearance.sesstterm - xchg->stgwzemappearance.sesstwarn));

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngWzemConfirm(true, jrefSess, "");

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

void RootWzem::handleTimerWithSrefWarnterm(
			DbsWzem* dbswzem
		) {
	SessWzem* sess = NULL;

	time_t tlast;
	time_t tnext = 0;

	time_t rawtime;
	time(&rawtime);

	bool term;

	if (xchg->stgwzemappearance.sesstterm != 0) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = (SessWzem*) it->second;

			term = false;

			tlast = xchg->getRefPreset(VecWzemVPreset::PREWZEMTLAST, sess->jref);

			if ((tlast + ((int) xchg->stgwzemappearance.sesstterm)) <= rawtime) term = true;
			else if ((tlast + ((int) xchg->stgwzemappearance.sesstterm) - ((int) xchg->stgwzemappearance.sesstwarn)) <= rawtime) {
				sess->warnTerm(dbswzem);
				if ((tnext == 0) || ((tlast + ((int) xchg->stgwzemappearance.sesstterm)) < tnext)) tnext = tlast + ((int) xchg->stgwzemappearance.sesstterm);
			} else if ((tnext == 0) || ((tlast + ((int) xchg->stgwzemappearance.sesstterm) - ((int) xchg->stgwzemappearance.sesstwarn)) < tnext)) tnext = tlast + xchg->stgwzemappearance.sesstterm - xchg->stgwzemappearance.sesstwarn;

			if (term) {
				sess->term(dbswzem);
				it = sesss.erase(it);

				delete sess;

			} else it++;
		};
	};

	term = false;

	if (xchg->stgwzemappearance.roottterm != 0) {
		tlast = xchg->getRefPreset(VecWzemVPreset::PREWZEMTLAST, jref);

		if ((tlast + ((int) xchg->stgwzemappearance.roottterm)) <= rawtime) term = true;
		else if ((tnext == 0) || ((tlast + ((int) xchg->stgwzemappearance.roottterm)) < tnext)) tnext = tlast + xchg->stgwzemappearance.roottterm;
	};

	if (term) {
		cout << endl << "\tterminating due to inactivity" << endl;
		kill(getpid(), SIGTERM);
	} else if (tnext != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (tnext - rawtime));
};

void RootWzem::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMREFPRESET) {
		call->abort = handleCallWzemRefPreSet(dbswzem, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMSUSPSESS) {
		call->abort = handleCallWzemSuspsess(dbswzem, call->jref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMLOGOUT) {
		call->abort = handleCallWzemLogout(dbswzem, call->jref, call->argInv.boolval);
	};
};

bool RootWzem::handleCallWzemRefPreSet(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzemVPreset::PREWZEMTLAST) {
		xchg->addRefPreset(ixInv, jref, refInv);
	};

	return retval;
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

	time_t rawtime;

	termSess(dbswzem, jrefTrig);

	if (!boolvalInv) {
		eraseSubjobByJref(sesss, jrefTrig);

		if (xchg->stgwzemappearance.roottterm) {
			time(&rawtime);
			xchg->addRefPreset(VecWzemVPreset::PREWZEMTLAST, jref, rawtime);
		};
	};

	return retval;
};
