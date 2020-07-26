/**
	* \file WzemAMUsergroupAccess.h
	* database access for table TblWzemAMUsergroupAccess (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMAMUSERGROUPACCESS_H
#define WZEMAMUSERGROUPACCESS_H

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
	* WzemAMUsergroupAccess: record of TblWzemAMUsergroupAccess
	*/
class WzemAMUsergroupAccess {

public:
	WzemAMUsergroupAccess(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUsergroup;
	Sbecore::uint x1IxWzemVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWzemWAccess;

public:
	bool operator==(const WzemAMUsergroupAccess& comp);
	bool operator!=(const WzemAMUsergroupAccess& comp);
};

/**
	* ListWzemAMUsergroupAccess: recordset of TblWzemAMUsergroupAccess
	*/
class ListWzemAMUsergroupAccess {

public:
	ListWzemAMUsergroupAccess();
	ListWzemAMUsergroupAccess(const ListWzemAMUsergroupAccess& src);
	~ListWzemAMUsergroupAccess();

	void clear();
	unsigned int size() const;
	void append(WzemAMUsergroupAccess* rec);

	WzemAMUsergroupAccess* operator[](const Sbecore::uint ix);
	ListWzemAMUsergroupAccess& operator=(const ListWzemAMUsergroupAccess& src);
	bool operator==(const ListWzemAMUsergroupAccess& comp);
	bool operator!=(const ListWzemAMUsergroupAccess& comp);

public:
	std::vector<WzemAMUsergroupAccess*> nodes;
};

/**
	* TblWzemAMUsergroupAccess: C++ wrapper for table TblWzemAMUsergroupAccess
	*/
class TblWzemAMUsergroupAccess {

public:

public:
	TblWzemAMUsergroupAccess();
	virtual ~TblWzemAMUsergroupAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUsergroupAccess& rst);

	virtual Sbecore::ubigint insertRec(WzemAMUsergroupAccess* rec);
	Sbecore::ubigint insertNewRec(WzemAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemAMUsergroupAccess& rst, WzemAMUsergroupAccess** rec = NULL, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);
	virtual void insertRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	virtual void updateRec(WzemAMUsergroupAccess* rec);
	virtual void updateRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAMUsergroupAccess** rec);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemAMUsergroupAccess& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAMUsergroupAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAMUsergroupAccess: C++ wrapper for table TblWzemAMUsergroupAccess (MySQL database)
	*/
class MyTblWzemAMUsergroupAccess : public TblWzemAMUsergroupAccess, public Sbecore::MyTable {

public:
	MyTblWzemAMUsergroupAccess();
	~MyTblWzemAMUsergroupAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WzemAMUsergroupAccess* rec);
	void insertRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WzemAMUsergroupAccess* rec);
	void updateRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemAMUsergroupAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAMUsergroupAccess: C++ wrapper for table TblWzemAMUsergroupAccess (PgSQL database)
	*/
class PgTblWzemAMUsergroupAccess : public TblWzemAMUsergroupAccess, public Sbecore::PgTable {

public:
	PgTblWzemAMUsergroupAccess();
	~PgTblWzemAMUsergroupAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAMUsergroupAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WzemAMUsergroupAccess* rec);
	void insertRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WzemAMUsergroupAccess* rec);
	void updateRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemAMUsergroupAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAMUsergroupAccess: C++ wrapper for table TblWzemAMUsergroupAccess (SQLite database)
	*/
class LiteTblWzemAMUsergroupAccess : public TblWzemAMUsergroupAccess, public Sbecore::LiteTable {

public:
	LiteTblWzemAMUsergroupAccess();
	~LiteTblWzemAMUsergroupAccess();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByUsg;
	sqlite3_stmt* stmtLoadRstByUsg;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAMUsergroupAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemAMUsergroupAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAMUsergroupAccess& rst);

	Sbecore::ubigint insertRec(WzemAMUsergroupAccess* rec);
	void insertRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	void updateRec(WzemAMUsergroupAccess* rec);
	void updateRst(ListWzemAMUsergroupAccess& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAMUsergroupAccess** rec);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, ListWzemAMUsergroupAccess& rst);
};
#endif

#endif

