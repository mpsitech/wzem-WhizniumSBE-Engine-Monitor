/**
	* \file CrdWzemNav.cpp
	* API code for job CrdWzemNav (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWzemNav.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWzemNav::VecVDo
 ******************************************************************************/

uint CrdWzemNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitsesspsclick") return MITSESSPSCLICK;
	if (s == "mitsestrmclick") return MITSESTRMCLICK;
	if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	if (s == "mitcrdprdclick") return MITCRDPRDCLICK;
	if (s == "mitcrdevtclick") return MITCRDEVTCLICK;
	if (s == "mitcrdjobclick") return MITCRDJOBCLICK;
	if (s == "mitcrdcalclick") return MITCRDCALCLICK;
	if (s == "mitcrdclnclick") return MITCRDCLNCLICK;
	if (s == "mitcrdopxclick") return MITCRDOPXCLICK;
	if (s == "mitcrdpstclick") return MITCRDPSTCLICK;
	if (s == "mitcrdndeclick") return MITCRDNDECLICK;
	if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdWzemNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
	if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	if (ix == MITCRDPRDCLICK) return("MitCrdPrdClick");
	if (ix == MITCRDEVTCLICK) return("MitCrdEvtClick");
	if (ix == MITCRDJOBCLICK) return("MitCrdJobClick");
	if (ix == MITCRDCALCLICK) return("MitCrdCalClick");
	if (ix == MITCRDCLNCLICK) return("MitCrdClnClick");
	if (ix == MITCRDOPXCLICK) return("MitCrdOpxClick");
	if (ix == MITCRDPSTCLICK) return("MitCrdPstClick");
	if (ix == MITCRDNDECLICK) return("MitCrdNdeClick");
	if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdWzemNav::VecVSge
 ******************************************************************************/

uint CrdWzemNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwzemabt") return ALRWZEMABT;
	if (s == "alrwzemtrm") return ALRWZEMTRM;

	return(0);
};

string CrdWzemNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZEMABT) return("alrwzemabt");
	if (ix == ALRWZEMTRM) return("alrwzemtrm");

	return("");
};

/******************************************************************************
 class CrdWzemNav::ContInf
 ******************************************************************************/

CrdWzemNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdWzemNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdWzemNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdWzemNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzemNav::StatApp
 ******************************************************************************/

CrdWzemNav::StatApp::StatApp(
			const uint ixWzemVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneMon
		) :
			Block()
		{
	this->ixWzemVReqitmode = ixWzemVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdonePre = initdonePre;
	this->initdoneAdmin = initdoneAdmin;
	this->initdoneMon = initdoneMon;

	mask = {IXWZEMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEMON};
};

bool CrdWzemNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVReqitmode", srefIxWzemVReqitmode)) {
			ixWzemVReqitmode = VecWzemVReqitmode::getIx(srefIxWzemVReqitmode);
			add(IXWZEMVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMon", initdoneMon)) add(INITDONEMON);
	};

	return basefound;
};

set<uint> CrdWzemNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVReqitmode == comp->ixWzemVReqitmode) insert(items, IXWZEMVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneMon == comp->initdoneMon) insert(items, INITDONEMON);

	return(items);
};

set<uint> CrdWzemNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEMON};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzemNav::StatShr
 ******************************************************************************/

CrdWzemNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefHeadbar
			, const string& scrJrefPre
			, const bool pnlpreAvail
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefMon
			, const bool pnlmonAvail
			, const bool MitSesSpsAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MspCrd2Avail
			, const bool MitCrdPrdAvail
			, const bool MitCrdEvtAvail
			, const bool MitCrdEvtActive
			, const bool MitCrdJobAvail
			, const bool MitCrdJobActive
			, const bool MitCrdCalAvail
			, const bool MitCrdCalActive
			, const bool MitCrdClnAvail
			, const bool MitCrdClnActive
			, const bool MitCrdOpxAvail
			, const bool MitCrdOpxActive
			, const bool MitCrdPstAvail
			, const bool MitCrdPstActive
			, const bool MitCrdNdeAvail
			, const bool MitCrdNdeActive
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) :
			Block()
		{
	this->scrJrefDlgloaini = scrJrefDlgloaini;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefPre = scrJrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->scrJrefAdmin = scrJrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->scrJrefMon = scrJrefMon;
	this->pnlmonAvail = pnlmonAvail;
	this->MitSesSpsAvail = MitSesSpsAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdPrdAvail = MitCrdPrdAvail;
	this->MitCrdEvtAvail = MitCrdEvtAvail;
	this->MitCrdEvtActive = MitCrdEvtActive;
	this->MitCrdJobAvail = MitCrdJobAvail;
	this->MitCrdJobActive = MitCrdJobActive;
	this->MitCrdCalAvail = MitCrdCalAvail;
	this->MitCrdCalActive = MitCrdCalActive;
	this->MitCrdClnAvail = MitCrdClnAvail;
	this->MitCrdClnActive = MitCrdClnActive;
	this->MitCrdOpxAvail = MitCrdOpxAvail;
	this->MitCrdOpxActive = MitCrdOpxActive;
	this->MitCrdPstAvail = MitCrdPstAvail;
	this->MitCrdPstActive = MitCrdPstActive;
	this->MitCrdNdeAvail = MitCrdNdeAvail;
	this->MitCrdNdeActive = MitCrdNdeActive;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFMON, PNLMONAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MSPCRD2AVAIL, MITCRDPRDAVAIL, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MITCRDCLNAVAIL, MITCRDCLNACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDNDEAVAIL, MITCRDNDEACTIVE, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

bool CrdWzemNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpreAvail", pnlpreAvail)) add(PNLPREAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMon", scrJrefMon)) add(SCRJREFMON);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmonAvail", pnlmonAvail)) add(PNLMONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitSesSpsAvail", MitSesSpsAvail)) add(MITSESSPSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrdAvail", MitCrdPrdAvail)) add(MITCRDPRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEvtAvail", MitCrdEvtAvail)) add(MITCRDEVTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEvtActive", MitCrdEvtActive)) add(MITCRDEVTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdJobAvail", MitCrdJobAvail)) add(MITCRDJOBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdJobActive", MitCrdJobActive)) add(MITCRDJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCalAvail", MitCrdCalAvail)) add(MITCRDCALAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCalActive", MitCrdCalActive)) add(MITCRDCALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdClnAvail", MitCrdClnAvail)) add(MITCRDCLNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdClnActive", MitCrdClnActive)) add(MITCRDCLNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOpxAvail", MitCrdOpxAvail)) add(MITCRDOPXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOpxActive", MitCrdOpxActive)) add(MITCRDOPXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPstAvail", MitCrdPstAvail)) add(MITCRDPSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPstActive", MitCrdPstActive)) add(MITCRDPSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNdeAvail", MitCrdNdeAvail)) add(MITCRDNDEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNdeActive", MitCrdNdeActive)) add(MITCRDNDEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdWzemNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini == comp->scrJrefDlgloaini) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefPre == comp->scrJrefPre) insert(items, SCRJREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (scrJrefAdmin == comp->scrJrefAdmin) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefMon == comp->scrJrefMon) insert(items, SCRJREFMON);
	if (pnlmonAvail == comp->pnlmonAvail) insert(items, PNLMONAVAIL);
	if (MitSesSpsAvail == comp->MitSesSpsAvail) insert(items, MITSESSPSAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdPrdAvail == comp->MitCrdPrdAvail) insert(items, MITCRDPRDAVAIL);
	if (MitCrdEvtAvail == comp->MitCrdEvtAvail) insert(items, MITCRDEVTAVAIL);
	if (MitCrdEvtActive == comp->MitCrdEvtActive) insert(items, MITCRDEVTACTIVE);
	if (MitCrdJobAvail == comp->MitCrdJobAvail) insert(items, MITCRDJOBAVAIL);
	if (MitCrdJobActive == comp->MitCrdJobActive) insert(items, MITCRDJOBACTIVE);
	if (MitCrdCalAvail == comp->MitCrdCalAvail) insert(items, MITCRDCALAVAIL);
	if (MitCrdCalActive == comp->MitCrdCalActive) insert(items, MITCRDCALACTIVE);
	if (MitCrdClnAvail == comp->MitCrdClnAvail) insert(items, MITCRDCLNAVAIL);
	if (MitCrdClnActive == comp->MitCrdClnActive) insert(items, MITCRDCLNACTIVE);
	if (MitCrdOpxAvail == comp->MitCrdOpxAvail) insert(items, MITCRDOPXAVAIL);
	if (MitCrdOpxActive == comp->MitCrdOpxActive) insert(items, MITCRDOPXACTIVE);
	if (MitCrdPstAvail == comp->MitCrdPstAvail) insert(items, MITCRDPSTAVAIL);
	if (MitCrdPstActive == comp->MitCrdPstActive) insert(items, MITCRDPSTACTIVE);
	if (MitCrdNdeAvail == comp->MitCrdNdeAvail) insert(items, MITCRDNDEAVAIL);
	if (MitCrdNdeActive == comp->MitCrdNdeActive) insert(items, MITCRDNDEACTIVE);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdWzemNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFMON, PNLMONAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MSPCRD2AVAIL, MITCRDPRDAVAIL, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MITCRDCLNAVAIL, MITCRDCLNACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDNDEAVAIL, MITCRDNDEACTIVE, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzemNav::Tag
 ******************************************************************************/

CrdWzemNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesSps
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdPrs
			, const string& MitCrdPrd
			, const string& MitCrdEvt
			, const string& MitCrdJob
			, const string& MitCrdCal
			, const string& MitCrdCln
			, const string& MitCrdOpx
			, const string& MitCrdPst
			, const string& MitCrdNde
			, const string& MitAppLoi
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitSesSps = MitSesSps;
	this->MitSesTrm = MitSesTrm;
	this->MitCrdUsg = MitCrdUsg;
	this->MitCrdUsr = MitCrdUsr;
	this->MitCrdPrs = MitCrdPrs;
	this->MitCrdPrd = MitCrdPrd;
	this->MitCrdEvt = MitCrdEvt;
	this->MitCrdJob = MitCrdJob;
	this->MitCrdCal = MitCrdCal;
	this->MitCrdCln = MitCrdCln;
	this->MitCrdOpx = MitCrdOpx;
	this->MitCrdPst = MitCrdPst;
	this->MitCrdNde = MitCrdNde;
	this->MitAppLoi = MitAppLoi;

	mask = {MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDPRD, MITCRDEVT, MITCRDJOB, MITCRDCAL, MITCRDCLN, MITCRDOPX, MITCRDPST, MITCRDNDE, MITAPPLOI};
};

bool CrdWzemNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesSps", MitSesSps)) add(MITSESSPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrd", MitCrdPrd)) add(MITCRDPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdEvt", MitCrdEvt)) add(MITCRDEVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdJob", MitCrdJob)) add(MITCRDJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCal", MitCrdCal)) add(MITCRDCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCln", MitCrdCln)) add(MITCRDCLN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdOpx", MitCrdOpx)) add(MITCRDOPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPst", MitCrdPst)) add(MITCRDPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNde", MitCrdNde)) add(MITCRDNDE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdWzemNav::DpchAppDo
 ******************************************************************************/

CrdWzemNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWzemNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzemNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzemNav::DpchEngData
 ******************************************************************************/

CrdWzemNav::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWzemNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzemNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemNavData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
