/**
	* \file PnlWzemUsrDetail.h
	* job handler for job PnlWzemUsrDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMUSRDETAIL_H
#define PNLWZEMUSRDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemUsrDetailDo PnlWzemUsrDetail::VecVDo

#define ContIacWzemUsrDetail PnlWzemUsrDetail::ContIac
#define ContInfWzemUsrDetail PnlWzemUsrDetail::ContInf
#define StatAppWzemUsrDetail PnlWzemUsrDetail::StatApp
#define StatShrWzemUsrDetail PnlWzemUsrDetail::StatShr
#define TagWzemUsrDetail PnlWzemUsrDetail::Tag

#define DpchAppWzemUsrDetailData PnlWzemUsrDetail::DpchAppData
#define DpchAppWzemUsrDetailDo PnlWzemUsrDetail::DpchAppDo
#define DpchEngWzemUsrDetailData PnlWzemUsrDetail::DpchEngData

/**
	* PnlWzemUsrDetail
	*/
class PnlWzemUsrDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRSVIEWCLICK = 2;
		static const Sbecore::uint BUTUSGVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemUsrDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPSTE = 1;
		static const Sbecore::uint NUMFPUPLCL = 2;
		static const Sbecore::uint NUMFPUPULV = 3;
		static const Sbecore::uint TXFPWD = 4;
		static const Sbecore::uint TXFFKY = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIac(const Sbecore::uint numFPupSte = 1, const Sbecore::uint numFPupLcl = 1, const Sbecore::uint numFPupUlv = 1, const std::string& TxfPwd = "", const std::string& TxfFky = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupSte;
		Sbecore::uint numFPupLcl;
		Sbecore::uint numFPupUlv;
		std::string TxfPwd;
		std::string TxfFky;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemUsrDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRS = 1;
		static const Sbecore::uint TXTSRF = 2;
		static const Sbecore::uint TXTUSG = 3;

	public:
		ContInf(const std::string& TxtPrs = "", const std::string& TxtSrf = "", const std::string& TxtUsg = "");

	public:
		std::string TxtPrs;
		std::string TxtSrf;
		std::string TxtUsg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemUsrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzemUsrDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRSACTIVE = 3;
		static const Sbecore::uint BUTPRSVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTUSGACTIVE = 7;
		static const Sbecore::uint BUTUSGVIEWAVAIL = 8;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 9;
		static const Sbecore::uint PUPSTEACTIVE = 10;
		static const Sbecore::uint PUPLCLACTIVE = 11;
		static const Sbecore::uint PUPULVACTIVE = 12;
		static const Sbecore::uint TXFPWDACTIVE = 13;
		static const Sbecore::uint TXFFKYACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemUsrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemUsrDetailData)
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
		* DpchAppDo (full: DpchAppWzemUsrDetailDo)
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
		* DpchEngData (full: DpchEngWzemUsrDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPLCL = 4;
		static const Sbecore::uint FEEDFPUPSTE = 5;
		static const Sbecore::uint FEEDFPUPULV = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupLcl = NULL, Sbecore::Xmlio::Feed* feedFPupSte = NULL, Sbecore::Xmlio::Feed* feedFPupUlv = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupLcl;
		Sbecore::Xmlio::Feed feedFPupSte;
		Sbecore::Xmlio::Feed feedFPupUlv;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzem* dbswzem);
	bool evalButSaveActive(DbsWzem* dbswzem);
	bool evalTxtPrsActive(DbsWzem* dbswzem);
	bool evalButPrsViewAvail(DbsWzem* dbswzem);
	bool evalButPrsViewActive(DbsWzem* dbswzem);
	bool evalTxtSrfActive(DbsWzem* dbswzem);
	bool evalTxtUsgActive(DbsWzem* dbswzem);
	bool evalButUsgViewAvail(DbsWzem* dbswzem);
	bool evalButUsgViewActive(DbsWzem* dbswzem);
	bool evalPupSteActive(DbsWzem* dbswzem);
	bool evalPupLclActive(DbsWzem* dbswzem);
	bool evalPupUlvActive(DbsWzem* dbswzem);
	bool evalTxfPwdActive(DbsWzem* dbswzem);
	bool evalTxfFkyActive(DbsWzem* dbswzem);
	bool evalTxfCmtActive(DbsWzem* dbswzem);

public:
	PnlWzemUsrDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemUsrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupLcl;
	Sbecore::Xmlio::Feed feedFPupSte;
	Sbecore::Xmlio::Feed feedFPupUlv;

	WzemMUser recUsr;

	WzemJMUserState recUsrJste;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecUsr(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecUsrJste(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButUsgViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemUsrJsteMod_usrEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemUsrUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemUsr_usgEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemUsr_prsEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif







