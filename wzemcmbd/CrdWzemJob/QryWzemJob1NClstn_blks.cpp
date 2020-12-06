/**
	* \file QryWzemJob1NClstn_blks.cpp
	* job handler for job QryWzemJob1NClstn (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWzemJob1NClstn::StatApp
 ******************************************************************************/

void QryWzemJob1NClstn::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) {
	if (difftag.length() == 0) difftag = "StatAppQryWzemJob1NClstn";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppQryWzemJob1NClstn";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "firstcol", firstcol);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstdisp", jnumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "ncol", ncol);
		writeUintAttr(wr, itemtag, "sref", "ndisp", ndisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class QryWzemJob1NClstn::StatShr
 ******************************************************************************/

QryWzemJob1NClstn::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

void QryWzemJob1NClstn::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrQryWzemJob1NClstn";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrQryWzemJob1NClstn";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "ntot", ntot);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWzemJob1NClstn::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWzemJob1NClstn::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWzemJob1NClstn::StgIac
 ******************************************************************************/

QryWzemJob1NClstn::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;
	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWzemJob1NClstn::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWzemJob1NClstn");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWzemJob1NClstn";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWzemJob1NClstn::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWzemJob1NClstn";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWzemJob1NClstn";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWzemJob1NClstn::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWzemJob1NClstn::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};







