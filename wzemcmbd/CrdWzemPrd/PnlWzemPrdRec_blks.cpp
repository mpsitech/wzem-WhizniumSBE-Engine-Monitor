/**
	* \file PnlWzemPrdRec_blks.cpp
	* job handler for job PnlWzemPrdRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemPrdRec::VecVDo
 ******************************************************************************/

uint PnlWzemPrdRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWzemPrdRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWzemPrdRec::ContInf
 ******************************************************************************/

PnlWzemPrdRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWzemPrdRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemPrdRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWzemPrdRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemPrdRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemPrdRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemPrdRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWzemPrdRec::ContInf::diff(
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
 class PnlWzemPrdRec::StatApp
 ******************************************************************************/

void PnlWzemPrdRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdone1NNode
			, const bool initdone1NJob
			, const bool initdone1NEvent
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemPrdRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdone1NNode"] = initdone1NNode;
	me["initdone1NJob"] = initdone1NJob;
	me["initdone1NEvent"] = initdone1NEvent;
};

void PnlWzemPrdRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NNode
			, const bool initdone1NJob
			, const bool initdone1NEvent
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemPrdRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemPrdRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NNode", initdone1NNode);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NJob", initdone1NJob);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NEvent", initdone1NEvent);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemPrdRec::StatShr
 ******************************************************************************/

PnlWzemPrdRec::StatShr::StatShr(
			const uint ixWzemVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NNode
			, const ubigint jref1NJob
			, const ubigint jref1NEvent
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NNode = jref1NNode;
	this->jref1NJob = jref1NJob;
	this->jref1NEvent = jref1NEvent;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZEMVEXPSTATE, JREFDETAIL, JREF1NNODE, JREF1NJOB, JREF1NEVENT, BUTREGULARIZEACTIVE};
};

void PnlWzemPrdRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemPrdRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzemVExpstate"] = VecWzemVExpstate::getSref(ixWzemVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJref1NNode"] = Scr::scramble(jref1NNode);
	me["scrJref1NJob"] = Scr::scramble(jref1NJob);
	me["scrJref1NEvent"] = Scr::scramble(jref1NEvent);
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWzemPrdRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemPrdRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemPrdRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NNode", Scr::scramble(jref1NNode));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NJob", Scr::scramble(jref1NJob));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NEvent", Scr::scramble(jref1NEvent));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemPrdRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NNode == comp->jref1NNode) insert(items, JREF1NNODE);
	if (jref1NJob == comp->jref1NJob) insert(items, JREF1NJOB);
	if (jref1NEvent == comp->jref1NEvent) insert(items, JREF1NEVENT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWzemPrdRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, JREFDETAIL, JREF1NNODE, JREF1NJOB, JREF1NEVENT, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPrdRec::Tag
 ******************************************************************************/

void PnlWzemPrdRec::Tag::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzemPrdRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["Cpt"] = "Monitoring period";
	};
};

void PnlWzemPrdRec::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemPrdRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemPrdRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Monitoring period");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemPrdRec::DpchAppDo
 ******************************************************************************/

PnlWzemPrdRec::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMPRDRECDO)
		{
	ixVDo = 0;
};

string PnlWzemPrdRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPrdRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemPrdRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzemPrdRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemPrdRecDo");
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
 class PnlWzemPrdRec::DpchEngData
 ******************************************************************************/

PnlWzemPrdRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMPRDRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemPrdRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPrdRec::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemPrdRec::DpchEngData::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemPrdRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzemVLocale, me);
};

void PnlWzemPrdRec::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemPrdRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};
