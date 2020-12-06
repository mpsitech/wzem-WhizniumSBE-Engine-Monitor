/**
	* \file WzemQPrd1NEvent.cpp
	* API code for table TblWzemQPrd1NEvent (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQPrd1NEvent.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPrd1NEvent
 ******************************************************************************/

WzemQPrd1NEvent::WzemQPrd1NEvent(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzemQPrd1NEvent::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQPrd1NEvent");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQPrd1NEvent
 ******************************************************************************/

ListWzemQPrd1NEvent::ListWzemQPrd1NEvent() {
};

ListWzemQPrd1NEvent::ListWzemQPrd1NEvent(
			const ListWzemQPrd1NEvent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrd1NEvent(*(src.nodes[i]));
};

ListWzemQPrd1NEvent& ListWzemQPrd1NEvent::operator=(
			const ListWzemQPrd1NEvent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrd1NEvent(*(src.nodes[i]));

	return *this;
};

ListWzemQPrd1NEvent::~ListWzemQPrd1NEvent() {
	clear();
};

void ListWzemQPrd1NEvent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQPrd1NEvent::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQPrd1NEvent* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQPrd1NEvent");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQPrd1NEvent", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQPrd1NEvent(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQPrd1NEvent[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

