/**
	* \file QryWzemUsr1NSession.h
	* job handler for job QryWzemUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZEMUSR1NSESSION_H
#define QRYWZEMUSR1NSESSION_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatAppQryWzemUsr1NSession QryWzemUsr1NSession::StatApp
#define StatShrQryWzemUsr1NSession QryWzemUsr1NSession::StatShr
#define StgIacQryWzemUsr1NSession QryWzemUsr1NSession::StgIac

/**
	* QryWzemUsr1NSession
	*/
class QryWzemUsr1NSession : public JobWzem {

public:
	/**
		* StatApp (full: StatAppQryWzemUsr1NSession)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 1, const Sbecore::uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryWzemUsr1NSession)
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
		* StgIac (full: StgIacQryWzemUsr1NSession)
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
	QryWzemUsr1NSession(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~QryWzemUsr1NSession();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWzemQUsr1NSession rst;

	Sbecore::uint ixWzemVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWzem* dbswzem, const bool call = false);

	void fetch(DbsWzem* dbswzem);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WzemQUsr1NSession* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:
	bool handleRerun(DbsWzem* dbswzem);
	bool handleShow(DbsWzem* dbswzem);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemSesMod_usrEq(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemStubChgFromSelf(DbsWzem* dbswzem);

};

#endif

