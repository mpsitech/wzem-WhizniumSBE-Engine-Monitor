/**
	* \file WzemMPerson_vecs.cpp
	* database access for table TblWzemMPerson (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzemMPerson::VecVSex
 ******************************************************************************/

uint TblWzemMPerson::VecVSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	if (s == "m") return M;

	return(0);
};

string TblWzemMPerson::VecVSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	if (ix == M) return("m");

	return("");
};

string TblWzemMPerson::VecVSex::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == F) return("female");
		if (ix == M) return("male");
		return(getSref(ix));
	};

	return("");
};

void TblWzemMPerson::VecVSex::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

/******************************************************************************
 class TblWzemMPerson::VecWDerivate
 ******************************************************************************/

uint TblWzemMPerson::VecWDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void TblWzemMPerson::VecWDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*USR); i *= 2) if (ix & i) ics.insert(i);
};

string TblWzemMPerson::VecWDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWzemMPerson::VecWDerivate::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == USR) return("user");
		return(getSrefs(ix));
	};

	return("");
};

void TblWzemMPerson::VecWDerivate::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= USR; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWzemVLocale));
};
