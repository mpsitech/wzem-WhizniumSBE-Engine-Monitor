/**
	* \file PnlWzemPstRec.h
	* job handler for job PnlWzemPstRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPSTREC_H
#define PNLWZEMPSTREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzemPstDetail.h"

#define VecVWzemPstRecDo PnlWzemPstRec::VecVDo

#define ContInfWzemPstRec PnlWzemPstRec::ContInf
#define StatAppWzemPstRec PnlWzemPstRec::StatApp
#define StatShrWzemPstRec PnlWzemPstRec::StatShr
#define TagWzemPstRec PnlWzemPstRec::Tag

#define DpchAppWzemPstRecDo PnlWzemPstRec::DpchAppDo
#define DpchEngWzemPstRecData PnlWzemPstRec::DpchEngData

/**
	* PnlWzemPstRec
	*/
class PnlWzemPstRec : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemPstRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemPstRec)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemPstRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false);
	};

	/**
		* StatShr (full: StatShrWzemPstRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 3;

	public:
		StatShr(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzemVExpstate;
		Sbecore::ubigint jrefDetail;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemPstRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzemPstRecDo)
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
		* DpchEngData (full: DpchEngWzemPstRecData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWzem* dbswzem);

public:
	PnlWzemPstRec(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemPstRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWzemPstDetail* pnldetail;

	WzemMPreset recPst;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWzem* dbswzem, const bool notif = false, DpchEngWzem** dpcheng = NULL);
	void regularize(DbsWzem* dbswzem, const bool notif = false, DpchEngWzem** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemPstUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemPst_jobEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
