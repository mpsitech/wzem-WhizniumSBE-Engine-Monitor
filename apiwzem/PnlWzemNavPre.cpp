/**
	* \file PnlWzemNavPre.cpp
	* API code for job PnlWzemNavPre (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "PnlWzemNavPre.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemNavPre::VecVDo
 ******************************************************************************/

uint PnlWzemNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butprdremoveclick") return BUTPRDREMOVECLICK;

	return(0);
};

string PnlWzemNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRDREMOVECLICK) return("ButPrdRemoveClick");

	return("");
};

/******************************************************************************
 class PnlWzemNavPre::ContInf
 ******************************************************************************/

PnlWzemNavPre::ContInf::ContInf(
			const string& TxtPrd
		) :
			Block()
		{
	this->TxtPrd = TxtPrd;

	mask = {TXTPRD};
};

bool PnlWzemNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrd", TxtPrd)) add(TXTPRD);
	};

	return basefound;
};

set<uint> PnlWzemNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);

	return(items);
};

set<uint> PnlWzemNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavPre::StatShr
 ******************************************************************************/

PnlWzemNavPre::StatShr::StatShr(
			const bool TxtPrdAvail
		) :
			Block()
		{
	this->TxtPrdAvail = TxtPrdAvail;

	mask = {TXTPRDAVAIL};
};

bool PnlWzemNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrdAvail", TxtPrdAvail)) add(TXTPRDAVAIL);
	};

	return basefound;
};

set<uint> PnlWzemNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtPrdAvail == comp->TxtPrdAvail) insert(items, TXTPRDAVAIL);

	return(items);
};

set<uint> PnlWzemNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavPre::Tag
 ******************************************************************************/

PnlWzemNavPre::Tag::Tag(
			const string& CptPrd
		) :
			Block()
		{
	this->CptPrd = CptPrd;

	mask = {CPTPRD};
};

bool PnlWzemNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemNavPre::DpchAppDo
 ******************************************************************************/

PnlWzemNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVPREDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavPre::DpchEngData
 ******************************************************************************/

PnlWzemNavPre::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVPREDATA)
		{
};

string PnlWzemNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};

