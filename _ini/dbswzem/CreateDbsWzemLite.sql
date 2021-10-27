-- file CreateDbsWzemLite.sql
-- SQLite database create script
-- copyright: (C) 2016-2020 MPSI Technologies GmbH
-- author: Alexander Wirthmueller (auto-generation)
-- date created: 3 May 2021
-- IP header --- ABOVE

DROP TABLE IF EXISTS TblWzemAccRMUserUniversal;
DROP TABLE IF EXISTS TblWzemAMPersonDetail;
DROP TABLE IF EXISTS TblWzemAMUserAccess;
DROP TABLE IF EXISTS TblWzemAMUsergroupAccess;
DROP TABLE IF EXISTS TblWzemAVControlPar;
DROP TABLE IF EXISTS TblWzemAVKeylistKey;
DROP TABLE IF EXISTS TblWzemAVValuelistVal;
DROP TABLE IF EXISTS TblWzemCEvent;
DROP TABLE IF EXISTS TblWzemHistRMUserUniversal;
DROP TABLE IF EXISTS TblWzemJAVKeylistKey;
DROP TABLE IF EXISTS TblWzemJMCallArgRet;
DROP TABLE IF EXISTS TblWzemJMClstn;
DROP TABLE IF EXISTS TblWzemJMJobDcol;
DROP TABLE IF EXISTS TblWzemJMJobStmgr;
DROP TABLE IF EXISTS TblWzemJMPersonLastname;
DROP TABLE IF EXISTS TblWzemJMPresetArg;
DROP TABLE IF EXISTS TblWzemJMUserState;
DROP TABLE IF EXISTS TblWzemMCall;
DROP TABLE IF EXISTS TblWzemMClstn;
DROP TABLE IF EXISTS TblWzemMDpch;
DROP TABLE IF EXISTS TblWzemMEvent;
DROP TABLE IF EXISTS TblWzemMJob;
DROP TABLE IF EXISTS TblWzemMNode;
DROP TABLE IF EXISTS TblWzemMOp;
DROP TABLE IF EXISTS TblWzemMPeriod;
DROP TABLE IF EXISTS TblWzemMPerson;
DROP TABLE IF EXISTS TblWzemMPreset;
DROP TABLE IF EXISTS TblWzemMSession;
DROP TABLE IF EXISTS TblWzemMUser;
DROP TABLE IF EXISTS TblWzemMUsergroup;
DROP TABLE IF EXISTS TblWzemRMUsergroupUniversal;
DROP TABLE IF EXISTS TblWzemRMUserMUsergroup;

DROP TABLE IF EXISTS TblWzemQCalList;
DROP TABLE IF EXISTS TblWzemQClnList;
DROP TABLE IF EXISTS TblWzemQEvtList;
DROP TABLE IF EXISTS TblWzemQJob1NCall;
DROP TABLE IF EXISTS TblWzemQJob1NClstn;
DROP TABLE IF EXISTS TblWzemQJob1NOp;
DROP TABLE IF EXISTS TblWzemQJob1NPreset;
DROP TABLE IF EXISTS TblWzemQJobList;
DROP TABLE IF EXISTS TblWzemQJobSup1NJob;
DROP TABLE IF EXISTS TblWzemQNdeList;
DROP TABLE IF EXISTS TblWzemQOpxList;
DROP TABLE IF EXISTS TblWzemQPrd1NEvent;
DROP TABLE IF EXISTS TblWzemQPrd1NJob;
DROP TABLE IF EXISTS TblWzemQPrd1NNode;
DROP TABLE IF EXISTS TblWzemQPrdList;
DROP TABLE IF EXISTS TblWzemQPreselect;
DROP TABLE IF EXISTS TblWzemQPrsADetail;
DROP TABLE IF EXISTS TblWzemQPrsList;
DROP TABLE IF EXISTS TblWzemQPstList;
DROP TABLE IF EXISTS TblWzemQSelect;
DROP TABLE IF EXISTS TblWzemQUsgAAccess;
DROP TABLE IF EXISTS TblWzemQUsgList;
DROP TABLE IF EXISTS TblWzemQUsgMNUser;
DROP TABLE IF EXISTS TblWzemQUsr1NSession;
DROP TABLE IF EXISTS TblWzemQUsrAAccess;
DROP TABLE IF EXISTS TblWzemQUsrList;
DROP TABLE IF EXISTS TblWzemQUsrMNUsergroup;

CREATE TABLE TblWzemAccRMUserUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUser BIGINT,
	unvIxWzemVMaintable INT,
	unvUref BIGINT,
	ixWzemVRecaccess INT
);
CREATE INDEX TblWzemAccRMUserUniversal_refWzemMUser ON TblWzemAccRMUserUniversal (refWzemMUser);
CREATE INDEX TblWzemAccRMUserUniversal_unvIxWzemVMaintable ON TblWzemAccRMUserUniversal (unvIxWzemVMaintable);
CREATE INDEX TblWzemAccRMUserUniversal_unvUref ON TblWzemAccRMUserUniversal (unvUref);

CREATE TABLE TblWzemAMPersonDetail(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
CREATE INDEX TblWzemAMPersonDetail_refWzemMPerson ON TblWzemAMPersonDetail (refWzemMPerson);

CREATE TABLE TblWzemAMUserAccess(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUser BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
CREATE INDEX TblWzemAMUserAccess_refWzemMUser ON TblWzemAMUserAccess (refWzemMUser);
CREATE INDEX TblWzemAMUserAccess_x1IxWzemVFeatgroup ON TblWzemAMUserAccess (x1IxWzemVFeatgroup);
CREATE INDEX TblWzemAMUserAccess_x2FeaSrefUix ON TblWzemAMUserAccess (x2FeaSrefUix);

CREATE TABLE TblWzemAMUsergroupAccess(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUsergroup BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
CREATE INDEX TblWzemAMUsergroupAccess_refWzemMUsergroup ON TblWzemAMUsergroupAccess (refWzemMUsergroup);
CREATE INDEX TblWzemAMUsergroupAccess_x1IxWzemVFeatgroup ON TblWzemAMUsergroupAccess (x1IxWzemVFeatgroup);
CREATE INDEX TblWzemAMUsergroupAccess_x2FeaSrefUix ON TblWzemAMUsergroupAccess (x2FeaSrefUix);

CREATE TABLE TblWzemAVControlPar(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	ixWzemVControl INT,
	x1RefWzemMUser BIGINT,
	x2IxWzemVLocale INT,
	Par VARCHAR(192),
	Val VARCHAR(192)
);
CREATE INDEX TblWzemAVControlPar_ixWzemVControl ON TblWzemAVControlPar (ixWzemVControl);
CREATE INDEX TblWzemAVControlPar_x1RefWzemMUser ON TblWzemAVControlPar (x1RefWzemMUser);
CREATE INDEX TblWzemAVControlPar_x2IxWzemVLocale ON TblWzemAVControlPar (x2IxWzemVLocale);
CREATE INDEX TblWzemAVControlPar_Par ON TblWzemAVControlPar (Par);

CREATE TABLE TblWzemAVKeylistKey(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	klsIxWzemVKeylist INT,
	klsNum INT,
	x1IxWzemVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
CREATE INDEX TblWzemAVKeylistKey_klsIxWzemVKeylist ON TblWzemAVKeylistKey (klsIxWzemVKeylist);
CREATE INDEX TblWzemAVKeylistKey_klsNum ON TblWzemAVKeylistKey (klsNum);
CREATE INDEX TblWzemAVKeylistKey_x1IxWzemVMaintable ON TblWzemAVKeylistKey (x1IxWzemVMaintable);
CREATE INDEX TblWzemAVKeylistKey_x1Uref ON TblWzemAVKeylistKey (x1Uref);
CREATE INDEX TblWzemAVKeylistKey_sref ON TblWzemAVKeylistKey (sref);

CREATE TABLE TblWzemAVValuelistVal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	vlsIxWzemVValuelist INT,
	vlsNum INT,
	x1IxWzemVLocale INT,
	Val VARCHAR(192)
);
CREATE INDEX TblWzemAVValuelistVal_vlsIxWzemVValuelist ON TblWzemAVValuelistVal (vlsIxWzemVValuelist);
CREATE INDEX TblWzemAVValuelistVal_vlsNum ON TblWzemAVValuelistVal (vlsNum);
CREATE INDEX TblWzemAVValuelistVal_x1IxWzemVLocale ON TblWzemAVValuelistVal (x1IxWzemVLocale);

CREATE TABLE TblWzemCEvent(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	void SMALLINT

);

CREATE TABLE TblWzemHistRMUserUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUser BIGINT,
	unvIxWzemVMaintable INT,
	unvUref BIGINT,
	ixWzemVCard INT,
	ixWzemVPreset INT,
	preIxWzemVMaintable INT,
	preUref BIGINT,
	start INT
);
CREATE INDEX TblWzemHistRMUserUniversal_refWzemMUser ON TblWzemHistRMUserUniversal (refWzemMUser);
CREATE INDEX TblWzemHistRMUserUniversal_unvIxWzemVMaintable ON TblWzemHistRMUserUniversal (unvIxWzemVMaintable);
CREATE INDEX TblWzemHistRMUserUniversal_unvUref ON TblWzemHistRMUserUniversal (unvUref);
CREATE INDEX TblWzemHistRMUserUniversal_ixWzemVCard ON TblWzemHistRMUserUniversal (ixWzemVCard);
CREATE INDEX TblWzemHistRMUserUniversal_ixWzemVPreset ON TblWzemHistRMUserUniversal (ixWzemVPreset);
CREATE INDEX TblWzemHistRMUserUniversal_preIxWzemVMaintable ON TblWzemHistRMUserUniversal (preIxWzemVMaintable);
CREATE INDEX TblWzemHistRMUserUniversal_preUref ON TblWzemHistRMUserUniversal (preUref);

CREATE TABLE TblWzemJAVKeylistKey(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemAVKeylistKey BIGINT,
	x1IxWzemVLocale INT,
	Title VARCHAR(192),
	Comment TEXT
);
CREATE INDEX TblWzemJAVKeylistKey_refWzemAVKeylistKey ON TblWzemJAVKeylistKey (refWzemAVKeylistKey);
CREATE INDEX TblWzemJAVKeylistKey_x1IxWzemVLocale ON TblWzemJAVKeylistKey (x1IxWzemVLocale);

CREATE TABLE TblWzemJMCallArgRet(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMCall BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	argRet VARCHAR(192)
);
CREATE INDEX TblWzemJMCallArgRet_refWzemMCall ON TblWzemJMCallArgRet (refWzemMCall);
CREATE INDEX TblWzemJMCallArgRet_x1Startu ON TblWzemJMCallArgRet (x1Startu);
CREATE INDEX TblWzemJMCallArgRet_x1Stopu ON TblWzemJMCallArgRet (x1Stopu);

CREATE TABLE TblWzemJMClstn(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMClstn BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	argMask VARCHAR(192),
	ixVJactype INT
);
CREATE INDEX TblWzemJMClstn_refWzemMClstn ON TblWzemJMClstn (refWzemMClstn);
CREATE INDEX TblWzemJMClstn_x1Startu ON TblWzemJMClstn (x1Startu);
CREATE INDEX TblWzemJMClstn_x1Stopu ON TblWzemJMClstn (x1Stopu);

CREATE TABLE TblWzemJMJobDcol(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMJob BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	Dcol SMALLINT
);
CREATE INDEX TblWzemJMJobDcol_refWzemMJob ON TblWzemJMJobDcol (refWzemMJob);
CREATE INDEX TblWzemJMJobDcol_x1Startu ON TblWzemJMJobDcol (x1Startu);
CREATE INDEX TblWzemJMJobDcol_x1Stopu ON TblWzemJMJobDcol (x1Stopu);

CREATE TABLE TblWzemJMJobStmgr(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMJob BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	Stmgr SMALLINT
);
CREATE INDEX TblWzemJMJobStmgr_refWzemMJob ON TblWzemJMJobStmgr (refWzemMJob);
CREATE INDEX TblWzemJMJobStmgr_x1Startu ON TblWzemJMJobStmgr (x1Startu);
CREATE INDEX TblWzemJMJobStmgr_x1Stopu ON TblWzemJMJobStmgr (x1Stopu);

CREATE TABLE TblWzemJMPersonLastname(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
CREATE INDEX TblWzemJMPersonLastname_refWzemMPerson ON TblWzemJMPersonLastname (refWzemMPerson);
CREATE INDEX TblWzemJMPersonLastname_x1Startd ON TblWzemJMPersonLastname (x1Startd);
CREATE INDEX TblWzemJMPersonLastname_Lastname ON TblWzemJMPersonLastname (Lastname);

CREATE TABLE TblWzemJMPresetArg(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMPreset BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	arg VARCHAR(192)
);
CREATE INDEX TblWzemJMPresetArg_refWzemMPreset ON TblWzemJMPresetArg (refWzemMPreset);
CREATE INDEX TblWzemJMPresetArg_x1Startu ON TblWzemJMPresetArg (x1Startu);
CREATE INDEX TblWzemJMPresetArg_x1Stopu ON TblWzemJMPresetArg (x1Stopu);

CREATE TABLE TblWzemJMUserState(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUser BIGINT,
	x1Start INT,
	ixVState INT
);
CREATE INDEX TblWzemJMUserState_refWzemMUser ON TblWzemJMUserState (refWzemMUser);
CREATE INDEX TblWzemJMUserState_x1Start ON TblWzemJMUserState (x1Start);

CREATE TABLE TblWzemMCall(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	argInv VARCHAR(192),
	argRet VARCHAR(192)
);
CREATE INDEX TblWzemMCall_x1Startu ON TblWzemMCall (x1Startu);
CREATE INDEX TblWzemMCall_x1Stopu ON TblWzemMCall (x1Stopu);
CREATE INDEX TblWzemMCall_refWzemMJob ON TblWzemMCall (refWzemMJob);

CREATE TABLE TblWzemMClstn(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	ixVTarget INT,
	ixVJobmask INT,
	tjbRefWzemMJob BIGINT,
	ixVArgmask INT,
	arg VARCHAR(192),
	srefIxVSge VARCHAR(192),
	ixVJactype INT
);
CREATE INDEX TblWzemMClstn_x1Startu ON TblWzemMClstn (x1Startu);
CREATE INDEX TblWzemMClstn_x1Stopu ON TblWzemMClstn (x1Stopu);
CREATE INDEX TblWzemMClstn_refWzemMJob ON TblWzemMClstn (refWzemMJob);

CREATE TABLE TblWzemMDpch(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMEvent BIGINT,
	srefIxVDpch VARCHAR(192),
	srefsMask VARCHAR(192),
	Content TEXT
);
CREATE INDEX TblWzemMDpch_refWzemMEvent ON TblWzemMDpch (refWzemMEvent);

CREATE TABLE TblWzemMEvent(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	ixVBasetype INT,
	refWzemCEvent BIGINT,
	refWzemMPeriod BIGINT,
	refWzemMDpch BIGINT,
	startu DOUBLE PRECISION,
	refWzemMCall BIGINT,
	refWzemMClstn BIGINT,
	refWzemMJob BIGINT,
	refWzemMNode BIGINT,
	refWzemMOp BIGINT,
	refWzemMPreset BIGINT,
	Cmd VARCHAR(192),
	Filename TEXT,
	srefIxVFeatgroup VARCHAR(192),
	srefIxVMethod VARCHAR(192),
	xsref VARCHAR(192)
);
CREATE INDEX TblWzemMEvent_ixVBasetype ON TblWzemMEvent (ixVBasetype);
CREATE INDEX TblWzemMEvent_refWzemCEvent ON TblWzemMEvent (refWzemCEvent);
CREATE INDEX TblWzemMEvent_refWzemMPeriod ON TblWzemMEvent (refWzemMPeriod);
CREATE INDEX TblWzemMEvent_refWzemMDpch ON TblWzemMEvent (refWzemMDpch);
CREATE INDEX TblWzemMEvent_startu ON TblWzemMEvent (startu);

CREATE TABLE TblWzemMJob(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMPeriod BIGINT,
	supRefWzemMJob BIGINT,
	srefIxVJob VARCHAR(192),
	xjref BIGINT,
	Clisrv SMALLINT,
	srvNotCli SMALLINT,
	Dcol SMALLINT,
	Stmgr SMALLINT
);
CREATE INDEX TblWzemMJob_x1Startu ON TblWzemMJob (x1Startu);
CREATE INDEX TblWzemMJob_x1Stopu ON TblWzemMJob (x1Stopu);
CREATE INDEX TblWzemMJob_refWzemMPeriod ON TblWzemMJob (refWzemMPeriod);
CREATE INDEX TblWzemMJob_supRefWzemMJob ON TblWzemMJob (supRefWzemMJob);

CREATE TABLE TblWzemMNode(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMPeriod BIGINT,
	xnref BIGINT,
	Ip VARCHAR(30),
	Port SMALLINT,
	Opprcn SMALLINT
);
CREATE INDEX TblWzemMNode_x1Startu ON TblWzemMNode (x1Startu);
CREATE INDEX TblWzemMNode_x1Stopu ON TblWzemMNode (x1Stopu);
CREATE INDEX TblWzemMNode_refWzemMPeriod ON TblWzemMNode (refWzemMPeriod);

CREATE TABLE TblWzemMOp(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	xoref BIGINT
);
CREATE INDEX TblWzemMOp_x1Startu ON TblWzemMOp (x1Startu);
CREATE INDEX TblWzemMOp_x1Stopu ON TblWzemMOp (x1Stopu);
CREATE INDEX TblWzemMOp_refWzemMJob ON TblWzemMOp (refWzemMJob);

CREATE TABLE TblWzemMPeriod(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	Version VARCHAR(192),
	start INT,
	stop INT
);
CREATE INDEX TblWzemMPeriod_grp ON TblWzemMPeriod (grp);
CREATE INDEX TblWzemMPeriod_own ON TblWzemMPeriod (own);
CREATE INDEX TblWzemMPeriod_start ON TblWzemMPeriod (start);

CREATE TABLE TblWzemMPerson(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	telVal VARCHAR(192),
	emlRefADetail BIGINT,
	emlVal VARCHAR(192),
	Salutation VARCHAR(100)
);
CREATE INDEX TblWzemMPerson_grp ON TblWzemMPerson (grp);
CREATE INDEX TblWzemMPerson_own ON TblWzemMPerson (own);
CREATE INDEX TblWzemMPerson_ixWDerivate ON TblWzemMPerson (ixWDerivate);
CREATE INDEX TblWzemMPerson_Lastname ON TblWzemMPerson (Lastname);

CREATE TABLE TblWzemMPreset(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	srefIxVPreset VARCHAR(192),
	arg VARCHAR(192)
);
CREATE INDEX TblWzemMPreset_x1Startu ON TblWzemMPreset (x1Startu);
CREATE INDEX TblWzemMPreset_x1Stopu ON TblWzemMPreset (x1Stopu);
CREATE INDEX TblWzemMPreset_refWzemMJob ON TblWzemMPreset (refWzemMJob);

CREATE TABLE TblWzemMSession(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
CREATE INDEX TblWzemMSession_refWzemMUser ON TblWzemMSession (refWzemMUser);
CREATE INDEX TblWzemMSession_start ON TblWzemMSession (start);

CREATE TABLE TblWzemMUser(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refWzemMUsergroup BIGINT,
	refWzemMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixWzemVLocale INT,
	ixWzemVUserlevel INT,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT
);
CREATE INDEX TblWzemMUser_grp ON TblWzemMUser (grp);
CREATE INDEX TblWzemMUser_own ON TblWzemMUser (own);
CREATE INDEX TblWzemMUser_refWzemMUsergroup ON TblWzemMUser (refWzemMUsergroup);
CREATE INDEX TblWzemMUser_refWzemMPerson ON TblWzemMUser (refWzemMPerson);
CREATE INDEX TblWzemMUser_sref ON TblWzemMUser (sref);
CREATE INDEX TblWzemMUser_refJState ON TblWzemMUser (refJState);
CREATE INDEX TblWzemMUser_ixVState ON TblWzemMUser (ixVState);

CREATE TABLE TblWzemMUsergroup(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
CREATE INDEX TblWzemMUsergroup_grp ON TblWzemMUsergroup (grp);
CREATE INDEX TblWzemMUsergroup_own ON TblWzemMUsergroup (own);
CREATE INDEX TblWzemMUsergroup_sref ON TblWzemMUsergroup (sref);

CREATE TABLE TblWzemRMUsergroupUniversal(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUsergroup BIGINT,
	unvIxWzemVMaintable INT,
	unvUref BIGINT,
	ixWzemVRecaccess INT
);
CREATE INDEX TblWzemRMUsergroupUniversal_refWzemMUsergroup ON TblWzemRMUsergroupUniversal (refWzemMUsergroup);
CREATE INDEX TblWzemRMUsergroupUniversal_unvIxWzemVMaintable ON TblWzemRMUsergroupUniversal (unvIxWzemVMaintable);
CREATE INDEX TblWzemRMUsergroupUniversal_unvUref ON TblWzemRMUsergroupUniversal (unvUref);

CREATE TABLE TblWzemRMUserMUsergroup(
	ref INTEGER PRIMARY KEY AUTOINCREMENT,
	refWzemMUser BIGINT,
	refWzemMUsergroup BIGINT,
	ixWzemVUserlevel INT
);
CREATE INDEX TblWzemRMUserMUsergroup_refWzemMUser ON TblWzemRMUserMUsergroup (refWzemMUser);
CREATE INDEX TblWzemRMUserMUsergroup_refWzemMUsergroup ON TblWzemRMUserMUsergroup (refWzemMUsergroup);

CREATE TABLE TblWzemQCalList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
CREATE INDEX TblWzemQCalList_jref ON TblWzemQCalList (jref);
CREATE INDEX TblWzemQCalList_jnum ON TblWzemQCalList (jnum);

CREATE TABLE TblWzemQClnList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	srefIxVSge VARCHAR(192),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
CREATE INDEX TblWzemQClnList_jref ON TblWzemQClnList (jref);
CREATE INDEX TblWzemQClnList_jnum ON TblWzemQClnList (jnum);

CREATE TABLE TblWzemQEvtList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	ixVBasetype INT,
	refWzemMPeriod BIGINT,
	startu DOUBLE PRECISION,
	refWzemMDpch BIGINT,
	Cmd VARCHAR(192),
	srefIxVFeatgroup VARCHAR(192),
	srefIxVMethod VARCHAR(192),
	xsref VARCHAR(192)
);
CREATE INDEX TblWzemQEvtList_jref ON TblWzemQEvtList (jref);
CREATE INDEX TblWzemQEvtList_jnum ON TblWzemQEvtList (jnum);

CREATE TABLE TblWzemQJob1NCall(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQJob1NCall_jref ON TblWzemQJob1NCall (jref);
CREATE INDEX TblWzemQJob1NCall_jnum ON TblWzemQJob1NCall (jnum);

CREATE TABLE TblWzemQJob1NClstn(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQJob1NClstn_jref ON TblWzemQJob1NClstn (jref);
CREATE INDEX TblWzemQJob1NClstn_jnum ON TblWzemQJob1NClstn (jnum);

CREATE TABLE TblWzemQJob1NOp(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQJob1NOp_jref ON TblWzemQJob1NOp (jref);
CREATE INDEX TblWzemQJob1NOp_jnum ON TblWzemQJob1NOp (jnum);

CREATE TABLE TblWzemQJob1NPreset(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQJob1NPreset_jref ON TblWzemQJob1NPreset (jref);
CREATE INDEX TblWzemQJob1NPreset_jnum ON TblWzemQJob1NPreset (jnum);

CREATE TABLE TblWzemQJobList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMPeriod BIGINT,
	srefIxVJob VARCHAR(192),
	xjref BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	supRefWzemMJob BIGINT
);
CREATE INDEX TblWzemQJobList_jref ON TblWzemQJobList (jref);
CREATE INDEX TblWzemQJobList_jnum ON TblWzemQJobList (jnum);

CREATE TABLE TblWzemQJobSup1NJob(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQJobSup1NJob_jref ON TblWzemQJobSup1NJob (jref);
CREATE INDEX TblWzemQJobSup1NJob_jnum ON TblWzemQJobSup1NJob (jnum);

CREATE TABLE TblWzemQNdeList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMPeriod BIGINT,
	xnref BIGINT,
	Ip VARCHAR(30),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	Port SMALLINT,
	Opprcn SMALLINT
);
CREATE INDEX TblWzemQNdeList_jref ON TblWzemQNdeList (jref);
CREATE INDEX TblWzemQNdeList_jnum ON TblWzemQNdeList (jnum);

CREATE TABLE TblWzemQOpxList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	xoref BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
CREATE INDEX TblWzemQOpxList_jref ON TblWzemQOpxList (jref);
CREATE INDEX TblWzemQOpxList_jnum ON TblWzemQOpxList (jnum);

CREATE TABLE TblWzemQPrd1NEvent(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQPrd1NEvent_jref ON TblWzemQPrd1NEvent (jref);
CREATE INDEX TblWzemQPrd1NEvent_jnum ON TblWzemQPrd1NEvent (jnum);

CREATE TABLE TblWzemQPrd1NJob(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQPrd1NJob_jref ON TblWzemQPrd1NJob (jref);
CREATE INDEX TblWzemQPrd1NJob_jnum ON TblWzemQPrd1NJob (jnum);

CREATE TABLE TblWzemQPrd1NNode(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQPrd1NNode_jref ON TblWzemQPrd1NNode (jref);
CREATE INDEX TblWzemQPrd1NNode_jnum ON TblWzemQPrd1NNode (jnum);

CREATE TABLE TblWzemQPrdList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Version VARCHAR(192),
	start INT,
	stop INT
);
CREATE INDEX TblWzemQPrdList_jref ON TblWzemQPrdList (jref);
CREATE INDEX TblWzemQPrdList_jnum ON TblWzemQPrdList (jnum);

CREATE TABLE TblWzemQPreselect(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQPreselect_jref ON TblWzemQPreselect (jref);

CREATE TABLE TblWzemQPrsADetail(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
CREATE INDEX TblWzemQPrsADetail_jref ON TblWzemQPrsADetail (jref);
CREATE INDEX TblWzemQPrsADetail_jnum ON TblWzemQPrsADetail (jnum);

CREATE TABLE TblWzemQPrsList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	ixVSex INT,
	telVal VARCHAR(192),
	emlVal VARCHAR(192)
);
CREATE INDEX TblWzemQPrsList_jref ON TblWzemQPrsList (jref);
CREATE INDEX TblWzemQPrsList_jnum ON TblWzemQPrsList (jnum);

CREATE TABLE TblWzemQPstList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	srefIxVPreset VARCHAR(192),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
CREATE INDEX TblWzemQPstList_jref ON TblWzemQPstList (jref);
CREATE INDEX TblWzemQPstList_jnum ON TblWzemQPstList (jnum);

CREATE TABLE TblWzemQSelect(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
CREATE INDEX TblWzemQSelect_jref ON TblWzemQSelect (jref);
CREATE INDEX TblWzemQSelect_ix ON TblWzemQSelect (ix);

CREATE TABLE TblWzemQUsgAAccess(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
CREATE INDEX TblWzemQUsgAAccess_jref ON TblWzemQUsgAAccess (jref);
CREATE INDEX TblWzemQUsgAAccess_jnum ON TblWzemQUsgAAccess (jnum);

CREATE TABLE TblWzemQUsgList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50)
);
CREATE INDEX TblWzemQUsgList_jref ON TblWzemQUsgList (jref);
CREATE INDEX TblWzemQUsgList_jnum ON TblWzemQUsgList (jnum);

CREATE TABLE TblWzemQUsgMNUser(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWzemVUserlevel INT
);
CREATE INDEX TblWzemQUsgMNUser_jref ON TblWzemQUsgMNUser (jref);
CREATE INDEX TblWzemQUsgMNUser_jnum ON TblWzemQUsgMNUser (jnum);

CREATE TABLE TblWzemQUsr1NSession(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
CREATE INDEX TblWzemQUsr1NSession_jref ON TblWzemQUsr1NSession (jref);
CREATE INDEX TblWzemQUsr1NSession_jnum ON TblWzemQUsr1NSession (jnum);

CREATE TABLE TblWzemQUsrAAccess(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
CREATE INDEX TblWzemQUsrAAccess_jref ON TblWzemQUsrAAccess (jref);
CREATE INDEX TblWzemQUsrAAccess_jnum ON TblWzemQUsrAAccess (jnum);

CREATE TABLE TblWzemQUsrList(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	refWzemMPerson BIGINT,
	sref VARCHAR(50),
	refWzemMUsergroup BIGINT,
	ixVState INT,
	ixWzemVLocale INT,
	ixWzemVUserlevel INT
);
CREATE INDEX TblWzemQUsrList_jref ON TblWzemQUsrList (jref);
CREATE INDEX TblWzemQUsrList_jnum ON TblWzemQUsrList (jnum);

CREATE TABLE TblWzemQUsrMNUsergroup(
	qref INTEGER PRIMARY KEY AUTOINCREMENT,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWzemVUserlevel INT
);
CREATE INDEX TblWzemQUsrMNUsergroup_jref ON TblWzemQUsrMNUsergroup (jref);
CREATE INDEX TblWzemQUsrMNUsergroup_jnum ON TblWzemQUsrMNUsergroup (jnum);
