/**
	* \file VecWzemVOpengtype.cpp
	* vector VecWzemVOpengtype (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "VecWzemVOpengtype.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVOpengtype
 ******************************************************************************/

uint VecWzemVOpengtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	return(0);
};

string VecWzemVOpengtype::getSref(
			const uint ix
		) {

	return("");
};

string VecWzemVOpengtype::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		return(getSref(ix));
	};

	return("");
};

void VecWzemVOpengtype::appendToFeed(
			const uint ix
			, const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWzemVLocale));
};

void VecWzemVOpengtype::fillFeed(
			const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 0; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzemVLocale));
};

