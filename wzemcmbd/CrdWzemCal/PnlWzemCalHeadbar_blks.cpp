/**
	* \file PnlWzemCalHeadbar_blks.cpp
	* job handler for job PnlWzemCalHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemCalHeadbar::StgInf
 ******************************************************************************/

void PnlWzemCalHeadbar::StgInf::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfWzemCalHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["MenAppCptwidth"] = "270";
		me["MenAppWidth"] = "295";
		me["MenCrdCptwidth"] = "46";
		me["MenCrdWidth"] = "323";
	};
};

void PnlWzemCalHeadbar::StgInf::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfWzemCalHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfWzemCalHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "270");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "295");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "46");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "323");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemCalHeadbar::Tag
 ******************************************************************************/

void PnlWzemCalHeadbar::Tag::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzemCalHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["MenApp"] = "WhizniumSBE Engine Monitor";
		me["MenCrd"] = "Call";
	};
};

void PnlWzemCalHeadbar::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemCalHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemCalHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "WhizniumSBE Engine Monitor");
			writeStringAttr(wr, itemtag, "sref", "MenCrd", "Call");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemCalHeadbar::DpchEngData
 ******************************************************************************/

PnlWzemCalHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMCALHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STGINF, TAG};
	else this->mask = mask;

};

string PnlWzemCalHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemCalHeadbar::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlWzemCalHeadbar::DpchEngData::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemCalHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STGINF)) StgInf::writeJSON(ixWzemVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixWzemVLocale, me);
};

void PnlWzemCalHeadbar::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemCalHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STGINF)) StgInf::writeXML(ixWzemVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};
