/**
	* \file DbsWzem.cpp
	* C++ wrapper for database DbsWzem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "DbsWzem.h"

#include "DbsWzem_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class DbsWzem
 ******************************************************************************/

DbsWzem::DbsWzem() {
	initdone = false;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	dbsMy = NULL;
#endif
#if defined(SBECORE_PG)
	dbsPg = NULL;
#endif
#if defined(SBECORE_LITE)
	dbsLite = NULL;
#endif
};

DbsWzem::~DbsWzem() {
	if (initdone) term();
};

void DbsWzem::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		initMy();
		initdone = true;
	};
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		initPg();
		initdone = true;
	};
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		initLite();
		initdone = true;
	};
#endif
};

void DbsWzem::term() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		termMy();
		initdone = false;
	};
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		termPg();
		initdone = false;
	};
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		termLite();
		initdone = false;
	};
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWzem::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), port, NULL, 0)) {
		string dbms = "DbsWzem::initMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblwzemaccrmuseruniversal = new MyTblWzemAccRMUserUniversal();
	((MyTblWzemAccRMUserUniversal*) tblwzemaccrmuseruniversal)->init(dbsMy);
	tblwzemampersondetail = new MyTblWzemAMPersonDetail();
	((MyTblWzemAMPersonDetail*) tblwzemampersondetail)->init(dbsMy);
	tblwzemamuseraccess = new MyTblWzemAMUserAccess();
	((MyTblWzemAMUserAccess*) tblwzemamuseraccess)->init(dbsMy);
	tblwzemamusergroupaccess = new MyTblWzemAMUsergroupAccess();
	((MyTblWzemAMUsergroupAccess*) tblwzemamusergroupaccess)->init(dbsMy);
	tblwzemavcontrolpar = new MyTblWzemAVControlPar();
	((MyTblWzemAVControlPar*) tblwzemavcontrolpar)->init(dbsMy);
	tblwzemavkeylistkey = new MyTblWzemAVKeylistKey();
	((MyTblWzemAVKeylistKey*) tblwzemavkeylistkey)->init(dbsMy);
	tblwzemavvaluelistval = new MyTblWzemAVValuelistVal();
	((MyTblWzemAVValuelistVal*) tblwzemavvaluelistval)->init(dbsMy);
	tblwzemcevent = new MyTblWzemCEvent();
	((MyTblWzemCEvent*) tblwzemcevent)->init(dbsMy);
	tblwzemhistrmuseruniversal = new MyTblWzemHistRMUserUniversal();
	((MyTblWzemHistRMUserUniversal*) tblwzemhistrmuseruniversal)->init(dbsMy);
	tblwzemjavkeylistkey = new MyTblWzemJAVKeylistKey();
	((MyTblWzemJAVKeylistKey*) tblwzemjavkeylistkey)->init(dbsMy);
	tblwzemjmcallargret = new MyTblWzemJMCallArgRet();
	((MyTblWzemJMCallArgRet*) tblwzemjmcallargret)->init(dbsMy);
	tblwzemjmclstn = new MyTblWzemJMClstn();
	((MyTblWzemJMClstn*) tblwzemjmclstn)->init(dbsMy);
	tblwzemjmjobdcol = new MyTblWzemJMJobDcol();
	((MyTblWzemJMJobDcol*) tblwzemjmjobdcol)->init(dbsMy);
	tblwzemjmjobstmgr = new MyTblWzemJMJobStmgr();
	((MyTblWzemJMJobStmgr*) tblwzemjmjobstmgr)->init(dbsMy);
	tblwzemjmpersonlastname = new MyTblWzemJMPersonLastname();
	((MyTblWzemJMPersonLastname*) tblwzemjmpersonlastname)->init(dbsMy);
	tblwzemjmpresetarg = new MyTblWzemJMPresetArg();
	((MyTblWzemJMPresetArg*) tblwzemjmpresetarg)->init(dbsMy);
	tblwzemjmuserstate = new MyTblWzemJMUserState();
	((MyTblWzemJMUserState*) tblwzemjmuserstate)->init(dbsMy);
	tblwzemmcall = new MyTblWzemMCall();
	((MyTblWzemMCall*) tblwzemmcall)->init(dbsMy);
	tblwzemmclstn = new MyTblWzemMClstn();
	((MyTblWzemMClstn*) tblwzemmclstn)->init(dbsMy);
	tblwzemmdpch = new MyTblWzemMDpch();
	((MyTblWzemMDpch*) tblwzemmdpch)->init(dbsMy);
	tblwzemmevent = new MyTblWzemMEvent();
	((MyTblWzemMEvent*) tblwzemmevent)->init(dbsMy);
	tblwzemmjob = new MyTblWzemMJob();
	((MyTblWzemMJob*) tblwzemmjob)->init(dbsMy);
	tblwzemmnode = new MyTblWzemMNode();
	((MyTblWzemMNode*) tblwzemmnode)->init(dbsMy);
	tblwzemmop = new MyTblWzemMOp();
	((MyTblWzemMOp*) tblwzemmop)->init(dbsMy);
	tblwzemmperiod = new MyTblWzemMPeriod();
	((MyTblWzemMPeriod*) tblwzemmperiod)->init(dbsMy);
	tblwzemmperson = new MyTblWzemMPerson();
	((MyTblWzemMPerson*) tblwzemmperson)->init(dbsMy);
	tblwzemmpreset = new MyTblWzemMPreset();
	((MyTblWzemMPreset*) tblwzemmpreset)->init(dbsMy);
	tblwzemmsession = new MyTblWzemMSession();
	((MyTblWzemMSession*) tblwzemmsession)->init(dbsMy);
	tblwzemmuser = new MyTblWzemMUser();
	((MyTblWzemMUser*) tblwzemmuser)->init(dbsMy);
	tblwzemmusergroup = new MyTblWzemMUsergroup();
	((MyTblWzemMUsergroup*) tblwzemmusergroup)->init(dbsMy);
	tblwzemrmusergroupuniversal = new MyTblWzemRMUsergroupUniversal();
	((MyTblWzemRMUsergroupUniversal*) tblwzemrmusergroupuniversal)->init(dbsMy);
	tblwzemrmusermusergroup = new MyTblWzemRMUserMUsergroup();
	((MyTblWzemRMUserMUsergroup*) tblwzemrmusermusergroup)->init(dbsMy);

	tblwzemqcallist = new MyTblWzemQCalList();
	((MyTblWzemQCalList*) tblwzemqcallist)->init(dbsMy);
	tblwzemqclnlist = new MyTblWzemQClnList();
	((MyTblWzemQClnList*) tblwzemqclnlist)->init(dbsMy);
	tblwzemqevtlist = new MyTblWzemQEvtList();
	((MyTblWzemQEvtList*) tblwzemqevtlist)->init(dbsMy);
	tblwzemqjob1ncall = new MyTblWzemQJob1NCall();
	((MyTblWzemQJob1NCall*) tblwzemqjob1ncall)->init(dbsMy);
	tblwzemqjob1nclstn = new MyTblWzemQJob1NClstn();
	((MyTblWzemQJob1NClstn*) tblwzemqjob1nclstn)->init(dbsMy);
	tblwzemqjob1nop = new MyTblWzemQJob1NOp();
	((MyTblWzemQJob1NOp*) tblwzemqjob1nop)->init(dbsMy);
	tblwzemqjob1npreset = new MyTblWzemQJob1NPreset();
	((MyTblWzemQJob1NPreset*) tblwzemqjob1npreset)->init(dbsMy);
	tblwzemqjoblist = new MyTblWzemQJobList();
	((MyTblWzemQJobList*) tblwzemqjoblist)->init(dbsMy);
	tblwzemqjobsup1njob = new MyTblWzemQJobSup1NJob();
	((MyTblWzemQJobSup1NJob*) tblwzemqjobsup1njob)->init(dbsMy);
	tblwzemqndelist = new MyTblWzemQNdeList();
	((MyTblWzemQNdeList*) tblwzemqndelist)->init(dbsMy);
	tblwzemqopxlist = new MyTblWzemQOpxList();
	((MyTblWzemQOpxList*) tblwzemqopxlist)->init(dbsMy);
	tblwzemqprd1nevent = new MyTblWzemQPrd1NEvent();
	((MyTblWzemQPrd1NEvent*) tblwzemqprd1nevent)->init(dbsMy);
	tblwzemqprd1njob = new MyTblWzemQPrd1NJob();
	((MyTblWzemQPrd1NJob*) tblwzemqprd1njob)->init(dbsMy);
	tblwzemqprd1nnode = new MyTblWzemQPrd1NNode();
	((MyTblWzemQPrd1NNode*) tblwzemqprd1nnode)->init(dbsMy);
	tblwzemqprdlist = new MyTblWzemQPrdList();
	((MyTblWzemQPrdList*) tblwzemqprdlist)->init(dbsMy);
	tblwzemqpreselect = new MyTblWzemQPreselect();
	((MyTblWzemQPreselect*) tblwzemqpreselect)->init(dbsMy);
	tblwzemqprsadetail = new MyTblWzemQPrsADetail();
	((MyTblWzemQPrsADetail*) tblwzemqprsadetail)->init(dbsMy);
	tblwzemqprslist = new MyTblWzemQPrsList();
	((MyTblWzemQPrsList*) tblwzemqprslist)->init(dbsMy);
	tblwzemqpstlist = new MyTblWzemQPstList();
	((MyTblWzemQPstList*) tblwzemqpstlist)->init(dbsMy);
	tblwzemqselect = new MyTblWzemQSelect();
	((MyTblWzemQSelect*) tblwzemqselect)->init(dbsMy);
	tblwzemqusgaaccess = new MyTblWzemQUsgAAccess();
	((MyTblWzemQUsgAAccess*) tblwzemqusgaaccess)->init(dbsMy);
	tblwzemqusglist = new MyTblWzemQUsgList();
	((MyTblWzemQUsgList*) tblwzemqusglist)->init(dbsMy);
	tblwzemqusgmnuser = new MyTblWzemQUsgMNUser();
	((MyTblWzemQUsgMNUser*) tblwzemqusgmnuser)->init(dbsMy);
	tblwzemqusr1nsession = new MyTblWzemQUsr1NSession();
	((MyTblWzemQUsr1NSession*) tblwzemqusr1nsession)->init(dbsMy);
	tblwzemqusraaccess = new MyTblWzemQUsrAAccess();
	((MyTblWzemQUsrAAccess*) tblwzemqusraaccess)->init(dbsMy);
	tblwzemqusrlist = new MyTblWzemQUsrList();
	((MyTblWzemQUsrList*) tblwzemqusrlist)->init(dbsMy);
	tblwzemqusrmnusergroup = new MyTblWzemQUsrMNUsergroup();
	((MyTblWzemQUsrMNUsergroup*) tblwzemqusrmnusergroup)->init(dbsMy);
};

void DbsWzem::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};
#endif

#if defined(SBECORE_PG)
void DbsWzem::initPg() {
	// connect to PostgreSQL database
	dbsPg = PQsetdbLogin(ip.c_str(), to_string(port).c_str(), NULL, NULL, dbsname.c_str(), username.c_str(), password.c_str());

	if (PQstatus(dbsPg) == CONNECTION_BAD) {
		string dbms = "DbsWzem::initPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	tblwzemaccrmuseruniversal = new PgTblWzemAccRMUserUniversal();
	((PgTblWzemAccRMUserUniversal*) tblwzemaccrmuseruniversal)->init(dbsPg);
	tblwzemampersondetail = new PgTblWzemAMPersonDetail();
	((PgTblWzemAMPersonDetail*) tblwzemampersondetail)->init(dbsPg);
	tblwzemamuseraccess = new PgTblWzemAMUserAccess();
	((PgTblWzemAMUserAccess*) tblwzemamuseraccess)->init(dbsPg);
	tblwzemamusergroupaccess = new PgTblWzemAMUsergroupAccess();
	((PgTblWzemAMUsergroupAccess*) tblwzemamusergroupaccess)->init(dbsPg);
	tblwzemavcontrolpar = new PgTblWzemAVControlPar();
	((PgTblWzemAVControlPar*) tblwzemavcontrolpar)->init(dbsPg);
	tblwzemavkeylistkey = new PgTblWzemAVKeylistKey();
	((PgTblWzemAVKeylistKey*) tblwzemavkeylistkey)->init(dbsPg);
	tblwzemavvaluelistval = new PgTblWzemAVValuelistVal();
	((PgTblWzemAVValuelistVal*) tblwzemavvaluelistval)->init(dbsPg);
	tblwzemcevent = new PgTblWzemCEvent();
	((PgTblWzemCEvent*) tblwzemcevent)->init(dbsPg);
	tblwzemhistrmuseruniversal = new PgTblWzemHistRMUserUniversal();
	((PgTblWzemHistRMUserUniversal*) tblwzemhistrmuseruniversal)->init(dbsPg);
	tblwzemjavkeylistkey = new PgTblWzemJAVKeylistKey();
	((PgTblWzemJAVKeylistKey*) tblwzemjavkeylistkey)->init(dbsPg);
	tblwzemjmcallargret = new PgTblWzemJMCallArgRet();
	((PgTblWzemJMCallArgRet*) tblwzemjmcallargret)->init(dbsPg);
	tblwzemjmclstn = new PgTblWzemJMClstn();
	((PgTblWzemJMClstn*) tblwzemjmclstn)->init(dbsPg);
	tblwzemjmjobdcol = new PgTblWzemJMJobDcol();
	((PgTblWzemJMJobDcol*) tblwzemjmjobdcol)->init(dbsPg);
	tblwzemjmjobstmgr = new PgTblWzemJMJobStmgr();
	((PgTblWzemJMJobStmgr*) tblwzemjmjobstmgr)->init(dbsPg);
	tblwzemjmpersonlastname = new PgTblWzemJMPersonLastname();
	((PgTblWzemJMPersonLastname*) tblwzemjmpersonlastname)->init(dbsPg);
	tblwzemjmpresetarg = new PgTblWzemJMPresetArg();
	((PgTblWzemJMPresetArg*) tblwzemjmpresetarg)->init(dbsPg);
	tblwzemjmuserstate = new PgTblWzemJMUserState();
	((PgTblWzemJMUserState*) tblwzemjmuserstate)->init(dbsPg);
	tblwzemmcall = new PgTblWzemMCall();
	((PgTblWzemMCall*) tblwzemmcall)->init(dbsPg);
	tblwzemmclstn = new PgTblWzemMClstn();
	((PgTblWzemMClstn*) tblwzemmclstn)->init(dbsPg);
	tblwzemmdpch = new PgTblWzemMDpch();
	((PgTblWzemMDpch*) tblwzemmdpch)->init(dbsPg);
	tblwzemmevent = new PgTblWzemMEvent();
	((PgTblWzemMEvent*) tblwzemmevent)->init(dbsPg);
	tblwzemmjob = new PgTblWzemMJob();
	((PgTblWzemMJob*) tblwzemmjob)->init(dbsPg);
	tblwzemmnode = new PgTblWzemMNode();
	((PgTblWzemMNode*) tblwzemmnode)->init(dbsPg);
	tblwzemmop = new PgTblWzemMOp();
	((PgTblWzemMOp*) tblwzemmop)->init(dbsPg);
	tblwzemmperiod = new PgTblWzemMPeriod();
	((PgTblWzemMPeriod*) tblwzemmperiod)->init(dbsPg);
	tblwzemmperson = new PgTblWzemMPerson();
	((PgTblWzemMPerson*) tblwzemmperson)->init(dbsPg);
	tblwzemmpreset = new PgTblWzemMPreset();
	((PgTblWzemMPreset*) tblwzemmpreset)->init(dbsPg);
	tblwzemmsession = new PgTblWzemMSession();
	((PgTblWzemMSession*) tblwzemmsession)->init(dbsPg);
	tblwzemmuser = new PgTblWzemMUser();
	((PgTblWzemMUser*) tblwzemmuser)->init(dbsPg);
	tblwzemmusergroup = new PgTblWzemMUsergroup();
	((PgTblWzemMUsergroup*) tblwzemmusergroup)->init(dbsPg);
	tblwzemrmusergroupuniversal = new PgTblWzemRMUsergroupUniversal();
	((PgTblWzemRMUsergroupUniversal*) tblwzemrmusergroupuniversal)->init(dbsPg);
	tblwzemrmusermusergroup = new PgTblWzemRMUserMUsergroup();
	((PgTblWzemRMUserMUsergroup*) tblwzemrmusermusergroup)->init(dbsPg);

	tblwzemqcallist = new PgTblWzemQCalList();
	((PgTblWzemQCalList*) tblwzemqcallist)->init(dbsPg);
	tblwzemqclnlist = new PgTblWzemQClnList();
	((PgTblWzemQClnList*) tblwzemqclnlist)->init(dbsPg);
	tblwzemqevtlist = new PgTblWzemQEvtList();
	((PgTblWzemQEvtList*) tblwzemqevtlist)->init(dbsPg);
	tblwzemqjob1ncall = new PgTblWzemQJob1NCall();
	((PgTblWzemQJob1NCall*) tblwzemqjob1ncall)->init(dbsPg);
	tblwzemqjob1nclstn = new PgTblWzemQJob1NClstn();
	((PgTblWzemQJob1NClstn*) tblwzemqjob1nclstn)->init(dbsPg);
	tblwzemqjob1nop = new PgTblWzemQJob1NOp();
	((PgTblWzemQJob1NOp*) tblwzemqjob1nop)->init(dbsPg);
	tblwzemqjob1npreset = new PgTblWzemQJob1NPreset();
	((PgTblWzemQJob1NPreset*) tblwzemqjob1npreset)->init(dbsPg);
	tblwzemqjoblist = new PgTblWzemQJobList();
	((PgTblWzemQJobList*) tblwzemqjoblist)->init(dbsPg);
	tblwzemqjobsup1njob = new PgTblWzemQJobSup1NJob();
	((PgTblWzemQJobSup1NJob*) tblwzemqjobsup1njob)->init(dbsPg);
	tblwzemqndelist = new PgTblWzemQNdeList();
	((PgTblWzemQNdeList*) tblwzemqndelist)->init(dbsPg);
	tblwzemqopxlist = new PgTblWzemQOpxList();
	((PgTblWzemQOpxList*) tblwzemqopxlist)->init(dbsPg);
	tblwzemqprd1nevent = new PgTblWzemQPrd1NEvent();
	((PgTblWzemQPrd1NEvent*) tblwzemqprd1nevent)->init(dbsPg);
	tblwzemqprd1njob = new PgTblWzemQPrd1NJob();
	((PgTblWzemQPrd1NJob*) tblwzemqprd1njob)->init(dbsPg);
	tblwzemqprd1nnode = new PgTblWzemQPrd1NNode();
	((PgTblWzemQPrd1NNode*) tblwzemqprd1nnode)->init(dbsPg);
	tblwzemqprdlist = new PgTblWzemQPrdList();
	((PgTblWzemQPrdList*) tblwzemqprdlist)->init(dbsPg);
	tblwzemqpreselect = new PgTblWzemQPreselect();
	((PgTblWzemQPreselect*) tblwzemqpreselect)->init(dbsPg);
	tblwzemqprsadetail = new PgTblWzemQPrsADetail();
	((PgTblWzemQPrsADetail*) tblwzemqprsadetail)->init(dbsPg);
	tblwzemqprslist = new PgTblWzemQPrsList();
	((PgTblWzemQPrsList*) tblwzemqprslist)->init(dbsPg);
	tblwzemqpstlist = new PgTblWzemQPstList();
	((PgTblWzemQPstList*) tblwzemqpstlist)->init(dbsPg);
	tblwzemqselect = new PgTblWzemQSelect();
	((PgTblWzemQSelect*) tblwzemqselect)->init(dbsPg);
	tblwzemqusgaaccess = new PgTblWzemQUsgAAccess();
	((PgTblWzemQUsgAAccess*) tblwzemqusgaaccess)->init(dbsPg);
	tblwzemqusglist = new PgTblWzemQUsgList();
	((PgTblWzemQUsgList*) tblwzemqusglist)->init(dbsPg);
	tblwzemqusgmnuser = new PgTblWzemQUsgMNUser();
	((PgTblWzemQUsgMNUser*) tblwzemqusgmnuser)->init(dbsPg);
	tblwzemqusr1nsession = new PgTblWzemQUsr1NSession();
	((PgTblWzemQUsr1NSession*) tblwzemqusr1nsession)->init(dbsPg);
	tblwzemqusraaccess = new PgTblWzemQUsrAAccess();
	((PgTblWzemQUsrAAccess*) tblwzemqusraaccess)->init(dbsPg);
	tblwzemqusrlist = new PgTblWzemQUsrList();
	((PgTblWzemQUsrList*) tblwzemqusrlist)->init(dbsPg);
	tblwzemqusrmnusergroup = new PgTblWzemQUsrMNUsergroup();
	((PgTblWzemQUsrMNUsergroup*) tblwzemqusrmnusergroup)->init(dbsPg);
};

void DbsWzem::termPg() {
	PQfinish(dbsPg);
};
#endif

#if defined(SBECORE_LITE)
void DbsWzem::initLite() {
	int res;

	res = sqlite3_open_v2(dbspath.c_str(), &dbsLite, SQLITE_OPEN_READWRITE | SQLITE_OPEN_FULLMUTEX, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzem::initLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	sqlite3_extended_result_codes(dbsLite, 1);
	sqlite3_busy_timeout(dbsLite, 5000);

	tblwzemaccrmuseruniversal = new LiteTblWzemAccRMUserUniversal();
	((LiteTblWzemAccRMUserUniversal*) tblwzemaccrmuseruniversal)->init(dbsLite);
	tblwzemampersondetail = new LiteTblWzemAMPersonDetail();
	((LiteTblWzemAMPersonDetail*) tblwzemampersondetail)->init(dbsLite);
	tblwzemamuseraccess = new LiteTblWzemAMUserAccess();
	((LiteTblWzemAMUserAccess*) tblwzemamuseraccess)->init(dbsLite);
	tblwzemamusergroupaccess = new LiteTblWzemAMUsergroupAccess();
	((LiteTblWzemAMUsergroupAccess*) tblwzemamusergroupaccess)->init(dbsLite);
	tblwzemavcontrolpar = new LiteTblWzemAVControlPar();
	((LiteTblWzemAVControlPar*) tblwzemavcontrolpar)->init(dbsLite);
	tblwzemavkeylistkey = new LiteTblWzemAVKeylistKey();
	((LiteTblWzemAVKeylistKey*) tblwzemavkeylistkey)->init(dbsLite);
	tblwzemavvaluelistval = new LiteTblWzemAVValuelistVal();
	((LiteTblWzemAVValuelistVal*) tblwzemavvaluelistval)->init(dbsLite);
	tblwzemcevent = new LiteTblWzemCEvent();
	((LiteTblWzemCEvent*) tblwzemcevent)->init(dbsLite);
	tblwzemhistrmuseruniversal = new LiteTblWzemHistRMUserUniversal();
	((LiteTblWzemHistRMUserUniversal*) tblwzemhistrmuseruniversal)->init(dbsLite);
	tblwzemjavkeylistkey = new LiteTblWzemJAVKeylistKey();
	((LiteTblWzemJAVKeylistKey*) tblwzemjavkeylistkey)->init(dbsLite);
	tblwzemjmcallargret = new LiteTblWzemJMCallArgRet();
	((LiteTblWzemJMCallArgRet*) tblwzemjmcallargret)->init(dbsLite);
	tblwzemjmclstn = new LiteTblWzemJMClstn();
	((LiteTblWzemJMClstn*) tblwzemjmclstn)->init(dbsLite);
	tblwzemjmjobdcol = new LiteTblWzemJMJobDcol();
	((LiteTblWzemJMJobDcol*) tblwzemjmjobdcol)->init(dbsLite);
	tblwzemjmjobstmgr = new LiteTblWzemJMJobStmgr();
	((LiteTblWzemJMJobStmgr*) tblwzemjmjobstmgr)->init(dbsLite);
	tblwzemjmpersonlastname = new LiteTblWzemJMPersonLastname();
	((LiteTblWzemJMPersonLastname*) tblwzemjmpersonlastname)->init(dbsLite);
	tblwzemjmpresetarg = new LiteTblWzemJMPresetArg();
	((LiteTblWzemJMPresetArg*) tblwzemjmpresetarg)->init(dbsLite);
	tblwzemjmuserstate = new LiteTblWzemJMUserState();
	((LiteTblWzemJMUserState*) tblwzemjmuserstate)->init(dbsLite);
	tblwzemmcall = new LiteTblWzemMCall();
	((LiteTblWzemMCall*) tblwzemmcall)->init(dbsLite);
	tblwzemmclstn = new LiteTblWzemMClstn();
	((LiteTblWzemMClstn*) tblwzemmclstn)->init(dbsLite);
	tblwzemmdpch = new LiteTblWzemMDpch();
	((LiteTblWzemMDpch*) tblwzemmdpch)->init(dbsLite);
	tblwzemmevent = new LiteTblWzemMEvent();
	((LiteTblWzemMEvent*) tblwzemmevent)->init(dbsLite);
	tblwzemmjob = new LiteTblWzemMJob();
	((LiteTblWzemMJob*) tblwzemmjob)->init(dbsLite);
	tblwzemmnode = new LiteTblWzemMNode();
	((LiteTblWzemMNode*) tblwzemmnode)->init(dbsLite);
	tblwzemmop = new LiteTblWzemMOp();
	((LiteTblWzemMOp*) tblwzemmop)->init(dbsLite);
	tblwzemmperiod = new LiteTblWzemMPeriod();
	((LiteTblWzemMPeriod*) tblwzemmperiod)->init(dbsLite);
	tblwzemmperson = new LiteTblWzemMPerson();
	((LiteTblWzemMPerson*) tblwzemmperson)->init(dbsLite);
	tblwzemmpreset = new LiteTblWzemMPreset();
	((LiteTblWzemMPreset*) tblwzemmpreset)->init(dbsLite);
	tblwzemmsession = new LiteTblWzemMSession();
	((LiteTblWzemMSession*) tblwzemmsession)->init(dbsLite);
	tblwzemmuser = new LiteTblWzemMUser();
	((LiteTblWzemMUser*) tblwzemmuser)->init(dbsLite);
	tblwzemmusergroup = new LiteTblWzemMUsergroup();
	((LiteTblWzemMUsergroup*) tblwzemmusergroup)->init(dbsLite);
	tblwzemrmusergroupuniversal = new LiteTblWzemRMUsergroupUniversal();
	((LiteTblWzemRMUsergroupUniversal*) tblwzemrmusergroupuniversal)->init(dbsLite);
	tblwzemrmusermusergroup = new LiteTblWzemRMUserMUsergroup();
	((LiteTblWzemRMUserMUsergroup*) tblwzemrmusermusergroup)->init(dbsLite);

	tblwzemqcallist = new LiteTblWzemQCalList();
	((LiteTblWzemQCalList*) tblwzemqcallist)->init(dbsLite);
	tblwzemqclnlist = new LiteTblWzemQClnList();
	((LiteTblWzemQClnList*) tblwzemqclnlist)->init(dbsLite);
	tblwzemqevtlist = new LiteTblWzemQEvtList();
	((LiteTblWzemQEvtList*) tblwzemqevtlist)->init(dbsLite);
	tblwzemqjob1ncall = new LiteTblWzemQJob1NCall();
	((LiteTblWzemQJob1NCall*) tblwzemqjob1ncall)->init(dbsLite);
	tblwzemqjob1nclstn = new LiteTblWzemQJob1NClstn();
	((LiteTblWzemQJob1NClstn*) tblwzemqjob1nclstn)->init(dbsLite);
	tblwzemqjob1nop = new LiteTblWzemQJob1NOp();
	((LiteTblWzemQJob1NOp*) tblwzemqjob1nop)->init(dbsLite);
	tblwzemqjob1npreset = new LiteTblWzemQJob1NPreset();
	((LiteTblWzemQJob1NPreset*) tblwzemqjob1npreset)->init(dbsLite);
	tblwzemqjoblist = new LiteTblWzemQJobList();
	((LiteTblWzemQJobList*) tblwzemqjoblist)->init(dbsLite);
	tblwzemqjobsup1njob = new LiteTblWzemQJobSup1NJob();
	((LiteTblWzemQJobSup1NJob*) tblwzemqjobsup1njob)->init(dbsLite);
	tblwzemqndelist = new LiteTblWzemQNdeList();
	((LiteTblWzemQNdeList*) tblwzemqndelist)->init(dbsLite);
	tblwzemqopxlist = new LiteTblWzemQOpxList();
	((LiteTblWzemQOpxList*) tblwzemqopxlist)->init(dbsLite);
	tblwzemqprd1nevent = new LiteTblWzemQPrd1NEvent();
	((LiteTblWzemQPrd1NEvent*) tblwzemqprd1nevent)->init(dbsLite);
	tblwzemqprd1njob = new LiteTblWzemQPrd1NJob();
	((LiteTblWzemQPrd1NJob*) tblwzemqprd1njob)->init(dbsLite);
	tblwzemqprd1nnode = new LiteTblWzemQPrd1NNode();
	((LiteTblWzemQPrd1NNode*) tblwzemqprd1nnode)->init(dbsLite);
	tblwzemqprdlist = new LiteTblWzemQPrdList();
	((LiteTblWzemQPrdList*) tblwzemqprdlist)->init(dbsLite);
	tblwzemqpreselect = new LiteTblWzemQPreselect();
	((LiteTblWzemQPreselect*) tblwzemqpreselect)->init(dbsLite);
	tblwzemqprsadetail = new LiteTblWzemQPrsADetail();
	((LiteTblWzemQPrsADetail*) tblwzemqprsadetail)->init(dbsLite);
	tblwzemqprslist = new LiteTblWzemQPrsList();
	((LiteTblWzemQPrsList*) tblwzemqprslist)->init(dbsLite);
	tblwzemqpstlist = new LiteTblWzemQPstList();
	((LiteTblWzemQPstList*) tblwzemqpstlist)->init(dbsLite);
	tblwzemqselect = new LiteTblWzemQSelect();
	((LiteTblWzemQSelect*) tblwzemqselect)->init(dbsLite);
	tblwzemqusgaaccess = new LiteTblWzemQUsgAAccess();
	((LiteTblWzemQUsgAAccess*) tblwzemqusgaaccess)->init(dbsLite);
	tblwzemqusglist = new LiteTblWzemQUsgList();
	((LiteTblWzemQUsgList*) tblwzemqusglist)->init(dbsLite);
	tblwzemqusgmnuser = new LiteTblWzemQUsgMNUser();
	((LiteTblWzemQUsgMNUser*) tblwzemqusgmnuser)->init(dbsLite);
	tblwzemqusr1nsession = new LiteTblWzemQUsr1NSession();
	((LiteTblWzemQUsr1NSession*) tblwzemqusr1nsession)->init(dbsLite);
	tblwzemqusraaccess = new LiteTblWzemQUsrAAccess();
	((LiteTblWzemQUsrAAccess*) tblwzemqusraaccess)->init(dbsLite);
	tblwzemqusrlist = new LiteTblWzemQUsrList();
	((LiteTblWzemQUsrList*) tblwzemqusrlist)->init(dbsLite);
	tblwzemqusrmnusergroup = new LiteTblWzemQUsrMNUsergroup();
	((LiteTblWzemQUsrMNUsergroup*) tblwzemqusrmnusergroup)->init(dbsLite);
};

void DbsWzem::termLite() {
	sqlite3_close(dbsLite);
};
#endif

void DbsWzem::begin() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) beginPg();
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) beginLite();
#endif
};

bool DbsWzem::commit() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return commitPg();
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return commitLite();
#endif

	return false;
};

void DbsWzem::rollback() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) rollbackPg();
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) rollbackLite();
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWzem::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) {
		string dbms = "DbsWzem::beginMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};
};

bool DbsWzem::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsWzem::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) {
		string dbms = "DbsWzem::rollbackMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};
};
#endif

#if defined(SBECORE_PG)
void DbsWzem::beginPg() {
	PGresult* res;

	res = PQexec(dbsPg, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "DbsWzem::beginPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};

	PQclear(res);
};

bool DbsWzem::commitPg() {
	PGresult* res;

	res = PQexec(dbsPg, "COMMIT");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		rollbackPg();

		PQclear(res);
		return false;
	};

	PQclear(res);
	return true;
};

void DbsWzem::rollbackPg() {
	PGresult* res;

	res = PQexec(dbsPg, "ROLLBACK");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "DbsWzem::rollbackPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};

	PQclear(res);
};
#endif

#if defined(SBECORE_LITE)
void DbsWzem::beginLite() {
	if (sqlite3_exec(dbsLite, "BEGIN", NULL, NULL, NULL) != SQLITE_OK) {
		string dbms = "DbsWzem::beginLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};
};

bool DbsWzem::commitLite() {
	if (sqlite3_exec(dbsLite, "COMMIT", NULL, NULL, NULL) != SQLITE_OK) {
		rollbackLite();
		return false;
	};

	return true;
};

void DbsWzem::rollbackLite() {
	if (sqlite3_exec(dbsLite, "ROLLBACK", NULL, NULL, NULL) != SQLITE_OK) {
		string dbms = "DbsWzem::rollbackLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};
};
#endif

bool DbsWzem::loadUintBySQL(
			const string& sqlstr
			, uint& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUintBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadUintBySQLPg(sqlstr, val);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadUintBySQLLite(sqlstr, val);
#endif

	return false;
};

bool DbsWzem::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadStringBySQLPg(sqlstr, val);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadStringBySQLLite(sqlstr, val);
#endif

	return false;
};

bool DbsWzem::loadRefBySQL(
			const string& sqlstr
			, ubigint& ref
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefBySQLMy(sqlstr, ref);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefBySQLPg(sqlstr, ref);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadRefBySQLLite(sqlstr, ref);
#endif

	return false;
};

ubigint DbsWzem::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefsBySQLPg(sqlstr, append, refs);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) return loadRefsBySQLLite(sqlstr, append, refs);
#endif

	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
bool DbsWzem::loadUintBySQLMy(
			const string& sqlstr
			, uint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzem::loadUintBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzem::loadUintBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atol((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWzem::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzem::loadStringBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzem::loadStringBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWzem::loadRefBySQLMy(
			const string& sqlstr
			, ubigint& ref
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzem::loadRefBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzem::loadRefBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		ref = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsWzem::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWzem::loadRefsBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWzem::loadRefsBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};
#endif

#if defined(SBECORE_PG)
bool DbsWzem::loadUintBySQLPg(
			const string& sqlstr
			, uint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWzem::loadUintBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atol(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsWzem::loadStringBySQLPg(
			const string& sqlstr
			, string& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;

	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWzem::loadStringBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val.assign(ptr, PQgetlength(res, 0, 0));

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsWzem::loadRefBySQLPg(
			const string& sqlstr
			, ubigint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWzem::loadRefBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

ubigint DbsWzem::loadRefsBySQLPg(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	PGresult* res; ubigint numrow; ubigint numread = 0; char* ptr;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWzem::loadRefsBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = PQntuples(res);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		ptr = PQgetvalue(res, numread, 0); refs.push_back(atoll(ptr));
		numread++;
	};

	PQclear(res);

	return(numread);
};
#endif

#if defined(SBECORE_LITE)
bool DbsWzem::loadUintBySQLLite(
			const string& sqlstr
			, uint& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), -1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzem::loadUintBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val = sqlite3_column_int(stmt, 0);

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

bool DbsWzem::loadStringBySQLLite(
			const string& sqlstr
			, string& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzem::loadStringBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val.assign((const char*) sqlite3_column_text(stmt, 0));

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

bool DbsWzem::loadRefBySQLLite(
			const string& sqlstr
			, ubigint& val
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzem::loadRefBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		val = sqlite3_column_int64(stmt, 0);

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) retval = true;
	};

	sqlite3_finalize(stmt);

	return retval;
};

ubigint DbsWzem::loadRefsBySQLLite(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	int res; ubigint numread = 0;
	sqlite3_stmt* stmt;

	res = sqlite3_prepare_v2(dbsLite, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "DbsWzem::loadRefsBySQLLite() / " + string(sqlite3_errmsg(dbsLite));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (!append) refs.resize(0);

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		refs.push_back(sqlite3_column_int64(stmt, 0));
		numread++;

		res = sqlite3_step(stmt);
	};

	sqlite3_finalize(stmt);

	return(numread);
};
#endif

void DbsWzem::executeQuery(
			const string& sqlstr
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY)
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str()))) {
			string dbms = "DbsWzem::executeQuery() / MySQL / " + string(mysql_error(dbsMy));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
#endif

#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		PGresult* res;

		res = PQexec(dbsPg, sqlstr.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			string dbms = "DbsWzem::executeQuery() / PgSQL / " + string(PQerrorMessage(dbsPg));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
	};
#endif

#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) {
		int res;

		res = sqlite3_exec(dbsLite, sqlstr.c_str(), NULL, NULL, NULL);
		if (res != SQLITE_OK) {
			string dbms = "DbsWzem::executeQuery() / SQLite / " + string(sqlite3_errmsg(dbsLite));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
	};
#endif
};

void DbsWzem::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrpg
			, const string& sqlstrlite
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) executeQuery(sqlstrpg);
#endif
#if defined(SBECORE_LITE)
	if (ixDbsVDbstype == VecDbsVDbstype::LITE) executeQuery(sqlstrlite);
#endif
};

void DbsWzem::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

void DbsWzem::fillFeedFromKlst(
			const uint klsIxWzemVKeylist
			, const uint ixWzemVLocale
			, Feed& feed
		) {
	ListWzemAVKeylistKey klsAkeys;
	WzemAVKeylistKey* klsAkey = NULL;

	tblwzemavkeylistkey->loadRstByKls(klsIxWzemVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwzemjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWzemVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsWzem::fillFeedFromKlstByMtbUref(
			const uint klsIxWzemVKeylist
			, const uint x1IxWzemVMaintable
			, const ubigint x1Uref
			, const uint ixWzemVLocale
			, Feed& feed
		) {
	ListWzemAVKeylistKey klsAkeys;
	WzemAVKeylistKey* klsAkey = NULL;

	tblwzemavkeylistkey->loadRstByKlsMtbUrf(klsIxWzemVKeylist, x1IxWzemVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwzemjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWzemVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsWzem::getKlstTitleBySref(
			const uint klsIxWzemVKeylist
			, const string& sref
			, const uint ixWzemVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwzemavkeylistkey->loadRefByKlsSrf(klsIxWzemVKeylist, sref, refKlk))
		if (!tblwzemjavkeylistkey->loadTitByKlkLcl(refKlk, ixWzemVLocale, retval))
			tblwzemavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsWzem::getKlstTitleByMtbUrefSref(
			const uint klsIxWzemVKeylist
			, const uint x1IxWzemVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixWzemVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwzemavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxWzemVKeylist, x1IxWzemVMaintable, x1Uref, sref, refKlk))
		if (!tblwzemjavkeylistkey->loadTitByKlkLcl(refKlk, ixWzemVLocale, retval))
			tblwzemavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsWzem::fillFeedFromVlst(
			const uint vlsIxWzemVValuelist
			, const uint x1IxWzemVLocale
			, Feed& feed
		) {
	ListWzemAVValuelistVal vlsAvals;
	WzemAVValuelistVal* vlsAval = NULL;

	tblwzemavvaluelistval->loadRstByVlsLcl(vlsIxWzemVValuelist, x1IxWzemVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i = 0; i < vlsAvals.nodes.size(); i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};

