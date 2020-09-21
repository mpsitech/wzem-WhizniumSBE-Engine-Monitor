/**
	* \file VecWzemVReqitmode.cpp
	* vector VecWzemVReqitmode (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "VecWzemVReqitmode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVReqitmode
 ******************************************************************************/

uint VecWzemVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "notify") return NOTIFY;
	if (s == "poll") return POLL;

	return(0);
};

string VecWzemVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == NOTIFY) return("notify");
	if (ix == POLL) return("poll");

	return("");
};

