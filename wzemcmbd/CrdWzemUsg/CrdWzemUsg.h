/**
	* \file CrdWzemUsg.h
	* job handler for job CrdWzemUsg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZEMUSG_H
#define CRDWZEMUSG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzemUsgList.h"
#include "PnlWzemUsgHeadbar.h"
#include "PnlWzemUsgRec.h"

#define VecVWzemUsgDo CrdWzemUsg::VecVDo
#define VecVWzemUsgSge CrdWzemUsg::VecVSge

#define ContInfWzemUsg CrdWzemUsg::ContInf
#define StatAppWzemUsg CrdWzemUsg::StatApp
#define StatShrWzemUsg CrdWzemUsg::StatShr
#define TagWzemUsg CrdWzemUsg::Tag

#define DpchAppWzemUsgDo CrdWzemUsg::DpchAppDo
#define DpchEngWzemUsgData CrdWzemUsg::DpchEngData

/**
	* CrdWzemUsg
	*/
class CrdWzemUsg : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemUsgDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzemUsgSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZEMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWzemUsg)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDUSG = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdUsg = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdUsg;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemUsg)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzemVReqitmode = VecWzemVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzemVReqitmode = VecWzemVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWzemUsg)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFHEADBAR = 1;
		static const Sbecore::uint JREFLIST = 2;
		static const Sbecore::uint JREFREC = 3;

	public:
		StatShr(const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0);

	public:
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemUsg)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzemUsgDo)
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
		* DpchEngData (full: DpchEngWzemUsgData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

public:
	CrdWzemUsg(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale, const Sbecore::ubigint ref = 0);
	~CrdWzemUsg();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWzemUsgList* pnllist;
	PnlWzemUsgHeadbar* pnlheadbar;
	PnlWzemUsgRec* pnlrec;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void changeRef(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);
	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

	void handleDpchAppDoClose(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppWzemAlert(DbsWzem* dbswzem, DpchAppWzemAlert* dpchappwzemalert, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemRefPreSet(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWzemDlgClose(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemStatChg(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);

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
