/**
	* \file PnlWzemNdeDetail.h
	* job handler for job PnlWzemNdeDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNDEDETAIL_H
#define PNLWZEMNDEDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemNdeDetailDo PnlWzemNdeDetail::VecVDo

#define ContIacWzemNdeDetail PnlWzemNdeDetail::ContIac
#define ContInfWzemNdeDetail PnlWzemNdeDetail::ContInf
#define StatAppWzemNdeDetail PnlWzemNdeDetail::StatApp
#define StatShrWzemNdeDetail PnlWzemNdeDetail::StatShr
#define TagWzemNdeDetail PnlWzemNdeDetail::Tag

#define DpchAppWzemNdeDetailData PnlWzemNdeDetail::DpchAppData
#define DpchAppWzemNdeDetailDo PnlWzemNdeDetail::DpchAppDo
#define DpchEngWzemNdeDetailData PnlWzemNdeDetail::DpchEngData

/**
	* PnlWzemNdeDetail
	*/
class PnlWzemNdeDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemNdeDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRDVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemNdeDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFXNR = 1;
		static const Sbecore::uint TXFIP = 2;
		static const Sbecore::uint TXFSTA = 3;
		static const Sbecore::uint TXFSTO = 4;
		static const Sbecore::uint TXFPRT = 5;
		static const Sbecore::uint TXFORN = 6;

	public:
		ContIac(const std::string& TxfXnr = "", const std::string& TxfIp = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfPrt = "", const std::string& TxfOrn = "");

	public:
		std::string TxfXnr;
		std::string TxfIp;
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfPrt;
		std::string TxfOrn;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemNdeDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRD = 1;

	public:
		ContInf(const std::string& TxtPrd = "");

	public:
		std::string TxtPrd;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemNdeDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzemNdeDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRDACTIVE = 3;
		static const Sbecore::uint BUTPRDVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 5;
		static const Sbecore::uint TXFXNRACTIVE = 6;
		static const Sbecore::uint TXFIPACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint TXFPRTACTIVE = 10;
		static const Sbecore::uint TXFORNACTIVE = 11;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfXnrActive = true, const bool TxfIpActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfPrtActive = true, const bool TxfOrnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfXnrActive;
		bool TxfIpActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfPrtActive;
		bool TxfOrnActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemNdeDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemNdeDetailData)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNdeDetailDo)
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

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzemNdeDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzem* dbswzem);
	bool evalButSaveActive(DbsWzem* dbswzem);
	bool evalTxtPrdActive(DbsWzem* dbswzem);
	bool evalButPrdViewAvail(DbsWzem* dbswzem);
	bool evalButPrdViewActive(DbsWzem* dbswzem);
	bool evalTxfXnrActive(DbsWzem* dbswzem);
	bool evalTxfIpActive(DbsWzem* dbswzem);
	bool evalTxfStaActive(DbsWzem* dbswzem);
	bool evalTxfStoActive(DbsWzem* dbswzem);
	bool evalTxfPrtActive(DbsWzem* dbswzem);
	bool evalTxfOrnActive(DbsWzem* dbswzem);

public:
	PnlWzemNdeDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemNdeDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WzemMNode recNde;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecNde(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

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

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemNdeUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemNde_prdEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
