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

	if (s == "stubwzemcalstd") return STUBWZEMCALSTD;
	if (s == "stubwzemgroup") return STUBWZEMGROUP;
	if (s == "stubwzemusgstd") return STUBWZEMUSGSTD;
	if (s == "stubwzemowner") return STUBWZEMOWNER;
	if (s == "stubwzemusrstd") return STUBWZEMUSRSTD;
	if (s == "stubwzemsesmenu") return STUBWZEMSESMENU;
	if (s == "stubwzemsesstd") return STUBWZEMSESSTD;
	if (s == "stubwzempststd") return STUBWZEMPSTSTD;
	if (s == "stubwzemprsstd") return STUBWZEMPRSSTD;
	if (s == "stubwzemprdstd") return STUBWZEMPRDSTD;
	if (s == "stubwzemndestd") return STUBWZEMNDESTD;
	if (s == "stubwzemndexnref") return STUBWZEMNDEXNREF;
	if (s == "stubwzemopxstd") return STUBWZEMOPXSTD;
	if (s == "stubwzemjobstd") return STUBWZEMJOBSTD;
	if (s == "stubwzemjobxjref") return STUBWZEMJOBXJREF;
	if (s == "stubwzemevtstd") return STUBWZEMEVTSTD;
	if (s == "stubwzemdchstd") return STUBWZEMDCHSTD;
	if (s == "stubwzemclnstd") return STUBWZEMCLNSTD;

	return(0);
};

string VecWzemVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWZEMCALSTD) return("StubWzemCalStd");
	if (ix == STUBWZEMGROUP) return("StubWzemGroup");
	if (ix == STUBWZEMUSGSTD) return("StubWzemUsgStd");
	if (ix == STUBWZEMOWNER) return("StubWzemOwner");
	if (ix == STUBWZEMUSRSTD) return("StubWzemUsrStd");
	if (ix == STUBWZEMSESMENU) return("StubWzemSesMenu");
	if (ix == STUBWZEMSESSTD) return("StubWzemSesStd");
	if (ix == STUBWZEMPSTSTD) return("StubWzemPstStd");
	if (ix == STUBWZEMPRSSTD) return("StubWzemPrsStd");
	if (ix == STUBWZEMPRDSTD) return("StubWzemPrdStd");
	if (ix == STUBWZEMNDESTD) return("StubWzemNdeStd");
	if (ix == STUBWZEMNDEXNREF) return("StubWzemNdeXnref");
	if (ix == STUBWZEMOPXSTD) return("StubWzemOpxStd");
	if (ix == STUBWZEMJOBSTD) return("StubWzemJobStd");
	if (ix == STUBWZEMJOBXJREF) return("StubWzemJobXjref");
	if (ix == STUBWZEMEVTSTD) return("StubWzemEvtStd");
	if (ix == STUBWZEMDCHSTD) return("StubWzemDchStd");
	if (ix == STUBWZEMCLNSTD) return("StubWzemClnStd");

	return("");
};







