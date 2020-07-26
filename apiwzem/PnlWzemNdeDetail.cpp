/**
	* \file PnlWzemNdeDetail.cpp
	* API code for job PnlWzemNdeDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "PnlWzemNdeDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemNdeDetail::VecVDo
 ******************************************************************************/

uint PnlWzemNdeDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprdviewclick") return BUTPRDVIEWCLICK;

	return(0);
};

string PnlWzemNdeDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");

	return("");
};

/******************************************************************************
 class PnlWzemNdeDetail::ContIac
 ******************************************************************************/

PnlWzemNdeDetail::ContIac::ContIac(
			const string& TxfXnr
			, const string& TxfIp
			, const string& TxfSta
			, const string& TxfSto
			, const string& TxfPrt
			, const string& TxfOrn
		) :
			Block()
		{
	this->TxfXnr = TxfXnr;
	this->TxfIp = TxfIp;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->TxfPrt = TxfPrt;
	this->TxfOrn = TxfOrn;

	mask = {TXFXNR, TXFIP, TXFSTA, TXFSTO, TXFPRT, TXFORN};
};

bool PnlWzemNdeDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemNdeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemNdeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXnr", TxfXnr)) add(TXFXNR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIp", TxfIp)) add(TXFIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPrt", TxfPrt)) add(TXFPRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOrn", TxfOrn)) add(TXFORN);
	};

	return basefound;
};

void PnlWzemNdeDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemNdeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemNdeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfXnr", TxfXnr);
		writeStringAttr(wr, itemtag, "sref", "TxfIp", TxfIp);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeStringAttr(wr, itemtag, "sref", "TxfPrt", TxfPrt);
		writeStringAttr(wr, itemtag, "sref", "TxfOrn", TxfOrn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNdeDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfXnr == comp->TxfXnr) insert(items, TXFXNR);
	if (TxfIp == comp->TxfIp) insert(items, TXFIP);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (TxfPrt == comp->TxfPrt) insert(items, TXFPRT);
	if (TxfOrn == comp->TxfOrn) insert(items, TXFORN);

	return(items);
};

set<uint> PnlWzemNdeDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFXNR, TXFIP, TXFSTA, TXFSTO, TXFPRT, TXFORN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNdeDetail::ContInf
 ******************************************************************************/

PnlWzemNdeDetail::ContInf::ContInf(
			const string& TxtPrd
		) :
			Block()
		{
	this->TxtPrd = TxtPrd;

	mask = {TXTPRD};
};

bool PnlWzemNdeDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemNdeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemNdeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrd", TxtPrd)) add(TXTPRD);
	};

	return basefound;
};

set<uint> PnlWzemNdeDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);

	return(items);
};

set<uint> PnlWzemNdeDetail::ContInf::diff(
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
 class PnlWzemNdeDetail::StatApp
 ******************************************************************************/

PnlWzemNdeDetail::StatApp::StatApp(
			const uint ixWzemVExpstate
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;

	mask = {IXWZEMVEXPSTATE};
};

bool PnlWzemNdeDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemNdeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemNdeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzemNdeDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);

	return(items);
};

set<uint> PnlWzemNdeDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNdeDetail::StatShr
 ******************************************************************************/

PnlWzemNdeDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtPrdActive
			, const bool ButPrdViewAvail
			, const bool ButPrdViewActive
			, const bool TxfXnrActive
			, const bool TxfIpActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxfPrtActive
			, const bool TxfOrnActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtPrdActive = TxtPrdActive;
	this->ButPrdViewAvail = ButPrdViewAvail;
	this->ButPrdViewActive = ButPrdViewActive;
	this->TxfXnrActive = TxfXnrActive;
	this->TxfIpActive = TxfIpActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxfPrtActive = TxfPrtActive;
	this->TxfOrnActive = TxfOrnActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFXNRACTIVE, TXFIPACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFPRTACTIVE, TXFORNACTIVE};
};

bool PnlWzemNdeDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemNdeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemNdeDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrdActive", TxtPrdActive)) add(TXTPRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewAvail", ButPrdViewAvail)) add(BUTPRDVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", ButPrdViewActive)) add(BUTPRDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXnrActive", TxfXnrActive)) add(TXFXNRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfIpActive", TxfIpActive)) add(TXFIPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPrtActive", TxfPrtActive)) add(TXFPRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOrnActive", TxfOrnActive)) add(TXFORNACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemNdeDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtPrdActive == comp->TxtPrdActive) insert(items, TXTPRDACTIVE);
	if (ButPrdViewAvail == comp->ButPrdViewAvail) insert(items, BUTPRDVIEWAVAIL);
	if (ButPrdViewActive == comp->ButPrdViewActive) insert(items, BUTPRDVIEWACTIVE);
	if (TxfXnrActive == comp->TxfXnrActive) insert(items, TXFXNRACTIVE);
	if (TxfIpActive == comp->TxfIpActive) insert(items, TXFIPACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxfPrtActive == comp->TxfPrtActive) insert(items, TXFPRTACTIVE);
	if (TxfOrnActive == comp->TxfOrnActive) insert(items, TXFORNACTIVE);

	return(items);
};

set<uint> PnlWzemNdeDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFXNRACTIVE, TXFIPACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFPRTACTIVE, TXFORNACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNdeDetail::Tag
 ******************************************************************************/

PnlWzemNdeDetail::Tag::Tag(
			const string& Cpt
			, const string& CptPrd
			, const string& CptXnr
			, const string& CptIp
			, const string& CptSta
			, const string& CptSto
			, const string& CptPrt
			, const string& CptOrn
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrd = CptPrd;
	this->CptXnr = CptXnr;
	this->CptIp = CptIp;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptPrt = CptPrt;
	this->CptOrn = CptOrn;

	mask = {CPT, CPTPRD, CPTXNR, CPTIP, CPTSTA, CPTSTO, CPTPRT, CPTORN};
};

bool PnlWzemNdeDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemNdeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemNdeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXnr", CptXnr)) add(CPTXNR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIp", CptIp)) add(CPTIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrt", CptPrt)) add(CPTPRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOrn", CptOrn)) add(CPTORN);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemNdeDetail::DpchAppData
 ******************************************************************************/

PnlWzemNdeDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNDEDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemNdeDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNdeDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNdeDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNdeDetail::DpchAppDo
 ******************************************************************************/

PnlWzemNdeDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNDEDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemNdeDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNdeDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNdeDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNdeDetail::DpchEngData
 ******************************************************************************/

PnlWzemNdeDetail::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNDEDETAILDATA)
		{
};

string PnlWzemNdeDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNdeDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemNdeDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

