/**
	* \file WzemQUsrAAccess.cpp
	* API code for table TblWzemQUsrAAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsrAAccess
 ******************************************************************************/

WzemQUsrAAccess::WzemQUsrAAccess(
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

bool WzemQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQUsrAAccess");
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
 class ListWzemQUsrAAccess
 ******************************************************************************/

ListWzemQUsrAAccess::ListWzemQUsrAAccess() {
};

ListWzemQUsrAAccess::ListWzemQUsrAAccess(
			const ListWzemQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrAAccess(*(src.nodes[i]));
};

ListWzemQUsrAAccess& ListWzemQUsrAAccess::operator=(
			const ListWzemQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListWzemQUsrAAccess::~ListWzemQUsrAAccess() {
	clear();
};

void ListWzemQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

