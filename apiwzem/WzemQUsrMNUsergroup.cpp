/**
	* \file WzemQUsrMNUsergroup.cpp
	* API code for table TblWzemQUsrMNUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQUsrMNUsergroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsrMNUsergroup
 ******************************************************************************/

WzemQUsrMNUsergroup::WzemQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxWzemVUserlevel = srefIxWzemVUserlevel;
	this->titIxWzemVUserlevel = titIxWzemVUserlevel;
};

bool WzemQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxWzemVUserlevel", "ulv", srefIxWzemVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWzemVUserlevel", "ulv2", titIxWzemVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQUsrMNUsergroup
 ******************************************************************************/

ListWzemQUsrMNUsergroup::ListWzemQUsrMNUsergroup() {
};

ListWzemQUsrMNUsergroup::ListWzemQUsrMNUsergroup(
			const ListWzemQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrMNUsergroup(*(src.nodes[i]));
};

ListWzemQUsrMNUsergroup& ListWzemQUsrMNUsergroup::operator=(
			const ListWzemQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListWzemQUsrMNUsergroup::~ListWzemQUsrMNUsergroup() {
	clear();
};

void ListWzemQUsrMNUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

