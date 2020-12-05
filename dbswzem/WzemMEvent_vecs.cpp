/**
	* \file WzemMEvent_vecs.cpp
	* database access for table TblWzemMEvent (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzemMEvent::VecVBasetype
 ******************************************************************************/

uint TblWzemMEvent::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "addjob") return ADDJOB;
	if (s == "removejob") return REMOVEJOB;
	if (s == "adddcol") return ADDDCOL;
	if (s == "removedcol") return REMOVEDCOL;
	if (s == "addstmgr") return ADDSTMGR;
	if (s == "removestmgr") return REMOVESTMGR;
	if (s == "addclstn") return ADDCLSTN;
	if (s == "changeclstnarg") return CHANGECLSTNARG;
	if (s == "removeclstn") return REMOVECLSTN;
	if (s == "addpreset") return ADDPRESET;
	if (s == "changepreset") return CHANGEPRESET;
	if (s == "removepreset") return REMOVEPRESET;
	if (s == "addnode") return ADDNODE;
	if (s == "removenode") return REMOVENODE;
	if (s == "triggercall") return TRIGGERCALL;
	if (s == "handlecall") return HANDLECALL;
	if (s == "retcall") return RETCALL;
	if (s == "finalizecall") return FINALIZECALL;
	if (s == "handlereqcmd") return HANDLEREQCMD;
	if (s == "handlereqdpchapp") return HANDLEREQDPCHAPP;
	if (s == "replyreqdpchapp") return REPLYREQDPCHAPP;
	if (s == "handlerequpload") return HANDLEREQUPLOAD;
	if (s == "handlereqdownload") return HANDLEREQDOWNLOAD;
	if (s == "replyreqdownload") return REPLYREQDOWNLOAD;
	if (s == "handlereqdpchret") return HANDLEREQDPCHRET;
	if (s == "handlereqmethod") return HANDLEREQMETHOD;
	if (s == "handlereqtimer") return HANDLEREQTIMER;
	if (s == "submitdpch") return SUBMITDPCH;
	if (s == "addinv") return ADDINV;

	return(0);
};

string TblWzemMEvent::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == ADDJOB) return("addJob");
	if (ix == REMOVEJOB) return("removeJob");
	if (ix == ADDDCOL) return("addDcol");
	if (ix == REMOVEDCOL) return("removeDcol");
	if (ix == ADDSTMGR) return("addStmgr");
	if (ix == REMOVESTMGR) return("removeStmgr");
	if (ix == ADDCLSTN) return("addClstn");
	if (ix == CHANGECLSTNARG) return("changeClstnArg");
	if (ix == REMOVECLSTN) return("removeClstn");
	if (ix == ADDPRESET) return("addPreset");
	if (ix == CHANGEPRESET) return("changePreset");
	if (ix == REMOVEPRESET) return("removePreset");
	if (ix == ADDNODE) return("addNode");
	if (ix == REMOVENODE) return("removeNode");
	if (ix == TRIGGERCALL) return("triggerCall");
	if (ix == HANDLECALL) return("handleCall");
	if (ix == RETCALL) return("retCall");
	if (ix == FINALIZECALL) return("finalizeCall");
	if (ix == HANDLEREQCMD) return("handleReqCmd");
	if (ix == HANDLEREQDPCHAPP) return("handleReqDpchapp");
	if (ix == REPLYREQDPCHAPP) return("replyReqDpchapp");
	if (ix == HANDLEREQUPLOAD) return("handleReqUpload");
	if (ix == HANDLEREQDOWNLOAD) return("handleReqDownload");
	if (ix == REPLYREQDOWNLOAD) return("replyReqDownload");
	if (ix == HANDLEREQDPCHRET) return("handleReqDpchret");
	if (ix == HANDLEREQMETHOD) return("handleReqMethod");
	if (ix == HANDLEREQTIMER) return("handleReqTimer");
	if (ix == SUBMITDPCH) return("submitDpch");
	if (ix == ADDINV) return("addInv");

	return("");
};

void TblWzemMEvent::VecVBasetype::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 29; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

