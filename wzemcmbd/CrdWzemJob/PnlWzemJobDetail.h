/**
	* \file PnlWzemJobDetail.h
	* job handler for job PnlWzemJobDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMJOBDETAIL_H
#define PNLWZEMJOBDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemJobDetailDo PnlWzemJobDetail::VecVDo

#define ContIacWzemJobDetail PnlWzemJobDetail::ContIac
#define ContInfWzemJobDetail PnlWzemJobDetail::ContInf
#define StatAppWzemJobDetail PnlWzemJobDetail::StatApp
#define StatShrWzemJobDetail PnlWzemJobDetail::StatShr
#define TagWzemJobDetail PnlWzemJobDetail::Tag

#define DpchAppWzemJobDetailData PnlWzemJobDetail::DpchAppData
#define DpchAppWzemJobDetailDo PnlWzemJobDetail::DpchAppDo
#define DpchEngWzemJobDetailData PnlWzemJobDetail::DpchEngData

/**
	* PnlWzemJobDetail
	*/
class PnlWzemJobDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemJobDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRDVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemJobDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFJOB = 1;
		static const Sbecore::uint TXFXJR = 2;
		static const Sbecore::uint TXFSTA = 3;
		static const Sbecore::uint TXFSTO = 4;
		static const Sbecore::uint CHKCLS = 5;
		static const Sbecore::uint CHKSNC = 6;
		static const Sbecore::uint CHKDCL = 7;
		static const Sbecore::uint CHKSTM = 8;

	public:
		ContIac(const std::string& TxfJob = "", const std::string& TxfXjr = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const bool ChkCls = false, const bool ChkSnc = false, const bool ChkDcl = false, const bool ChkStm = false);

	public:
		std::string TxfJob;
		std::string TxfXjr;
		std::string TxfSta;
		std::string TxfSto;
		bool ChkCls;
		bool ChkSnc;
		bool ChkDcl;
		bool ChkStm;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemJobDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRD = 1;
		static const Sbecore::uint TXTSUP = 2;

	public:
		ContInf(const std::string& TxtPrd = "", const std::string& TxtSup = "");

	public:
		std::string TxtPrd;
		std::string TxtSup;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemJobDetail)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzemJobDetail)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRDACTIVE = 3;
		static const Sbecore::uint BUTPRDVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 5;
		static const Sbecore::uint TXFJOBACTIVE = 6;
		static const Sbecore::uint TXFXJRACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint TXTSUPACTIVE = 10;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 11;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 12;
		static const Sbecore::uint CHKCLSACTIVE = 13;
		static const Sbecore::uint CHKSNCACTIVE = 14;
		static const Sbecore::uint CHKDCLACTIVE = 15;
		static const Sbecore::uint CHKSTMACTIVE = 16;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfJobActive = true, const bool TxfXjrActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool ChkClsActive = true, const bool ChkSncActive = true, const bool ChkDclActive = true, const bool ChkStmActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfJobActive;
		bool TxfXjrActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool ChkClsActive;
		bool ChkSncActive;
		bool ChkDclActive;
		bool ChkStmActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemJobDetail)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemJobDetailData)
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
		* DpchAppDo (full: DpchAppWzemJobDetailDo)
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
		* DpchEngData (full: DpchEngWzemJobDetailData)
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
	bool evalTxfJobActive(DbsWzem* dbswzem);
	bool evalTxfXjrActive(DbsWzem* dbswzem);
	bool evalTxfStaActive(DbsWzem* dbswzem);
	bool evalTxfStoActive(DbsWzem* dbswzem);
	bool evalTxtSupActive(DbsWzem* dbswzem);
	bool evalButSupViewAvail(DbsWzem* dbswzem);
	bool evalButSupViewActive(DbsWzem* dbswzem);
	bool evalChkClsActive(DbsWzem* dbswzem);
	bool evalChkSncActive(DbsWzem* dbswzem);
	bool evalChkDclActive(DbsWzem* dbswzem);
	bool evalChkStmActive(DbsWzem* dbswzem);

public:
	PnlWzemJobDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemJobDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WzemMJob recJob;

	WzemJMJobDcol recJobJdcl;

	WzemJMJobStmgr recJobJstm;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecJob(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecJobJdcl(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecJobJstm(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButSupViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemJobJstmMod_jobEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemJobJdclMod_jobEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemJobUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemJob_supEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemJob_prdEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
