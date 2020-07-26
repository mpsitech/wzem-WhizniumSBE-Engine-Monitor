/**
	* \file WzemQPrsList.cpp
	* API code for table TblWzemQPrsList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemQPrsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPrsList
 ******************************************************************************/

WzemQPrsList::WzemQPrsList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

bool WzemQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname);
		extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname);
		extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex);
		extractStringUclc(docctx, basexpath, "titIxVSex", "sex2", titIxVSex);
		extractStringUclc(docctx, basexpath, "telVal", "tel", telVal);
		extractStringUclc(docctx, basexpath, "emlVal", "eml", emlVal);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQPrsList
 ******************************************************************************/

ListWzemQPrsList::ListWzemQPrsList() {
};

ListWzemQPrsList::ListWzemQPrsList(
			const ListWzemQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrsList(*(src.nodes[i]));
};

ListWzemQPrsList& ListWzemQPrsList::operator=(
			const ListWzemQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrsList(*(src.nodes[i]));

	return *this;
};

ListWzemQPrsList::~ListWzemQPrsList() {
	clear();
};

void ListWzemQPrsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQPrsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQPrsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQPrsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQPrsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

