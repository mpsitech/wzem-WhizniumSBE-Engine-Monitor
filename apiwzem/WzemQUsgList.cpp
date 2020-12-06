/**
	* \file WzemQUsgList.cpp
	* API code for table TblWzemQUsgList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQUsgList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsgList
 ******************************************************************************/

WzemQUsgList::WzemQUsgList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string sref
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->sref = sref;
};

bool WzemQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQUsgList
 ******************************************************************************/

ListWzemQUsgList::ListWzemQUsgList() {
};

ListWzemQUsgList::ListWzemQUsgList(
			const ListWzemQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsgList(*(src.nodes[i]));
};

ListWzemQUsgList& ListWzemQUsgList::operator=(
			const ListWzemQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsgList(*(src.nodes[i]));

	return *this;
};

ListWzemQUsgList::~ListWzemQUsgList() {
	clear();
};

void ListWzemQUsgList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQUsgList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQUsgList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQUsgList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQUsgList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

