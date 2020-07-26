/**
	* \file PnlWzemJobDetail_blks.cpp
	* job handler for job PnlWzemJobDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

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

void PnlWzemJobDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemJobDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemJobDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrd", TxtPrd);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
	xmlTextWriterEndElement(wr);
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

void PnlWzemJobDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemJobDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemJobDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
	xmlTextWriterEndElement(wr);
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

void PnlWzemJobDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemJobDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemJobDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrdActive", TxtPrdActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrdViewAvail", ButPrdViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrdViewActive", ButPrdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfJobActive", TxfJobActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXjrActive", TxfXjrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkClsActive", ChkClsActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkSncActive", ChkSncActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkDclActive", ChkDclActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkStmActive", ChkStmActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzemJobDetail::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemJobDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemJobDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "monitoring period");
			writeStringAttr(wr, itemtag, "sref", "CptJob", "type");
			writeStringAttr(wr, itemtag, "sref", "CptXjr", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "added");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "removed");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super job");
			writeStringAttr(wr, itemtag, "sref", "CptCls", "client/server");
			writeStringAttr(wr, itemtag, "sref", "CptSnc", "client");
			writeStringAttr(wr, itemtag, "sref", "CptDcl", "dispatch collector");
			writeStringAttr(wr, itemtag, "sref", "CptStm", "stub manager");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::DETAIL, ixWzemVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobDetail::DpchAppData
 ******************************************************************************/

PnlWzemJobDetail::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBDETAILDATA)
		{
};

string PnlWzemJobDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemJobDetailData");
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
 class PnlWzemJobDetail::DpchAppDo
 ******************************************************************************/

PnlWzemJobDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzemJobDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemJobDetailDo");
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
 class PnlWzemJobDetail::DpchEngData
 ******************************************************************************/

PnlWzemJobDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMJOBDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemJobDetail::DpchEngData::getSrefsMask() {
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

void PnlWzemJobDetail::DpchEngData::merge(
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

void PnlWzemJobDetail::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemJobDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};

