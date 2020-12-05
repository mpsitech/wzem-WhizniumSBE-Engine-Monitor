/**
	* \file WzemMOp.h
	* database access for table TblWzemMOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMOP_H
#define WZEMMOP_H

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
	* WzemMOp: record of TblWzemMOp
	*/
class WzemMOp {

public:
	WzemMOp(const Sbecore::ubigint ref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const Sbecore::ubigint xoref = 0);

public:
	Sbecore::ubigint ref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint refWzemMJob;
	Sbecore::ubigint xoref;

public:
	bool operator==(const WzemMOp& comp);
	bool operator!=(const WzemMOp& comp);
};

/**
	* ListWzemMOp: recordset of TblWzemMOp
	*/
class ListWzemMOp {

public:
	ListWzemMOp();
	ListWzemMOp(const ListWzemMOp& src);
	~ListWzemMOp();

	void clear();
	unsigned int size() const;
	void append(WzemMOp* rec);

	WzemMOp* operator[](const Sbecore::uint ix);
	ListWzemMOp& operator=(const ListWzemMOp& src);
	bool operator==(const ListWzemMOp& comp);
	bool operator!=(const ListWzemMOp& comp);

public:
	std::vector<WzemMOp*> nodes;
};

/**
	* TblWzemMOp: C++ wrapper for table TblWzemMOp
	*/
class TblWzemMOp {

public:

public:
	TblWzemMOp();
	virtual ~TblWzemMOp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMOp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMOp& rst);

	virtual Sbecore::ubigint insertRec(WzemMOp* rec);
	Sbecore::ubigint insertNewRec(WzemMOp** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const Sbecore::ubigint xoref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemMOp& rst, WzemMOp** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const Sbecore::ubigint xoref = 0);
	virtual void insertRst(ListWzemMOp& rst, bool transact = false);
	virtual void updateRec(WzemMOp* rec);
	virtual void updateRst(ListWzemMOp& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMOp** rec);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMOp& rst);
	virtual bool loadXorByRef(Sbecore::ubigint ref, std::string& xoref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMOp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMOp: C++ wrapper for table TblWzemMOp (MySQL database)
	*/
class MyTblWzemMOp : public TblWzemMOp, public Sbecore::MyTable {

public:
	MyTblWzemMOp();
	~MyTblWzemMOp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMOp& rst);

	Sbecore::ubigint insertRec(WzemMOp* rec);
	void insertRst(ListWzemMOp& rst, bool transact = false);
	void updateRec(WzemMOp* rec);
	void updateRst(ListWzemMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMOp** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMOp& rst);
	bool loadXorByRef(Sbecore::ubigint ref, std::string& xoref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMOp: C++ wrapper for table TblWzemMOp (PgSQL database)
	*/
class PgTblWzemMOp : public TblWzemMOp, public Sbecore::PgTable {

public:
	PgTblWzemMOp();
	~PgTblWzemMOp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMOp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMOp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMOp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMOp& rst);

	Sbecore::ubigint insertRec(WzemMOp* rec);
	void insertRst(ListWzemMOp& rst, bool transact = false);
	void updateRec(WzemMOp* rec);
	void updateRst(ListWzemMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMOp** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMOp& rst);
	bool loadXorByRef(Sbecore::ubigint ref, std::string& xoref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMOp: C++ wrapper for table TblWzemMOp (SQLite database)
	*/
class LiteTblWzemMOp : public TblWzemMOp, public Sbecore::LiteTable {

public:
	LiteTblWzemMOp();
	~LiteTblWzemMOp();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByJob;
	sqlite3_stmt* stmtLoadXorByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMOp** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMOp& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMOp** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMOp& rst);

	Sbecore::ubigint insertRec(WzemMOp* rec);
	void insertRst(ListWzemMOp& rst, bool transact = false);
	void updateRec(WzemMOp* rec);
	void updateRst(ListWzemMOp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMOp** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMOp& rst);
	bool loadXorByRef(Sbecore::ubigint ref, std::string& xoref);
};
#endif

#endif

