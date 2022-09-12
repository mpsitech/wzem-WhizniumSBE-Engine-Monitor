/**
	* \file PnlWzemNdeList_blks.cpp
	* job handler for job PnlWzemNdeList (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemNdeList::VecVDo
 ******************************************************************************/

uint PnlWzemNdeList::VecVDo::getIx(
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

string PnlWzemNdeList::VecVDo::getSref(
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
 class PnlWzemNdeList::ContIac
 ******************************************************************************/

PnlWzemNdeList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlWzemNdeList::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzemNdeList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFTos")) {numFTos = me["numFTos"].asUInt(); add(NUMFTOS);};
	};

	return basefound;
};

bool PnlWzemNdeList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemNdeList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemNdeList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlWzemNdeList::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemNdeList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFTos"] = numFTos;
};

void PnlWzemNdeList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemNdeList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemNdeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNdeList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlWzemNdeList::ContIac::diff(
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
 class PnlWzemNdeList::ContInf
 ******************************************************************************/

PnlWzemNdeList::ContInf::ContInf(
			const string& TxtFor
			, const string& TxtPre
			, const bool ButFilterOn
			, const uint numFCsiQst
		) :
			Block()
		{
	this->TxtFor = TxtFor;
	this->TxtPre = TxtPre;
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
};

void PnlWzemNdeList::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemNdeList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtFor"] = TxtFor;
	me["TxtPre"] = TxtPre;
	me["ButFilterOn"] = ButFilterOn;
	me["numFCsiQst"] = numFCsiQst;
};

void PnlWzemNdeList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemNdeList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemNdeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFor", TxtFor);
		writeStringAttr(wr, itemtag, "sref", "TxtPre", TxtPre);
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNdeList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor == comp->TxtFor) insert(items, TXTFOR);
	if (TxtPre == comp->TxtPre) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWzemNdeList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNdeList::StatShr
 ******************************************************************************/

PnlWzemNdeList::StatShr::StatShr(
			const uint ixWzemVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXWZEMVEXPSTATE, BUTDELETEACTIVE};
};

void PnlWzemNdeList::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNdeList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzemVExpstate"] = VecWzemVExpstate::getSref(ixWzemVExpstate);
	me["ButDeleteActive"] = ButDeleteActive;
};

void PnlWzemNdeList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNdeList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemNdeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNdeList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWzemNdeList::StatShr::diff(
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
 class PnlWzemNdeList::StgIac
 ******************************************************************************/

PnlWzemNdeList::StgIac::StgIac(
			const uint TcoPrdWidth
			, const uint TcoXnrWidth
			, const uint TcoIpWidth
			, const uint TcoStaWidth
			, const uint TcoStoWidth
			, const uint TcoPrtWidth
			, const uint TcoOrnWidth
		) :
			Block()
		{
	this->TcoPrdWidth = TcoPrdWidth;
	this->TcoXnrWidth = TcoXnrWidth;
	this->TcoIpWidth = TcoIpWidth;
	this->TcoStaWidth = TcoStaWidth;
	this->TcoStoWidth = TcoStoWidth;
	this->TcoPrtWidth = TcoPrtWidth;
	this->TcoOrnWidth = TcoOrnWidth;
	mask = {TCOPRDWIDTH, TCOXNRWIDTH, TCOIPWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOPRTWIDTH, TCOORNWIDTH};
};

bool PnlWzemNdeList::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacWzemNdeList"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoPrdWidth")) {TcoPrdWidth = me["TcoPrdWidth"].asUInt(); add(TCOPRDWIDTH);};
		if (me.isMember("TcoXnrWidth")) {TcoXnrWidth = me["TcoXnrWidth"].asUInt(); add(TCOXNRWIDTH);};
		if (me.isMember("TcoIpWidth")) {TcoIpWidth = me["TcoIpWidth"].asUInt(); add(TCOIPWIDTH);};
		if (me.isMember("TcoStaWidth")) {TcoStaWidth = me["TcoStaWidth"].asUInt(); add(TCOSTAWIDTH);};
		if (me.isMember("TcoStoWidth")) {TcoStoWidth = me["TcoStoWidth"].asUInt(); add(TCOSTOWIDTH);};
		if (me.isMember("TcoPrtWidth")) {TcoPrtWidth = me["TcoPrtWidth"].asUInt(); add(TCOPRTWIDTH);};
		if (me.isMember("TcoOrnWidth")) {TcoOrnWidth = me["TcoOrnWidth"].asUInt(); add(TCOORNWIDTH);};
	};

	return basefound;
};

bool PnlWzemNdeList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWzemNdeList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWzemNdeList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrdWidth", TcoPrdWidth)) add(TCOPRDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXnrWidth", TcoXnrWidth)) add(TCOXNRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIpWidth", TcoIpWidth)) add(TCOIPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStaWidth", TcoStaWidth)) add(TCOSTAWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoStoWidth", TcoStoWidth)) add(TCOSTOWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrtWidth", TcoPrtWidth)) add(TCOPRTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOrnWidth", TcoOrnWidth)) add(TCOORNWIDTH);
	};

	return basefound;
};

void PnlWzemNdeList::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacWzemNdeList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoPrdWidth"] = TcoPrdWidth;
	me["TcoXnrWidth"] = TcoXnrWidth;
	me["TcoIpWidth"] = TcoIpWidth;
	me["TcoStaWidth"] = TcoStaWidth;
	me["TcoStoWidth"] = TcoStoWidth;
	me["TcoPrtWidth"] = TcoPrtWidth;
	me["TcoOrnWidth"] = TcoOrnWidth;
};

void PnlWzemNdeList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWzemNdeList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWzemNdeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoPrdWidth", TcoPrdWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoXnrWidth", TcoXnrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoIpWidth", TcoIpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStaWidth", TcoStaWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoStoWidth", TcoStoWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrtWidth", TcoPrtWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoOrnWidth", TcoOrnWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNdeList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoPrdWidth == comp->TcoPrdWidth) insert(items, TCOPRDWIDTH);
	if (TcoXnrWidth == comp->TcoXnrWidth) insert(items, TCOXNRWIDTH);
	if (TcoIpWidth == comp->TcoIpWidth) insert(items, TCOIPWIDTH);
	if (TcoStaWidth == comp->TcoStaWidth) insert(items, TCOSTAWIDTH);
	if (TcoStoWidth == comp->TcoStoWidth) insert(items, TCOSTOWIDTH);
	if (TcoPrtWidth == comp->TcoPrtWidth) insert(items, TCOPRTWIDTH);
	if (TcoOrnWidth == comp->TcoOrnWidth) insert(items, TCOORNWIDTH);

	return(items);
};

set<uint> PnlWzemNdeList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOPRDWIDTH, TCOXNRWIDTH, TCOIPWIDTH, TCOSTAWIDTH, TCOSTOWIDTH, TCOPRTWIDTH, TCOORNWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNdeList::Tag
 ******************************************************************************/

void PnlWzemNdeList::Tag::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzemNdeList";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["Cpt"] = "Nodes";
		me["TcoPrd"] = "Monitoring period";
		me["TcoXnr"] = "Reference";
		me["TcoIp"] = "IP";
		me["TcoSta"] = "Added";
		me["TcoSto"] = "Removed";
		me["TcoPrt"] = "Port";
		me["TcoOrn"] = "Op. proc.";
	};
	me["TxtFor"] = VecWzemVTag::getTitle(VecWzemVTag::FOR, ixWzemVLocale);
	me["TxtRecord1"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::REC, ixWzemVLocale));
	me["TxtRecord2"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::EMPLONG, ixWzemVLocale));
	me["Trs"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::GOTO, ixWzemVLocale)) + " ...";
	me["TxtShowing1"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::SHOWLONG, ixWzemVLocale));
	me["TxtShowing2"] = StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::EMPLONG, ixWzemVLocale));
};

void PnlWzemNdeList::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemNdeList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemNdeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Nodes");
			writeStringAttr(wr, itemtag, "sref", "TcoPrd", "Monitoring period");
			writeStringAttr(wr, itemtag, "sref", "TcoXnr", "Reference");
			writeStringAttr(wr, itemtag, "sref", "TcoIp", "IP");
			writeStringAttr(wr, itemtag, "sref", "TcoSta", "Added");
			writeStringAttr(wr, itemtag, "sref", "TcoSto", "Removed");
			writeStringAttr(wr, itemtag, "sref", "TcoPrt", "Port");
			writeStringAttr(wr, itemtag, "sref", "TcoOrn", "Op. proc.");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtFor", VecWzemVTag::getTitle(VecWzemVTag::FOR, ixWzemVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::REC, ixWzemVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::EMPLONG, ixWzemVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::GOTO, ixWzemVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::SHOWLONG, ixWzemVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::EMPLONG, ixWzemVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNdeList::DpchAppData
 ******************************************************************************/

PnlWzemNdeList::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNDELISTDATA)
		{
};

string PnlWzemNdeList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNdeList::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemNdeListData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryWzemNdeList::StgIac();
	};
};

void PnlWzemNdeList::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemNdeListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryWzemNdeList::StgIac();
	};
};

/******************************************************************************
 class PnlWzemNdeList::DpchAppDo
 ******************************************************************************/

PnlWzemNdeList::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNDELISTDO)
		{
	ixVDo = 0;
};

string PnlWzemNdeList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNdeList::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemNdeListDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzemNdeList::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemNdeListDo");
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
 class PnlWzemNdeList::DpchEngData
 ******************************************************************************/

PnlWzemNdeList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListWzemQNdeList* rst
			, QryWzemNdeList::StatShr* statshrqry
			, QryWzemNdeList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNDELISTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWzemNdeList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWzemNdeList::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWzemNdeList::DpchEngData::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemNdeListData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(FEEDFTOS)) feedFTos.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzemVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryWzemNdeList::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlWzemNdeList::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemNdeListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWzemNdeList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
