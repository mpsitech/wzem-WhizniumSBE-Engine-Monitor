/**
	* \file WzemRMUserMUsergroup.h
	* database access for table TblWzemRMUserMUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMRMUSERMUSERGROUP_H
#define WZEMRMUSERMUSERGROUP_H

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
	* WzemRMUserMUsergroup: record of TblWzemRMUserMUsergroup
	*/
class WzemRMUserMUsergroup {

public:
	WzemRMUserMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint ixWzemVUserlevel = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUser;
	Sbecore::ubigint refWzemMUsergroup;
	Sbecore::uint ixWzemVUserlevel;

public:
	bool operator==(const WzemRMUserMUsergroup& comp);
	bool operator!=(const WzemRMUserMUsergroup& comp);
};

/**
	* ListWzemRMUserMUsergroup: recordset of TblWzemRMUserMUsergroup
	*/
class ListWzemRMUserMUsergroup {

public:
	ListWzemRMUserMUsergroup();
	ListWzemRMUserMUsergroup(const ListWzemRMUserMUsergroup& src);
	~ListWzemRMUserMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WzemRMUserMUsergroup* rec);

	WzemRMUserMUsergroup* operator[](const Sbecore::uint ix);
	ListWzemRMUserMUsergroup& operator=(const ListWzemRMUserMUsergroup& src);
	bool operator==(const ListWzemRMUserMUsergroup& comp);
	bool operator!=(const ListWzemRMUserMUsergroup& comp);

public:
	std::vector<WzemRMUserMUsergroup*> nodes;
};

/**
	* TblWzemRMUserMUsergroup: C++ wrapper for table TblWzemRMUserMUsergroup
	*/
class TblWzemRMUserMUsergroup {

public:

public:
	TblWzemRMUserMUsergroup();
	virtual ~TblWzemRMUserMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUserMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WzemRMUserMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WzemRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint ixWzemVUserlevel = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemRMUserMUsergroup& rst, WzemRMUserMUsergroup** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint ixWzemVUserlevel = 0);
	virtual void insertRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	virtual void updateRec(WzemRMUserMUsergroup* rec);
	virtual void updateRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemRMUserMUsergroup** rec);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemRMUserMUsergroup& rst);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemRMUserMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemRMUserMUsergroup: C++ wrapper for table TblWzemRMUserMUsergroup (MySQL database)
	*/
class MyTblWzemRMUserMUsergroup : public TblWzemRMUserMUsergroup, public Sbecore::MyTable {

public:
	MyTblWzemRMUserMUsergroup();
	~MyTblWzemRMUserMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WzemRMUserMUsergroup* rec);
	void insertRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WzemRMUserMUsergroup* rec);
	void updateRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemRMUserMUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemRMUserMUsergroup: C++ wrapper for table TblWzemRMUserMUsergroup (PgSQL database)
	*/
class PgTblWzemRMUserMUsergroup : public TblWzemRMUserMUsergroup, public Sbecore::PgTable {

public:
	PgTblWzemRMUserMUsergroup();
	~PgTblWzemRMUserMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemRMUserMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WzemRMUserMUsergroup* rec);
	void insertRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WzemRMUserMUsergroup* rec);
	void updateRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemRMUserMUsergroup& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemRMUserMUsergroup: C++ wrapper for table TblWzemRMUserMUsergroup (SQLite database)
	*/
class LiteTblWzemRMUserMUsergroup : public TblWzemRMUserMUsergroup, public Sbecore::LiteTable {

public:
	LiteTblWzemRMUserMUsergroup();
	~LiteTblWzemRMUserMUsergroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByUsg;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemRMUserMUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemRMUserMUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUserMUsergroup& rst);

	Sbecore::ubigint insertRec(WzemRMUserMUsergroup* rec);
	void insertRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	void updateRec(WzemRMUserMUsergroup* rec);
	void updateRst(ListWzemRMUserMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemRMUserMUsergroup** rec);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemRMUserMUsergroup& rst);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemRMUserMUsergroup& rst);
};
#endif

#endif

