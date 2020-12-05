/**
	* \file DbsWzem.h
	* C++ wrapper for database DbsWzem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef DBSWZEM_H
#define DBSWZEM_H

#define WZEM_VERSION "1.0.0"
#define WZEM_VERSION_MAJOR 1
#define WZEM_VERSION_MINOR 0
#define WZEM_VERSION_SUB 0

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

#include "WzemAccRMUserUniversal.h"
#include "WzemAMPersonDetail.h"
#include "WzemAMUserAccess.h"
#include "WzemAMUsergroupAccess.h"
#include "WzemAVControlPar.h"
#include "WzemAVKeylistKey.h"
#include "WzemAVValuelistVal.h"
#include "WzemCEvent.h"
#include "WzemHistRMUserUniversal.h"
#include "WzemJAVKeylistKey.h"
#include "WzemJMCallArgRet.h"
#include "WzemJMClstn.h"
#include "WzemJMJobDcol.h"
#include "WzemJMJobStmgr.h"
#include "WzemJMPersonLastname.h"
#include "WzemJMPresetArg.h"
#include "WzemJMUserState.h"
#include "WzemMCall.h"
#include "WzemMClstn.h"
#include "WzemMDpch.h"
#include "WzemMEvent.h"
#include "WzemMJob.h"
#include "WzemMNode.h"
#include "WzemMOp.h"
#include "WzemMPeriod.h"
#include "WzemMPerson.h"
#include "WzemMPreset.h"
#include "WzemMSession.h"
#include "WzemMUser.h"
#include "WzemMUsergroup.h"
#include "WzemRMUsergroupUniversal.h"
#include "WzemRMUserMUsergroup.h"

#include "WzemQCalList.h"
#include "WzemQClnList.h"
#include "WzemQEvtList.h"
#include "WzemQJob1NCall.h"
#include "WzemQJob1NClstn.h"
#include "WzemQJob1NOp.h"
#include "WzemQJob1NPreset.h"
#include "WzemQJobList.h"
#include "WzemQJobSup1NJob.h"
#include "WzemQNdeList.h"
#include "WzemQOpxList.h"
#include "WzemQPrd1NEvent.h"
#include "WzemQPrd1NJob.h"
#include "WzemQPrd1NNode.h"
#include "WzemQPrdList.h"
#include "WzemQPreselect.h"
#include "WzemQPrsADetail.h"
#include "WzemQPrsList.h"
#include "WzemQPstList.h"
#include "WzemQSelect.h"
#include "WzemQUsgAAccess.h"
#include "WzemQUsgList.h"
#include "WzemQUsgMNUser.h"
#include "WzemQUsr1NSession.h"
#include "WzemQUsrAAccess.h"
#include "WzemQUsrList.h"
#include "WzemQUsrMNUsergroup.h"

#define VecWzemVCard DbsWzem::VecVCard
#define VecWzemVControl DbsWzem::VecVControl
#define VecWzemVFeatgroup DbsWzem::VecVFeatgroup
#define VecWzemVKeylist DbsWzem::VecVKeylist
#define VecWzemVLat DbsWzem::VecVLat
#define VecWzemVLocale DbsWzem::VecVLocale
#define VecWzemVLop DbsWzem::VecVLop
#define VecWzemVMaintable DbsWzem::VecVMaintable
#define VecWzemVOolop DbsWzem::VecVOolop
#define VecWzemVPreset DbsWzem::VecVPreset
#define VecWzemVRecaccess DbsWzem::VecVRecaccess
#define VecWzemVUserlevel DbsWzem::VecVUserlevel
#define VecWzemVValuelist DbsWzem::VecVValuelist
#define VecWzemWAccess DbsWzem::VecWAccess

/**
	* DbsWzem
	*/
class DbsWzem {

public:
	/**
		* VecVCard (full: VecWzemVCard)
		*/
	class VecVCard {

	public:
		static const Sbecore::uint CRDWZEMUSG = 1;
		static const Sbecore::uint CRDWZEMUSR = 2;
		static const Sbecore::uint CRDWZEMPRS = 3;
		static const Sbecore::uint CRDWZEMNAV = 4;
		static const Sbecore::uint CRDWZEMPRD = 5;
		static const Sbecore::uint CRDWZEMEVT = 6;
		static const Sbecore::uint CRDWZEMJOB = 7;
		static const Sbecore::uint CRDWZEMCAL = 8;
		static const Sbecore::uint CRDWZEMCLN = 9;
		static const Sbecore::uint CRDWZEMOPX = 10;
		static const Sbecore::uint CRDWZEMPST = 11;
		static const Sbecore::uint CRDWZEMNDE = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVControl (full: VecWzemVControl)
		*/
	class VecVControl {

	public:
		static const Sbecore::uint PNLWZEMUSGLIST_TCOGRP = 1;
		static const Sbecore::uint PNLWZEMUSGLIST_TCOOWN = 2;
		static const Sbecore::uint PNLWZEMUSGLIST_TCOSRF = 3;
		static const Sbecore::uint PNLWZEMUSGAACCESS_TCOFEG = 4;
		static const Sbecore::uint PNLWZEMUSGAACCESS_TCOFEA = 5;
		static const Sbecore::uint PNLWZEMUSGAACCESS_TCOACC = 6;
		static const Sbecore::uint PNLWZEMUSGMNUSER_TCOMREF = 7;
		static const Sbecore::uint PNLWZEMUSGMNUSER_TCOULV = 8;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOGRP = 9;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOOWN = 10;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOPRS = 11;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOSRF = 12;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOUSG = 13;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOSTE = 14;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOLCL = 15;
		static const Sbecore::uint PNLWZEMUSRLIST_TCOULV = 16;
		static const Sbecore::uint PNLWZEMUSRAACCESS_TCOFEG = 17;
		static const Sbecore::uint PNLWZEMUSRAACCESS_TCOFEA = 18;
		static const Sbecore::uint PNLWZEMUSRAACCESS_TCOACC = 19;
		static const Sbecore::uint PNLWZEMUSR1NSESSION_TCOREF = 20;
		static const Sbecore::uint PNLWZEMUSRMNUSERGROUP_TCOMREF = 21;
		static const Sbecore::uint PNLWZEMUSRMNUSERGROUP_TCOULV = 22;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOGRP = 23;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOOWN = 24;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOTIT = 25;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOFNM = 26;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOLNM = 27;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOSEX = 28;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOTEL = 29;
		static const Sbecore::uint PNLWZEMPRSLIST_TCOEML = 30;
		static const Sbecore::uint PNLWZEMPRSADETAIL_TCOTYP = 31;
		static const Sbecore::uint PNLWZEMPRSADETAIL_TCOVAL = 32;
		static const Sbecore::uint PNLWZEMPRDLIST_TCOGRP = 33;
		static const Sbecore::uint PNLWZEMPRDLIST_TCOOWN = 34;
		static const Sbecore::uint PNLWZEMPRDLIST_TCOVER = 35;
		static const Sbecore::uint PNLWZEMPRDLIST_TCOSTA = 36;
		static const Sbecore::uint PNLWZEMPRDLIST_TCOSTO = 37;
		static const Sbecore::uint PNLWZEMPRD1NEVENT_TCOREF = 38;
		static const Sbecore::uint PNLWZEMPRD1NNODE_TCOREF = 39;
		static const Sbecore::uint PNLWZEMPRD1NJOB_TCOREF = 40;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOTYP = 41;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOPRD = 42;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOSTA = 43;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOCMD = 44;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOFEG = 45;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOMTD = 46;
		static const Sbecore::uint PNLWZEMEVTLIST_TCOXSR = 47;
		static const Sbecore::uint PNLWZEMJOBLIST_TCOPRD = 48;
		static const Sbecore::uint PNLWZEMJOBLIST_TCOJOB = 49;
		static const Sbecore::uint PNLWZEMJOBLIST_TCOXJR = 50;
		static const Sbecore::uint PNLWZEMJOBLIST_TCOSTA = 51;
		static const Sbecore::uint PNLWZEMJOBLIST_TCOSTO = 52;
		static const Sbecore::uint PNLWZEMJOBLIST_TCOSUP = 53;
		static const Sbecore::uint PNLWZEMJOB1NCALL_TCOREF = 54;
		static const Sbecore::uint PNLWZEMJOB1NOP_TCOREF = 55;
		static const Sbecore::uint PNLWZEMJOB1NCLSTN_TCOREF = 56;
		static const Sbecore::uint PNLWZEMJOB1NPRESET_TCOREF = 57;
		static const Sbecore::uint PNLWZEMJOBSUP1NJOB_TCOREF = 58;
		static const Sbecore::uint PNLWZEMCALLIST_TCOJOB = 59;
		static const Sbecore::uint PNLWZEMCALLIST_TCOCAL = 60;
		static const Sbecore::uint PNLWZEMCALLIST_TCOSTA = 61;
		static const Sbecore::uint PNLWZEMCALLIST_TCOSTO = 62;
		static const Sbecore::uint PNLWZEMCLNLIST_TCOJOB = 63;
		static const Sbecore::uint PNLWZEMCLNLIST_TCOCAL = 64;
		static const Sbecore::uint PNLWZEMCLNLIST_TCOSGE = 65;
		static const Sbecore::uint PNLWZEMCLNLIST_TCOSTA = 66;
		static const Sbecore::uint PNLWZEMCLNLIST_TCOSTO = 67;
		static const Sbecore::uint PNLWZEMOPXLIST_TCOJOB = 68;
		static const Sbecore::uint PNLWZEMOPXLIST_TCOXOR = 69;
		static const Sbecore::uint PNLWZEMOPXLIST_TCOSTA = 70;
		static const Sbecore::uint PNLWZEMOPXLIST_TCOSTO = 71;
		static const Sbecore::uint PNLWZEMPSTLIST_TCOJOB = 72;
		static const Sbecore::uint PNLWZEMPSTLIST_TCOPST = 73;
		static const Sbecore::uint PNLWZEMPSTLIST_TCOSTA = 74;
		static const Sbecore::uint PNLWZEMPSTLIST_TCOSTO = 75;
		static const Sbecore::uint PNLWZEMNDELIST_TCOPRD = 76;
		static const Sbecore::uint PNLWZEMNDELIST_TCOXNR = 77;
		static const Sbecore::uint PNLWZEMNDELIST_TCOIP = 78;
		static const Sbecore::uint PNLWZEMNDELIST_TCOSTA = 79;
		static const Sbecore::uint PNLWZEMNDELIST_TCOSTO = 80;
		static const Sbecore::uint PNLWZEMNDELIST_TCOPRT = 81;
		static const Sbecore::uint PNLWZEMNDELIST_TCOORN = 82;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVFeatgroup (full: VecWzemVFeatgroup)
		*/
	class VecVFeatgroup {

	public:
		static const Sbecore::uint VECWZEMVCARD = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVKeylist (full: VecWzemVKeylist)
		*/
	class VecVKeylist {

	public:
		static const Sbecore::uint KLSTWZEMKAMPERSONDETAILTYPE = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);
	};

	/**
		* VecVLat (full: VecWzemVLat)
		*/
	class VecVLat {

	public:
		static const Sbecore::uint DLO = 1;
		static const Sbecore::uint INI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVLocale (full: VecWzemVLocale)
		*/
	class VecVLocale {

	public:
		static const Sbecore::uint ENUS = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVLop (full: VecWzemVLop)
		*/
	class VecVLop {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RMV = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMaintable (full: VecWzemVMaintable)
		*/
	class VecVMaintable {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBLWZEMMCALL = 2;
		static const Sbecore::uint TBLWZEMMCLSTN = 3;
		static const Sbecore::uint TBLWZEMMDPCH = 4;
		static const Sbecore::uint TBLWZEMMEVENT = 5;
		static const Sbecore::uint TBLWZEMMJOB = 6;
		static const Sbecore::uint TBLWZEMMNODE = 7;
		static const Sbecore::uint TBLWZEMMOP = 8;
		static const Sbecore::uint TBLWZEMMPERIOD = 9;
		static const Sbecore::uint TBLWZEMMPERSON = 10;
		static const Sbecore::uint TBLWZEMMPRESET = 11;
		static const Sbecore::uint TBLWZEMMSESSION = 12;
		static const Sbecore::uint TBLWZEMMUSER = 13;
		static const Sbecore::uint TBLWZEMMUSERGROUP = 14;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVOolop (full: VecWzemVOolop)
		*/
	class VecVOolop {

	public:
		static const Sbecore::uint INA = 1;
		static const Sbecore::uint INB = 2;
		static const Sbecore::uint RMV = 3;
		static const Sbecore::uint SWP = 4;
		static const Sbecore::uint TOA = 5;
		static const Sbecore::uint TOB = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVPreset (full: VecWzemVPreset)
		*/
	class VecVPreset {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PREWZEMADMIN = 2;
		static const Sbecore::uint PREWZEMCALLIST_JOB = 3;
		static const Sbecore::uint PREWZEMCALLIST_STA = 4;
		static const Sbecore::uint PREWZEMCALLIST_STO = 5;
		static const Sbecore::uint PREWZEMCLNLIST_JOB = 6;
		static const Sbecore::uint PREWZEMCLNLIST_STA = 7;
		static const Sbecore::uint PREWZEMCLNLIST_STO = 8;
		static const Sbecore::uint PREWZEMEVTLIST_PRD = 9;
		static const Sbecore::uint PREWZEMEVTLIST_STA = 10;
		static const Sbecore::uint PREWZEMEVTLIST_TYP = 11;
		static const Sbecore::uint PREWZEMGROUP = 12;
		static const Sbecore::uint PREWZEMIP = 13;
		static const Sbecore::uint PREWZEMIXCRDACCCAL = 14;
		static const Sbecore::uint PREWZEMIXCRDACCCLN = 15;
		static const Sbecore::uint PREWZEMIXCRDACCEVT = 16;
		static const Sbecore::uint PREWZEMIXCRDACCJOB = 17;
		static const Sbecore::uint PREWZEMIXCRDACCNDE = 18;
		static const Sbecore::uint PREWZEMIXCRDACCOPX = 19;
		static const Sbecore::uint PREWZEMIXCRDACCPRD = 20;
		static const Sbecore::uint PREWZEMIXCRDACCPRS = 21;
		static const Sbecore::uint PREWZEMIXCRDACCPST = 22;
		static const Sbecore::uint PREWZEMIXCRDACCUSG = 23;
		static const Sbecore::uint PREWZEMIXCRDACCUSR = 24;
		static const Sbecore::uint PREWZEMIXLCL = 25;
		static const Sbecore::uint PREWZEMIXORD = 26;
		static const Sbecore::uint PREWZEMIXPRE = 27;
		static const Sbecore::uint PREWZEMIXRECACC = 28;
		static const Sbecore::uint PREWZEMJOB1NCALL_X1 = 29;
		static const Sbecore::uint PREWZEMJOB1NCLSTN_X1 = 30;
		static const Sbecore::uint PREWZEMJOB1NOP_X1 = 31;
		static const Sbecore::uint PREWZEMJOB1NPRESET_X1 = 32;
		static const Sbecore::uint PREWZEMJOBLIST_PRD = 33;
		static const Sbecore::uint PREWZEMJOBLIST_STA = 34;
		static const Sbecore::uint PREWZEMJOBLIST_STO = 35;
		static const Sbecore::uint PREWZEMJOBLIST_SUP = 36;
		static const Sbecore::uint PREWZEMJOBSUP1NJOB_X1 = 37;
		static const Sbecore::uint PREWZEMJREFNOTIFY = 38;
		static const Sbecore::uint PREWZEMJREFSESS = 39;
		static const Sbecore::uint PREWZEMNDELIST_PRD = 40;
		static const Sbecore::uint PREWZEMNDELIST_STA = 41;
		static const Sbecore::uint PREWZEMNDELIST_STO = 42;
		static const Sbecore::uint PREWZEMNOADM = 43;
		static const Sbecore::uint PREWZEMOPXLIST_JOB = 44;
		static const Sbecore::uint PREWZEMOPXLIST_STA = 45;
		static const Sbecore::uint PREWZEMOPXLIST_STO = 46;
		static const Sbecore::uint PREWZEMOWNER = 47;
		static const Sbecore::uint PREWZEMPRD1NJOB_X1 = 48;
		static const Sbecore::uint PREWZEMPRD1NNODE_X1 = 49;
		static const Sbecore::uint PREWZEMPRDLIST_GRP = 50;
		static const Sbecore::uint PREWZEMPRDLIST_OWN = 51;
		static const Sbecore::uint PREWZEMPRDLIST_STA = 52;
		static const Sbecore::uint PREWZEMPRSADETAIL_X1 = 53;
		static const Sbecore::uint PREWZEMPRSLIST_GRP = 54;
		static const Sbecore::uint PREWZEMPRSLIST_LNM = 55;
		static const Sbecore::uint PREWZEMPRSLIST_OWN = 56;
		static const Sbecore::uint PREWZEMPSTLIST_JOB = 57;
		static const Sbecore::uint PREWZEMPSTLIST_STA = 58;
		static const Sbecore::uint PREWZEMPSTLIST_STO = 59;
		static const Sbecore::uint PREWZEMREFCAL = 60;
		static const Sbecore::uint PREWZEMREFCLN = 61;
		static const Sbecore::uint PREWZEMREFDCH = 62;
		static const Sbecore::uint PREWZEMREFEVT = 63;
		static const Sbecore::uint PREWZEMREFJOB = 64;
		static const Sbecore::uint PREWZEMREFNDE = 65;
		static const Sbecore::uint PREWZEMREFOPX = 66;
		static const Sbecore::uint PREWZEMREFPRD = 67;
		static const Sbecore::uint PREWZEMREFPRS = 68;
		static const Sbecore::uint PREWZEMREFPST = 69;
		static const Sbecore::uint PREWZEMREFSEL = 70;
		static const Sbecore::uint PREWZEMREFSES = 71;
		static const Sbecore::uint PREWZEMREFUSG = 72;
		static const Sbecore::uint PREWZEMREFUSR = 73;
		static const Sbecore::uint PREWZEMSESS = 74;
		static const Sbecore::uint PREWZEMSUSPSESS = 75;
		static const Sbecore::uint PREWZEMSYSDATE = 76;
		static const Sbecore::uint PREWZEMSYSSTAMP = 77;
		static const Sbecore::uint PREWZEMSYSTIME = 78;
		static const Sbecore::uint PREWZEMUSGAACCESS_X1 = 79;
		static const Sbecore::uint PREWZEMUSGAACCESS_X2 = 80;
		static const Sbecore::uint PREWZEMUSGLIST_GRP = 81;
		static const Sbecore::uint PREWZEMUSGLIST_OWN = 82;
		static const Sbecore::uint PREWZEMUSGLIST_SRF = 83;
		static const Sbecore::uint PREWZEMUSRAACCESS_X1 = 84;
		static const Sbecore::uint PREWZEMUSRAACCESS_X2 = 85;
		static const Sbecore::uint PREWZEMUSRLIST_GRP = 86;
		static const Sbecore::uint PREWZEMUSRLIST_OWN = 87;
		static const Sbecore::uint PREWZEMUSRLIST_PRS = 88;
		static const Sbecore::uint PREWZEMUSRLIST_SRF = 89;
		static const Sbecore::uint PREWZEMUSRLIST_STE = 90;
		static const Sbecore::uint PREWZEMUSRLIST_USG = 91;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);
	};

	/**
		* VecVRecaccess (full: VecWzemVRecaccess)
		*/
	class VecVRecaccess {

	public:
		static const Sbecore::uint FULL = 1;
		static const Sbecore::uint NONE = 2;
		static const Sbecore::uint VIEW = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVUserlevel (full: VecWzemVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const Sbecore::uint ADM = 1;
		static const Sbecore::uint GADM = 2;
		static const Sbecore::uint REG = 3;
		static const Sbecore::uint VTOR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVValuelist (full: VecWzemVValuelist)
		*/
	class VecVValuelist {

	public:
		static const Sbecore::uint VLSTWZEMUMPERSONTITLE = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);
	};

	/**
		* VecWAccess (full: VecWzemWAccess)
		*/
	class VecWAccess {

	public:
		static const Sbecore::uint EDIT = 1;
		static const Sbecore::uint EXEC = 2;
		static const Sbecore::uint VIEW = 4;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	DbsWzem();
	~DbsWzem();

	void init(const Sbecore::uint _ixDbsVDbstype, const std::string& _dbspath, const std::string& _dbsname, const std::string& _ip, const Sbecore::uint _port, const std::string& _username, const std::string& _password);
	void term();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void initMy();
	void termMy();
#endif
#if defined(SBECORE_PG)
	void initPg();
	void termPg();
#endif
#if defined(SBECORE_LITE)
	void initLite();
	void termLite();
#endif

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	int port;

	bool initdone;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	MYSQL* dbsMy;
#endif
#if defined(SBECORE_PG)
	PGconn* dbsPg;
#endif
#if defined(SBECORE_LITE)
	sqlite3* dbsLite;
#endif

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void beginMy();
	bool commitMy();
	void rollbackMy();
#endif
#if defined(SBECORE_PG)
	void beginPg();
	bool commitPg();
	void rollbackPg();
#endif
#if defined(SBECORE_LITE)
	void beginLite();
	bool commitLite();
	void rollbackLite();
#endif

	bool loadUintBySQL(const std::string& sqlstr, Sbecore::uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const std::string& sqlstr, std::string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const std::string& sqlstr, Sbecore::ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	Sbecore::ubigint loadRefsBySQL(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	bool loadUintBySQLMy(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLMy(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLMy(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLMy(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

#if defined(SBECORE_PG)
	bool loadUintBySQLPg(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLPg(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLPg(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLPg(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

#if defined(SBECORE_LITE)
	bool loadUintBySQLLite(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLLite(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLLite(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLLite(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

	void executeQuery(const std::string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const std::string& sqlstrmy, const std::string& sqlstrpg, const std::string& sqlstrlite);
	void executeFile(const std::string& fullpath);								//!< SQL file batch execution

public:

	void fillFeedFromKlst(const Sbecore::uint klsIxWzemVKeylist, const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeedFromKlstByMtbUref(const Sbecore::uint klsIxWzemVKeylist, const Sbecore::uint x1IxWzemVMaintable, const Sbecore::ubigint x1Uref, const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);

	std::string getKlstTitleBySref(const Sbecore::uint klsIxWzemVKeylist, const std::string& sref, const Sbecore::uint ixWzemVLocale = 0);
	std::string getKlstTitleByMtbUrefSref(const Sbecore::uint klsIxWzemVKeylist, const Sbecore::uint x1IxWzemVMaintable, const Sbecore::ubigint x1Uref, const std::string& sref, const Sbecore::uint ixWzemVLocale = 0);

	void fillFeedFromVlst(const Sbecore::uint vlsIxWzemVValuelist, const Sbecore::uint x1IxWzemVLocale, Sbecore::Xmlio::Feed& feed);

public:
	TblWzemAccRMUserUniversal* tblwzemaccrmuseruniversal;
	TblWzemAMPersonDetail* tblwzemampersondetail;
	TblWzemAMUserAccess* tblwzemamuseraccess;
	TblWzemAMUsergroupAccess* tblwzemamusergroupaccess;
	TblWzemAVControlPar* tblwzemavcontrolpar;
	TblWzemAVKeylistKey* tblwzemavkeylistkey;
	TblWzemAVValuelistVal* tblwzemavvaluelistval;
	TblWzemCEvent* tblwzemcevent;
	TblWzemHistRMUserUniversal* tblwzemhistrmuseruniversal;
	TblWzemJAVKeylistKey* tblwzemjavkeylistkey;
	TblWzemJMCallArgRet* tblwzemjmcallargret;
	TblWzemJMClstn* tblwzemjmclstn;
	TblWzemJMJobDcol* tblwzemjmjobdcol;
	TblWzemJMJobStmgr* tblwzemjmjobstmgr;
	TblWzemJMPersonLastname* tblwzemjmpersonlastname;
	TblWzemJMPresetArg* tblwzemjmpresetarg;
	TblWzemJMUserState* tblwzemjmuserstate;
	TblWzemMCall* tblwzemmcall;
	TblWzemMClstn* tblwzemmclstn;
	TblWzemMDpch* tblwzemmdpch;
	TblWzemMEvent* tblwzemmevent;
	TblWzemMJob* tblwzemmjob;
	TblWzemMNode* tblwzemmnode;
	TblWzemMOp* tblwzemmop;
	TblWzemMPeriod* tblwzemmperiod;
	TblWzemMPerson* tblwzemmperson;
	TblWzemMPreset* tblwzemmpreset;
	TblWzemMSession* tblwzemmsession;
	TblWzemMUser* tblwzemmuser;
	TblWzemMUsergroup* tblwzemmusergroup;
	TblWzemRMUsergroupUniversal* tblwzemrmusergroupuniversal;
	TblWzemRMUserMUsergroup* tblwzemrmusermusergroup;

	TblWzemQCalList* tblwzemqcallist;
	TblWzemQClnList* tblwzemqclnlist;
	TblWzemQEvtList* tblwzemqevtlist;
	TblWzemQJob1NCall* tblwzemqjob1ncall;
	TblWzemQJob1NClstn* tblwzemqjob1nclstn;
	TblWzemQJob1NOp* tblwzemqjob1nop;
	TblWzemQJob1NPreset* tblwzemqjob1npreset;
	TblWzemQJobList* tblwzemqjoblist;
	TblWzemQJobSup1NJob* tblwzemqjobsup1njob;
	TblWzemQNdeList* tblwzemqndelist;
	TblWzemQOpxList* tblwzemqopxlist;
	TblWzemQPrd1NEvent* tblwzemqprd1nevent;
	TblWzemQPrd1NJob* tblwzemqprd1njob;
	TblWzemQPrd1NNode* tblwzemqprd1nnode;
	TblWzemQPrdList* tblwzemqprdlist;
	TblWzemQPreselect* tblwzemqpreselect;
	TblWzemQPrsADetail* tblwzemqprsadetail;
	TblWzemQPrsList* tblwzemqprslist;
	TblWzemQPstList* tblwzemqpstlist;
	TblWzemQSelect* tblwzemqselect;
	TblWzemQUsgAAccess* tblwzemqusgaaccess;
	TblWzemQUsgList* tblwzemqusglist;
	TblWzemQUsgMNUser* tblwzemqusgmnuser;
	TblWzemQUsr1NSession* tblwzemqusr1nsession;
	TblWzemQUsrAAccess* tblwzemqusraaccess;
	TblWzemQUsrList* tblwzemqusrlist;
	TblWzemQUsrMNUsergroup* tblwzemqusrmnusergroup;
};
#endif

