/**
	* \file WzemMCall.h
	* database access for table TblWzemMCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMCALL_H
#define WZEMMCALL_H

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
	* WzemMCall: record of TblWzemMCall
	*/
class WzemMCall {

public:
	WzemMCall(const Sbecore::ubigint ref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVCall = "", const std::string argInv = "", const std::string argRet = "");

public:
	Sbecore::ubigint ref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint refWzemMJob;
	std::string srefIxVCall;
	std::string argInv;
	std::string argRet;

public:
	bool operator==(const WzemMCall& comp);
	bool operator!=(const WzemMCall& comp);
};

/**
	* ListWzemMCall: recordset of TblWzemMCall
	*/
class ListWzemMCall {

public:
	ListWzemMCall();
	ListWzemMCall(const ListWzemMCall& src);
	~ListWzemMCall();

	void clear();
	unsigned int size() const;
	void append(WzemMCall* rec);

	WzemMCall* operator[](const Sbecore::uint ix);
	ListWzemMCall& operator=(const ListWzemMCall& src);
	bool operator==(const ListWzemMCall& comp);
	bool operator!=(const ListWzemMCall& comp);

public:
	std::vector<WzemMCall*> nodes;
};

/**
	* TblWzemMCall: C++ wrapper for table TblWzemMCall
	*/
class TblWzemMCall {

public:

public:
	TblWzemMCall();
	virtual ~TblWzemMCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMCall& rst);

	virtual Sbecore::ubigint insertRec(WzemMCall* rec);
	Sbecore::ubigint insertNewRec(WzemMCall** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVCall = "", const std::string argInv = "", const std::string argRet = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMCall& rst, WzemMCall** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVCall = "", const std::string argInv = "", const std::string argRet = "");
	virtual void insertRst(ListWzemMCall& rst, bool transact = false);
	virtual void updateRec(WzemMCall* rec);
	virtual void updateRst(ListWzemMCall& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMCall** rec);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMCall& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMCall: C++ wrapper for table TblWzemMCall (MySQL database)
	*/
class MyTblWzemMCall : public TblWzemMCall, public Sbecore::MyTable {

public:
	MyTblWzemMCall();
	~MyTblWzemMCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMCall& rst);

	Sbecore::ubigint insertRec(WzemMCall* rec);
	void insertRst(ListWzemMCall& rst, bool transact = false);
	void updateRec(WzemMCall* rec);
	void updateRst(ListWzemMCall& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMCall** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMCall& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMCall: C++ wrapper for table TblWzemMCall (PgSQL database)
	*/
class PgTblWzemMCall : public TblWzemMCall, public Sbecore::PgTable {

public:
	PgTblWzemMCall();
	~PgTblWzemMCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMCall& rst);

	Sbecore::ubigint insertRec(WzemMCall* rec);
	void insertRst(ListWzemMCall& rst, bool transact = false);
	void updateRec(WzemMCall* rec);
	void updateRst(ListWzemMCall& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMCall** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMCall& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMCall: C++ wrapper for table TblWzemMCall (SQLite database)
	*/
class LiteTblWzemMCall : public TblWzemMCall, public Sbecore::LiteTable {

public:
	LiteTblWzemMCall();
	~LiteTblWzemMCall();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByJob;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMCall** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMCall& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMCall** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMCall& rst);

	Sbecore::ubigint insertRec(WzemMCall* rec);
	void insertRst(ListWzemMCall& rst, bool transact = false);
	void updateRec(WzemMCall* rec);
	void updateRst(ListWzemMCall& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMCall** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMCall& rst);
};
#endif

#endif

