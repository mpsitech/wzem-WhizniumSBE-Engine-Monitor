/**
	* \file QryWzemPrdList.h
	* job handler for job QryWzemPrdList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZEMPRDLIST_H
#define QRYWZEMPRDLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWzemPrdListOrd QryWzemPrdList::VecVOrd

#define StatAppQryWzemPrdList QryWzemPrdList::StatApp
#define StatShrQryWzemPrdList QryWzemPrdList::StatShr
#define StgIacQryWzemPrdList QryWzemPrdList::StgIac

/**
	* QryWzemPrdList
	*/
class QryWzemPrdList : public JobWzem {

public:
	/**
		* VecVOrd (full: VecVQryWzemPrdListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint STA = 1;
		static const Sbecore::uint GRP = 2;
		static const Sbecore::uint OWN = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWzemPrdList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 5, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWzemPrdList)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWzemPrdList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWzemPrdList(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~QryWzemPrdList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWzemQPrdList rst;

	Sbecore::uint ixWzemVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWzem* dbswzem, const bool call = false);
	void rerun_filtSQL(std::string& sqlstr, const Sbecore::ubigint preGrp, const Sbecore::ubigint preOwn, const int preSta, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWzem* dbswzem);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WzemQPrdList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:
	bool handleRerun(DbsWzem* dbswzem);
	bool handleShow(DbsWzem* dbswzem);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemPrdUpd_refEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemPrdMod(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemStubChgFromSelf(DbsWzem* dbswzem);

};

#endif
