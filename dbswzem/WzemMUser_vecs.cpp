/**
	* \file WzemMUser_vecs.cpp
	* database access for table TblWzemMUser (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzemMUser::VecVState
 ******************************************************************************/

uint TblWzemMUser::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	if (s == "dsg") return DSG;
	if (s == "due") return DUE;
	if (s == "exp") return EXP;

	return(0);
};

string TblWzemMUser::VecVState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	if (ix == DSG) return("dsg");
	if (ix == DUE) return("due");
	if (ix == EXP) return("exp");

	return("");
};

string TblWzemMUser::VecVState::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == ACT) return("active");
		if (ix == DSG) return("designated");
		if (ix == DUE) return("due for expiration");
		if (ix == EXP) return("expired");
		return(getSref(ix));
	};

	return("");
};

void TblWzemMUser::VecVState::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};
