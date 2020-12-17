-- file CreateDbsWzemMy.sql
-- MySQL / MariaDB database create script
-- copyright: (C) 2016-2020 MPSI Technologies GmbH
-- author: Alexander Wirthmueller (auto-generation)
-- date created: 1 Dec 2020
-- IP header --- ABOVE

DROP DATABASE IF EXISTS DbsWzem;
CREATE DATABASE DbsWzem;
USE DbsWzem;

CREATE USER IF NOT EXISTS 'mpsitech'@'%' IDENTIFIED BY 'asdf1234';
GRANT ALL PRIVILEGES ON DbsWzem.* TO 'mpsitech'@'%';

CREATE USER IF NOT EXISTS 'mpsitech'@'localhost' IDENTIFIED BY 'asdf1234';
GRANT ALL PRIVILEGES ON DbsWzem.* TO 'mpsitech'@'localhost';

CREATE TABLE TblWzemAccRMUserUniversal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUser BIGINT UNSIGNED,
	unvIxWzemVMaintable INT UNSIGNED,
	unvUref BIGINT UNSIGNED,
	ixWzemVRecaccess INT UNSIGNED,
	INDEX (refWzemMUser),
	INDEX (unvIxWzemVMaintable),
	INDEX (unvUref)
) ENGINE = MYISAM;

CREATE TABLE TblWzemAMPersonDetail(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMPerson BIGINT UNSIGNED,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192),
	INDEX (refWzemMPerson)
) ENGINE = MYISAM;

CREATE TABLE TblWzemAMUserAccess(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUser BIGINT UNSIGNED,
	x1IxWzemVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT UNSIGNED,
	INDEX (refWzemMUser),
	INDEX (x1IxWzemVFeatgroup),
	INDEX (x2FeaSrefUix)
) ENGINE = MYISAM;

CREATE TABLE TblWzemAMUsergroupAccess(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUsergroup BIGINT UNSIGNED,
	x1IxWzemVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT UNSIGNED,
	INDEX (refWzemMUsergroup),
	INDEX (x1IxWzemVFeatgroup),
	INDEX (x2FeaSrefUix)
) ENGINE = MYISAM;

CREATE TABLE TblWzemAVControlPar(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	ixWzemVControl INT UNSIGNED,
	x1RefWzemMUser BIGINT UNSIGNED,
	x2IxWzemVLocale INT UNSIGNED,
	Par VARCHAR(192),
	Val VARCHAR(192),
	INDEX (ixWzemVControl),
	INDEX (x1RefWzemMUser),
	INDEX (x2IxWzemVLocale),
	INDEX (Par)
) ENGINE = MYISAM;

CREATE TABLE TblWzemAVKeylistKey(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	klsIxWzemVKeylist INT UNSIGNED,
	klsNum INT UNSIGNED,
	x1IxWzemVMaintable INT UNSIGNED,
	x1Uref BIGINT UNSIGNED,
	Fixed TINYINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT UNSIGNED,
	Title VARCHAR(192),
	Comment TEXT,
	INDEX (klsIxWzemVKeylist),
	INDEX (klsNum),
	INDEX (x1IxWzemVMaintable),
	INDEX (x1Uref),
	INDEX (sref)
) ENGINE = MYISAM;

CREATE TABLE TblWzemAVValuelistVal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	vlsIxWzemVValuelist INT UNSIGNED,
	vlsNum INT UNSIGNED,
	x1IxWzemVLocale INT UNSIGNED,
	Val VARCHAR(192),
	INDEX (vlsIxWzemVValuelist),
	INDEX (vlsNum),
	INDEX (x1IxWzemVLocale)
) ENGINE = MYISAM;

CREATE TABLE TblWzemCEvent(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY
) ENGINE = MYISAM;

CREATE TABLE TblWzemHistRMUserUniversal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUser BIGINT UNSIGNED,
	unvIxWzemVMaintable INT UNSIGNED,
	unvUref BIGINT UNSIGNED,
	ixWzemVCard INT UNSIGNED,
	ixWzemVPreset INT UNSIGNED,
	preIxWzemVMaintable INT UNSIGNED,
	preUref BIGINT UNSIGNED,
	start INT UNSIGNED,
	INDEX (refWzemMUser),
	INDEX (unvIxWzemVMaintable),
	INDEX (unvUref),
	INDEX (ixWzemVCard),
	INDEX (ixWzemVPreset),
	INDEX (preIxWzemVMaintable),
	INDEX (preUref)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJAVKeylistKey(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemAVKeylistKey BIGINT UNSIGNED,
	x1IxWzemVLocale INT UNSIGNED,
	Title VARCHAR(192),
	Comment TEXT,
	INDEX (refWzemAVKeylistKey),
	INDEX (x1IxWzemVLocale)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMCallArgRet(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMCall BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	argRet VARCHAR(192),
	INDEX (refWzemMCall),
	INDEX (x1Startu),
	INDEX (x1Stopu)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMClstn(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMClstn BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	argMask VARCHAR(192),
	ixVJactype INT UNSIGNED,
	INDEX (refWzemMClstn),
	INDEX (x1Startu),
	INDEX (x1Stopu)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMJobDcol(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMJob BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	Dcol TINYINT,
	INDEX (refWzemMJob),
	INDEX (x1Startu),
	INDEX (x1Stopu)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMJobStmgr(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMJob BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	Stmgr TINYINT,
	INDEX (refWzemMJob),
	INDEX (x1Startu),
	INDEX (x1Stopu)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMPersonLastname(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMPerson BIGINT UNSIGNED,
	x1Startd INT UNSIGNED,
	Lastname VARCHAR(50),
	INDEX (refWzemMPerson),
	INDEX (x1Startd),
	INDEX (Lastname)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMPresetArg(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMPreset BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	arg VARCHAR(192),
	INDEX (refWzemMPreset),
	INDEX (x1Startu),
	INDEX (x1Stopu)
) ENGINE = MYISAM;

CREATE TABLE TblWzemJMUserState(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUser BIGINT UNSIGNED,
	x1Start INT UNSIGNED,
	ixVState INT UNSIGNED,
	INDEX (refWzemMUser),
	INDEX (x1Start)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMCall(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	refWzemMJob BIGINT UNSIGNED,
	srefIxVCall VARCHAR(192),
	argInv VARCHAR(192),
	argRet VARCHAR(192),
	INDEX (x1Startu),
	INDEX (x1Stopu),
	INDEX (refWzemMJob)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMClstn(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	refWzemMJob BIGINT UNSIGNED,
	srefIxVCall VARCHAR(192),
	ixVTarget INT UNSIGNED,
	ixVJobmask INT UNSIGNED,
	tjbRefWzemMJob BIGINT UNSIGNED,
	ixVArgmask INT UNSIGNED,
	arg VARCHAR(192),
	srefIxVSge VARCHAR(192),
	ixVJactype INT UNSIGNED,
	INDEX (x1Startu),
	INDEX (x1Stopu),
	INDEX (refWzemMJob)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMDpch(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMEvent BIGINT UNSIGNED,
	srefIxVDpch VARCHAR(192),
	srefsMask VARCHAR(192),
	Content TEXT,
	INDEX (refWzemMEvent)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMEvent(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	ixVBasetype INT UNSIGNED,
	refWzemCEvent BIGINT UNSIGNED,
	refWzemMPeriod BIGINT UNSIGNED,
	refWzemMDpch BIGINT UNSIGNED,
	startu DOUBLE,
	refWzemMCall BIGINT UNSIGNED,
	refWzemMClstn BIGINT UNSIGNED,
	refWzemMJob BIGINT UNSIGNED,
	refWzemMNode BIGINT UNSIGNED,
	refWzemMOp BIGINT UNSIGNED,
	refWzemMPreset BIGINT UNSIGNED,
	Cmd VARCHAR(192),
	Filename TEXT,
	srefIxVFeatgroup VARCHAR(192),
	srefIxVMethod VARCHAR(192),
	xsref VARCHAR(192),
	INDEX (ixVBasetype),
	INDEX (refWzemCEvent),
	INDEX (refWzemMPeriod),
	INDEX (refWzemMDpch),
	INDEX (startu)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMJob(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	refWzemMPeriod BIGINT UNSIGNED,
	supRefWzemMJob BIGINT UNSIGNED,
	srefIxVJob VARCHAR(192),
	xjref BIGINT UNSIGNED,
	Clisrv TINYINT,
	srvNotCli TINYINT,
	Dcol TINYINT,
	Stmgr TINYINT,
	INDEX (x1Startu),
	INDEX (x1Stopu),
	INDEX (refWzemMPeriod),
	INDEX (supRefWzemMJob)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMNode(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	refWzemMPeriod BIGINT UNSIGNED,
	xnref BIGINT UNSIGNED,
	Ip VARCHAR(30),
	Port SMALLINT UNSIGNED,
	Opprcn TINYINT UNSIGNED,
	INDEX (x1Startu),
	INDEX (x1Stopu),
	INDEX (refWzemMPeriod)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMOp(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	refWzemMJob BIGINT UNSIGNED,
	xoref BIGINT UNSIGNED,
	INDEX (x1Startu),
	INDEX (x1Stopu),
	INDEX (refWzemMJob)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMPeriod(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	Version VARCHAR(192),
	start INT UNSIGNED,
	stop INT UNSIGNED,
	INDEX (grp),
	INDEX (own),
	INDEX (start)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMPerson(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	ixWDerivate INT UNSIGNED,
	ixVSex INT UNSIGNED,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT UNSIGNED,
	Lastname VARCHAR(50),
	telRefADetail BIGINT UNSIGNED,
	telVal VARCHAR(192),
	emlRefADetail BIGINT UNSIGNED,
	emlVal VARCHAR(192),
	Salutation VARCHAR(100),
	INDEX (grp),
	INDEX (own),
	INDEX (ixWDerivate),
	INDEX (Lastname)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMPreset(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	refWzemMJob BIGINT UNSIGNED,
	srefIxVPreset VARCHAR(192),
	arg VARCHAR(192),
	INDEX (x1Startu),
	INDEX (x1Stopu),
	INDEX (refWzemMJob)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMSession(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUser BIGINT UNSIGNED,
	start INT UNSIGNED,
	stop INT UNSIGNED,
	Ip VARCHAR(30),
	INDEX (refWzemMUser),
	INDEX (start)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMUser(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refRUsergroup BIGINT UNSIGNED,
	refWzemMUsergroup BIGINT UNSIGNED,
	refWzemMPerson BIGINT UNSIGNED,
	sref VARCHAR(50),
	refJState BIGINT UNSIGNED,
	ixVState INT UNSIGNED,
	ixWzemVLocale INT UNSIGNED,
	ixWzemVUserlevel INT UNSIGNED,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT,
	INDEX (grp),
	INDEX (own),
	INDEX (refWzemMUsergroup),
	INDEX (refWzemMPerson),
	INDEX (sref),
	INDEX (refJState),
	INDEX (ixVState)
) ENGINE = MYISAM;

CREATE TABLE TblWzemMUsergroup(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	sref VARCHAR(50),
	Comment TEXT,
	INDEX (grp),
	INDEX (own),
	INDEX (sref)
) ENGINE = MYISAM;

CREATE TABLE TblWzemRMUsergroupUniversal(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUsergroup BIGINT UNSIGNED,
	unvIxWzemVMaintable INT UNSIGNED,
	unvUref BIGINT UNSIGNED,
	ixWzemVRecaccess INT UNSIGNED,
	INDEX (refWzemMUsergroup),
	INDEX (unvIxWzemVMaintable),
	INDEX (unvUref)
) ENGINE = MYISAM;

CREATE TABLE TblWzemRMUserMUsergroup(
	ref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	refWzemMUser BIGINT UNSIGNED,
	refWzemMUsergroup BIGINT UNSIGNED,
	ixWzemVUserlevel INT UNSIGNED,
	INDEX (refWzemMUser),
	INDEX (refWzemMUsergroup)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQCalList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refWzemMJob BIGINT UNSIGNED,
	srefIxVCall VARCHAR(192),
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQClnList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refWzemMJob BIGINT UNSIGNED,
	srefIxVCall VARCHAR(192),
	srefIxVSge VARCHAR(192),
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQEvtList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	ixVBasetype INT UNSIGNED,
	refWzemMPeriod BIGINT UNSIGNED,
	startu DOUBLE,
	refWzemMDpch BIGINT UNSIGNED,
	Cmd VARCHAR(192),
	srefIxVFeatgroup VARCHAR(192),
	srefIxVMethod VARCHAR(192),
	xsref VARCHAR(192),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQJob1NCall(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQJob1NClstn(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQJob1NOp(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQJob1NPreset(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQJobList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refWzemMPeriod BIGINT UNSIGNED,
	srefIxVJob VARCHAR(192),
	xjref BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	supRefWzemMJob BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQJobSup1NJob(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQNdeList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refWzemMPeriod BIGINT UNSIGNED,
	xnref BIGINT UNSIGNED,
	Ip VARCHAR(30),
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	Port SMALLINT UNSIGNED,
	Opprcn TINYINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQOpxList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refWzemMJob BIGINT UNSIGNED,
	xoref BIGINT UNSIGNED,
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPrd1NEvent(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPrd1NJob(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPrd1NNode(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPrdList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	Version VARCHAR(192),
	start INT UNSIGNED,
	stop INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPreselect(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPrsADetail(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPrsList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	ixVSex INT UNSIGNED,
	telVal VARCHAR(192),
	emlVal VARCHAR(192),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQPstList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	refWzemMJob BIGINT UNSIGNED,
	srefIxVPreset VARCHAR(192),
	x1Startu DOUBLE,
	x1Stopu DOUBLE,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQSelect(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ix INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (ix)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsgAAccess(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1IxWzemVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsgList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	sref VARCHAR(50),
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsgMNUser(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	ixWzemVUserlevel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsr1NSession(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsrAAccess(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	x1IxWzemVFeatgroup INT UNSIGNED,
	x2FeaSrefUix VARCHAR(50),
	ixWzemWAccess INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsrList(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	ref BIGINT UNSIGNED,
	grp BIGINT UNSIGNED,
	own BIGINT UNSIGNED,
	refWzemMPerson BIGINT UNSIGNED,
	sref VARCHAR(50),
	refWzemMUsergroup BIGINT UNSIGNED,
	ixVState INT UNSIGNED,
	ixWzemVLocale INT UNSIGNED,
	ixWzemVUserlevel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

CREATE TABLE TblWzemQUsrMNUsergroup(
	qref BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	jref BIGINT UNSIGNED,
	jnum INT UNSIGNED,
	mref BIGINT UNSIGNED,
	ref BIGINT UNSIGNED,
	ixWzemVUserlevel INT UNSIGNED,
	INDEX (jref),
	INDEX (jnum)
) ENGINE = MYISAM;

