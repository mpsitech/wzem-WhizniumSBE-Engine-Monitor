/**
	* \file SessWzem.cpp
	* API code for job SessWzem (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "SessWzem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessWzem::StatShr
 ******************************************************************************/

SessWzem::StatShr::StatShr(
			const string& scrJrefCrdnav
		) :
			Block()
		{
	this->scrJrefCrdnav = scrJrefCrdnav;

	mask = {SCRJREFCRDNAV};
};

bool SessWzem::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrSessWzem");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrSessWzem";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", scrJrefCrdnav)) add(SCRJREFCRDNAV);
	};

	return basefound;
};

set<uint> SessWzem::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefCrdnav == comp->scrJrefCrdnav) insert(items, SCRJREFCRDNAV);

	return(items);
};

set<uint> SessWzem::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessWzem::DpchEngData
 ******************************************************************************/

SessWzem::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGSESSWZEMDATA)
		{
	feedFEnsSec.tag = "FeedFEnsSec";
};

string SessWzem::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessWzem::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngSessWzemData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSec.readXML(docctx, basexpath, true)) add(FEEDFENSSEC);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		feedFEnsSec.clear();
		statshr = StatShr();
	};
};

