/**
	* \file WzemAVKeylistKey.h
	* database access for table TblWzemAVKeylistKey (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMAVKEYLISTKEY_H
#define WZEMAVKEYLISTKEY_H

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
	* WzemAVKeylistKey: record of TblWzemAVKeylistKey
	*/
class WzemAVKeylistKey {

public:
	WzemAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::uint klsIxWzemVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWzemVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint klsIxWzemVKeylist;
	Sbecore::uint klsNum;
	Sbecore::uint x1IxWzemVMaintable;
	Sbecore::ubigint x1Uref;
	bool Fixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WzemAVKeylistKey& comp);
	bool operator!=(const WzemAVKeylistKey& comp);
};

/**
	* ListWzemAVKeylistKey: recordset of TblWzemAVKeylistKey
	*/
class ListWzemAVKeylistKey {

public:
	ListWzemAVKeylistKey();
	ListWzemAVKeylistKey(const ListWzemAVKeylistKey& src);
	~ListWzemAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WzemAVKeylistKey* rec);

	WzemAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWzemAVKeylistKey& operator=(const ListWzemAVKeylistKey& src);
	bool operator==(const ListWzemAVKeylistKey& comp);
	bool operator!=(const ListWzemAVKeylistKey& comp);

public:
	std::vector<WzemAVKeylistKey*> nodes;
};

/**
	* TblWzemAVKeylistKey: C++ wrapper for table TblWzemAVKeylistKey
	*/
class TblWzemAVKeylistKey {

public:

public:
	TblWzemAVKeylistKey();
	virtual ~TblWzemAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WzemAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WzemAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWzemVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWzemVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemAVKeylistKey& rst, WzemAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWzemVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWzemVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWzemAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WzemAVKeylistKey* rec);
	virtual void updateRst(ListWzemAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	virtual bool loadRefByKlsSrf(Sbecore::uint klsIxWzemVKeylist, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzemVKeylist, const bool append, ListWzemAVKeylistKey& rst);
	virtual Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzemAVKeylistKey& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAVKeylistKey: C++ wrapper for table TblWzemAVKeylistKey (MySQL database)
	*/
class MyTblWzemAVKeylistKey : public TblWzemAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWzemAVKeylistKey();
	~MyTblWzemAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzemAVKeylistKey* rec);
	void insertRst(ListWzemAVKeylistKey& rst, bool transact = false);
	void updateRec(WzemAVKeylistKey* rec);
	void updateRst(ListWzemAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWzemVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzemVKeylist, const bool append, ListWzemAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzemAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAVKeylistKey: C++ wrapper for table TblWzemAVKeylistKey (PgSQL database)
	*/
class PgTblWzemAVKeylistKey : public TblWzemAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblWzemAVKeylistKey();
	~PgTblWzemAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzemAVKeylistKey* rec);
	void insertRst(ListWzemAVKeylistKey& rst, bool transact = false);
	void updateRec(WzemAVKeylistKey* rec);
	void updateRst(ListWzemAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWzemVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzemVKeylist, const bool append, ListWzemAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzemAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAVKeylistKey: C++ wrapper for table TblWzemAVKeylistKey (SQLite database)
	*/
class LiteTblWzemAVKeylistKey : public TblWzemAVKeylistKey, public Sbecore::LiteTable {

public:
	LiteTblWzemAVKeylistKey();
	~LiteTblWzemAVKeylistKey();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefByKlsMtbUrfSrf;
	sqlite3_stmt* stmtLoadRefByKlsSrf;
	sqlite3_stmt* stmtLoadRstByKls;
	sqlite3_stmt* stmtLoadRstByKlsMtbUrf;
	sqlite3_stmt* stmtLoadTitByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAVKeylistKey& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzemAVKeylistKey* rec);
	void insertRst(ListWzemAVKeylistKey& rst, bool transact = false);
	void updateRec(WzemAVKeylistKey* rec);
	void updateRst(ListWzemAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWzemVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWzemVKeylist, const bool append, ListWzemAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWzemVKeylist, Sbecore::uint x1IxWzemVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWzemAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

