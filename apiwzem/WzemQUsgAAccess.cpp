/**
	* \file WzemQUsgAAccess.cpp
	* API code for table TblWzemQUsgAAccess (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQUsgAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsgAAccess
 ******************************************************************************/

WzemQUsgAAccess::WzemQUsgAAccess(
			const uint jnum
			, const string srefX1IxWzemVFeatgroup
			, const string titX1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const string srefsIxWzemWAccess
			, const string titsIxWzemWAccess
		) {
	this->jnum = jnum;
	this->srefX1IxWzemVFeatgroup = srefX1IxWzemVFeatgroup;
	this->titX1IxWzemVFeatgroup = titX1IxWzemVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->srefsIxWzemWAccess = srefsIxWzemWAccess;
	this->titsIxWzemWAccess = titsIxWzemWAccess;
};

bool WzemQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxWzemVFeatgroup", "feg", srefX1IxWzemVFeatgroup);
		extractStringUclc(docctx, basexpath, "titX1IxWzemVFeatgroup", "feg2", titX1IxWzemVFeatgroup);
		extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix);
		extractStringUclc(docctx, basexpath, "srefsIxWzemWAccess", "acc", srefsIxWzemWAccess);
		extractStringUclc(docctx, basexpath, "titsIxWzemWAccess", "acc2", titsIxWzemWAccess);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQUsgAAccess
 ******************************************************************************/

ListWzemQUsgAAccess::ListWzemQUsgAAccess() {
};

ListWzemQUsgAAccess::ListWzemQUsgAAccess(
			const ListWzemQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsgAAccess(*(src.nodes[i]));
};

ListWzemQUsgAAccess& ListWzemQUsgAAccess::operator=(
			const ListWzemQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsgAAccess(*(src.nodes[i]));

	return *this;
};

ListWzemQUsgAAccess::~ListWzemQUsgAAccess() {
	clear();
};

void ListWzemQUsgAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQUsgAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQUsgAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQUsgAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQUsgAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQUsgAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQUsgAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

