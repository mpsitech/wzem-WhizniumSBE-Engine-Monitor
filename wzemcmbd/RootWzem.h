/**
	* \file RootWzem.h
	* job handler for job RootWzem (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef ROOTWZEM_H
#define ROOTWZEM_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "SessWzem.h"

#define DpchAppRootWzemLogin RootWzem::DpchAppLogin
#define DpchEngRootWzemData RootWzem::DpchEngData

/**
	* RootWzem
	*/
class RootWzem : public JobWzem {

public:
	/**
		* DpchAppLogin (full: DpchAppRootWzemLogin)
		*/
	class DpchAppLogin : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;

	public:
		DpchAppLogin();

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngRootWzemData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Xmlio::Feed* feedFEnsSps = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Xmlio::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

public:
	RootWzem(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const bool _clearAll);
	~RootWzem();

public:

	std::list<SessWzem*> sesss;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsWzem* dbswzem);
	void clearQtb(DbsWzem* dbswzem);

	bool authenticate(DbsWzem* dbswzem, const std::string& username, const std::string& password, Sbecore::ubigint& refWzemMUser);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:
	bool handleClearAll(DbsWzem* dbswzem);
	bool handleCreateSess(DbsWzem* dbswzem);
	bool handleEraseSess(DbsWzem* dbswzem);

	void handleDpchAppLogin(DbsWzem* dbswzem, DpchAppLogin* dpchapplogin, const std::string ip, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemSuspsess(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);
	bool handleCallWzemLogout(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const bool boolvalInv);

};

#endif

