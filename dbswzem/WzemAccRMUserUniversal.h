/**
	* \file WzemAccRMUserUniversal.h
	* database access for table TblWzemAccRMUserUniversal (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMACCRMUSERUNIVERSAL_H
#define WZEMACCRMUSERUNIVERSAL_H

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
	* WzemAccRMUserUniversal: record of TblWzemAccRMUserUniversal
	*/
class WzemAccRMUserUniversal {

public:
	WzemAccRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVRecaccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUser;
	Sbecore::uint unvIxWzemVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWzemVRecaccess;

public:
	bool operator==(const WzemAccRMUserUniversal& comp);
	bool operator!=(const WzemAccRMUserUniversal& comp);
};

/**
	* ListWzemAccRMUserUniversal: recordset of TblWzemAccRMUserUniversal
	*/
class ListWzemAccRMUserUniversal {

public:
	ListWzemAccRMUserUniversal();
	ListWzemAccRMUserUniversal(const ListWzemAccRMUserUniversal& src);
	~ListWzemAccRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WzemAccRMUserUniversal* rec);

	WzemAccRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWzemAccRMUserUniversal& operator=(const ListWzemAccRMUserUniversal& src);
	bool operator==(const ListWzemAccRMUserUniversal& comp);
	bool operator!=(const ListWzemAccRMUserUniversal& comp);

public:
	std::vector<WzemAccRMUserUniversal*> nodes;
};

/**
	* TblWzemAccRMUserUniversal: C++ wrapper for table TblWzemAccRMUserUniversal
	*/
class TblWzemAccRMUserUniversal {

public:

public:
	TblWzemAccRMUserUniversal();
	virtual ~TblWzemAccRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAccRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAccRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WzemAccRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WzemAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVRecaccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemAccRMUserUniversal& rst, WzemAccRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVRecaccess = 0);
	virtual void insertRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WzemAccRMUserUniversal* rec);
	virtual void updateRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAccRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAccRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAccRMUserUniversal: C++ wrapper for table TblWzemAccRMUserUniversal (MySQL database)
	*/
class MyTblWzemAccRMUserUniversal : public TblWzemAccRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWzemAccRMUserUniversal();
	~MyTblWzemAccRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzemAccRMUserUniversal* rec);
	void insertRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WzemAccRMUserUniversal* rec);
	void updateRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemAccRMUserUniversal** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAccRMUserUniversal: C++ wrapper for table TblWzemAccRMUserUniversal (PgSQL database)
	*/
class PgTblWzemAccRMUserUniversal : public TblWzemAccRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblWzemAccRMUserUniversal();
	~PgTblWzemAccRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAccRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAccRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzemAccRMUserUniversal* rec);
	void insertRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WzemAccRMUserUniversal* rec);
	void updateRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemAccRMUserUniversal** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAccRMUserUniversal: C++ wrapper for table TblWzemAccRMUserUniversal (SQLite database)
	*/
class LiteTblWzemAccRMUserUniversal : public TblWzemAccRMUserUniversal, public Sbecore::LiteTable {

public:
	LiteTblWzemAccRMUserUniversal();
	~LiteTblWzemAccRMUserUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrMtbUnv;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAccRMUserUniversal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAccRMUserUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAccRMUserUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAccRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAccRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzemAccRMUserUniversal* rec);
	void insertRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	void updateRec(WzemAccRMUserUniversal* rec);
	void updateRst(ListWzemAccRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAccRMUserUniversal** rec);
	bool loadRecByUsrMtbUnv(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, WzemAccRMUserUniversal** rec);
};
#endif

#endif

