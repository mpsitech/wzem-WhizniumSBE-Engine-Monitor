/**
	* \file VecWzemVDpch.h
	* vector VecWzemVDpch (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "VecWzemVDpch.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 namespace VecWzemVDpch
 ******************************************************************************/

uint VecWzemVDpch::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dpchengdlgwzemnavloainidata") return DPCHENGDLGWZEMNAVLOAINIDATA;
	if (s == "dpchengrootwzemdata") return DPCHENGROOTWZEMDATA;
	if (s == "dpchengsesswzemdata") return DPCHENGSESSWZEMDATA;
	if (s == "dpchengwzemack") return DPCHENGWZEMACK;
	if (s == "dpchengwzemalert") return DPCHENGWZEMALERT;
	if (s == "dpchengwzemcaldata") return DPCHENGWZEMCALDATA;
	if (s == "dpchengwzemcaldetaildata") return DPCHENGWZEMCALDETAILDATA;
	if (s == "dpchengwzemcalheadbardata") return DPCHENGWZEMCALHEADBARDATA;
	if (s == "dpchengwzemcallistdata") return DPCHENGWZEMCALLISTDATA;
	if (s == "dpchengwzemcalrecdata") return DPCHENGWZEMCALRECDATA;
	if (s == "dpchengwzemclndata") return DPCHENGWZEMCLNDATA;
	if (s == "dpchengwzemclndetaildata") return DPCHENGWZEMCLNDETAILDATA;
	if (s == "dpchengwzemclnheadbardata") return DPCHENGWZEMCLNHEADBARDATA;
	if (s == "dpchengwzemclnlistdata") return DPCHENGWZEMCLNLISTDATA;
	if (s == "dpchengwzemclnrecdata") return DPCHENGWZEMCLNRECDATA;
	if (s == "dpchengwzemconfirm") return DPCHENGWZEMCONFIRM;
	if (s == "dpchengwzemevtdata") return DPCHENGWZEMEVTDATA;
	if (s == "dpchengwzemevtdetaildata") return DPCHENGWZEMEVTDETAILDATA;
	if (s == "dpchengwzemevtheadbardata") return DPCHENGWZEMEVTHEADBARDATA;
	if (s == "dpchengwzemevtlistdata") return DPCHENGWZEMEVTLISTDATA;
	if (s == "dpchengwzemevtrecdata") return DPCHENGWZEMEVTRECDATA;
	if (s == "dpchengwzemjob1ncalldata") return DPCHENGWZEMJOB1NCALLDATA;
	if (s == "dpchengwzemjob1nclstndata") return DPCHENGWZEMJOB1NCLSTNDATA;
	if (s == "dpchengwzemjob1nopdata") return DPCHENGWZEMJOB1NOPDATA;
	if (s == "dpchengwzemjob1npresetdata") return DPCHENGWZEMJOB1NPRESETDATA;
	if (s == "dpchengwzemjobdata") return DPCHENGWZEMJOBDATA;
	if (s == "dpchengwzemjobdetaildata") return DPCHENGWZEMJOBDETAILDATA;
	if (s == "dpchengwzemjobheadbardata") return DPCHENGWZEMJOBHEADBARDATA;
	if (s == "dpchengwzemjoblistdata") return DPCHENGWZEMJOBLISTDATA;
	if (s == "dpchengwzemjobrecdata") return DPCHENGWZEMJOBRECDATA;
	if (s == "dpchengwzemjobsup1njobdata") return DPCHENGWZEMJOBSUP1NJOBDATA;
	if (s == "dpchengwzemnavadmindata") return DPCHENGWZEMNAVADMINDATA;
	if (s == "dpchengwzemnavdata") return DPCHENGWZEMNAVDATA;
	if (s == "dpchengwzemnavheadbardata") return DPCHENGWZEMNAVHEADBARDATA;
	if (s == "dpchengwzemnavmondata") return DPCHENGWZEMNAVMONDATA;
	if (s == "dpchengwzemnavpredata") return DPCHENGWZEMNAVPREDATA;
	if (s == "dpchengwzemndedata") return DPCHENGWZEMNDEDATA;
	if (s == "dpchengwzemndedetaildata") return DPCHENGWZEMNDEDETAILDATA;
	if (s == "dpchengwzemndeheadbardata") return DPCHENGWZEMNDEHEADBARDATA;
	if (s == "dpchengwzemndelistdata") return DPCHENGWZEMNDELISTDATA;
	if (s == "dpchengwzemnderecdata") return DPCHENGWZEMNDERECDATA;
	if (s == "dpchengwzemopxdata") return DPCHENGWZEMOPXDATA;
	if (s == "dpchengwzemopxdetaildata") return DPCHENGWZEMOPXDETAILDATA;
	if (s == "dpchengwzemopxheadbardata") return DPCHENGWZEMOPXHEADBARDATA;
	if (s == "dpchengwzemopxlistdata") return DPCHENGWZEMOPXLISTDATA;
	if (s == "dpchengwzemopxrecdata") return DPCHENGWZEMOPXRECDATA;
	if (s == "dpchengwzemprd1neventdata") return DPCHENGWZEMPRD1NEVENTDATA;
	if (s == "dpchengwzemprd1njobdata") return DPCHENGWZEMPRD1NJOBDATA;
	if (s == "dpchengwzemprd1nnodedata") return DPCHENGWZEMPRD1NNODEDATA;
	if (s == "dpchengwzemprddata") return DPCHENGWZEMPRDDATA;
	if (s == "dpchengwzemprddetaildata") return DPCHENGWZEMPRDDETAILDATA;
	if (s == "dpchengwzemprdheadbardata") return DPCHENGWZEMPRDHEADBARDATA;
	if (s == "dpchengwzemprdlistdata") return DPCHENGWZEMPRDLISTDATA;
	if (s == "dpchengwzemprdrecdata") return DPCHENGWZEMPRDRECDATA;
	if (s == "dpchengwzemprsadetaildata") return DPCHENGWZEMPRSADETAILDATA;
	if (s == "dpchengwzemprsdata") return DPCHENGWZEMPRSDATA;
	if (s == "dpchengwzemprsdetaildata") return DPCHENGWZEMPRSDETAILDATA;
	if (s == "dpchengwzemprsheadbardata") return DPCHENGWZEMPRSHEADBARDATA;
	if (s == "dpchengwzemprslistdata") return DPCHENGWZEMPRSLISTDATA;
	if (s == "dpchengwzemprsrecdata") return DPCHENGWZEMPRSRECDATA;
	if (s == "dpchengwzempstdata") return DPCHENGWZEMPSTDATA;
	if (s == "dpchengwzempstdetaildata") return DPCHENGWZEMPSTDETAILDATA;
	if (s == "dpchengwzempstheadbardata") return DPCHENGWZEMPSTHEADBARDATA;
	if (s == "dpchengwzempstlistdata") return DPCHENGWZEMPSTLISTDATA;
	if (s == "dpchengwzempstrecdata") return DPCHENGWZEMPSTRECDATA;
	if (s == "dpchengwzemsuspend") return DPCHENGWZEMSUSPEND;
	if (s == "dpchengwzemusgaaccessdata") return DPCHENGWZEMUSGAACCESSDATA;
	if (s == "dpchengwzemusgdata") return DPCHENGWZEMUSGDATA;
	if (s == "dpchengwzemusgdetaildata") return DPCHENGWZEMUSGDETAILDATA;
	if (s == "dpchengwzemusgheadbardata") return DPCHENGWZEMUSGHEADBARDATA;
	if (s == "dpchengwzemusglistdata") return DPCHENGWZEMUSGLISTDATA;
	if (s == "dpchengwzemusgmnuserdata") return DPCHENGWZEMUSGMNUSERDATA;
	if (s == "dpchengwzemusgrecdata") return DPCHENGWZEMUSGRECDATA;
	if (s == "dpchengwzemusr1nsessiondata") return DPCHENGWZEMUSR1NSESSIONDATA;
	if (s == "dpchengwzemusraaccessdata") return DPCHENGWZEMUSRAACCESSDATA;
	if (s == "dpchengwzemusrdata") return DPCHENGWZEMUSRDATA;
	if (s == "dpchengwzemusrdetaildata") return DPCHENGWZEMUSRDETAILDATA;
	if (s == "dpchengwzemusrheadbardata") return DPCHENGWZEMUSRHEADBARDATA;
	if (s == "dpchengwzemusrlistdata") return DPCHENGWZEMUSRLISTDATA;
	if (s == "dpchengwzemusrmnusergroupdata") return DPCHENGWZEMUSRMNUSERGROUPDATA;
	if (s == "dpchengwzemusrrecdata") return DPCHENGWZEMUSRRECDATA;
	if (s == "dpchappdlgwzemnavloainidata") return DPCHAPPDLGWZEMNAVLOAINIDATA;
	if (s == "dpchappdlgwzemnavloainido") return DPCHAPPDLGWZEMNAVLOAINIDO;
	if (s == "dpchapprootwzemlogin") return DPCHAPPROOTWZEMLOGIN;
	if (s == "dpchappwzemalert") return DPCHAPPWZEMALERT;
	if (s == "dpchappwzemcaldetaildata") return DPCHAPPWZEMCALDETAILDATA;
	if (s == "dpchappwzemcaldetaildo") return DPCHAPPWZEMCALDETAILDO;
	if (s == "dpchappwzemcaldo") return DPCHAPPWZEMCALDO;
	if (s == "dpchappwzemcallistdata") return DPCHAPPWZEMCALLISTDATA;
	if (s == "dpchappwzemcallistdo") return DPCHAPPWZEMCALLISTDO;
	if (s == "dpchappwzemcalrecdo") return DPCHAPPWZEMCALRECDO;
	if (s == "dpchappwzemclndetaildata") return DPCHAPPWZEMCLNDETAILDATA;
	if (s == "dpchappwzemclndetaildo") return DPCHAPPWZEMCLNDETAILDO;
	if (s == "dpchappwzemclndo") return DPCHAPPWZEMCLNDO;
	if (s == "dpchappwzemclnlistdata") return DPCHAPPWZEMCLNLISTDATA;
	if (s == "dpchappwzemclnlistdo") return DPCHAPPWZEMCLNLISTDO;
	if (s == "dpchappwzemclnrecdo") return DPCHAPPWZEMCLNRECDO;
	if (s == "dpchappwzemevtdetaildata") return DPCHAPPWZEMEVTDETAILDATA;
	if (s == "dpchappwzemevtdetaildo") return DPCHAPPWZEMEVTDETAILDO;
	if (s == "dpchappwzemevtdo") return DPCHAPPWZEMEVTDO;
	if (s == "dpchappwzemevtlistdata") return DPCHAPPWZEMEVTLISTDATA;
	if (s == "dpchappwzemevtlistdo") return DPCHAPPWZEMEVTLISTDO;
	if (s == "dpchappwzemevtrecdo") return DPCHAPPWZEMEVTRECDO;
	if (s == "dpchappwzeminit") return DPCHAPPWZEMINIT;
	if (s == "dpchappwzemjob1ncalldata") return DPCHAPPWZEMJOB1NCALLDATA;
	if (s == "dpchappwzemjob1ncalldo") return DPCHAPPWZEMJOB1NCALLDO;
	if (s == "dpchappwzemjob1nclstndata") return DPCHAPPWZEMJOB1NCLSTNDATA;
	if (s == "dpchappwzemjob1nclstndo") return DPCHAPPWZEMJOB1NCLSTNDO;
	if (s == "dpchappwzemjob1nopdata") return DPCHAPPWZEMJOB1NOPDATA;
	if (s == "dpchappwzemjob1nopdo") return DPCHAPPWZEMJOB1NOPDO;
	if (s == "dpchappwzemjob1npresetdata") return DPCHAPPWZEMJOB1NPRESETDATA;
	if (s == "dpchappwzemjob1npresetdo") return DPCHAPPWZEMJOB1NPRESETDO;
	if (s == "dpchappwzemjobdetaildata") return DPCHAPPWZEMJOBDETAILDATA;
	if (s == "dpchappwzemjobdetaildo") return DPCHAPPWZEMJOBDETAILDO;
	if (s == "dpchappwzemjobdo") return DPCHAPPWZEMJOBDO;
	if (s == "dpchappwzemjoblistdata") return DPCHAPPWZEMJOBLISTDATA;
	if (s == "dpchappwzemjoblistdo") return DPCHAPPWZEMJOBLISTDO;
	if (s == "dpchappwzemjobrecdo") return DPCHAPPWZEMJOBRECDO;
	if (s == "dpchappwzemjobsup1njobdata") return DPCHAPPWZEMJOBSUP1NJOBDATA;
	if (s == "dpchappwzemjobsup1njobdo") return DPCHAPPWZEMJOBSUP1NJOBDO;
	if (s == "dpchappwzemnavadmindata") return DPCHAPPWZEMNAVADMINDATA;
	if (s == "dpchappwzemnavadmindo") return DPCHAPPWZEMNAVADMINDO;
	if (s == "dpchappwzemnavdo") return DPCHAPPWZEMNAVDO;
	if (s == "dpchappwzemnavmondata") return DPCHAPPWZEMNAVMONDATA;
	if (s == "dpchappwzemnavmondo") return DPCHAPPWZEMNAVMONDO;
	if (s == "dpchappwzemnavpredo") return DPCHAPPWZEMNAVPREDO;
	if (s == "dpchappwzemndedetaildata") return DPCHAPPWZEMNDEDETAILDATA;
	if (s == "dpchappwzemndedetaildo") return DPCHAPPWZEMNDEDETAILDO;
	if (s == "dpchappwzemndedo") return DPCHAPPWZEMNDEDO;
	if (s == "dpchappwzemndelistdata") return DPCHAPPWZEMNDELISTDATA;
	if (s == "dpchappwzemndelistdo") return DPCHAPPWZEMNDELISTDO;
	if (s == "dpchappwzemnderecdo") return DPCHAPPWZEMNDERECDO;
	if (s == "dpchappwzemopxdetaildata") return DPCHAPPWZEMOPXDETAILDATA;
	if (s == "dpchappwzemopxdetaildo") return DPCHAPPWZEMOPXDETAILDO;
	if (s == "dpchappwzemopxdo") return DPCHAPPWZEMOPXDO;
	if (s == "dpchappwzemopxlistdata") return DPCHAPPWZEMOPXLISTDATA;
	if (s == "dpchappwzemopxlistdo") return DPCHAPPWZEMOPXLISTDO;
	if (s == "dpchappwzemopxrecdo") return DPCHAPPWZEMOPXRECDO;
	if (s == "dpchappwzemprd1neventdata") return DPCHAPPWZEMPRD1NEVENTDATA;
	if (s == "dpchappwzemprd1neventdo") return DPCHAPPWZEMPRD1NEVENTDO;
	if (s == "dpchappwzemprd1njobdata") return DPCHAPPWZEMPRD1NJOBDATA;
	if (s == "dpchappwzemprd1njobdo") return DPCHAPPWZEMPRD1NJOBDO;
	if (s == "dpchappwzemprd1nnodedata") return DPCHAPPWZEMPRD1NNODEDATA;
	if (s == "dpchappwzemprd1nnodedo") return DPCHAPPWZEMPRD1NNODEDO;
	if (s == "dpchappwzemprddetaildata") return DPCHAPPWZEMPRDDETAILDATA;
	if (s == "dpchappwzemprddetaildo") return DPCHAPPWZEMPRDDETAILDO;
	if (s == "dpchappwzemprddo") return DPCHAPPWZEMPRDDO;
	if (s == "dpchappwzemprdlistdata") return DPCHAPPWZEMPRDLISTDATA;
	if (s == "dpchappwzemprdlistdo") return DPCHAPPWZEMPRDLISTDO;
	if (s == "dpchappwzemprdrecdo") return DPCHAPPWZEMPRDRECDO;
	if (s == "dpchappwzemprsadetaildata") return DPCHAPPWZEMPRSADETAILDATA;
	if (s == "dpchappwzemprsadetaildo") return DPCHAPPWZEMPRSADETAILDO;
	if (s == "dpchappwzemprsdetaildata") return DPCHAPPWZEMPRSDETAILDATA;
	if (s == "dpchappwzemprsdetaildo") return DPCHAPPWZEMPRSDETAILDO;
	if (s == "dpchappwzemprsdo") return DPCHAPPWZEMPRSDO;
	if (s == "dpchappwzemprslistdata") return DPCHAPPWZEMPRSLISTDATA;
	if (s == "dpchappwzemprslistdo") return DPCHAPPWZEMPRSLISTDO;
	if (s == "dpchappwzemprsrecdo") return DPCHAPPWZEMPRSRECDO;
	if (s == "dpchappwzempstdetaildata") return DPCHAPPWZEMPSTDETAILDATA;
	if (s == "dpchappwzempstdetaildo") return DPCHAPPWZEMPSTDETAILDO;
	if (s == "dpchappwzempstdo") return DPCHAPPWZEMPSTDO;
	if (s == "dpchappwzempstlistdata") return DPCHAPPWZEMPSTLISTDATA;
	if (s == "dpchappwzempstlistdo") return DPCHAPPWZEMPSTLISTDO;
	if (s == "dpchappwzempstrecdo") return DPCHAPPWZEMPSTRECDO;
	if (s == "dpchappwzemresume") return DPCHAPPWZEMRESUME;
	if (s == "dpchappwzemusgaaccessdata") return DPCHAPPWZEMUSGAACCESSDATA;
	if (s == "dpchappwzemusgaaccessdo") return DPCHAPPWZEMUSGAACCESSDO;
	if (s == "dpchappwzemusgdetaildata") return DPCHAPPWZEMUSGDETAILDATA;
	if (s == "dpchappwzemusgdetaildo") return DPCHAPPWZEMUSGDETAILDO;
	if (s == "dpchappwzemusgdo") return DPCHAPPWZEMUSGDO;
	if (s == "dpchappwzemusglistdata") return DPCHAPPWZEMUSGLISTDATA;
	if (s == "dpchappwzemusglistdo") return DPCHAPPWZEMUSGLISTDO;
	if (s == "dpchappwzemusgmnuserdata") return DPCHAPPWZEMUSGMNUSERDATA;
	if (s == "dpchappwzemusgmnuserdo") return DPCHAPPWZEMUSGMNUSERDO;
	if (s == "dpchappwzemusgrecdo") return DPCHAPPWZEMUSGRECDO;
	if (s == "dpchappwzemusr1nsessiondata") return DPCHAPPWZEMUSR1NSESSIONDATA;
	if (s == "dpchappwzemusr1nsessiondo") return DPCHAPPWZEMUSR1NSESSIONDO;
	if (s == "dpchappwzemusraaccessdata") return DPCHAPPWZEMUSRAACCESSDATA;
	if (s == "dpchappwzemusraaccessdo") return DPCHAPPWZEMUSRAACCESSDO;
	if (s == "dpchappwzemusrdetaildata") return DPCHAPPWZEMUSRDETAILDATA;
	if (s == "dpchappwzemusrdetaildo") return DPCHAPPWZEMUSRDETAILDO;
	if (s == "dpchappwzemusrdo") return DPCHAPPWZEMUSRDO;
	if (s == "dpchappwzemusrlistdata") return DPCHAPPWZEMUSRLISTDATA;
	if (s == "dpchappwzemusrlistdo") return DPCHAPPWZEMUSRLISTDO;
	if (s == "dpchappwzemusrmnusergroupdata") return DPCHAPPWZEMUSRMNUSERGROUPDATA;
	if (s == "dpchappwzemusrmnusergroupdo") return DPCHAPPWZEMUSRMNUSERGROUPDO;
	if (s == "dpchappwzemusrrecdo") return DPCHAPPWZEMUSRRECDO;

	return(0);
};

string VecWzemVDpch::getSref(
			const uint ix
		) {
	if (ix == DPCHENGDLGWZEMNAVLOAINIDATA) return("DpchEngDlgWzemNavLoainiData");
	if (ix == DPCHENGROOTWZEMDATA) return("DpchEngRootWzemData");
	if (ix == DPCHENGSESSWZEMDATA) return("DpchEngSessWzemData");
	if (ix == DPCHENGWZEMACK) return("DpchEngWzemAck");
	if (ix == DPCHENGWZEMALERT) return("DpchEngWzemAlert");
	if (ix == DPCHENGWZEMCALDATA) return("DpchEngWzemCalData");
	if (ix == DPCHENGWZEMCALDETAILDATA) return("DpchEngWzemCalDetailData");
	if (ix == DPCHENGWZEMCALHEADBARDATA) return("DpchEngWzemCalHeadbarData");
	if (ix == DPCHENGWZEMCALLISTDATA) return("DpchEngWzemCalListData");
	if (ix == DPCHENGWZEMCALRECDATA) return("DpchEngWzemCalRecData");
	if (ix == DPCHENGWZEMCLNDATA) return("DpchEngWzemClnData");
	if (ix == DPCHENGWZEMCLNDETAILDATA) return("DpchEngWzemClnDetailData");
	if (ix == DPCHENGWZEMCLNHEADBARDATA) return("DpchEngWzemClnHeadbarData");
	if (ix == DPCHENGWZEMCLNLISTDATA) return("DpchEngWzemClnListData");
	if (ix == DPCHENGWZEMCLNRECDATA) return("DpchEngWzemClnRecData");
	if (ix == DPCHENGWZEMCONFIRM) return("DpchEngWzemConfirm");
	if (ix == DPCHENGWZEMEVTDATA) return("DpchEngWzemEvtData");
	if (ix == DPCHENGWZEMEVTDETAILDATA) return("DpchEngWzemEvtDetailData");
	if (ix == DPCHENGWZEMEVTHEADBARDATA) return("DpchEngWzemEvtHeadbarData");
	if (ix == DPCHENGWZEMEVTLISTDATA) return("DpchEngWzemEvtListData");
	if (ix == DPCHENGWZEMEVTRECDATA) return("DpchEngWzemEvtRecData");
	if (ix == DPCHENGWZEMJOB1NCALLDATA) return("DpchEngWzemJob1NCallData");
	if (ix == DPCHENGWZEMJOB1NCLSTNDATA) return("DpchEngWzemJob1NClstnData");
	if (ix == DPCHENGWZEMJOB1NOPDATA) return("DpchEngWzemJob1NOpData");
	if (ix == DPCHENGWZEMJOB1NPRESETDATA) return("DpchEngWzemJob1NPresetData");
	if (ix == DPCHENGWZEMJOBDATA) return("DpchEngWzemJobData");
	if (ix == DPCHENGWZEMJOBDETAILDATA) return("DpchEngWzemJobDetailData");
	if (ix == DPCHENGWZEMJOBHEADBARDATA) return("DpchEngWzemJobHeadbarData");
	if (ix == DPCHENGWZEMJOBLISTDATA) return("DpchEngWzemJobListData");
	if (ix == DPCHENGWZEMJOBRECDATA) return("DpchEngWzemJobRecData");
	if (ix == DPCHENGWZEMJOBSUP1NJOBDATA) return("DpchEngWzemJobSup1NJobData");
	if (ix == DPCHENGWZEMNAVADMINDATA) return("DpchEngWzemNavAdminData");
	if (ix == DPCHENGWZEMNAVDATA) return("DpchEngWzemNavData");
	if (ix == DPCHENGWZEMNAVHEADBARDATA) return("DpchEngWzemNavHeadbarData");
	if (ix == DPCHENGWZEMNAVMONDATA) return("DpchEngWzemNavMonData");
	if (ix == DPCHENGWZEMNAVPREDATA) return("DpchEngWzemNavPreData");
	if (ix == DPCHENGWZEMNDEDATA) return("DpchEngWzemNdeData");
	if (ix == DPCHENGWZEMNDEDETAILDATA) return("DpchEngWzemNdeDetailData");
	if (ix == DPCHENGWZEMNDEHEADBARDATA) return("DpchEngWzemNdeHeadbarData");
	if (ix == DPCHENGWZEMNDELISTDATA) return("DpchEngWzemNdeListData");
	if (ix == DPCHENGWZEMNDERECDATA) return("DpchEngWzemNdeRecData");
	if (ix == DPCHENGWZEMOPXDATA) return("DpchEngWzemOpxData");
	if (ix == DPCHENGWZEMOPXDETAILDATA) return("DpchEngWzemOpxDetailData");
	if (ix == DPCHENGWZEMOPXHEADBARDATA) return("DpchEngWzemOpxHeadbarData");
	if (ix == DPCHENGWZEMOPXLISTDATA) return("DpchEngWzemOpxListData");
	if (ix == DPCHENGWZEMOPXRECDATA) return("DpchEngWzemOpxRecData");
	if (ix == DPCHENGWZEMPRD1NEVENTDATA) return("DpchEngWzemPrd1NEventData");
	if (ix == DPCHENGWZEMPRD1NJOBDATA) return("DpchEngWzemPrd1NJobData");
	if (ix == DPCHENGWZEMPRD1NNODEDATA) return("DpchEngWzemPrd1NNodeData");
	if (ix == DPCHENGWZEMPRDDATA) return("DpchEngWzemPrdData");
	if (ix == DPCHENGWZEMPRDDETAILDATA) return("DpchEngWzemPrdDetailData");
	if (ix == DPCHENGWZEMPRDHEADBARDATA) return("DpchEngWzemPrdHeadbarData");
	if (ix == DPCHENGWZEMPRDLISTDATA) return("DpchEngWzemPrdListData");
	if (ix == DPCHENGWZEMPRDRECDATA) return("DpchEngWzemPrdRecData");
	if (ix == DPCHENGWZEMPRSADETAILDATA) return("DpchEngWzemPrsADetailData");
	if (ix == DPCHENGWZEMPRSDATA) return("DpchEngWzemPrsData");
	if (ix == DPCHENGWZEMPRSDETAILDATA) return("DpchEngWzemPrsDetailData");
	if (ix == DPCHENGWZEMPRSHEADBARDATA) return("DpchEngWzemPrsHeadbarData");
	if (ix == DPCHENGWZEMPRSLISTDATA) return("DpchEngWzemPrsListData");
	if (ix == DPCHENGWZEMPRSRECDATA) return("DpchEngWzemPrsRecData");
	if (ix == DPCHENGWZEMPSTDATA) return("DpchEngWzemPstData");
	if (ix == DPCHENGWZEMPSTDETAILDATA) return("DpchEngWzemPstDetailData");
	if (ix == DPCHENGWZEMPSTHEADBARDATA) return("DpchEngWzemPstHeadbarData");
	if (ix == DPCHENGWZEMPSTLISTDATA) return("DpchEngWzemPstListData");
	if (ix == DPCHENGWZEMPSTRECDATA) return("DpchEngWzemPstRecData");
	if (ix == DPCHENGWZEMSUSPEND) return("DpchEngWzemSuspend");
	if (ix == DPCHENGWZEMUSGAACCESSDATA) return("DpchEngWzemUsgAAccessData");
	if (ix == DPCHENGWZEMUSGDATA) return("DpchEngWzemUsgData");
	if (ix == DPCHENGWZEMUSGDETAILDATA) return("DpchEngWzemUsgDetailData");
	if (ix == DPCHENGWZEMUSGHEADBARDATA) return("DpchEngWzemUsgHeadbarData");
	if (ix == DPCHENGWZEMUSGLISTDATA) return("DpchEngWzemUsgListData");
	if (ix == DPCHENGWZEMUSGMNUSERDATA) return("DpchEngWzemUsgMNUserData");
	if (ix == DPCHENGWZEMUSGRECDATA) return("DpchEngWzemUsgRecData");
	if (ix == DPCHENGWZEMUSR1NSESSIONDATA) return("DpchEngWzemUsr1NSessionData");
	if (ix == DPCHENGWZEMUSRAACCESSDATA) return("DpchEngWzemUsrAAccessData");
	if (ix == DPCHENGWZEMUSRDATA) return("DpchEngWzemUsrData");
	if (ix == DPCHENGWZEMUSRDETAILDATA) return("DpchEngWzemUsrDetailData");
	if (ix == DPCHENGWZEMUSRHEADBARDATA) return("DpchEngWzemUsrHeadbarData");
	if (ix == DPCHENGWZEMUSRLISTDATA) return("DpchEngWzemUsrListData");
	if (ix == DPCHENGWZEMUSRMNUSERGROUPDATA) return("DpchEngWzemUsrMNUsergroupData");
	if (ix == DPCHENGWZEMUSRRECDATA) return("DpchEngWzemUsrRecData");
	if (ix == DPCHAPPDLGWZEMNAVLOAINIDATA) return("DpchAppDlgWzemNavLoainiData");
	if (ix == DPCHAPPDLGWZEMNAVLOAINIDO) return("DpchAppDlgWzemNavLoainiDo");
	if (ix == DPCHAPPROOTWZEMLOGIN) return("DpchAppRootWzemLogin");
	if (ix == DPCHAPPWZEMALERT) return("DpchAppWzemAlert");
	if (ix == DPCHAPPWZEMCALDETAILDATA) return("DpchAppWzemCalDetailData");
	if (ix == DPCHAPPWZEMCALDETAILDO) return("DpchAppWzemCalDetailDo");
	if (ix == DPCHAPPWZEMCALDO) return("DpchAppWzemCalDo");
	if (ix == DPCHAPPWZEMCALLISTDATA) return("DpchAppWzemCalListData");
	if (ix == DPCHAPPWZEMCALLISTDO) return("DpchAppWzemCalListDo");
	if (ix == DPCHAPPWZEMCALRECDO) return("DpchAppWzemCalRecDo");
	if (ix == DPCHAPPWZEMCLNDETAILDATA) return("DpchAppWzemClnDetailData");
	if (ix == DPCHAPPWZEMCLNDETAILDO) return("DpchAppWzemClnDetailDo");
	if (ix == DPCHAPPWZEMCLNDO) return("DpchAppWzemClnDo");
	if (ix == DPCHAPPWZEMCLNLISTDATA) return("DpchAppWzemClnListData");
	if (ix == DPCHAPPWZEMCLNLISTDO) return("DpchAppWzemClnListDo");
	if (ix == DPCHAPPWZEMCLNRECDO) return("DpchAppWzemClnRecDo");
	if (ix == DPCHAPPWZEMEVTDETAILDATA) return("DpchAppWzemEvtDetailData");
	if (ix == DPCHAPPWZEMEVTDETAILDO) return("DpchAppWzemEvtDetailDo");
	if (ix == DPCHAPPWZEMEVTDO) return("DpchAppWzemEvtDo");
	if (ix == DPCHAPPWZEMEVTLISTDATA) return("DpchAppWzemEvtListData");
	if (ix == DPCHAPPWZEMEVTLISTDO) return("DpchAppWzemEvtListDo");
	if (ix == DPCHAPPWZEMEVTRECDO) return("DpchAppWzemEvtRecDo");
	if (ix == DPCHAPPWZEMINIT) return("DpchAppWzemInit");
	if (ix == DPCHAPPWZEMJOB1NCALLDATA) return("DpchAppWzemJob1NCallData");
	if (ix == DPCHAPPWZEMJOB1NCALLDO) return("DpchAppWzemJob1NCallDo");
	if (ix == DPCHAPPWZEMJOB1NCLSTNDATA) return("DpchAppWzemJob1NClstnData");
	if (ix == DPCHAPPWZEMJOB1NCLSTNDO) return("DpchAppWzemJob1NClstnDo");
	if (ix == DPCHAPPWZEMJOB1NOPDATA) return("DpchAppWzemJob1NOpData");
	if (ix == DPCHAPPWZEMJOB1NOPDO) return("DpchAppWzemJob1NOpDo");
	if (ix == DPCHAPPWZEMJOB1NPRESETDATA) return("DpchAppWzemJob1NPresetData");
	if (ix == DPCHAPPWZEMJOB1NPRESETDO) return("DpchAppWzemJob1NPresetDo");
	if (ix == DPCHAPPWZEMJOBDETAILDATA) return("DpchAppWzemJobDetailData");
	if (ix == DPCHAPPWZEMJOBDETAILDO) return("DpchAppWzemJobDetailDo");
	if (ix == DPCHAPPWZEMJOBDO) return("DpchAppWzemJobDo");
	if (ix == DPCHAPPWZEMJOBLISTDATA) return("DpchAppWzemJobListData");
	if (ix == DPCHAPPWZEMJOBLISTDO) return("DpchAppWzemJobListDo");
	if (ix == DPCHAPPWZEMJOBRECDO) return("DpchAppWzemJobRecDo");
	if (ix == DPCHAPPWZEMJOBSUP1NJOBDATA) return("DpchAppWzemJobSup1NJobData");
	if (ix == DPCHAPPWZEMJOBSUP1NJOBDO) return("DpchAppWzemJobSup1NJobDo");
	if (ix == DPCHAPPWZEMNAVADMINDATA) return("DpchAppWzemNavAdminData");
	if (ix == DPCHAPPWZEMNAVADMINDO) return("DpchAppWzemNavAdminDo");
	if (ix == DPCHAPPWZEMNAVDO) return("DpchAppWzemNavDo");
	if (ix == DPCHAPPWZEMNAVMONDATA) return("DpchAppWzemNavMonData");
	if (ix == DPCHAPPWZEMNAVMONDO) return("DpchAppWzemNavMonDo");
	if (ix == DPCHAPPWZEMNAVPREDO) return("DpchAppWzemNavPreDo");
	if (ix == DPCHAPPWZEMNDEDETAILDATA) return("DpchAppWzemNdeDetailData");
	if (ix == DPCHAPPWZEMNDEDETAILDO) return("DpchAppWzemNdeDetailDo");
	if (ix == DPCHAPPWZEMNDEDO) return("DpchAppWzemNdeDo");
	if (ix == DPCHAPPWZEMNDELISTDATA) return("DpchAppWzemNdeListData");
	if (ix == DPCHAPPWZEMNDELISTDO) return("DpchAppWzemNdeListDo");
	if (ix == DPCHAPPWZEMNDERECDO) return("DpchAppWzemNdeRecDo");
	if (ix == DPCHAPPWZEMOPXDETAILDATA) return("DpchAppWzemOpxDetailData");
	if (ix == DPCHAPPWZEMOPXDETAILDO) return("DpchAppWzemOpxDetailDo");
	if (ix == DPCHAPPWZEMOPXDO) return("DpchAppWzemOpxDo");
	if (ix == DPCHAPPWZEMOPXLISTDATA) return("DpchAppWzemOpxListData");
	if (ix == DPCHAPPWZEMOPXLISTDO) return("DpchAppWzemOpxListDo");
	if (ix == DPCHAPPWZEMOPXRECDO) return("DpchAppWzemOpxRecDo");
	if (ix == DPCHAPPWZEMPRD1NEVENTDATA) return("DpchAppWzemPrd1NEventData");
	if (ix == DPCHAPPWZEMPRD1NEVENTDO) return("DpchAppWzemPrd1NEventDo");
	if (ix == DPCHAPPWZEMPRD1NJOBDATA) return("DpchAppWzemPrd1NJobData");
	if (ix == DPCHAPPWZEMPRD1NJOBDO) return("DpchAppWzemPrd1NJobDo");
	if (ix == DPCHAPPWZEMPRD1NNODEDATA) return("DpchAppWzemPrd1NNodeData");
	if (ix == DPCHAPPWZEMPRD1NNODEDO) return("DpchAppWzemPrd1NNodeDo");
	if (ix == DPCHAPPWZEMPRDDETAILDATA) return("DpchAppWzemPrdDetailData");
	if (ix == DPCHAPPWZEMPRDDETAILDO) return("DpchAppWzemPrdDetailDo");
	if (ix == DPCHAPPWZEMPRDDO) return("DpchAppWzemPrdDo");
	if (ix == DPCHAPPWZEMPRDLISTDATA) return("DpchAppWzemPrdListData");
	if (ix == DPCHAPPWZEMPRDLISTDO) return("DpchAppWzemPrdListDo");
	if (ix == DPCHAPPWZEMPRDRECDO) return("DpchAppWzemPrdRecDo");
	if (ix == DPCHAPPWZEMPRSADETAILDATA) return("DpchAppWzemPrsADetailData");
	if (ix == DPCHAPPWZEMPRSADETAILDO) return("DpchAppWzemPrsADetailDo");
	if (ix == DPCHAPPWZEMPRSDETAILDATA) return("DpchAppWzemPrsDetailData");
	if (ix == DPCHAPPWZEMPRSDETAILDO) return("DpchAppWzemPrsDetailDo");
	if (ix == DPCHAPPWZEMPRSDO) return("DpchAppWzemPrsDo");
	if (ix == DPCHAPPWZEMPRSLISTDATA) return("DpchAppWzemPrsListData");
	if (ix == DPCHAPPWZEMPRSLISTDO) return("DpchAppWzemPrsListDo");
	if (ix == DPCHAPPWZEMPRSRECDO) return("DpchAppWzemPrsRecDo");
	if (ix == DPCHAPPWZEMPSTDETAILDATA) return("DpchAppWzemPstDetailData");
	if (ix == DPCHAPPWZEMPSTDETAILDO) return("DpchAppWzemPstDetailDo");
	if (ix == DPCHAPPWZEMPSTDO) return("DpchAppWzemPstDo");
	if (ix == DPCHAPPWZEMPSTLISTDATA) return("DpchAppWzemPstListData");
	if (ix == DPCHAPPWZEMPSTLISTDO) return("DpchAppWzemPstListDo");
	if (ix == DPCHAPPWZEMPSTRECDO) return("DpchAppWzemPstRecDo");
	if (ix == DPCHAPPWZEMRESUME) return("DpchAppWzemResume");
	if (ix == DPCHAPPWZEMUSGAACCESSDATA) return("DpchAppWzemUsgAAccessData");
	if (ix == DPCHAPPWZEMUSGAACCESSDO) return("DpchAppWzemUsgAAccessDo");
	if (ix == DPCHAPPWZEMUSGDETAILDATA) return("DpchAppWzemUsgDetailData");
	if (ix == DPCHAPPWZEMUSGDETAILDO) return("DpchAppWzemUsgDetailDo");
	if (ix == DPCHAPPWZEMUSGDO) return("DpchAppWzemUsgDo");
	if (ix == DPCHAPPWZEMUSGLISTDATA) return("DpchAppWzemUsgListData");
	if (ix == DPCHAPPWZEMUSGLISTDO) return("DpchAppWzemUsgListDo");
	if (ix == DPCHAPPWZEMUSGMNUSERDATA) return("DpchAppWzemUsgMNUserData");
	if (ix == DPCHAPPWZEMUSGMNUSERDO) return("DpchAppWzemUsgMNUserDo");
	if (ix == DPCHAPPWZEMUSGRECDO) return("DpchAppWzemUsgRecDo");
	if (ix == DPCHAPPWZEMUSR1NSESSIONDATA) return("DpchAppWzemUsr1NSessionData");
	if (ix == DPCHAPPWZEMUSR1NSESSIONDO) return("DpchAppWzemUsr1NSessionDo");
	if (ix == DPCHAPPWZEMUSRAACCESSDATA) return("DpchAppWzemUsrAAccessData");
	if (ix == DPCHAPPWZEMUSRAACCESSDO) return("DpchAppWzemUsrAAccessDo");
	if (ix == DPCHAPPWZEMUSRDETAILDATA) return("DpchAppWzemUsrDetailData");
	if (ix == DPCHAPPWZEMUSRDETAILDO) return("DpchAppWzemUsrDetailDo");
	if (ix == DPCHAPPWZEMUSRDO) return("DpchAppWzemUsrDo");
	if (ix == DPCHAPPWZEMUSRLISTDATA) return("DpchAppWzemUsrListData");
	if (ix == DPCHAPPWZEMUSRLISTDO) return("DpchAppWzemUsrListDo");
	if (ix == DPCHAPPWZEMUSRMNUSERGROUPDATA) return("DpchAppWzemUsrMNUsergroupData");
	if (ix == DPCHAPPWZEMUSRMNUSERGROUPDO) return("DpchAppWzemUsrMNUsergroupDo");
	if (ix == DPCHAPPWZEMUSRRECDO) return("DpchAppWzemUsrRecDo");

	return("");
};
