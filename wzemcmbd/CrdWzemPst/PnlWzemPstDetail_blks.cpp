/**
	* \file PnlWzemPstDetail_blks.cpp
	* job handler for job PnlWzemPstDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemPstDetail::VecVDo
 ******************************************************************************/

uint PnlWzemPstDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;

	return(0);
};

string PnlWzemPstDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");

	return("");
};

/******************************************************************************
 class PnlWzemPstDetail::ContIac
 ******************************************************************************/

PnlWzemPstDetail::ContIac::ContIac(
			const string& TxfPst
			, const string& TxfSta
			, const string& TxfSto
			, const string& TxfArg
		) :
			Block()
		{
	this->TxfPst = TxfPst;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->TxfArg = TxfArg;

	mask = {TXFPST, TXFSTA, TXFSTO, TXFARG};
};

bool PnlWzemPstDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemPstDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemPstDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPst", TxfPst)) add(TXFPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfArg", TxfArg)) add(TXFARG);
	};

	return basefound;
};

void PnlWzemPstDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemPstDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemPstDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfPst", TxfPst);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeStringAttr(wr, itemtag, "sref", "TxfArg", TxfArg);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemPstDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfPst == comp->TxfPst) insert(items, TXFPST);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (TxfArg == comp->TxfArg) insert(items, TXFARG);

	return(items);
};

set<uint> PnlWzemPstDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFPST, TXFSTA, TXFSTO, TXFARG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPstDetail::ContInf
 ******************************************************************************/

PnlWzemPstDetail::ContInf::ContInf(
			const string& TxtJob
		) :
			Block()
		{
	this->TxtJob = TxtJob;

	mask = {TXTJOB};
};

void PnlWzemPstDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemPstDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemPstDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtJob", TxtJob);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemPstDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);

	return(items);
};

set<uint> PnlWzemPstDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTJOB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPstDetail::StatApp
 ******************************************************************************/

void PnlWzemPstDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemPstDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemPstDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemPstDetail::StatShr
 ******************************************************************************/

PnlWzemPstDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxfPstActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxfArgActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxfPstActive = TxfPstActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxfArgActive = TxfArgActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFPSTACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFARGACTIVE};
};

void PnlWzemPstDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemPstDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemPstDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtJobActive", TxtJobActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewAvail", ButJobViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfPstActive", TxfPstActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfArgActive", TxfArgActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemPstDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxfPstActive == comp->TxfPstActive) insert(items, TXFPSTACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxfArgActive == comp->TxfArgActive) insert(items, TXFARGACTIVE);

	return(items);
};

set<uint> PnlWzemPstDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFPSTACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFARGACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPstDetail::Tag
 ******************************************************************************/

void PnlWzemPstDetail::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemPstDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemPstDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptJob", "job");
			writeStringAttr(wr, itemtag, "sref", "CptPst", "type");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "added");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "removed");
			writeStringAttr(wr, itemtag, "sref", "CptArg", "argument");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::DETAIL, ixWzemVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemPstDetail::DpchAppData
 ******************************************************************************/

PnlWzemPstDetail::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMPSTDETAILDATA)
		{
};

string PnlWzemPstDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPstDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemPstDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWzemPstDetail::DpchAppDo
 ******************************************************************************/

PnlWzemPstDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMPSTDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzemPstDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPstDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemPstDetailDo");
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
 class PnlWzemPstDetail::DpchEngData
 ******************************************************************************/

PnlWzemPstDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMPSTDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemPstDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPstDetail::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemPstDetail::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemPstDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};







