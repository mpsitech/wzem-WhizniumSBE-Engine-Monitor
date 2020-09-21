/**
	* \file WzemQJob1NOp.cpp
	* API code for table TblWzemQJob1NOp (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQJob1NOp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQJob1NOp
 ******************************************************************************/

WzemQJob1NOp::WzemQJob1NOp(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzemQJob1NOp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQJob1NOp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQJob1NOp
 ******************************************************************************/

ListWzemQJob1NOp::ListWzemQJob1NOp() {
};

ListWzemQJob1NOp::ListWzemQJob1NOp(
			const ListWzemQJob1NOp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQJob1NOp(*(src.nodes[i]));
};

ListWzemQJob1NOp& ListWzemQJob1NOp::operator=(
			const ListWzemQJob1NOp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQJob1NOp(*(src.nodes[i]));

	return *this;
};

ListWzemQJob1NOp::~ListWzemQJob1NOp() {
	clear();
};

void ListWzemQJob1NOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQJob1NOp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQJob1NOp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQJob1NOp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQJob1NOp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQJob1NOp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQJob1NOp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

