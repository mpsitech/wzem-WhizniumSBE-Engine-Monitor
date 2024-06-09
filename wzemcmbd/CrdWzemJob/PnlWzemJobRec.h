/**
	* \file PnlWzemJobRec.h
	* job handler for job PnlWzemJobRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMJOBREC_H
#define PNLWZEMJOBREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzemJobSup1NJob.h"
#include "PnlWzemJob1NPreset.h"
#include "PnlWzemJob1NCall.h"
#include "PnlWzemJob1NClstn.h"
#include "PnlWzemJob1NOp.h"
#include "PnlWzemJobDetail.h"

#define VecVWzemJobRecDo PnlWzemJobRec::VecVDo

#define ContInfWzemJobRec PnlWzemJobRec::ContInf
#define StatAppWzemJobRec PnlWzemJobRec::StatApp
#define StatShrWzemJobRec PnlWzemJobRec::StatShr
#define TagWzemJobRec PnlWzemJobRec::Tag

#define DpchAppWzemJobRecDo PnlWzemJobRec::DpchAppDo
#define DpchEngWzemJobRecData PnlWzemJobRec::DpchEngData

/**
	* PnlWzemJobRec
	*/
class PnlWzemJobRec : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemJobRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemJobRec)
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
		* StatApp (full: StatAppWzemJobRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdone1NOp = false, const bool initdone1NClstn = false, const bool initdone1NCall = false, const bool initdone1NPreset = false, const bool initdoneSup1NJob = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NOp = false, const bool initdone1NClstn = false, const bool initdone1NCall = false, const bool initdone1NPreset = false, const bool initdoneSup1NJob = false);
	};

	/**
		* StatShr (full: StatShrWzemJobRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NOP = 3;
		static const Sbecore::uint JREF1NCLSTN = 4;
		static const Sbecore::uint JREF1NCALL = 5;
		static const Sbecore::uint JREF1NPRESET = 6;
		static const Sbecore::uint JREFSUP1NJOB = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NOp = 0, const Sbecore::ubigint jref1NClstn = 0, const Sbecore::ubigint jref1NCall = 0, const Sbecore::ubigint jref1NPreset = 0, const Sbecore::ubigint jrefSup1NJob = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzemVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NOp;
		Sbecore::ubigint jref1NClstn;
		Sbecore::ubigint jref1NCall;
		Sbecore::ubigint jref1NPreset;
		Sbecore::ubigint jrefSup1NJob;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemJobRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzemJobRecDo)
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
		* DpchEngData (full: DpchEngWzemJobRecData)
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
	PnlWzemJobRec(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemJobRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWzemJobSup1NJob* pnlsup1njob;
	PnlWzemJob1NPreset* pnl1npreset;
	PnlWzemJob1NCall* pnl1ncall;
	PnlWzemJob1NClstn* pnl1nclstn;
	PnlWzemJob1NOp* pnl1nop;
	PnlWzemJobDetail* pnldetail;

	WzemMJob recJob;

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
	bool handleCallWzemJobUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemJob_supEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemJob_prdEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
