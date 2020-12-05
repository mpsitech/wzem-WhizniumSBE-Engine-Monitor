/**
	* \file PnlWzemPstDetail.h
	* job handler for job PnlWzemPstDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPSTDETAIL_H
#define PNLWZEMPSTDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemPstDetailDo PnlWzemPstDetail::VecVDo

#define ContIacWzemPstDetail PnlWzemPstDetail::ContIac
#define ContInfWzemPstDetail PnlWzemPstDetail::ContInf
#define StatAppWzemPstDetail PnlWzemPstDetail::StatApp
#define StatShrWzemPstDetail PnlWzemPstDetail::StatShr
#define TagWzemPstDetail PnlWzemPstDetail::Tag

#define DpchAppWzemPstDetailData PnlWzemPstDetail::DpchAppData
#define DpchAppWzemPstDetailDo PnlWzemPstDetail::DpchAppDo
#define DpchEngWzemPstDetailData PnlWzemPstDetail::DpchEngData

/**
	* PnlWzemPstDetail
	*/
class PnlWzemPstDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemPstDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemPstDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFPST = 1;
		static const Sbecore::uint TXFSTA = 2;
		static const Sbecore::uint TXFSTO = 3;
		static const Sbecore::uint TXFARG = 4;

	public:
		ContIac(const std::string& TxfPst = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfArg = "");

	public:
		std::string TxfPst;
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfArg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemPstDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTJOB = 1;

	public:
		ContInf(const std::string& TxtJob = "");

	public:
		std::string TxtJob;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemPstDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzemPstDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTJOBACTIVE = 3;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 4;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 5;
		static const Sbecore::uint TXFPSTACTIVE = 6;
		static const Sbecore::uint TXFSTAACTIVE = 7;
		static const Sbecore::uint TXFSTOACTIVE = 8;
		static const Sbecore::uint TXFARGACTIVE = 9;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfPstActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfArgActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfPstActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfArgActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemPstDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemPstDetailData)
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
		* DpchAppDo (full: DpchAppWzemPstDetailDo)
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
		* DpchEngData (full: DpchEngWzemPstDetailData)
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

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzem* dbswzem);
	bool evalButSaveActive(DbsWzem* dbswzem);
	bool evalTxtJobActive(DbsWzem* dbswzem);
	bool evalButJobViewAvail(DbsWzem* dbswzem);
	bool evalButJobViewActive(DbsWzem* dbswzem);
	bool evalTxfPstActive(DbsWzem* dbswzem);
	bool evalTxfStaActive(DbsWzem* dbswzem);
	bool evalTxfStoActive(DbsWzem* dbswzem);
	bool evalTxfArgActive(DbsWzem* dbswzem);

public:
	PnlWzemPstDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemPstDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WzemMPreset recPst;

	WzemJMPresetArg recPstJarg;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecPst(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecPstJarg(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButJobViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemPstJargMod_pstEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemPstUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemPst_jobEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

