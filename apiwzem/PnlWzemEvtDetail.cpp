/**
	* \file PnlWzemEvtDetail.cpp
	* API code for job PnlWzemEvtDetail (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "PnlWzemEvtDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzemEvtDetail::VecVDo
 ******************************************************************************/

uint PnlWzemEvtDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprdviewclick") return BUTPRDVIEWCLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butcalviewclick") return BUTCALVIEWCLICK;
	if (s == "butclnviewclick") return BUTCLNVIEWCLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butndeviewclick") return BUTNDEVIEWCLICK;
	if (s == "butopxviewclick") return BUTOPXVIEWCLICK;
	if (s == "butpstviewclick") return BUTPSTVIEWCLICK;
	if (s == "butdchnewclick") return BUTDCHNEWCLICK;
	if (s == "butdchdeleteclick") return BUTDCHDELETECLICK;

	return(0);
};

string PnlWzemEvtDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRDVIEWCLICK) return("ButPrdViewClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTCALVIEWCLICK) return("ButCalViewClick");
	if (ix == BUTCLNVIEWCLICK) return("ButClnViewClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTNDEVIEWCLICK) return("ButNdeViewClick");
	if (ix == BUTOPXVIEWCLICK) return("ButOpxViewClick");
	if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
	if (ix == BUTDCHNEWCLICK) return("ButDchNewClick");
	if (ix == BUTDCHDELETECLICK) return("ButDchDeleteClick");

	return("");
};

/******************************************************************************
 class PnlWzemEvtDetail::ContIac
 ******************************************************************************/

PnlWzemEvtDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const string& TxfSta
			, const uint numFLstClu
			, const string& TxfCmd
			, const string& TxfFnm
			, const string& TxfFeg
			, const string& TxfMtd
			, const string& TxfXsr
			, const string& TxfDchDch
			, const string& TxfDchMsk
			, const string& TxfDchCnt
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->TxfSta = TxfSta;
	this->numFLstClu = numFLstClu;
	this->TxfCmd = TxfCmd;
	this->TxfFnm = TxfFnm;
	this->TxfFeg = TxfFeg;
	this->TxfMtd = TxfMtd;
	this->TxfXsr = TxfXsr;
	this->TxfDchDch = TxfDchDch;
	this->TxfDchMsk = TxfDchMsk;
	this->TxfDchCnt = TxfDchCnt;

	mask = {NUMFPUPTYP, TXFSTA, NUMFLSTCLU, TXFCMD, TXFFNM, TXFFEG, TXFMTD, TXFXSR, TXFDCHDCH, TXFDCHMSK, TXFDCHCNT};
};

bool PnlWzemEvtDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWzemEvtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWzemEvtDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmd", TxfCmd)) add(TXFCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFeg", TxfFeg)) add(TXFFEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMtd", TxfMtd)) add(TXFMTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXsr", TxfXsr)) add(TXFXSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDchDch", TxfDchDch)) add(TXFDCHDCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDchMsk", TxfDchMsk)) add(TXFDCHMSK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDchCnt", TxfDchCnt)) add(TXFDCHCNT);
	};

	return basefound;
};

void PnlWzemEvtDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWzemEvtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWzemEvtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfCmd", TxfCmd);
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeStringAttr(wr, itemtag, "sref", "TxfFeg", TxfFeg);
		writeStringAttr(wr, itemtag, "sref", "TxfMtd", TxfMtd);
		writeStringAttr(wr, itemtag, "sref", "TxfXsr", TxfXsr);
		writeStringAttr(wr, itemtag, "sref", "TxfDchDch", TxfDchDch);
		writeStringAttr(wr, itemtag, "sref", "TxfDchMsk", TxfDchMsk);
		writeStringAttr(wr, itemtag, "sref", "TxfDchCnt", TxfDchCnt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWzemEvtDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfCmd == comp->TxfCmd) insert(items, TXFCMD);
	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (TxfFeg == comp->TxfFeg) insert(items, TXFFEG);
	if (TxfMtd == comp->TxfMtd) insert(items, TXFMTD);
	if (TxfXsr == comp->TxfXsr) insert(items, TXFXSR);
	if (TxfDchDch == comp->TxfDchDch) insert(items, TXFDCHDCH);
	if (TxfDchMsk == comp->TxfDchMsk) insert(items, TXFDCHMSK);
	if (TxfDchCnt == comp->TxfDchCnt) insert(items, TXFDCHCNT);

	return(items);
};

set<uint> PnlWzemEvtDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFSTA, NUMFLSTCLU, TXFCMD, TXFFNM, TXFFEG, TXFMTD, TXFXSR, TXFDCHDCH, TXFDCHMSK, TXFDCHCNT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemEvtDetail::ContInf
 ******************************************************************************/

PnlWzemEvtDetail::ContInf::ContInf(
			const string& TxtPrd
			, const string& TxtClu
			, const string& TxtCal
			, const string& TxtCln
			, const string& TxtJob
			, const string& TxtNde
			, const string& TxtOpx
			, const string& TxtPst
		) :
			Block()
		{
	this->TxtPrd = TxtPrd;
	this->TxtClu = TxtClu;
	this->TxtCal = TxtCal;
	this->TxtCln = TxtCln;
	this->TxtJob = TxtJob;
	this->TxtNde = TxtNde;
	this->TxtOpx = TxtOpx;
	this->TxtPst = TxtPst;

	mask = {TXTPRD, TXTCLU, TXTCAL, TXTCLN, TXTJOB, TXTNDE, TXTOPX, TXTPST};
};

bool PnlWzemEvtDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzemEvtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzemEvtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrd", TxtPrd)) add(TXTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCal", TxtCal)) add(TXTCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCln", TxtCln)) add(TXTCLN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtJob", TxtJob)) add(TXTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtNde", TxtNde)) add(TXTNDE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOpx", TxtOpx)) add(TXTOPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPst", TxtPst)) add(TXTPST);
	};

	return basefound;
};

set<uint> PnlWzemEvtDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrd == comp->TxtPrd) insert(items, TXTPRD);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtCal == comp->TxtCal) insert(items, TXTCAL);
	if (TxtCln == comp->TxtCln) insert(items, TXTCLN);
	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);
	if (TxtNde == comp->TxtNde) insert(items, TXTNDE);
	if (TxtOpx == comp->TxtOpx) insert(items, TXTOPX);
	if (TxtPst == comp->TxtPst) insert(items, TXTPST);

	return(items);
};

set<uint> PnlWzemEvtDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRD, TXTCLU, TXTCAL, TXTCLN, TXTJOB, TXTNDE, TXTOPX, TXTPST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemEvtDetail::StatApp
 ******************************************************************************/

PnlWzemEvtDetail::StatApp::StatApp(
			const uint ixWzemVExpstate
			, const bool LstCluAlt
			, const uint LstCluNumFirstdisp
		) :
			Block()
		{
	this->ixWzemVExpstate = ixWzemVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;

	mask = {IXWZEMVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP};
};

bool PnlWzemEvtDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzemVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzemEvtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzemEvtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzemVExpstate", srefIxWzemVExpstate)) {
			ixWzemVExpstate = VecWzemVExpstate::getIx(srefIxWzemVExpstate);
			add(IXWZEMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWzemEvtDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzemVExpstate == comp->ixWzemVExpstate) insert(items, IXWZEMVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWzemEvtDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZEMVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemEvtDetail::StatShr
 ******************************************************************************/

PnlWzemEvtDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool PupTypActive
			, const bool TxtPrdActive
			, const bool ButPrdViewAvail
			, const bool ButPrdViewActive
			, const bool TxfStaActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtCalActive
			, const bool ButCalViewAvail
			, const bool ButCalViewActive
			, const bool TxtClnActive
			, const bool ButClnViewAvail
			, const bool ButClnViewActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxtNdeActive
			, const bool ButNdeViewAvail
			, const bool ButNdeViewActive
			, const bool TxtOpxActive
			, const bool ButOpxViewAvail
			, const bool ButOpxViewActive
			, const bool TxtPstActive
			, const bool ButPstViewAvail
			, const bool ButPstViewActive
			, const bool TxfCmdActive
			, const bool TxfFnmActive
			, const bool TxfFegActive
			, const bool TxfMtdActive
			, const bool TxfXsrActive
			, const bool ButDchNewAvail
			, const bool ButDchDeleteAvail
			, const bool TxfDchDchAvail
			, const bool TxfDchDchActive
			, const bool TxfDchMskAvail
			, const bool TxfDchMskActive
			, const bool TxfDchCntAvail
			, const bool TxfDchCntActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->PupTypActive = PupTypActive;
	this->TxtPrdActive = TxtPrdActive;
	this->ButPrdViewAvail = ButPrdViewAvail;
	this->ButPrdViewActive = ButPrdViewActive;
	this->TxfStaActive = TxfStaActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtCalActive = TxtCalActive;
	this->ButCalViewAvail = ButCalViewAvail;
	this->ButCalViewActive = ButCalViewActive;
	this->TxtClnActive = TxtClnActive;
	this->ButClnViewAvail = ButClnViewAvail;
	this->ButClnViewActive = ButClnViewActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxtNdeActive = TxtNdeActive;
	this->ButNdeViewAvail = ButNdeViewAvail;
	this->ButNdeViewActive = ButNdeViewActive;
	this->TxtOpxActive = TxtOpxActive;
	this->ButOpxViewAvail = ButOpxViewAvail;
	this->ButOpxViewActive = ButOpxViewActive;
	this->TxtPstActive = TxtPstActive;
	this->ButPstViewAvail = ButPstViewAvail;
	this->ButPstViewActive = ButPstViewActive;
	this->TxfCmdActive = TxfCmdActive;
	this->TxfFnmActive = TxfFnmActive;
	this->TxfFegActive = TxfFegActive;
	this->TxfMtdActive = TxfMtdActive;
	this->TxfXsrActive = TxfXsrActive;
	this->ButDchNewAvail = ButDchNewAvail;
	this->ButDchDeleteAvail = ButDchDeleteAvail;
	this->TxfDchDchAvail = TxfDchDchAvail;
	this->TxfDchDchActive = TxfDchDchActive;
	this->TxfDchMskAvail = TxfDchMskAvail;
	this->TxfDchMskActive = TxfDchMskActive;
	this->TxfDchCntAvail = TxfDchCntAvail;
	this->TxfDchCntActive = TxfDchCntActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, PUPTYPACTIVE, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFSTAACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTCALACTIVE, BUTCALVIEWAVAIL, BUTCALVIEWACTIVE, TXTCLNACTIVE, BUTCLNVIEWAVAIL, BUTCLNVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXTNDEACTIVE, BUTNDEVIEWAVAIL, BUTNDEVIEWACTIVE, TXTOPXACTIVE, BUTOPXVIEWAVAIL, BUTOPXVIEWACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXFCMDACTIVE, TXFFNMACTIVE, TXFFEGACTIVE, TXFMTDACTIVE, TXFXSRACTIVE, BUTDCHNEWAVAIL, BUTDCHDELETEAVAIL, TXFDCHDCHAVAIL, TXFDCHDCHACTIVE, TXFDCHMSKAVAIL, TXFDCHMSKACTIVE, TXFDCHCNTAVAIL, TXFDCHCNTACTIVE};
};

bool PnlWzemEvtDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzemEvtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzemEvtDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrdActive", TxtPrdActive)) add(TXTPRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewAvail", ButPrdViewAvail)) add(BUTPRDVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrdViewActive", ButPrdViewActive)) add(BUTPRDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCalActive", TxtCalActive)) add(TXTCALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCalViewAvail", ButCalViewAvail)) add(BUTCALVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCalViewActive", ButCalViewActive)) add(BUTCALVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtClnActive", TxtClnActive)) add(TXTCLNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClnViewAvail", ButClnViewAvail)) add(BUTCLNVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClnViewActive", ButClnViewActive)) add(BUTCLNVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtJobActive", TxtJobActive)) add(TXTJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", ButJobViewAvail)) add(BUTJOBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtNdeActive", TxtNdeActive)) add(TXTNDEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNdeViewAvail", ButNdeViewAvail)) add(BUTNDEVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNdeViewActive", ButNdeViewActive)) add(BUTNDEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtOpxActive", TxtOpxActive)) add(TXTOPXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpxViewAvail", ButOpxViewAvail)) add(BUTOPXVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpxViewActive", ButOpxViewActive)) add(BUTOPXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstActive", TxtPstActive)) add(TXTPSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstViewAvail", ButPstViewAvail)) add(BUTPSTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstViewActive", ButPstViewActive)) add(BUTPSTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmdActive", TxfCmdActive)) add(TXFCMDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFnmActive", TxfFnmActive)) add(TXFFNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFegActive", TxfFegActive)) add(TXFFEGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMtdActive", TxfMtdActive)) add(TXFMTDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXsrActive", TxfXsrActive)) add(TXFXSRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDchNewAvail", ButDchNewAvail)) add(BUTDCHNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDchDeleteAvail", ButDchDeleteAvail)) add(BUTDCHDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDchDchAvail", TxfDchDchAvail)) add(TXFDCHDCHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDchDchActive", TxfDchDchActive)) add(TXFDCHDCHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDchMskAvail", TxfDchMskAvail)) add(TXFDCHMSKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDchMskActive", TxfDchMskActive)) add(TXFDCHMSKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDchCntAvail", TxfDchCntAvail)) add(TXFDCHCNTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDchCntActive", TxfDchCntActive)) add(TXFDCHCNTACTIVE);
	};

	return basefound;
};

set<uint> PnlWzemEvtDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtPrdActive == comp->TxtPrdActive) insert(items, TXTPRDACTIVE);
	if (ButPrdViewAvail == comp->ButPrdViewAvail) insert(items, BUTPRDVIEWAVAIL);
	if (ButPrdViewActive == comp->ButPrdViewActive) insert(items, BUTPRDVIEWACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtCalActive == comp->TxtCalActive) insert(items, TXTCALACTIVE);
	if (ButCalViewAvail == comp->ButCalViewAvail) insert(items, BUTCALVIEWAVAIL);
	if (ButCalViewActive == comp->ButCalViewActive) insert(items, BUTCALVIEWACTIVE);
	if (TxtClnActive == comp->TxtClnActive) insert(items, TXTCLNACTIVE);
	if (ButClnViewAvail == comp->ButClnViewAvail) insert(items, BUTCLNVIEWAVAIL);
	if (ButClnViewActive == comp->ButClnViewActive) insert(items, BUTCLNVIEWACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxtNdeActive == comp->TxtNdeActive) insert(items, TXTNDEACTIVE);
	if (ButNdeViewAvail == comp->ButNdeViewAvail) insert(items, BUTNDEVIEWAVAIL);
	if (ButNdeViewActive == comp->ButNdeViewActive) insert(items, BUTNDEVIEWACTIVE);
	if (TxtOpxActive == comp->TxtOpxActive) insert(items, TXTOPXACTIVE);
	if (ButOpxViewAvail == comp->ButOpxViewAvail) insert(items, BUTOPXVIEWAVAIL);
	if (ButOpxViewActive == comp->ButOpxViewActive) insert(items, BUTOPXVIEWACTIVE);
	if (TxtPstActive == comp->TxtPstActive) insert(items, TXTPSTACTIVE);
	if (ButPstViewAvail == comp->ButPstViewAvail) insert(items, BUTPSTVIEWAVAIL);
	if (ButPstViewActive == comp->ButPstViewActive) insert(items, BUTPSTVIEWACTIVE);
	if (TxfCmdActive == comp->TxfCmdActive) insert(items, TXFCMDACTIVE);
	if (TxfFnmActive == comp->TxfFnmActive) insert(items, TXFFNMACTIVE);
	if (TxfFegActive == comp->TxfFegActive) insert(items, TXFFEGACTIVE);
	if (TxfMtdActive == comp->TxfMtdActive) insert(items, TXFMTDACTIVE);
	if (TxfXsrActive == comp->TxfXsrActive) insert(items, TXFXSRACTIVE);
	if (ButDchNewAvail == comp->ButDchNewAvail) insert(items, BUTDCHNEWAVAIL);
	if (ButDchDeleteAvail == comp->ButDchDeleteAvail) insert(items, BUTDCHDELETEAVAIL);
	if (TxfDchDchAvail == comp->TxfDchDchAvail) insert(items, TXFDCHDCHAVAIL);
	if (TxfDchDchActive == comp->TxfDchDchActive) insert(items, TXFDCHDCHACTIVE);
	if (TxfDchMskAvail == comp->TxfDchMskAvail) insert(items, TXFDCHMSKAVAIL);
	if (TxfDchMskActive == comp->TxfDchMskActive) insert(items, TXFDCHMSKACTIVE);
	if (TxfDchCntAvail == comp->TxfDchCntAvail) insert(items, TXFDCHCNTAVAIL);
	if (TxfDchCntActive == comp->TxfDchCntActive) insert(items, TXFDCHCNTACTIVE);

	return(items);
};

set<uint> PnlWzemEvtDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, PUPTYPACTIVE, TXTPRDACTIVE, BUTPRDVIEWAVAIL, BUTPRDVIEWACTIVE, TXFSTAACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTCALACTIVE, BUTCALVIEWAVAIL, BUTCALVIEWACTIVE, TXTCLNACTIVE, BUTCLNVIEWAVAIL, BUTCLNVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXTNDEACTIVE, BUTNDEVIEWAVAIL, BUTNDEVIEWACTIVE, TXTOPXACTIVE, BUTOPXVIEWAVAIL, BUTOPXVIEWACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXFCMDACTIVE, TXFFNMACTIVE, TXFFEGACTIVE, TXFMTDACTIVE, TXFXSRACTIVE, BUTDCHNEWAVAIL, BUTDCHDELETEAVAIL, TXFDCHDCHAVAIL, TXFDCHDCHACTIVE, TXFDCHMSKAVAIL, TXFDCHMSKACTIVE, TXFDCHCNTAVAIL, TXFDCHCNTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzemEvtDetail::Tag
 ******************************************************************************/

PnlWzemEvtDetail::Tag::Tag(
			const string& Cpt
			, const string& CptTyp
			, const string& CptPrd
			, const string& CptSta
			, const string& CptClu
			, const string& CptCal
			, const string& CptCln
			, const string& CptJob
			, const string& CptNde
			, const string& CptOpx
			, const string& CptPst
			, const string& CptCmd
			, const string& CptFnm
			, const string& CptFeg
			, const string& CptMtd
			, const string& CptXsr
			, const string& HdgDch
			, const string& CptDchDch
			, const string& CptDchMsk
			, const string& CptDchCnt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptTyp = CptTyp;
	this->CptPrd = CptPrd;
	this->CptSta = CptSta;
	this->CptClu = CptClu;
	this->CptCal = CptCal;
	this->CptCln = CptCln;
	this->CptJob = CptJob;
	this->CptNde = CptNde;
	this->CptOpx = CptOpx;
	this->CptPst = CptPst;
	this->CptCmd = CptCmd;
	this->CptFnm = CptFnm;
	this->CptFeg = CptFeg;
	this->CptMtd = CptMtd;
	this->CptXsr = CptXsr;
	this->HdgDch = HdgDch;
	this->CptDchDch = CptDchDch;
	this->CptDchMsk = CptDchMsk;
	this->CptDchCnt = CptDchCnt;

	mask = {CPT, CPTTYP, CPTPRD, CPTSTA, CPTCLU, CPTCAL, CPTCLN, CPTJOB, CPTNDE, CPTOPX, CPTPST, CPTCMD, CPTFNM, CPTFEG, CPTMTD, CPTXSR, HDGDCH, CPTDCHDCH, CPTDCHMSK, CPTDCHCNT};
};

bool PnlWzemEvtDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzemEvtDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzemEvtDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrd", CptPrd)) add(CPTPRD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCal", CptCal)) add(CPTCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCln", CptCln)) add(CPTCLN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptNde", CptNde)) add(CPTNDE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpx", CptOpx)) add(CPTOPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPst", CptPst)) add(CPTPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmd", CptCmd)) add(CPTCMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnm", CptFnm)) add(CPTFNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFeg", CptFeg)) add(CPTFEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMtd", CptMtd)) add(CPTMTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXsr", CptXsr)) add(CPTXSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgDch", HdgDch)) add(HDGDCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDchDch", CptDchDch)) add(CPTDCHDCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDchMsk", CptDchMsk)) add(CPTDCHMSK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDchCnt", CptDchCnt)) add(CPTDCHCNT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzemEvtDetail::DpchAppData
 ******************************************************************************/

PnlWzemEvtDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMEVTDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWzemEvtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemEvtDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemEvtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemEvtDetail::DpchAppDo
 ******************************************************************************/

PnlWzemEvtDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMEVTDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzemEvtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemEvtDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzemEvtDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemEvtDetail::DpchEngData
 ******************************************************************************/

PnlWzemEvtDetail::DpchEngData::DpchEngData() :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMEVTDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWzemEvtDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemEvtDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzemEvtDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

