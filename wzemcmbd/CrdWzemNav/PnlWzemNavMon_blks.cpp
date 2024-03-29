/**
	* \file PnlWzemNavMon_blks.cpp
	* job handler for job PnlWzemNavMon (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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

bool PnlWzemNavMon::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWzemNavMon"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstPrd")) {numFLstPrd = me["numFLstPrd"].asUInt(); add(NUMFLSTPRD);};
		if (me.isMember("numFLstEvt")) {numFLstEvt = me["numFLstEvt"].asUInt(); add(NUMFLSTEVT);};
		if (me.isMember("numFLstJob")) {numFLstJob = me["numFLstJob"].asUInt(); add(NUMFLSTJOB);};
		if (me.isMember("numFLstCal")) {numFLstCal = me["numFLstCal"].asUInt(); add(NUMFLSTCAL);};
		if (me.isMember("numFLstCln")) {numFLstCln = me["numFLstCln"].asUInt(); add(NUMFLSTCLN);};
		if (me.isMember("numFLstOpx")) {numFLstOpx = me["numFLstOpx"].asUInt(); add(NUMFLSTOPX);};
		if (me.isMember("numFLstPst")) {numFLstPst = me["numFLstPst"].asUInt(); add(NUMFLSTPST);};
		if (me.isMember("numFLstNde")) {numFLstNde = me["numFLstNde"].asUInt(); add(NUMFLSTNDE);};
	};

	return basefound;
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

void PnlWzemNavMon::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemNavMon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstPrd"] = numFLstPrd;
	me["numFLstEvt"] = numFLstEvt;
	me["numFLstJob"] = numFLstJob;
	me["numFLstCal"] = numFLstCal;
	me["numFLstCln"] = numFLstCln;
	me["numFLstOpx"] = numFLstOpx;
	me["numFLstPst"] = numFLstPst;
	me["numFLstNde"] = numFLstNde;
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

void PnlWzemNavMon::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWzemVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemNavMon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWzemVExpstate"] = VecWzemVExpstate::getSref(ixWzemVExpstate);
	me["LstPrdAlt"] = LstPrdAlt;
	me["LstEvtAlt"] = LstEvtAlt;
	me["LstJobAlt"] = LstJobAlt;
	me["LstCalAlt"] = LstCalAlt;
	me["LstClnAlt"] = LstClnAlt;
	me["LstOpxAlt"] = LstOpxAlt;
	me["LstPstAlt"] = LstPstAlt;
	me["LstNdeAlt"] = LstNdeAlt;
	me["LstPrdNumFirstdisp"] = LstPrdNumFirstdisp;
	me["LstEvtNumFirstdisp"] = LstEvtNumFirstdisp;
	me["LstJobNumFirstdisp"] = LstJobNumFirstdisp;
	me["LstCalNumFirstdisp"] = LstCalNumFirstdisp;
	me["LstClnNumFirstdisp"] = LstClnNumFirstdisp;
	me["LstOpxNumFirstdisp"] = LstOpxNumFirstdisp;
	me["LstPstNumFirstdisp"] = LstPstNumFirstdisp;
	me["LstNdeNumFirstdisp"] = LstNdeNumFirstdisp;
};

void PnlWzemNavMon::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemNavMon";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemNavMon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPrdAlt", LstPrdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstEvtAlt", LstEvtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstJobAlt", LstJobAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCalAlt", LstCalAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstClnAlt", LstClnAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOpxAlt", LstOpxAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPstAlt", LstPstAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstNdeAlt", LstNdeAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPrdNumFirstdisp", LstPrdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstEvtNumFirstdisp", LstEvtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstJobNumFirstdisp", LstJobNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCalNumFirstdisp", LstCalNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstClnNumFirstdisp", LstClnNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOpxNumFirstdisp", LstOpxNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPstNumFirstdisp", LstPstNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstNdeNumFirstdisp", LstNdeNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWzemNavMon::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNavMon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstPrdAvail"] = LstPrdAvail;
	me["ButPrdViewActive"] = ButPrdViewActive;
	me["LstEvtAvail"] = LstEvtAvail;
	me["ButEvtViewActive"] = ButEvtViewActive;
	me["ButEvtNewcrdActive"] = ButEvtNewcrdActive;
	me["LstJobAvail"] = LstJobAvail;
	me["ButJobViewActive"] = ButJobViewActive;
	me["ButJobNewcrdActive"] = ButJobNewcrdActive;
	me["LstCalAvail"] = LstCalAvail;
	me["ButCalViewActive"] = ButCalViewActive;
	me["ButCalNewcrdActive"] = ButCalNewcrdActive;
	me["LstClnAvail"] = LstClnAvail;
	me["ButClnViewActive"] = ButClnViewActive;
	me["ButClnNewcrdActive"] = ButClnNewcrdActive;
	me["LstOpxAvail"] = LstOpxAvail;
	me["ButOpxViewActive"] = ButOpxViewActive;
	me["ButOpxNewcrdActive"] = ButOpxNewcrdActive;
	me["LstPstAvail"] = LstPstAvail;
	me["ButPstViewActive"] = ButPstViewActive;
	me["ButPstNewcrdActive"] = ButPstNewcrdActive;
	me["LstNdeAvail"] = LstNdeAvail;
	me["ButNdeViewActive"] = ButNdeViewActive;
	me["ButNdeNewcrdActive"] = ButNdeNewcrdActive;
};

void PnlWzemNavMon::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemNavMon";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemNavMon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstPrdAvail", LstPrdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrdViewActive", ButPrdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstEvtAvail", LstEvtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEvtViewActive", ButEvtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEvtNewcrdActive", ButEvtNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstJobAvail", LstJobAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobNewcrdActive", ButJobNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCalAvail", LstCalAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCalViewActive", ButCalViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCalNewcrdActive", ButCalNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstClnAvail", LstClnAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButClnViewActive", ButClnViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButClnNewcrdActive", ButClnNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOpxAvail", LstOpxAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOpxViewActive", ButOpxViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOpxNewcrdActive", ButOpxNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPstAvail", LstPstAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewActive", ButPstViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstNewcrdActive", ButPstNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstNdeAvail", LstNdeAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButNdeViewActive", ButNdeViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButNdeNewcrdActive", ButNdeNewcrdActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzemNavMon::Tag::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWzemNavMon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWzemVLocale == VecWzemVLocale::ENUS) {
		me["Cpt"] = "Monitoring";
		me["CptPrd"] = "monitoring periods";
		me["CptEvt"] = "events";
		me["CptJob"] = "jobs";
		me["CptCal"] = "calls";
		me["CptCln"] = "call listeners";
		me["CptOpx"] = "operations";
		me["CptPst"] = "presettings";
		me["CptNde"] = "nodes";
	};
};

void PnlWzemNavMon::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemNavMon";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemNavMon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Monitoring");
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "monitoring periods");
			writeStringAttr(wr, itemtag, "sref", "CptEvt", "events");
			writeStringAttr(wr, itemtag, "sref", "CptJob", "jobs");
			writeStringAttr(wr, itemtag, "sref", "CptCal", "calls");
			writeStringAttr(wr, itemtag, "sref", "CptCln", "call listeners");
			writeStringAttr(wr, itemtag, "sref", "CptOpx", "operations");
			writeStringAttr(wr, itemtag, "sref", "CptPst", "presettings");
			writeStringAttr(wr, itemtag, "sref", "CptNde", "nodes");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemNavMon::DpchAppData
 ******************************************************************************/

PnlWzemNavMon::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVMONDATA)
		{
};

string PnlWzemNavMon::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavMon::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemNavMonData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWzemNavMon::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemNavMonData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWzemNavMon::DpchAppDo
 ******************************************************************************/

PnlWzemNavMon::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMNAVMONDO)
		{
	ixVDo = 0;
};

string PnlWzemNavMon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemNavMon::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWzemNavMonDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWzemNavMon::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemNavMonDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlWzemNavMon::DpchEngData
 ******************************************************************************/

PnlWzemNavMon::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCal
			, Feed* feedFLstCln
			, Feed* feedFLstEvt
			, Feed* feedFLstJob
			, Feed* feedFLstNde
			, Feed* feedFLstOpx
			, Feed* feedFLstPrd
			, Feed* feedFLstPst
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMNAVMONDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCAL, FEEDFLSTCLN, FEEDFLSTEVT, FEEDFLSTJOB, FEEDFLSTNDE, FEEDFLSTOPX, FEEDFLSTPRD, FEEDFLSTPST, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCAL) && feedFLstCal) this->feedFLstCal = *feedFLstCal;
	if (find(this->mask, FEEDFLSTCLN) && feedFLstCln) this->feedFLstCln = *feedFLstCln;
	if (find(this->mask, FEEDFLSTEVT) && feedFLstEvt) this->feedFLstEvt = *feedFLstEvt;
	if (find(this->mask, FEEDFLSTJOB) && feedFLstJob) this->feedFLstJob = *feedFLstJob;
	if (find(this->mask, FEEDFLSTNDE) && feedFLstNde) this->feedFLstNde = *feedFLstNde;
	if (find(this->mask, FEEDFLSTOPX) && feedFLstOpx) this->feedFLstOpx = *feedFLstOpx;
	if (find(this->mask, FEEDFLSTPRD) && feedFLstPrd) this->feedFLstPrd = *feedFLstPrd;
	if (find(this->mask, FEEDFLSTPST) && feedFLstPst) this->feedFLstPst = *feedFLstPst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemNavMon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWzemNavMon::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCAL)) {feedFLstCal = src->feedFLstCal; add(FEEDFLSTCAL);};
	if (src->has(FEEDFLSTCLN)) {feedFLstCln = src->feedFLstCln; add(FEEDFLSTCLN);};
	if (src->has(FEEDFLSTEVT)) {feedFLstEvt = src->feedFLstEvt; add(FEEDFLSTEVT);};
	if (src->has(FEEDFLSTJOB)) {feedFLstJob = src->feedFLstJob; add(FEEDFLSTJOB);};
	if (src->has(FEEDFLSTNDE)) {feedFLstNde = src->feedFLstNde; add(FEEDFLSTNDE);};
	if (src->has(FEEDFLSTOPX)) {feedFLstOpx = src->feedFLstOpx; add(FEEDFLSTOPX);};
	if (src->has(FEEDFLSTPRD)) {feedFLstPrd = src->feedFLstPrd; add(FEEDFLSTPRD);};
	if (src->has(FEEDFLSTPST)) {feedFLstPst = src->feedFLstPst; add(FEEDFLSTPST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemNavMon::DpchEngData::writeJSON(
			const uint ixWzemVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWzemNavMonData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTCAL)) feedFLstCal.writeJSON(me);
	if (has(FEEDFLSTCLN)) feedFLstCln.writeJSON(me);
	if (has(FEEDFLSTEVT)) feedFLstEvt.writeJSON(me);
	if (has(FEEDFLSTJOB)) feedFLstJob.writeJSON(me);
	if (has(FEEDFLSTNDE)) feedFLstNde.writeJSON(me);
	if (has(FEEDFLSTOPX)) feedFLstOpx.writeJSON(me);
	if (has(FEEDFLSTPRD)) feedFLstPrd.writeJSON(me);
	if (has(FEEDFLSTPST)) feedFLstPst.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWzemVLocale, me);
};

void PnlWzemNavMon::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemNavMonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCAL)) feedFLstCal.writeXML(wr);
		if (has(FEEDFLSTCLN)) feedFLstCln.writeXML(wr);
		if (has(FEEDFLSTEVT)) feedFLstEvt.writeXML(wr);
		if (has(FEEDFLSTJOB)) feedFLstJob.writeXML(wr);
		if (has(FEEDFLSTNDE)) feedFLstNde.writeXML(wr);
		if (has(FEEDFLSTOPX)) feedFLstOpx.writeXML(wr);
		if (has(FEEDFLSTPRD)) feedFLstPrd.writeXML(wr);
		if (has(FEEDFLSTPST)) feedFLstPst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};
