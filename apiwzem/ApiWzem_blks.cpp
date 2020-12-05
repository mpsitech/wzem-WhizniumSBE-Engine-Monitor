/**
	* \file ApiWzem_blks.cpp
	* Wzem API library global data blocks (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#include "ApiWzem_blks.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class ContInfWzemAlert
 ******************************************************************************/

ContInfWzemAlert::ContInfWzemAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) :
			Block()
		{
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;
	this->TxtMsg10 = TxtMsg11;
	this->TxtMsg10 = TxtMsg12;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfWzemAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

bool ContInfWzemAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemAlert";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCpt", TxtCpt)) add(TXTCPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg1", TxtMsg1)) add(TXTMSG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg2", TxtMsg2)) add(TXTMSG2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg3", TxtMsg3)) add(TXTMSG3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg4", TxtMsg4)) add(TXTMSG4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg5", TxtMsg5)) add(TXTMSG5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg6", TxtMsg6)) add(TXTMSG6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg7", TxtMsg7)) add(TXTMSG7);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg8", TxtMsg8)) add(TXTMSG8);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg9", TxtMsg9)) add(TXTMSG9);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg10", TxtMsg10)) add(TXTMSG10);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg11", TxtMsg11)) add(TXTMSG11);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMsg12", TxtMsg12)) add(TXTMSG12);
	};

	return basefound;
};

set<uint> ContInfWzemAlert::compare(
			const ContInfWzemAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchWzem
 ******************************************************************************/

DpchWzem::DpchWzem(
			const uint ixWzemVDpch
		) {
	this->ixWzemVDpch = ixWzemVDpch;
};

DpchWzem::~DpchWzem() {
};

/******************************************************************************
 class DpchAppWzem
 ******************************************************************************/

DpchAppWzem::DpchAppWzem(
			const uint ixWzemVDpch
			, const string& scrJref
		) :
			DpchWzem(ixWzemVDpch)
		{
	this->scrJref = scrJref;

	mask = {SCRJREF};
};

DpchAppWzem::~DpchAppWzem() {
};

bool DpchAppWzem::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;

	return true;
};

string DpchAppWzem::getSrefsMask() {
	if (has(SCRJREF)) return("scrJref");
	else return("");
};

void DpchAppWzem::writeXML(
			xmlTextWriter* wr
		) {
	string tag = VecWzemVDpch::getSref(ixWzemVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchAppWzemAlert
 ******************************************************************************/

DpchAppWzemAlert::DpchAppWzemAlert(
			const string& scrJref
			, const uint numFMcb
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMALERT, scrJref)
		{
	this->numFMcb = numFMcb;

	if (find(mask, ALL)) this->mask = {SCRJREF, NUMFMCB};
	else this->mask = mask;
};

bool DpchAppWzemAlert::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppWzemAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppWzemAlert::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(NUMFMCB)) writeUint(wr, "numFMcb", numFMcb);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchAppWzemInit
 ******************************************************************************/

DpchAppWzemInit::DpchAppWzemInit(
			const string& scrJref
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMINIT, scrJref)
		{
};

/******************************************************************************
 class DpchAppWzemResume
 ******************************************************************************/

DpchAppWzemResume::DpchAppWzemResume(
			const string& scrJref
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMRESUME, scrJref)
		{
};

/******************************************************************************
 class DpchEngWzem
 ******************************************************************************/

DpchEngWzem::DpchEngWzem(
			const uint ixWzemVDpch
		) :
			DpchWzem(ixWzemVDpch)
		{
};

DpchEngWzem::~DpchEngWzem() {
};

bool DpchEngWzem::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;

	return true;
};

string DpchEngWzem::getSrefsMask() {
	if (has(SCRJREF)) return("scrJref");
	else return("");
};

void DpchEngWzem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecWzemVDpch::getSref(ixWzemVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

/******************************************************************************
 class DpchEngWzemAck
 ******************************************************************************/

DpchEngWzemAck::DpchEngWzemAck() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMACK)
		{
};

/******************************************************************************
 class DpchEngWzemAlert
 ******************************************************************************/

DpchEngWzemAlert::DpchEngWzemAlert() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMALERT)
		{
};

bool DpchEngWzemAlert::all(
			const set<uint>& items
		) {
	if (!find(items, SCRJREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngWzemAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWzemAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFMcb.readXML(docctx, basexpath, true)) add(FEEDFMCB);
	} else {
		continf = ContInfWzemAlert();
		feedFMcb.clear();
	};
};

/******************************************************************************
 class DpchEngWzemConfirm
 ******************************************************************************/

DpchEngWzemConfirm::DpchEngWzemConfirm() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMCONFIRM)
		{
	accepted = false;
};

bool DpchEngWzemConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, SCRJREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngWzemConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWzemConfirm::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemConfirm");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractBoolUclc(docctx, basexpath, "accepted", "", accepted)) add(ACCEPTED);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "sref", "", sref)) add(SREF);
	} else {
	};
};

/******************************************************************************
 class DpchEngWzemSuspend
 ******************************************************************************/

DpchEngWzemSuspend::DpchEngWzemSuspend() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMSUSPEND)
		{
};

