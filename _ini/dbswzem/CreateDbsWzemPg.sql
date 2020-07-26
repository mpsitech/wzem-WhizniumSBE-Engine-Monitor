-- CREATE ROLE mpsitech LOGIN
-- 	UNENCRYPTED PASSWORD 'asdf1234'
-- 	NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE;
-- COMMENT ON ROLE mpsitech IS 'MPSI Technologies GmbH';

CREATE DATABASE "DbsWzem"
	WITH ENCODING='UTF8'
	OWNER = mpsitech
	CONNECTION LIMIT = -1;

DROP TABLE IF EXISTS TblWzemAccRMUserUniversal;
DROP TABLE IF EXISTS TblWzemAMPersonDetail;
DROP TABLE IF EXISTS TblWzemAMUserAccess;
DROP TABLE IF EXISTS TblWzemAMUsergroupAccess;
DROP TABLE IF EXISTS TblWzemAVControlPar;
DROP TABLE IF EXISTS TblWzemAVKeylistKey;
DROP TABLE IF EXISTS TblWzemAVValuelistVal;
DROP SEQUENCE IF EXISTS TblWzemCEvent;
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
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUser BIGINT,
	unvIxWzemVMaintable INT,
	unvUref BIGINT,
	ixWzemVRecaccess INT
);
ALTER TABLE TblWzemAccRMUserUniversal OWNER TO epsi;
CREATE INDEX TblWzemAccRMUserUniversal_refWzemMUser ON TblWzemAccRMUserUniversal (refWzemMUser);
CREATE INDEX TblWzemAccRMUserUniversal_unvIxWzemVMaintable ON TblWzemAccRMUserUniversal (unvIxWzemVMaintable);
CREATE INDEX TblWzemAccRMUserUniversal_unvUref ON TblWzemAccRMUserUniversal (unvUref);

CREATE TABLE TblWzemAMPersonDetail(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWzemAMPersonDetail OWNER TO epsi;
CREATE INDEX TblWzemAMPersonDetail_refWzemMPerson ON TblWzemAMPersonDetail (refWzemMPerson);

CREATE TABLE TblWzemAMUserAccess(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUser BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
ALTER TABLE TblWzemAMUserAccess OWNER TO epsi;
CREATE INDEX TblWzemAMUserAccess_refWzemMUser ON TblWzemAMUserAccess (refWzemMUser);
CREATE INDEX TblWzemAMUserAccess_x1IxWzemVFeatgroup ON TblWzemAMUserAccess (x1IxWzemVFeatgroup);
CREATE INDEX TblWzemAMUserAccess_x2FeaSrefUix ON TblWzemAMUserAccess (x2FeaSrefUix);

CREATE TABLE TblWzemAMUsergroupAccess(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUsergroup BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
ALTER TABLE TblWzemAMUsergroupAccess OWNER TO epsi;
CREATE INDEX TblWzemAMUsergroupAccess_refWzemMUsergroup ON TblWzemAMUsergroupAccess (refWzemMUsergroup);
CREATE INDEX TblWzemAMUsergroupAccess_x1IxWzemVFeatgroup ON TblWzemAMUsergroupAccess (x1IxWzemVFeatgroup);
CREATE INDEX TblWzemAMUsergroupAccess_x2FeaSrefUix ON TblWzemAMUsergroupAccess (x2FeaSrefUix);

CREATE TABLE TblWzemAVControlPar(
	ref BIGSERIAL PRIMARY KEY,
	ixWzemVControl INT,
	x1RefWzemMUser BIGINT,
	x2IxWzemVLocale INT,
	Par VARCHAR(192),
	Val VARCHAR(192)
);
ALTER TABLE TblWzemAVControlPar OWNER TO epsi;
CREATE INDEX TblWzemAVControlPar_ixWzemVControl ON TblWzemAVControlPar (ixWzemVControl);
CREATE INDEX TblWzemAVControlPar_x1RefWzemMUser ON TblWzemAVControlPar (x1RefWzemMUser);
CREATE INDEX TblWzemAVControlPar_x2IxWzemVLocale ON TblWzemAVControlPar (x2IxWzemVLocale);
CREATE INDEX TblWzemAVControlPar_Par ON TblWzemAVControlPar (Par);

CREATE TABLE TblWzemAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemAVKeylistKey OWNER TO epsi;
CREATE INDEX TblWzemAVKeylistKey_klsIxWzemVKeylist ON TblWzemAVKeylistKey (klsIxWzemVKeylist);
CREATE INDEX TblWzemAVKeylistKey_klsNum ON TblWzemAVKeylistKey (klsNum);
CREATE INDEX TblWzemAVKeylistKey_x1IxWzemVMaintable ON TblWzemAVKeylistKey (x1IxWzemVMaintable);
CREATE INDEX TblWzemAVKeylistKey_x1Uref ON TblWzemAVKeylistKey (x1Uref);
CREATE INDEX TblWzemAVKeylistKey_sref ON TblWzemAVKeylistKey (sref);

CREATE TABLE TblWzemAVValuelistVal(
	ref BIGSERIAL PRIMARY KEY,
	vlsIxWzemVValuelist INT,
	vlsNum INT,
	x1IxWzemVLocale INT,
	Val VARCHAR(192)
);
ALTER TABLE TblWzemAVValuelistVal OWNER TO epsi;
CREATE INDEX TblWzemAVValuelistVal_vlsIxWzemVValuelist ON TblWzemAVValuelistVal (vlsIxWzemVValuelist);
CREATE INDEX TblWzemAVValuelistVal_vlsNum ON TblWzemAVValuelistVal (vlsNum);
CREATE INDEX TblWzemAVValuelistVal_x1IxWzemVLocale ON TblWzemAVValuelistVal (x1IxWzemVLocale);

CREATE SEQUENCE TblWzemCEvent INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWzemCEvent OWNER TO epsi;

CREATE TABLE TblWzemHistRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUser BIGINT,
	unvIxWzemVMaintable INT,
	unvUref BIGINT,
	ixWzemVCard INT,
	ixWzemVPreset INT,
	preIxWzemVMaintable INT,
	preUref BIGINT,
	start INT
);
ALTER TABLE TblWzemHistRMUserUniversal OWNER TO epsi;
CREATE INDEX TblWzemHistRMUserUniversal_refWzemMUser ON TblWzemHistRMUserUniversal (refWzemMUser);
CREATE INDEX TblWzemHistRMUserUniversal_unvIxWzemVMaintable ON TblWzemHistRMUserUniversal (unvIxWzemVMaintable);
CREATE INDEX TblWzemHistRMUserUniversal_unvUref ON TblWzemHistRMUserUniversal (unvUref);
CREATE INDEX TblWzemHistRMUserUniversal_ixWzemVCard ON TblWzemHistRMUserUniversal (ixWzemVCard);
CREATE INDEX TblWzemHistRMUserUniversal_ixWzemVPreset ON TblWzemHistRMUserUniversal (ixWzemVPreset);
CREATE INDEX TblWzemHistRMUserUniversal_preIxWzemVMaintable ON TblWzemHistRMUserUniversal (preIxWzemVMaintable);
CREATE INDEX TblWzemHistRMUserUniversal_preUref ON TblWzemHistRMUserUniversal (preUref);

CREATE TABLE TblWzemJAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	refWzemAVKeylistKey BIGINT,
	x1IxWzemVLocale INT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWzemJAVKeylistKey OWNER TO epsi;
CREATE INDEX TblWzemJAVKeylistKey_refWzemAVKeylistKey ON TblWzemJAVKeylistKey (refWzemAVKeylistKey);
CREATE INDEX TblWzemJAVKeylistKey_x1IxWzemVLocale ON TblWzemJAVKeylistKey (x1IxWzemVLocale);

CREATE TABLE TblWzemJMCallArgRet(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMCall BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	argRet VARCHAR(192)
);
ALTER TABLE TblWzemJMCallArgRet OWNER TO epsi;
CREATE INDEX TblWzemJMCallArgRet_refWzemMCall ON TblWzemJMCallArgRet (refWzemMCall);
CREATE INDEX TblWzemJMCallArgRet_x1Startu ON TblWzemJMCallArgRet (x1Startu);
CREATE INDEX TblWzemJMCallArgRet_x1Stopu ON TblWzemJMCallArgRet (x1Stopu);

CREATE TABLE TblWzemJMClstn(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMClstn BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	argMask VARCHAR(192),
	ixVJactype INT
);
ALTER TABLE TblWzemJMClstn OWNER TO epsi;
CREATE INDEX TblWzemJMClstn_refWzemMClstn ON TblWzemJMClstn (refWzemMClstn);
CREATE INDEX TblWzemJMClstn_x1Startu ON TblWzemJMClstn (x1Startu);
CREATE INDEX TblWzemJMClstn_x1Stopu ON TblWzemJMClstn (x1Stopu);

CREATE TABLE TblWzemJMJobDcol(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMJob BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	Dcol SMALLINT
);
ALTER TABLE TblWzemJMJobDcol OWNER TO epsi;
CREATE INDEX TblWzemJMJobDcol_refWzemMJob ON TblWzemJMJobDcol (refWzemMJob);
CREATE INDEX TblWzemJMJobDcol_x1Startu ON TblWzemJMJobDcol (x1Startu);
CREATE INDEX TblWzemJMJobDcol_x1Stopu ON TblWzemJMJobDcol (x1Stopu);

CREATE TABLE TblWzemJMJobStmgr(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMJob BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	Stmgr SMALLINT
);
ALTER TABLE TblWzemJMJobStmgr OWNER TO epsi;
CREATE INDEX TblWzemJMJobStmgr_refWzemMJob ON TblWzemJMJobStmgr (refWzemMJob);
CREATE INDEX TblWzemJMJobStmgr_x1Startu ON TblWzemJMJobStmgr (x1Startu);
CREATE INDEX TblWzemJMJobStmgr_x1Stopu ON TblWzemJMJobStmgr (x1Stopu);

CREATE TABLE TblWzemJMPersonLastname(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
ALTER TABLE TblWzemJMPersonLastname OWNER TO epsi;
CREATE INDEX TblWzemJMPersonLastname_refWzemMPerson ON TblWzemJMPersonLastname (refWzemMPerson);
CREATE INDEX TblWzemJMPersonLastname_x1Startd ON TblWzemJMPersonLastname (x1Startd);
CREATE INDEX TblWzemJMPersonLastname_Lastname ON TblWzemJMPersonLastname (Lastname);

CREATE TABLE TblWzemJMPresetArg(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMPreset BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	arg VARCHAR(192)
);
ALTER TABLE TblWzemJMPresetArg OWNER TO epsi;
CREATE INDEX TblWzemJMPresetArg_refWzemMPreset ON TblWzemJMPresetArg (refWzemMPreset);
CREATE INDEX TblWzemJMPresetArg_x1Startu ON TblWzemJMPresetArg (x1Startu);
CREATE INDEX TblWzemJMPresetArg_x1Stopu ON TblWzemJMPresetArg (x1Stopu);

CREATE TABLE TblWzemJMUserState(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUser BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblWzemJMUserState OWNER TO epsi;
CREATE INDEX TblWzemJMUserState_refWzemMUser ON TblWzemJMUserState (refWzemMUser);
CREATE INDEX TblWzemJMUserState_x1Start ON TblWzemJMUserState (x1Start);

CREATE TABLE TblWzemMCall(
	ref BIGSERIAL PRIMARY KEY,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	argInv VARCHAR(192),
	argRet VARCHAR(192)
);
ALTER TABLE TblWzemMCall OWNER TO epsi;
CREATE INDEX TblWzemMCall_x1Startu ON TblWzemMCall (x1Startu);
CREATE INDEX TblWzemMCall_x1Stopu ON TblWzemMCall (x1Stopu);
CREATE INDEX TblWzemMCall_refWzemMJob ON TblWzemMCall (refWzemMJob);

CREATE TABLE TblWzemMClstn(
	ref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemMClstn OWNER TO epsi;
CREATE INDEX TblWzemMClstn_x1Startu ON TblWzemMClstn (x1Startu);
CREATE INDEX TblWzemMClstn_x1Stopu ON TblWzemMClstn (x1Stopu);
CREATE INDEX TblWzemMClstn_refWzemMJob ON TblWzemMClstn (refWzemMJob);

CREATE TABLE TblWzemMDpch(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMEvent BIGINT,
	srefIxVDpch VARCHAR(192),
	srefsMask VARCHAR(192),
	Content TEXT
);
ALTER TABLE TblWzemMDpch OWNER TO epsi;
CREATE INDEX TblWzemMDpch_refWzemMEvent ON TblWzemMDpch (refWzemMEvent);

CREATE TABLE TblWzemMEvent(
	ref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemMEvent OWNER TO epsi;
CREATE INDEX TblWzemMEvent_ixVBasetype ON TblWzemMEvent (ixVBasetype);
CREATE INDEX TblWzemMEvent_refWzemCEvent ON TblWzemMEvent (refWzemCEvent);
CREATE INDEX TblWzemMEvent_refWzemMPeriod ON TblWzemMEvent (refWzemMPeriod);
CREATE INDEX TblWzemMEvent_refWzemMDpch ON TblWzemMEvent (refWzemMDpch);
CREATE INDEX TblWzemMEvent_startu ON TblWzemMEvent (startu);

CREATE TABLE TblWzemMJob(
	ref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemMJob OWNER TO epsi;
CREATE INDEX TblWzemMJob_x1Startu ON TblWzemMJob (x1Startu);
CREATE INDEX TblWzemMJob_x1Stopu ON TblWzemMJob (x1Stopu);
CREATE INDEX TblWzemMJob_refWzemMPeriod ON TblWzemMJob (refWzemMPeriod);
CREATE INDEX TblWzemMJob_supRefWzemMJob ON TblWzemMJob (supRefWzemMJob);

CREATE TABLE TblWzemMNode(
	ref BIGSERIAL PRIMARY KEY,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMPeriod BIGINT,
	xnref BIGINT,
	Ip VARCHAR(30),
	Port SMALLINT,
	Opprcn SMALLINT
);
ALTER TABLE TblWzemMNode OWNER TO epsi;
CREATE INDEX TblWzemMNode_x1Startu ON TblWzemMNode (x1Startu);
CREATE INDEX TblWzemMNode_x1Stopu ON TblWzemMNode (x1Stopu);
CREATE INDEX TblWzemMNode_refWzemMPeriod ON TblWzemMNode (refWzemMPeriod);

CREATE TABLE TblWzemMOp(
	ref BIGSERIAL PRIMARY KEY,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	xoref BIGINT
);
ALTER TABLE TblWzemMOp OWNER TO epsi;
CREATE INDEX TblWzemMOp_x1Startu ON TblWzemMOp (x1Startu);
CREATE INDEX TblWzemMOp_x1Stopu ON TblWzemMOp (x1Stopu);
CREATE INDEX TblWzemMOp_refWzemMJob ON TblWzemMOp (refWzemMJob);

CREATE TABLE TblWzemMPeriod(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	Version VARCHAR(192),
	start INT,
	stop INT
);
ALTER TABLE TblWzemMPeriod OWNER TO epsi;
CREATE INDEX TblWzemMPeriod_grp ON TblWzemMPeriod (grp);
CREATE INDEX TblWzemMPeriod_own ON TblWzemMPeriod (own);
CREATE INDEX TblWzemMPeriod_start ON TblWzemMPeriod (start);

CREATE TABLE TblWzemMPerson(
	ref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemMPerson OWNER TO epsi;
CREATE INDEX TblWzemMPerson_grp ON TblWzemMPerson (grp);
CREATE INDEX TblWzemMPerson_own ON TblWzemMPerson (own);
CREATE INDEX TblWzemMPerson_ixWDerivate ON TblWzemMPerson (ixWDerivate);
CREATE INDEX TblWzemMPerson_Lastname ON TblWzemMPerson (Lastname);

CREATE TABLE TblWzemMPreset(
	ref BIGSERIAL PRIMARY KEY,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION,
	refWzemMJob BIGINT,
	srefIxVPreset VARCHAR(192),
	arg VARCHAR(192)
);
ALTER TABLE TblWzemMPreset OWNER TO epsi;
CREATE INDEX TblWzemMPreset_x1Startu ON TblWzemMPreset (x1Startu);
CREATE INDEX TblWzemMPreset_x1Stopu ON TblWzemMPreset (x1Stopu);
CREATE INDEX TblWzemMPreset_refWzemMJob ON TblWzemMPreset (refWzemMJob);

CREATE TABLE TblWzemMSession(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
ALTER TABLE TblWzemMSession OWNER TO epsi;
CREATE INDEX TblWzemMSession_refWzemMUser ON TblWzemMSession (refWzemMUser);
CREATE INDEX TblWzemMSession_start ON TblWzemMSession (start);

CREATE TABLE TblWzemMUser(
	ref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemMUser OWNER TO epsi;
CREATE INDEX TblWzemMUser_grp ON TblWzemMUser (grp);
CREATE INDEX TblWzemMUser_own ON TblWzemMUser (own);
CREATE INDEX TblWzemMUser_refWzemMUsergroup ON TblWzemMUser (refWzemMUsergroup);
CREATE INDEX TblWzemMUser_refWzemMPerson ON TblWzemMUser (refWzemMPerson);
CREATE INDEX TblWzemMUser_sref ON TblWzemMUser (sref);
CREATE INDEX TblWzemMUser_refJState ON TblWzemMUser (refJState);
CREATE INDEX TblWzemMUser_ixVState ON TblWzemMUser (ixVState);

CREATE TABLE TblWzemMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWzemMUsergroup OWNER TO epsi;
CREATE INDEX TblWzemMUsergroup_grp ON TblWzemMUsergroup (grp);
CREATE INDEX TblWzemMUsergroup_own ON TblWzemMUsergroup (own);
CREATE INDEX TblWzemMUsergroup_sref ON TblWzemMUsergroup (sref);

CREATE TABLE TblWzemRMUsergroupUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUsergroup BIGINT,
	unvIxWzemVMaintable INT,
	unvUref BIGINT,
	ixWzemVRecaccess INT
);
ALTER TABLE TblWzemRMUsergroupUniversal OWNER TO epsi;
CREATE INDEX TblWzemRMUsergroupUniversal_refWzemMUsergroup ON TblWzemRMUsergroupUniversal (refWzemMUsergroup);
CREATE INDEX TblWzemRMUsergroupUniversal_unvIxWzemVMaintable ON TblWzemRMUsergroupUniversal (unvIxWzemVMaintable);
CREATE INDEX TblWzemRMUsergroupUniversal_unvUref ON TblWzemRMUsergroupUniversal (unvUref);

CREATE TABLE TblWzemRMUserMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	refWzemMUser BIGINT,
	refWzemMUsergroup BIGINT,
	ixWzemVUserlevel INT
);
ALTER TABLE TblWzemRMUserMUsergroup OWNER TO epsi;
CREATE INDEX TblWzemRMUserMUsergroup_refWzemMUser ON TblWzemRMUserMUsergroup (refWzemMUser);
CREATE INDEX TblWzemRMUserMUsergroup_refWzemMUsergroup ON TblWzemRMUserMUsergroup (refWzemMUsergroup);

CREATE TABLE TblWzemQCalList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
ALTER TABLE TblWzemQCalList OWNER TO epsi;
CREATE INDEX TblWzemQCalList_jref ON TblWzemQCalList (jref);
CREATE INDEX TblWzemQCalList_jnum ON TblWzemQCalList (jnum);

CREATE TABLE TblWzemQClnList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	srefIxVCall VARCHAR(192),
	srefIxVSge VARCHAR(192),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
ALTER TABLE TblWzemQClnList OWNER TO epsi;
CREATE INDEX TblWzemQClnList_jref ON TblWzemQClnList (jref);
CREATE INDEX TblWzemQClnList_jnum ON TblWzemQClnList (jnum);

CREATE TABLE TblWzemQEvtList(
	qref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemQEvtList OWNER TO epsi;
CREATE INDEX TblWzemQEvtList_jref ON TblWzemQEvtList (jref);
CREATE INDEX TblWzemQEvtList_jnum ON TblWzemQEvtList (jnum);

CREATE TABLE TblWzemQJob1NCall(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQJob1NCall OWNER TO epsi;
CREATE INDEX TblWzemQJob1NCall_jref ON TblWzemQJob1NCall (jref);
CREATE INDEX TblWzemQJob1NCall_jnum ON TblWzemQJob1NCall (jnum);

CREATE TABLE TblWzemQJob1NClstn(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQJob1NClstn OWNER TO epsi;
CREATE INDEX TblWzemQJob1NClstn_jref ON TblWzemQJob1NClstn (jref);
CREATE INDEX TblWzemQJob1NClstn_jnum ON TblWzemQJob1NClstn (jnum);

CREATE TABLE TblWzemQJob1NOp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQJob1NOp OWNER TO epsi;
CREATE INDEX TblWzemQJob1NOp_jref ON TblWzemQJob1NOp (jref);
CREATE INDEX TblWzemQJob1NOp_jnum ON TblWzemQJob1NOp (jnum);

CREATE TABLE TblWzemQJob1NPreset(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQJob1NPreset OWNER TO epsi;
CREATE INDEX TblWzemQJob1NPreset_jref ON TblWzemQJob1NPreset (jref);
CREATE INDEX TblWzemQJob1NPreset_jnum ON TblWzemQJob1NPreset (jnum);

CREATE TABLE TblWzemQJobList(
	qref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemQJobList OWNER TO epsi;
CREATE INDEX TblWzemQJobList_jref ON TblWzemQJobList (jref);
CREATE INDEX TblWzemQJobList_jnum ON TblWzemQJobList (jnum);

CREATE TABLE TblWzemQJobSup1NJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQJobSup1NJob OWNER TO epsi;
CREATE INDEX TblWzemQJobSup1NJob_jref ON TblWzemQJobSup1NJob (jref);
CREATE INDEX TblWzemQJobSup1NJob_jnum ON TblWzemQJobSup1NJob (jnum);

CREATE TABLE TblWzemQNdeList(
	qref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemQNdeList OWNER TO epsi;
CREATE INDEX TblWzemQNdeList_jref ON TblWzemQNdeList (jref);
CREATE INDEX TblWzemQNdeList_jnum ON TblWzemQNdeList (jnum);

CREATE TABLE TblWzemQOpxList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	xoref BIGINT,
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
ALTER TABLE TblWzemQOpxList OWNER TO epsi;
CREATE INDEX TblWzemQOpxList_jref ON TblWzemQOpxList (jref);
CREATE INDEX TblWzemQOpxList_jnum ON TblWzemQOpxList (jnum);

CREATE TABLE TblWzemQPrd1NEvent(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQPrd1NEvent OWNER TO epsi;
CREATE INDEX TblWzemQPrd1NEvent_jref ON TblWzemQPrd1NEvent (jref);
CREATE INDEX TblWzemQPrd1NEvent_jnum ON TblWzemQPrd1NEvent (jnum);

CREATE TABLE TblWzemQPrd1NJob(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQPrd1NJob OWNER TO epsi;
CREATE INDEX TblWzemQPrd1NJob_jref ON TblWzemQPrd1NJob (jref);
CREATE INDEX TblWzemQPrd1NJob_jnum ON TblWzemQPrd1NJob (jnum);

CREATE TABLE TblWzemQPrd1NNode(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQPrd1NNode OWNER TO epsi;
CREATE INDEX TblWzemQPrd1NNode_jref ON TblWzemQPrd1NNode (jref);
CREATE INDEX TblWzemQPrd1NNode_jnum ON TblWzemQPrd1NNode (jnum);

CREATE TABLE TblWzemQPrdList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Version VARCHAR(192),
	start INT,
	stop INT
);
ALTER TABLE TblWzemQPrdList OWNER TO epsi;
CREATE INDEX TblWzemQPrdList_jref ON TblWzemQPrdList (jref);
CREATE INDEX TblWzemQPrdList_jnum ON TblWzemQPrdList (jnum);

CREATE TABLE TblWzemQPreselect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQPreselect OWNER TO epsi;
CREATE INDEX TblWzemQPreselect_jref ON TblWzemQPreselect (jref);

CREATE TABLE TblWzemQPrsADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWzemQPrsADetail OWNER TO epsi;
CREATE INDEX TblWzemQPrsADetail_jref ON TblWzemQPrsADetail (jref);
CREATE INDEX TblWzemQPrsADetail_jnum ON TblWzemQPrsADetail (jnum);

CREATE TABLE TblWzemQPrsList(
	qref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemQPrsList OWNER TO epsi;
CREATE INDEX TblWzemQPrsList_jref ON TblWzemQPrsList (jref);
CREATE INDEX TblWzemQPrsList_jnum ON TblWzemQPrsList (jnum);

CREATE TABLE TblWzemQPstList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refWzemMJob BIGINT,
	srefIxVPreset VARCHAR(192),
	x1Startu DOUBLE PRECISION,
	x1Stopu DOUBLE PRECISION
);
ALTER TABLE TblWzemQPstList OWNER TO epsi;
CREATE INDEX TblWzemQPstList_jref ON TblWzemQPstList (jref);
CREATE INDEX TblWzemQPstList_jnum ON TblWzemQPstList (jnum);

CREATE TABLE TblWzemQSelect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
ALTER TABLE TblWzemQSelect OWNER TO epsi;
CREATE INDEX TblWzemQSelect_jref ON TblWzemQSelect (jref);
CREATE INDEX TblWzemQSelect_ix ON TblWzemQSelect (ix);

CREATE TABLE TblWzemQUsgAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
ALTER TABLE TblWzemQUsgAAccess OWNER TO epsi;
CREATE INDEX TblWzemQUsgAAccess_jref ON TblWzemQUsgAAccess (jref);
CREATE INDEX TblWzemQUsgAAccess_jnum ON TblWzemQUsgAAccess (jnum);

CREATE TABLE TblWzemQUsgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblWzemQUsgList OWNER TO epsi;
CREATE INDEX TblWzemQUsgList_jref ON TblWzemQUsgList (jref);
CREATE INDEX TblWzemQUsgList_jnum ON TblWzemQUsgList (jnum);

CREATE TABLE TblWzemQUsgMNUser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWzemVUserlevel INT
);
ALTER TABLE TblWzemQUsgMNUser OWNER TO epsi;
CREATE INDEX TblWzemQUsgMNUser_jref ON TblWzemQUsgMNUser (jref);
CREATE INDEX TblWzemQUsgMNUser_jnum ON TblWzemQUsgMNUser (jnum);

CREATE TABLE TblWzemQUsr1NSession(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWzemQUsr1NSession OWNER TO epsi;
CREATE INDEX TblWzemQUsr1NSession_jref ON TblWzemQUsr1NSession (jref);
CREATE INDEX TblWzemQUsr1NSession_jnum ON TblWzemQUsr1NSession (jnum);

CREATE TABLE TblWzemQUsrAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWzemVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT
);
ALTER TABLE TblWzemQUsrAAccess OWNER TO epsi;
CREATE INDEX TblWzemQUsrAAccess_jref ON TblWzemQUsrAAccess (jref);
CREATE INDEX TblWzemQUsrAAccess_jnum ON TblWzemQUsrAAccess (jnum);

CREATE TABLE TblWzemQUsrList(
	qref BIGSERIAL PRIMARY KEY,
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
ALTER TABLE TblWzemQUsrList OWNER TO epsi;
CREATE INDEX TblWzemQUsrList_jref ON TblWzemQUsrList (jref);
CREATE INDEX TblWzemQUsrList_jnum ON TblWzemQUsrList (jnum);

CREATE TABLE TblWzemQUsrMNUsergroup(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWzemVUserlevel INT
);
ALTER TABLE TblWzemQUsrMNUsergroup OWNER TO epsi;
CREATE INDEX TblWzemQUsrMNUsergroup_jref ON TblWzemQUsrMNUsergroup (jref);
CREATE INDEX TblWzemQUsrMNUsergroup_jnum ON TblWzemQUsrMNUsergroup (jnum);

