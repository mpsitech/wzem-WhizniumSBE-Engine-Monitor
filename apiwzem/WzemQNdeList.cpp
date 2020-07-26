/**
	* \file WzemQNdeList.cpp
	* API code for table TblWzemQNdeList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemQNdeList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQNdeList
 ******************************************************************************/

WzemQNdeList::WzemQNdeList(
			const uint jnum
			, const string stubRefWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const double x1Startu
			, const double x1Stopu
			, const usmallint Port
			, const utinyint Opprcn
		) {
	this->jnum = jnum;
	this->stubRefWzemMPeriod = stubRefWzemMPeriod;
	this->xnref = xnref;
	this->Ip = Ip;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->Port = Port;
	this->Opprcn = Opprcn;
};

bool WzemQNdeList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQNdeList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzemMPeriod", "prd", stubRefWzemMPeriod);
		extractUbigintUclc(docctx, basexpath, "xnref", "xnr", xnref);
		extractStringUclc(docctx, basexpath, "Ip", "ip", Ip);
		extractDoubleUclc(docctx, basexpath, "x1Startu", "sta", x1Startu);
		extractDoubleUclc(docctx, basexpath, "x1Stopu", "sto", x1Stopu);
		extractUsmallintUclc(docctx, basexpath, "Port", "prt", Port);
		extractUtinyintUclc(docctx, basexpath, "Opprcn", "orn", Opprcn);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQNdeList
 ******************************************************************************/

ListWzemQNdeList::ListWzemQNdeList() {
};

ListWzemQNdeList::ListWzemQNdeList(
			const ListWzemQNdeList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQNdeList(*(src.nodes[i]));
};

ListWzemQNdeList& ListWzemQNdeList::operator=(
			const ListWzemQNdeList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQNdeList(*(src.nodes[i]));

	return *this;
};

ListWzemQNdeList::~ListWzemQNdeList() {
	clear();
};

void ListWzemQNdeList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQNdeList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQNdeList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQNdeList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQNdeList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQNdeList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQNdeList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

