/**
	* \file VecWzemVStub.cpp
	* vector VecWzemVStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "VecWzemVStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVStub
 ******************************************************************************/

uint VecWzemVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubwzemjobstd") return STUBWZEMJOBSTD;
	if (s == "stubwzemjobxjref") return STUBWZEMJOBXJREF;
	if (s == "stubwzemopxstd") return STUBWZEMOPXSTD;
	if (s == "stubwzemndestd") return STUBWZEMNDESTD;
	if (s == "stubwzemndexnref") return STUBWZEMNDEXNREF;
	if (s == "stubwzemprdstd") return STUBWZEMPRDSTD;
	if (s == "stubwzemprsstd") return STUBWZEMPRSSTD;
	if (s == "stubwzempststd") return STUBWZEMPSTSTD;
	if (s == "stubwzemsesmenu") return STUBWZEMSESMENU;
	if (s == "stubwzemsesstd") return STUBWZEMSESSTD;
	if (s == "stubwzemowner") return STUBWZEMOWNER;
	if (s == "stubwzemusrstd") return STUBWZEMUSRSTD;
	if (s == "stubwzemgroup") return STUBWZEMGROUP;
	if (s == "stubwzemusgstd") return STUBWZEMUSGSTD;
	if (s == "stubwzemevtstd") return STUBWZEMEVTSTD;
	if (s == "stubwzemdchstd") return STUBWZEMDCHSTD;
	if (s == "stubwzemclnstd") return STUBWZEMCLNSTD;
	if (s == "stubwzemcalstd") return STUBWZEMCALSTD;

	return(0);
};

string VecWzemVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWZEMJOBSTD) return("StubWzemJobStd");
	if (ix == STUBWZEMJOBXJREF) return("StubWzemJobXjref");
	if (ix == STUBWZEMOPXSTD) return("StubWzemOpxStd");
	if (ix == STUBWZEMNDESTD) return("StubWzemNdeStd");
	if (ix == STUBWZEMNDEXNREF) return("StubWzemNdeXnref");
	if (ix == STUBWZEMPRDSTD) return("StubWzemPrdStd");
	if (ix == STUBWZEMPRSSTD) return("StubWzemPrsStd");
	if (ix == STUBWZEMPSTSTD) return("StubWzemPstStd");
	if (ix == STUBWZEMSESMENU) return("StubWzemSesMenu");
	if (ix == STUBWZEMSESSTD) return("StubWzemSesStd");
	if (ix == STUBWZEMOWNER) return("StubWzemOwner");
	if (ix == STUBWZEMUSRSTD) return("StubWzemUsrStd");
	if (ix == STUBWZEMGROUP) return("StubWzemGroup");
	if (ix == STUBWZEMUSGSTD) return("StubWzemUsgStd");
	if (ix == STUBWZEMEVTSTD) return("StubWzemEvtStd");
	if (ix == STUBWZEMDCHSTD) return("StubWzemDchStd");
	if (ix == STUBWZEMCLNSTD) return("StubWzemClnStd");
	if (ix == STUBWZEMCALSTD) return("StubWzemCalStd");

	return("");
};
