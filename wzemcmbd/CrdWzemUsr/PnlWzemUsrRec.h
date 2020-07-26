/**
	* \file PnlWzemUsrRec.h
	* job handler for job PnlWzemUsrRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef PNLWZEMUSRREC_H
#define PNLWZEMUSRREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzemUsrMNUsergroup.h"
#include "PnlWzemUsr1NSession.h"
#include "PnlWzemUsrAAccess.h"
#include "PnlWzemUsrDetail.h"

#define VecVWzemUsrRecDo PnlWzemUsrRec::VecVDo

#define ContInfWzemUsrRec PnlWzemUsrRec::ContInf
#define StatAppWzemUsrRec PnlWzemUsrRec::StatApp
#define StatShrWzemUsrRec PnlWzemUsrRec::StatShr
#define TagWzemUsrRec PnlWzemUsrRec::Tag

#define DpchAppWzemUsrRecDo PnlWzemUsrRec::DpchAppDo
#define DpchEngWzemUsrRecData PnlWzemUsrRec::DpchEngData

/**
	* PnlWzemUsrRec
	*/
class PnlWzemUsrRec : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemUsrRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemUsrRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzemUsrRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdone1NSession = false, const bool initdoneMNUsergroup = false);
	};

	/**
		* StatShr (full: StatShrWzemUsrRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAACCESS = 3;
		static const Sbecore::uint JREF1NSESSION = 4;
		static const Sbecore::uint JREFMNUSERGROUP = 5;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAAccess = 0, const Sbecore::ubigint jref1NSession = 0, const Sbecore::ubigint jrefMNUsergroup = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzemVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAAccess;
		Sbecore::ubigint jref1NSession;
		Sbecore::ubigint jrefMNUsergroup;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemUsrRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzemUsrRecDo)
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
		* DpchEngData (full: DpchEngWzemUsrRecData)
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

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWzem* dbswzem);

public:
	PnlWzemUsrRec(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemUsrRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWzemUsrMNUsergroup* pnlmnusergroup;
	PnlWzemUsr1NSession* pnl1nsession;
	PnlWzemUsrAAccess* pnlaaccess;
	PnlWzemUsrDetail* pnldetail;

	WzemMUser recUsr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

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
	bool handleCallWzemUsrUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemUsr_usgEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzemUsr_prsEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

