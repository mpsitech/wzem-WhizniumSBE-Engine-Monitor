/**
	* \file PnlWzemEvtDetail.h
	* job handler for job PnlWzemEvtDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMEVTDETAIL_H
#define PNLWZEMEVTDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

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
class PnlWzemEvtDetail : public JobWzem {

public:
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
	class ContIac : public Sbecore::Xmlio::Block {

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
	class ContInf : public Sbecore::Xmlio::Block {

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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemEvtDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstCluAlt = true, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzemEvtDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemEvtDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemEvtDetailData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemEvtDetailDo)
		*/
	class DpchAppDo : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzemEvtDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPTYP = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstClu = NULL, Sbecore::Xmlio::Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupTyp;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzem* dbswzem);
	bool evalButSaveActive(DbsWzem* dbswzem);
	bool evalPupTypActive(DbsWzem* dbswzem);
	bool evalTxtPrdActive(DbsWzem* dbswzem);
	bool evalButPrdViewAvail(DbsWzem* dbswzem);
	bool evalButPrdViewActive(DbsWzem* dbswzem);
	bool evalTxfStaActive(DbsWzem* dbswzem);
	bool evalLstCluActive(DbsWzem* dbswzem);
	bool evalButCluViewActive(DbsWzem* dbswzem);
	bool evalButCluClusterAvail(DbsWzem* dbswzem);
	bool evalButCluUnclusterAvail(DbsWzem* dbswzem);
	bool evalTxtCalActive(DbsWzem* dbswzem);
	bool evalButCalViewAvail(DbsWzem* dbswzem);
	bool evalButCalViewActive(DbsWzem* dbswzem);
	bool evalTxtClnActive(DbsWzem* dbswzem);
	bool evalButClnViewAvail(DbsWzem* dbswzem);
	bool evalButClnViewActive(DbsWzem* dbswzem);
	bool evalTxtJobActive(DbsWzem* dbswzem);
	bool evalButJobViewAvail(DbsWzem* dbswzem);
	bool evalButJobViewActive(DbsWzem* dbswzem);
	bool evalTxtNdeActive(DbsWzem* dbswzem);
	bool evalButNdeViewAvail(DbsWzem* dbswzem);
	bool evalButNdeViewActive(DbsWzem* dbswzem);
	bool evalTxtOpxActive(DbsWzem* dbswzem);
	bool evalButOpxViewAvail(DbsWzem* dbswzem);
	bool evalButOpxViewActive(DbsWzem* dbswzem);
	bool evalTxtPstActive(DbsWzem* dbswzem);
	bool evalButPstViewAvail(DbsWzem* dbswzem);
	bool evalButPstViewActive(DbsWzem* dbswzem);
	bool evalTxfCmdActive(DbsWzem* dbswzem);
	bool evalTxfFnmActive(DbsWzem* dbswzem);
	bool evalTxfFegActive(DbsWzem* dbswzem);
	bool evalTxfMtdActive(DbsWzem* dbswzem);
	bool evalTxfXsrActive(DbsWzem* dbswzem);
	bool evalButDchNewAvail(DbsWzem* dbswzem);
	bool evalButDchDeleteAvail(DbsWzem* dbswzem);
	bool evalTxfDchDchAvail(DbsWzem* dbswzem);
	bool evalTxfDchDchActive(DbsWzem* dbswzem);
	bool evalTxfDchMskAvail(DbsWzem* dbswzem);
	bool evalTxfDchMskActive(DbsWzem* dbswzem);
	bool evalTxfDchCntAvail(DbsWzem* dbswzem);
	bool evalTxfDchCntActive(DbsWzem* dbswzem);

public:
	PnlWzemEvtDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemEvtDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstClu;
	Sbecore::Xmlio::Feed feedFPupTyp;

	WzemMEvent recEvt;

	WzemMDpch recDch;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refreshRecEvt(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecDch(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButPrdViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButCalViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButClnViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButJobViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButNdeViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButOpxViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButPstViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButDchNewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButDchDeleteClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemEvtMod_cluEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemEvtUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemDchUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemEvt_pstEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_prdEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_opxEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_ndeEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_jobEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_dchEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_cluEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_clnEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemEvt_calEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif







