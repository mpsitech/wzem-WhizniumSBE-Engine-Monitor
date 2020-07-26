/**
	* \file VecWzemVTag.cpp
	* vector VecWzemVTag (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "VecWzemVTag.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVTag
 ******************************************************************************/

uint VecWzemVTag::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "about") return ABOUT;
	if (s == "always") return ALWAYS;
	if (s == "cancel") return CANCEL;
	if (s == "close") return CLOSE;
	if (s == "clsess") return CLSESS;
	if (s == "clust") return CLUST;
	if (s == "detail") return DETAIL;
	if (s == "done") return DONE;
	if (s == "download") return DOWNLOAD;
	if (s == "emplong") return EMPLONG;
	if (s == "empshort") return EMPSHORT;
	if (s == "error") return ERROR;
	if (s == "filename") return FILENAME;
	if (s == "fls") return FLS;
	if (s == "general") return GENERAL;
	if (s == "goto") return GOTO;
	if (s == "grp") return GRP;
	if (s == "help") return HELP;
	if (s == "imperr") return IMPERR;
	if (s == "import") return IMPORT;
	if (s == "loaini") return LOAINI;
	if (s == "nav") return NAV;
	if (s == "no") return NO;
	if (s == "ok") return OK;
	if (s == "opscpllast") return OPSCPLLAST;
	if (s == "opsprep") return OPSPREP;
	if (s == "own") return OWN;
	if (s == "progress") return PROGRESS;
	if (s == "prserr") return PRSERR;
	if (s == "quest") return QUEST;
	if (s == "reverse") return REVERSE;
	if (s == "run") return RUN;
	if (s == "sess") return SESS;
	if (s == "showlong") return SHOWLONG;
	if (s == "showshort") return SHOWSHORT;
	if (s == "stop") return STOP;
	if (s == "suspsess") return SUSPSESS;
	if (s == "tru") return TRU;
	if (s == "upload") return UPLOAD;
	if (s == "yes") return YES;

	return(0);
};

string VecWzemVTag::getSref(
			const uint ix
		) {
	if (ix == ABOUT) return("about");
	if (ix == ALWAYS) return("always");
	if (ix == CANCEL) return("cancel");
	if (ix == CLOSE) return("close");
	if (ix == CLSESS) return("clsess");
	if (ix == CLUST) return("clust");
	if (ix == DETAIL) return("detail");
	if (ix == DONE) return("done");
	if (ix == DOWNLOAD) return("download");
	if (ix == EMPLONG) return("emplong");
	if (ix == EMPSHORT) return("empshort");
	if (ix == ERROR) return("error");
	if (ix == FILENAME) return("filename");
	if (ix == FLS) return("fls");
	if (ix == GENERAL) return("general");
	if (ix == GOTO) return("goto");
	if (ix == GRP) return("grp");
	if (ix == HELP) return("help");
	if (ix == IMPERR) return("imperr");
	if (ix == IMPORT) return("import");
	if (ix == LOAINI) return("loaini");
	if (ix == NAV) return("nav");
	if (ix == NO) return("no");
	if (ix == OK) return("ok");
	if (ix == OPSCPLLAST) return("opscpllast");
	if (ix == OPSPREP) return("opsprep");
	if (ix == OWN) return("own");
	if (ix == PROGRESS) return("progress");
	if (ix == PRSERR) return("prserr");
	if (ix == QUEST) return("quest");
	if (ix == REVERSE) return("reverse");
	if (ix == RUN) return("run");
	if (ix == SESS) return("sess");
	if (ix == SHOWLONG) return("showlong");
	if (ix == SHOWSHORT) return("showshort");
	if (ix == STOP) return("stop");
	if (ix == SUSPSESS) return("suspsess");
	if (ix == TRU) return("tru");
	if (ix == UPLOAD) return("upload");
	if (ix == YES) return("yes");

	return("");
};

string VecWzemVTag::getTitle(
			const uint ix
			, const uint ixWzemVLocale
		) {
	if (ixWzemVLocale == 1) {
		if (ix == ABOUT) return("About WhizniumSBE Engine Monitor");
		if (ix == ALWAYS) return("always");
		if (ix == CANCEL) return("cancel");
		if (ix == CLOSE) return("close");
		if (ix == CLSESS) return("close session");
		if (ix == CLUST) return("clustered with");
		if (ix == DETAIL) return("details");
		if (ix == DONE) return("done");
		if (ix == DOWNLOAD) return("download");
		if (ix == EMPLONG) return("no entries");
		if (ix == EMPSHORT) return("empty");
		if (ix == ERROR) return("error");
		if (ix == FILENAME) return("file name");
		if (ix == FLS) return("No");
		if (ix == GENERAL) return("generally");
		if (ix == GOTO) return("go to");
		if (ix == GRP) return("group");
		if (ix == HELP) return("WhizniumSBE Engine Monitor help");
		if (ix == IMPERR) return("import error");
		if (ix == IMPORT) return("import");
		if (ix == LOAINI) return("load initialization data");
		if (ix == NAV) return("navigation");
		if (ix == NO) return("no");
		if (ix == OK) return("OK");
		if (ix == OPSCPLLAST) return("operations completed, last");
		if (ix == OPSPREP) return("operations prepared");
		if (ix == OWN) return("owner");
		if (ix == PROGRESS) return("progress");
		if (ix == PRSERR) return("parse error");
		if (ix == QUEST) return("question");
		if (ix == REVERSE) return("reverse");
		if (ix == RUN) return("execute");
		if (ix == SESS) return("session");
		if (ix == SHOWLONG) return("showing &firstdisp; to &lastdisp; of &ntot;");
		if (ix == SHOWSHORT) return("&firstdisp;-&lastdisp; of &ntot;");
		if (ix == SUSPSESS) return("suspend session");
		if (ix == TRU) return("Yes");
		if (ix == UPLOAD) return("upload");
		if (ix == YES) return("yes");
		return(getSref(ix));
	};

	return("");
};

void VecWzemVTag::appendToFeed(
			const uint ix
			, const uint ixWzemVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixWzemVLocale));
};

