/**
	* \file PnlWzemOpxDetail_blks.cpp
	* job handler for job PnlWzemOpxDetail (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemOpxDetail::VecVDo
 ******************************************************************************/

uint PnlWzemOpxDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;

	return(0);
};

string PnlWzemOpxDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");

	return("");
};

/******************************************************************************
 class PnlWzemOpxDetail::ContIac
 ******************************************************************************/

PnlWzemOpxDetail::ContIac::ContIac(
			const string& TxfXor
			, const string& TxfSta
			, const string& TxfSto
		) :
			Block()
		{
	this->TxfXor = TxfXor;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;

	mask = {TXFXOR, TXFSTA, TXFSTO};
};

bool PnlWzemOpxDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemOpxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXor", TxfXor)) add(TXFXOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
	};

	return basefound;
};

void PnlWzemOpxDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfXor", TxfXor);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemOpxDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfXor == comp->TxfXor) insert(items, TXFXOR);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);

	return(items);
};

set<uint> PnlWzemOpxDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFXOR, TXFSTA, TXFSTO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemOpxDetail::ContInf
 ******************************************************************************/

PnlWzemOpxDetail::ContInf::ContInf(
			const string& TxtJob
		) :
			Block()
		{
	this->TxtJob = TxtJob;

	mask = {TXTJOB};
};

void PnlWzemOpxDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtJob", TxtJob);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemOpxDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);

	return(items);
};

set<uint> PnlWzemOpxDetail::ContInf::diff(
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
 class PnlWzemOpxDetail::StatApp
 ******************************************************************************/

void PnlWzemOpxDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemOpxDetail::StatShr
 ******************************************************************************/

PnlWzemOpxDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxfXorActive
			, const bool TxfStaActive
			, const bool TxfStoActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxfXorActive = TxfXorActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFXORACTIVE, TXFSTAACTIVE, TXFSTOACTIVE};
};

void PnlWzemOpxDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtJobActive", TxtJobActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewAvail", ButJobViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXorActive", TxfXorActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemOpxDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxfXorActive == comp->TxfXorActive) insert(items, TXFXORACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);

	return(items);
};

set<uint> PnlWzemOpxDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFXORACTIVE, TXFSTAACTIVE, TXFSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemOpxDetail::Tag
 ******************************************************************************/

void PnlWzemOpxDetail::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptJob", "job");
			writeStringAttr(wr, itemtag, "sref", "CptXor", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "added");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "removed");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::DETAIL, ixWzemVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemOpxDetail::DpchAppData
 ******************************************************************************/

PnlWzemOpxDetail::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMOPXDETAILDATA)
		{
};

string PnlWzemOpxDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemOpxDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemOpxDetailData");
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
 class PnlWzemOpxDetail::DpchAppDo
 ******************************************************************************/

PnlWzemOpxDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMOPXDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzemOpxDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemOpxDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemOpxDetailDo");
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
 class PnlWzemOpxDetail::DpchEngData
 ******************************************************************************/

PnlWzemOpxDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMOPXDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemOpxDetail::DpchEngData::getSrefsMask() {
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

void PnlWzemOpxDetail::DpchEngData::merge(
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

void PnlWzemOpxDetail::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemOpxDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};

