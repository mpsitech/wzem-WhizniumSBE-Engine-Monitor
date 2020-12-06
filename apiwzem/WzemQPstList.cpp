/**
	* \file WzemQPstList.cpp
	* API code for table TblWzemQPstList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQPstList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPstList
 ******************************************************************************/

WzemQPstList::WzemQPstList(
			const uint jnum
			, const string stubRefWzemMJob
			, const string srefIxVPreset
			, const double x1Startu
			, const double x1Stopu
		) {
	this->jnum = jnum;
	this->stubRefWzemMJob = stubRefWzemMJob;
	this->srefIxVPreset = srefIxVPreset;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
};

bool WzemQPstList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQPstList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzemMJob", "job", stubRefWzemMJob);
		extractStringUclc(docctx, basexpath, "srefIxVPreset", "pst", srefIxVPreset);
		extractDoubleUclc(docctx, basexpath, "x1Startu", "sta", x1Startu);
		extractDoubleUclc(docctx, basexpath, "x1Stopu", "sto", x1Stopu);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQPstList
 ******************************************************************************/

ListWzemQPstList::ListWzemQPstList() {
};

ListWzemQPstList::ListWzemQPstList(
			const ListWzemQPstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPstList(*(src.nodes[i]));
};

ListWzemQPstList& ListWzemQPstList::operator=(
			const ListWzemQPstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPstList(*(src.nodes[i]));

	return *this;
};

ListWzemQPstList::~ListWzemQPstList() {
	clear();
};

void ListWzemQPstList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQPstList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQPstList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQPstList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQPstList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQPstList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQPstList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
