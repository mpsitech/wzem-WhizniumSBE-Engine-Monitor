/**
	* \file VecWzemVOppack.cpp
	* vector VecWzemVOppack (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "VecWzemVOppack.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVOppack
 ******************************************************************************/

uint VecWzemVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	return(0);
};

string VecWzemVOppack::getSref(
			const uint ix
		) {

	return("");
};

string VecWzemVOppack::getTitle(
			const uint ix
		) {
	return(getSref(ix));

	return("");
};

string VecWzemVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecWzemVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecWzemVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 0; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};







