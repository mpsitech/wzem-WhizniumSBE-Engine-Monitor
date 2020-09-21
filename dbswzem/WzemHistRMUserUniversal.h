/**
	* \file WzemHistRMUserUniversal.h
	* database access for table TblWzemHistRMUserUniversal (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMHISTRMUSERUNIVERSAL_H
#define WZEMHISTRMUSERUNIVERSAL_H

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
	* WzemHistRMUserUniversal: record of TblWzemHistRMUserUniversal
	*/
class WzemHistRMUserUniversal {

public:
	WzemHistRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVCard = 0, const Sbecore::uint ixWzemVPreset = 0, const Sbecore::uint preIxWzemVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMUser;
	Sbecore::uint unvIxWzemVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWzemVCard;
	Sbecore::uint ixWzemVPreset;
	Sbecore::uint preIxWzemVMaintable;
	Sbecore::ubigint preUref;
	Sbecore::uint start;

public:
	bool operator==(const WzemHistRMUserUniversal& comp);
	bool operator!=(const WzemHistRMUserUniversal& comp);
};

/**
	* ListWzemHistRMUserUniversal: recordset of TblWzemHistRMUserUniversal
	*/
class ListWzemHistRMUserUniversal {

public:
	ListWzemHistRMUserUniversal();
	ListWzemHistRMUserUniversal(const ListWzemHistRMUserUniversal& src);
	~ListWzemHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WzemHistRMUserUniversal* rec);

	WzemHistRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWzemHistRMUserUniversal& operator=(const ListWzemHistRMUserUniversal& src);
	bool operator==(const ListWzemHistRMUserUniversal& comp);
	bool operator!=(const ListWzemHistRMUserUniversal& comp);

public:
	std::vector<WzemHistRMUserUniversal*> nodes;
};

/**
	* TblWzemHistRMUserUniversal: C++ wrapper for table TblWzemHistRMUserUniversal
	*/
class TblWzemHistRMUserUniversal {

public:

public:
	TblWzemHistRMUserUniversal();
	virtual ~TblWzemHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemHistRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WzemHistRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WzemHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVCard = 0, const Sbecore::uint ixWzemVPreset = 0, const Sbecore::uint preIxWzemVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemHistRMUserUniversal& rst, WzemHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWzemMUser = 0, const Sbecore::uint unvIxWzemVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWzemVCard = 0, const Sbecore::uint ixWzemVPreset = 0, const Sbecore::uint preIxWzemVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	virtual void insertRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WzemHistRMUserUniversal* rec);
	virtual void updateRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemHistRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzemVCard, WzemHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::uint ixWzemVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint ixWzemVCard, const bool append, ListWzemHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemHistRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemHistRMUserUniversal: C++ wrapper for table TblWzemHistRMUserUniversal (MySQL database)
	*/
class MyTblWzemHistRMUserUniversal : public TblWzemHistRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWzemHistRMUserUniversal();
	~MyTblWzemHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzemHistRMUserUniversal* rec);
	void insertRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WzemHistRMUserUniversal* rec);
	void updateRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzemVCard, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::uint ixWzemVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint ixWzemVCard, const bool append, ListWzemHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemHistRMUserUniversal: C++ wrapper for table TblWzemHistRMUserUniversal (PgSQL database)
	*/
class PgTblWzemHistRMUserUniversal : public TblWzemHistRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblWzemHistRMUserUniversal();
	~PgTblWzemHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemHistRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzemHistRMUserUniversal* rec);
	void insertRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WzemHistRMUserUniversal* rec);
	void updateRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzemVCard, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::uint ixWzemVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint ixWzemVCard, const bool append, ListWzemHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemHistRMUserUniversal: C++ wrapper for table TblWzemHistRMUserUniversal (SQLite database)
	*/
class LiteTblWzemHistRMUserUniversal : public TblWzemHistRMUserUniversal, public Sbecore::LiteTable {

public:
	LiteTblWzemHistRMUserUniversal();
	~LiteTblWzemHistRMUserUniversal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByUsrMtbUnvCrd;
	sqlite3_stmt* stmtLoadRefsByUsrMtbCrd;
	sqlite3_stmt* stmtLoadRstByUsrCrd;
	sqlite3_stmt* stmtLoadUnuByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemHistRMUserUniversal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WzemHistRMUserUniversal* rec);
	void insertRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WzemHistRMUserUniversal* rec);
	void updateRst(ListWzemHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWzemVCard, WzemHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint unvIxWzemVMaintable, Sbecore::uint ixWzemVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWzemMUser, Sbecore::uint ixWzemVCard, const bool append, ListWzemHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#endif

