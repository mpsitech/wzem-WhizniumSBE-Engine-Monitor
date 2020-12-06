/**
	* \file WzemAMUserAccess.h
	* database access for table TblWzemAMUserAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMAMUSERACCESS_H
#define WZEMAMUSERACCESS_H

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

/**
	* WzemAMUserAccess: record of TblWzemAMUserAccess
	*/
class WzemAMUserAccess {

public:
	WzemAMUserAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUser;
	Sbecore::uint x1IxWzemVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWzemWAccess;

public:
	bool operator==(const WzemAMUserAccess& comp);
	bool operator!=(const WzemAMUserAccess& comp);
};

/**
	* ListWzemAMUserAccess: recordset of TblWzemAMUserAccess
	*/
class ListWzemAMUserAccess {

public:
	ListWzemAMUserAccess();
	ListWzemAMUserAccess(const ListWzemAMUserAccess& src);
	~ListWzemAMUserAccess();

	void clear();
	unsigned int size() const;
	void append(WzemAMUserAccess* rec);

	WzemAMUserAccess* operator[](const Sbecore::uint ix);
	ListWzemAMUserAccess& operator=(const ListWzemAMUserAccess& src);
	bool operator==(const ListWzemAMUserAccess& comp);
	bool operator!=(const ListWzemAMUserAccess& comp);

public:
	std::vector<WzemAMUserAccess*> nodes;
};

/**
	* TblWzemAMUserAccess: C++ wrapper for table TblWzemAMUserAccess
	*/
class TblWzemAMUserAccess {

public:

public:
	TblWzemAMUserAccess();
	virtual ~TblWzemAMUserAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAMUserAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUserAccess& rst);

	virtual Sbecore::ubigint insertRec(WzemAMUserAccess* rec);
	Sbecore::ubigint insertNewRec(WzemAMUserAccess** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemAMUserAccess& rst, WzemAMUserAccess** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);
	virtual void insertRst(ListWzemAMUserAccess& rst, bool transact = false);
	virtual void updateRec(WzemAMUserAccess* rec);
	virtual void updateRst(ListWzemAMUserAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAMUserAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemAMUserAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAMUserAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAMUserAccess: C++ wrapper for table TblWzemAMUserAccess (MySQL database)
	*/
class MyTblWzemAMUserAccess : public TblWzemAMUserAccess, public Sbecore::MyTable {

public:
	MyTblWzemAMUserAccess();
	~MyTblWzemAMUserAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUserAccess& rst);

	Sbecore::ubigint insertRec(WzemAMUserAccess* rec);
	void insertRst(ListWzemAMUserAccess& rst, bool transact = false);
	void updateRec(WzemAMUserAccess* rec);
	void updateRst(ListWzemAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemAMUserAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAMUserAccess: C++ wrapper for table TblWzemAMUserAccess (PgSQL database)
	*/
class PgTblWzemAMUserAccess : public TblWzemAMUserAccess, public Sbecore::PgTable {

public:
	PgTblWzemAMUserAccess();
	~PgTblWzemAMUserAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAMUserAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemAMUserAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUserAccess& rst);

	Sbecore::ubigint insertRec(WzemAMUserAccess* rec);
	void insertRst(ListWzemAMUserAccess& rst, bool transact = false);
	void updateRec(WzemAMUserAccess* rec);
	void updateRst(ListWzemAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemAMUserAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAMUserAccess: C++ wrapper for table TblWzemAMUserAccess (SQLite database)
	*/
class LiteTblWzemAMUserAccess : public TblWzemAMUserAccess, public Sbecore::LiteTable {

public:
	LiteTblWzemAMUserAccess();
	~LiteTblWzemAMUserAccess();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByUsr;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAMUserAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemAMUserAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUserAccess& rst);

	Sbecore::ubigint insertRec(WzemAMUserAccess* rec);
	void insertRst(ListWzemAMUserAccess& rst, bool transact = false);
	void updateRec(WzemAMUserAccess* rec);
	void updateRst(ListWzemAMUserAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMUserAccess** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemAMUserAccess& rst);
};
#endif

#endif

