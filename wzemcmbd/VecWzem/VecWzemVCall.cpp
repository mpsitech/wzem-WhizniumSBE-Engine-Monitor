/**
	* \file VecWzemVCall.cpp
	* vector VecWzemVCall (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "VecWzemVCall.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzemVCall
 ******************************************************************************/

uint VecWzemVCall::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "callwzemboolvalpreset") return CALLWZEMBOOLVALPRESET;
	if (s == "callwzemcal.jobeq") return CALLWZEMCAL_JOBEQ;
	if (s == "callwzemcaljretmod.caleq") return CALLWZEMCALJRETMOD_CALEQ;
	if (s == "callwzemcalmod") return CALLWZEMCALMOD;
	if (s == "callwzemcalmod.jobeq") return CALLWZEMCALMOD_JOBEQ;
	if (s == "callwzemcalupd.refeq") return CALLWZEMCALUPD_REFEQ;
	if (s == "callwzemclaimchg") return CALLWZEMCLAIMCHG;
	if (s == "callwzemcln.jobeq") return CALLWZEMCLN_JOBEQ;
	if (s == "callwzemcln.tjbeq") return CALLWZEMCLN_TJBEQ;
	if (s == "callwzemclnjmod.clneq") return CALLWZEMCLNJMOD_CLNEQ;
	if (s == "callwzemclnmod") return CALLWZEMCLNMOD;
	if (s == "callwzemclnmod.jobeq") return CALLWZEMCLNMOD_JOBEQ;
	if (s == "callwzemclnupd.refeq") return CALLWZEMCLNUPD_REFEQ;
	if (s == "callwzemcrdactive") return CALLWZEMCRDACTIVE;
	if (s == "callwzemcrdclose") return CALLWZEMCRDCLOSE;
	if (s == "callwzemcrdopen") return CALLWZEMCRDOPEN;
	if (s == "callwzemctlaparmod.usreq") return CALLWZEMCTLAPARMOD_USREQ;
	if (s == "callwzemdatchg") return CALLWZEMDATCHG;
	if (s == "callwzemdblvalpreset") return CALLWZEMDBLVALPRESET;
	if (s == "callwzemdchmod") return CALLWZEMDCHMOD;
	if (s == "callwzemdchupd.refeq") return CALLWZEMDCHUPD_REFEQ;
	if (s == "callwzemdlgclose") return CALLWZEMDLGCLOSE;
	if (s == "callwzemevt.caleq") return CALLWZEMEVT_CALEQ;
	if (s == "callwzemevt.clneq") return CALLWZEMEVT_CLNEQ;
	if (s == "callwzemevt.clueq") return CALLWZEMEVT_CLUEQ;
	if (s == "callwzemevt.dcheq") return CALLWZEMEVT_DCHEQ;
	if (s == "callwzemevt.jobeq") return CALLWZEMEVT_JOBEQ;
	if (s == "callwzemevt.ndeeq") return CALLWZEMEVT_NDEEQ;
	if (s == "callwzemevt.opxeq") return CALLWZEMEVT_OPXEQ;
	if (s == "callwzemevt.prdeq") return CALLWZEMEVT_PRDEQ;
	if (s == "callwzemevt.psteq") return CALLWZEMEVT_PSTEQ;
	if (s == "callwzemevtmod") return CALLWZEMEVTMOD;
	if (s == "callwzemevtmod.clueq") return CALLWZEMEVTMOD_CLUEQ;
	if (s == "callwzemevtmod.prdeq") return CALLWZEMEVTMOD_PRDEQ;
	if (s == "callwzemevtupd.refeq") return CALLWZEMEVTUPD_REFEQ;
	if (s == "callwzemhusrrunvmod.crdusreq") return CALLWZEMHUSRRUNVMOD_CRDUSREQ;
	if (s == "callwzemintvalpreset") return CALLWZEMINTVALPRESET;
	if (s == "callwzemixpreset") return CALLWZEMIXPRESET;
	if (s == "callwzemjob.prdeq") return CALLWZEMJOB_PRDEQ;
	if (s == "callwzemjob.supeq") return CALLWZEMJOB_SUPEQ;
	if (s == "callwzemjobjdclmod.jobeq") return CALLWZEMJOBJDCLMOD_JOBEQ;
	if (s == "callwzemjobjstmmod.jobeq") return CALLWZEMJOBJSTMMOD_JOBEQ;
	if (s == "callwzemjobmod") return CALLWZEMJOBMOD;
	if (s == "callwzemjobmod.prdeq") return CALLWZEMJOBMOD_PRDEQ;
	if (s == "callwzemjobmod.supeq") return CALLWZEMJOBMOD_SUPEQ;
	if (s == "callwzemjobupd.refeq") return CALLWZEMJOBUPD_REFEQ;
	if (s == "callwzemkakjkeymod.klsakeyeq") return CALLWZEMKAKJKEYMOD_KLSAKEYEQ;
	if (s == "callwzemklsakeymod.klseq") return CALLWZEMKLSAKEYMOD_KLSEQ;
	if (s == "callwzemklsakeymod.klsmtburfeq") return CALLWZEMKLSAKEYMOD_KLSMTBURFEQ;
	if (s == "callwzemlog") return CALLWZEMLOG;
	if (s == "callwzemlogout") return CALLWZEMLOGOUT;
	if (s == "callwzemmonstatchg") return CALLWZEMMONSTATCHG;
	if (s == "callwzemnde.prdeq") return CALLWZEMNDE_PRDEQ;
	if (s == "callwzemndemod") return CALLWZEMNDEMOD;
	if (s == "callwzemndemod.prdeq") return CALLWZEMNDEMOD_PRDEQ;
	if (s == "callwzemndeupd.refeq") return CALLWZEMNDEUPD_REFEQ;
	if (s == "callwzemnodechg") return CALLWZEMNODECHG;
	if (s == "callwzemopx.jobeq") return CALLWZEMOPX_JOBEQ;
	if (s == "callwzemopxmod") return CALLWZEMOPXMOD;
	if (s == "callwzemopxmod.jobeq") return CALLWZEMOPXMOD_JOBEQ;
	if (s == "callwzemopxupd.refeq") return CALLWZEMOPXUPD_REFEQ;
	if (s == "callwzemprdmod") return CALLWZEMPRDMOD;
	if (s == "callwzemprdupd.refeq") return CALLWZEMPRDUPD_REFEQ;
	if (s == "callwzemprsadetmod.prseq") return CALLWZEMPRSADETMOD_PRSEQ;
	if (s == "callwzemprsjlnmmod.prseq") return CALLWZEMPRSJLNMMOD_PRSEQ;
	if (s == "callwzemprsmod") return CALLWZEMPRSMOD;
	if (s == "callwzemprsupd.refeq") return CALLWZEMPRSUPD_REFEQ;
	if (s == "callwzempst.jobeq") return CALLWZEMPST_JOBEQ;
	if (s == "callwzempstjargmod.psteq") return CALLWZEMPSTJARGMOD_PSTEQ;
	if (s == "callwzempstmod") return CALLWZEMPSTMOD;
	if (s == "callwzempstmod.jobeq") return CALLWZEMPSTMOD_JOBEQ;
	if (s == "callwzempstupd.refeq") return CALLWZEMPSTUPD_REFEQ;
	if (s == "callwzemrecaccess") return CALLWZEMRECACCESS;
	if (s == "callwzemrefpreset") return CALLWZEMREFPRESET;
	if (s == "callwzemrefspreset") return CALLWZEMREFSPRESET;
	if (s == "callwzemsesmod") return CALLWZEMSESMOD;
	if (s == "callwzemsesmod.usreq") return CALLWZEMSESMOD_USREQ;
	if (s == "callwzemsesupd.refeq") return CALLWZEMSESUPD_REFEQ;
	if (s == "callwzemsgechg") return CALLWZEMSGECHG;
	if (s == "callwzemshrdatchg") return CALLWZEMSHRDATCHG;
	if (s == "callwzemsrefpreset") return CALLWZEMSREFPRESET;
	if (s == "callwzemstatchg") return CALLWZEMSTATCHG;
	if (s == "callwzemstgchg") return CALLWZEMSTGCHG;
	if (s == "callwzemstubchg") return CALLWZEMSTUBCHG;
	if (s == "callwzemsuspsess") return CALLWZEMSUSPSESS;
	if (s == "callwzemtxtvalpreset") return CALLWZEMTXTVALPRESET;
	if (s == "callwzemusgaaccmod.usgeq") return CALLWZEMUSGAACCMOD_USGEQ;
	if (s == "callwzemusgmod") return CALLWZEMUSGMOD;
	if (s == "callwzemusgupd.refeq") return CALLWZEMUSGUPD_REFEQ;
	if (s == "callwzemusr.prseq") return CALLWZEMUSR_PRSEQ;
	if (s == "callwzemusr.usgeq") return CALLWZEMUSR_USGEQ;
	if (s == "callwzemusraaccmod.usreq") return CALLWZEMUSRAACCMOD_USREQ;
	if (s == "callwzemusrjstemod.usreq") return CALLWZEMUSRJSTEMOD_USREQ;
	if (s == "callwzemusrmod") return CALLWZEMUSRMOD;
	if (s == "callwzemusrrusgmod.usgeq") return CALLWZEMUSRRUSGMOD_USGEQ;
	if (s == "callwzemusrrusgmod.usreq") return CALLWZEMUSRRUSGMOD_USREQ;
	if (s == "callwzemusrupd.refeq") return CALLWZEMUSRUPD_REFEQ;

	return(0);
};

string VecWzemVCall::getSref(
			const uint ix
		) {
	if (ix == CALLWZEMBOOLVALPRESET) return("CallWzemBoolvalPreSet");
	if (ix == CALLWZEMCAL_JOBEQ) return("CallWzemCal.jobEq");
	if (ix == CALLWZEMCALJRETMOD_CALEQ) return("CallWzemCalJretMod.calEq");
	if (ix == CALLWZEMCALMOD) return("CallWzemCalMod");
	if (ix == CALLWZEMCALMOD_JOBEQ) return("CallWzemCalMod.jobEq");
	if (ix == CALLWZEMCALUPD_REFEQ) return("CallWzemCalUpd.refEq");
	if (ix == CALLWZEMCLAIMCHG) return("CallWzemClaimChg");
	if (ix == CALLWZEMCLN_JOBEQ) return("CallWzemCln.jobEq");
	if (ix == CALLWZEMCLN_TJBEQ) return("CallWzemCln.tjbEq");
	if (ix == CALLWZEMCLNJMOD_CLNEQ) return("CallWzemClnJMod.clnEq");
	if (ix == CALLWZEMCLNMOD) return("CallWzemClnMod");
	if (ix == CALLWZEMCLNMOD_JOBEQ) return("CallWzemClnMod.jobEq");
	if (ix == CALLWZEMCLNUPD_REFEQ) return("CallWzemClnUpd.refEq");
	if (ix == CALLWZEMCRDACTIVE) return("CallWzemCrdActive");
	if (ix == CALLWZEMCRDCLOSE) return("CallWzemCrdClose");
	if (ix == CALLWZEMCRDOPEN) return("CallWzemCrdOpen");
	if (ix == CALLWZEMCTLAPARMOD_USREQ) return("CallWzemCtlAparMod.usrEq");
	if (ix == CALLWZEMDATCHG) return("CallWzemDatChg");
	if (ix == CALLWZEMDBLVALPRESET) return("CallWzemDblvalPreSet");
	if (ix == CALLWZEMDCHMOD) return("CallWzemDchMod");
	if (ix == CALLWZEMDCHUPD_REFEQ) return("CallWzemDchUpd.refEq");
	if (ix == CALLWZEMDLGCLOSE) return("CallWzemDlgClose");
	if (ix == CALLWZEMEVT_CALEQ) return("CallWzemEvt.calEq");
	if (ix == CALLWZEMEVT_CLNEQ) return("CallWzemEvt.clnEq");
	if (ix == CALLWZEMEVT_CLUEQ) return("CallWzemEvt.cluEq");
	if (ix == CALLWZEMEVT_DCHEQ) return("CallWzemEvt.dchEq");
	if (ix == CALLWZEMEVT_JOBEQ) return("CallWzemEvt.jobEq");
	if (ix == CALLWZEMEVT_NDEEQ) return("CallWzemEvt.ndeEq");
	if (ix == CALLWZEMEVT_OPXEQ) return("CallWzemEvt.opxEq");
	if (ix == CALLWZEMEVT_PRDEQ) return("CallWzemEvt.prdEq");
	if (ix == CALLWZEMEVT_PSTEQ) return("CallWzemEvt.pstEq");
	if (ix == CALLWZEMEVTMOD) return("CallWzemEvtMod");
	if (ix == CALLWZEMEVTMOD_CLUEQ) return("CallWzemEvtMod.cluEq");
	if (ix == CALLWZEMEVTMOD_PRDEQ) return("CallWzemEvtMod.prdEq");
	if (ix == CALLWZEMEVTUPD_REFEQ) return("CallWzemEvtUpd.refEq");
	if (ix == CALLWZEMHUSRRUNVMOD_CRDUSREQ) return("CallWzemHusrRunvMod.crdUsrEq");
	if (ix == CALLWZEMINTVALPRESET) return("CallWzemIntvalPreSet");
	if (ix == CALLWZEMIXPRESET) return("CallWzemIxPreSet");
	if (ix == CALLWZEMJOB_PRDEQ) return("CallWzemJob.prdEq");
	if (ix == CALLWZEMJOB_SUPEQ) return("CallWzemJob.supEq");
	if (ix == CALLWZEMJOBJDCLMOD_JOBEQ) return("CallWzemJobJdclMod.jobEq");
	if (ix == CALLWZEMJOBJSTMMOD_JOBEQ) return("CallWzemJobJstmMod.jobEq");
	if (ix == CALLWZEMJOBMOD) return("CallWzemJobMod");
	if (ix == CALLWZEMJOBMOD_PRDEQ) return("CallWzemJobMod.prdEq");
	if (ix == CALLWZEMJOBMOD_SUPEQ) return("CallWzemJobMod.supEq");
	if (ix == CALLWZEMJOBUPD_REFEQ) return("CallWzemJobUpd.refEq");
	if (ix == CALLWZEMKAKJKEYMOD_KLSAKEYEQ) return("CallWzemKakJkeyMod.klsAkeyEq");
	if (ix == CALLWZEMKLSAKEYMOD_KLSEQ) return("CallWzemKlsAkeyMod.klsEq");
	if (ix == CALLWZEMKLSAKEYMOD_KLSMTBURFEQ) return("CallWzemKlsAkeyMod.klsMtbUrfEq");
	if (ix == CALLWZEMLOG) return("CallWzemLog");
	if (ix == CALLWZEMLOGOUT) return("CallWzemLogout");
	if (ix == CALLWZEMMONSTATCHG) return("CallWzemMonstatChg");
	if (ix == CALLWZEMNDE_PRDEQ) return("CallWzemNde.prdEq");
	if (ix == CALLWZEMNDEMOD) return("CallWzemNdeMod");
	if (ix == CALLWZEMNDEMOD_PRDEQ) return("CallWzemNdeMod.prdEq");
	if (ix == CALLWZEMNDEUPD_REFEQ) return("CallWzemNdeUpd.refEq");
	if (ix == CALLWZEMNODECHG) return("CallWzemNodeChg");
	if (ix == CALLWZEMOPX_JOBEQ) return("CallWzemOpx.jobEq");
	if (ix == CALLWZEMOPXMOD) return("CallWzemOpxMod");
	if (ix == CALLWZEMOPXMOD_JOBEQ) return("CallWzemOpxMod.jobEq");
	if (ix == CALLWZEMOPXUPD_REFEQ) return("CallWzemOpxUpd.refEq");
	if (ix == CALLWZEMPRDMOD) return("CallWzemPrdMod");
	if (ix == CALLWZEMPRDUPD_REFEQ) return("CallWzemPrdUpd.refEq");
	if (ix == CALLWZEMPRSADETMOD_PRSEQ) return("CallWzemPrsAdetMod.prsEq");
	if (ix == CALLWZEMPRSJLNMMOD_PRSEQ) return("CallWzemPrsJlnmMod.prsEq");
	if (ix == CALLWZEMPRSMOD) return("CallWzemPrsMod");
	if (ix == CALLWZEMPRSUPD_REFEQ) return("CallWzemPrsUpd.refEq");
	if (ix == CALLWZEMPST_JOBEQ) return("CallWzemPst.jobEq");
	if (ix == CALLWZEMPSTJARGMOD_PSTEQ) return("CallWzemPstJargMod.pstEq");
	if (ix == CALLWZEMPSTMOD) return("CallWzemPstMod");
	if (ix == CALLWZEMPSTMOD_JOBEQ) return("CallWzemPstMod.jobEq");
	if (ix == CALLWZEMPSTUPD_REFEQ) return("CallWzemPstUpd.refEq");
	if (ix == CALLWZEMRECACCESS) return("CallWzemRecaccess");
	if (ix == CALLWZEMREFPRESET) return("CallWzemRefPreSet");
	if (ix == CALLWZEMREFSPRESET) return("CallWzemRefsPreSet");
	if (ix == CALLWZEMSESMOD) return("CallWzemSesMod");
	if (ix == CALLWZEMSESMOD_USREQ) return("CallWzemSesMod.usrEq");
	if (ix == CALLWZEMSESUPD_REFEQ) return("CallWzemSesUpd.refEq");
	if (ix == CALLWZEMSGECHG) return("CallWzemSgeChg");
	if (ix == CALLWZEMSHRDATCHG) return("CallWzemShrdatChg");
	if (ix == CALLWZEMSREFPRESET) return("CallWzemSrefPreSet");
	if (ix == CALLWZEMSTATCHG) return("CallWzemStatChg");
	if (ix == CALLWZEMSTGCHG) return("CallWzemStgChg");
	if (ix == CALLWZEMSTUBCHG) return("CallWzemStubChg");
	if (ix == CALLWZEMSUSPSESS) return("CallWzemSuspsess");
	if (ix == CALLWZEMTXTVALPRESET) return("CallWzemTxtvalPreSet");
	if (ix == CALLWZEMUSGAACCMOD_USGEQ) return("CallWzemUsgAaccMod.usgEq");
	if (ix == CALLWZEMUSGMOD) return("CallWzemUsgMod");
	if (ix == CALLWZEMUSGUPD_REFEQ) return("CallWzemUsgUpd.refEq");
	if (ix == CALLWZEMUSR_PRSEQ) return("CallWzemUsr.prsEq");
	if (ix == CALLWZEMUSR_USGEQ) return("CallWzemUsr.usgEq");
	if (ix == CALLWZEMUSRAACCMOD_USREQ) return("CallWzemUsrAaccMod.usrEq");
	if (ix == CALLWZEMUSRJSTEMOD_USREQ) return("CallWzemUsrJsteMod.usrEq");
	if (ix == CALLWZEMUSRMOD) return("CallWzemUsrMod");
	if (ix == CALLWZEMUSRRUSGMOD_USGEQ) return("CallWzemUsrRusgMod.usgEq");
	if (ix == CALLWZEMUSRRUSGMOD_USREQ) return("CallWzemUsrRusgMod.usrEq");
	if (ix == CALLWZEMUSRUPD_REFEQ) return("CallWzemUsrUpd.refEq");

	return("");
};

