/**
	* \file PnlWzemEvtDetail.h
	* API code for job PnlWzemEvtDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMEVTDETAIL_H
#define PNLWZEMEVTDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemEvtDetailDo PnlWzemEvtDetail::VecVDo

#define ContIacWzemEvtDetail PnlWzemEvtDetail::ContIac
#define ContInfWzemEvtDetail PnlWzemEvtDetail::ContInf
#define StatAppWzemEvtDetail PnlWzemEvtDetail::StatApp
#define StatShrWzemEvtDetail PnlWzemEvtDetail::StatShr
#define TagWzemEvtDetail PnlWzemEvtDetail::Tag

#define DpchAppWzemEvtDetailData PnlWzemEvtDetail::DpchAppData
#define DpchAppWzemEvtDetailDo PnlWzemEvtDetail::DpchAppDo
#define DpchEngWzemEvtDetailData PnlWzemEvtDetail::DpchEngData

/**
	* PnlWzemEvtDetail
	*/
namespace PnlWzemEvtDetail {
	/**
		* VecVDo (full: VecVWzemEvtDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRDVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUVIEWCLICK = 3;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 4;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 5;
		static const Sbecore::uint BUTCALVIEWCLICK = 6;
		static const Sbecore::uint BUTCLNVIEWCLICK = 7;
		static const Sbecore::uint BUTJOBVIEWCLICK = 8;
		static const Sbecore::uint BUTNDEVIEWCLICK = 9;
		static const Sbecore::uint BUTOPXVIEWCLICK = 10;
		static const Sbecore::uint BUTPSTVIEWCLICK = 11;
		static const Sbecore::uint BUTDCHNEWCLICK = 12;
		static const Sbecore::uint BUTDCHDELETECLICK = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemEvtDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPTYP = 1;
		static const Sbecore::uint TXFSTA = 2;
		static const Sbecore::uint NUMFLSTCLU = 3;
		static const Sbecore::uint TXFCMD = 4;
		static const Sbecore::uint TXFFNM = 5;
		static const Sbecore::uint TXFFEG = 6;
		static const Sbecore::uint TXFMTD = 7;
		static const Sbecore::uint TXFXSR = 8;
		static const Sbecore::uint TXFDCHDCH = 9;
		static const Sbecore::uint TXFDCHMSK = 10;
		static const Sbecore::uint TXFDCHCNT = 11;

	public:
		ContIac(const Sbecore::uint numFPupTyp = 1, const std::string& TxfSta = "", const Sbecore::uint numFLstClu = 1, const std::string& TxfCmd = "", const std::string& TxfFnm = "", const std::string& TxfFeg = "", const std::string& TxfMtd = "", const std::string& TxfXsr = "", const std::string& TxfDchDch = "", const std::string& TxfDchMsk = "", const std::string& TxfDchCnt = "");

	public:
		Sbecore::uint numFPupTyp;
		std::string TxfSta;
		Sbecore::uint numFLstClu;
		std::string TxfCmd;
		std::string TxfFnm;
		std::string TxfFeg;
		std::string TxfMtd;
		std::string TxfXsr;
		std::string TxfDchDch;
		std::string TxfDchMsk;
		std::string TxfDchCnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemEvtDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRD = 1;
		static const Sbecore::uint TXTCLU = 2;
		static const Sbecore::uint TXTCAL = 3;
		static const Sbecore::uint TXTCLN = 4;
		static const Sbecore::uint TXTJOB = 5;
		static const Sbecore::uint TXTNDE = 6;
		static const Sbecore::uint TXTOPX = 7;
		static const Sbecore::uint TXTPST = 8;

	public:
		ContInf(const std::string& TxtPrd = "", const std::string& TxtClu = "", const std::string& TxtCal = "", const std::string& TxtCln = "", const std::string& TxtJob = "", const std::string& TxtNde = "", const std::string& TxtOpx = "", const std::string& TxtPst = "");

	public:
		std::string TxtPrd;
		std::string TxtClu;
		std::string TxtCal;
		std::string TxtCln;
		std::string TxtJob;
		std::string TxtNde;
		std::string TxtOpx;
		std::string TxtPst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemEvtDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint LSTCLUALT = 2;
		static const Sbecore::uint LSTCLUNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzemVExpstate;
		bool LstCluAlt;
		Sbecore::uint LstCluNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemEvtDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint PUPTYPACTIVE = 3;
		static const Sbecore::uint TXTPRDACTIVE = 4;
		static const Sbecore::uint BUTPRDVIEWAVAIL = 5;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 6;
		static const Sbecore::uint TXFSTAACTIVE = 7;
		static const Sbecore::uint LSTCLUACTIVE = 8;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 9;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 10;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 11;
		static const Sbecore::uint TXTCALACTIVE = 12;
		static const Sbecore::uint BUTCALVIEWAVAIL = 13;
		static const Sbecore::uint BUTCALVIEWACTIVE = 14;
		static const Sbecore::uint TXTCLNACTIVE = 15;
		static const Sbecore::uint BUTCLNVIEWAVAIL = 16;
		static const Sbecore::uint BUTCLNVIEWACTIVE = 17;
		static const Sbecore::uint TXTJOBACTIVE = 18;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 19;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 20;
		static const Sbecore::uint TXTNDEACTIVE = 21;
		static const Sbecore::uint BUTNDEVIEWAVAIL = 22;
		static const Sbecore::uint BUTNDEVIEWACTIVE = 23;
		static const Sbecore::uint TXTOPXACTIVE = 24;
		static const Sbecore::uint BUTOPXVIEWAVAIL = 25;
		static const Sbecore::uint BUTOPXVIEWACTIVE = 26;
		static const Sbecore::uint TXTPSTACTIVE = 27;
		static const Sbecore::uint BUTPSTVIEWAVAIL = 28;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 29;
		static const Sbecore::uint TXFCMDACTIVE = 30;
		static const Sbecore::uint TXFFNMACTIVE = 31;
		static const Sbecore::uint TXFFEGACTIVE = 32;
		static const Sbecore::uint TXFMTDACTIVE = 33;
		static const Sbecore::uint TXFXSRACTIVE = 34;
		static const Sbecore::uint BUTDCHNEWAVAIL = 35;
		static const Sbecore::uint BUTDCHDELETEAVAIL = 36;
		static const Sbecore::uint TXFDCHDCHAVAIL = 37;
		static const Sbecore::uint TXFDCHDCHACTIVE = 38;
		static const Sbecore::uint TXFDCHMSKAVAIL = 39;
		static const Sbecore::uint TXFDCHMSKACTIVE = 40;
		static const Sbecore::uint TXFDCHCNTAVAIL = 41;
		static const Sbecore::uint TXFDCHCNTACTIVE = 42;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool PupTypActive = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfStaActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtCalActive = true, const bool ButCalViewAvail = true, const bool ButCalViewActive = true, const bool TxtClnActive = true, const bool ButClnViewAvail = true, const bool ButClnViewActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxtNdeActive = true, const bool ButNdeViewAvail = true, const bool ButNdeViewActive = true, const bool TxtOpxActive = true, const bool ButOpxViewAvail = true, const bool ButOpxViewActive = true, const bool TxtPstActive = true, const bool ButPstViewAvail = true, const bool ButPstViewActive = true, const bool TxfCmdActive = true, const bool TxfFnmActive = true, const bool TxfFegActive = true, const bool TxfMtdActive = true, const bool TxfXsrActive = true, const bool ButDchNewAvail = true, const bool ButDchDeleteAvail = true, const bool TxfDchDchAvail = true, const bool TxfDchDchActive = true, const bool TxfDchMskAvail = true, const bool TxfDchMskActive = true, const bool TxfDchCntAvail = true, const bool TxfDchCntActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool PupTypActive;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfStaActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtCalActive;
		bool ButCalViewAvail;
		bool ButCalViewActive;
		bool TxtClnActive;
		bool ButClnViewAvail;
		bool ButClnViewActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxtNdeActive;
		bool ButNdeViewAvail;
		bool ButNdeViewActive;
		bool TxtOpxActive;
		bool ButOpxViewAvail;
		bool ButOpxViewActive;
		bool TxtPstActive;
		bool ButPstViewAvail;
		bool ButPstViewActive;
		bool TxfCmdActive;
		bool TxfFnmActive;
		bool TxfFegActive;
		bool TxfMtdActive;
		bool TxfXsrActive;
		bool ButDchNewAvail;
		bool ButDchDeleteAvail;
		bool TxfDchDchAvail;
		bool TxfDchDchActive;
		bool TxfDchMskAvail;
		bool TxfDchMskActive;
		bool TxfDchCntAvail;
		bool TxfDchCntActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemEvtDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTTYP = 2;
		static const Sbecore::uint CPTPRD = 3;
		static const Sbecore::uint CPTSTA = 4;
		static const Sbecore::uint CPTCLU = 5;
		static const Sbecore::uint CPTCAL = 6;
		static const Sbecore::uint CPTCLN = 7;
		static const Sbecore::uint CPTJOB = 8;
		static const Sbecore::uint CPTNDE = 9;
		static const Sbecore::uint CPTOPX = 10;
		static const Sbecore::uint CPTPST = 11;
		static const Sbecore::uint CPTCMD = 12;
		static const Sbecore::uint CPTFNM = 13;
		static const Sbecore::uint CPTFEG = 14;
		static const Sbecore::uint CPTMTD = 15;
		static const Sbecore::uint CPTXSR = 16;
		static const Sbecore::uint HDGDCH = 17;
		static const Sbecore::uint CPTDCHDCH = 18;
		static const Sbecore::uint CPTDCHMSK = 19;
		static const Sbecore::uint CPTDCHCNT = 20;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptTyp = "", const std::string& CptPrd = "", const std::string& CptSta = "", const std::string& CptClu = "", const std::string& CptCal = "", const std::string& CptCln = "", const std::string& CptJob = "", const std::string& CptNde = "", const std::string& CptOpx = "", const std::string& CptPst = "", const std::string& CptCmd = "", const std::string& CptFnm = "", const std::string& CptFeg = "", const std::string& CptMtd = "", const std::string& CptXsr = "", const std::string& HdgDch = "", const std::string& CptDchDch = "", const std::string& CptDchMsk = "", const std::string& CptDchCnt = "");

	public:
		std::string Cpt;
		std::string CptTyp;
		std::string CptPrd;
		std::string CptSta;
		std::string CptClu;
		std::string CptCal;
		std::string CptCln;
		std::string CptJob;
		std::string CptNde;
		std::string CptOpx;
		std::string CptPst;
		std::string CptCmd;
		std::string CptFnm;
		std::string CptFeg;
		std::string CptMtd;
		std::string CptXsr;
		std::string HdgDch;
		std::string CptDchDch;
		std::string CptDchMsk;
		std::string CptDchCnt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemEvtDetailData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzemEvtDetailDo)
		*/
	class DpchAppDo : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWzemEvtDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstClu;
		Sbecore::Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
