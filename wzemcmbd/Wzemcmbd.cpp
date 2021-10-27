/**
	* \file Wzemcmbd.cpp
	* inter-thread exchange object for Wzem combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "Wzemcmbd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchAppWzem
 ******************************************************************************/

DpchAppWzem::DpchAppWzem(
			const uint ixWzemVDpch
		) :
			DpchWzem(ixWzemVDpch)
		{
	jref = 0;
};

DpchAppWzem::~DpchAppWzem() {
};

bool DpchAppWzem::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchAppWzem::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchAppWzem::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup[VecWzemVDpch::getSref(ixWzemVDpch)];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
	};
};

void DpchAppWzem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecWzemVDpch::getSref(ixWzemVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppWzemAlert
 ******************************************************************************/

DpchAppWzemAlert::DpchAppWzemAlert() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMALERT)
		{
};

bool DpchAppWzemAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

string DpchAppWzemAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(NUMFMCB)) ss.push_back("numFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchAppWzemAlert::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWzemAlert"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {
			jref = Scr::descramble(me["scrJref"].asString());
			add(JREF);
		};
		if (me.isMember("numFMcb")) {numFMcb = me["numFMcb"].asInt(); add(NUMFMCB);};
	};
};

void DpchAppWzemAlert::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppWzemInit
 ******************************************************************************/

DpchAppWzemInit::DpchAppWzemInit() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMINIT)
		{
};

/******************************************************************************
 class DpchAppWzemResume
 ******************************************************************************/

DpchAppWzemResume::DpchAppWzemResume() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMRESUME)
		{
};

/******************************************************************************
 class DpchEngWzem
 ******************************************************************************/

DpchEngWzem::DpchEngWzem(
			const uint ixWzemVDpch
			, const ubigint jref
		) :
			DpchWzem(ixWzemVDpch)
		{
	this->jref = jref;

	mask = {JREF};
};

DpchEngWzem::~DpchEngWzem() {
};

bool DpchEngWzem::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

string DpchEngWzem::getSrefsMask() {
	if (has(JREF)) return("jref");
	else return("");
};

void DpchEngWzem::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngWzem* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngWzem::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup[VecWzemVDpch::getSref(ixWzemVDpch)] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
};

void DpchEngWzem::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	string tag = VecWzemVDpch::getSref(ixWzemVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWzemAck
 ******************************************************************************/

DpchEngWzemAck::DpchEngWzemAck(
			const ubigint jref
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMACK, jref)
		{
};

/******************************************************************************
 class DpchEngWzemAlert
 ******************************************************************************/

DpchEngWzemAlert::DpchEngWzemAlert(
			const ubigint jref
			, ContInfWzemAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMALERT, jref)
		{
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngWzemAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

string DpchEngWzemAlert::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFMCB)) ss.push_back("feedFMcb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWzemAlert::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngWzemAlert* src = (DpchEngWzemAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngWzemAlert::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemAlert"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFMCB)) feedFMcb.writeJSON(me);
};

void DpchEngWzemAlert::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWzemConfirm
 ******************************************************************************/

DpchEngWzemConfirm::DpchEngWzemConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMCONFIRM, jref)
		{
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngWzemConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

string DpchEngWzemConfirm::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(ACCEPTED)) ss.push_back("accepted");
	if (has(JREF)) ss.push_back("jref");
	if (has(SREF)) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DpchEngWzemConfirm::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngWzemConfirm* src = (DpchEngWzemConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngWzemConfirm::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemConfirm"] = Json::Value(Json::objectValue);

	if (has(ACCEPTED)) me["accepted"] = accepted;
	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(SREF)) me["sref"] = sref;
};

void DpchEngWzemConfirm::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngWzemSuspend
 ******************************************************************************/

DpchEngWzemSuspend::DpchEngWzemSuspend(
			const ubigint jref
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMSUSPEND, jref)
		{
};

/******************************************************************************
 class StgWzemAppearance
 ******************************************************************************/

StgWzemAppearance::StgWzemAppearance(
			const usmallint histlength
			, const bool suspsess
			, const uint sesstterm
			, const uint sesstwarn
			, const uint roottterm
		) :
			Block()
		{
	this->histlength = histlength;
	this->suspsess = suspsess;
	this->sesstterm = sesstterm;
	this->sesstwarn = sesstwarn;
	this->roottterm = roottterm;
	mask = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
};

bool StgWzemAppearance::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzemAppearance");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzemAppearance";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "suspsess", suspsess)) add(SUSPSESS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstterm", sesstterm)) add(SESSTTERM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sesstwarn", sesstwarn)) add(SESSTWARN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roottterm", roottterm)) add(ROOTTTERM);
	};

	return basefound;
};

void StgWzemAppearance::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzemAppearance";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzemAppearance";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
		writeBoolAttr(wr, itemtag, "sref", "suspsess", suspsess);
		writeUintAttr(wr, itemtag, "sref", "sesstterm", sesstterm);
		writeUintAttr(wr, itemtag, "sref", "sesstwarn", sesstwarn);
		writeUintAttr(wr, itemtag, "sref", "roottterm", roottterm);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzemAppearance::comm(
			const StgWzemAppearance* comp
		) {
	set<uint> items;

	if (histlength == comp->histlength) insert(items, HISTLENGTH);
	if (suspsess == comp->suspsess) insert(items, SUSPSESS);
	if (sesstterm == comp->sesstterm) insert(items, SESSTTERM);
	if (sesstwarn == comp->sesstwarn) insert(items, SESSTWARN);
	if (roottterm == comp->roottterm) insert(items, ROOTTTERM);

	return(items);
};

set<uint> StgWzemAppearance::diff(
			const StgWzemAppearance* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {HISTLENGTH, SUSPSESS, SESSTTERM, SESSTWARN, ROOTTTERM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzemAppsrv
 ******************************************************************************/

StgWzemAppsrv::StgWzemAppsrv(
			const usmallint port
			, const bool https
		) :
			Block()
		{
	this->port = port;
	this->https = https;
	mask = {PORT, HTTPS};
};

bool StgWzemAppsrv::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzemAppsrv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzemAppsrv";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "https", https)) add(HTTPS);
	};

	return basefound;
};

void StgWzemAppsrv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzemAppsrv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzemAppsrv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeBoolAttr(wr, itemtag, "sref", "https", https);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzemAppsrv::comm(
			const StgWzemAppsrv* comp
		) {
	set<uint> items;

	if (port == comp->port) insert(items, PORT);
	if (https == comp->https) insert(items, HTTPS);

	return(items);
};

set<uint> StgWzemAppsrv::diff(
			const StgWzemAppsrv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PORT, HTTPS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzemcmbd
 ******************************************************************************/

StgWzemcmbd::StgWzemcmbd(
			const usmallint jobprcn
			, const usmallint opprcn
			, const bool appsrv
		) :
			Block()
		{
	this->jobprcn = jobprcn;
	this->opprcn = opprcn;
	this->appsrv = appsrv;
	mask = {JOBPRCN, OPPRCN, APPSRV};
};

bool StgWzemcmbd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzemcmbd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzemcmbd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrv", appsrv)) add(APPSRV);
	};

	return basefound;
};

void StgWzemcmbd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzemcmbd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzemcmbd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
		writeBoolAttr(wr, itemtag, "sref", "appsrv", appsrv);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzemcmbd::comm(
			const StgWzemcmbd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);
	if (appsrv == comp->appsrv) insert(items, APPSRV);

	return(items);
};

set<uint> StgWzemcmbd::diff(
			const StgWzemcmbd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPPRCN, APPSRV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzemDatabase
 ******************************************************************************/

StgWzemDatabase::StgWzemDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) :
			Block()
		{
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgWzemDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzemDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzemDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgWzemDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzemDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzemDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzemDatabase::comm(
			const StgWzemDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgWzemDatabase::diff(
			const StgWzemDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWzemPath
 ******************************************************************************/

StgWzemPath::StgWzemPath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) :
			Block()
		{
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgWzemPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzemPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzemPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgWzemPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzemPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWzemPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzemPath::comm(
			const StgWzemPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgWzemPath::diff(
			const StgWzemPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 namespace AlrWzem
 ******************************************************************************/

DpchEngWzemAlert* AlrWzem::prepareAlrAbt(
			const ubigint jref
			, const uint ixWzemVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWzemAlert continf;
	// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecWzemVTag::getTitle(VecWzemVTag::ABOUT, ixWzemVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		continf.TxtMsg1 = "WhizniumSBE Engine Monitor version v1.0.6 released on 3-5-2021";
		continf.TxtMsg2 = "\\u00a9 MPSI Technologies GmbH";
		continf.TxtMsg4 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg6 = "WhizniumSBE Engine Monitor serves as a debugging tool for projects developed with WhizniumSBE.";
		continf.TxtMsg7 = "Events modifying the run-time job structure can be tracked along with external requests and operation execution.";
	};

	feedFMcbAlert.clear();

	VecWzemVTag::appendToFeed(VecWzemVTag::CLOSE, ixWzemVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrAbt --- END
	return(new DpchEngWzemAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzemAlert::ALL}));
};

DpchEngWzemAlert* AlrWzem::prepareAlrIer(
			const ubigint jref
			, const uint ixWzemVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWzemAlert continf;
	// IP prepareAlrIer --- BEGIN
	continf.TxtCpt = VecWzemVTag::getTitle(VecWzemVTag::IMPERR, ixWzemVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWzemVTag::appendToFeed(VecWzemVTag::CANCEL, ixWzemVLocale, feedFMcbAlert);
	VecWzemVTag::appendToFeed(VecWzemVTag::REVERSE, ixWzemVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrIer --- END
	return(new DpchEngWzemAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzemAlert::ALL}));
};

DpchEngWzemAlert* AlrWzem::prepareAlrPer(
			const ubigint jref
			, const uint ixWzemVLocale
			, const string& iexsqk
			, Feed& feedFMcbAlert
		) {
	ContInfWzemAlert continf;
	// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecWzemVTag::getTitle(VecWzemVTag::PRSERR, ixWzemVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		continf.TxtMsg1 = "" + iexsqk + "";
	};

	feedFMcbAlert.clear();

	VecWzemVTag::appendToFeed(VecWzemVTag::OK, ixWzemVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrPer --- END
	return(new DpchEngWzemAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzemAlert::ALL}));
};

DpchEngWzemAlert* AlrWzem::prepareAlrSav(
			const ubigint jref
			, const uint ixWzemVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfWzemAlert continf;
	// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecWzemVTag::getTitle(VecWzemVTag::QUEST, ixWzemVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	};

	feedFMcbAlert.clear();

	VecWzemVTag::appendToFeed(VecWzemVTag::CANCEL, ixWzemVLocale, feedFMcbAlert);
	VecWzemVTag::appendToFeed(VecWzemVTag::FLS, ixWzemVLocale, feedFMcbAlert);
	VecWzemVTag::appendToFeed(VecWzemVTag::TRU, ixWzemVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrSav --- END
	return(new DpchEngWzemAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzemAlert::ALL}));
};

DpchEngWzemAlert* AlrWzem::prepareAlrTrm(
			const ubigint jref
			, const uint ixWzemVLocale
			, const uint sesstterm
			, const uint sesstwarn
			, Feed& feedFMcbAlert
		) {
	ContInfWzemAlert continf;
	// IP prepareAlrTrm --- BEGIN
	continf.TxtCpt = VecWzemVTag::getTitle(VecWzemVTag::ANNOUNCE, ixWzemVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		continf.TxtMsg1 = "Your session has been inactive for " + prepareAlrTrm_dtToString(ixWzemVLocale, sesstterm) + ". It will be terminated in " + prepareAlrTrm_dtToString(ixWzemVLocale, sesstwarn) + ".";
	};

	feedFMcbAlert.clear();

	VecWzemVTag::appendToFeed(VecWzemVTag::OK, ixWzemVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP prepareAlrTrm --- END
	return(new DpchEngWzemAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzemAlert::ALL}));
};

string AlrWzem::prepareAlrTrm_dtToString(
			const uint ixWzemVLocale
			, const time_t dt
		) {
	string s;

	if ((dt%3600) == 0) {
		s = to_string(dt/3600);

		if (dt == 3600) s += " " + VecWzemVTag::getTitle(VecWzemVTag::HOUR, ixWzemVLocale);
		else s += " " + VecWzemVTag::getTitle(VecWzemVTag::HOURS, ixWzemVLocale);

	} else if ((dt%60) == 0) {
		s = to_string(dt/60);

		if (dt == 60) s += " " + VecWzemVTag::getTitle(VecWzemVTag::MINUTE, ixWzemVLocale);
		else s += " " + VecWzemVTag::getTitle(VecWzemVTag::MINUTES, ixWzemVLocale);

	} else {
		s = to_string(dt);

		if (dt == 1) s += " " + VecWzemVTag::getTitle(VecWzemVTag::SECOND, ixWzemVLocale);
		else s += " " + VecWzemVTag::getTitle(VecWzemVTag::SECONDS, ixWzemVLocale);
	};

	return s;
};

/******************************************************************************
 class ReqWzem
 ******************************************************************************/

ReqWzem::ReqWzem(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) :
			cReady("cReady", "ReqWzem", "ReqWzem")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	retain = !((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::DPCHAPP) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD) || (ixVBasetype == VecVBasetype::METHOD));

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jsonNotXml = false;

	jref = 0;

	wref = 0;

	call = NULL;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixWzemVLocale = VecWzemVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;

	method = NULL;
};

ReqWzem::~ReqWzem() {
	if (pp) MHD_destroy_post_processor(pp);

	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	if (call) delete call;

	if (request) delete[] request;

	if (dpchapp) delete dpchapp;

	if (dpcheng) delete dpcheng;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	if (method) delete method;
};

void ReqWzem::setStateReply() {
	cReady.lockMutex("ReqWzem", "setStateReply", "jref=" + to_string(jref));
	ixVState = VecVState::REPLY;
	cReady.unlockMutex("ReqWzem", "setStateReply", "jref=" + to_string(jref));

	cReady.signal("ReqWzem", "setStateReply", "jref=" + to_string(jref));
};

/******************************************************************************
 class DcolWzem
 ******************************************************************************/

DcolWzem::DcolWzem(
			const ubigint jref
			, const uint ixWzemVLocale
		) :
			mAccess("dcol.mAccess", "DcolWzem", "DcolWzem", "jref=" + to_string(jref))
		{
	this->jref = jref;
	this->ixWzemVLocale = ixWzemVLocale;

	hot = false;

	req = NULL;
};

DcolWzem::~DcolWzem() {
	for (auto it = dpchs.begin(); it != dpchs.end(); it++) delete(*it);

	if (req) req->cReady.signal("DcolWzem", "~DcolWzem", "jref=" + to_string(jref));

	mAccess.lock("DcolWzem", "~DcolWzem", "jref=" + to_string(jref));
	mAccess.unlock("DcolWzem", "~DcolWzem", "jref=" + to_string(jref));
};

void DcolWzem::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void DcolWzem::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class JobWzem
 ******************************************************************************/

JobWzem::JobWzem(
			XchgWzem* xchg
			, const uint ixWzemVJob
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			mAccess("mAccess", VecWzemVJob::getSref(ixWzemVJob), VecWzemVJob::getSref(ixWzemVJob), "jrefSup=" + to_string(jrefSup))
			, mOps("mOps", VecWzemVJob::getSref(ixWzemVJob), VecWzemVJob::getSref(ixWzemVJob), "jrefSup=" + to_string(jrefSup))
		{
	this->xchg = xchg;

	jref = 0;

	this->ixWzemVJob = ixWzemVJob;

	this->ixWzemVLocale = ixWzemVLocale;

	muteRefresh = false;

	ixVSge = 1;
	nextIxVSgeSuccess = 1;
	nextIxVSgeFailure = 1;

	opN = 0;
	opNSuccess = 0;
	opNFailure = 0;

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobWzem::~JobWzem() {
	if (reqCmd) delete reqCmd;

	mAccess.lock(VecWzemVJob::getSref(ixWzemVJob), "~" + VecWzemVJob::getSref(ixWzemVJob), "jref=" + to_string(jref));
	mAccess.unlock(VecWzemVJob::getSref(ixWzemVJob), "~" + VecWzemVJob::getSref(ixWzemVJob), "jref=" + to_string(jref));
};

DpchEngWzem* JobWzem::getNewDpchEng(
			set<uint> items
		) {
	return new DpchEngWzemConfirm(true, jref, "");
};

void JobWzem::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
};

void JobWzem::refreshWithDpchEng(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
			, const bool unmute
		) {
	set<uint> moditems;

	DpchEngWzem* _dpcheng = NULL;

	refresh(dbswzem, moditems, unmute);
	if (muteRefresh) return;

	if (dpcheng) {
		_dpcheng = getNewDpchEng(moditems);

		if (*dpcheng) {
			if (_dpcheng->ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCONFIRM) delete _dpcheng;
			else if (_dpcheng->ixWzemVDpch == (*dpcheng)->ixWzemVDpch) {
				(*dpcheng)->merge(_dpcheng);
				delete _dpcheng;

			} else xchg->submitDpch(_dpcheng);

		} else *dpcheng = _dpcheng;

	} else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
};

string JobWzem::getSquawk(
			DbsWzem* dbswzem
		) {
	return "";
};

void JobWzem::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
};

void JobWzem::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
};

void JobWzem::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

bool JobWzem::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return mAccess.trylock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWzem::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

void JobWzem::lockAccess(
			const string& srefMember
		) {
	mAccess.lock(VecWzemVJob::getSref(ixWzemVJob), srefMember, "jref=" + to_string(jref));
};

bool JobWzem::trylockAccess(
			const string& srefMember
		) {
	return mAccess.trylock(VecWzemVJob::getSref(ixWzemVJob), srefMember, "jref=" + to_string(jref));
};

void JobWzem::unlockAccess(
			const string& srefMember
		) {
	mAccess.unlock(VecWzemVJob::getSref(ixWzemVJob), srefMember, "jref=" + to_string(jref));
};

void JobWzem::setStage(
			DbsWzem* dbswzem
			, const uint _ixVSge
		) {
	xchg->setJobStage(dbswzem, this, _ixVSge);
};

void JobWzem::clearInvs() {
	for (unsigned int i = 0; i < invs.size(); i++) delete invs[i];
	invs.clear();
};

ubigint JobWzem::addInv(
			DpchInvWzem* inv
		) {
	inv->oref = xchg->orefseq.getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;

	return(inv->oref);
};

void JobWzem::addInvs(
			vector<DpchInvWzem*>& _invs
		) {
	for (unsigned int i = 0; i < _invs.size(); i++) addInv(_invs[i]);
};

void JobWzem::submitInvs(
			DbsWzem* dbswzem
			, const uint nextIxVSgeEmpty
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = nextIxVSgeEmpty;

	} else {
		xchg->addInvs(dbswzem, this, invs);
		invs.clear();
	};
};

void JobWzem::clearOps() {
	mOps.lock(VecWzemVJob::getSref(ixWzemVJob), "clearOps", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) delete(*it);
	ops.clear();

	mOps.unlock(VecWzemVJob::getSref(ixWzemVJob), "clearOps", "jref=" + to_string(jref));
};

void JobWzem::addOp(
			DbsWzem* dbswzem
			, DpchInvWzem* inv
		) {
	string squawk;

	mOps.lock(VecWzemVJob::getSref(ixWzemVJob), "addOp", "jref=" + to_string(jref));

	// generate squawk

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixWzemVDpch, squawk));

	mOps.unlock(VecWzemVJob::getSref(ixWzemVJob), "addOp", "jref=" + to_string(jref));
};

void JobWzem::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	mOps.lock(VecWzemVJob::getSref(ixWzemVJob), "removeOp", "jref=" + to_string(jref));

	for (auto it = ops.begin(); it != ops.end(); it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	mOps.unlock(VecWzemVJob::getSref(ixWzemVJob), "removeOp", "jref=" + to_string(jref));
};

string JobWzem::getOpsqkLast() {
	string retval;

	mOps.lock(VecWzemVJob::getSref(ixWzemVJob), "getOpsqkLast", "jref=" + to_string(jref));

	retval = opsqkLast;

	mOps.unlock(VecWzemVJob::getSref(ixWzemVJob), "getOpsqkLast", "jref=" + to_string(jref));

	return retval;
};

void JobWzem::callback(
			const uint nextIxVSge
		) {
	nextIxVSgeSuccess = nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobWzem::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class CsjobWzem
 ******************************************************************************/

CsjobWzem::CsjobWzem(
			XchgWzem* xchg
			, const uint ixWzemVJob
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, ixWzemVJob, jrefSup, ixWzemVLocale)
		{
	srvNotCli = false;
	srv = NULL;
};

bool CsjobWzem::handleClaim(
			DbsWzem* dbswzem
			, map<ubigint,Claim*>& claims
			, const ubigint jrefNewest
		) {
	return false;
};

/******************************************************************************
 class ShrdatWzem
 ******************************************************************************/

ShrdatWzem::ShrdatWzem(
			const string& srefSupclass
			, const string& srefObject
		) :
			rwmAccess("shrdat.mAccess", srefSupclass + "::" + srefObject, srefObject)
		{
	this->srefSupclass = srefSupclass;
	this->srefObject = srefObject;
};

ShrdatWzem::~ShrdatWzem() {
};

void ShrdatWzem::init(
			XchgWzem* xchg
			, DbsWzem* dbswzem
		) {
};

void ShrdatWzem::term(
			XchgWzem* xchg
		) {
};

void ShrdatWzem::rlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.rlock(srefObject, srefMember, args);
};

void ShrdatWzem::runlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.runlock(srefObject, srefMember, args);
};

void ShrdatWzem::rlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.rlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWzem::runlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.runlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWzem::wlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wlock(srefObject, srefMember, args);
};

void ShrdatWzem::wunlockAccess(
			const string& srefObject
			, const string& srefMember
			, const string& args
		) {
	rwmAccess.wunlock(srefObject, srefMember, args);
};

void ShrdatWzem::wlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

void ShrdatWzem::wunlockAccess(
			const ubigint jref
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefSupclass, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class StmgrWzem
 ******************************************************************************/

StmgrWzem::StmgrWzem(
			XchgWzem* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) :
			mAccess("stmgr.mAccess", "StmgrWzem", "StmgrWzem", "jref=" + to_string(jref))
		{
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);
};

StmgrWzem::~StmgrWzem() {
	delete stcch;

	mAccess.lock("StmgrWzem", "~StmgrWzem", "jref=" + to_string(jref));
	mAccess.unlock("StmgrWzem", "~StmgrWzem", "jref=" + to_string(jref));
};

void StmgrWzem::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	set<uint> icsWzemVStub;
	pair<multimap<stcchitemref_t,Stcchitem*>::iterator,multimap<stcchitemref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecWzemVCall::CALLWZEMCALUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMCALSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCLNUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMCLNSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMDCHUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMDCHSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMEVTUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMEVTSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMJOBUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMJOBXJREF);
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMJOBSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMNDEUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMNDEXNREF);
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMNDESTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMOPXUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMOPXSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPRDUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMPRDSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPRSUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMPRSSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMPSTUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMPSTSTD);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMSESUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMSESSTD);
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMSESMENU);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSGUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMUSGSTD);
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMGROUP);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMUSRUPD_REFEQ) {
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMOWNER);
		insert(icsWzemVStub, VecWzemVStub::STUBWZEMUSRSTD);
	};

	for (auto it = icsWzemVStub.begin(); it != icsWzemVStub.end(); it++) {
		rng = stcch->nodes.equal_range(stcchitemref_t(*it, call->argInv.ref, 0));
		for (auto it2 = rng.first; it2 != rng.second; it2++) if (refresh(dbswzem, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMSTUBCHG, jref);
};

bool StmgrWzem::refresh(
			DbsWzem* dbswzem
			, Stcchitem* stit
		) {
	set<stcchitemref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubWzem::getStub(dbswzem, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it = strefsSub_backup.begin(); it != strefsSub_backup.end(); it++) refresh(dbswzem, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrWzem::begin() {
	stcch->begin();
};

void StmgrWzem::commit() {
	for (auto it = stcch->icsVStubNew.begin(); it != stcch->icsVStubNew.end(); it++) {
		if (*it == VecWzemVStub::STUBWZEMCALSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMCALUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMCLNSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMCLNUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMDCHSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMDCHUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMEVTSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMEVTUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMGROUP) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMUSGUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMJOBSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMJOBUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMJOBXJREF) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMJOBUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMNDESTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMNDEUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMNDEXNREF) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMNDEUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMOPXSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMOPXUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMOWNER) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMUSRUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMPRDSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMPRDUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMPRSSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMPRSUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMPSTSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMPSTUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMSESMENU) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMSESUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMSESSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMSESUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMUSGSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMUSGUPD_REFEQ, jref);
		} else if (*it == VecWzemVStub::STUBWZEMUSRSTD) {
			xchg->addClstnStmgr(VecWzemVCall::CALLWZEMUSRUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

void StmgrWzem::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.lock(srefObject, srefMember, "jref=" + to_string(jref));
};

void StmgrWzem::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	mAccess.unlock(srefObject, srefMember, "jref=" + to_string(jref));
};

/******************************************************************************
 class WakeupWzem
 ******************************************************************************/

WakeupWzem::WakeupWzem(
			XchgWzem* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ExtcallWzem
 ******************************************************************************/

ExtcallWzem::ExtcallWzem(
			XchgWzem* xchg
			, Call* call
		) {
	this->xchg = xchg;
	this->call = call;
};

// IP ShrdatJobprc.subs --- INSERT

/******************************************************************************
 class XchgWzemcmbd::ShrdatJobprc
 ******************************************************************************/

XchgWzemcmbd::ShrdatJobprc::ShrdatJobprc() :
			ShrdatWzem("XchgWzem", "ShrdatJobprc")
		{
};

void XchgWzemcmbd::ShrdatJobprc::init(
			XchgWzem* xchg
			, DbsWzem* dbswzem
		) {
	// IP ShrdatJobprc.init --- INSERT
};

void XchgWzemcmbd::ShrdatJobprc::term(
			XchgWzem* xchg
		) {
	// IP ShrdatJobprc.term --- INSERT
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgWzemcmbd::ShrdatOpprc
 ******************************************************************************/

XchgWzemcmbd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatWzem("XchgWzem", "ShrdatOpprc")
		{
};

void XchgWzemcmbd::ShrdatOpprc::init(
			XchgWzem* xchg
			, DbsWzem* dbswzem
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgWzemcmbd::ShrdatOpprc::term(
			XchgWzem* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgWzemcmbd
 ******************************************************************************/

XchgWzemcmbd::XchgWzemcmbd() :
			cStable("cStable", "XchgWzemcmbd", "XchgWzemcmbd")
			, mLogfile("mLogfile", "XchgWzemcmbd", "XchgWzemcmbd")
			, cJobprcs("cJobprcs", "XchgWzemcmbd", "XchgWzemcmbd")
			, cOpprcs("cOpprcs", "XchgWzemcmbd", "XchgWzemcmbd")
			, mReqs("mReqs", "XchgWzemcmbd", "XchgWzemcmbd")
			, orefseq("orefseq")
			, mInvs("mInvs", "XchgWzemcmbd", "XchgWzemcmbd")
			, rwmPresets("rwmPresets", "XchgWzemcmbd", "XchgWzemcmbd")
			, rwmStmgrs("rwmStmgrs", "XchgWzemcmbd", "XchgWzemcmbd")
			, rwmClstns("rwmClstns", "XchgWzemcmbd", "XchgWzemcmbd")
			, rwmDcols("rwmDcols", "XchgWzemcmbd", "XchgWzemcmbd")
			, jrefseq("jrefseq")
			, rwmJobs("rwmJobs", "XchgWzemcmbd", "XchgWzemcmbd")
			, rwmCsjobinfos("rwmCsjobinfos", "XchgWzemcmbd", "XchgWzemcmbd")
			, wrefseq("wrefseq")
		{
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// client-server job information

};

XchgWzemcmbd::~XchgWzemcmbd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = invs.begin(); it != invs.end(); it++) delete(*it);
	for (auto it = presets.begin(); it != presets.end(); it++) delete(it->second);
	for (auto it = stmgrs.begin(); it != stmgrs.end(); it++) delete(it->second);
	for (auto it = clstns.begin(); it != clstns.end(); it++) delete(it->second);
	for (auto it = dcols.begin(); it != dcols.end(); it++) delete(it->second);
	for (auto it = jobs.begin(); it != jobs.end(); it++) delete(it->second);
	for (auto it = jobinfos.begin(); it != jobinfos.end(); it++) delete(it->second);
	for (auto it = csjobinfos.begin(); it != csjobinfos.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgWzemcmbd::startMon() {
	JobWzem* job = NULL;
	Jobinfo* jobinfo = NULL;

	DcolWzem* dcol = NULL;
	bool Dcol;

	StmgrWzem* stmgr = NULL;
	bool Stmgr;

	Clstn* clstn = NULL;
	Preset* preset = NULL;

	mon.start("WhizniumSBE Engine Monitor v1.0.6", stgwzempath.monpath);

	rwmJobs.rlock("XchgWzemcmbd", "startMon");
	for (auto it = jobs.begin(); it != jobs.end(); it++) {
		job = it->second;
		jobinfo = jobinfos[job->jref];

		dcol = getDcolByJref(job->jref, false);
		if (dcol) {
			Dcol = true;
			dcol->unlockAccess("XchgWzemcmbd", "startMon");
		} else Dcol = false;

		stmgr = getStmgrByJref(job->jref);
		if (stmgr) {
			Stmgr = true;
			stmgr->unlockAccess("XchgWzemcmbd", "startMon");
		} else Stmgr = false;

		if (getCsjobNotJob(job->ixWzemVJob)) mon.insertJob(jobinfo->jrefSup, VecWzemVJob::getSref(job->ixWzemVJob), job->jref, true, ((CsjobWzem*) job)->srvNotCli, Dcol, Stmgr);
		else mon.insertJob(jobinfo->jrefSup, VecWzemVJob::getSref(job->ixWzemVJob), job->jref, false, false, Dcol, Stmgr);
	};
	rwmJobs.runlock("XchgWzemcmbd", "startMon");

	rwmClstns.rlock("XchgWzemcmbd", "startMon");
	for (auto it = clstns.begin(); it != clstns.end(); it++) {
		clstn = it->second;
		mon.insertClstn(clstn->cref.jref, Clstn::VecVTarget::getSref(clstn->cref.ixVTarget), VecWzemVCall::getSref(clstn->cref.ixVCall), Clstn::VecVJobmask::getSref(clstn->cref.ixVJobmask), clstn->cref.jrefTrig, clstn->cref.arg, clstn->cref.ixVSge, Clstn::VecVJactype::getSref(clstn->ixVJactype));
	};
	rwmClstns.runlock("XchgWzemcmbd", "startMon");

	rwmPresets.rlock("XchgWzemcmbd", "startMon");
	for (auto it = presets.begin(); it != presets.end(); it++) {
		preset = it->second;
		mon.insertPreset(preset->pref.jref, VecWzemVPreset::getSref(preset->pref.ixVPreset), preset->arg);
	};
	rwmPresets.runlock("XchgWzemcmbd", "startMon");

	triggerCall(NULL, VecWzemVCall::CALLWZEMMONSTATCHG, jrefRoot);
};

void XchgWzemcmbd::stopMon() {
	mon.stop();

	triggerCall(NULL, VecWzemVCall::CALLWZEMMONSTATCHG, jrefRoot);
};

void XchgWzemcmbd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgWzemcmbd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgWzemcmbd", "appendToLogfile");
};

void XchgWzemcmbd::addReq(
			ReqWzem* req
		) {
	if (jrefRoot == 0) return;

	mReqs.lock("XchgWzemcmbd", "addReq", "jref=" + to_string(req->jref));

	req->ixVState = ReqWzem::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgWzemcmbd", "addReq", "jref=" + to_string(req->jref));

	cJobprcs.signal("XchgWzemcmbd", "addReq", "jref=" + to_string(req->jref));
};

ReqWzem* XchgWzemcmbd::pullFirstReq() {
	ReqWzem* req;

	// get first element from list
	mReqs.lock("XchgWzemcmbd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqWzem::VecVState::PRC;
		reqs.pop_front();
	};

	mReqs.unlock("XchgWzemcmbd", "pullFirstReq");

	return req;
};

void XchgWzemcmbd::addInvs(
			DbsWzem* dbswzem
			, JobWzem* job
			, vector<DpchInvWzem*>& dpchinvs
		) {
	// append to inv list and signal the news (note the double-lock)
	mInvs.lock("XchgWzemcmbd", "addInvs", "jref=" + to_string(job->jref));
	job->mOps.lock("XchgWzemcmbd", "addInvs", "jref=" + to_string(job->jref));

	for (unsigned int i = 0; i < dpchinvs.size(); i++) {
		job->addOp(dbswzem, dpchinvs[i]);

		invs.push_back(dpchinvs[i]);

		mon.eventAddInv(job->jref, VecWzemVDpch::getSref(dpchinvs[i]->ixWzemVDpch), "", dpchinvs[i]->oref);
	};

	job->mOps.unlock("XchgWzemcmbd", "addInvs", "jref=" + to_string(job->jref));
	mInvs.unlock("XchgWzemcmbd", "addInvs", "jref=" + to_string(job->jref));

	cOpprcs.broadcast("XchgWzemcmbd", "addInvs", "jref=" + to_string(job->jref));
};

DpchInvWzem* XchgWzemcmbd::pullFirstInv() {
	DpchInvWzem* inv;

	// get first element from list
	mInvs.lock("XchgWzemcmbd", "pullFirstInv");

	inv = NULL;

	if (!invs.empty()) {
		inv = *(invs.begin());
		invs.pop_front();
	};

	mInvs.unlock("XchgWzemcmbd", "pullFirstInv");

	return inv;
};

Preset* XchgWzemcmbd::addPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	presetref_t pref(jref, ixWzemVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	preset = getPresetByPref(pref);

	rwmPresets.wlock("XchgWzemcmbd", "addPreset", "jref=" + to_string(jref));

	if (preset) {
		preset->arg = arg;

		mon.eventChangePreset(jref, VecWzemVPreset::getSref(ixWzemVPreset), arg);

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<presetref_t,Preset*>(pref, preset));

		mon.eventAddPreset(jref, VecWzemVPreset::getSref(ixWzemVPreset), arg);
	};

	rwmPresets.wunlock("XchgWzemcmbd", "addPreset", "jref=" + to_string(jref));

	return(preset);
};

Preset* XchgWzemcmbd::addIxPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgWzemcmbd::addRefPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgWzemcmbd::addRefsPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixWzemVPreset, jref, arg));
};

Preset* XchgWzemcmbd::addSrefPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgWzemcmbd::addIntvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgWzemcmbd::addDblvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgWzemcmbd::addBoolvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgWzemcmbd::addTxtvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixWzemVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgWzemcmbd::getPresetByPref(
			const presetref_t& pref
		) {
	Preset* preset = NULL;

	rwmPresets.rlock("XchgWzemcmbd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	rwmPresets.runlock("XchgWzemcmbd", "getPresetByPref");

	return preset;
};

Arg XchgWzemcmbd::getPreset(
			const uint ixWzemVPreset
			, ubigint jref
		) {
	Arg arg;

	Jobinfo* jobinfo = NULL;
	Preset* preset = NULL;

	if ( (ixWzemVPreset == VecWzemVPreset::PREWZEMSYSDATE) || (ixWzemVPreset == VecWzemVPreset::PREWZEMSYSTIME) || (ixWzemVPreset == VecWzemVPreset::PREWZEMSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		if (ixWzemVPreset == VecWzemVPreset::PREWZEMSYSSTAMP) {
			arg.mask = Arg::REF;
			arg.ref = rawtime;

		} else {
			arg.mask = Arg::INTVAL;

			if (ixWzemVPreset == VecWzemVPreset::PREWZEMSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
			else arg.intval = rawtime%(3600*24);
		};

	} else {
		rwmJobs.rlock("XchgWzemcmbd", "getPreset", "jref=" + to_string(jref));
		rwmPresets.rlock("XchgWzemcmbd", "getPreset", "jref=" + to_string(jref));

		jobinfo = getJobinfoByJref(jref);

		if (jobinfo && (ixWzemVPreset == VecWzemVPreset::PREWZEMIXLCL)) {
			arg.mask = Arg::IX;
			arg.ix = jobs[jref]->ixWzemVLocale;

		} else {
			while (jobinfo && !preset) {
				preset = getPresetByPref(presetref_t(jref, ixWzemVPreset));

				if (preset) arg = preset->arg;
				else {
					jref = jobinfo->jrefSup;
					jobinfo = getJobinfoByJref(jref);
				};
			};
		};

		rwmPresets.runlock("XchgWzemcmbd", "getPreset", "jref=" + to_string(jref));
		rwmJobs.runlock("XchgWzemcmbd", "getPreset", "jref=" + to_string(jref));
	};

	return(arg);
};

uint XchgWzemcmbd::getIxPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgWzemcmbd::getRefPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgWzemcmbd::getRefsPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgWzemcmbd::getSrefPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgWzemcmbd::getIntvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgWzemcmbd::getDblvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgWzemcmbd::getBoolvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgWzemcmbd::getTxtvalPreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixWzemVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgWzemcmbd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsWzemVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsWzemVPreset.clear();
	args.clear();

	rwmPresets.rlock("XchgWzemcmbd", "getPresetsByJref", "jref=" + to_string(jref));

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		preset = it->second;

		icsWzemVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	rwmPresets.runlock("XchgWzemcmbd", "getPresetsByJref", "jref=" + to_string(jref));
};

void XchgWzemcmbd::removePreset(
			const uint ixWzemVPreset
			, const ubigint jref
		) {
	rwmPresets.wlock("XchgWzemcmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxWzemVPreset=" + VecWzemVPreset::getSref(ixWzemVPreset));

	auto it = presets.find(presetref_t(jref, ixWzemVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);

		mon.eventRemovePreset(jref, VecWzemVPreset::getSref(ixWzemVPreset));
	};

	rwmPresets.wunlock("XchgWzemcmbd", "removePreset", "jref=" + to_string(jref) + ",srefIxWzemVPreset=" + VecWzemVPreset::getSref(ixWzemVPreset));
};

void XchgWzemcmbd::removePresetsByJref(
			const ubigint jref
		) {
	rwmPresets.wlock("XchgWzemcmbd", "removePresetsByJref", "jref=" + to_string(jref));

	uint ixVPreset;

	auto rng = presets.equal_range(presetref_t(jref, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVPreset = it->second->pref.ixVPreset;
		delete it->second;

		mon.eventRemovePreset(jref, VecWzemVPreset::getSref(ixVPreset));
	};
	presets.erase(rng.first, rng.second);

	rwmPresets.wunlock("XchgWzemcmbd", "removePresetsByJref", "jref=" + to_string(jref));
};

StmgrWzem* XchgWzemcmbd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrWzem* stmgr = NULL;

	// create new stmgr and append to stmgr list
	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		rwmStmgrs.wlock("XchgWzemcmbd", "addStmgr", "jref=" + to_string(jref));

		stmgr = new StmgrWzem(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;

		rwmStmgrs.wunlock("XchgWzemcmbd", "addStmgr", "jref=" + to_string(jref));

		mon.eventAddStmgr(jref);
	};

	return(stmgr);
};

StmgrWzem* XchgWzemcmbd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrWzem* stmgr = NULL;

	rwmStmgrs.rlock("XchgWzemcmbd", "getStmgrByJref", "jref=" + to_string(jref));

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgWzemcmbd", "getStmgrByJref");
	};

	rwmStmgrs.runlock("XchgWzemcmbd", "getStmgrByJref", "jref=" + to_string(jref));

	return(stmgr);
};

void XchgWzemcmbd::removeStmgrByJref(
			const ubigint jref
		) {
	rwmStmgrs.wlock("XchgWzemcmbd", "removeStmgrByJref", "jref=" + to_string(jref));

	removeClstnsByJref(jref, Clstn::VecVTarget::STMGR);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);

		mon.eventRemoveStmgr(jref);
	};

	rwmStmgrs.wunlock("XchgWzemcmbd", "removeStmgrByJref", "jref=" + to_string(jref));
};

Clstn* XchgWzemcmbd::addClstn(
			const uint ixWzemVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const Arg& arg
			, const uint ixVSge
			, const uint ixVJactype
		) {
	clstnref_t cref(ixWzemVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, arg, ixVSge);
	clstnref2_t cref2(cref);

	multimap<clstnref_t,Clstn*>::iterator it;
	Clstn* clstn = NULL;

	rwmClstns.wlock("XchgWzemcmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxWzemVCall=" + VecWzemVCall::getSref(ixWzemVCall));

	if (!chgarg) it = clstns.end();
	else {
		Arg argFind = arg;
		argFind.clearContent();

		clstnref_t crefFind(ixWzemVCall, jref, Clstn::VecVTarget::JOB, ixVJobmask, jrefTrig, argFind, ixVSge);

		it = clstns.find(crefFind);
	};

	if (it == clstns.end()) {
		// create new clstn and append to clstn list
		clstn = new Clstn(cref, ixVJactype);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		mon.eventAddClstn(jref, "job", VecWzemVCall::getSref(ixWzemVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));

	} else {
		// change clstn argument
		clstn = it->second;
		clstn->cref = cref;

		cref2sClstns.erase(clstnref2_t(it->first));
		clstns.erase(it->first);

		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));
		
		mon.eventChangeClstnArg(jref, "job", VecWzemVCall::getSref(ixWzemVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJactype::getSref(ixVJactype));
	};

	rwmClstns.wunlock("XchgWzemcmbd", "addClstn", "jref=" + to_string(jref) + ",srefIxWzemVCall=" + VecWzemVCall::getSref(ixWzemVCall));

	return(clstn);
};

Clstn* XchgWzemcmbd::addIxClstn(
			const uint ixWzemVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixWzemVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWzemcmbd::addRefClstn(
			const uint ixWzemVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixWzemVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWzemcmbd::addIxRefClstn(
			const uint ixWzemVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixWzemVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
		};

Clstn* XchgWzemcmbd::addIxRefSrefClstn(
			const uint ixWzemVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const bool chgarg
			, const uint ix
			, const ubigint ref
			, const string& sref
			, const uint ixVSge
			, const uint ixVJactype
		) {
	Arg arg(ix, ref, {}, sref, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixWzemVCall, jref, ixVJobmask, jrefTrig, chgarg, arg, ixVSge, ixVJactype));
};

Clstn* XchgWzemcmbd::addClstnStmgr(
			const uint ixWzemVCall
			, const ubigint jref
		) {
	clstnref_t cref(ixWzemVCall, jref, Clstn::VecVTarget::STMGR, Clstn::VecVJobmask::ALL);
	clstnref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	clstn = getClstnByCref(cref);

	if (!clstn) {
		rwmClstns.wlock("XchgWzemcmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWzemVCall=" + VecWzemVCall::getSref(ixWzemVCall));

		clstn = new Clstn(cref, Clstn::VecVJactype::LOCK);
		clstns.insert(pair<clstnref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<clstnref2_t,clstnref_t>(cref2, cref));

		rwmClstns.wunlock("XchgWzemcmbd", "addClstnStmgr", "jref=" + to_string(jref) + ",srefIxWzemVCall=" + VecWzemVCall::getSref(ixWzemVCall));

		mon.eventAddClstn(jref, "stmgr", VecWzemVCall::getSref(ixWzemVCall), Clstn::VecVJobmask::getSref(Clstn::VecVJobmask::ALL), 0, Arg(), 0, Clstn::VecVJactype::getSref(Clstn::VecVJactype::LOCK));
	};

	return(clstn);
};

Clstn* XchgWzemcmbd::getClstnByCref(
			const clstnref_t& cref
		) {
	Clstn* clstn = NULL;

	rwmClstns.rlock("XchgWzemcmbd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	rwmClstns.runlock("XchgWzemcmbd", "getClstnByCref");

	return clstn;
};

void XchgWzemcmbd::getClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
			, vector<uint>& icsWzemVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsWzemVCall.clear();
	icsVJobmask.clear();

	rwmClstns.rlock("XchgWzemcmbd", "getClstnsByJref", "jref=" + to_string(jref));

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsWzemVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	rwmClstns.runlock("XchgWzemcmbd", "getClstnsByJref", "jref=" + to_string(jref));
};

void XchgWzemcmbd::removeClstns(
			const uint ixWzemVCall
			, const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWzemcmbd", "removeClstns", "jref=" + to_string(jref));

	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = clstns.equal_range(clstnref_t(ixWzemVCall, jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		ixVJobmask = it->second->cref.ixVJobmask;
		jrefTrig = it->second->cref.jrefTrig;
		arg = it->second->cref.arg;
		ixVSge = it->second->cref.ixVSge;
		ixVJactype = it->second->ixVJactype;

		cref2sClstns.erase(clstnref2_t(it->first));
		delete it->second;

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWzemVCall::getSref(ixWzemVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	clstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWzemcmbd", "removeClstns", "jref=" + to_string(jref));
};

void XchgWzemcmbd::removeClstnsByJref(
			const ubigint jref
			, const uint ixVTarget
		) {
	rwmClstns.wlock("XchgWzemcmbd", "removeClstnsByJref", "jref=" + to_string(jref));

	uint ixVCall;
	uint ixVJobmask;
	ubigint jrefTrig;
	Arg arg;
	uint ixVSge;
	uint ixVJactype;

	auto rng = cref2sClstns.equal_range(clstnref2_t(jref, ixVTarget));
	for (auto it = rng.first; it != rng.second; it++) {
		auto it2 = clstns.find(it->second);

		ixVCall = it2->second->cref.ixVCall;
		ixVJobmask = it2->second->cref.ixVJobmask;
		jrefTrig = it2->second->cref.jrefTrig;
		arg = it2->second->cref.arg;
		ixVSge = it2->second->cref.ixVSge;
		ixVJactype = it2->second->ixVJactype;

		delete it2->second;
		clstns.erase(it2);

		mon.eventRemoveClstn(jref, Clstn::VecVTarget::getSref(ixVTarget), VecWzemVCall::getSref(ixVCall), Clstn::VecVJobmask::getSref(ixVJobmask), jrefTrig, arg, ixVSge, Clstn::VecVJobmask::getSref(ixVJactype));
	};
	cref2sClstns.erase(rng.first, rng.second);

	rwmClstns.wunlock("XchgWzemcmbd", "removeClstnsByJref", "jref=" + to_string(jref));
};

void XchgWzemcmbd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefTrigs
			, vector<ubigint>& jrefs
			, vector<uint>& icsVTarget
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	set<ubigint> jrefsClissrv;

	ubigint jrefTrig;
	bool match;

	rwmJobs.rlock("XchgWzemcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmClstns.rlock("XchgWzemcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));

	jrefsClissrv = getCsjobClisByJref(call->jref);
	jrefsClissrv.insert(call->jref);

	auto rng = clstns.equal_range(clstnref_t(call->ixVCall, 0));
	for (auto it = rng.first; it != rng.second; it++) {
		clstn = it->second;

		jrefTrig = call->jref;

		if (clstn->cref.ixVTarget == Clstn::VecVTarget::JOB) {
			match = true;

			if (clstn->cref.arg.mask & Arg::IX) if (clstn->cref.arg.ix != call->argInv.ix) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::REF) if (clstn->cref.arg.ref != call->argInv.ref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::INTVAL) if (clstn->cref.arg.intval != call->argInv.intval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::DBLVAL) if (clstn->cref.arg.dblval != call->argInv.dblval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::BOOLVAL) if (clstn->cref.arg.boolval != call->argInv.boolval) match = false;
			if (match) if (clstn->cref.arg.mask & Arg::TXTVAL) if (clstn->cref.arg.txtval != call->argInv.txtval) match = false;

			if (match) if (clstn->cref.ixVSge != 0) if (clstn->cref.ixVSge != jobinfos[clstn->cref.jref]->ixVSge) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about jrefsClissrv
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// check if trigger job is immediate sub-job to listener job
						if (clstn->cref.jref == jobinfos[*it]->jrefSup) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SELF) {
					// check if trigger job is equivalent to listener job
					if (clstn->cref.jref == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
						// require specific jref
						if (clstn->cref.jrefTrig == (*it)) {
							jrefTrig = *it;
							match = true;
							break;
						};
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					if (clstn->cref.jref == call->jref) match = true;
					else {
						for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
							// check if trigger job is down the tree from listener job
							if (getJobSup(clstn->cref.jref, *it)) {
								jrefTrig = *it;
								match = true;
								break;
							};
						};
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(clstn->ixVJactype);
			};

		} else if (clstn->cref.ixVTarget == Clstn::VecVTarget::STMGR) {
			jrefTrigs.push_back(jrefTrig);
			jrefs.push_back(clstn->cref.jref);
			icsVTarget.push_back(clstn->cref.ixVTarget);
			icsVJactype.push_back(0);

		} else {
			// targets DDSPUB and UASRV
			match = true;

			if (clstn->cref.arg.mask & Arg::SREF) if (clstn->cref.arg.sref != call->argInv.sref) match = false;

			if (match) if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
				match = false;

				for (auto it = jrefsClissrv.begin(); it != jrefsClissrv.end(); it++) {
					// require specific jref
					if (clstn->cref.jrefTrig == (*it)) {
						jrefTrig = *it;
						match = true;
						break;
					};
				};
			};

			if (match) {
				jrefTrigs.push_back(jrefTrig);
				jrefs.push_back(clstn->cref.jref);
				icsVTarget.push_back(clstn->cref.ixVTarget);
				icsVJactype.push_back(0);
			};
		};
	};

	rwmClstns.runlock("XchgWzemcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
	rwmJobs.runlock("XchgWzemcmbd", "findJrefsByCall", "jref=" + to_string(call->jref));
};

void XchgWzemcmbd::triggerCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	vector<ubigint> jrefTrigs;
	vector<ubigint> jrefs;
	vector<uint> icsVTarget;
	vector<uint> icsVJactype;

	uint ixVTarget;
	ubigint jref;
	uint ixVJactype;

	JobWzem* job = NULL;

	StmgrWzem* stmgr = NULL;

	ubigint eref;

	Arg argRet_old;

	eref = mon.eventTriggerCall(call->jref, VecWzemVCall::getSref(call->ixVCall), call->argInv);

	findJrefsByCall(call, jrefTrigs, jrefs, icsVTarget, icsVJactype);

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		call->jref = jrefTrigs[i];
		jref = jrefs[i];
		ixVTarget = icsVTarget[i];
		ixVJactype = icsVJactype[i];

		if (ixVTarget == Clstn::VecVTarget::JOB) {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgWzemcmbd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (!job->trylockAccess("XchgWzemcmbd", "triggerCall")) continue;
					};
				};

				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				job->handleCall(dbswzem, call);

				if (call->argRet != argRet_old) mon.eventRetCall(eref, jref, call->argRet);
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgWzemcmbd", "triggerCall");
			};

		} else if (ixVTarget == Clstn::VecVTarget::STMGR) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				mon.eventHandleCall(eref, jref);
				argRet_old = call->argRet;

				stmgr->handleCall(dbswzem, call);

				if (!(call->argRet == argRet_old)) mon.eventRetCall(eref, jref, call->argRet);

				stmgr->unlockAccess("XchgWzemcmbd", "triggerCall");
			};

		};

		if (call->abort) break;
	};

	mon.eventFinalizeCall(eref);
};

bool XchgWzemcmbd::triggerArgToArgCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

	call = new Call(ixWzemVCall, jref, argInv);
	triggerCall(dbswzem, call);

	argRet = call->argRet;
	retval = call->abort;

	delete call;
	return retval;
};

bool XchgWzemcmbd::triggerCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIxCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerRefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIntvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerBoolvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIxRefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIxSrefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIxSrefToIxCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;
	
	return retval;
};

bool XchgWzemcmbd::triggerIxIntvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIxDblvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerIxTxtvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const string& txtvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, txtvalInv, Arg::IX + Arg::TXTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerSrefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const string& srefInv
		) {
	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet));
};

bool XchgWzemcmbd::triggerToBoolvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWzemcmbd::triggerIxToBoolvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWzemcmbd::triggerRefToSrefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const ubigint refInv
			, string& srefRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) srefRet = argRet.sref;

	return(retval);
};

bool XchgWzemcmbd::triggerRefToBoolvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgWzemcmbd::triggerIxRefToIxCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWzemcmbd::triggerIxRefToRefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWzemcmbd::triggerIxRefSrefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWzemcmbd::triggerIxRefSrefIntvalCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgWzemcmbd::triggerIxRefSrefIntvalToRefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgWzemcmbd::triggerRefToIxCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgWzemcmbd::triggerSrefToRefCall(
			DbsWzem* dbswzem
			, const uint ixWzemVCall
			, const ubigint jref
			, const string& srefInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(0, 0, {}, srefInv, 0, 0.0, false, "", Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbswzem, ixWzemVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

DcolWzem* XchgWzemcmbd::addDcol(
			const ubigint jref
		) {
	JobWzem* job = NULL;

	DcolWzem* dcol = NULL;

	// create new dcol and append to dcol list
	rwmJobs.rlock("XchgWzemcmbd", "addDcol", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			rwmDcols.wlock("XchgWzemcmbd", "addDcol", "jref=" + to_string(jref));

			dcol = new DcolWzem(jref, job->ixWzemVLocale);
			dcols[jref] = dcol;

			dcol->lockAccess("XchgWzemcmbd", "addDcol");

			rwmDcols.wunlock("XchgWzemcmbd", "addDcol", "jref=" + to_string(jref));

			mon.eventAddDcol(jref);
		};
	};

	rwmJobs.runlock("XchgWzemcmbd", "addDcol", "jref=" + to_string(jref));

	// make dcol the session's active notify dcol
	triggerIxRefCall(NULL, VecWzemVCall::CALLWZEMREFPRESET, jref, VecWzemVPreset::PREWZEMJREFNOTIFY, jref);

	return(dcol);
};

DcolWzem* XchgWzemcmbd::getDcolByJref(
			ubigint jref
			, const bool tree
		) {
	Jobinfo* jobinfo = NULL;

	DcolWzem* dcol = NULL;

	rwmJobs.rlock("XchgWzemcmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmDcols.rlock("XchgWzemcmbd", "getDcolByJref", "jref=" + to_string(jref));

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo != NULL) {
		auto it = dcols.find(jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgWzemcmbd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	rwmDcols.runlock("XchgWzemcmbd", "getDcolByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWzemcmbd", "getDcolByJref", "jref=" + to_string(jref));

	return(dcol);
};

void XchgWzemcmbd::removeDcolByJref(
			const ubigint jref
		) {
	rwmDcols.wlock("XchgWzemcmbd", "removeDcolByJref", "jref=" + to_string(jref));

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);

		mon.eventRemoveDcol(jref);
	};

	rwmDcols.wunlock("XchgWzemcmbd", "removeDcolByJref", "jref=" + to_string(jref));
};

void XchgWzemcmbd::removeDcolsByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	vector<ubigint> jrefs;

	rwmJobs.rlock("XchgWzemcmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmDcols.wlock("XchgWzemcmbd", "removeDcolsByJref", "jref=" + to_string(jref));

	jrefs.push_back(jref);

	// sub-tree without recursion
	for (unsigned int i = 0; i < jrefs.size(); i++) {
		jobinfo = getJobinfoByJref(jrefs[i]);

		if (jobinfo) for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) jrefs.push_back(*it);
	};

	for (unsigned int i = 0; i < jrefs.size(); i++) {
		auto it = dcols.find(jrefs[i]);
		if (it != dcols.end()) {
			delete it->second;
			dcols.erase(it);

			mon.eventRemoveDcol(jrefs[i]);
		};
	};

	rwmDcols.wunlock("XchgWzemcmbd", "removeDcolsByJref", "jref=" + to_string(jref));
	rwmJobs.runlock("XchgWzemcmbd", "removeDcolsByJref", "jref=" + to_string(jref));
};

void XchgWzemcmbd::submitDpch(
			DpchEngWzem* dpcheng
		) {
	DcolWzem* dcol = NULL;

	Cond* cReady_backup;

	DpchEngWzem* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		mon.eventSubmitDpch(dpcheng->jref, VecWzemVDpch::getSref(dpcheng->ixWzemVDpch), dpcheng->getSrefsMask(), "");

		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);

			dcol->req = NULL;
			//cout << "XchgWzemcmbd::submitDpch() waiting request for ixWzemVDpch = " << dpcheng->ixWzemVDpch << ", jref = " << dpcheng->jref << endl;

			cReady_backup->signal("XchgWzemcmbd", "submitDpch", "jref=" + to_string(dcol->jref));

			dcol->unlockAccess("XchgWzemcmbd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixWzemVDpch == dpcheng->ixWzemVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgWzemcmbd::submitDpch() merge for ixWzemVDpch = " << dpcheng->ixWzemVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgWzemcmbd::submitDpch() append for ixWzemVDpch = " << dpcheng->ixWzemVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgWzemcmbd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngWzem* XchgWzemcmbd::pullFirstDpch(
			DcolWzem* dcol
		) {
	DpchEngWzem* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgWzemcmbd::addJob(
			DbsWzem* dbswzem
			, JobWzem* job
			, const ubigint jrefSup
		) {
	CsjobWzem* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob = getCsjobNotJob(job->ixWzemVJob);
	bool srvNotCli = false;

	// get new jref and append to job list
	rwmJobs.wlock("XchgWzemcmbd", "addJob", "jrefSup=" + to_string(jrefSup));

	job->jref = jrefseq.getNewRef();
	jobs[job->jref] = job;

	if (jobs.size() == 1) {
		// root job
		jrefRoot = job->jref;
		jrefCmd = job->jref;
	};

	ixWzemVJobs[job->jref] = job->ixWzemVJob;
	jobinfos[job->jref] = new Jobinfo(jrefSup);

	if (jrefSup != 0) jobinfos[jrefSup]->jrefsSub.insert(job->jref);

	if (csjobNotJob) {
		rwmCsjobinfos.wlock("XchgWzemcmbd", "addJob", "jref=" + to_string(job->jref));

		csjob = (CsjobWzem*) job;
		csjobinfo = csjobinfos[job->ixWzemVJob];

		if (jrefSup == jrefRoot) {
			csjob->srvNotCli = true;
			srvNotCli = true;
			
			csjobinfo->jrefSrv = job->jref;
			for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) {
				jobs[*it]->ixVSge = job->ixVSge;
				((CsjobWzem*) (jobs[*it]))->srv = csjob;
			};

		} else {
			csjob->srvNotCli = false;
			
			if (csjobinfo->jrefSrv != 0) {
				job->ixVSge = jobs[csjobinfo->jrefSrv]->ixVSge;
				csjob->srv = (CsjobWzem*) jobs[csjobinfo->jrefSrv];
			};
			csjobinfo->jrefsCli.insert(job->jref);
		};

		rwmCsjobinfos.wunlock("XchgWzemcmbd", "addJob", "jref=" + to_string(job->jref));
	};

	rwmJobs.wunlock("XchgWzemcmbd", "addJob", "jref=" + to_string(job->jref));

	mon.eventAddJob(jrefSup, VecWzemVJob::getSref(job->ixWzemVJob), job->jref, csjobNotJob, srvNotCli);

	return(job->jref);
};

JobWzem* XchgWzemcmbd::getJobByJref(
			const ubigint jref
		) {
	JobWzem* job = NULL;

	rwmJobs.rlock("XchgWzemcmbd", "getJobByJref", "jref=" + to_string(jref));

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	rwmJobs.runlock("XchgWzemcmbd", "getJobByJref", "jref=" + to_string(jref));

	return job;
};

Jobinfo* XchgWzemcmbd::getJobinfoByJref(
			const ubigint jref
		) {
	Jobinfo* jobinfo = NULL;

	rwmJobs.rlock("XchgWzemcmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	auto it = jobinfos.find(jref);
	if (it != jobinfos.end()) jobinfo = it->second;

	rwmJobs.runlock("XchgWzemcmbd", "getJobinfoByJref", "jref=" + to_string(jref));

	return jobinfo;
};

void XchgWzemcmbd::removeJobByJref(
			const ubigint jref
		) {
	JobWzem* job = NULL;
	Jobinfo* jobinfo = NULL;

	CsjobWzem* csjob = NULL;
	Csjobinfo* csjobinfo = NULL;

	bool csjobNotJob;

	rwmJobs.rlock("XchgWzemcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

	job = getJobByJref(jref);

	if (job) {
 		csjobNotJob = getCsjobNotJob(job->ixWzemVJob);

		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		if (csjobNotJob) {
			rwmCsjobinfos.rlock("XchgWzemcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			csjob = (CsjobWzem*) job;
			csjobinfo = csjobinfos[job->ixWzemVJob];

			removeCsjobClaim(NULL, csjob);

			rwmCsjobinfos.runlock("XchgWzemcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

			rwmCsjobinfos.wlock("XchgWzemcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

			if (csjob->srvNotCli) {
				csjobinfo->jrefSrv = 0;
				for (auto it = csjobinfo->jrefsCli.begin(); it != csjobinfo->jrefsCli.end(); it++) ((CsjobWzem*) (jobs[*it]))->srv = NULL;

			} else csjobinfo->jrefsCli.erase(jref);

			rwmCsjobinfos.wunlock("XchgWzemcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));
		};

		jobinfo = jobinfos[jref];

		rwmJobs.runlock("XchgWzemcmbd", "removeJobByJref[1]", "jref=" + to_string(jref));

		rwmJobs.wlock("XchgWzemcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		if (jobinfo->jrefSup != 0) jobinfos[jobinfo->jrefSup]->jrefsSub.erase(jref);

		rwmJobs.wunlock("XchgWzemcmbd", "removeJobByJref[2]", "jref=" + to_string(jref));

		while (jobinfo->jrefsSub.size() > 0) delete jobs[*(jobinfo->jrefsSub.begin())];

		rwmJobs.wlock("XchgWzemcmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);

		delete jobinfo;
		jobinfos.erase(jref);

		ixWzemVJobs.erase(jref);

		if (jobs.empty()) {
			// root job
			jrefRoot = 0;
			jrefCmd = 0;
		};

		rwmJobs.wunlock("XchgWzemcmbd", "removeJobByJref[3]", "jref=" + to_string(jref));

		mon.eventRemoveJob(jref);

	} else rwmJobs.wunlock("XchgWzemcmbd", "removeJobByJref[4]", "jref=" + to_string(jref));
};

bool XchgWzemcmbd::getJobSup(
			const ubigint jrefSup
			, ubigint jref
		) {
	bool retval = false;

	Jobinfo* jobinfo = NULL;

	jobinfo = getJobinfoByJref(jref);

	while (jobinfo) {
		if (jobinfo->jrefSup == jrefSup) {
			retval = true;
			break;
		};

		jref = jobinfo->jrefSup;
		jobinfo = getJobinfoByJref(jref);
	};

	return retval;
};

void XchgWzemcmbd::setJobStage(
			DbsWzem* dbswzem
			, JobWzem* job
			, const uint ixVSge
		) {
	set<ubigint> jrefsCli;

	bool csjobNotJob = getCsjobNotJob(job->ixWzemVJob);

	rwmJobs.rlock("XchgWzemcmbd", "setJobStage", "jref=" + to_string(job->jref));
	if (csjobNotJob) rwmCsjobinfos.rlock("XchgWzemcmbd", "setJobStage", "jref=" + to_string(job->jref));

	jobinfos[job->jref]->ixVSge = ixVSge;
	job->ixVSge = ixVSge;
	
	if (csjobNotJob) {
		jrefsCli = getCsjobClisByJref(job->jref);
		
		for (auto it = jrefsCli.begin(); it != jrefsCli.end(); it++) {
			jobinfos[*it]->ixVSge = ixVSge;
			jobs[*it]->ixVSge = ixVSge;
		};
	};

	if (csjobNotJob) rwmCsjobinfos.runlock("XchgWzemcmbd", "setJobStage", "jref=" + to_string(job->jref));
	rwmJobs.runlock("XchgWzemcmbd", "setJobStage", "jref=" + to_string(job->jref));

	triggerIxCall(dbswzem, VecWzemVCall::CALLWZEMSGECHG, job->jref, ixVSge);
};

void XchgWzemcmbd::addCsjobClaim(
			DbsWzem* dbswzem
			, CsjobWzem* csjob
			, Claim* claim
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWzemcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWzemVJob];

		rwmCsjobinfos.runlock("XchgWzemcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWzemcmbd", "addCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWzemcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) delete it->second;

		csjobinfo->claims[csjob->jref] = claim;

		mod = csjob->srv->handleClaim(dbswzem, csjobinfo->claims, csjob->jref);

		csjobinfo->mClaims.wunlock("XchgWzemcmbd", "addCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWzemcmbd", "addCsjobClaim");

		if (mod) triggerCall(dbswzem, VecWzemVCall::CALLWZEMCLAIMCHG, csjob->jref);
	};
};

bool XchgWzemcmbd::getCsjobClaim(
			CsjobWzem* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
			, bool& run
		) {
	bool retval = false;

	Csjobinfo* csjobinfo = NULL;;

	takenNotAvailable = false;
	fulfilled = false;
	run = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWzemcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWzemVJob];

		csjobinfo->mClaims.rlock("XchgWzemcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		retval = (it != csjobinfo->claims.end());

		if (retval) {
			takenNotAvailable = it->second->takenNotAvailable;
			fulfilled = it->second->fulfilled;
			run = it->second->run;
		};

		csjobinfo->mClaims.runlock("XchgWzemcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));

		rwmCsjobinfos.runlock("XchgWzemcmbd", "getCsjobClaim", "jref=" + to_string(csjob->jref));
	};

	return retval;
};

bool XchgWzemcmbd::getCsjobClaim(
			CsjobWzem* csjob
			, bool& takenNotAvailable
			, bool& fulfilled
		) {
	bool run;

	return getCsjobClaim(csjob, takenNotAvailable, fulfilled, run);
};

void XchgWzemcmbd::clearCsjobRun(
			DbsWzem* dbswzem
			, const uint ixWzemVJob
		) {
	Csjobinfo* csjobinfo = NULL;
	Claim* claim = NULL;

	bool mod = false;

	rwmCsjobinfos.rlock("XchgWzemcmbd", "clearCsjobRun", "srefIxWzemVJob=" + VecWzemVJob::getSref(ixWzemVJob));

	auto it = csjobinfos.find(ixWzemVJob);
	if (it != csjobinfos.end()) csjobinfo = it->second;

	rwmCsjobinfos.runlock("XchgWzemcmbd", "clearCsjobRun", "srefIxWzemVJob=" + VecWzemVJob::getSref(ixWzemVJob));

	if (csjobinfo) {
		csjobinfo->mClaims.wlock("XchgWzemcmbd", "clearCsjobRun", "srefIxWzemVJob=" + VecWzemVJob::getSref(ixWzemVJob));

		for (auto it2 = csjobinfo->claims.begin(); it2 != csjobinfo->claims.end(); it2++) {
			claim = it2->second;

			if (claim->run) {
				claim->run = false;
				mod = true;
			};
		};

		csjobinfo->mClaims.wunlock("XchgWzemcmbd", "clearCsjobRun", "srefIxWzemVJob=" + VecWzemVJob::getSref(ixWzemVJob));

		if (mod) triggerCall(dbswzem, VecWzemVCall::CALLWZEMCLAIMCHG, csjobinfo->jrefSrv);
	};
};

void XchgWzemcmbd::removeCsjobClaim(
			DbsWzem* dbswzem
			, CsjobWzem* csjob
		) {
	Csjobinfo* csjobinfo = NULL;;

	bool mod = false;

	if (!csjob->srvNotCli && csjob->srv) {
		rwmCsjobinfos.rlock("XchgWzemcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjobinfo = csjobinfos[csjob->ixWzemVJob];

		rwmCsjobinfos.runlock("XchgWzemcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->lockAccess("XchgWzemcmbd", "removeCsjobClaim");

		csjobinfo->mClaims.wlock("XchgWzemcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		auto it = csjobinfo->claims.find(csjob->jref);
		if (it != csjobinfo->claims.end()) {
			delete it->second;
			csjobinfo->claims.erase(it);

			mod = csjob->srv->handleClaim(dbswzem, csjobinfo->claims, 0);
		};

		csjobinfo->mClaims.wunlock("XchgWzemcmbd", "removeCsjobClaim", "jref=" + to_string(csjob->jref));

		csjob->srv->unlockAccess("XchgWzemcmbd", "removeCsjobClaim");

		if (mod) triggerCall(dbswzem, VecWzemVCall::CALLWZEMCLAIMCHG, csjobinfo->jrefSrv);
	};
};

bool XchgWzemcmbd::getCsjobNotJob(
			const uint ixWzemVJob
		) {
	bool retval;

	rwmCsjobinfos.rlock("XchgWzemcmbd", "getCsjobNotJob", "srefIxWzemVJob=" + VecWzemVJob::getSref(ixWzemVJob));

	retval = (csjobinfos.find(ixWzemVJob) != csjobinfos.end());

	rwmCsjobinfos.runlock("XchgWzemcmbd", "getCsjobNotJob", "srefIxWzemVJob=" + VecWzemVJob::getSref(ixWzemVJob));

	return retval;
};

set<ubigint> XchgWzemcmbd::getCsjobClisByJref(
			const ubigint jref
		) {
	set<ubigint> retval;

	rwmCsjobinfos.rlock("XchgWzemcmbd", "getCsjobClis", "jref=" + to_string(jref));

	auto it = csjobinfos.find(ixWzemVJobs[jref]);
	
	if (it != csjobinfos.end()) retval = it->second->jrefsCli;

	rwmCsjobinfos.runlock("XchgWzemcmbd", "getCsjobClis", "jref=" + to_string(jref));

	return retval;
};

ubigint XchgWzemcmbd::addWakeup(
			const ubigint jref
			, const string sref
			, const uint64_t deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq.getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqWzem* req = new ReqWzem(ReqWzem::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupWzem* wakeup = new WakeupWzem(this, wref, jref, sref, deltat, weak);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "XchgWzemcmbd::addWakeup() error creating timer thread (" << res << ")" << endl;
		else {
			res = pthread_detach(timer);
			if (res != 0) cout << "XchgWzemcmbd::addWakeup() error detaching timer thread (" << res << ")" << endl;
		};
	};

	return(wref);
};

void* XchgWzemcmbd::runWakeup(
			void* arg
		) {
	WakeupWzem* wakeup = (WakeupWzem*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqWzem* req = new ReqWzem(ReqWzem::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

void XchgWzemcmbd::runExtcall(
			void* arg
		) {
	ExtcallWzem* extcall = (ExtcallWzem*) arg;

	// generate request to be treated by job processor
	ReqWzem* req = new ReqWzem(ReqWzem::VecVBasetype::EXTCALL);
	req->call = new Call(*(extcall->call));

	extcall->xchg->addReq(req);
};
