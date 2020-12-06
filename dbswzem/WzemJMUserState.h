/**
	* \file WzemJMUserState.h
	* database access for table TblWzemJMUserState (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMJMUSERSTATE_H
#define WZEMJMUSERSTATE_H

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
	* WzemJMUserState: record of TblWzemJMUserState
	*/
class WzemJMUserState {

public:
	WzemJMUserState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUser;
	Sbecore::uint x1Start;
	Sbecore::uint ixVState;

public:
	bool operator==(const WzemJMUserState& comp);
	bool operator!=(const WzemJMUserState& comp);
};

/**
	* ListWzemJMUserState: recordset of TblWzemJMUserState
	*/
class ListWzemJMUserState {

public:
	ListWzemJMUserState();
	ListWzemJMUserState(const ListWzemJMUserState& src);
	~ListWzemJMUserState();

	void clear();
	unsigned int size() const;
	void append(WzemJMUserState* rec);

	WzemJMUserState* operator[](const Sbecore::uint ix);
	ListWzemJMUserState& operator=(const ListWzemJMUserState& src);
	bool operator==(const ListWzemJMUserState& comp);
	bool operator!=(const ListWzemJMUserState& comp);

public:
	std::vector<WzemJMUserState*> nodes;
};

/**
	* TblWzemJMUserState: C++ wrapper for table TblWzemJMUserState
	*/
class TblWzemJMUserState {

public:

public:
	TblWzemJMUserState();
	virtual ~TblWzemJMUserState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMUserState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMUserState& rst);

	virtual Sbecore::ubigint insertRec(WzemJMUserState* rec);
	Sbecore::ubigint insertNewRec(WzemJMUserState** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemJMUserState& rst, WzemJMUserState** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint x1Start = 0, const Sbecore::uint ixVState = 0);
	virtual void insertRst(ListWzemJMUserState& rst, bool transact = false);
	virtual void updateRec(WzemJMUserState* rec);
	virtual void updateRst(ListWzemJMUserState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMUserState** rec);
	virtual bool loadRecByUsrSta(Sbecore::ubigint refWzemMUser, Sbecore::uint x1Start, WzemJMUserState** rec);
	virtual Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemJMUserState& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMUserState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMUserState: C++ wrapper for table TblWzemJMUserState (MySQL database)
	*/
class MyTblWzemJMUserState : public TblWzemJMUserState, public Sbecore::MyTable {

public:
	MyTblWzemJMUserState();
	~MyTblWzemJMUserState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMUserState& rst);

	Sbecore::ubigint insertRec(WzemJMUserState* rec);
	void insertRst(ListWzemJMUserState& rst, bool transact = false);
	void updateRec(WzemJMUserState* rec);
	void updateRst(ListWzemJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWzemMUser, Sbecore::uint x1Start, WzemJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemJMUserState& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMUserState: C++ wrapper for table TblWzemJMUserState (PgSQL database)
	*/
class PgTblWzemJMUserState : public TblWzemJMUserState, public Sbecore::PgTable {

public:
	PgTblWzemJMUserState();
	~PgTblWzemJMUserState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMUserState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMUserState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMUserState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMUserState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMUserState& rst);

	Sbecore::ubigint insertRec(WzemJMUserState* rec);
	void insertRst(ListWzemJMUserState& rst, bool transact = false);
	void updateRec(WzemJMUserState* rec);
	void updateRst(ListWzemJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWzemMUser, Sbecore::uint x1Start, WzemJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemJMUserState& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMUserState: C++ wrapper for table TblWzemJMUserState (SQLite database)
	*/
class LiteTblWzemJMUserState : public TblWzemJMUserState, public Sbecore::LiteTable {

public:
	LiteTblWzemJMUserState();
	~LiteTblWzemJMUserState();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrSta;
	sqlite3_stmt* stmtLoadRefsByUsr;
	sqlite3_stmt* stmtLoadRstByUsr;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMUserState** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMUserState& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMUserState** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMUserState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMUserState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMUserState& rst);

	Sbecore::ubigint insertRec(WzemJMUserState* rec);
	void insertRst(ListWzemJMUserState& rst, bool transact = false);
	void updateRec(WzemJMUserState* rec);
	void updateRst(ListWzemJMUserState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMUserState** rec);
	bool loadRecByUsrSta(Sbecore::ubigint refWzemMUser, Sbecore::uint x1Start, WzemJMUserState** rec);
	Sbecore::ubigint loadRefsByUsr(Sbecore::ubigint refWzemMUser, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByUsr(Sbecore::ubigint refWzemMUser, const bool append, ListWzemJMUserState& rst);
};
#endif

#endif
