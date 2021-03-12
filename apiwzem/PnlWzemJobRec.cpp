/**
	* \file PnlWzemJobRec.cpp
	* API code for job PnlWzemJobRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzemJobRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemJobRec::VecVDo
 ******************************************************************************/

uint PnlWzemJobRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWzemJobRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWzemJobRec::ContInf
 ******************************************************************************/

PnlWzemJobRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWzemJobRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemJobRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWzemJobRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWzemJobRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobRec::StatApp
 ******************************************************************************/

PnlWzemJobRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NClstn
			, const bool initdone1NPreset
			, const bool initdone1NCall
			, const bool initdone1NOp
			, const bool initdoneSup1NJob
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdone1NClstn = initdone1NClstn;
	this->initdone1NPreset = initdone1NPreset;
	this->initdone1NCall = initdone1NCall;
	this->initdone1NOp = initdone1NOp;
	this->initdoneSup1NJob = initdoneSup1NJob;

	mask = {INITDONEDETAIL, INITDONE1NCLSTN, INITDONE1NPRESET, INITDONE1NCALL, INITDONE1NOP, INITDONESUP1NJOB};
};

bool PnlWzemJobRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemJobRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NClstn", initdone1NClstn)) add(INITDONE1NCLSTN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NPreset", initdone1NPreset)) add(INITDONE1NPRESET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NCall", initdone1NCall)) add(INITDONE1NCALL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NOp", initdone1NOp)) add(INITDONE1NOP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NJob", initdoneSup1NJob)) add(INITDONESUP1NJOB);
	};

	return basefound;
};

set<uint> PnlWzemJobRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NClstn == comp->initdone1NClstn) insert(items, INITDONE1NCLSTN);
	if (initdone1NPreset == comp->initdone1NPreset) insert(items, INITDONE1NPRESET);
	if (initdone1NCall == comp->initdone1NCall) insert(items, INITDONE1NCALL);
	if (initdone1NOp == comp->initdone1NOp) insert(items, INITDONE1NOP);
	if (initdoneSup1NJob == comp->initdoneSup1NJob) insert(items, INITDONESUP1NJOB);

	return(items);
};

set<uint> PnlWzemJobRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NCLSTN, INITDONE1NPRESET, INITDONE1NCALL, INITDONE1NOP, INITDONESUP1NJOB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobRec::StatShr
 ******************************************************************************/

PnlWzemJobRec::StatShr::StatShr(
			const uint ixWzemVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NClstn
			, const string& scrJref1NPreset
			, const string& scrJref1NCall
			, const string& scrJref1NOp
			, const string& scrJrefSup1NJob
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NClstn = scrJref1NClstn;
	this->scrJref1NPreset = scrJref1NPreset;
	this->scrJref1NCall = scrJref1NCall;
	this->scrJref1NOp = scrJref1NOp;
	this->scrJrefSup1NJob = scrJrefSup1NJob;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZEMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NCLSTN, SCRJREF1NPRESET, SCRJREF1NCALL, SCRJREF1NOP, SCRJREFSUP1NJOB, BUTREGULARIZEACTIVE};
};

bool PnlWzemJobRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemJobRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NClstn", scrJref1NClstn)) add(SCRJREF1NCLSTN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NPreset", scrJref1NPreset)) add(SCRJREF1NPRESET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NCall", scrJref1NCall)) add(SCRJREF1NCALL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NOp", scrJref1NOp)) add(SCRJREF1NOP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NJob", scrJrefSup1NJob)) add(SCRJREFSUP1NJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemJobRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NClstn == comp->scrJref1NClstn) insert(items, SCRJREF1NCLSTN);
	if (scrJref1NPreset == comp->scrJref1NPreset) insert(items, SCRJREF1NPRESET);
	if (scrJref1NCall == comp->scrJref1NCall) insert(items, SCRJREF1NCALL);
	if (scrJref1NOp == comp->scrJref1NOp) insert(items, SCRJREF1NOP);
	if (scrJrefSup1NJob == comp->scrJrefSup1NJob) insert(items, SCRJREFSUP1NJOB);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWzemJobRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NCLSTN, SCRJREF1NPRESET, SCRJREF1NCALL, SCRJREF1NOP, SCRJREFSUP1NJOB, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobRec::Tag
 ******************************************************************************/

PnlWzemJobRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWzemJobRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemJobRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemJobRec::DpchAppDo
 ******************************************************************************/

PnlWzemJobRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemJobRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemJobRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobRec::DpchEngData
 ******************************************************************************/

PnlWzemJobRec::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMJOBRECDATA)
		{
};

string PnlWzemJobRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemJobRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
