/**
	* \file PnlWzemNavMon.cpp
	* API code for job PnlWzemNavMon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzemNavMon.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemNavMon::VecVDo
 ******************************************************************************/

uint PnlWzemNavMon::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butprdviewclick") return BUTPRDVIEWCLICK;
	if (s == "butprdnewcrdclick") return BUTPRDNEWCRDCLICK;
	if (s == "butevtviewclick") return BUTEVTVIEWCLICK;
	if (s == "butevtnewcrdclick") return BUTEVTNEWCRDCLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butjobnewcrdclick") return BUTJOBNEWCRDCLICK;
	if (s == "butcalviewclick") return BUTCALVIEWCLICK;
	if (s == "butcalnewcrdclick") return BUTCALNEWCRDCLICK;
	if (s == "butclnviewclick") return BUTCLNVIEWCLICK;
	if (s == "butclnnewcrdclick") return BUTCLNNEWCRDCLICK;
	if (s == "butopxviewclick") return BUTOPXVIEWCLICK;
	if (s == "butopxnewcrdclick") return BUTOPXNEWCRDCLICK;
	if (s == "butpstviewclick") return BUTPSTVIEWCLICK;
	if (s == "butpstnewcrdclick") return BUTPSTNEWCRDCLICK;
	if (s == "butndeviewclick") return BUTNDEVIEWCLICK;
	if (s == "butndenewcrdclick") return BUTNDENEWCRDCLICK;

	return(0);
};

string PnlWzemNavMon::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");
	if (ix == BUTPRDNEWCRDCLICK) return("ButPrdNewcrdClick");
	if (ix == BUTEVTVIEWCLICK) return("ButEvtViewClick");
	if (ix == BUTEVTNEWCRDCLICK) return("ButEvtNewcrdClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTJOBNEWCRDCLICK) return("ButJobNewcrdClick");
	if (ix == BUTCALVIEWCLICK) return("ButCalViewClick");
	if (ix == BUTCALNEWCRDCLICK) return("ButCalNewcrdClick");
	if (ix == BUTCLNVIEWCLICK) return("ButClnViewClick");
	if (ix == BUTCLNNEWCRDCLICK) return("ButClnNewcrdClick");
	if (ix == BUTOPXVIEWCLICK) return("ButOpxViewClick");
	if (ix == BUTOPXNEWCRDCLICK) return("ButOpxNewcrdClick");
	if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
	if (ix == BUTPSTNEWCRDCLICK) return("ButPstNewcrdClick");
	if (ix == BUTNDEVIEWCLICK) return("ButNdeViewClick");
	if (ix == BUTNDENEWCRDCLICK) return("ButNdeNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzemNavMon::ContIac
 ******************************************************************************/

PnlWzemNavMon::ContIac::ContIac(
			const uint numFLstPrd
			, const uint numFLstEvt
			, const uint numFLstJob
			, const uint numFLstCal
			, const uint numFLstCln
			, const uint numFLstOpx
			, const uint numFLstPst
			, const uint numFLstNde
		) :
			Block()
		{
	this->numFLstPrd = numFLstPrd;
	this->numFLstEvt = numFLstEvt;
	this->numFLstJob = numFLstJob;
	this->numFLstCal = numFLstCal;
	this->numFLstCln = numFLstCln;
	this->numFLstOpx = numFLstOpx;
	this->numFLstPst = numFLstPst;
	this->numFLstNde = numFLstNde;

	mask = {NUMFLSTPRD, NUMFLSTEVT, NUMFLSTJOB, NUMFLSTCAL, NUMFLSTCLN, NUMFLSTOPX, NUMFLSTPST, NUMFLSTNDE};
};

bool PnlWzemNavMon::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemNavMon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemNavMon";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrd", numFLstPrd)) add(NUMFLSTPRD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstEvt", numFLstEvt)) add(NUMFLSTEVT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstJob", numFLstJob)) add(NUMFLSTJOB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCal", numFLstCal)) add(NUMFLSTCAL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCln", numFLstCln)) add(NUMFLSTCLN);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpx", numFLstOpx)) add(NUMFLSTOPX);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPst", numFLstPst)) add(NUMFLSTPST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstNde", numFLstNde)) add(NUMFLSTNDE);
	};

	return basefound;
};

void PnlWzemNavMon::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemNavMon";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemNavMon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPrd", numFLstPrd);
		writeUintAttr(wr, itemtag, "sref", "numFLstEvt", numFLstEvt);
		writeUintAttr(wr, itemtag, "sref", "numFLstJob", numFLstJob);
		writeUintAttr(wr, itemtag, "sref", "numFLstCal", numFLstCal);
		writeUintAttr(wr, itemtag, "sref", "numFLstCln", numFLstCln);
		writeUintAttr(wr, itemtag, "sref", "numFLstOpx", numFLstOpx);
		writeUintAttr(wr, itemtag, "sref", "numFLstPst", numFLstPst);
		writeUintAttr(wr, itemtag, "sref", "numFLstNde", numFLstNde);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemNavMon::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrd == comp->numFLstPrd) insert(items, NUMFLSTPRD);
	if (numFLstEvt == comp->numFLstEvt) insert(items, NUMFLSTEVT);
	if (numFLstJob == comp->numFLstJob) insert(items, NUMFLSTJOB);
	if (numFLstCal == comp->numFLstCal) insert(items, NUMFLSTCAL);
	if (numFLstCln == comp->numFLstCln) insert(items, NUMFLSTCLN);
	if (numFLstOpx == comp->numFLstOpx) insert(items, NUMFLSTOPX);
	if (numFLstPst == comp->numFLstPst) insert(items, NUMFLSTPST);
	if (numFLstNde == comp->numFLstNde) insert(items, NUMFLSTNDE);

	return(items);
};

set<uint> PnlWzemNavMon::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRD, NUMFLSTEVT, NUMFLSTJOB, NUMFLSTCAL, NUMFLSTCLN, NUMFLSTOPX, NUMFLSTPST, NUMFLSTNDE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavMon::StatApp
 ******************************************************************************/

PnlWzemNavMon::StatApp::StatApp(
			const uint ixWzemVExpstate
			, const bool LstPrdAlt
			, const bool LstEvtAlt
			, const bool LstJobAlt
			, const bool LstCalAlt
			, const bool LstClnAlt
			, const bool LstOpxAlt
			, const bool LstPstAlt
			, const bool LstNdeAlt
			, const uint LstPrdNumFirstdisp
			, const uint LstEvtNumFirstdisp
			, const uint LstJobNumFirstdisp
			, const uint LstCalNumFirstdisp
			, const uint LstClnNumFirstdisp
			, const uint LstOpxNumFirstdisp
			, const uint LstPstNumFirstdisp
			, const uint LstNdeNumFirstdisp
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->LstPrdAlt = LstPrdAlt;
	this->LstEvtAlt = LstEvtAlt;
	this->LstJobAlt = LstJobAlt;
	this->LstCalAlt = LstCalAlt;
	this->LstClnAlt = LstClnAlt;
	this->LstOpxAlt = LstOpxAlt;
	this->LstPstAlt = LstPstAlt;
	this->LstNdeAlt = LstNdeAlt;
	this->LstPrdNumFirstdisp = LstPrdNumFirstdisp;
	this->LstEvtNumFirstdisp = LstEvtNumFirstdisp;
	this->LstJobNumFirstdisp = LstJobNumFirstdisp;
	this->LstCalNumFirstdisp = LstCalNumFirstdisp;
	this->LstClnNumFirstdisp = LstClnNumFirstdisp;
	this->LstOpxNumFirstdisp = LstOpxNumFirstdisp;
	this->LstPstNumFirstdisp = LstPstNumFirstdisp;
	this->LstNdeNumFirstdisp = LstNdeNumFirstdisp;

	mask = {IXWZEMVEXPSTATE, LSTPRDALT, LSTEVTALT, LSTJOBALT, LSTCALALT, LSTCLNALT, LSTOPXALT, LSTPSTALT, LSTNDEALT, LSTPRDNUMFIRSTDISP, LSTEVTNUMFIRSTDISP, LSTJOBNUMFIRSTDISP, LSTCALNUMFIRSTDISP, LSTCLNNUMFIRSTDISP, LSTOPXNUMFIRSTDISP, LSTPSTNUMFIRSTDISP, LSTNDENUMFIRSTDISP};
};

bool PnlWzemNavMon::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemNavMon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemNavMon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrdAlt", LstPrdAlt)) add(LSTPRDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEvtAlt", LstEvtAlt)) add(LSTEVTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstJobAlt", LstJobAlt)) add(LSTJOBALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCalAlt", LstCalAlt)) add(LSTCALALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstClnAlt", LstClnAlt)) add(LSTCLNALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpxAlt", LstOpxAlt)) add(LSTOPXALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPstAlt", LstPstAlt)) add(LSTPSTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstNdeAlt", LstNdeAlt)) add(LSTNDEALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrdNumFirstdisp", LstPrdNumFirstdisp)) add(LSTPRDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEvtNumFirstdisp", LstEvtNumFirstdisp)) add(LSTEVTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstJobNumFirstdisp", LstJobNumFirstdisp)) add(LSTJOBNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCalNumFirstdisp", LstCalNumFirstdisp)) add(LSTCALNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstClnNumFirstdisp", LstClnNumFirstdisp)) add(LSTCLNNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpxNumFirstdisp", LstOpxNumFirstdisp)) add(LSTOPXNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPstNumFirstdisp", LstPstNumFirstdisp)) add(LSTPSTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstNdeNumFirstdisp", LstNdeNumFirstdisp)) add(LSTNDENUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzemNavMon::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (LstPrdAlt == comp->LstPrdAlt) insert(items, LSTPRDALT);
	if (LstEvtAlt == comp->LstEvtAlt) insert(items, LSTEVTALT);
	if (LstJobAlt == comp->LstJobAlt) insert(items, LSTJOBALT);
	if (LstCalAlt == comp->LstCalAlt) insert(items, LSTCALALT);
	if (LstClnAlt == comp->LstClnAlt) insert(items, LSTCLNALT);
	if (LstOpxAlt == comp->LstOpxAlt) insert(items, LSTOPXALT);
	if (LstPstAlt == comp->LstPstAlt) insert(items, LSTPSTALT);
	if (LstNdeAlt == comp->LstNdeAlt) insert(items, LSTNDEALT);
	if (LstPrdNumFirstdisp == comp->LstPrdNumFirstdisp) insert(items, LSTPRDNUMFIRSTDISP);
	if (LstEvtNumFirstdisp == comp->LstEvtNumFirstdisp) insert(items, LSTEVTNUMFIRSTDISP);
	if (LstJobNumFirstdisp == comp->LstJobNumFirstdisp) insert(items, LSTJOBNUMFIRSTDISP);
	if (LstCalNumFirstdisp == comp->LstCalNumFirstdisp) insert(items, LSTCALNUMFIRSTDISP);
	if (LstClnNumFirstdisp == comp->LstClnNumFirstdisp) insert(items, LSTCLNNUMFIRSTDISP);
	if (LstOpxNumFirstdisp == comp->LstOpxNumFirstdisp) insert(items, LSTOPXNUMFIRSTDISP);
	if (LstPstNumFirstdisp == comp->LstPstNumFirstdisp) insert(items, LSTPSTNUMFIRSTDISP);
	if (LstNdeNumFirstdisp == comp->LstNdeNumFirstdisp) insert(items, LSTNDENUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzemNavMon::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, LSTPRDALT, LSTEVTALT, LSTJOBALT, LSTCALALT, LSTCLNALT, LSTOPXALT, LSTPSTALT, LSTNDEALT, LSTPRDNUMFIRSTDISP, LSTEVTNUMFIRSTDISP, LSTJOBNUMFIRSTDISP, LSTCALNUMFIRSTDISP, LSTCLNNUMFIRSTDISP, LSTOPXNUMFIRSTDISP, LSTPSTNUMFIRSTDISP, LSTNDENUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavMon::StatShr
 ******************************************************************************/

PnlWzemNavMon::StatShr::StatShr(
			const bool LstPrdAvail
			, const bool ButPrdViewActive
			, const bool LstEvtAvail
			, const bool ButEvtViewActive
			, const bool ButEvtNewcrdActive
			, const bool LstJobAvail
			, const bool ButJobViewActive
			, const bool ButJobNewcrdActive
			, const bool LstCalAvail
			, const bool ButCalViewActive
			, const bool ButCalNewcrdActive
			, const bool LstClnAvail
			, const bool ButClnViewActive
			, const bool ButClnNewcrdActive
			, const bool LstOpxAvail
			, const bool ButOpxViewActive
			, const bool ButOpxNewcrdActive
			, const bool LstPstAvail
			, const bool ButPstViewActive
			, const bool ButPstNewcrdActive
			, const bool LstNdeAvail
			, const bool ButNdeViewActive
			, const bool ButNdeNewcrdActive
		) :
			Block()
		{
	this->LstPrdAvail = LstPrdAvail;
	this->ButPrdViewActive = ButPrdViewActive;
	this->LstEvtAvail = LstEvtAvail;
	this->ButEvtViewActive = ButEvtViewActive;
	this->ButEvtNewcrdActive = ButEvtNewcrdActive;
	this->LstJobAvail = LstJobAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->ButJobNewcrdActive = ButJobNewcrdActive;
	this->LstCalAvail = LstCalAvail;
	this->ButCalViewActive = ButCalViewActive;
	this->ButCalNewcrdActive = ButCalNewcrdActive;
	this->LstClnAvail = LstClnAvail;
	this->ButClnViewActive = ButClnViewActive;
	this->ButClnNewcrdActive = ButClnNewcrdActive;
	this->LstOpxAvail = LstOpxAvail;
	this->ButOpxViewActive = ButOpxViewActive;
	this->ButOpxNewcrdActive = ButOpxNewcrdActive;
	this->LstPstAvail = LstPstAvail;
	this->ButPstViewActive = ButPstViewActive;
	this->ButPstNewcrdActive = ButPstNewcrdActive;
	this->LstNdeAvail = LstNdeAvail;
	this->ButNdeViewActive = ButNdeViewActive;
	this->ButNdeNewcrdActive = ButNdeNewcrdActive;

	mask = {LSTPRDAVAIL, BUTPRDVIEWACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTJOBAVAIL, BUTJOBVIEWACTIVE, BUTJOBNEWCRDACTIVE, LSTCALAVAIL, BUTCALVIEWACTIVE, BUTCALNEWCRDACTIVE, LSTCLNAVAIL, BUTCLNVIEWACTIVE, BUTCLNNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE, LSTPSTAVAIL, BUTPSTVIEWACTIVE, BUTPSTNEWCRDACTIVE, LSTNDEAVAIL, BUTNDEVIEWACTIVE, BUTNDENEWCRDACTIVE};
};

bool PnlWzemNavMon::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemNavMon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemNavMon";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrdAvail", LstPrdAvail)) add(LSTPRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", ButPrdViewActive)) add(BUTPRDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEvtAvail", LstEvtAvail)) add(LSTEVTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEvtViewActive", ButEvtViewActive)) add(BUTEVTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEvtNewcrdActive", ButEvtNewcrdActive)) add(BUTEVTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstJobAvail", LstJobAvail)) add(LSTJOBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobNewcrdActive", ButJobNewcrdActive)) add(BUTJOBNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCalAvail", LstCalAvail)) add(LSTCALAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCalViewActive", ButCalViewActive)) add(BUTCALVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCalNewcrdActive", ButCalNewcrdActive)) add(BUTCALNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstClnAvail", LstClnAvail)) add(LSTCLNAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClnViewActive", ButClnViewActive)) add(BUTCLNVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClnNewcrdActive", ButClnNewcrdActive)) add(BUTCLNNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpxAvail", LstOpxAvail)) add(LSTOPXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpxViewActive", ButOpxViewActive)) add(BUTOPXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpxNewcrdActive", ButOpxNewcrdActive)) add(BUTOPXNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPstAvail", LstPstAvail)) add(LSTPSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstViewActive", ButPstViewActive)) add(BUTPSTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstNewcrdActive", ButPstNewcrdActive)) add(BUTPSTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstNdeAvail", LstNdeAvail)) add(LSTNDEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNdeViewActive", ButNdeViewActive)) add(BUTNDEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNdeNewcrdActive", ButNdeNewcrdActive)) add(BUTNDENEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemNavMon::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPrdAvail == comp->LstPrdAvail) insert(items, LSTPRDAVAIL);
	if (ButPrdViewActive == comp->ButPrdViewActive) insert(items, BUTPRDVIEWACTIVE);
	if (LstEvtAvail == comp->LstEvtAvail) insert(items, LSTEVTAVAIL);
	if (ButEvtViewActive == comp->ButEvtViewActive) insert(items, BUTEVTVIEWACTIVE);
	if (ButEvtNewcrdActive == comp->ButEvtNewcrdActive) insert(items, BUTEVTNEWCRDACTIVE);
	if (LstJobAvail == comp->LstJobAvail) insert(items, LSTJOBAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (ButJobNewcrdActive == comp->ButJobNewcrdActive) insert(items, BUTJOBNEWCRDACTIVE);
	if (LstCalAvail == comp->LstCalAvail) insert(items, LSTCALAVAIL);
	if (ButCalViewActive == comp->ButCalViewActive) insert(items, BUTCALVIEWACTIVE);
	if (ButCalNewcrdActive == comp->ButCalNewcrdActive) insert(items, BUTCALNEWCRDACTIVE);
	if (LstClnAvail == comp->LstClnAvail) insert(items, LSTCLNAVAIL);
	if (ButClnViewActive == comp->ButClnViewActive) insert(items, BUTCLNVIEWACTIVE);
	if (ButClnNewcrdActive == comp->ButClnNewcrdActive) insert(items, BUTCLNNEWCRDACTIVE);
	if (LstOpxAvail == comp->LstOpxAvail) insert(items, LSTOPXAVAIL);
	if (ButOpxViewActive == comp->ButOpxViewActive) insert(items, BUTOPXVIEWACTIVE);
	if (ButOpxNewcrdActive == comp->ButOpxNewcrdActive) insert(items, BUTOPXNEWCRDACTIVE);
	if (LstPstAvail == comp->LstPstAvail) insert(items, LSTPSTAVAIL);
	if (ButPstViewActive == comp->ButPstViewActive) insert(items, BUTPSTVIEWACTIVE);
	if (ButPstNewcrdActive == comp->ButPstNewcrdActive) insert(items, BUTPSTNEWCRDACTIVE);
	if (LstNdeAvail == comp->LstNdeAvail) insert(items, LSTNDEAVAIL);
	if (ButNdeViewActive == comp->ButNdeViewActive) insert(items, BUTNDEVIEWACTIVE);
	if (ButNdeNewcrdActive == comp->ButNdeNewcrdActive) insert(items, BUTNDENEWCRDACTIVE);

	return(items);
};

set<uint> PnlWzemNavMon::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPRDAVAIL, BUTPRDVIEWACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTJOBAVAIL, BUTJOBVIEWACTIVE, BUTJOBNEWCRDACTIVE, LSTCALAVAIL, BUTCALVIEWACTIVE, BUTCALNEWCRDACTIVE, LSTCLNAVAIL, BUTCLNVIEWACTIVE, BUTCLNNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE, LSTPSTAVAIL, BUTPSTVIEWACTIVE, BUTPSTNEWCRDACTIVE, LSTNDEAVAIL, BUTNDEVIEWACTIVE, BUTNDENEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemNavMon::Tag
 ******************************************************************************/

PnlWzemNavMon::Tag::Tag(
			const string& Cpt
			, const string& CptPrd
			, const string& CptEvt
			, const string& CptJob
			, const string& CptCal
			, const string& CptCln
			, const string& CptOpx
			, const string& CptPst
			, const string& CptNde
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrd = CptPrd;
	this->CptEvt = CptEvt;
	this->CptJob = CptJob;
	this->CptCal = CptCal;
	this->CptCln = CptCln;
	this->CptOpx = CptOpx;
	this->CptPst = CptPst;
	this->CptNde = CptNde;

	mask = {CPT, CPTPRD, CPTEVT, CPTJOB, CPTCAL, CPTCLN, CPTOPX, CPTPST, CPTNDE};
};

bool PnlWzemNavMon::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemNavMon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemNavMon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEvt", CptEvt)) add(CPTEVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCal", CptCal)) add(CPTCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCln", CptCln)) add(CPTCLN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpx", CptOpx)) add(CPTOPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPst", CptPst)) add(CPTPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptNde", CptNde)) add(CPTNDE);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemNavMon::DpchAppData
 ******************************************************************************/

PnlWzemNavMon::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVMONDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemNavMon::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavMon::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNavMonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavMon::DpchAppDo
 ******************************************************************************/

PnlWzemNavMon::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVMONDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemNavMon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavMon::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemNavMonDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavMon::DpchEngData
 ******************************************************************************/

PnlWzemNavMon::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVMONDATA)
		{
	feedFLstCal.tag = "FeedFLstCal";
	feedFLstCln.tag = "FeedFLstCln";
	feedFLstEvt.tag = "FeedFLstEvt";
	feedFLstJob.tag = "FeedFLstJob";
	feedFLstNde.tag = "FeedFLstNde";
	feedFLstOpx.tag = "FeedFLstOpx";
	feedFLstPrd.tag = "FeedFLstPrd";
	feedFLstPst.tag = "FeedFLstPst";
};

string PnlWzemNavMon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCAL)) ss.push_back("feedFLstCal");
	if (has(FEEDFLSTCLN)) ss.push_back("feedFLstCln");
	if (has(FEEDFLSTEVT)) ss.push_back("feedFLstEvt");
	if (has(FEEDFLSTJOB)) ss.push_back("feedFLstJob");
	if (has(FEEDFLSTNDE)) ss.push_back("feedFLstNde");
	if (has(FEEDFLSTOPX)) ss.push_back("feedFLstOpx");
	if (has(FEEDFLSTPRD)) ss.push_back("feedFLstPrd");
	if (has(FEEDFLSTPST)) ss.push_back("feedFLstPst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavMon::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemNavMonData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCal.readXML(docctx, basexpath, true)) add(FEEDFLSTCAL);
		if (feedFLstCln.readXML(docctx, basexpath, true)) add(FEEDFLSTCLN);
		if (feedFLstEvt.readXML(docctx, basexpath, true)) add(FEEDFLSTEVT);
		if (feedFLstJob.readXML(docctx, basexpath, true)) add(FEEDFLSTJOB);
		if (feedFLstNde.readXML(docctx, basexpath, true)) add(FEEDFLSTNDE);
		if (feedFLstOpx.readXML(docctx, basexpath, true)) add(FEEDFLSTOPX);
		if (feedFLstPrd.readXML(docctx, basexpath, true)) add(FEEDFLSTPRD);
		if (feedFLstPst.readXML(docctx, basexpath, true)) add(FEEDFLSTPST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCal.clear();
		feedFLstCln.clear();
		feedFLstEvt.clear();
		feedFLstJob.clear();
		feedFLstNde.clear();
		feedFLstOpx.clear();
		feedFLstPrd.clear();
		feedFLstPst.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
