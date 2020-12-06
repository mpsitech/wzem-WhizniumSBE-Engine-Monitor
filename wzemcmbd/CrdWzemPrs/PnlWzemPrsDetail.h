/**
	* \file PnlWzemPrsDetail.h
	* job handler for job PnlWzemPrsDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPRSDETAIL_H
#define PNLWZEMPRSDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemPrsDetailDo PnlWzemPrsDetail::VecVDo

#define ContIacWzemPrsDetail PnlWzemPrsDetail::ContIac
#define ContInfWzemPrsDetail PnlWzemPrsDetail::ContInf
#define StatAppWzemPrsDetail PnlWzemPrsDetail::StatApp
#define StatShrWzemPrsDetail PnlWzemPrsDetail::StatShr
#define TagWzemPrsDetail PnlWzemPrsDetail::Tag

#define DpchAppWzemPrsDetailData PnlWzemPrsDetail::DpchAppData
#define DpchAppWzemPrsDetailDo PnlWzemPrsDetail::DpchAppDo
#define DpchEngWzemPrsDetailData PnlWzemPrsDetail::DpchEngData

/**
	* PnlWzemPrsDetail
	*/
class PnlWzemPrsDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemPrsDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFNM = 2;
		static const Sbecore::uint NUMFPUPJ = 3;
		static const Sbecore::uint NUMSFLSTDRV = 4;
		static const Sbecore::uint NUMFPUPSEX = 5;
		static const Sbecore::uint TXFTEL = 6;
		static const Sbecore::uint TXFEML = 7;
		static const Sbecore::uint TXFSAL = 8;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFnm = "", const Sbecore::uint numFPupJ = 1, const std::vector<Sbecore::uint>& numsFLstDrv = {}, const Sbecore::uint numFPupSex = 1, const std::string& TxfTel = "", const std::string& TxfEml = "", const std::string& TxfSal = "");

	public:
		std::string TxfTit;
		std::string TxfFnm;
		Sbecore::uint numFPupJ;
		std::vector<Sbecore::uint> numsFLstDrv;
		Sbecore::uint numFPupSex;
		std::string TxfTel;
		std::string TxfEml;
		std::string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemPrsDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTLNM = 1;
		static const Sbecore::uint TXTDRV = 2;

	public:
		ContInf(const std::string& TxtLnm = "", const std::string& TxtDrv = "");

	public:
		std::string TxtLnm;
		std::string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemPrsDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstDrvAlt = true, const Sbecore::uint LstDrvNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzemPrsDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFTITACTIVE = 3;
		static const Sbecore::uint TXFFNMACTIVE = 4;
		static const Sbecore::uint PUPJACTIVE = 5;
		static const Sbecore::uint BUTJEDITAVAIL = 6;
		static const Sbecore::uint TXTLNMACTIVE = 7;
		static const Sbecore::uint LSTDRVACTIVE = 8;
		static const Sbecore::uint PUPSEXACTIVE = 9;
		static const Sbecore::uint TXFTELACTIVE = 10;
		static const Sbecore::uint TXFEMLACTIVE = 11;
		static const Sbecore::uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemPrsDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemPrsDetailData)
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
		* DpchAppDo (full: DpchAppWzemPrsDetailDo)
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
		* DpchEngData (full: DpchEngWzemPrsDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDRV = 4;
		static const Sbecore::uint FEEDFPUPJ = 5;
		static const Sbecore::uint FEEDFPUPSEX = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstDrv = NULL, Sbecore::Xmlio::Feed* feedFPupJ = NULL, Sbecore::Xmlio::Feed* feedFPupSex = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDrv;
		Sbecore::Xmlio::Feed feedFPupJ;
		Sbecore::Xmlio::Feed feedFPupSex;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzem* dbswzem);
	bool evalButSaveActive(DbsWzem* dbswzem);
	bool evalTxfTitActive(DbsWzem* dbswzem);
	bool evalTxfFnmActive(DbsWzem* dbswzem);
	bool evalPupJActive(DbsWzem* dbswzem);
	bool evalButJEditAvail(DbsWzem* dbswzem);
	bool evalTxtLnmActive(DbsWzem* dbswzem);
	bool evalLstDrvActive(DbsWzem* dbswzem);
	bool evalPupSexActive(DbsWzem* dbswzem);
	bool evalTxfTelActive(DbsWzem* dbswzem);
	bool evalTxfEmlActive(DbsWzem* dbswzem);
	bool evalTxfSalActive(DbsWzem* dbswzem);

public:
	PnlWzemPrsDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemPrsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstDrv;
	Sbecore::Xmlio::Feed feedFPupJ;
	Sbecore::Xmlio::Feed feedFPupSex;

	WzemMPerson recPrs;

	WzemJMPersonLastname recPrsJlnm;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJ(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshTxtDrv(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refreshRecPrs(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecPrsJlnm(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButJEditClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemPrsJlnmMod_prsEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemPrsUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);

};

#endif







