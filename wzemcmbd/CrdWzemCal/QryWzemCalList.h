/**
	* \file QryWzemCalList.h
	* job handler for job QryWzemCalList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZEMCALLIST_H
#define QRYWZEMCALLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWzemCalListOrd QryWzemCalList::VecVOrd

#define StatAppQryWzemCalList QryWzemCalList::StatApp
#define StatShrQryWzemCalList QryWzemCalList::StatShr
#define StgIacQryWzemCalList QryWzemCalList::StgIac

/**
	* QryWzemCalList
	*/
class QryWzemCalList : public JobWzem {

public:
	/**
		* VecVOrd (full: VecVQryWzemCalListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint STO = 1;
		static const Sbecore::uint STA = 2;
		static const Sbecore::uint JOB = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWzemCalList)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 4, const Sbecore::uint ndisp = 25);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 4, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWzemCalList)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWzemCalList)
		*/
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWzemCalList(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~QryWzemCalList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWzemQCalList rst;

	Sbecore::uint ixWzemVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWzem* dbswzem, const bool call = false);
	void rerun_baseSQL(std::string& sqlstr);
	void rerun_filtSQL(std::string& sqlstr, const Sbecore::ubigint preJob, const double preSta, const double preSto, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWzem* dbswzem);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WzemQCalList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:
	bool handleRerun(DbsWzem* dbswzem);
	bool handleShow(DbsWzem* dbswzem);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemCalUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemCalMod(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemStubChgFromSelf(DbsWzem* dbswzem);

};

#endif
