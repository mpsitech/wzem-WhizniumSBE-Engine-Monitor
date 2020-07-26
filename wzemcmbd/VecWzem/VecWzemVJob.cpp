/**
	* \file VecWzemVJob.cpp
	* vector VecWzemVJob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "VecWzemVJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVJob
 ******************************************************************************/

uint VecWzemVJob::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdwzemcal") return CRDWZEMCAL;
	if (s == "crdwzemcln") return CRDWZEMCLN;
	if (s == "crdwzemevt") return CRDWZEMEVT;
	if (s == "crdwzemjob") return CRDWZEMJOB;
	if (s == "crdwzemnav") return CRDWZEMNAV;
	if (s == "crdwzemnde") return CRDWZEMNDE;
	if (s == "crdwzemopx") return CRDWZEMOPX;
	if (s == "crdwzemprd") return CRDWZEMPRD;
	if (s == "crdwzemprs") return CRDWZEMPRS;
	if (s == "crdwzempst") return CRDWZEMPST;
	if (s == "crdwzemusg") return CRDWZEMUSG;
	if (s == "crdwzemusr") return CRDWZEMUSR;
	if (s == "dlgwzemnavloaini") return DLGWZEMNAVLOAINI;
	if (s == "jobwzemiexini") return JOBWZEMIEXINI;
	if (s == "pnlwzemcaldetail") return PNLWZEMCALDETAIL;
	if (s == "pnlwzemcalheadbar") return PNLWZEMCALHEADBAR;
	if (s == "pnlwzemcallist") return PNLWZEMCALLIST;
	if (s == "pnlwzemcalrec") return PNLWZEMCALREC;
	if (s == "pnlwzemclndetail") return PNLWZEMCLNDETAIL;
	if (s == "pnlwzemclnheadbar") return PNLWZEMCLNHEADBAR;
	if (s == "pnlwzemclnlist") return PNLWZEMCLNLIST;
	if (s == "pnlwzemclnrec") return PNLWZEMCLNREC;
	if (s == "pnlwzemevtdetail") return PNLWZEMEVTDETAIL;
	if (s == "pnlwzemevtheadbar") return PNLWZEMEVTHEADBAR;
	if (s == "pnlwzemevtlist") return PNLWZEMEVTLIST;
	if (s == "pnlwzemevtrec") return PNLWZEMEVTREC;
	if (s == "pnlwzemjob1ncall") return PNLWZEMJOB1NCALL;
	if (s == "pnlwzemjob1nclstn") return PNLWZEMJOB1NCLSTN;
	if (s == "pnlwzemjob1nop") return PNLWZEMJOB1NOP;
	if (s == "pnlwzemjob1npreset") return PNLWZEMJOB1NPRESET;
	if (s == "pnlwzemjobdetail") return PNLWZEMJOBDETAIL;
	if (s == "pnlwzemjobheadbar") return PNLWZEMJOBHEADBAR;
	if (s == "pnlwzemjoblist") return PNLWZEMJOBLIST;
	if (s == "pnlwzemjobrec") return PNLWZEMJOBREC;
	if (s == "pnlwzemjobsup1njob") return PNLWZEMJOBSUP1NJOB;
	if (s == "pnlwzemnavadmin") return PNLWZEMNAVADMIN;
	if (s == "pnlwzemnavheadbar") return PNLWZEMNAVHEADBAR;
	if (s == "pnlwzemnavmon") return PNLWZEMNAVMON;
	if (s == "pnlwzemnavpre") return PNLWZEMNAVPRE;
	if (s == "pnlwzemndedetail") return PNLWZEMNDEDETAIL;
	if (s == "pnlwzemndeheadbar") return PNLWZEMNDEHEADBAR;
	if (s == "pnlwzemndelist") return PNLWZEMNDELIST;
	if (s == "pnlwzemnderec") return PNLWZEMNDEREC;
	if (s == "pnlwzemopxdetail") return PNLWZEMOPXDETAIL;
	if (s == "pnlwzemopxheadbar") return PNLWZEMOPXHEADBAR;
	if (s == "pnlwzemopxlist") return PNLWZEMOPXLIST;
	if (s == "pnlwzemopxrec") return PNLWZEMOPXREC;
	if (s == "pnlwzemprd1nevent") return PNLWZEMPRD1NEVENT;
	if (s == "pnlwzemprd1njob") return PNLWZEMPRD1NJOB;
	if (s == "pnlwzemprd1nnode") return PNLWZEMPRD1NNODE;
	if (s == "pnlwzemprddetail") return PNLWZEMPRDDETAIL;
	if (s == "pnlwzemprdheadbar") return PNLWZEMPRDHEADBAR;
	if (s == "pnlwzemprdlist") return PNLWZEMPRDLIST;
	if (s == "pnlwzemprdrec") return PNLWZEMPRDREC;
	if (s == "pnlwzemprsadetail") return PNLWZEMPRSADETAIL;
	if (s == "pnlwzemprsdetail") return PNLWZEMPRSDETAIL;
	if (s == "pnlwzemprsheadbar") return PNLWZEMPRSHEADBAR;
	if (s == "pnlwzemprslist") return PNLWZEMPRSLIST;
	if (s == "pnlwzemprsrec") return PNLWZEMPRSREC;
	if (s == "pnlwzempstdetail") return PNLWZEMPSTDETAIL;
	if (s == "pnlwzempstheadbar") return PNLWZEMPSTHEADBAR;
	if (s == "pnlwzempstlist") return PNLWZEMPSTLIST;
	if (s == "pnlwzempstrec") return PNLWZEMPSTREC;
	if (s == "pnlwzemusgaaccess") return PNLWZEMUSGAACCESS;
	if (s == "pnlwzemusgdetail") return PNLWZEMUSGDETAIL;
	if (s == "pnlwzemusgheadbar") return PNLWZEMUSGHEADBAR;
	if (s == "pnlwzemusglist") return PNLWZEMUSGLIST;
	if (s == "pnlwzemusgmnuser") return PNLWZEMUSGMNUSER;
	if (s == "pnlwzemusgrec") return PNLWZEMUSGREC;
	if (s == "pnlwzemusr1nsession") return PNLWZEMUSR1NSESSION;
	if (s == "pnlwzemusraaccess") return PNLWZEMUSRAACCESS;
	if (s == "pnlwzemusrdetail") return PNLWZEMUSRDETAIL;
	if (s == "pnlwzemusrheadbar") return PNLWZEMUSRHEADBAR;
	if (s == "pnlwzemusrlist") return PNLWZEMUSRLIST;
	if (s == "pnlwzemusrmnusergroup") return PNLWZEMUSRMNUSERGROUP;
	if (s == "pnlwzemusrrec") return PNLWZEMUSRREC;
	if (s == "qrywzemcallist") return QRYWZEMCALLIST;
	if (s == "qrywzemclnlist") return QRYWZEMCLNLIST;
	if (s == "qrywzemevtlist") return QRYWZEMEVTLIST;
	if (s == "qrywzemjob1ncall") return QRYWZEMJOB1NCALL;
	if (s == "qrywzemjob1nclstn") return QRYWZEMJOB1NCLSTN;
	if (s == "qrywzemjob1nop") return QRYWZEMJOB1NOP;
	if (s == "qrywzemjob1npreset") return QRYWZEMJOB1NPRESET;
	if (s == "qrywzemjoblist") return QRYWZEMJOBLIST;
	if (s == "qrywzemjobsup1njob") return QRYWZEMJOBSUP1NJOB;
	if (s == "qrywzemndelist") return QRYWZEMNDELIST;
	if (s == "qrywzemopxlist") return QRYWZEMOPXLIST;
	if (s == "qrywzemprd1nevent") return QRYWZEMPRD1NEVENT;
	if (s == "qrywzemprd1njob") return QRYWZEMPRD1NJOB;
	if (s == "qrywzemprd1nnode") return QRYWZEMPRD1NNODE;
	if (s == "qrywzemprdlist") return QRYWZEMPRDLIST;
	if (s == "qrywzemprsadetail") return QRYWZEMPRSADETAIL;
	if (s == "qrywzemprslist") return QRYWZEMPRSLIST;
	if (s == "qrywzempstlist") return QRYWZEMPSTLIST;
	if (s == "qrywzemusgaaccess") return QRYWZEMUSGAACCESS;
	if (s == "qrywzemusglist") return QRYWZEMUSGLIST;
	if (s == "qrywzemusgmnuser") return QRYWZEMUSGMNUSER;
	if (s == "qrywzemusr1nsession") return QRYWZEMUSR1NSESSION;
	if (s == "qrywzemusraaccess") return QRYWZEMUSRAACCESS;
	if (s == "qrywzemusrlist") return QRYWZEMUSRLIST;
	if (s == "qrywzemusrmnusergroup") return QRYWZEMUSRMNUSERGROUP;
	if (s == "rootwzem") return ROOTWZEM;
	if (s == "sesswzem") return SESSWZEM;

	return(0);
};

string VecWzemVJob::getSref(
			const uint ix
		) {
	if (ix == CRDWZEMCAL) return("CrdWzemCal");
	if (ix == CRDWZEMCLN) return("CrdWzemCln");
	if (ix == CRDWZEMEVT) return("CrdWzemEvt");
	if (ix == CRDWZEMJOB) return("CrdWzemJob");
	if (ix == CRDWZEMNAV) return("CrdWzemNav");
	if (ix == CRDWZEMNDE) return("CrdWzemNde");
	if (ix == CRDWZEMOPX) return("CrdWzemOpx");
	if (ix == CRDWZEMPRD) return("CrdWzemPrd");
	if (ix == CRDWZEMPRS) return("CrdWzemPrs");
	if (ix == CRDWZEMPST) return("CrdWzemPst");
	if (ix == CRDWZEMUSG) return("CrdWzemUsg");
	if (ix == CRDWZEMUSR) return("CrdWzemUsr");
	if (ix == DLGWZEMNAVLOAINI) return("DlgWzemNavLoaini");
	if (ix == JOBWZEMIEXINI) return("JobWzemIexIni");
	if (ix == PNLWZEMCALDETAIL) return("PnlWzemCalDetail");
	if (ix == PNLWZEMCALHEADBAR) return("PnlWzemCalHeadbar");
	if (ix == PNLWZEMCALLIST) return("PnlWzemCalList");
	if (ix == PNLWZEMCALREC) return("PnlWzemCalRec");
	if (ix == PNLWZEMCLNDETAIL) return("PnlWzemClnDetail");
	if (ix == PNLWZEMCLNHEADBAR) return("PnlWzemClnHeadbar");
	if (ix == PNLWZEMCLNLIST) return("PnlWzemClnList");
	if (ix == PNLWZEMCLNREC) return("PnlWzemClnRec");
	if (ix == PNLWZEMEVTDETAIL) return("PnlWzemEvtDetail");
	if (ix == PNLWZEMEVTHEADBAR) return("PnlWzemEvtHeadbar");
	if (ix == PNLWZEMEVTLIST) return("PnlWzemEvtList");
	if (ix == PNLWZEMEVTREC) return("PnlWzemEvtRec");
	if (ix == PNLWZEMJOB1NCALL) return("PnlWzemJob1NCall");
	if (ix == PNLWZEMJOB1NCLSTN) return("PnlWzemJob1NClstn");
	if (ix == PNLWZEMJOB1NOP) return("PnlWzemJob1NOp");
	if (ix == PNLWZEMJOB1NPRESET) return("PnlWzemJob1NPreset");
	if (ix == PNLWZEMJOBDETAIL) return("PnlWzemJobDetail");
	if (ix == PNLWZEMJOBHEADBAR) return("PnlWzemJobHeadbar");
	if (ix == PNLWZEMJOBLIST) return("PnlWzemJobList");
	if (ix == PNLWZEMJOBREC) return("PnlWzemJobRec");
	if (ix == PNLWZEMJOBSUP1NJOB) return("PnlWzemJobSup1NJob");
	if (ix == PNLWZEMNAVADMIN) return("PnlWzemNavAdmin");
	if (ix == PNLWZEMNAVHEADBAR) return("PnlWzemNavHeadbar");
	if (ix == PNLWZEMNAVMON) return("PnlWzemNavMon");
	if (ix == PNLWZEMNAVPRE) return("PnlWzemNavPre");
	if (ix == PNLWZEMNDEDETAIL) return("PnlWzemNdeDetail");
	if (ix == PNLWZEMNDEHEADBAR) return("PnlWzemNdeHeadbar");
	if (ix == PNLWZEMNDELIST) return("PnlWzemNdeList");
	if (ix == PNLWZEMNDEREC) return("PnlWzemNdeRec");
	if (ix == PNLWZEMOPXDETAIL) return("PnlWzemOpxDetail");
	if (ix == PNLWZEMOPXHEADBAR) return("PnlWzemOpxHeadbar");
	if (ix == PNLWZEMOPXLIST) return("PnlWzemOpxList");
	if (ix == PNLWZEMOPXREC) return("PnlWzemOpxRec");
	if (ix == PNLWZEMPRD1NEVENT) return("PnlWzemPrd1NEvent");
	if (ix == PNLWZEMPRD1NJOB) return("PnlWzemPrd1NJob");
	if (ix == PNLWZEMPRD1NNODE) return("PnlWzemPrd1NNode");
	if (ix == PNLWZEMPRDDETAIL) return("PnlWzemPrdDetail");
	if (ix == PNLWZEMPRDHEADBAR) return("PnlWzemPrdHeadbar");
	if (ix == PNLWZEMPRDLIST) return("PnlWzemPrdList");
	if (ix == PNLWZEMPRDREC) return("PnlWzemPrdRec");
	if (ix == PNLWZEMPRSADETAIL) return("PnlWzemPrsADetail");
	if (ix == PNLWZEMPRSDETAIL) return("PnlWzemPrsDetail");
	if (ix == PNLWZEMPRSHEADBAR) return("PnlWzemPrsHeadbar");
	if (ix == PNLWZEMPRSLIST) return("PnlWzemPrsList");
	if (ix == PNLWZEMPRSREC) return("PnlWzemPrsRec");
	if (ix == PNLWZEMPSTDETAIL) return("PnlWzemPstDetail");
	if (ix == PNLWZEMPSTHEADBAR) return("PnlWzemPstHeadbar");
	if (ix == PNLWZEMPSTLIST) return("PnlWzemPstList");
	if (ix == PNLWZEMPSTREC) return("PnlWzemPstRec");
	if (ix == PNLWZEMUSGAACCESS) return("PnlWzemUsgAAccess");
	if (ix == PNLWZEMUSGDETAIL) return("PnlWzemUsgDetail");
	if (ix == PNLWZEMUSGHEADBAR) return("PnlWzemUsgHeadbar");
	if (ix == PNLWZEMUSGLIST) return("PnlWzemUsgList");
	if (ix == PNLWZEMUSGMNUSER) return("PnlWzemUsgMNUser");
	if (ix == PNLWZEMUSGREC) return("PnlWzemUsgRec");
	if (ix == PNLWZEMUSR1NSESSION) return("PnlWzemUsr1NSession");
	if (ix == PNLWZEMUSRAACCESS) return("PnlWzemUsrAAccess");
	if (ix == PNLWZEMUSRDETAIL) return("PnlWzemUsrDetail");
	if (ix == PNLWZEMUSRHEADBAR) return("PnlWzemUsrHeadbar");
	if (ix == PNLWZEMUSRLIST) return("PnlWzemUsrList");
	if (ix == PNLWZEMUSRMNUSERGROUP) return("PnlWzemUsrMNUsergroup");
	if (ix == PNLWZEMUSRREC) return("PnlWzemUsrRec");
	if (ix == QRYWZEMCALLIST) return("QryWzemCalList");
	if (ix == QRYWZEMCLNLIST) return("QryWzemClnList");
	if (ix == QRYWZEMEVTLIST) return("QryWzemEvtList");
	if (ix == QRYWZEMJOB1NCALL) return("QryWzemJob1NCall");
	if (ix == QRYWZEMJOB1NCLSTN) return("QryWzemJob1NClstn");
	if (ix == QRYWZEMJOB1NOP) return("QryWzemJob1NOp");
	if (ix == QRYWZEMJOB1NPRESET) return("QryWzemJob1NPreset");
	if (ix == QRYWZEMJOBLIST) return("QryWzemJobList");
	if (ix == QRYWZEMJOBSUP1NJOB) return("QryWzemJobSup1NJob");
	if (ix == QRYWZEMNDELIST) return("QryWzemNdeList");
	if (ix == QRYWZEMOPXLIST) return("QryWzemOpxList");
	if (ix == QRYWZEMPRD1NEVENT) return("QryWzemPrd1NEvent");
	if (ix == QRYWZEMPRD1NJOB) return("QryWzemPrd1NJob");
	if (ix == QRYWZEMPRD1NNODE) return("QryWzemPrd1NNode");
	if (ix == QRYWZEMPRDLIST) return("QryWzemPrdList");
	if (ix == QRYWZEMPRSADETAIL) return("QryWzemPrsADetail");
	if (ix == QRYWZEMPRSLIST) return("QryWzemPrsList");
	if (ix == QRYWZEMPSTLIST) return("QryWzemPstList");
	if (ix == QRYWZEMUSGAACCESS) return("QryWzemUsgAAccess");
	if (ix == QRYWZEMUSGLIST) return("QryWzemUsgList");
	if (ix == QRYWZEMUSGMNUSER) return("QryWzemUsgMNUser");
	if (ix == QRYWZEMUSR1NSESSION) return("QryWzemUsr1NSession");
	if (ix == QRYWZEMUSRAACCESS) return("QryWzemUsrAAccess");
	if (ix == QRYWZEMUSRLIST) return("QryWzemUsrList");
	if (ix == QRYWZEMUSRMNUSERGROUP) return("QryWzemUsrMNUsergroup");
	if (ix == ROOTWZEM) return("RootWzem");
	if (ix == SESSWZEM) return("SessWzem");

	return("");
};

