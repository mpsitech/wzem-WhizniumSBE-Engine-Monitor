/**
	* \file PnlWzemPrsDetail.cpp
	* API code for job PnlWzemPrsDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "PnlWzemPrsDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemPrsDetail::VecVDo
 ******************************************************************************/

uint PnlWzemPrsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjeditclick") return BUTJEDITCLICK;

	return(0);
};

string PnlWzemPrsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJEDITCLICK) return("ButJEditClick");

	return("");
};

/******************************************************************************
 class PnlWzemPrsDetail::ContIac
 ******************************************************************************/

PnlWzemPrsDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfFnm
			, const uint numFPupJ
			, const vector<uint>& numsFLstDrv
			, const uint numFPupSex
			, const string& TxfTel
			, const string& TxfEml
			, const string& TxfSal
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->TxfFnm = TxfFnm;
	this->numFPupJ = numFPupJ;
	this->numsFLstDrv = numsFLstDrv;
	this->numFPupSex = numFPupSex;
	this->TxfTel = TxfTel;
	this->TxfEml = TxfEml;
	this->TxfSal = TxfSal;

	mask = {TXFTIT, TXFFNM, NUMFPUPJ, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
};

bool PnlWzemPrsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", numsFLstDrv)) add(NUMSFLSTDRV);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSex", numFPupSex)) add(NUMFPUPSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTel", TxfTel)) add(TXFTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEml", TxfEml)) add(TXFEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSal", TxfSal)) add(TXFSAL);
	};

	return basefound;
};

void PnlWzemPrsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
		writeUintAttr(wr, itemtag, "sref", "numFPupSex", numFPupSex);
		writeStringAttr(wr, itemtag, "sref", "TxfTel", TxfTel);
		writeStringAttr(wr, itemtag, "sref", "TxfEml", TxfEml);
		writeStringAttr(wr, itemtag, "sref", "TxfSal", TxfSal);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemPrsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (compareUintvec(numsFLstDrv, comp->numsFLstDrv)) insert(items, NUMSFLSTDRV);
	if (numFPupSex == comp->numFPupSex) insert(items, NUMFPUPSEX);
	if (TxfTel == comp->TxfTel) insert(items, TXFTEL);
	if (TxfEml == comp->TxfEml) insert(items, TXFEML);
	if (TxfSal == comp->TxfSal) insert(items, TXFSAL);

	return(items);
};

set<uint> PnlWzemPrsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFFNM, NUMFPUPJ, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPrsDetail::ContInf
 ******************************************************************************/

PnlWzemPrsDetail::ContInf::ContInf(
			const string& TxtLnm
			, const string& TxtDrv
		) :
			Block()
		{
	this->TxtLnm = TxtLnm;
	this->TxtDrv = TxtDrv;

	mask = {TXTLNM, TXTDRV};
};

bool PnlWzemPrsDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLnm", TxtLnm)) add(TXTLNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtDrv", TxtDrv)) add(TXTDRV);
	};

	return basefound;
};

set<uint> PnlWzemPrsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtLnm == comp->TxtLnm) insert(items, TXTLNM);
	if (TxtDrv == comp->TxtDrv) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlWzemPrsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTLNM, TXTDRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPrsDetail::StatApp
 ******************************************************************************/

PnlWzemPrsDetail::StatApp::StatApp(
			const uint ixWzemVExpstate
			, const bool LstDrvAlt
			, const uint LstDrvNumFirstdisp
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->LstDrvAlt = LstDrvAlt;
	this->LstDrvNumFirstdisp = LstDrvNumFirstdisp;

	mask = {IXWZEMVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
};

bool PnlWzemPrsDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvAlt", LstDrvAlt)) add(LSTDRVALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvNumFirstdisp", LstDrvNumFirstdisp)) add(LSTDRVNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzemPrsDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (LstDrvAlt == comp->LstDrvAlt) insert(items, LSTDRVALT);
	if (LstDrvNumFirstdisp == comp->LstDrvNumFirstdisp) insert(items, LSTDRVNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzemPrsDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPrsDetail::StatShr
 ******************************************************************************/

PnlWzemPrsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfTitActive
			, const bool TxfFnmActive
			, const bool PupJActive
			, const bool ButJEditAvail
			, const bool TxtLnmActive
			, const bool LstDrvActive
			, const bool PupSexActive
			, const bool TxfTelActive
			, const bool TxfEmlActive
			, const bool TxfSalActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfTitActive = TxfTitActive;
	this->TxfFnmActive = TxfFnmActive;
	this->PupJActive = PupJActive;
	this->ButJEditAvail = ButJEditAvail;
	this->TxtLnmActive = TxtLnmActive;
	this->LstDrvActive = LstDrvActive;
	this->PupSexActive = PupSexActive;
	this->TxfTelActive = TxfTelActive;
	this->TxfEmlActive = TxfEmlActive;
	this->TxfSalActive = TxfSalActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
};

bool PnlWzemPrsDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemPrsDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFnmActive", TxfFnmActive)) add(TXFFNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJActive", PupJActive)) add(PUPJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLnmActive", TxtLnmActive)) add(TXTLNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDrvActive", LstDrvActive)) add(LSTDRVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSexActive", PupSexActive)) add(PUPSEXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTelActive", TxfTelActive)) add(TXFTELACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfEmlActive", TxfEmlActive)) add(TXFEMLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSalActive", TxfSalActive)) add(TXFSALACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemPrsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfFnmActive == comp->TxfFnmActive) insert(items, TXFFNMACTIVE);
	if (PupJActive == comp->PupJActive) insert(items, PUPJACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (TxtLnmActive == comp->TxtLnmActive) insert(items, TXTLNMACTIVE);
	if (LstDrvActive == comp->LstDrvActive) insert(items, LSTDRVACTIVE);
	if (PupSexActive == comp->PupSexActive) insert(items, PUPSEXACTIVE);
	if (TxfTelActive == comp->TxfTelActive) insert(items, TXFTELACTIVE);
	if (TxfEmlActive == comp->TxfEmlActive) insert(items, TXFEMLACTIVE);
	if (TxfSalActive == comp->TxfSalActive) insert(items, TXFSALACTIVE);

	return(items);
};

set<uint> PnlWzemPrsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemPrsDetail::Tag
 ******************************************************************************/

PnlWzemPrsDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTit
			, const string& CptFnm
			, const string& CptLnm
			, const string& CptDrv
			, const string& CptSex
			, const string& CptTel
			, const string& CptEml
			, const string& CptSal
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptTit = CptTit;
	this->CptFnm = CptFnm;
	this->CptLnm = CptLnm;
	this->CptDrv = CptDrv;
	this->CptSex = CptSex;
	this->CptTel = CptTel;
	this->CptEml = CptEml;
	this->CptSal = CptSal;

	mask = {CPT, CPTTIT, CPTFNM, CPTLNM, CPTDRV, CPTSEX, CPTTEL, CPTEML, CPTSAL};
};

bool PnlWzemPrsDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnm", CptFnm)) add(CPTFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLnm", CptLnm)) add(CPTLNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDrv", CptDrv)) add(CPTDRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSex", CptSex)) add(CPTSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTel", CptTel)) add(CPTTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEml", CptEml)) add(CPTEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSal", CptSal)) add(CPTSAL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemPrsDetail::DpchAppData
 ******************************************************************************/

PnlWzemPrsDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMPRSDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemPrsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPrsDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemPrsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemPrsDetail::DpchAppDo
 ******************************************************************************/

PnlWzemPrsDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMPRSDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemPrsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPrsDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemPrsDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemPrsDetail::DpchEngData
 ******************************************************************************/

PnlWzemPrsDetail::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMPRSDETAILDATA)
		{
	feedFLstDrv.tag = "FeedFLstDrv";
	feedFPupJ.tag = "FeedFPupJ";
	feedFPupSex.tag = "FeedFPupSex";
};

string PnlWzemPrsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDRV)) ss.push_back("feedFLstDrv");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPSEX)) ss.push_back("feedFPupSex");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemPrsDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemPrsDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstDrv.readXML(docctx, basexpath, true)) add(FEEDFLSTDRV);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (feedFPupSex.readXML(docctx, basexpath, true)) add(FEEDFPUPSEX);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstDrv.clear();
		feedFPupJ.clear();
		feedFPupSex.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

