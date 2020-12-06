/**
	* \file WzemQCalList.cpp
	* API code for table TblWzemQCalList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQCalList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQCalList
 ******************************************************************************/

WzemQCalList::WzemQCalList(
			const uint jnum
			, const string stubRefWzemMJob
			, const string srefIxVCall
			, const double x1Startu
			, const double x1Stopu
		) {
	this->jnum = jnum;
	this->stubRefWzemMJob = stubRefWzemMJob;
	this->srefIxVCall = srefIxVCall;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
};

bool WzemQCalList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQCalList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzemMJob", "job", stubRefWzemMJob);
		extractStringUclc(docctx, basexpath, "srefIxVCall", "cal", srefIxVCall);
		extractDoubleUclc(docctx, basexpath, "x1Startu", "sta", x1Startu);
		extractDoubleUclc(docctx, basexpath, "x1Stopu", "sto", x1Stopu);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQCalList
 ******************************************************************************/

ListWzemQCalList::ListWzemQCalList() {
};

ListWzemQCalList::ListWzemQCalList(
			const ListWzemQCalList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQCalList(*(src.nodes[i]));
};

ListWzemQCalList& ListWzemQCalList::operator=(
			const ListWzemQCalList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQCalList(*(src.nodes[i]));

	return *this;
};

ListWzemQCalList::~ListWzemQCalList() {
	clear();
};

void ListWzemQCalList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQCalList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQCalList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQCalList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQCalList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQCalList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQCalList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
