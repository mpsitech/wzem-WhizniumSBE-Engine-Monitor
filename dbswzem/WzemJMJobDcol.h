/**
	* \file WzemJMJobDcol.h
	* database access for table TblWzemJMJobDcol (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMJMJOBDCOL_H
#define WZEMJMJOBDCOL_H

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
	* WzemJMJobDcol: record of TblWzemJMJobDcol
	*/
class WzemJMJobDcol {

public:
	WzemJMJobDcol(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const bool Dcol = false);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMJob;
	double x1Startu;
	double x1Stopu;
	bool Dcol;

public:
	bool operator==(const WzemJMJobDcol& comp);
	bool operator!=(const WzemJMJobDcol& comp);
};

/**
	* ListWzemJMJobDcol: recordset of TblWzemJMJobDcol
	*/
class ListWzemJMJobDcol {

public:
	ListWzemJMJobDcol();
	ListWzemJMJobDcol(const ListWzemJMJobDcol& src);
	~ListWzemJMJobDcol();

	void clear();
	unsigned int size() const;
	void append(WzemJMJobDcol* rec);

	WzemJMJobDcol* operator[](const Sbecore::uint ix);
	ListWzemJMJobDcol& operator=(const ListWzemJMJobDcol& src);
	bool operator==(const ListWzemJMJobDcol& comp);
	bool operator!=(const ListWzemJMJobDcol& comp);

public:
	std::vector<WzemJMJobDcol*> nodes;
};

/**
	* TblWzemJMJobDcol: C++ wrapper for table TblWzemJMJobDcol
	*/
class TblWzemJMJobDcol {

public:

public:
	TblWzemJMJobDcol();
	virtual ~TblWzemJMJobDcol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMJobDcol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobDcol& rst);

	virtual Sbecore::ubigint insertRec(WzemJMJobDcol* rec);
	Sbecore::ubigint insertNewRec(WzemJMJobDcol** rec = NULL, const Sbecore::ubigint refWzemMJob = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const bool Dcol = false);
	Sbecore::ubigint appendNewRecToRst(ListWzemJMJobDcol& rst, WzemJMJobDcol** rec = NULL, const Sbecore::ubigint refWzemMJob = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const bool Dcol = false);
	virtual void insertRst(ListWzemJMJobDcol& rst, bool transact = false);
	virtual void updateRec(WzemJMJobDcol* rec);
	virtual void updateRst(ListWzemJMJobDcol& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobDcol** rec);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobDcol& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMJobDcol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMJobDcol: C++ wrapper for table TblWzemJMJobDcol (MySQL database)
	*/
class MyTblWzemJMJobDcol : public TblWzemJMJobDcol, public Sbecore::MyTable {

public:
	MyTblWzemJMJobDcol();
	~MyTblWzemJMJobDcol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobDcol& rst);

	Sbecore::ubigint insertRec(WzemJMJobDcol* rec);
	void insertRst(ListWzemJMJobDcol& rst, bool transact = false);
	void updateRec(WzemJMJobDcol* rec);
	void updateRst(ListWzemJMJobDcol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobDcol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMJobDcol: C++ wrapper for table TblWzemJMJobDcol (PgSQL database)
	*/
class PgTblWzemJMJobDcol : public TblWzemJMJobDcol, public Sbecore::PgTable {

public:
	PgTblWzemJMJobDcol();
	~PgTblWzemJMJobDcol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMJobDcol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMJobDcol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobDcol& rst);

	Sbecore::ubigint insertRec(WzemJMJobDcol* rec);
	void insertRst(ListWzemJMJobDcol& rst, bool transact = false);
	void updateRec(WzemJMJobDcol* rec);
	void updateRst(ListWzemJMJobDcol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobDcol& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMJobDcol: C++ wrapper for table TblWzemJMJobDcol (SQLite database)
	*/
class LiteTblWzemJMJobDcol : public TblWzemJMJobDcol, public Sbecore::LiteTable {

public:
	LiteTblWzemJMJobDcol();
	~LiteTblWzemJMJobDcol();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByJob;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMJobDcol& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMJobDcol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMJobDcol& rst);

	Sbecore::ubigint insertRec(WzemJMJobDcol* rec);
	void insertRst(ListWzemJMJobDcol& rst, bool transact = false);
	void updateRec(WzemJMJobDcol* rec);
	void updateRst(ListWzemJMJobDcol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMJobDcol** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemJMJobDcol& rst);
};
#endif

#endif

