/**
	* \file WzemQPrd1NJob.cpp
	* API code for table TblWzemQPrd1NJob (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQPrd1NJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPrd1NJob
 ******************************************************************************/

WzemQPrd1NJob::WzemQPrd1NJob(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzemQPrd1NJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzemQPrd1NJob");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzemQPrd1NJob
 ******************************************************************************/

ListWzemQPrd1NJob::ListWzemQPrd1NJob() {
};

ListWzemQPrd1NJob::ListWzemQPrd1NJob(
			const ListWzemQPrd1NJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrd1NJob(*(src.nodes[i]));
};

ListWzemQPrd1NJob& ListWzemQPrd1NJob::operator=(
			const ListWzemQPrd1NJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrd1NJob(*(src.nodes[i]));

	return *this;
};

ListWzemQPrd1NJob::~ListWzemQPrd1NJob() {
	clear();
};

void ListWzemQPrd1NJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzemQPrd1NJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzemQPrd1NJob* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzemQPrd1NJob");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzemQPrd1NJob", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzemQPrd1NJob(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzemQPrd1NJob[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

