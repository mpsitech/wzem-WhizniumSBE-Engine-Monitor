/**
	* \file WzemRMUsergroupUniversal.h
	* database access for table TblWzemRMUsergroupUniversal (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMRMUSERGROUPUNIVERSAL_H
#define WZEMRMUSERGROUPUNIVERSAL_H

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
	* WzemRMUsergroupUniversal: record of TblWzemRMUsergroupUniversal
	*/
class WzemRMUsergroupUniversal {

public:
	WzemRMUsergroupUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUsergroup;
	Sbecore::uint unvIxWzemVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWzemVRecaccess;

public:
	bool operator==(const WzemRMUsergroupUniversal& comp);
	bool operator!=(const WzemRMUsergroupUniversal& comp);
};

/**
	* ListWzemRMUsergroupUniversal: recordset of TblWzemRMUsergroupUniversal
	*/
class ListWzemRMUsergroupUniversal {

public:
	ListWzemRMUsergroupUniversal();
	ListWzemRMUsergroupUniversal(const ListWzemRMUsergroupUniversal& src);
	~ListWzemRMUsergroupUniversal();

	void clear();
	unsigned int size() const;
	void append(WzemRMUsergroupUniversal* rec);

	WzemRMUsergroupUniversal* operator[](const Sbecore::uint ix);
	ListWzemRMUsergroupUniversal& operator=(const ListWzemRMUsergroupUniversal& src);
	bool operator==(const ListWzemRMUsergroupUniversal& comp);
	bool operator!=(const ListWzemRMUsergroupUniversal& comp);

public:
	std::vector<WzemRMUsergroupUniversal*> nodes;
};

/**
	* TblWzemRMUsergroupUniversal: C++ wrapper for table TblWzemRMUsergroupUniversal
	*/
class TblWzemRMUsergroupUniversal {

public:

public:
	TblWzemRMUsergroupUniversal();
	virtual ~TblWzemRMUsergroupUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemRMUsergroupUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUsergroupUniversal& rst);

	virtual Sbecore::ubigint insertRec(WzemRMUsergroupUniversal* rec);
	Sbecore::ubigint insertNewRec(WzemRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemRMUsergroupUniversal& rst, WzemRMUsergroupUniversal** rec = NULL, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVRecaccess = 0);
	virtual void insertRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	virtual void updateRec(WzemRMUsergroupUniversal* rec);
	virtual void updateRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemRMUsergroupUniversal** rec);
	virtual bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzemMUsergroup, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemRMUsergroupUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemRMUsergroupUniversal: C++ wrapper for table TblWzemRMUsergroupUniversal (MySQL database)
	*/
class MyTblWzemRMUsergroupUniversal : public TblWzemRMUsergroupUniversal, public Sbecore::MyTable {

public:
	MyTblWzemRMUsergroupUniversal();
	~MyTblWzemRMUsergroupUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WzemRMUsergroupUniversal* rec);
	void insertRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WzemRMUsergroupUniversal* rec);
	void updateRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzemMUsergroup, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemRMUsergroupUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemRMUsergroupUniversal: C++ wrapper for table TblWzemRMUsergroupUniversal (PgSQL database)
	*/
class PgTblWzemRMUsergroupUniversal : public TblWzemRMUsergroupUniversal, public Sbecore::PgTable {

public:
	PgTblWzemRMUsergroupUniversal();
	~PgTblWzemRMUsergroupUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemRMUsergroupUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WzemRMUsergroupUniversal* rec);
	void insertRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WzemRMUsergroupUniversal* rec);
	void updateRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzemMUsergroup, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemRMUsergroupUniversal** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemRMUsergroupUniversal: C++ wrapper for table TblWzemRMUsergroupUniversal (SQLite database)
	*/
class LiteTblWzemRMUsergroupUniversal : public TblWzemRMUsergroupUniversal, public Sbecore::LiteTable {

public:
	LiteTblWzemRMUsergroupUniversal();
	~LiteTblWzemRMUsergroupUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsgMtbUnv;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemRMUsergroupUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemRMUsergroupUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemRMUsergroupUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemRMUsergroupUniversal& rst);

	Sbecore::ubigint insertRec(WzemRMUsergroupUniversal* rec);
	void insertRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	void updateRec(WzemRMUsergroupUniversal* rec);
	void updateRst(ListWzemRMUsergroupUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemRMUsergroupUniversal** rec);
	bool loadRecByUsgMtbUnv(Sbecore::ubigint refWzemMUsergroup, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemRMUsergroupUniversal** rec);
};
#endif

#endif

