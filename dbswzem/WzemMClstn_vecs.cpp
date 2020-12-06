/**
	* \file WzemMClstn_vecs.cpp
	* database access for table TblWzemMClstn (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzemMClstn::VecVJactype
 ******************************************************************************/

uint TblWzemMClstn::VecVJactype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "lock") return LOCK;
	if (s == "try") return TRY;
	if (s == "weak") return WEAK;

	return(0);
};

string TblWzemMClstn::VecVJactype::getSref(
			const uint ix
		) {
	if (ix == LOCK) return("lock");
	if (ix == TRY) return("try");
	if (ix == WEAK) return("weak");

	return("");
};

void TblWzemMClstn::VecVJactype::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class TblWzemMClstn::VecVJobmask
 ******************************************************************************/

uint TblWzemMClstn::VecVJobmask::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "all") return ALL;
	if (s == "imm") return IMM;
	if (s == "mast") return MAST;
	if (s == "self") return SELF;
	if (s == "slv") return SLV;
	if (s == "spec") return SPEC;
	if (s == "tree") return TREE;

	return(0);
};

string TblWzemMClstn::VecVJobmask::getSref(
			const uint ix
		) {
	if (ix == ALL) return("all");
	if (ix == IMM) return("imm");
	if (ix == MAST) return("mast");
	if (ix == SELF) return("self");
	if (ix == SLV) return("slv");
	if (ix == SPEC) return("spec");
	if (ix == TREE) return("tree");

	return("");
};

void TblWzemMClstn::VecVJobmask::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class TblWzemMClstn::VecVTarget
 ******************************************************************************/

uint TblWzemMClstn::VecVTarget::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "job") return JOB;
	if (s == "stmgr") return STMGR;
	if (s == "ddspub") return DDSPUB;
	if (s == "uasrv") return UASRV;

	return(0);
};

string TblWzemMClstn::VecVTarget::getSref(
			const uint ix
		) {
	if (ix == JOB) return("job");
	if (ix == STMGR) return("stmgr");
	if (ix == DDSPUB) return("ddspub");
	if (ix == UASRV) return("uasrv");

	return("");
};

void TblWzemMClstn::VecVTarget::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class TblWzemMClstn::VecWArgmask
 ******************************************************************************/

uint TblWzemMClstn::VecWArgmask::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "ix") ix |= IX;
		else if (ss[i] == "ref") ix |= REF;
		else if (ss[i] == "refs") ix |= REFS;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "intval") ix |= INTVAL;
		else if (ss[i] == "dblval") ix |= DBLVAL;
		else if (ss[i] == "boolval") ix |= BOOLVAL;
		else if (ss[i] == "txtval") ix |= TXTVAL;
	};

	return(ix);
};

void TblWzemMClstn::VecWArgmask::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TXTVAL); i *= 2) if (ix & i) ics.insert(i);
};

string TblWzemMClstn::VecWArgmask::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IX) ss.push_back("ix");
	if (ix & REF) ss.push_back("ref");
	if (ix & REFS) ss.push_back("refs");
	if (ix & SREF) ss.push_back("sref");
	if (ix & INTVAL) ss.push_back("intval");
	if (ix & DBLVAL) ss.push_back("dblval");
	if (ix & BOOLVAL) ss.push_back("boolval");
	if (ix & TXTVAL) ss.push_back("txtval");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void TblWzemMClstn::VecWArgmask::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= TXTVAL; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getSrefs(i));
};

