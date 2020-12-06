/**
	* \file PnlWzemJobList.cpp
	* API code for job PnlWzemJobList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzemJobList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemJobList::VecVDo
 ******************************************************************************/

uint PnlWzemJobList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butfilterclick") return BUTFILTERCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWzemJobList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTFILTERCLICK) return("ButFilterClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWzemJobList::ContIac
 ******************************************************************************/

PnlWzemJobList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlWzemJobList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemJobList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlWzemJobList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemJobList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemJobList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemJobList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlWzemJobList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobList::ContInf
 ******************************************************************************/

PnlWzemJobList::ContInf::ContInf(
			const bool ButFilterOn
			, const uint numFCsiQst
		) :
			Block()
		{
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {BUTFILTERON, NUMFCSIQST};
};

bool PnlWzemJobList::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemJobList";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ButFilterOn", ButFilterOn)) add(BUTFILTERON);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlWzemJobList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWzemJobList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTFILTERON, NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobList::StatShr
 ******************************************************************************/

PnlWzemJobList::StatShr::StatShr(
			const uint ixWzemVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXWZEMVEXPSTATE, BUTDELETEACTIVE};
};

bool PnlWzemJobList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemJobList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemJobList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWzemJobList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobList::StgIac
 ******************************************************************************/

PnlWzemJobList::StgIac::StgIac(
			const uint TcoPrdWidth
			, const uint TcoJobWidth
			, const uint TcoXjrWidth
			, const uint TcoStaWidth
			, const uint TcoStoWidth
			, const uint TcoSupWidth
		) :
			Block()
		{
	this->TcoPrdWidth = TcoPrdWidth;
	this->TcoJobWidth = TcoJobWidth;
	this->TcoXjrWidth = TcoXjrWidth;
	this->TcoStaWidth = TcoStaWidth;
	this->TcoStoWidth = TcoStoWidth;
	this->TcoSupWidth = TcoSupWidth;

	mask = {TCOPRDWIDTH, TCOJOBWIDTH, TCOXJRWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOSUPWIDTH};
};

bool PnlWzemJobList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWzemJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWzemJobList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrdWidth", TcoPrdWidth)) add(TCOPRDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoJobWidth", TcoJobWidth)) add(TCOJOBWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXjrWidth", TcoXjrWidth)) add(TCOXJRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStaWidth", TcoStaWidth)) add(TCOSTAWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStoWidth", TcoStoWidth)) add(TCOSTOWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSupWidth", TcoSupWidth)) add(TCOSUPWIDTH);
	};

	return basefound;
};

void PnlWzemJobList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWzemJobList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWzemJobList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoPrdWidth", TcoPrdWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoJobWidth", TcoJobWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoXjrWidth", TcoXjrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStaWidth", TcoStaWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStoWidth", TcoStoWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSupWidth", TcoSupWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemJobList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoPrdWidth == comp->TcoPrdWidth) insert(items, TCOPRDWIDTH);
	if (TcoJobWidth == comp->TcoJobWidth) insert(items, TCOJOBWIDTH);
	if (TcoXjrWidth == comp->TcoXjrWidth) insert(items, TCOXJRWIDTH);
	if (TcoStaWidth == comp->TcoStaWidth) insert(items, TCOSTAWIDTH);
	if (TcoStoWidth == comp->TcoStoWidth) insert(items, TCOSTOWIDTH);
	if (TcoSupWidth == comp->TcoSupWidth) insert(items, TCOSUPWIDTH);

	return(items);
};

set<uint> PnlWzemJobList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOPRDWIDTH, TCOJOBWIDTH, TCOXJRWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOSUPWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemJobList::Tag
 ******************************************************************************/

PnlWzemJobList::Tag::Tag(
			const string& Cpt
			, const string& TxtRecord1
			, const string& TxtRecord2
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoPrd
			, const string& TcoJob
			, const string& TcoXjr
			, const string& TcoSta
			, const string& TcoSto
			, const string& TcoSup
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->TxtRecord1 = TxtRecord1;
	this->TxtRecord2 = TxtRecord2;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoPrd = TcoPrd;
	this->TcoJob = TcoJob;
	this->TcoXjr = TcoXjr;
	this->TcoSta = TcoSta;
	this->TcoSto = TcoSto;
	this->TcoSup = TcoSup;

	mask = {CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOPRD, TCOJOB, TCOXJR, TCOSTA, TCOSTO, TCOSUP};
};

bool PnlWzemJobList::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemJobList";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord1", TxtRecord1)) add(TXTRECORD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord2", TxtRecord2)) add(TXTRECORD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoPrd", TcoPrd)) add(TCOPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoJob", TcoJob)) add(TCOJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXjr", TcoXjr)) add(TCOXJR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSta", TcoSta)) add(TCOSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSto", TcoSto)) add(TCOSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSup", TcoSup)) add(TCOSUP);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemJobList::DpchAppData
 ******************************************************************************/

PnlWzemJobList::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, StgIac* stgiac
			, QryWzemJobList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBLISTDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWzemJobList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobList::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemJobListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobList::DpchAppDo
 ******************************************************************************/

PnlWzemJobList::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMJOBLISTDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemJobList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobList::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemJobListDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemJobList::DpchEngData
 ******************************************************************************/

PnlWzemJobList::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMJOBLISTDATA)
		{
	feedFCsiQst.tag = "FeedFCsiQst";
	feedFTos.tag = "FeedFTos";
};

string PnlWzemJobList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(FEEDFTOS)) ss.push_back("feedFTos");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemJobList::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemJobListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (feedFTos.readXML(docctx, basexpath, true)) add(FEEDFTOS);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFCsiQst.clear();
		feedFTos.clear();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryWzemJobList::StatApp();
		statshrqry = QryWzemJobList::StatShr();
		stgiacqry = QryWzemJobList::StgIac();
	};
};

