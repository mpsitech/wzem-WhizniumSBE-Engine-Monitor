/**
	* \file WzemJAVKeylistKey.h
	* database access for table TblWzemJAVKeylistKey (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMJAVKEYLISTKEY_H
#define WZEMJAVKEYLISTKEY_H

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
	* WzemJAVKeylistKey: record of TblWzemJAVKeylistKey
	*/
class WzemJAVKeylistKey {

public:
	WzemJAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemAVKeylistKey = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemAVKeylistKey;
	Sbecore::uint x1IxWzemVLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WzemJAVKeylistKey& comp);
	bool operator!=(const WzemJAVKeylistKey& comp);
};

/**
	* ListWzemJAVKeylistKey: recordset of TblWzemJAVKeylistKey
	*/
class ListWzemJAVKeylistKey {

public:
	ListWzemJAVKeylistKey();
	ListWzemJAVKeylistKey(const ListWzemJAVKeylistKey& src);
	~ListWzemJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WzemJAVKeylistKey* rec);

	WzemJAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWzemJAVKeylistKey& operator=(const ListWzemJAVKeylistKey& src);
	bool operator==(const ListWzemJAVKeylistKey& comp);
	bool operator!=(const ListWzemJAVKeylistKey& comp);

public:
	std::vector<WzemJAVKeylistKey*> nodes;
};

/**
	* TblWzemJAVKeylistKey: C++ wrapper for table TblWzemJAVKeylistKey
	*/
class TblWzemJAVKeylistKey {

public:

public:
	TblWzemJAVKeylistKey();
	virtual ~TblWzemJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WzemJAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WzemJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWzemAVKeylistKey = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemJAVKeylistKey& rst, WzemJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWzemAVKeylistKey = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WzemJAVKeylistKey* rec);
	virtual void updateRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, WzemJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, ListWzemJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJAVKeylistKey: C++ wrapper for table TblWzemJAVKeylistKey (MySQL database)
	*/
class MyTblWzemJAVKeylistKey : public TblWzemJAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWzemJAVKeylistKey();
	~MyTblWzemJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzemJAVKeylistKey* rec);
	void insertRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	void updateRec(WzemJAVKeylistKey* rec);
	void updateRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, ListWzemJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJAVKeylistKey: C++ wrapper for table TblWzemJAVKeylistKey (PgSQL database)
	*/
class PgTblWzemJAVKeylistKey : public TblWzemJAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblWzemJAVKeylistKey();
	~PgTblWzemJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzemJAVKeylistKey* rec);
	void insertRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	void updateRec(WzemJAVKeylistKey* rec);
	void updateRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, ListWzemJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, std::string& Title);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJAVKeylistKey: C++ wrapper for table TblWzemJAVKeylistKey (SQLite database)
	*/
class LiteTblWzemJAVKeylistKey : public TblWzemJAVKeylistKey, public Sbecore::LiteTable {

public:
	LiteTblWzemJAVKeylistKey();
	~LiteTblWzemJAVKeylistKey();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByKlkLcl;
	sqlite3_stmt* stmtLoadRefsByKlk;
	sqlite3_stmt* stmtLoadRstByKlk;
	sqlite3_stmt* stmtLoadTitByKlkLcl;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJAVKeylistKey& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WzemJAVKeylistKey* rec);
	void insertRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	void updateRec(WzemJAVKeylistKey* rec);
	void updateRst(ListWzemJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, WzemJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWzemAVKeylistKey, const bool append, ListWzemJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWzemAVKeylistKey, Sbecore::uint x1IxWzemVLocale, std::string& Title);
};
#endif

#endif

