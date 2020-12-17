/**
	* \file PnlWzemClnDetail.h
	* job handler for job PnlWzemClnDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMCLNDETAIL_H
#define PNLWZEMCLNDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemClnDetailDo PnlWzemClnDetail::VecVDo

#define ContIacWzemClnDetail PnlWzemClnDetail::ContIac
#define ContInfWzemClnDetail PnlWzemClnDetail::ContInf
#define StatAppWzemClnDetail PnlWzemClnDetail::StatApp
#define StatShrWzemClnDetail PnlWzemClnDetail::StatShr
#define TagWzemClnDetail PnlWzemClnDetail::Tag

#define DpchAppWzemClnDetailData PnlWzemClnDetail::DpchAppData
#define DpchAppWzemClnDetailDo PnlWzemClnDetail::DpchAppDo
#define DpchEngWzemClnDetailData PnlWzemClnDetail::DpchEngData

/**
	* PnlWzemClnDetail
	*/
class PnlWzemClnDetail : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemClnDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;
		static const Sbecore::uint BUTTJBVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemClnDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFCAL = 1;
		static const Sbecore::uint TXFSGE = 2;
		static const Sbecore::uint TXFSTA = 3;
		static const Sbecore::uint TXFSTO = 4;
		static const Sbecore::uint NUMFPUPTRG = 5;
		static const Sbecore::uint NUMFPUPJMS = 6;
		static const Sbecore::uint NUMSFLSTAMS = 7;
		static const Sbecore::uint TXFARG = 8;
		static const Sbecore::uint NUMFPUPJAT = 9;

	public:
		ContIac(const std::string& TxfCal = "", const std::string& TxfSge = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const Sbecore::uint numFPupTrg = 1, const Sbecore::uint numFPupJms = 1, const std::vector<Sbecore::uint>& numsFLstAms = {}, const std::string& TxfArg = "", const Sbecore::uint numFPupJat = 1);

	public:
		std::string TxfCal;
		std::string TxfSge;
		std::string TxfSta;
		std::string TxfSto;
		Sbecore::uint numFPupTrg;
		Sbecore::uint numFPupJms;
		std::vector<Sbecore::uint> numsFLstAms;
		std::string TxfArg;
		Sbecore::uint numFPupJat;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemClnDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTJOB = 1;
		static const Sbecore::uint TXTTJB = 2;
		static const Sbecore::uint TXTAMS = 3;

	public:
		ContInf(const std::string& TxtJob = "", const std::string& TxtTjb = "", const std::string& TxtAms = "");

	public:
		std::string TxtJob;
		std::string TxtTjb;
		std::string TxtAms;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemClnDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstAmsAlt = true, const Sbecore::uint LstAmsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzemClnDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTJOBACTIVE = 3;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 4;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 5;
		static const Sbecore::uint TXFCALACTIVE = 6;
		static const Sbecore::uint TXFSGEACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint PUPTRGACTIVE = 10;
		static const Sbecore::uint PUPJMSACTIVE = 11;
		static const Sbecore::uint TXTTJBACTIVE = 12;
		static const Sbecore::uint BUTTJBVIEWAVAIL = 13;
		static const Sbecore::uint BUTTJBVIEWACTIVE = 14;
		static const Sbecore::uint LSTAMSACTIVE = 15;
		static const Sbecore::uint TXFARGACTIVE = 16;
		static const Sbecore::uint PUPJATACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfCalActive = true, const bool TxfSgeActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool PupTrgActive = true, const bool PupJmsActive = true, const bool TxtTjbActive = true, const bool ButTjbViewAvail = true, const bool ButTjbViewActive = true, const bool LstAmsActive = true, const bool TxfArgActive = true, const bool PupJatActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfCalActive;
		bool TxfSgeActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool PupTrgActive;
		bool PupJmsActive;
		bool TxtTjbActive;
		bool ButTjbViewAvail;
		bool ButTjbViewActive;
		bool LstAmsActive;
		bool TxfArgActive;
		bool PupJatActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemClnDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemClnDetailData)
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
		* DpchAppDo (full: DpchAppWzemClnDetailDo)
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
		* DpchEngData (full: DpchEngWzemClnDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTAMS = 4;
		static const Sbecore::uint FEEDFPUPJAT = 5;
		static const Sbecore::uint FEEDFPUPJMS = 6;
		static const Sbecore::uint FEEDFPUPTRG = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstAms = NULL, Sbecore::Xmlio::Feed* feedFPupJat = NULL, Sbecore::Xmlio::Feed* feedFPupJms = NULL, Sbecore::Xmlio::Feed* feedFPupTrg = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstAms;
		Sbecore::Xmlio::Feed feedFPupJat;
		Sbecore::Xmlio::Feed feedFPupJms;
		Sbecore::Xmlio::Feed feedFPupTrg;
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
	bool evalTxfCalActive(DbsWzem* dbswzem);
	bool evalTxfSgeActive(DbsWzem* dbswzem);
	bool evalTxfStaActive(DbsWzem* dbswzem);
	bool evalTxfStoActive(DbsWzem* dbswzem);
	bool evalPupTrgActive(DbsWzem* dbswzem);
	bool evalPupJmsActive(DbsWzem* dbswzem);
	bool evalTxtTjbActive(DbsWzem* dbswzem);
	bool evalButTjbViewAvail(DbsWzem* dbswzem);
	bool evalButTjbViewActive(DbsWzem* dbswzem);
	bool evalLstAmsActive(DbsWzem* dbswzem);
	bool evalTxfArgActive(DbsWzem* dbswzem);
	bool evalPupJatActive(DbsWzem* dbswzem);

public:
	PnlWzemClnDetail(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemClnDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstAms;
	Sbecore::Xmlio::Feed feedFPupJat;
	Sbecore::Xmlio::Feed feedFPupJms;
	Sbecore::Xmlio::Feed feedFPupTrg;

	WzemMClstn recCln;

	WzemJMClstn recClnJ;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshTxtAms(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refreshRecCln(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshRecClnJ(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDoButTjbViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemClnJMod_clnEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemClnUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemCln_tjbEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemCln_jobEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
