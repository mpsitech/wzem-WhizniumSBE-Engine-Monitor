/**
	* \file PnlWzemPrdDetail.h
	* job handler for job PnlWzemPrdDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPRDDETAIL_H
#define PNLWZEMPRDDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemPrdDetailDo PnlWzemPrdDetail::VecVDo

#define ContIacWzemPrdDetail PnlWzemPrdDetail::ContIac
#define StatAppWzemPrdDetail PnlWzemPrdDetail::StatApp
#define StatShrWzemPrdDetail PnlWzemPrdDetail::StatShr
#define TagWzemPrdDetail PnlWzemPrdDetail::Tag

#define DpchAppWzemPrdDetailData PnlWzemPrdDetail::DpchAppData
#define DpchAppWzemPrdDetailDo PnlWzemPrdDetail::DpchAppDo
#define DpchEngWzemPrdDetailData PnlWzemPrdDetail::DpchEngData

/**
	* PnlWzemPrdDetail
	*/
class PnlWzemPrdDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemPrdDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemPrdDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFVER = 1;
		static const Sbecore::uint TXFSTA = 2;
		static const Sbecore::uint TXFSTO = 3;

	public:
		ContIac(const std::string& TxfVer = "", const std::string& TxfSta = "", const std::string& TxfSto = "");

	public:
		std::string TxfVer;
		std::string TxfSta;
		std::string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWzemPrdDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzemPrdDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFVERACTIVE = 3;
		static const Sbecore::uint TXFSTAACTIVE = 4;
		static const Sbecore::uint TXFSTOACTIVE = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfVerActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfVerActive;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemPrdDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemPrdDetailData)
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
		* DpchAppDo (full: DpchAppWzemPrdDetailDo)
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
		* DpchEngData (full: DpchEngWzemPrdDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzem* dbswzem);
	bool evalButSaveActive(DbsWzem* dbswzem);
	bool evalTxfVerActive(DbsWzem* dbswzem);
	bool evalTxfStaActive(DbsWzem* dbswzem);
	bool evalTxfStoActive(DbsWzem* dbswzem);

public:
	PnlWzemPrdDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemPrdDetail();

public:
	ContIac contiac;
	StatShr statshr;

	WzemMPeriod recPrd;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecPrd(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemPrdUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);

};

#endif







