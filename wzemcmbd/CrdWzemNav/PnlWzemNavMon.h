/**
	* \file PnlWzemNavMon.h
	* job handler for job PnlWzemNavMon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNAVMON_H
#define PNLWZEMNAVMON_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemNavMonDo PnlWzemNavMon::VecVDo

#define ContIacWzemNavMon PnlWzemNavMon::ContIac
#define StatAppWzemNavMon PnlWzemNavMon::StatApp
#define StatShrWzemNavMon PnlWzemNavMon::StatShr
#define TagWzemNavMon PnlWzemNavMon::Tag

#define DpchAppWzemNavMonData PnlWzemNavMon::DpchAppData
#define DpchAppWzemNavMonDo PnlWzemNavMon::DpchAppDo
#define DpchEngWzemNavMonData PnlWzemNavMon::DpchEngData

/**
	* PnlWzemNavMon
	*/
class PnlWzemNavMon : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemNavMonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRDVIEWCLICK = 1;
		static const Sbecore::uint BUTPRDNEWCRDCLICK = 2;
		static const Sbecore::uint BUTEVTVIEWCLICK = 3;
		static const Sbecore::uint BUTEVTNEWCRDCLICK = 4;
		static const Sbecore::uint BUTJOBVIEWCLICK = 5;
		static const Sbecore::uint BUTJOBNEWCRDCLICK = 6;
		static const Sbecore::uint BUTCALVIEWCLICK = 7;
		static const Sbecore::uint BUTCALNEWCRDCLICK = 8;
		static const Sbecore::uint BUTCLNVIEWCLICK = 9;
		static const Sbecore::uint BUTCLNNEWCRDCLICK = 10;
		static const Sbecore::uint BUTOPXVIEWCLICK = 11;
		static const Sbecore::uint BUTOPXNEWCRDCLICK = 12;
		static const Sbecore::uint BUTPSTVIEWCLICK = 13;
		static const Sbecore::uint BUTPSTNEWCRDCLICK = 14;
		static const Sbecore::uint BUTNDEVIEWCLICK = 15;
		static const Sbecore::uint BUTNDENEWCRDCLICK = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemNavMon)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTPRD = 1;
		static const Sbecore::uint NUMFLSTEVT = 2;
		static const Sbecore::uint NUMFLSTJOB = 3;
		static const Sbecore::uint NUMFLSTCAL = 4;
		static const Sbecore::uint NUMFLSTCLN = 5;
		static const Sbecore::uint NUMFLSTOPX = 6;
		static const Sbecore::uint NUMFLSTPST = 7;
		static const Sbecore::uint NUMFLSTNDE = 8;

	public:
		ContIac(const Sbecore::uint numFLstPrd = 1, const Sbecore::uint numFLstEvt = 1, const Sbecore::uint numFLstJob = 1, const Sbecore::uint numFLstCal = 1, const Sbecore::uint numFLstCln = 1, const Sbecore::uint numFLstOpx = 1, const Sbecore::uint numFLstPst = 1, const Sbecore::uint numFLstNde = 1);

	public:
		Sbecore::uint numFLstPrd;
		Sbecore::uint numFLstEvt;
		Sbecore::uint numFLstJob;
		Sbecore::uint numFLstCal;
		Sbecore::uint numFLstCln;
		Sbecore::uint numFLstOpx;
		Sbecore::uint numFLstPst;
		Sbecore::uint numFLstNde;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWzemNavMon)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstPrdAlt = true, const bool LstEvtAlt = true, const bool LstJobAlt = true, const bool LstCalAlt = true, const bool LstClnAlt = true, const bool LstOpxAlt = true, const bool LstPstAlt = true, const bool LstNdeAlt = true, const Sbecore::uint LstPrdNumFirstdisp = 1, const Sbecore::uint LstEvtNumFirstdisp = 1, const Sbecore::uint LstJobNumFirstdisp = 1, const Sbecore::uint LstCalNumFirstdisp = 1, const Sbecore::uint LstClnNumFirstdisp = 1, const Sbecore::uint LstOpxNumFirstdisp = 1, const Sbecore::uint LstPstNumFirstdisp = 1, const Sbecore::uint LstNdeNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstPrdAlt = true, const bool LstEvtAlt = true, const bool LstJobAlt = true, const bool LstCalAlt = true, const bool LstClnAlt = true, const bool LstOpxAlt = true, const bool LstPstAlt = true, const bool LstNdeAlt = true, const Sbecore::uint LstPrdNumFirstdisp = 1, const Sbecore::uint LstEvtNumFirstdisp = 1, const Sbecore::uint LstJobNumFirstdisp = 1, const Sbecore::uint LstCalNumFirstdisp = 1, const Sbecore::uint LstClnNumFirstdisp = 1, const Sbecore::uint LstOpxNumFirstdisp = 1, const Sbecore::uint LstPstNumFirstdisp = 1, const Sbecore::uint LstNdeNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzemNavMon)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTPRDAVAIL = 1;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 2;
		static const Sbecore::uint LSTEVTAVAIL = 3;
		static const Sbecore::uint BUTEVTVIEWACTIVE = 4;
		static const Sbecore::uint BUTEVTNEWCRDACTIVE = 5;
		static const Sbecore::uint LSTJOBAVAIL = 6;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 7;
		static const Sbecore::uint BUTJOBNEWCRDACTIVE = 8;
		static const Sbecore::uint LSTCALAVAIL = 9;
		static const Sbecore::uint BUTCALVIEWACTIVE = 10;
		static const Sbecore::uint BUTCALNEWCRDACTIVE = 11;
		static const Sbecore::uint LSTCLNAVAIL = 12;
		static const Sbecore::uint BUTCLNVIEWACTIVE = 13;
		static const Sbecore::uint BUTCLNNEWCRDACTIVE = 14;
		static const Sbecore::uint LSTOPXAVAIL = 15;
		static const Sbecore::uint BUTOPXVIEWACTIVE = 16;
		static const Sbecore::uint BUTOPXNEWCRDACTIVE = 17;
		static const Sbecore::uint LSTPSTAVAIL = 18;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 19;
		static const Sbecore::uint BUTPSTNEWCRDACTIVE = 20;
		static const Sbecore::uint LSTNDEAVAIL = 21;
		static const Sbecore::uint BUTNDEVIEWACTIVE = 22;
		static const Sbecore::uint BUTNDENEWCRDACTIVE = 23;

	public:
		StatShr(const bool LstPrdAvail = true, const bool ButPrdViewActive = true, const bool LstEvtAvail = true, const bool ButEvtViewActive = true, const bool ButEvtNewcrdActive = true, const bool LstJobAvail = true, const bool ButJobViewActive = true, const bool ButJobNewcrdActive = true, const bool LstCalAvail = true, const bool ButCalViewActive = true, const bool ButCalNewcrdActive = true, const bool LstClnAvail = true, const bool ButClnViewActive = true, const bool ButClnNewcrdActive = true, const bool LstOpxAvail = true, const bool ButOpxViewActive = true, const bool ButOpxNewcrdActive = true, const bool LstPstAvail = true, const bool ButPstViewActive = true, const bool ButPstNewcrdActive = true, const bool LstNdeAvail = true, const bool ButNdeViewActive = true, const bool ButNdeNewcrdActive = true);

	public:
		bool LstPrdAvail;
		bool ButPrdViewActive;
		bool LstEvtAvail;
		bool ButEvtViewActive;
		bool ButEvtNewcrdActive;
		bool LstJobAvail;
		bool ButJobViewActive;
		bool ButJobNewcrdActive;
		bool LstCalAvail;
		bool ButCalViewActive;
		bool ButCalNewcrdActive;
		bool LstClnAvail;
		bool ButClnViewActive;
		bool ButClnNewcrdActive;
		bool LstOpxAvail;
		bool ButOpxViewActive;
		bool ButOpxNewcrdActive;
		bool LstPstAvail;
		bool ButPstViewActive;
		bool ButPstNewcrdActive;
		bool LstNdeAvail;
		bool ButNdeViewActive;
		bool ButNdeNewcrdActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemNavMon)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemNavMonData)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNavMonDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzemNavMonData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCAL = 3;
		static const Sbecore::uint FEEDFLSTCLN = 4;
		static const Sbecore::uint FEEDFLSTEVT = 5;
		static const Sbecore::uint FEEDFLSTJOB = 6;
		static const Sbecore::uint FEEDFLSTNDE = 7;
		static const Sbecore::uint FEEDFLSTOPX = 8;
		static const Sbecore::uint FEEDFLSTPRD = 9;
		static const Sbecore::uint FEEDFLSTPST = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint ALL = 14;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstCal = NULL, Sbecore::Feed* feedFLstCln = NULL, Sbecore::Feed* feedFLstEvt = NULL, Sbecore::Feed* feedFLstJob = NULL, Sbecore::Feed* feedFLstNde = NULL, Sbecore::Feed* feedFLstOpx = NULL, Sbecore::Feed* feedFLstPrd = NULL, Sbecore::Feed* feedFLstPst = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstCal;
		Sbecore::Feed feedFLstCln;
		Sbecore::Feed feedFLstEvt;
		Sbecore::Feed feedFLstJob;
		Sbecore::Feed feedFLstNde;
		Sbecore::Feed feedFLstOpx;
		Sbecore::Feed feedFLstPrd;
		Sbecore::Feed feedFLstPst;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalLstPrdAvail(DbsWzem* dbswzem);
	bool evalButPrdViewActive(DbsWzem* dbswzem);
	bool evalLstEvtAvail(DbsWzem* dbswzem);
	bool evalButEvtViewActive(DbsWzem* dbswzem);
	bool evalButEvtNewcrdActive(DbsWzem* dbswzem);
	bool evalLstJobAvail(DbsWzem* dbswzem);
	bool evalButJobViewActive(DbsWzem* dbswzem);
	bool evalButJobNewcrdActive(DbsWzem* dbswzem);
	bool evalLstCalAvail(DbsWzem* dbswzem);
	bool evalButCalViewActive(DbsWzem* dbswzem);
	bool evalButCalNewcrdActive(DbsWzem* dbswzem);
	bool evalLstClnAvail(DbsWzem* dbswzem);
	bool evalButClnViewActive(DbsWzem* dbswzem);
	bool evalButClnNewcrdActive(DbsWzem* dbswzem);
	bool evalLstOpxAvail(DbsWzem* dbswzem);
	bool evalButOpxViewActive(DbsWzem* dbswzem);
	bool evalButOpxNewcrdActive(DbsWzem* dbswzem);
	bool evalLstPstAvail(DbsWzem* dbswzem);
	bool evalButPstViewActive(DbsWzem* dbswzem);
	bool evalButPstNewcrdActive(DbsWzem* dbswzem);
	bool evalLstNdeAvail(DbsWzem* dbswzem);
	bool evalButNdeViewActive(DbsWzem* dbswzem);
	bool evalButNdeNewcrdActive(DbsWzem* dbswzem);

public:
	PnlWzemNavMon(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemNavMon();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstCal;
	Sbecore::Feed feedFLstCln;
	Sbecore::Feed feedFLstEvt;
	Sbecore::Feed feedFLstJob;
	Sbecore::Feed feedFLstNde;
	Sbecore::Feed feedFLstOpx;
	Sbecore::Feed feedFLstPrd;
	Sbecore::Feed feedFLstPst;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstPrd(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshPrd(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstEvt(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshEvt(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstJob(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshJob(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstCal(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshCal(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstCln(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshCln(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstOpx(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshOpx(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstPst(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshPst(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLstNde(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshNde(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButPrdViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButPrdNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButEvtViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButEvtNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButJobViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButJobNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButCalViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButCalNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButClnViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButClnNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButOpxViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButOpxNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButPstViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButPstNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButNdeViewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButNdeNewcrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemHusrRunvMod_crdUsrEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
