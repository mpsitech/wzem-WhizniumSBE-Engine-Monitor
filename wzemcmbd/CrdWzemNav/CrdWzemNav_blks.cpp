/**
	* \file CrdWzemNav_blks.cpp
	* job handler for job CrdWzemNav (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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

void CrdWzemNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdWzemNav::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxSesSes1"] = MtxSesSes1;
	me["MtxSesSes2"] = MtxSesSes2;
	me["MtxSesSes3"] = MtxSesSes3;
};

void CrdWzemNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
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

void CrdWzemNav::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzemVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneMon
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzemVReqitmode"] = VecWzemVReqitmode::getSref(ixWzemVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdonePre"] = initdonePre;
	me["initdoneAdmin"] = initdoneAdmin;
	me["initdoneMon"] = initdoneMon;
};

void CrdWzemNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneMon
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVReqitmode", VecWzemVReqitmode::getSref(ixWzemVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMon", initdoneMon);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzemNav::StatShr
 ******************************************************************************/

CrdWzemNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefHeadbar
			, const ubigint jrefPre
			, const bool pnlpreAvail
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefMon
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
	this->jrefDlgloaini = jrefDlgloaini;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefPre = jrefPre;
	this->pnlpreAvail = pnlpreAvail;
	this->jrefAdmin = jrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->jrefMon = jrefMon;
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

	mask = {JREFDLGLOAINI, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFMON, PNLMONAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MSPCRD2AVAIL, MITCRDPRDAVAIL, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MITCRDCLNAVAIL, MITCRDCLNACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDNDEAVAIL, MITCRDNDEACTIVE, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

void CrdWzemNav::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgloaini"] = Scr::scramble(jrefDlgloaini);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefPre"] = Scr::scramble(jrefPre);
	me["pnlpreAvail"] = pnlpreAvail;
	me["scrJrefAdmin"] = Scr::scramble(jrefAdmin);
	me["pnladminAvail"] = pnladminAvail;
	me["scrJrefMon"] = Scr::scramble(jrefMon);
	me["pnlmonAvail"] = pnlmonAvail;
	me["MitSesSpsAvail"] = MitSesSpsAvail;
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdUsgAvail"] = MitCrdUsgAvail;
	me["MitCrdUsrAvail"] = MitCrdUsrAvail;
	me["MitCrdPrsAvail"] = MitCrdPrsAvail;
	me["MspCrd2Avail"] = MspCrd2Avail;
	me["MitCrdPrdAvail"] = MitCrdPrdAvail;
	me["MitCrdEvtAvail"] = MitCrdEvtAvail;
	me["MitCrdEvtActive"] = MitCrdEvtActive;
	me["MitCrdJobAvail"] = MitCrdJobAvail;
	me["MitCrdJobActive"] = MitCrdJobActive;
	me["MitCrdCalAvail"] = MitCrdCalAvail;
	me["MitCrdCalActive"] = MitCrdCalActive;
	me["MitCrdClnAvail"] = MitCrdClnAvail;
	me["MitCrdClnActive"] = MitCrdClnActive;
	me["MitCrdOpxAvail"] = MitCrdOpxAvail;
	me["MitCrdOpxActive"] = MitCrdOpxActive;
	me["MitCrdPstAvail"] = MitCrdPstAvail;
	me["MitCrdPstActive"] = MitCrdPstActive;
	me["MitCrdNdeAvail"] = MitCrdNdeAvail;
	me["MitCrdNdeActive"] = MitCrdNdeActive;
	me["MspApp2Avail"] = MspApp2Avail;
	me["MitAppLoiAvail"] = MitAppLoiAvail;
};

void CrdWzemNav::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(jrefPre));
		writeBoolAttr(wr, itemtag, "sref", "pnlpreAvail", pnlpreAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMon", Scr::scramble(jrefMon));
		writeBoolAttr(wr, itemtag, "sref", "pnlmonAvail", pnlmonAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitSesSpsAvail", MitSesSpsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrdAvail", MitCrdPrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEvtAvail", MitCrdEvtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEvtActive", MitCrdEvtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdJobAvail", MitCrdJobAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdJobActive", MitCrdJobActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCalAvail", MitCrdCalAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCalActive", MitCrdCalActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdClnAvail", MitCrdClnAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdClnActive", MitCrdClnActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOpxAvail", MitCrdOpxAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOpxActive", MitCrdOpxActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPstAvail", MitCrdPstAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPstActive", MitCrdPstActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNdeAvail", MitCrdNdeAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNdeActive", MitCrdNdeActive);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWzemNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefMon == comp->jrefMon) insert(items, JREFMON);
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

	diffitems = {JREFDLGLOAINI, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFMON, PNLMONAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MSPCRD2AVAIL, MITCRDPRDAVAIL, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MITCRDCLNAVAIL, MITCRDCLNACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDNDEAVAIL, MITCRDNDEACTIVE, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWzemNav::Tag
 ******************************************************************************/

void CrdWzemNav::Tag::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzemNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["MitCrdUsg"] = "User groups ...";
		me["MitCrdUsr"] = "Users ...";
		me["MitCrdPrs"] = "Persons ...";
		me["MitCrdPrd"] = "Monitoring periods ...";
		me["MitCrdEvt"] = "Events ...";
		me["MitCrdJob"] = "Jobs ...";
		me["MitCrdCal"] = "Calls ...";
		me["MitCrdCln"] = "Call listeners ...";
		me["MitCrdOpx"] = "Operations ...";
		me["MitCrdPst"] = "Presettings ...";
		me["MitCrdNde"] = "Nodes ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::ABOUT, ixWzemVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::HELP, ixWzemVLocale)) + " ...";
	me["MitSesSps"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::SUSPSESS, ixWzemVLocale));
	me["MitSesTrm"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::CLSESS, ixWzemVLocale));
	me["MitAppLoi"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::LOAINI, ixWzemVLocale)) + " ...";
};

void CrdWzemNav::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrd", "Monitoring periods ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdEvt", "Events ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdJob", "Jobs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCal", "Calls ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCln", "Call listeners ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpx", "Operations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPst", "Presettings ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdNde", "Nodes ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::ABOUT, ixWzemVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::HELP, ixWzemVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesSps", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::SUSPSESS, ixWzemVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::CLSESS, ixWzemVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::LOAINI, ixWzemVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWzemNav::DpchAppDo
 ******************************************************************************/

CrdWzemNav::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVDO)
		{
	ixVDo = 0;
};

string CrdWzemNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzemNav::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemNavDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWzemNav::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemNavDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class CrdWzemNav::DpchEngData
 ******************************************************************************/

CrdWzemNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWzemNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWzemNav::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWzemNav::DpchEngData::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemNavData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzemVLocale, me);
};

void CrdWzemNav::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};
