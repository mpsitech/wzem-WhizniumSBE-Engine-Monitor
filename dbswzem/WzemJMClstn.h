/**
	* \file WzemJMClstn.h
	* database access for table TblWzemJMClstn (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMJMCLSTN_H
#define WZEMJMCLSTN_H

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
	* WzemJMClstn: record of TblWzemJMClstn
	*/
class WzemJMClstn {

public:
	WzemJMClstn(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMClstn = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string argMask = "", const Sbecore::uint ixVJactype = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMClstn;
	double x1Startu;
	double x1Stopu;
	std::string argMask;
	Sbecore::uint ixVJactype;

public:
	bool operator==(const WzemJMClstn& comp);
	bool operator!=(const WzemJMClstn& comp);
};

/**
	* ListWzemJMClstn: recordset of TblWzemJMClstn
	*/
class ListWzemJMClstn {

public:
	ListWzemJMClstn();
	ListWzemJMClstn(const ListWzemJMClstn& src);
	~ListWzemJMClstn();

	void clear();
	unsigned int size() const;
	void append(WzemJMClstn* rec);

	WzemJMClstn* operator[](const Sbecore::uint ix);
	ListWzemJMClstn& operator=(const ListWzemJMClstn& src);
	bool operator==(const ListWzemJMClstn& comp);
	bool operator!=(const ListWzemJMClstn& comp);

public:
	std::vector<WzemJMClstn*> nodes;
};

/**
	* TblWzemJMClstn: C++ wrapper for table TblWzemJMClstn
	*/
class TblWzemJMClstn {

public:

public:
	TblWzemJMClstn();
	virtual ~TblWzemJMClstn();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMClstn** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMClstn& rst);

	virtual Sbecore::ubigint insertRec(WzemJMClstn* rec);
	Sbecore::ubigint insertNewRec(WzemJMClstn** rec = NULL, const Sbecore::ubigint refWzemMClstn = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string argMask = "", const Sbecore::uint ixVJactype = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemJMClstn& rst, WzemJMClstn** rec = NULL, const Sbecore::ubigint refWzemMClstn = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string argMask = "", const Sbecore::uint ixVJactype = 0);
	virtual void insertRst(ListWzemJMClstn& rst, bool transact = false);
	virtual void updateRec(WzemJMClstn* rec);
	virtual void updateRst(ListWzemJMClstn& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMClstn** rec);
	virtual Sbecore::ubigint loadRstByCln(Sbecore::ubigint refWzemMClstn, const bool append, ListWzemJMClstn& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMClstn& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMClstn: C++ wrapper for table TblWzemJMClstn (MySQL database)
	*/
class MyTblWzemJMClstn : public TblWzemJMClstn, public Sbecore::MyTable {

public:
	MyTblWzemJMClstn();
	~MyTblWzemJMClstn();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMClstn& rst);

	Sbecore::ubigint insertRec(WzemJMClstn* rec);
	void insertRst(ListWzemJMClstn& rst, bool transact = false);
	void updateRec(WzemJMClstn* rec);
	void updateRst(ListWzemJMClstn& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMClstn** rec);
	Sbecore::ubigint loadRstByCln(Sbecore::ubigint refWzemMClstn, const bool append, ListWzemJMClstn& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMClstn: C++ wrapper for table TblWzemJMClstn (PgSQL database)
	*/
class PgTblWzemJMClstn : public TblWzemJMClstn, public Sbecore::PgTable {

public:
	PgTblWzemJMClstn();
	~PgTblWzemJMClstn();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMClstn** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMClstn& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMClstn** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMClstn& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMClstn& rst);

	Sbecore::ubigint insertRec(WzemJMClstn* rec);
	void insertRst(ListWzemJMClstn& rst, bool transact = false);
	void updateRec(WzemJMClstn* rec);
	void updateRst(ListWzemJMClstn& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMClstn** rec);
	Sbecore::ubigint loadRstByCln(Sbecore::ubigint refWzemMClstn, const bool append, ListWzemJMClstn& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMClstn: C++ wrapper for table TblWzemJMClstn (SQLite database)
	*/
class LiteTblWzemJMClstn : public TblWzemJMClstn, public Sbecore::LiteTable {

public:
	LiteTblWzemJMClstn();
	~LiteTblWzemJMClstn();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByCln;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMClstn** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMClstn& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMClstn** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMClstn& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMClstn& rst);

	Sbecore::ubigint insertRec(WzemJMClstn* rec);
	void insertRst(ListWzemJMClstn& rst, bool transact = false);
	void updateRec(WzemJMClstn* rec);
	void updateRst(ListWzemJMClstn& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMClstn** rec);
	Sbecore::ubigint loadRstByCln(Sbecore::ubigint refWzemMClstn, const bool append, ListWzemJMClstn& rst);
};
#endif

#endif

