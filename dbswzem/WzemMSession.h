/**
	* \file WzemMSession.h
	* database access for table TblWzemMSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMSESSION_H
#define WZEMMSESSION_H

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
	* WzemMSession: record of TblWzemMSession
	*/
class WzemMSession {

public:
	WzemMSession(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUser;
	Sbecore::uint start;
	Sbecore::uint stop;
	std::string Ip;

public:
	bool operator==(const WzemMSession& comp);
	bool operator!=(const WzemMSession& comp);
};

/**
	* ListWzemMSession: recordset of TblWzemMSession
	*/
class ListWzemMSession {

public:
	ListWzemMSession();
	ListWzemMSession(const ListWzemMSession& src);
	~ListWzemMSession();

	void clear();
	unsigned int size() const;
	void append(WzemMSession* rec);

	WzemMSession* operator[](const Sbecore::uint ix);
	ListWzemMSession& operator=(const ListWzemMSession& src);
	bool operator==(const ListWzemMSession& comp);
	bool operator!=(const ListWzemMSession& comp);

public:
	std::vector<WzemMSession*> nodes;
};

/**
	* TblWzemMSession: C++ wrapper for table TblWzemMSession
	*/
class TblWzemMSession {

public:

public:
	TblWzemMSession();
	virtual ~TblWzemMSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMSession& rst);

	virtual Sbecore::ubigint insertRec(WzemMSession* rec);
	Sbecore::ubigint insertNewRec(WzemMSession** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMSession& rst, WzemMSession** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint start = 0, const Sbecore::uint stop = 0, const std::string Ip = "");
	virtual void insertRst(ListWzemMSession& rst, bool transact = false);
	virtual void updateRec(WzemMSession* rec);
	virtual void updateRst(ListWzemMSession& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMSession** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemMSession& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMSession: C++ wrapper for table TblWzemMSession (MySQL database)
	*/
class MyTblWzemMSession : public TblWzemMSession, public Sbecore::MyTable {

public:
	MyTblWzemMSession();
	~MyTblWzemMSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMSession& rst);

	Sbecore::ubigint insertRec(WzemMSession* rec);
	void insertRst(ListWzemMSession& rst, bool transact = false);
	void updateRec(WzemMSession* rec);
	void updateRst(ListWzemMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemMSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMSession: C++ wrapper for table TblWzemMSession (PgSQL database)
	*/
class PgTblWzemMSession : public TblWzemMSession, public Sbecore::PgTable {

public:
	PgTblWzemMSession();
	~PgTblWzemMSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMSession& rst);

	Sbecore::ubigint insertRec(WzemMSession* rec);
	void insertRst(ListWzemMSession& rst, bool transact = false);
	void updateRec(WzemMSession* rec);
	void updateRst(ListWzemMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemMSession& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMSession: C++ wrapper for table TblWzemMSession (SQLite database)
	*/
class LiteTblWzemMSession : public TblWzemMSession, public Sbecore::LiteTable {

public:
	LiteTblWzemMSession();
	~LiteTblWzemMSession();

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
	bool loadRec(sqlite3_stmt* stmt, WzemMSession** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMSession& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMSession** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMSession& rst);

	Sbecore::ubigint insertRec(WzemMSession* rec);
	void insertRst(ListWzemMSession& rst, bool transact = false);
	void updateRec(WzemMSession* rec);
	void updateRst(ListWzemMSession& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMSession** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemMSession& rst);
};
#endif

#endif

