/**
	* \file PnlWzemJobRec_blks.cpp
	* job handler for job PnlWzemJobRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

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

void PnlWzemJobRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemJobRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWzemJobRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NOp
			, const bool initdone1NCall
			, const bool initdone1NPreset
			, const bool initdone1NClstn
			, const bool initdoneSup1NJob
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemJobRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NOp", initdone1NOp);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NCall", initdone1NCall);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NPreset", initdone1NPreset);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NClstn", initdone1NClstn);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NJob", initdoneSup1NJob);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobRec::StatShr
 ******************************************************************************/

PnlWzemJobRec::StatShr::StatShr(
			const uint ixWzemVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NOp
			, const ubigint jref1NCall
			, const ubigint jref1NPreset
			, const ubigint jref1NClstn
			, const ubigint jrefSup1NJob
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NOp = jref1NOp;
	this->jref1NCall = jref1NCall;
	this->jref1NPreset = jref1NPreset;
	this->jref1NClstn = jref1NClstn;
	this->jrefSup1NJob = jrefSup1NJob;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZEMVEXPSTATE, JREFDETAIL, JREF1NOP, JREF1NCALL, JREF1NPRESET, JREF1NCLSTN, JREFSUP1NJOB, BUTREGULARIZEACTIVE};
};

void PnlWzemJobRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemJobRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NOp", Scr::scramble(jref1NOp));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NCall", Scr::scramble(jref1NCall));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NPreset", Scr::scramble(jref1NPreset));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NClstn", Scr::scramble(jref1NClstn));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NJob", Scr::scramble(jrefSup1NJob));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemJobRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NOp == comp->jref1NOp) insert(items, JREF1NOP);
	if (jref1NCall == comp->jref1NCall) insert(items, JREF1NCALL);
	if (jref1NPreset == comp->jref1NPreset) insert(items, JREF1NPRESET);
	if (jref1NClstn == comp->jref1NClstn) insert(items, JREF1NCLSTN);
	if (jrefSup1NJob == comp->jrefSup1NJob) insert(items, JREFSUP1NJOB);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWzemJobRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, JREFDETAIL, JREF1NOP, JREF1NCALL, JREF1NPRESET, JREF1NCLSTN, JREFSUP1NJOB, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobRec::Tag
 ******************************************************************************/

void PnlWzemJobRec::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemJobRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Job");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobRec::DpchAppDo
 ******************************************************************************/

PnlWzemJobRec::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBRECDO)
		{
	ixVDo = 0;
};

string PnlWzemJobRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemJobRecDo");
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
 class PnlWzemJobRec::DpchEngData
 ******************************************************************************/

PnlWzemJobRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMJOBRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemJobRec::DpchEngData::getSrefsMask() {
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

void PnlWzemJobRec::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemJobRec::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemJobRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};

