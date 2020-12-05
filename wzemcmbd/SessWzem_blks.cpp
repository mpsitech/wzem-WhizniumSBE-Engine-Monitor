/**
	* \file SessWzem_blks.cpp
	* job handler for job SessWzem (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessWzem::StatShr
 ******************************************************************************/

SessWzem::StatShr::StatShr(
			const ubigint jrefCrdnav
		) :
			Block()
		{
	this->jrefCrdnav = jrefCrdnav;

	mask = {JREFCRDNAV};
};

void SessWzem::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrSessWzem";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrSessWzem";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefCrdnav", Scr::scramble(jrefCrdnav));
	xmlTextWriterEndElement(wr);
};

set<uint> SessWzem::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefCrdnav == comp->jrefCrdnav) insert(items, JREFCRDNAV);

	return(items);
};

set<uint> SessWzem::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessWzem::DpchEngData
 ******************************************************************************/

SessWzem::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSec
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGSESSWZEMDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSEC, STATSHR};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSEC) && feedFEnsSec) this->feedFEnsSec = *feedFEnsSec;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string SessWzem::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessWzem::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSEC)) {feedFEnsSec = src->feedFEnsSec; add(FEEDFENSSEC);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void SessWzem::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngSessWzemData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSEC)) feedFEnsSec.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

