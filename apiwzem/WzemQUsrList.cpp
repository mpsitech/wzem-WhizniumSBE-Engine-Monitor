/**
	* \file WzemQUsrList.cpp
	* API code for table TblWzemQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsrList
 ******************************************************************************/

WzemQUsrList::WzemQUsrList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubRefWzemMPerson
			, const string sref
			, const string stubRefWzemMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxWzemVLocale
			, const string titIxWzemVLocale
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->stubRefWzemMPerson = stubRefWzemMPerson;
	this->sref = sref;
	this->stubRefWzemMUsergroup = stubRefWzemMUsergroup;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->srefIxWzemVLocale = srefIxWzemVLocale;
	this->titIxWzemVLocale = titIxWzemVLocale;
	this->srefIxWzemVUserlevel = srefIxWzemVUserlevel;
	this->titIxWzemVUserlevel = titIxWzemVUserlevel;
};

bool WzemQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubRefWzemMPerson", "prs", stubRefWzemMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWzemMUsergroup", "usg", stubRefWzemMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxWzemVLocale", "lcl", srefIxWzemVLocale);
		extractStringUclc(docctx, basexpath, "titIxWzemVLocale", "lcl2", titIxWzemVLocale);
		extractStringUclc(docctx, basexpath, "srefIxWzemVUserlevel", "ulv", srefIxWzemVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWzemVUserlevel", "ulv2", titIxWzemVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQUsrList
 ******************************************************************************/

ListWzemQUsrList::ListWzemQUsrList() {
};

ListWzemQUsrList::ListWzemQUsrList(
			const ListWzemQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrList(*(src.nodes[i]));
};

ListWzemQUsrList& ListWzemQUsrList::operator=(
			const ListWzemQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrList(*(src.nodes[i]));

	return *this;
};

ListWzemQUsrList::~ListWzemQUsrList() {
	clear();
};

void ListWzemQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

