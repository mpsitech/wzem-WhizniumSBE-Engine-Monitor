/**
	* \file PnlWzemNavAdmin.cpp
	* API code for job PnlWzemNavAdmin (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzemNavAdmin.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemNavAdmin::VecVDo
 ******************************************************************************/

uint PnlWzemNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;

	return(0);
};

string PnlWzemNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzemNavAdmin::ContIac
 ******************************************************************************/

PnlWzemNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstPrs
		) :
			Block()
		{
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstPrs = numFLstPrs;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS};
};

bool PnlWzemNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
	};

	return basefound;
};

void PnlWzemNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);

	return(items);
};

set<uint> PnlWzemNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavAdmin::StatApp
 ******************************************************************************/

PnlWzemNavAdmin::StatApp::StatApp(
			const uint ixWzemVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->LstUsgAlt = LstUsgAlt;
	this->LstUsrAlt = LstUsrAlt;
	this->LstPrsAlt = LstPrsAlt;
	this->LstUsgNumFirstdisp = LstUsgNumFirstdisp;
	this->LstUsrNumFirstdisp = LstUsrNumFirstdisp;
	this->LstPrsNumFirstdisp = LstPrsNumFirstdisp;

	mask = {IXWZEMVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP};
};

bool PnlWzemNavAdmin::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAlt", LstUsgAlt)) add(LSTUSGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAlt", LstUsrAlt)) add(LSTUSRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAlt", LstPrsAlt)) add(LSTPRSALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp)) add(LSTUSGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp)) add(LSTUSRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp)) add(LSTPRSNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzemNavAdmin::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (LstUsgAlt == comp->LstUsgAlt) insert(items, LSTUSGALT);
	if (LstUsrAlt == comp->LstUsrAlt) insert(items, LSTUSRALT);
	if (LstPrsAlt == comp->LstPrsAlt) insert(items, LSTPRSALT);
	if (LstUsgNumFirstdisp == comp->LstUsgNumFirstdisp) insert(items, LSTUSGNUMFIRSTDISP);
	if (LstUsrNumFirstdisp == comp->LstUsrNumFirstdisp) insert(items, LSTUSRNUMFIRSTDISP);
	if (LstPrsNumFirstdisp == comp->LstPrsNumFirstdisp) insert(items, LSTPRSNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzemNavAdmin::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavAdmin::StatShr
 ******************************************************************************/

PnlWzemNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
		) :
			Block()
		{
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE};
};

bool PnlWzemNavAdmin::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemNavAdmin";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAvail", LstUsgAvail)) add(LSTUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", ButUsgViewActive)) add(BUTUSGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAvail", LstUsrAvail)) add(LSTUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", ButUsrViewActive)) add(BUTUSRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAvail", LstPrsAvail)) add(LSTPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", ButPrsViewActive)) add(BUTPRSVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);

	return(items);
};

set<uint> PnlWzemNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavAdmin::Tag
 ******************************************************************************/

PnlWzemNavAdmin::Tag::Tag(
			const string& Cpt
			, const string& CptUsg
			, const string& CptUsr
			, const string& CptPrs
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptUsg = CptUsg;
	this->CptUsr = CptUsr;
	this->CptPrs = CptPrs;

	mask = {CPT, CPTUSG, CPTUSR, CPTPRS};
};

bool PnlWzemNavAdmin::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsg", CptUsg)) add(CPTUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsr", CptUsr)) add(CPTUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemNavAdmin::DpchAppData
 ******************************************************************************/

PnlWzemNavAdmin::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVADMINDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavAdmin::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavAdmin::DpchAppDo
 ******************************************************************************/

PnlWzemNavAdmin::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVADMINDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavAdmin::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNavAdminDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavAdmin::DpchEngData
 ******************************************************************************/

PnlWzemNavAdmin::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVADMINDATA)
		{
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";
};

string PnlWzemNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavAdmin::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemNavAdminData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstPrs.readXML(docctx, basexpath, true)) add(FEEDFLSTPRS);
		if (feedFLstUsg.readXML(docctx, basexpath, true)) add(FEEDFLSTUSG);
		if (feedFLstUsr.readXML(docctx, basexpath, true)) add(FEEDFLSTUSR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstPrs.clear();
		feedFLstUsg.clear();
		feedFLstUsr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

