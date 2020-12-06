/**
	* \file PnlWzemEvtDetail_blks.cpp
	* job handler for job PnlWzemEvtDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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

void PnlWzemEvtDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemEvtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWzemEvtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrd", TxtPrd);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtCal", TxtCal);
		writeStringAttr(wr, itemtag, "sref", "TxtCln", TxtCln);
		writeStringAttr(wr, itemtag, "sref", "TxtJob", TxtJob);
		writeStringAttr(wr, itemtag, "sref", "TxtNde", TxtNde);
		writeStringAttr(wr, itemtag, "sref", "TxtOpx", TxtOpx);
		writeStringAttr(wr, itemtag, "sref", "TxtPst", TxtPst);
	xmlTextWriterEndElement(wr);
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

void PnlWzemEvtDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWzemVExpstate
			, const bool LstCluAlt
			, const uint LstCluNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWzemEvtDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWzemEvtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWzemVExpstate", VecWzemVExpstate::getSref(ixWzemVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWzemEvtDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWzemEvtDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWzemEvtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrdActive", TxtPrdActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrdViewAvail", ButPrdViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrdViewActive", ButPrdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCalActive", TxtCalActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCalViewAvail", ButCalViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCalViewActive", ButCalViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtClnActive", TxtClnActive);
		writeBoolAttr(wr, itemtag, "sref", "ButClnViewAvail", ButClnViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButClnViewActive", ButClnViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtJobActive", TxtJobActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewAvail", ButJobViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtNdeActive", TxtNdeActive);
		writeBoolAttr(wr, itemtag, "sref", "ButNdeViewAvail", ButNdeViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButNdeViewActive", ButNdeViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtOpxActive", TxtOpxActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOpxViewAvail", ButOpxViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOpxViewActive", ButOpxViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstActive", TxtPstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewAvail", ButPstViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewActive", ButPstViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmdActive", TxfCmdActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFnmActive", TxfFnmActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFegActive", TxfFegActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMtdActive", TxfMtdActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXsrActive", TxfXsrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDchNewAvail", ButDchNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDchDeleteAvail", ButDchDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfDchDchAvail", TxfDchDchAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfDchDchActive", TxfDchDchActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDchMskAvail", TxfDchMskAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfDchMskActive", TxfDchMskActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDchCntAvail", TxfDchCntAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfDchCntActive", TxfDchCntActive);
	xmlTextWriterEndElement(wr);
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

void PnlWzemEvtDetail::Tag::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWzemEvtDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWzemEvtDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptPrd", "monitoring period");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "time stamp");
			writeStringAttr(wr, itemtag, "sref", "CptCal", "call");
			writeStringAttr(wr, itemtag, "sref", "CptCln", "call listener");
			writeStringAttr(wr, itemtag, "sref", "CptJob", "job");
			writeStringAttr(wr, itemtag, "sref", "CptNde", "node");
			writeStringAttr(wr, itemtag, "sref", "CptOpx", "operation");
			writeStringAttr(wr, itemtag, "sref", "CptPst", "presetting");
			writeStringAttr(wr, itemtag, "sref", "CptCmd", "command");
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "file name");
			writeStringAttr(wr, itemtag, "sref", "CptFeg", "feature group");
			writeStringAttr(wr, itemtag, "sref", "CptMtd", "method");
			writeStringAttr(wr, itemtag, "sref", "CptXsr", "string reference");
			writeStringAttr(wr, itemtag, "sref", "HdgDch", "Dispatch");
			writeStringAttr(wr, itemtag, "sref", "CptDchDch", "type");
			writeStringAttr(wr, itemtag, "sref", "CptDchMsk", "mask");
			writeStringAttr(wr, itemtag, "sref", "CptDchCnt", "content");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWzemVTag::getTitle(VecWzemVTag::DETAIL, ixWzemVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWzemVTag::getTitle(VecWzemVTag::CLUST, ixWzemVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzemEvtDetail::DpchAppData
 ******************************************************************************/

PnlWzemEvtDetail::DpchAppData::DpchAppData() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMEVTDETAILDATA)
		{
};

string PnlWzemEvtDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemEvtDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemEvtDetailData");
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
 class PnlWzemEvtDetail::DpchAppDo
 ******************************************************************************/

PnlWzemEvtDetail::DpchAppDo::DpchAppDo() :
			DpchAppWzem(VecWzemVDpch::DPCHAPPWZEMEVTDETAILDO)
		{
	ixVDo = 0;
};

string PnlWzemEvtDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzemEvtDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWzemEvtDetailDo");
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
 class PnlWzemEvtDetail::DpchEngData
 ******************************************************************************/

PnlWzemEvtDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWzem(VecWzemVDpch::DPCHENGWZEMEVTDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWzemEvtDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWzemEvtDetail::DpchEngData::merge(
			DpchEngWzem* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWzemEvtDetail::DpchEngData::writeXML(
			const uint ixWzemVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWzemEvtDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWzemVLocale, wr);
	xmlTextWriterEndElement(wr);
};
