/**
	* \file PnlWzemNavPre_blks.cpp
	* job handler for job PnlWzemNavPre (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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

void PnlWzemNavPre::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemNavPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrd"] = TxtPrd;
};

void PnlWzemNavPre::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrd", TxtPrd);
	xmlTextWriterEndElement(wr);
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

void PnlWzemNavPre::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNavPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtPrdAvail"] = TxtPrdAvail;
};

void PnlWzemNavPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNavPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxtPrdAvail", TxtPrdAvail);
	xmlTextWriterEndElement(wr);
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

void PnlWzemNavPre::Tag::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzemNavPre";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["CptPrd"] = "monitoring period";
	};
};

void PnlWzemNavPre::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "monitoring period");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavPre::DpchAppDo
 ******************************************************************************/

PnlWzemNavPre::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVPREDO)
		{
	ixVDo = 0;
};

string PnlWzemNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavPre::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemNavPreDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzemNavPre::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemNavPreDo");
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
 class PnlWzemNavPre::DpchEngData
 ******************************************************************************/

PnlWzemNavPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVPREDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavPre::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemNavPre::DpchEngData::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemNavPreData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzemVLocale, me);
};

void PnlWzemNavPre::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemNavPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};
