/**
	* \file WzemAMPersonDetail.h
	* database access for table TblWzemAMPersonDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMAMPERSONDETAIL_H
#define WZEMAMPERSONDETAIL_H

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
	* WzemAMPersonDetail: record of TblWzemAMPersonDetail
	*/
class WzemAMPersonDetail {

public:
	WzemAMPersonDetail(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMPerson;
	std::string x1SrefKType;
	std::string Val;

public:
	bool operator==(const WzemAMPersonDetail& comp);
	bool operator!=(const WzemAMPersonDetail& comp);
};

/**
	* ListWzemAMPersonDetail: recordset of TblWzemAMPersonDetail
	*/
class ListWzemAMPersonDetail {

public:
	ListWzemAMPersonDetail();
	ListWzemAMPersonDetail(const ListWzemAMPersonDetail& src);
	~ListWzemAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(WzemAMPersonDetail* rec);

	WzemAMPersonDetail* operator[](const Sbecore::uint ix);
	ListWzemAMPersonDetail& operator=(const ListWzemAMPersonDetail& src);
	bool operator==(const ListWzemAMPersonDetail& comp);
	bool operator!=(const ListWzemAMPersonDetail& comp);

public:
	std::vector<WzemAMPersonDetail*> nodes;
};

/**
	* TblWzemAMPersonDetail: C++ wrapper for table TblWzemAMPersonDetail
	*/
class TblWzemAMPersonDetail {

public:

public:
	TblWzemAMPersonDetail();
	virtual ~TblWzemAMPersonDetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMPersonDetail& rst);

	virtual Sbecore::ubigint insertRec(WzemAMPersonDetail* rec);
	Sbecore::ubigint insertNewRec(WzemAMPersonDetail** rec = NULL, const Sbecore::ubigint refWzemMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemAMPersonDetail& rst, WzemAMPersonDetail** rec = NULL, const Sbecore::ubigint refWzemMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWzemAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(WzemAMPersonDetail* rec);
	virtual void updateRst(ListWzemAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAMPersonDetail** rec);
	virtual bool loadRecByPrsTyp(Sbecore::ubigint refWzemMPerson, std::string x1SrefKType, WzemAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemAMPersonDetail& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAMPersonDetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAMPersonDetail: C++ wrapper for table TblWzemAMPersonDetail (MySQL database)
	*/
class MyTblWzemAMPersonDetail : public TblWzemAMPersonDetail, public Sbecore::MyTable {

public:
	MyTblWzemAMPersonDetail();
	~MyTblWzemAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WzemAMPersonDetail* rec);
	void insertRst(ListWzemAMPersonDetail& rst, bool transact = false);
	void updateRec(WzemAMPersonDetail* rec);
	void updateRst(ListWzemAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWzemMPerson, std::string x1SrefKType, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemAMPersonDetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAMPersonDetail: C++ wrapper for table TblWzemAMPersonDetail (PgSQL database)
	*/
class PgTblWzemAMPersonDetail : public TblWzemAMPersonDetail, public Sbecore::PgTable {

public:
	PgTblWzemAMPersonDetail();
	~PgTblWzemAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAMPersonDetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemAMPersonDetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WzemAMPersonDetail* rec);
	void insertRst(ListWzemAMPersonDetail& rst, bool transact = false);
	void updateRec(WzemAMPersonDetail* rec);
	void updateRst(ListWzemAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWzemMPerson, std::string x1SrefKType, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemAMPersonDetail& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAMPersonDetail: C++ wrapper for table TblWzemAMPersonDetail (SQLite database)
	*/
class LiteTblWzemAMPersonDetail : public TblWzemAMPersonDetail, public Sbecore::LiteTable {

public:
	LiteTblWzemAMPersonDetail();
	~LiteTblWzemAMPersonDetail();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrsTyp;
	sqlite3_stmt* stmtLoadRstByPrs;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAMPersonDetail& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemAMPersonDetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WzemAMPersonDetail* rec);
	void insertRst(ListWzemAMPersonDetail& rst, bool transact = false);
	void updateRec(WzemAMPersonDetail* rec);
	void updateRst(ListWzemAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMPersonDetail** rec);
	bool loadRecByPrsTyp(Sbecore::ubigint refWzemMPerson, std::string x1SrefKType, WzemAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemAMPersonDetail& rst);
};
#endif

#endif

