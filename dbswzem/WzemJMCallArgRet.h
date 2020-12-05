/**
	* \file WzemJMCallArgRet.h
	* database access for table TblWzemJMCallArgRet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMJMCALLARGRET_H
#define WZEMJMCALLARGRET_H

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
	* WzemJMCallArgRet: record of TblWzemJMCallArgRet
	*/
class WzemJMCallArgRet {

public:
	WzemJMCallArgRet(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMCall = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string argRet = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMCall;
	double x1Startu;
	double x1Stopu;
	std::string argRet;

public:
	bool operator==(const WzemJMCallArgRet& comp);
	bool operator!=(const WzemJMCallArgRet& comp);
};

/**
	* ListWzemJMCallArgRet: recordset of TblWzemJMCallArgRet
	*/
class ListWzemJMCallArgRet {

public:
	ListWzemJMCallArgRet();
	ListWzemJMCallArgRet(const ListWzemJMCallArgRet& src);
	~ListWzemJMCallArgRet();

	void clear();
	unsigned int size() const;
	void append(WzemJMCallArgRet* rec);

	WzemJMCallArgRet* operator[](const Sbecore::uint ix);
	ListWzemJMCallArgRet& operator=(const ListWzemJMCallArgRet& src);
	bool operator==(const ListWzemJMCallArgRet& comp);
	bool operator!=(const ListWzemJMCallArgRet& comp);

public:
	std::vector<WzemJMCallArgRet*> nodes;
};

/**
	* TblWzemJMCallArgRet: C++ wrapper for table TblWzemJMCallArgRet
	*/
class TblWzemJMCallArgRet {

public:

public:
	TblWzemJMCallArgRet();
	virtual ~TblWzemJMCallArgRet();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMCallArgRet** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMCallArgRet& rst);

	virtual Sbecore::ubigint insertRec(WzemJMCallArgRet* rec);
	Sbecore::ubigint insertNewRec(WzemJMCallArgRet** rec = NULL, const Sbecore::ubigint refWzemMCall = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string argRet = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemJMCallArgRet& rst, WzemJMCallArgRet** rec = NULL, const Sbecore::ubigint refWzemMCall = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string argRet = "");
	virtual void insertRst(ListWzemJMCallArgRet& rst, bool transact = false);
	virtual void updateRec(WzemJMCallArgRet* rec);
	virtual void updateRst(ListWzemJMCallArgRet& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMCallArgRet** rec);
	virtual Sbecore::ubigint loadRstByCal(Sbecore::ubigint refWzemMCall, const bool append, ListWzemJMCallArgRet& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMCallArgRet& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMCallArgRet: C++ wrapper for table TblWzemJMCallArgRet (MySQL database)
	*/
class MyTblWzemJMCallArgRet : public TblWzemJMCallArgRet, public Sbecore::MyTable {

public:
	MyTblWzemJMCallArgRet();
	~MyTblWzemJMCallArgRet();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMCallArgRet& rst);

	Sbecore::ubigint insertRec(WzemJMCallArgRet* rec);
	void insertRst(ListWzemJMCallArgRet& rst, bool transact = false);
	void updateRec(WzemJMCallArgRet* rec);
	void updateRst(ListWzemJMCallArgRet& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstByCal(Sbecore::ubigint refWzemMCall, const bool append, ListWzemJMCallArgRet& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMCallArgRet: C++ wrapper for table TblWzemJMCallArgRet (PgSQL database)
	*/
class PgTblWzemJMCallArgRet : public TblWzemJMCallArgRet, public Sbecore::PgTable {

public:
	PgTblWzemJMCallArgRet();
	~PgTblWzemJMCallArgRet();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMCallArgRet& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMCallArgRet& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMCallArgRet& rst);

	Sbecore::ubigint insertRec(WzemJMCallArgRet* rec);
	void insertRst(ListWzemJMCallArgRet& rst, bool transact = false);
	void updateRec(WzemJMCallArgRet* rec);
	void updateRst(ListWzemJMCallArgRet& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstByCal(Sbecore::ubigint refWzemMCall, const bool append, ListWzemJMCallArgRet& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMCallArgRet: C++ wrapper for table TblWzemJMCallArgRet (SQLite database)
	*/
class LiteTblWzemJMCallArgRet : public TblWzemJMCallArgRet, public Sbecore::LiteTable {

public:
	LiteTblWzemJMCallArgRet();
	~LiteTblWzemJMCallArgRet();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByCal;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMCallArgRet& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMCallArgRet& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMCallArgRet& rst);

	Sbecore::ubigint insertRec(WzemJMCallArgRet* rec);
	void insertRst(ListWzemJMCallArgRet& rst, bool transact = false);
	void updateRec(WzemJMCallArgRet* rec);
	void updateRst(ListWzemJMCallArgRet& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMCallArgRet** rec);
	Sbecore::ubigint loadRstByCal(Sbecore::ubigint refWzemMCall, const bool append, ListWzemJMCallArgRet& rst);
};
#endif

#endif

