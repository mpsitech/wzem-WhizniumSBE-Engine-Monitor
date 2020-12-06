/**
	* \file WzemMPreset.h
	* database access for table TblWzemMPreset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMPRESET_H
#define WZEMMPRESET_H

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
	* WzemMPreset: record of TblWzemMPreset
	*/
class WzemMPreset {

public:
	WzemMPreset(const Sbecore::ubigint ref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVPreset = "", const std::string arg = "");

public:
	Sbecore::ubigint ref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint refWzemMJob;
	std::string srefIxVPreset;
	std::string arg;

public:
	bool operator==(const WzemMPreset& comp);
	bool operator!=(const WzemMPreset& comp);
};

/**
	* ListWzemMPreset: recordset of TblWzemMPreset
	*/
class ListWzemMPreset {

public:
	ListWzemMPreset();
	ListWzemMPreset(const ListWzemMPreset& src);
	~ListWzemMPreset();

	void clear();
	unsigned int size() const;
	void append(WzemMPreset* rec);

	WzemMPreset* operator[](const Sbecore::uint ix);
	ListWzemMPreset& operator=(const ListWzemMPreset& src);
	bool operator==(const ListWzemMPreset& comp);
	bool operator!=(const ListWzemMPreset& comp);

public:
	std::vector<WzemMPreset*> nodes;
};

/**
	* TblWzemMPreset: C++ wrapper for table TblWzemMPreset
	*/
class TblWzemMPreset {

public:

public:
	TblWzemMPreset();
	virtual ~TblWzemMPreset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMPreset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPreset& rst);

	virtual Sbecore::ubigint insertRec(WzemMPreset* rec);
	Sbecore::ubigint insertNewRec(WzemMPreset** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVPreset = "", const std::string arg = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMPreset& rst, WzemMPreset** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVPreset = "", const std::string arg = "");
	virtual void insertRst(ListWzemMPreset& rst, bool transact = false);
	virtual void updateRec(WzemMPreset* rec);
	virtual void updateRst(ListWzemMPreset& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMPreset** rec);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMPreset& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMPreset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMPreset: C++ wrapper for table TblWzemMPreset (MySQL database)
	*/
class MyTblWzemMPreset : public TblWzemMPreset, public Sbecore::MyTable {

public:
	MyTblWzemMPreset();
	~MyTblWzemMPreset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPreset& rst);

	Sbecore::ubigint insertRec(WzemMPreset* rec);
	void insertRst(ListWzemMPreset& rst, bool transact = false);
	void updateRec(WzemMPreset* rec);
	void updateRst(ListWzemMPreset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPreset** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMPreset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMPreset: C++ wrapper for table TblWzemMPreset (PgSQL database)
	*/
class PgTblWzemMPreset : public TblWzemMPreset, public Sbecore::PgTable {

public:
	PgTblWzemMPreset();
	~PgTblWzemMPreset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMPreset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMPreset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMPreset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMPreset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPreset& rst);

	Sbecore::ubigint insertRec(WzemMPreset* rec);
	void insertRst(ListWzemMPreset& rst, bool transact = false);
	void updateRec(WzemMPreset* rec);
	void updateRst(ListWzemMPreset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPreset** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMPreset& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMPreset: C++ wrapper for table TblWzemMPreset (SQLite database)
	*/
class LiteTblWzemMPreset : public TblWzemMPreset, public Sbecore::LiteTable {

public:
	LiteTblWzemMPreset();
	~LiteTblWzemMPreset();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByJob;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMPreset** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMPreset& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMPreset** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMPreset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPreset& rst);

	Sbecore::ubigint insertRec(WzemMPreset* rec);
	void insertRst(ListWzemMPreset& rst, bool transact = false);
	void updateRec(WzemMPreset* rec);
	void updateRst(ListWzemMPreset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPreset** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMPreset& rst);
};
#endif

#endif

