/**
	* \file WzemQEvtList.cpp
	* API code for table TblWzemQEvtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQEvtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQEvtList
 ******************************************************************************/

WzemQEvtList::WzemQEvtList(
			const uint jnum
			, const string srefIxVBasetype
			, const string stubRefWzemMPeriod
			, const double startu
			, const string Cmd
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {
	this->jnum = jnum;
	this->srefIxVBasetype = srefIxVBasetype;
	this->stubRefWzemMPeriod = stubRefWzemMPeriod;
	this->startu = startu;
	this->Cmd = Cmd;
	this->srefIxVFeatgroup = srefIxVFeatgroup;
	this->srefIxVMethod = srefIxVMethod;
	this->xsref = xsref;
};

bool WzemQEvtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQEvtList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWzemMPeriod", "prd", stubRefWzemMPeriod);
		extractDoubleUclc(docctx, basexpath, "startu", "sta", startu);
		extractStringUclc(docctx, basexpath, "Cmd", "cmd", Cmd);
		extractStringUclc(docctx, basexpath, "srefIxVFeatgroup", "feg", srefIxVFeatgroup);
		extractStringUclc(docctx, basexpath, "srefIxVMethod", "mtd", srefIxVMethod);
		extractStringUclc(docctx, basexpath, "xsref", "xsr", xsref);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQEvtList
 ******************************************************************************/

ListWzemQEvtList::ListWzemQEvtList() {
};

ListWzemQEvtList::ListWzemQEvtList(
			const ListWzemQEvtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQEvtList(*(src.nodes[i]));
};

ListWzemQEvtList& ListWzemQEvtList::operator=(
			const ListWzemQEvtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQEvtList(*(src.nodes[i]));

	return *this;
};

ListWzemQEvtList::~ListWzemQEvtList() {
	clear();
};

void ListWzemQEvtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQEvtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQEvtList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQEvtList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQEvtList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQEvtList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQEvtList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

