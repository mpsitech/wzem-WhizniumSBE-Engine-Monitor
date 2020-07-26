/**
	* \file WzemQOpxList.cpp
	* API code for table TblWzemQOpxList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemQOpxList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQOpxList
 ******************************************************************************/

WzemQOpxList::WzemQOpxList(
			const uint jnum
			, const string stubRefWzemMJob
			, const ubigint xoref
			, const double x1Startu
			, const double x1Stopu
		) {
	this->jnum = jnum;
	this->stubRefWzemMJob = stubRefWzemMJob;
	this->xoref = xoref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
};

bool WzemQOpxList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQOpxList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzemMJob", "job", stubRefWzemMJob);
		extractUbigintUclc(docctx, basexpath, "xoref", "xor", xoref);
		extractDoubleUclc(docctx, basexpath, "x1Startu", "sta", x1Startu);
		extractDoubleUclc(docctx, basexpath, "x1Stopu", "sto", x1Stopu);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQOpxList
 ******************************************************************************/

ListWzemQOpxList::ListWzemQOpxList() {
};

ListWzemQOpxList::ListWzemQOpxList(
			const ListWzemQOpxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQOpxList(*(src.nodes[i]));
};

ListWzemQOpxList& ListWzemQOpxList::operator=(
			const ListWzemQOpxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQOpxList(*(src.nodes[i]));

	return *this;
};

ListWzemQOpxList::~ListWzemQOpxList() {
	clear();
};

void ListWzemQOpxList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQOpxList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQOpxList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQOpxList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQOpxList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQOpxList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQOpxList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

