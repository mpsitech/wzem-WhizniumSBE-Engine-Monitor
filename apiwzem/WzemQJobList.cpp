/**
	* \file WzemQJobList.cpp
	* API code for table TblWzemQJobList (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQJobList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQJobList
 ******************************************************************************/

WzemQJobList::WzemQJobList(
			const uint jnum
			, const string stubRefWzemMPeriod
			, const string srefIxVJob
			, const ubigint xjref
			, const double x1Startu
			, const double x1Stopu
			, const string stubSupRefWzemMJob
		) {
	this->jnum = jnum;
	this->stubRefWzemMPeriod = stubRefWzemMPeriod;
	this->srefIxVJob = srefIxVJob;
	this->xjref = xjref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->stubSupRefWzemMJob = stubSupRefWzemMJob;
};

bool WzemQJobList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzemMPeriod", "prd", stubRefWzemMPeriod);
		extractStringUclc(docctx, basexpath, "srefIxVJob", "job", srefIxVJob);
		extractUbigintUclc(docctx, basexpath, "xjref", "xjr", xjref);
		extractDoubleUclc(docctx, basexpath, "x1Startu", "sta", x1Startu);
		extractDoubleUclc(docctx, basexpath, "x1Stopu", "sto", x1Stopu);
		extractStringUclc(docctx, basexpath, "stubSupRefWzemMJob", "sup", stubSupRefWzemMJob);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQJobList
 ******************************************************************************/

ListWzemQJobList::ListWzemQJobList() {
};

ListWzemQJobList::ListWzemQJobList(
			const ListWzemQJobList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQJobList(*(src.nodes[i]));
};

ListWzemQJobList& ListWzemQJobList::operator=(
			const ListWzemQJobList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQJobList(*(src.nodes[i]));

	return *this;
};

ListWzemQJobList::~ListWzemQJobList() {
	clear();
};

void ListWzemQJobList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQJobList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQJobList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQJobList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQJobList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQJobList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQJobList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

