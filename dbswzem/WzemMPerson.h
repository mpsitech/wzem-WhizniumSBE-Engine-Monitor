/**
	* \file WzemMPerson.h
	* database access for table TblWzemMPerson (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMPERSON_H
#define WZEMMPERSON_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif
#if defined(SBECORE_LITE)
	#include <sbecore/LiteDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWzemVMPersonSex TblWzemMPerson::VecVSex
#define VecWzemWMPersonDerivate TblWzemMPerson::VecWDerivate

/**
	* WzemMPerson: record of TblWzemMPerson
	*/
class WzemMPerson {

public:
	WzemMPerson(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixWDerivate;
	Sbecore::uint ixVSex;
	std::string Title;
	std::string Firstname;
	Sbecore::ubigint refJLastname;
	std::string Lastname;
	Sbecore::ubigint telRefADetail;
	std::string telVal;
	Sbecore::ubigint emlRefADetail;
	std::string emlVal;
	std::string Salutation;

public:
	bool operator==(const WzemMPerson& comp);
	bool operator!=(const WzemMPerson& comp);
};

/**
	* ListWzemMPerson: recordset of TblWzemMPerson
	*/
class ListWzemMPerson {

public:
	ListWzemMPerson();
	ListWzemMPerson(const ListWzemMPerson& src);
	~ListWzemMPerson();

	void clear();
	unsigned int size() const;
	void append(WzemMPerson* rec);

	WzemMPerson* operator[](const Sbecore::uint ix);
	ListWzemMPerson& operator=(const ListWzemMPerson& src);
	bool operator==(const ListWzemMPerson& comp);
	bool operator!=(const ListWzemMPerson& comp);

public:
	std::vector<WzemMPerson*> nodes;
};

/**
	* TblWzemMPerson: C++ wrapper for table TblWzemMPerson
	*/
class TblWzemMPerson {

public:
	/**
		* VecVSex (full: VecWzemVMPersonSex)
		*/
	class VecVSex {

	public:
		static const Sbecore::uint F = 1;
		static const Sbecore::uint M = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWDerivate (full: VecWzemWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const Sbecore::uint USR = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWzemMPerson();
	virtual ~TblWzemMPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPerson& rst);

	virtual Sbecore::ubigint insertRec(WzemMPerson* rec);
	Sbecore::ubigint insertNewRec(WzemMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMPerson& rst, WzemMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	virtual void insertRst(ListWzemMPerson& rst, bool transact = false);
	virtual void updateRec(WzemMPerson* rec);
	virtual void updateRst(ListWzemMPerson& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMPerson** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMPerson: C++ wrapper for table TblWzemMPerson (MySQL database)
	*/
class MyTblWzemMPerson : public TblWzemMPerson, public Sbecore::MyTable {

public:
	MyTblWzemMPerson();
	~MyTblWzemMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPerson& rst);

	Sbecore::ubigint insertRec(WzemMPerson* rec);
	void insertRst(ListWzemMPerson& rst, bool transact = false);
	void updateRec(WzemMPerson* rec);
	void updateRst(ListWzemMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPerson** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMPerson: C++ wrapper for table TblWzemMPerson (PgSQL database)
	*/
class PgTblWzemMPerson : public TblWzemMPerson, public Sbecore::PgTable {

public:
	PgTblWzemMPerson();
	~PgTblWzemMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMPerson** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPerson& rst);

	Sbecore::ubigint insertRec(WzemMPerson* rec);
	void insertRst(ListWzemMPerson& rst, bool transact = false);
	void updateRec(WzemMPerson* rec);
	void updateRst(ListWzemMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPerson** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMPerson: C++ wrapper for table TblWzemMPerson (SQLite database)
	*/
class LiteTblWzemMPerson : public TblWzemMPerson, public Sbecore::LiteTable {

public:
	LiteTblWzemMPerson();
	~LiteTblWzemMPerson();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMPerson** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMPerson& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMPerson** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPerson& rst);

	Sbecore::ubigint insertRec(WzemMPerson* rec);
	void insertRst(ListWzemMPerson& rst, bool transact = false);
	void updateRec(WzemMPerson* rec);
	void updateRst(ListWzemMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPerson** rec);
};
#endif

#endif

