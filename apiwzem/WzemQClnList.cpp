/**
	* \file WzemQClnList.cpp
	* API code for table TblWzemQClnList (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQClnList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQClnList
 ******************************************************************************/

WzemQClnList::WzemQClnList(
			const uint jnum
			, const string stubRefWzemMJob
			, const string srefIxVCall
			, const string srefIxVSge
			, const double x1Startu
			, const double x1Stopu
		) {
	this->jnum = jnum;
	this->stubRefWzemMJob = stubRefWzemMJob;
	this->srefIxVCall = srefIxVCall;
	this->srefIxVSge = srefIxVSge;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
};

bool WzemQClnList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQClnList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzemMJob", "job", stubRefWzemMJob);
		extractStringUclc(docctx, basexpath, "srefIxVCall", "cal", srefIxVCall);
		extractStringUclc(docctx, basexpath, "srefIxVSge", "sge", srefIxVSge);
		extractDoubleUclc(docctx, basexpath, "x1Startu", "sta", x1Startu);
		extractDoubleUclc(docctx, basexpath, "x1Stopu", "sto", x1Stopu);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQClnList
 ******************************************************************************/

ListWzemQClnList::ListWzemQClnList() {
};

ListWzemQClnList::ListWzemQClnList(
			const ListWzemQClnList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQClnList(*(src.nodes[i]));
};

ListWzemQClnList& ListWzemQClnList::operator=(
			const ListWzemQClnList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQClnList(*(src.nodes[i]));

	return *this;
};

ListWzemQClnList::~ListWzemQClnList() {
	clear();
};

void ListWzemQClnList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQClnList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQClnList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQClnList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQClnList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQClnList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQClnList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

