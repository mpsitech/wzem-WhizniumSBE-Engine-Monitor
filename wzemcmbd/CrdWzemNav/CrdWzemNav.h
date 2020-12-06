/**
	* \file CrdWzemNav.h
	* job handler for job CrdWzemNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZEMNAV_H
#define CRDWZEMNAV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzemNavMon.h"
#include "PnlWzemNavAdmin.h"
#include "PnlWzemNavPre.h"
#include "PnlWzemNavHeadbar.h"
#include "DlgWzemNavLoaini.h"

#define VecVWzemNavDo CrdWzemNav::VecVDo
#define VecVWzemNavSge CrdWzemNav::VecVSge

#define ContInfWzemNav CrdWzemNav::ContInf
#define StatAppWzemNav CrdWzemNav::StatApp
#define StatShrWzemNav CrdWzemNav::StatShr
#define TagWzemNav CrdWzemNav::Tag

#define DpchAppWzemNavDo CrdWzemNav::DpchAppDo
#define DpchEngWzemNavData CrdWzemNav::DpchEngData

/**
	* CrdWzemNav
	*/
class CrdWzemNav : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDPRDCLICK = 8;
		static const Sbecore::uint MITCRDEVTCLICK = 9;
		static const Sbecore::uint MITCRDJOBCLICK = 10;
		static const Sbecore::uint MITCRDCALCLICK = 11;
		static const Sbecore::uint MITCRDCLNCLICK = 12;
		static const Sbecore::uint MITCRDOPXCLICK = 13;
		static const Sbecore::uint MITCRDPSTCLICK = 14;
		static const Sbecore::uint MITCRDNDECLICK = 15;
		static const Sbecore::uint MITAPPLOICLICK = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzemNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZEMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWzemNav)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVReqitmode = VecWzemVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneMon = false);
	};

	/**
		* StatShr (full: StatShrWzemNav)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGLOAINI = 1;
		static const Sbecore::uint JREFHEADBAR = 2;
		static const Sbecore::uint JREFPRE = 3;
		static const Sbecore::uint PNLPREAVAIL = 4;
		static const Sbecore::uint JREFADMIN = 5;
		static const Sbecore::uint PNLADMINAVAIL = 6;
		static const Sbecore::uint JREFMON = 7;
		static const Sbecore::uint PNLMONAVAIL = 8;
		static const Sbecore::uint MITSESSPSAVAIL = 9;
		static const Sbecore::uint MSPCRD1AVAIL = 10;
		static const Sbecore::uint MITCRDUSGAVAIL = 11;
		static const Sbecore::uint MITCRDUSRAVAIL = 12;
		static const Sbecore::uint MITCRDPRSAVAIL = 13;
		static const Sbecore::uint MSPCRD2AVAIL = 14;
		static const Sbecore::uint MITCRDPRDAVAIL = 15;
		static const Sbecore::uint MITCRDEVTAVAIL = 16;
		static const Sbecore::uint MITCRDJOBAVAIL = 17;
		static const Sbecore::uint MITCRDCALAVAIL = 18;
		static const Sbecore::uint MITCRDCLNAVAIL = 19;
		static const Sbecore::uint MITCRDOPXAVAIL = 20;
		static const Sbecore::uint MITCRDPSTAVAIL = 21;
		static const Sbecore::uint MITCRDNDEAVAIL = 22;
		static const Sbecore::uint MSPAPP2AVAIL = 23;
		static const Sbecore::uint MITAPPLOIAVAIL = 24;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefPre = 0, const bool pnlpreAvail = false, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefMon = 0, const bool pnlmonAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MspCrd2Avail = true, const bool MitCrdPrdAvail = true, const bool MitCrdEvtAvail = true, const bool MitCrdJobAvail = true, const bool MitCrdCalAvail = true, const bool MitCrdClnAvail = true, const bool MitCrdOpxAvail = true, const bool MitCrdPstAvail = true, const bool MitCrdNdeAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		Sbecore::ubigint jrefDlgloaini;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefPre;
		bool pnlpreAvail;
		Sbecore::ubigint jrefAdmin;
		bool pnladminAvail;
		Sbecore::ubigint jrefMon;
		bool pnlmonAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MspCrd2Avail;
		bool MitCrdPrdAvail;
		bool MitCrdEvtAvail;
		bool MitCrdJobAvail;
		bool MitCrdCalAvail;
		bool MitCrdClnAvail;
		bool MitCrdOpxAvail;
		bool MitCrdPstAvail;
		bool MitCrdNdeAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemNav)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNavDo)
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
		* DpchEngData (full: DpchEngWzemNavData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalPnlpreAvail(DbsWzem* dbswzem);
	bool evalPnladminAvail(DbsWzem* dbswzem);
	bool evalPnlmonAvail(DbsWzem* dbswzem);
	bool evalMitSesSpsAvail(DbsWzem* dbswzem);
	bool evalMspCrd1Avail(DbsWzem* dbswzem);
	bool evalMitCrdUsgAvail(DbsWzem* dbswzem);
	bool evalMitCrdUsrAvail(DbsWzem* dbswzem);
	bool evalMitCrdPrsAvail(DbsWzem* dbswzem);
	bool evalMspCrd2Avail(DbsWzem* dbswzem);
	bool evalMitCrdPrdAvail(DbsWzem* dbswzem);
	bool evalMitCrdEvtAvail(DbsWzem* dbswzem);
	bool evalMitCrdJobAvail(DbsWzem* dbswzem);
	bool evalMitCrdCalAvail(DbsWzem* dbswzem);
	bool evalMitCrdClnAvail(DbsWzem* dbswzem);
	bool evalMitCrdOpxAvail(DbsWzem* dbswzem);
	bool evalMitCrdPstAvail(DbsWzem* dbswzem);
	bool evalMitCrdNdeAvail(DbsWzem* dbswzem);
	bool evalMspApp2Avail(DbsWzem* dbswzem);
	bool evalMitAppLoiAvail(DbsWzem* dbswzem);

public:
	CrdWzemNav(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~CrdWzemNav();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	PnlWzemNavMon* pnlmon;
	PnlWzemNavAdmin* pnladmin;
	PnlWzemNavPre* pnlpre;
	PnlWzemNavHeadbar* pnlheadbar;
	DlgWzemNavLoaini* dlgloaini;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

	void handleDpchAppDoClose(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitSesSpsClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdPrdClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdEvtClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdJobClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdCalClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdClnClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdOpxClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdPstClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitCrdNdeClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppWzemAlert(DbsWzem* dbswzem, DpchAppWzemAlert* dpchappwzemalert, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemDlgClose(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWzem* dbswzem, Sbecore::uint _ixVSge, DpchEngWzem** dpcheng = NULL);

public:
	std::string getSquawk(DbsWzem* dbswzem);

private:
	Sbecore::uint enterSgeIdle(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeIdle(DbsWzem* dbswzem);
	Sbecore::uint enterSgeAlrwzemabt(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeAlrwzemabt(DbsWzem* dbswzem);

};

#endif







