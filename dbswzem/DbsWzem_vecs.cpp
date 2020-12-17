/**
	* \file DbsWzem_vecs.cpp
	* C++ wrapper for database DbsWzem (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DbsWzem::VecVCard
 ******************************************************************************/

uint DbsWzem::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdwzemnav") return CRDWZEMNAV;
	if (s == "crdwzemusg") return CRDWZEMUSG;
	if (s == "crdwzemusr") return CRDWZEMUSR;
	if (s == "crdwzemprs") return CRDWZEMPRS;
	if (s == "crdwzemprd") return CRDWZEMPRD;
	if (s == "crdwzemevt") return CRDWZEMEVT;
	if (s == "crdwzemjob") return CRDWZEMJOB;
	if (s == "crdwzemcal") return CRDWZEMCAL;
	if (s == "crdwzemcln") return CRDWZEMCLN;
	if (s == "crdwzemopx") return CRDWZEMOPX;
	if (s == "crdwzempst") return CRDWZEMPST;
	if (s == "crdwzemnde") return CRDWZEMNDE;

	return(0);
};

string DbsWzem::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDWZEMNAV) return("CrdWzemNav");
	if (ix == CRDWZEMUSG) return("CrdWzemUsg");
	if (ix == CRDWZEMUSR) return("CrdWzemUsr");
	if (ix == CRDWZEMPRS) return("CrdWzemPrs");
	if (ix == CRDWZEMPRD) return("CrdWzemPrd");
	if (ix == CRDWZEMEVT) return("CrdWzemEvt");
	if (ix == CRDWZEMJOB) return("CrdWzemJob");
	if (ix == CRDWZEMCAL) return("CrdWzemCal");
	if (ix == CRDWZEMCLN) return("CrdWzemCln");
	if (ix == CRDWZEMOPX) return("CrdWzemOpx");
	if (ix == CRDWZEMPST) return("CrdWzemPst");
	if (ix == CRDWZEMNDE) return("CrdWzemNde");

	return("");
};

string DbsWzem::VecVCard::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == CRDWZEMUSG) return("user groups");
		if (ix == CRDWZEMUSR) return("users");
		if (ix == CRDWZEMPRS) return("persons");
		if (ix == CRDWZEMPRD) return("monitoring periods");
		if (ix == CRDWZEMEVT) return("events");
		if (ix == CRDWZEMJOB) return("jobs");
		if (ix == CRDWZEMCAL) return("calls");
		if (ix == CRDWZEMCLN) return("call listeners");
		if (ix == CRDWZEMOPX) return("operations");
		if (ix == CRDWZEMPST) return("presettings");
		if (ix == CRDWZEMNDE) return("nodes");
		return(getSref(ix));
	};

	return("");
};

void DbsWzem::VecVCard::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 12; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class DbsWzem::VecVControl
 ******************************************************************************/

uint DbsWzem::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlwzemusglist.tcogrp") return PNLWZEMUSGLIST_TCOGRP;
	if (s == "pnlwzemusglist.tcoown") return PNLWZEMUSGLIST_TCOOWN;
	if (s == "pnlwzemusglist.tcosrf") return PNLWZEMUSGLIST_TCOSRF;
	if (s == "pnlwzemusgaaccess.tcofeg") return PNLWZEMUSGAACCESS_TCOFEG;
	if (s == "pnlwzemusgaaccess.tcofea") return PNLWZEMUSGAACCESS_TCOFEA;
	if (s == "pnlwzemusgaaccess.tcoacc") return PNLWZEMUSGAACCESS_TCOACC;
	if (s == "pnlwzemusgmnuser.tcomref") return PNLWZEMUSGMNUSER_TCOMREF;
	if (s == "pnlwzemusgmnuser.tcoulv") return PNLWZEMUSGMNUSER_TCOULV;
	if (s == "pnlwzemusrlist.tcogrp") return PNLWZEMUSRLIST_TCOGRP;
	if (s == "pnlwzemusrlist.tcoown") return PNLWZEMUSRLIST_TCOOWN;
	if (s == "pnlwzemusrlist.tcoprs") return PNLWZEMUSRLIST_TCOPRS;
	if (s == "pnlwzemusrlist.tcosrf") return PNLWZEMUSRLIST_TCOSRF;
	if (s == "pnlwzemusrlist.tcousg") return PNLWZEMUSRLIST_TCOUSG;
	if (s == "pnlwzemusrlist.tcoste") return PNLWZEMUSRLIST_TCOSTE;
	if (s == "pnlwzemusrlist.tcolcl") return PNLWZEMUSRLIST_TCOLCL;
	if (s == "pnlwzemusrlist.tcoulv") return PNLWZEMUSRLIST_TCOULV;
	if (s == "pnlwzemusraaccess.tcofeg") return PNLWZEMUSRAACCESS_TCOFEG;
	if (s == "pnlwzemusraaccess.tcofea") return PNLWZEMUSRAACCESS_TCOFEA;
	if (s == "pnlwzemusraaccess.tcoacc") return PNLWZEMUSRAACCESS_TCOACC;
	if (s == "pnlwzemusr1nsession.tcoref") return PNLWZEMUSR1NSESSION_TCOREF;
	if (s == "pnlwzemusrmnusergroup.tcomref") return PNLWZEMUSRMNUSERGROUP_TCOMREF;
	if (s == "pnlwzemusrmnusergroup.tcoulv") return PNLWZEMUSRMNUSERGROUP_TCOULV;
	if (s == "pnlwzemprslist.tcogrp") return PNLWZEMPRSLIST_TCOGRP;
	if (s == "pnlwzemprslist.tcoown") return PNLWZEMPRSLIST_TCOOWN;
	if (s == "pnlwzemprslist.tcotit") return PNLWZEMPRSLIST_TCOTIT;
	if (s == "pnlwzemprslist.tcofnm") return PNLWZEMPRSLIST_TCOFNM;
	if (s == "pnlwzemprslist.tcolnm") return PNLWZEMPRSLIST_TCOLNM;
	if (s == "pnlwzemprslist.tcosex") return PNLWZEMPRSLIST_TCOSEX;
	if (s == "pnlwzemprslist.tcotel") return PNLWZEMPRSLIST_TCOTEL;
	if (s == "pnlwzemprslist.tcoeml") return PNLWZEMPRSLIST_TCOEML;
	if (s == "pnlwzemprsadetail.tcotyp") return PNLWZEMPRSADETAIL_TCOTYP;
	if (s == "pnlwzemprsadetail.tcoval") return PNLWZEMPRSADETAIL_TCOVAL;
	if (s == "pnlwzemprdlist.tcogrp") return PNLWZEMPRDLIST_TCOGRP;
	if (s == "pnlwzemprdlist.tcoown") return PNLWZEMPRDLIST_TCOOWN;
	if (s == "pnlwzemprdlist.tcover") return PNLWZEMPRDLIST_TCOVER;
	if (s == "pnlwzemprdlist.tcosta") return PNLWZEMPRDLIST_TCOSTA;
	if (s == "pnlwzemprdlist.tcosto") return PNLWZEMPRDLIST_TCOSTO;
	if (s == "pnlwzemprd1njob.tcoref") return PNLWZEMPRD1NJOB_TCOREF;
	if (s == "pnlwzemprd1nnode.tcoref") return PNLWZEMPRD1NNODE_TCOREF;
	if (s == "pnlwzemprd1nevent.tcoref") return PNLWZEMPRD1NEVENT_TCOREF;
	if (s == "pnlwzemevtlist.tcotyp") return PNLWZEMEVTLIST_TCOTYP;
	if (s == "pnlwzemevtlist.tcoprd") return PNLWZEMEVTLIST_TCOPRD;
	if (s == "pnlwzemevtlist.tcosta") return PNLWZEMEVTLIST_TCOSTA;
	if (s == "pnlwzemevtlist.tcocmd") return PNLWZEMEVTLIST_TCOCMD;
	if (s == "pnlwzemevtlist.tcofeg") return PNLWZEMEVTLIST_TCOFEG;
	if (s == "pnlwzemevtlist.tcomtd") return PNLWZEMEVTLIST_TCOMTD;
	if (s == "pnlwzemevtlist.tcoxsr") return PNLWZEMEVTLIST_TCOXSR;
	if (s == "pnlwzemjoblist.tcoprd") return PNLWZEMJOBLIST_TCOPRD;
	if (s == "pnlwzemjoblist.tcojob") return PNLWZEMJOBLIST_TCOJOB;
	if (s == "pnlwzemjoblist.tcoxjr") return PNLWZEMJOBLIST_TCOXJR;
	if (s == "pnlwzemjoblist.tcosta") return PNLWZEMJOBLIST_TCOSTA;
	if (s == "pnlwzemjoblist.tcosto") return PNLWZEMJOBLIST_TCOSTO;
	if (s == "pnlwzemjoblist.tcosup") return PNLWZEMJOBLIST_TCOSUP;
	if (s == "pnlwzemjob1nop.tcoref") return PNLWZEMJOB1NOP_TCOREF;
	if (s == "pnlwzemjob1ncall.tcoref") return PNLWZEMJOB1NCALL_TCOREF;
	if (s == "pnlwzemjob1npreset.tcoref") return PNLWZEMJOB1NPRESET_TCOREF;
	if (s == "pnlwzemjob1nclstn.tcoref") return PNLWZEMJOB1NCLSTN_TCOREF;
	if (s == "pnlwzemjobsup1njob.tcoref") return PNLWZEMJOBSUP1NJOB_TCOREF;
	if (s == "pnlwzemcallist.tcojob") return PNLWZEMCALLIST_TCOJOB;
	if (s == "pnlwzemcallist.tcocal") return PNLWZEMCALLIST_TCOCAL;
	if (s == "pnlwzemcallist.tcosta") return PNLWZEMCALLIST_TCOSTA;
	if (s == "pnlwzemcallist.tcosto") return PNLWZEMCALLIST_TCOSTO;
	if (s == "pnlwzemclnlist.tcojob") return PNLWZEMCLNLIST_TCOJOB;
	if (s == "pnlwzemclnlist.tcocal") return PNLWZEMCLNLIST_TCOCAL;
	if (s == "pnlwzemclnlist.tcosge") return PNLWZEMCLNLIST_TCOSGE;
	if (s == "pnlwzemclnlist.tcosta") return PNLWZEMCLNLIST_TCOSTA;
	if (s == "pnlwzemclnlist.tcosto") return PNLWZEMCLNLIST_TCOSTO;
	if (s == "pnlwzemopxlist.tcojob") return PNLWZEMOPXLIST_TCOJOB;
	if (s == "pnlwzemopxlist.tcoxor") return PNLWZEMOPXLIST_TCOXOR;
	if (s == "pnlwzemopxlist.tcosta") return PNLWZEMOPXLIST_TCOSTA;
	if (s == "pnlwzemopxlist.tcosto") return PNLWZEMOPXLIST_TCOSTO;
	if (s == "pnlwzempstlist.tcojob") return PNLWZEMPSTLIST_TCOJOB;
	if (s == "pnlwzempstlist.tcopst") return PNLWZEMPSTLIST_TCOPST;
	if (s == "pnlwzempstlist.tcosta") return PNLWZEMPSTLIST_TCOSTA;
	if (s == "pnlwzempstlist.tcosto") return PNLWZEMPSTLIST_TCOSTO;
	if (s == "pnlwzemndelist.tcoprd") return PNLWZEMNDELIST_TCOPRD;
	if (s == "pnlwzemndelist.tcoxnr") return PNLWZEMNDELIST_TCOXNR;
	if (s == "pnlwzemndelist.tcoip") return PNLWZEMNDELIST_TCOIP;
	if (s == "pnlwzemndelist.tcosta") return PNLWZEMNDELIST_TCOSTA;
	if (s == "pnlwzemndelist.tcosto") return PNLWZEMNDELIST_TCOSTO;
	if (s == "pnlwzemndelist.tcoprt") return PNLWZEMNDELIST_TCOPRT;
	if (s == "pnlwzemndelist.tcoorn") return PNLWZEMNDELIST_TCOORN;

	return(0);
};

string DbsWzem::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLWZEMUSGLIST_TCOGRP) return("PnlWzemUsgList.TcoGrp");
	if (ix == PNLWZEMUSGLIST_TCOOWN) return("PnlWzemUsgList.TcoOwn");
	if (ix == PNLWZEMUSGLIST_TCOSRF) return("PnlWzemUsgList.TcoSrf");
	if (ix == PNLWZEMUSGAACCESS_TCOFEG) return("PnlWzemUsgAAccess.TcoFeg");
	if (ix == PNLWZEMUSGAACCESS_TCOFEA) return("PnlWzemUsgAAccess.TcoFea");
	if (ix == PNLWZEMUSGAACCESS_TCOACC) return("PnlWzemUsgAAccess.TcoAcc");
	if (ix == PNLWZEMUSGMNUSER_TCOMREF) return("PnlWzemUsgMNUser.TcoMref");
	if (ix == PNLWZEMUSGMNUSER_TCOULV) return("PnlWzemUsgMNUser.TcoUlv");
	if (ix == PNLWZEMUSRLIST_TCOGRP) return("PnlWzemUsrList.TcoGrp");
	if (ix == PNLWZEMUSRLIST_TCOOWN) return("PnlWzemUsrList.TcoOwn");
	if (ix == PNLWZEMUSRLIST_TCOPRS) return("PnlWzemUsrList.TcoPrs");
	if (ix == PNLWZEMUSRLIST_TCOSRF) return("PnlWzemUsrList.TcoSrf");
	if (ix == PNLWZEMUSRLIST_TCOUSG) return("PnlWzemUsrList.TcoUsg");
	if (ix == PNLWZEMUSRLIST_TCOSTE) return("PnlWzemUsrList.TcoSte");
	if (ix == PNLWZEMUSRLIST_TCOLCL) return("PnlWzemUsrList.TcoLcl");
	if (ix == PNLWZEMUSRLIST_TCOULV) return("PnlWzemUsrList.TcoUlv");
	if (ix == PNLWZEMUSRAACCESS_TCOFEG) return("PnlWzemUsrAAccess.TcoFeg");
	if (ix == PNLWZEMUSRAACCESS_TCOFEA) return("PnlWzemUsrAAccess.TcoFea");
	if (ix == PNLWZEMUSRAACCESS_TCOACC) return("PnlWzemUsrAAccess.TcoAcc");
	if (ix == PNLWZEMUSR1NSESSION_TCOREF) return("PnlWzemUsr1NSession.TcoRef");
	if (ix == PNLWZEMUSRMNUSERGROUP_TCOMREF) return("PnlWzemUsrMNUsergroup.TcoMref");
	if (ix == PNLWZEMUSRMNUSERGROUP_TCOULV) return("PnlWzemUsrMNUsergroup.TcoUlv");
	if (ix == PNLWZEMPRSLIST_TCOGRP) return("PnlWzemPrsList.TcoGrp");
	if (ix == PNLWZEMPRSLIST_TCOOWN) return("PnlWzemPrsList.TcoOwn");
	if (ix == PNLWZEMPRSLIST_TCOTIT) return("PnlWzemPrsList.TcoTit");
	if (ix == PNLWZEMPRSLIST_TCOFNM) return("PnlWzemPrsList.TcoFnm");
	if (ix == PNLWZEMPRSLIST_TCOLNM) return("PnlWzemPrsList.TcoLnm");
	if (ix == PNLWZEMPRSLIST_TCOSEX) return("PnlWzemPrsList.TcoSex");
	if (ix == PNLWZEMPRSLIST_TCOTEL) return("PnlWzemPrsList.TcoTel");
	if (ix == PNLWZEMPRSLIST_TCOEML) return("PnlWzemPrsList.TcoEml");
	if (ix == PNLWZEMPRSADETAIL_TCOTYP) return("PnlWzemPrsADetail.TcoTyp");
	if (ix == PNLWZEMPRSADETAIL_TCOVAL) return("PnlWzemPrsADetail.TcoVal");
	if (ix == PNLWZEMPRDLIST_TCOGRP) return("PnlWzemPrdList.TcoGrp");
	if (ix == PNLWZEMPRDLIST_TCOOWN) return("PnlWzemPrdList.TcoOwn");
	if (ix == PNLWZEMPRDLIST_TCOVER) return("PnlWzemPrdList.TcoVer");
	if (ix == PNLWZEMPRDLIST_TCOSTA) return("PnlWzemPrdList.TcoSta");
	if (ix == PNLWZEMPRDLIST_TCOSTO) return("PnlWzemPrdList.TcoSto");
	if (ix == PNLWZEMPRD1NJOB_TCOREF) return("PnlWzemPrd1NJob.TcoRef");
	if (ix == PNLWZEMPRD1NNODE_TCOREF) return("PnlWzemPrd1NNode.TcoRef");
	if (ix == PNLWZEMPRD1NEVENT_TCOREF) return("PnlWzemPrd1NEvent.TcoRef");
	if (ix == PNLWZEMEVTLIST_TCOTYP) return("PnlWzemEvtList.TcoTyp");
	if (ix == PNLWZEMEVTLIST_TCOPRD) return("PnlWzemEvtList.TcoPrd");
	if (ix == PNLWZEMEVTLIST_TCOSTA) return("PnlWzemEvtList.TcoSta");
	if (ix == PNLWZEMEVTLIST_TCOCMD) return("PnlWzemEvtList.TcoCmd");
	if (ix == PNLWZEMEVTLIST_TCOFEG) return("PnlWzemEvtList.TcoFeg");
	if (ix == PNLWZEMEVTLIST_TCOMTD) return("PnlWzemEvtList.TcoMtd");
	if (ix == PNLWZEMEVTLIST_TCOXSR) return("PnlWzemEvtList.TcoXsr");
	if (ix == PNLWZEMJOBLIST_TCOPRD) return("PnlWzemJobList.TcoPrd");
	if (ix == PNLWZEMJOBLIST_TCOJOB) return("PnlWzemJobList.TcoJob");
	if (ix == PNLWZEMJOBLIST_TCOXJR) return("PnlWzemJobList.TcoXjr");
	if (ix == PNLWZEMJOBLIST_TCOSTA) return("PnlWzemJobList.TcoSta");
	if (ix == PNLWZEMJOBLIST_TCOSTO) return("PnlWzemJobList.TcoSto");
	if (ix == PNLWZEMJOBLIST_TCOSUP) return("PnlWzemJobList.TcoSup");
	if (ix == PNLWZEMJOB1NOP_TCOREF) return("PnlWzemJob1NOp.TcoRef");
	if (ix == PNLWZEMJOB1NCALL_TCOREF) return("PnlWzemJob1NCall.TcoRef");
	if (ix == PNLWZEMJOB1NPRESET_TCOREF) return("PnlWzemJob1NPreset.TcoRef");
	if (ix == PNLWZEMJOB1NCLSTN_TCOREF) return("PnlWzemJob1NClstn.TcoRef");
	if (ix == PNLWZEMJOBSUP1NJOB_TCOREF) return("PnlWzemJobSup1NJob.TcoRef");
	if (ix == PNLWZEMCALLIST_TCOJOB) return("PnlWzemCalList.TcoJob");
	if (ix == PNLWZEMCALLIST_TCOCAL) return("PnlWzemCalList.TcoCal");
	if (ix == PNLWZEMCALLIST_TCOSTA) return("PnlWzemCalList.TcoSta");
	if (ix == PNLWZEMCALLIST_TCOSTO) return("PnlWzemCalList.TcoSto");
	if (ix == PNLWZEMCLNLIST_TCOJOB) return("PnlWzemClnList.TcoJob");
	if (ix == PNLWZEMCLNLIST_TCOCAL) return("PnlWzemClnList.TcoCal");
	if (ix == PNLWZEMCLNLIST_TCOSGE) return("PnlWzemClnList.TcoSge");
	if (ix == PNLWZEMCLNLIST_TCOSTA) return("PnlWzemClnList.TcoSta");
	if (ix == PNLWZEMCLNLIST_TCOSTO) return("PnlWzemClnList.TcoSto");
	if (ix == PNLWZEMOPXLIST_TCOJOB) return("PnlWzemOpxList.TcoJob");
	if (ix == PNLWZEMOPXLIST_TCOXOR) return("PnlWzemOpxList.TcoXor");
	if (ix == PNLWZEMOPXLIST_TCOSTA) return("PnlWzemOpxList.TcoSta");
	if (ix == PNLWZEMOPXLIST_TCOSTO) return("PnlWzemOpxList.TcoSto");
	if (ix == PNLWZEMPSTLIST_TCOJOB) return("PnlWzemPstList.TcoJob");
	if (ix == PNLWZEMPSTLIST_TCOPST) return("PnlWzemPstList.TcoPst");
	if (ix == PNLWZEMPSTLIST_TCOSTA) return("PnlWzemPstList.TcoSta");
	if (ix == PNLWZEMPSTLIST_TCOSTO) return("PnlWzemPstList.TcoSto");
	if (ix == PNLWZEMNDELIST_TCOPRD) return("PnlWzemNdeList.TcoPrd");
	if (ix == PNLWZEMNDELIST_TCOXNR) return("PnlWzemNdeList.TcoXnr");
	if (ix == PNLWZEMNDELIST_TCOIP) return("PnlWzemNdeList.TcoIp");
	if (ix == PNLWZEMNDELIST_TCOSTA) return("PnlWzemNdeList.TcoSta");
	if (ix == PNLWZEMNDELIST_TCOSTO) return("PnlWzemNdeList.TcoSto");
	if (ix == PNLWZEMNDELIST_TCOPRT) return("PnlWzemNdeList.TcoPrt");
	if (ix == PNLWZEMNDELIST_TCOORN) return("PnlWzemNdeList.TcoOrn");

	return("");
};

/******************************************************************************
 class DbsWzem::VecVFeatgroup
 ******************************************************************************/

uint DbsWzem::VecVFeatgroup::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vecwzemvcard") return VECWZEMVCARD;

	return(0);
};

string DbsWzem::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECWZEMVCARD) return("VecWzemVCard");

	return("");
};

string DbsWzem::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == VECWZEMVCARD) return("card");
		return(getSref(ix));
	};

	return("");
};

void DbsWzem::VecVFeatgroup::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class DbsWzem::VecVKeylist
 ******************************************************************************/

uint DbsWzem::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstwzemkampersondetailtype") return KLSTWZEMKAMPERSONDETAILTYPE;

	return(0);
};

string DbsWzem::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTWZEMKAMPERSONDETAILTYPE) return("KlstWzemKAMPersonDetailType");

	return("");
};

string DbsWzem::VecVKeylist::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == KLSTWZEMKAMPERSONDETAILTYPE) return("type");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWzem::VecVLat
 ******************************************************************************/

uint DbsWzem::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string DbsWzem::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsWzem::VecVLocale
 ******************************************************************************/

uint DbsWzem::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;

	return(0);
};

string DbsWzem::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");

	return("");
};

string DbsWzem::VecVLocale::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		return(getSref(ix));
	};

	return("");
};

void DbsWzem::VecVLocale::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class DbsWzem::VecVLop
 ******************************************************************************/

uint DbsWzem::VecVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string DbsWzem::VecVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

/******************************************************************************
 class DbsWzem::VecVMaintable
 ******************************************************************************/

uint DbsWzem::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tblwzemmcall") return TBLWZEMMCALL;
	if (s == "tblwzemmclstn") return TBLWZEMMCLSTN;
	if (s == "tblwzemmdpch") return TBLWZEMMDPCH;
	if (s == "tblwzemmevent") return TBLWZEMMEVENT;
	if (s == "tblwzemmjob") return TBLWZEMMJOB;
	if (s == "tblwzemmnode") return TBLWZEMMNODE;
	if (s == "tblwzemmop") return TBLWZEMMOP;
	if (s == "tblwzemmperiod") return TBLWZEMMPERIOD;
	if (s == "tblwzemmperson") return TBLWZEMMPERSON;
	if (s == "tblwzemmpreset") return TBLWZEMMPRESET;
	if (s == "tblwzemmsession") return TBLWZEMMSESSION;
	if (s == "tblwzemmuser") return TBLWZEMMUSER;
	if (s == "tblwzemmusergroup") return TBLWZEMMUSERGROUP;

	return(0);
};

string DbsWzem::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLWZEMMCALL) return("TblWzemMCall");
	if (ix == TBLWZEMMCLSTN) return("TblWzemMClstn");
	if (ix == TBLWZEMMDPCH) return("TblWzemMDpch");
	if (ix == TBLWZEMMEVENT) return("TblWzemMEvent");
	if (ix == TBLWZEMMJOB) return("TblWzemMJob");
	if (ix == TBLWZEMMNODE) return("TblWzemMNode");
	if (ix == TBLWZEMMOP) return("TblWzemMOp");
	if (ix == TBLWZEMMPERIOD) return("TblWzemMPeriod");
	if (ix == TBLWZEMMPERSON) return("TblWzemMPerson");
	if (ix == TBLWZEMMPRESET) return("TblWzemMPreset");
	if (ix == TBLWZEMMSESSION) return("TblWzemMSession");
	if (ix == TBLWZEMMUSER) return("TblWzemMUser");
	if (ix == TBLWZEMMUSERGROUP) return("TblWzemMUsergroup");

	return("");
};

string DbsWzem::VecVMaintable::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBLWZEMMCALL) return("call");
		if (ix == TBLWZEMMCLSTN) return("call listener");
		if (ix == TBLWZEMMDPCH) return("dispatch");
		if (ix == TBLWZEMMEVENT) return("event");
		if (ix == TBLWZEMMJOB) return("job");
		if (ix == TBLWZEMMNODE) return("node");
		if (ix == TBLWZEMMOP) return("operation");
		if (ix == TBLWZEMMPERIOD) return("monitoring period");
		if (ix == TBLWZEMMPERSON) return("person");
		if (ix == TBLWZEMMPRESET) return("presetting");
		if (ix == TBLWZEMMSESSION) return("session");
		if (ix == TBLWZEMMUSER) return("user");
		if (ix == TBLWZEMMUSERGROUP) return("user group");
		return(getSref(ix));
	};

	return("");
};

void DbsWzem::VecVMaintable::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 14; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class DbsWzem::VecVOolop
 ******************************************************************************/

uint DbsWzem::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string DbsWzem::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsWzem::VecVPreset
 ******************************************************************************/

uint DbsWzem::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prewzemadmin") return PREWZEMADMIN;
	if (s == "prewzemcallist.job") return PREWZEMCALLIST_JOB;
	if (s == "prewzemcallist.sta") return PREWZEMCALLIST_STA;
	if (s == "prewzemcallist.sto") return PREWZEMCALLIST_STO;
	if (s == "prewzemclnlist.job") return PREWZEMCLNLIST_JOB;
	if (s == "prewzemclnlist.sta") return PREWZEMCLNLIST_STA;
	if (s == "prewzemclnlist.sto") return PREWZEMCLNLIST_STO;
	if (s == "prewzemevtlist.prd") return PREWZEMEVTLIST_PRD;
	if (s == "prewzemevtlist.sta") return PREWZEMEVTLIST_STA;
	if (s == "prewzemevtlist.typ") return PREWZEMEVTLIST_TYP;
	if (s == "prewzemgroup") return PREWZEMGROUP;
	if (s == "prewzemip") return PREWZEMIP;
	if (s == "prewzemixcrdacccal") return PREWZEMIXCRDACCCAL;
	if (s == "prewzemixcrdacccln") return PREWZEMIXCRDACCCLN;
	if (s == "prewzemixcrdaccevt") return PREWZEMIXCRDACCEVT;
	if (s == "prewzemixcrdaccjob") return PREWZEMIXCRDACCJOB;
	if (s == "prewzemixcrdaccnde") return PREWZEMIXCRDACCNDE;
	if (s == "prewzemixcrdaccopx") return PREWZEMIXCRDACCOPX;
	if (s == "prewzemixcrdaccprd") return PREWZEMIXCRDACCPRD;
	if (s == "prewzemixcrdaccprs") return PREWZEMIXCRDACCPRS;
	if (s == "prewzemixcrdaccpst") return PREWZEMIXCRDACCPST;
	if (s == "prewzemixcrdaccusg") return PREWZEMIXCRDACCUSG;
	if (s == "prewzemixcrdaccusr") return PREWZEMIXCRDACCUSR;
	if (s == "prewzemixlcl") return PREWZEMIXLCL;
	if (s == "prewzemixord") return PREWZEMIXORD;
	if (s == "prewzemixpre") return PREWZEMIXPRE;
	if (s == "prewzemixrecacc") return PREWZEMIXRECACC;
	if (s == "prewzemjob1ncall.x1") return PREWZEMJOB1NCALL_X1;
	if (s == "prewzemjob1nclstn.x1") return PREWZEMJOB1NCLSTN_X1;
	if (s == "prewzemjob1nop.x1") return PREWZEMJOB1NOP_X1;
	if (s == "prewzemjob1npreset.x1") return PREWZEMJOB1NPRESET_X1;
	if (s == "prewzemjoblist.prd") return PREWZEMJOBLIST_PRD;
	if (s == "prewzemjoblist.sta") return PREWZEMJOBLIST_STA;
	if (s == "prewzemjoblist.sto") return PREWZEMJOBLIST_STO;
	if (s == "prewzemjoblist.sup") return PREWZEMJOBLIST_SUP;
	if (s == "prewzemjobsup1njob.x1") return PREWZEMJOBSUP1NJOB_X1;
	if (s == "prewzemjrefnotify") return PREWZEMJREFNOTIFY;
	if (s == "prewzemjrefsess") return PREWZEMJREFSESS;
	if (s == "prewzemndelist.prd") return PREWZEMNDELIST_PRD;
	if (s == "prewzemndelist.sta") return PREWZEMNDELIST_STA;
	if (s == "prewzemndelist.sto") return PREWZEMNDELIST_STO;
	if (s == "prewzemnoadm") return PREWZEMNOADM;
	if (s == "prewzemopxlist.job") return PREWZEMOPXLIST_JOB;
	if (s == "prewzemopxlist.sta") return PREWZEMOPXLIST_STA;
	if (s == "prewzemopxlist.sto") return PREWZEMOPXLIST_STO;
	if (s == "prewzemowner") return PREWZEMOWNER;
	if (s == "prewzemprd1njob.x1") return PREWZEMPRD1NJOB_X1;
	if (s == "prewzemprd1nnode.x1") return PREWZEMPRD1NNODE_X1;
	if (s == "prewzemprdlist.grp") return PREWZEMPRDLIST_GRP;
	if (s == "prewzemprdlist.own") return PREWZEMPRDLIST_OWN;
	if (s == "prewzemprdlist.sta") return PREWZEMPRDLIST_STA;
	if (s == "prewzemprsadetail.x1") return PREWZEMPRSADETAIL_X1;
	if (s == "prewzemprslist.grp") return PREWZEMPRSLIST_GRP;
	if (s == "prewzemprslist.lnm") return PREWZEMPRSLIST_LNM;
	if (s == "prewzemprslist.own") return PREWZEMPRSLIST_OWN;
	if (s == "prewzempstlist.job") return PREWZEMPSTLIST_JOB;
	if (s == "prewzempstlist.sta") return PREWZEMPSTLIST_STA;
	if (s == "prewzempstlist.sto") return PREWZEMPSTLIST_STO;
	if (s == "prewzemrefcal") return PREWZEMREFCAL;
	if (s == "prewzemrefcln") return PREWZEMREFCLN;
	if (s == "prewzemrefdch") return PREWZEMREFDCH;
	if (s == "prewzemrefevt") return PREWZEMREFEVT;
	if (s == "prewzemrefjob") return PREWZEMREFJOB;
	if (s == "prewzemrefnde") return PREWZEMREFNDE;
	if (s == "prewzemrefopx") return PREWZEMREFOPX;
	if (s == "prewzemrefprd") return PREWZEMREFPRD;
	if (s == "prewzemrefprs") return PREWZEMREFPRS;
	if (s == "prewzemrefpst") return PREWZEMREFPST;
	if (s == "prewzemrefsel") return PREWZEMREFSEL;
	if (s == "prewzemrefses") return PREWZEMREFSES;
	if (s == "prewzemrefusg") return PREWZEMREFUSG;
	if (s == "prewzemrefusr") return PREWZEMREFUSR;
	if (s == "prewzemsess") return PREWZEMSESS;
	if (s == "prewzemsuspsess") return PREWZEMSUSPSESS;
	if (s == "prewzemsysdate") return PREWZEMSYSDATE;
	if (s == "prewzemsysstamp") return PREWZEMSYSSTAMP;
	if (s == "prewzemsystime") return PREWZEMSYSTIME;
	if (s == "prewzemusgaaccess.x1") return PREWZEMUSGAACCESS_X1;
	if (s == "prewzemusgaaccess.x2") return PREWZEMUSGAACCESS_X2;
	if (s == "prewzemusglist.grp") return PREWZEMUSGLIST_GRP;
	if (s == "prewzemusglist.own") return PREWZEMUSGLIST_OWN;
	if (s == "prewzemusglist.srf") return PREWZEMUSGLIST_SRF;
	if (s == "prewzemusraaccess.x1") return PREWZEMUSRAACCESS_X1;
	if (s == "prewzemusraaccess.x2") return PREWZEMUSRAACCESS_X2;
	if (s == "prewzemusrlist.grp") return PREWZEMUSRLIST_GRP;
	if (s == "prewzemusrlist.own") return PREWZEMUSRLIST_OWN;
	if (s == "prewzemusrlist.prs") return PREWZEMUSRLIST_PRS;
	if (s == "prewzemusrlist.srf") return PREWZEMUSRLIST_SRF;
	if (s == "prewzemusrlist.ste") return PREWZEMUSRLIST_STE;
	if (s == "prewzemusrlist.usg") return PREWZEMUSRLIST_USG;

	return(0);
};

string DbsWzem::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREWZEMADMIN) return("PreWzemAdmin");
	if (ix == PREWZEMCALLIST_JOB) return("PreWzemCalList.job");
	if (ix == PREWZEMCALLIST_STA) return("PreWzemCalList.sta");
	if (ix == PREWZEMCALLIST_STO) return("PreWzemCalList.sto");
	if (ix == PREWZEMCLNLIST_JOB) return("PreWzemClnList.job");
	if (ix == PREWZEMCLNLIST_STA) return("PreWzemClnList.sta");
	if (ix == PREWZEMCLNLIST_STO) return("PreWzemClnList.sto");
	if (ix == PREWZEMEVTLIST_PRD) return("PreWzemEvtList.prd");
	if (ix == PREWZEMEVTLIST_STA) return("PreWzemEvtList.sta");
	if (ix == PREWZEMEVTLIST_TYP) return("PreWzemEvtList.typ");
	if (ix == PREWZEMGROUP) return("PreWzemGroup");
	if (ix == PREWZEMIP) return("PreWzemIp");
	if (ix == PREWZEMIXCRDACCCAL) return("PreWzemIxCrdaccCal");
	if (ix == PREWZEMIXCRDACCCLN) return("PreWzemIxCrdaccCln");
	if (ix == PREWZEMIXCRDACCEVT) return("PreWzemIxCrdaccEvt");
	if (ix == PREWZEMIXCRDACCJOB) return("PreWzemIxCrdaccJob");
	if (ix == PREWZEMIXCRDACCNDE) return("PreWzemIxCrdaccNde");
	if (ix == PREWZEMIXCRDACCOPX) return("PreWzemIxCrdaccOpx");
	if (ix == PREWZEMIXCRDACCPRD) return("PreWzemIxCrdaccPrd");
	if (ix == PREWZEMIXCRDACCPRS) return("PreWzemIxCrdaccPrs");
	if (ix == PREWZEMIXCRDACCPST) return("PreWzemIxCrdaccPst");
	if (ix == PREWZEMIXCRDACCUSG) return("PreWzemIxCrdaccUsg");
	if (ix == PREWZEMIXCRDACCUSR) return("PreWzemIxCrdaccUsr");
	if (ix == PREWZEMIXLCL) return("PreWzemIxLcl");
	if (ix == PREWZEMIXORD) return("PreWzemIxOrd");
	if (ix == PREWZEMIXPRE) return("PreWzemIxPre");
	if (ix == PREWZEMIXRECACC) return("PreWzemIxRecacc");
	if (ix == PREWZEMJOB1NCALL_X1) return("PreWzemJob1NCall.x1");
	if (ix == PREWZEMJOB1NCLSTN_X1) return("PreWzemJob1NClstn.x1");
	if (ix == PREWZEMJOB1NOP_X1) return("PreWzemJob1NOp.x1");
	if (ix == PREWZEMJOB1NPRESET_X1) return("PreWzemJob1NPreset.x1");
	if (ix == PREWZEMJOBLIST_PRD) return("PreWzemJobList.prd");
	if (ix == PREWZEMJOBLIST_STA) return("PreWzemJobList.sta");
	if (ix == PREWZEMJOBLIST_STO) return("PreWzemJobList.sto");
	if (ix == PREWZEMJOBLIST_SUP) return("PreWzemJobList.sup");
	if (ix == PREWZEMJOBSUP1NJOB_X1) return("PreWzemJobSup1NJob.x1");
	if (ix == PREWZEMJREFNOTIFY) return("PreWzemJrefNotify");
	if (ix == PREWZEMJREFSESS) return("PreWzemJrefSess");
	if (ix == PREWZEMNDELIST_PRD) return("PreWzemNdeList.prd");
	if (ix == PREWZEMNDELIST_STA) return("PreWzemNdeList.sta");
	if (ix == PREWZEMNDELIST_STO) return("PreWzemNdeList.sto");
	if (ix == PREWZEMNOADM) return("PreWzemNoadm");
	if (ix == PREWZEMOPXLIST_JOB) return("PreWzemOpxList.job");
	if (ix == PREWZEMOPXLIST_STA) return("PreWzemOpxList.sta");
	if (ix == PREWZEMOPXLIST_STO) return("PreWzemOpxList.sto");
	if (ix == PREWZEMOWNER) return("PreWzemOwner");
	if (ix == PREWZEMPRD1NJOB_X1) return("PreWzemPrd1NJob.x1");
	if (ix == PREWZEMPRD1NNODE_X1) return("PreWzemPrd1NNode.x1");
	if (ix == PREWZEMPRDLIST_GRP) return("PreWzemPrdList.grp");
	if (ix == PREWZEMPRDLIST_OWN) return("PreWzemPrdList.own");
	if (ix == PREWZEMPRDLIST_STA) return("PreWzemPrdList.sta");
	if (ix == PREWZEMPRSADETAIL_X1) return("PreWzemPrsADetail.x1");
	if (ix == PREWZEMPRSLIST_GRP) return("PreWzemPrsList.grp");
	if (ix == PREWZEMPRSLIST_LNM) return("PreWzemPrsList.lnm");
	if (ix == PREWZEMPRSLIST_OWN) return("PreWzemPrsList.own");
	if (ix == PREWZEMPSTLIST_JOB) return("PreWzemPstList.job");
	if (ix == PREWZEMPSTLIST_STA) return("PreWzemPstList.sta");
	if (ix == PREWZEMPSTLIST_STO) return("PreWzemPstList.sto");
	if (ix == PREWZEMREFCAL) return("PreWzemRefCal");
	if (ix == PREWZEMREFCLN) return("PreWzemRefCln");
	if (ix == PREWZEMREFDCH) return("PreWzemRefDch");
	if (ix == PREWZEMREFEVT) return("PreWzemRefEvt");
	if (ix == PREWZEMREFJOB) return("PreWzemRefJob");
	if (ix == PREWZEMREFNDE) return("PreWzemRefNde");
	if (ix == PREWZEMREFOPX) return("PreWzemRefOpx");
	if (ix == PREWZEMREFPRD) return("PreWzemRefPrd");
	if (ix == PREWZEMREFPRS) return("PreWzemRefPrs");
	if (ix == PREWZEMREFPST) return("PreWzemRefPst");
	if (ix == PREWZEMREFSEL) return("PreWzemRefSel");
	if (ix == PREWZEMREFSES) return("PreWzemRefSes");
	if (ix == PREWZEMREFUSG) return("PreWzemRefUsg");
	if (ix == PREWZEMREFUSR) return("PreWzemRefUsr");
	if (ix == PREWZEMSESS) return("PreWzemSess");
	if (ix == PREWZEMSUSPSESS) return("PreWzemSuspsess");
	if (ix == PREWZEMSYSDATE) return("PreWzemSysdate");
	if (ix == PREWZEMSYSSTAMP) return("PreWzemSysstamp");
	if (ix == PREWZEMSYSTIME) return("PreWzemSystime");
	if (ix == PREWZEMUSGAACCESS_X1) return("PreWzemUsgAAccess.x1");
	if (ix == PREWZEMUSGAACCESS_X2) return("PreWzemUsgAAccess.x2");
	if (ix == PREWZEMUSGLIST_GRP) return("PreWzemUsgList.grp");
	if (ix == PREWZEMUSGLIST_OWN) return("PreWzemUsgList.own");
	if (ix == PREWZEMUSGLIST_SRF) return("PreWzemUsgList.srf");
	if (ix == PREWZEMUSRAACCESS_X1) return("PreWzemUsrAAccess.x1");
	if (ix == PREWZEMUSRAACCESS_X2) return("PreWzemUsrAAccess.x2");
	if (ix == PREWZEMUSRLIST_GRP) return("PreWzemUsrList.grp");
	if (ix == PREWZEMUSRLIST_OWN) return("PreWzemUsrList.own");
	if (ix == PREWZEMUSRLIST_PRS) return("PreWzemUsrList.prs");
	if (ix == PREWZEMUSRLIST_SRF) return("PreWzemUsrList.srf");
	if (ix == PREWZEMUSRLIST_STE) return("PreWzemUsrList.ste");
	if (ix == PREWZEMUSRLIST_USG) return("PreWzemUsrList.usg");

	return("");
};

string DbsWzem::VecVPreset::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == PREWZEMREFCAL) return("call");
		if (ix == PREWZEMREFCLN) return("call listener");
		if (ix == PREWZEMREFDCH) return("dispatch");
		if (ix == PREWZEMREFEVT) return("event");
		if (ix == PREWZEMREFJOB) return("job");
		if (ix == PREWZEMREFNDE) return("node");
		if (ix == PREWZEMREFOPX) return("operation");
		if (ix == PREWZEMREFPRD) return("monitoring period");
		if (ix == PREWZEMREFPRS) return("person");
		if (ix == PREWZEMREFPST) return("presetting");
		if (ix == PREWZEMREFSES) return("session");
		if (ix == PREWZEMREFUSG) return("user group");
		if (ix == PREWZEMREFUSR) return("user");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWzem::VecVRecaccess
 ******************************************************************************/

uint DbsWzem::VecVRecaccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	if (s == "none") return NONE;
	if (s == "view") return VIEW;

	return(0);
};

string DbsWzem::VecVRecaccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	if (ix == NONE) return("none");
	if (ix == VIEW) return("view");

	return("");
};

string DbsWzem::VecVRecaccess::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == FULL) return("full");
		if (ix == NONE) return("none");
		if (ix == VIEW) return("view");
		return(getSref(ix));
	};

	return("");
};

void DbsWzem::VecVRecaccess::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class DbsWzem::VecVUserlevel
 ******************************************************************************/

uint DbsWzem::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	if (s == "gadm") return GADM;
	if (s == "reg") return REG;
	if (s == "vtor") return VTOR;

	return(0);
};

string DbsWzem::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	if (ix == GADM) return("gadm");
	if (ix == REG) return("reg");
	if (ix == VTOR) return("vtor");

	return("");
};

string DbsWzem::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == ADM) return("administrator");
		if (ix == GADM) return("user group administrator");
		if (ix == REG) return("regular user");
		if (ix == VTOR) return("visitor");
		return(getSref(ix));
	};

	return("");
};

void DbsWzem::VecVUserlevel::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class DbsWzem::VecVValuelist
 ******************************************************************************/

uint DbsWzem::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstwzemumpersontitle") return VLSTWZEMUMPERSONTITLE;

	return(0);
};

string DbsWzem::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTWZEMUMPERSONTITLE) return("VlstWzemUMPersonTitle");

	return("");
};

string DbsWzem::VecVValuelist::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == VLSTWZEMUMPERSONTITLE) return("title");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWzem::VecWAccess
 ******************************************************************************/

uint DbsWzem::VecWAccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsWzem::VecWAccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VIEW); i *= 2) if (ix & i) ics.insert(i);
};

string DbsWzem::VecWAccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsWzem::VecWAccess::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == EDIT) return("edit");
		if (ix == EXEC) return("execute");
		if (ix == VIEW) return("view");
		return(getSrefs(ix));
	};

	return("");
};

void DbsWzem::VecWAccess::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= VIEW; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWzemVLocale));
};
