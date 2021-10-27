/**
	* \file PnlWzemNavHeadbar.h
	* job handler for job PnlWzemNavHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNAVHEADBAR_H
#define PNLWZEMNAVHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrWzemNavHeadbar PnlWzemNavHeadbar::StatShr
#define StgInfWzemNavHeadbar PnlWzemNavHeadbar::StgInf
#define TagWzemNavHeadbar PnlWzemNavHeadbar::Tag

#define DpchEngWzemNavHeadbarData PnlWzemNavHeadbar::DpchEngData

/**
	* PnlWzemNavHeadbar
	*/
class PnlWzemNavHeadbar : public JobWzem {

public:
	/**
		* StatShr (full: StatShrWzemNavHeadbar)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfWzemNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWzemNavHeadbar)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWzemNavHeadbarData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsWzem* dbswzem);
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

public:
	PnlWzemNavHeadbar(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemNavHeadbar();

public:
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

};

#endif
