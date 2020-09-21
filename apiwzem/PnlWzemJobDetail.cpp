/**
	* \file PnlWzemJobDetail.cpp
	* API code for job PnlWzemJobDetail (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "PnlWzemJobDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemJobDetail::VecVDo
 ******************************************************************************/

uint PnlWzemJobDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprdviewclick") return BUTPRDVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;

	return(0);
};

string PnlWzemJobDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");

	return("");
};

/******************************************************************************
 class PnlWzemJobDetail::ContIac
 ******************************************************************************/

PnlWzemJobDetail::ContIac::ContIac(
			const string& TxfJob
			, const string& TxfXjr
			, const string& TxfSta
			, const string& TxfSto
			, const bool ChkCls
			, const bool ChkSnc
			, const bool ChkDcl
			, const bool ChkStm
		) :
			Block()
		{
	this->TxfJob = TxfJob;
	this->TxfXjr = TxfXjr;
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->ChkCls = ChkCls;
	this->ChkSnc = ChkSnc;
	this->ChkDcl = ChkDcl;
	this->ChkStm = ChkStm;

	mask = {TXFJOB, TXFXJR, TXFSTA, TXFSTO, CHKCLS, CHKSNC, CHKDCL, CHKSTM};
};

bool PnlWzemJobDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemJobDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemJobDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfJob", TxfJob)) add(TXFJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXjr", TxfXjr)) add(TXFXJR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCls", ChkCls)) add(CHKCLS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkSnc", ChkSnc)) add(CHKSNC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkDcl", ChkDcl)) add(CHKDCL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkStm", ChkStm)) add(CHKSTM);
	};

	return basefound;
};

void PnlWzemJobDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemJobDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemJobDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfJob", TxfJob);
		writeStringAttr(wr, itemtag, "sref", "TxfXjr", TxfXjr);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeBoolAttr(wr, itemtag, "sref", "ChkCls", ChkCls);
		writeBoolAttr(wr, itemtag, "sref", "ChkSnc", ChkSnc);
		writeBoolAttr(wr, itemtag, "sref", "ChkDcl", ChkDcl);
		writeBoolAttr(wr, itemtag, "sref", "ChkStm", ChkStm);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemJobDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfJob == comp->TxfJob) insert(items, TXFJOB);
	if (TxfXjr == comp->TxfXjr) insert(items, TXFXJR);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (ChkCls == comp->ChkCls) insert(items, CHKCLS);
	if (ChkSnc == comp->ChkSnc) insert(items, CHKSNC);
	if (ChkDcl == comp->ChkDcl) insert(items, CHKDCL);
	if (ChkStm == comp->ChkStm) insert(items, CHKSTM);

	return(items);
};

set<uint> PnlWzemJobDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFJOB, TXFXJR, TXFSTA, TXFSTO, CHKCLS, CHKSNC, CHKDCL, CHKSTM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobDetail::ContInf
 ******************************************************************************/

PnlWzemJobDetail::ContInf::ContInf(
			const string& TxtPrd
			, const string& TxtSup
		) :
			Block()
		{
	this->TxtPrd = TxtPrd;
	this->TxtSup = TxtSup;

	mask = {TXTPRD, TXTSUP};
};

bool PnlWzemJobDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemJobDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemJobDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrd", TxtPrd)) add(TXTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
	};

	return basefound;
};

set<uint> PnlWzemJobDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);

	return(items);
};

set<uint> PnlWzemJobDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRD, TXTSUP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobDetail::StatApp
 ******************************************************************************/

PnlWzemJobDetail::StatApp::StatApp(
			const uint ixWzemVExpstate
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;

	mask = {IXWZEMVEXPSTATE};
};

bool PnlWzemJobDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemJobDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemJobDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzemJobDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);

	return(items);
};

set<uint> PnlWzemJobDetail::StatApp::diff(
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
 class PnlWzemJobDetail::StatShr
 ******************************************************************************/

PnlWzemJobDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtPrdActive
			, const bool ButPrdViewAvail
			, const bool ButPrdViewActive
			, const bool TxfJobActive
			, const bool TxfXjrActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool ChkClsActive
			, const bool ChkSncActive
			, const bool ChkDclActive
			, const bool ChkStmActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtPrdActive = TxtPrdActive;
	this->ButPrdViewAvail = ButPrdViewAvail;
	this->ButPrdViewActive = ButPrdViewActive;
	this->TxfJobActive = TxfJobActive;
	this->TxfXjrActive = TxfXjrActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->ChkClsActive = ChkClsActive;
	this->ChkSncActive = ChkSncActive;
	this->ChkDclActive = ChkDclActive;
	this->ChkStmActive = ChkStmActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFJOBACTIVE, TXFXJRACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, CHKCLSACTIVE, CHKSNCACTIVE, CHKDCLACTIVE, CHKSTMACTIVE};
};

bool PnlWzemJobDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemJobDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemJobDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrdActive", TxtPrdActive)) add(TXTPRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewAvail", ButPrdViewAvail)) add(BUTPRDVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", ButPrdViewActive)) add(BUTPRDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfJobActive", TxfJobActive)) add(TXFJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXjrActive", TxfXjrActive)) add(TXFXJRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkClsActive", ChkClsActive)) add(CHKCLSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkSncActive", ChkSncActive)) add(CHKSNCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkDclActive", ChkDclActive)) add(CHKDCLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkStmActive", ChkStmActive)) add(CHKSTMACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemJobDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtPrdActive == comp->TxtPrdActive) insert(items, TXTPRDACTIVE);
	if (ButPrdViewAvail == comp->ButPrdViewAvail) insert(items, BUTPRDVIEWAVAIL);
	if (ButPrdViewActive == comp->ButPrdViewActive) insert(items, BUTPRDVIEWACTIVE);
	if (TxfJobActive == comp->TxfJobActive) insert(items, TXFJOBACTIVE);
	if (TxfXjrActive == comp->TxfXjrActive) insert(items, TXFXJRACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (ChkClsActive == comp->ChkClsActive) insert(items, CHKCLSACTIVE);
	if (ChkSncActive == comp->ChkSncActive) insert(items, CHKSNCACTIVE);
	if (ChkDclActive == comp->ChkDclActive) insert(items, CHKDCLACTIVE);
	if (ChkStmActive == comp->ChkStmActive) insert(items, CHKSTMACTIVE);

	return(items);
};

set<uint> PnlWzemJobDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFJOBACTIVE, TXFXJRACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, CHKCLSACTIVE, CHKSNCACTIVE, CHKDCLACTIVE, CHKSTMACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobDetail::Tag
 ******************************************************************************/

PnlWzemJobDetail::Tag::Tag(
			const string& Cpt
			, const string& CptPrd
			, const string& CptJob
			, const string& CptXjr
			, const string& CptSta
			, const string& CptSto
			, const string& CptSup
			, const string& CptCls
			, const string& CptSnc
			, const string& CptDcl
			, const string& CptStm
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrd = CptPrd;
	this->CptJob = CptJob;
	this->CptXjr = CptXjr;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptSup = CptSup;
	this->CptCls = CptCls;
	this->CptSnc = CptSnc;
	this->CptDcl = CptDcl;
	this->CptStm = CptStm;

	mask = {CPT, CPTPRD, CPTJOB, CPTXJR, CPTSTA, CPTSTO, CPTSUP, CPTCLS, CPTSNC, CPTDCL, CPTSTM};
};

bool PnlWzemJobDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemJobDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemJobDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXjr", CptXjr)) add(CPTXJR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCls", CptCls)) add(CPTCLS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSnc", CptSnc)) add(CPTSNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDcl", CptDcl)) add(CPTDCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStm", CptStm)) add(CPTSTM);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemJobDetail::DpchAppData
 ******************************************************************************/

PnlWzemJobDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemJobDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemJobDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobDetail::DpchAppDo
 ******************************************************************************/

PnlWzemJobDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemJobDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemJobDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobDetail::DpchEngData
 ******************************************************************************/

PnlWzemJobDetail::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMJOBDETAILDATA)
		{
};

string PnlWzemJobDetail::DpchEngData::getSrefsMask() {
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

void PnlWzemJobDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemJobDetailData");
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

