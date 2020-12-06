/**
	* \file PnlWzemClnDetail.cpp
	* API code for job PnlWzemClnDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzemClnDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemClnDetail::VecVDo
 ******************************************************************************/

uint PnlWzemClnDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "buttjbviewclick") return BUTTJBVIEWCLICK;

	return(0);
};

string PnlWzemClnDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTTJBVIEWCLICK) return("ButTjbViewClick");

	return("");
};

/******************************************************************************
 class PnlWzemClnDetail::ContIac
 ******************************************************************************/

PnlWzemClnDetail::ContIac::ContIac(
			const string& TxfCal
			, const string& TxfSge
			, const string& TxfSta
			, const string& TxfSto
			, const uint numFPupTrg
			, const uint numFPupJms
			, const vector<uint>& numsFLstAms
			, const string& TxfArg
			, const uint numFPupJat
		) :
			Block()
		{
	this->TxfCal = TxfCal;
	this->TxfSge = TxfSge;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->numFPupTrg = numFPupTrg;
	this->numFPupJms = numFPupJms;
	this->numsFLstAms = numsFLstAms;
	this->TxfArg = TxfArg;
	this->numFPupJat = numFPupJat;

	mask = {TXFCAL, TXFSGE, TXFSTA, TXFSTO, NUMFPUPTRG, NUMFPUPJMS, NUMSFLSTAMS, TXFARG, NUMFPUPJAT};
};

bool PnlWzemClnDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemClnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemClnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCal", TxfCal)) add(TXFCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSge", TxfSge)) add(TXFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTrg", numFPupTrg)) add(NUMFPUPTRG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJms", numFPupJms)) add(NUMFPUPJMS);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstAms", numsFLstAms)) add(NUMSFLSTAMS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfArg", TxfArg)) add(TXFARG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJat", numFPupJat)) add(NUMFPUPJAT);
	};

	return basefound;
};

void PnlWzemClnDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemClnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemClnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfCal", TxfCal);
		writeStringAttr(wr, itemtag, "sref", "TxfSge", TxfSge);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeUintAttr(wr, itemtag, "sref", "numFPupTrg", numFPupTrg);
		writeUintAttr(wr, itemtag, "sref", "numFPupJms", numFPupJms);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstAms", numsFLstAms);
		writeStringAttr(wr, itemtag, "sref", "TxfArg", TxfArg);
		writeUintAttr(wr, itemtag, "sref", "numFPupJat", numFPupJat);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemClnDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfCal == comp->TxfCal) insert(items, TXFCAL);
	if (TxfSge == comp->TxfSge) insert(items, TXFSGE);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (numFPupTrg == comp->numFPupTrg) insert(items, NUMFPUPTRG);
	if (numFPupJms == comp->numFPupJms) insert(items, NUMFPUPJMS);
	if (compareUintvec(numsFLstAms, comp->numsFLstAms)) insert(items, NUMSFLSTAMS);
	if (TxfArg == comp->TxfArg) insert(items, TXFARG);
	if (numFPupJat == comp->numFPupJat) insert(items, NUMFPUPJAT);

	return(items);
};

set<uint> PnlWzemClnDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCAL, TXFSGE, TXFSTA, TXFSTO, NUMFPUPTRG, NUMFPUPJMS, NUMSFLSTAMS, TXFARG, NUMFPUPJAT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemClnDetail::ContInf
 ******************************************************************************/

PnlWzemClnDetail::ContInf::ContInf(
			const string& TxtJob
			, const string& TxtTjb
			, const string& TxtAms
		) :
			Block()
		{
	this->TxtJob = TxtJob;
	this->TxtTjb = TxtTjb;
	this->TxtAms = TxtAms;

	mask = {TXTJOB, TXTTJB, TXTAMS};
};

bool PnlWzemClnDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemClnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemClnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtJob", TxtJob)) add(TXTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTjb", TxtTjb)) add(TXTTJB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAms", TxtAms)) add(TXTAMS);
	};

	return basefound;
};

set<uint> PnlWzemClnDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);
	if (TxtTjb == comp->TxtTjb) insert(items, TXTTJB);
	if (TxtAms == comp->TxtAms) insert(items, TXTAMS);

	return(items);
};

set<uint> PnlWzemClnDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTJOB, TXTTJB, TXTAMS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemClnDetail::StatApp
 ******************************************************************************/

PnlWzemClnDetail::StatApp::StatApp(
			const uint ixWzemVExpstate
			, const bool LstAmsAlt
			, const uint LstAmsNumFirstdisp
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->LstAmsAlt = LstAmsAlt;
	this->LstAmsNumFirstdisp = LstAmsNumFirstdisp;

	mask = {IXWZEMVEXPSTATE, LSTAMSALT, LSTAMSNUMFIRSTDISP};
};

bool PnlWzemClnDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemClnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemClnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAmsAlt", LstAmsAlt)) add(LSTAMSALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAmsNumFirstdisp", LstAmsNumFirstdisp)) add(LSTAMSNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzemClnDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (LstAmsAlt == comp->LstAmsAlt) insert(items, LSTAMSALT);
	if (LstAmsNumFirstdisp == comp->LstAmsNumFirstdisp) insert(items, LSTAMSNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzemClnDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, LSTAMSALT, LSTAMSNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemClnDetail::StatShr
 ******************************************************************************/

PnlWzemClnDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxfCalActive
			, const bool TxfSgeActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool PupTrgActive
			, const bool PupJmsActive
			, const bool TxtTjbActive
			, const bool ButTjbViewAvail
			, const bool ButTjbViewActive
			, const bool LstAmsActive
			, const bool TxfArgActive
			, const bool PupJatActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxfCalActive = TxfCalActive;
	this->TxfSgeActive = TxfSgeActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->PupTrgActive = PupTrgActive;
	this->PupJmsActive = PupJmsActive;
	this->TxtTjbActive = TxtTjbActive;
	this->ButTjbViewAvail = ButTjbViewAvail;
	this->ButTjbViewActive = ButTjbViewActive;
	this->LstAmsActive = LstAmsActive;
	this->TxfArgActive = TxfArgActive;
	this->PupJatActive = PupJatActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFCALACTIVE, TXFSGEACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, PUPTRGACTIVE, PUPJMSACTIVE, TXTTJBACTIVE, BUTTJBVIEWAVAIL, BUTTJBVIEWACTIVE, LSTAMSACTIVE, TXFARGACTIVE, PUPJATACTIVE};
};

bool PnlWzemClnDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemClnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemClnDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtJobActive", TxtJobActive)) add(TXTJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", ButJobViewAvail)) add(BUTJOBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCalActive", TxfCalActive)) add(TXFCALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSgeActive", TxfSgeActive)) add(TXFSGEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTrgActive", PupTrgActive)) add(PUPTRGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJmsActive", PupJmsActive)) add(PUPJMSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTjbActive", TxtTjbActive)) add(TXTTJBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTjbViewAvail", ButTjbViewAvail)) add(BUTTJBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTjbViewActive", ButTjbViewActive)) add(BUTTJBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAmsActive", LstAmsActive)) add(LSTAMSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfArgActive", TxfArgActive)) add(TXFARGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJatActive", PupJatActive)) add(PUPJATACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemClnDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxfCalActive == comp->TxfCalActive) insert(items, TXFCALACTIVE);
	if (TxfSgeActive == comp->TxfSgeActive) insert(items, TXFSGEACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (PupTrgActive == comp->PupTrgActive) insert(items, PUPTRGACTIVE);
	if (PupJmsActive == comp->PupJmsActive) insert(items, PUPJMSACTIVE);
	if (TxtTjbActive == comp->TxtTjbActive) insert(items, TXTTJBACTIVE);
	if (ButTjbViewAvail == comp->ButTjbViewAvail) insert(items, BUTTJBVIEWAVAIL);
	if (ButTjbViewActive == comp->ButTjbViewActive) insert(items, BUTTJBVIEWACTIVE);
	if (LstAmsActive == comp->LstAmsActive) insert(items, LSTAMSACTIVE);
	if (TxfArgActive == comp->TxfArgActive) insert(items, TXFARGACTIVE);
	if (PupJatActive == comp->PupJatActive) insert(items, PUPJATACTIVE);

	return(items);
};

set<uint> PnlWzemClnDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFCALACTIVE, TXFSGEACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, PUPTRGACTIVE, PUPJMSACTIVE, TXTTJBACTIVE, BUTTJBVIEWAVAIL, BUTTJBVIEWACTIVE, LSTAMSACTIVE, TXFARGACTIVE, PUPJATACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemClnDetail::Tag
 ******************************************************************************/

PnlWzemClnDetail::Tag::Tag(
			const string& Cpt
			, const string& CptJob
			, const string& CptCal
			, const string& CptSge
			, const string& CptSta
			, const string& CptSto
			, const string& CptTrg
			, const string& CptJms
			, const string& CptTjb
			, const string& CptAms
			, const string& CptArg
			, const string& CptJat
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptJob = CptJob;
	this->CptCal = CptCal;
	this->CptSge = CptSge;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptTrg = CptTrg;
	this->CptJms = CptJms;
	this->CptTjb = CptTjb;
	this->CptAms = CptAms;
	this->CptArg = CptArg;
	this->CptJat = CptJat;

	mask = {CPT, CPTJOB, CPTCAL, CPTSGE, CPTSTA, CPTSTO, CPTTRG, CPTJMS, CPTTJB, CPTAMS, CPTARG, CPTJAT};
};

bool PnlWzemClnDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemClnDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemClnDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCal", CptCal)) add(CPTCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSge", CptSge)) add(CPTSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTrg", CptTrg)) add(CPTTRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJms", CptJms)) add(CPTJMS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTjb", CptTjb)) add(CPTTJB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAms", CptAms)) add(CPTAMS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptArg", CptArg)) add(CPTARG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJat", CptJat)) add(CPTJAT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemClnDetail::DpchAppData
 ******************************************************************************/

PnlWzemClnDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMCLNDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemClnDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemClnDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemClnDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemClnDetail::DpchAppDo
 ******************************************************************************/

PnlWzemClnDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMCLNDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemClnDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemClnDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemClnDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemClnDetail::DpchEngData
 ******************************************************************************/

PnlWzemClnDetail::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMCLNDETAILDATA)
		{
	feedFLstAms.tag = "FeedFLstAms";
	feedFPupJat.tag = "FeedFPupJat";
	feedFPupJms.tag = "FeedFPupJms";
	feedFPupTrg.tag = "FeedFPupTrg";
};

string PnlWzemClnDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTAMS)) ss.push_back("feedFLstAms");
	if (has(FEEDFPUPJAT)) ss.push_back("feedFPupJat");
	if (has(FEEDFPUPJMS)) ss.push_back("feedFPupJms");
	if (has(FEEDFPUPTRG)) ss.push_back("feedFPupTrg");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemClnDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemClnDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstAms.readXML(docctx, basexpath, true)) add(FEEDFLSTAMS);
		if (feedFPupJat.readXML(docctx, basexpath, true)) add(FEEDFPUPJAT);
		if (feedFPupJms.readXML(docctx, basexpath, true)) add(FEEDFPUPJMS);
		if (feedFPupTrg.readXML(docctx, basexpath, true)) add(FEEDFPUPTRG);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstAms.clear();
		feedFPupJat.clear();
		feedFPupJms.clear();
		feedFPupTrg.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

