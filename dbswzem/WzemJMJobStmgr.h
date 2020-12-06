/**
	* \file WzemJMJobStmgr.h
	* database access for table TblWzemJMJobStmgr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMJMJOBSTMGR_H
#define WZEMJMJOBSTMGR_H

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
	* WzemJMJobStmgr: record of TblWzemJMJobStmgr
	*/
class WzemJMJobStmgr {

public:
	WzemJMJobStmgr(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const bool Stmgr = false);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMJob;
	double x1Startu;
	double x1Stopu;
	bool Stmgr;

public:
	bool operator==(const WzemJMJobStmgr& comp);
	bool operator!=(const WzemJMJobStmgr& comp);
};

/**
	* ListWzemJMJobStmgr: recordset of TblWzemJMJobStmgr
	*/
class ListWzemJMJobStmgr {

public:
	ListWzemJMJobStmgr();
	ListWzemJMJobStmgr(const ListWzemJMJobStmgr& src);
	~ListWzemJMJobStmgr();

	void clear();
	unsigned int size() const;
	void append(WzemJMJobStmgr* rec);

	WzemJMJobStmgr* operator[](const Sbecore::uint ix);
	ListWzemJMJobStmgr& operator=(const ListWzemJMJobStmgr& src);
	bool operator==(const ListWzemJMJobStmgr& comp);
	bool operator!=(const ListWzemJMJobStmgr& comp);

public:
	std::vector<WzemJMJobStmgr*> nodes;
};

/**
	* TblWzemJMJobStmgr: C++ wrapper for table TblWzemJMJobStmgr
	*/
class TblWzemJMJobStmgr {

public:

public:
	TblWzemJMJobStmgr();
	virtual ~TblWzemJMJobStmgr();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMJobStmgr** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobStmgr& rst);

	virtual Sbecore::ubigint insertRec(WzemJMJobStmgr* rec);
	Sbecore::ubigint insertNewRec(WzemJMJobStmgr** rec = NULL, const Sbecore::ubigint refWzemMJob = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const bool Stmgr = false);
	Sbecore::ubigint appendNewRecToRst(ListWzemJMJobStmgr& rst, WzemJMJobStmgr** rec = NULL, const Sbecore::ubigint refWzemMJob = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const bool Stmgr = false);
	virtual void insertRst(ListWzemJMJobStmgr& rst, bool transact = false);
	virtual void updateRec(WzemJMJobStmgr* rec);
	virtual void updateRst(ListWzemJMJobStmgr& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobStmgr** rec);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobStmgr& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMJobStmgr& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMJobStmgr: C++ wrapper for table TblWzemJMJobStmgr (MySQL database)
	*/
class MyTblWzemJMJobStmgr : public TblWzemJMJobStmgr, public Sbecore::MyTable {

public:
	MyTblWzemJMJobStmgr();
	~MyTblWzemJMJobStmgr();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobStmgr& rst);

	Sbecore::ubigint insertRec(WzemJMJobStmgr* rec);
	void insertRst(ListWzemJMJobStmgr& rst, bool transact = false);
	void updateRec(WzemJMJobStmgr* rec);
	void updateRst(ListWzemJMJobStmgr& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobStmgr& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMJobStmgr: C++ wrapper for table TblWzemJMJobStmgr (PgSQL database)
	*/
class PgTblWzemJMJobStmgr : public TblWzemJMJobStmgr, public Sbecore::PgTable {

public:
	PgTblWzemJMJobStmgr();
	~PgTblWzemJMJobStmgr();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMJobStmgr& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMJobStmgr& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobStmgr& rst);

	Sbecore::ubigint insertRec(WzemJMJobStmgr* rec);
	void insertRst(ListWzemJMJobStmgr& rst, bool transact = false);
	void updateRec(WzemJMJobStmgr* rec);
	void updateRst(ListWzemJMJobStmgr& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobStmgr& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMJobStmgr: C++ wrapper for table TblWzemJMJobStmgr (SQLite database)
	*/
class LiteTblWzemJMJobStmgr : public TblWzemJMJobStmgr, public Sbecore::LiteTable {

public:
	LiteTblWzemJMJobStmgr();
	~LiteTblWzemJMJobStmgr();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByJob;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMJobStmgr& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMJobStmgr& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobStmgr& rst);

	Sbecore::ubigint insertRec(WzemJMJobStmgr* rec);
	void insertRst(ListWzemJMJobStmgr& rst, bool transact = false);
	void updateRec(WzemJMJobStmgr* rec);
	void updateRst(ListWzemJMJobStmgr& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobStmgr** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobStmgr& rst);
};
#endif

#endif

