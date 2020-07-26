/**
	* \file PnlWzemClnDetail_blks.cpp
	* job handler for job PnlWzemClnDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

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

void PnlWzemClnDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemClnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemClnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtJob", TxtJob);
		writeStringAttr(wr, itemtag, "sref", "TxtTjb", TxtTjb);
		writeStringAttr(wr, itemtag, "sref", "TxtAms", TxtAms);
	xmlTextWriterEndElement(wr);
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

void PnlWzemClnDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVExpstate
			, const bool LstAmsAlt
			, const uint LstAmsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemClnDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemClnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstAmsAlt", LstAmsAlt);
		writeUintAttr(wr, itemtag, "sref", "LstAmsNumFirstdisp", LstAmsNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWzemClnDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemClnDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemClnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtJobActive", TxtJobActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewAvail", ButJobViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCalActive", TxfCalActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSgeActive", TxfSgeActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTrgActive", PupTrgActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJmsActive", PupJmsActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTjbActive", TxtTjbActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTjbViewAvail", ButTjbViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTjbViewActive", ButTjbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstAmsActive", LstAmsActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfArgActive", TxfArgActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJatActive", PupJatActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzemClnDetail::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemClnDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemClnDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptJob", "job");
			writeStringAttr(wr, itemtag, "sref", "CptCal", "type");
			writeStringAttr(wr, itemtag, "sref", "CptSge", "stage");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "added");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "removed");
			writeStringAttr(wr, itemtag, "sref", "CptTrg", "target");
			writeStringAttr(wr, itemtag, "sref", "CptJms", "job mask");
			writeStringAttr(wr, itemtag, "sref", "CptTjb", "trigger job");
			writeStringAttr(wr, itemtag, "sref", "CptAms", "argument mask");
			writeStringAttr(wr, itemtag, "sref", "CptArg", "argument");
			writeStringAttr(wr, itemtag, "sref", "CptJat", "job access type");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::DETAIL, ixWzemVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemClnDetail::DpchAppData
 ******************************************************************************/

PnlWzemClnDetail::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMCLNDETAILDATA)
		{
};

string PnlWzemClnDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemClnDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemClnDetailData");
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
 class PnlWzemClnDetail::DpchAppDo
 ******************************************************************************/

PnlWzemClnDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMCLNDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzemClnDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemClnDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemClnDetailDo");
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
 class PnlWzemClnDetail::DpchEngData
 ******************************************************************************/

PnlWzemClnDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstAms
			, Feed* feedFPupJat
			, Feed* feedFPupJms
			, Feed* feedFPupTrg
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMCLNDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTAMS, FEEDFPUPJAT, FEEDFPUPJMS, FEEDFPUPTRG, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTAMS) && feedFLstAms) this->feedFLstAms = *feedFLstAms;
	if (find(this->mask, FEEDFPUPJAT) && feedFPupJat) this->feedFPupJat = *feedFPupJat;
	if (find(this->mask, FEEDFPUPJMS) && feedFPupJms) this->feedFPupJms = *feedFPupJms;
	if (find(this->mask, FEEDFPUPTRG) && feedFPupTrg) this->feedFPupTrg = *feedFPupTrg;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemClnDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWzemClnDetail::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTAMS)) {feedFLstAms = src->feedFLstAms; add(FEEDFLSTAMS);};
	if (src->has(FEEDFPUPJAT)) {feedFPupJat = src->feedFPupJat; add(FEEDFPUPJAT);};
	if (src->has(FEEDFPUPJMS)) {feedFPupJms = src->feedFPupJms; add(FEEDFPUPJMS);};
	if (src->has(FEEDFPUPTRG)) {feedFPupTrg = src->feedFPupTrg; add(FEEDFPUPTRG);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemClnDetail::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemClnDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTAMS)) feedFLstAms.writeXML(wr);
		if (has(FEEDFPUPJAT)) feedFPupJat.writeXML(wr);
		if (has(FEEDFPUPJMS)) feedFPupJms.writeXML(wr);
		if (has(FEEDFPUPTRG)) feedFPupTrg.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};

