/**
	* \file WzemMPeriod.h
	* database access for table TblWzemMPeriod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMPERIOD_H
#define WZEMMPERIOD_H

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
	* WzemMPeriod: record of TblWzemMPeriod
	*/
class WzemMPeriod {

public:
	WzemMPeriod(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string Version = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	std::string Version;
	Sbecore::uint start;
	Sbecore::uint stop;

public:
	bool operator==(const WzemMPeriod& comp);
	bool operator!=(const WzemMPeriod& comp);
};

/**
	* ListWzemMPeriod: recordset of TblWzemMPeriod
	*/
class ListWzemMPeriod {

public:
	ListWzemMPeriod();
	ListWzemMPeriod(const ListWzemMPeriod& src);
	~ListWzemMPeriod();

	void clear();
	unsigned int size() const;
	void append(WzemMPeriod* rec);

	WzemMPeriod* operator[](const Sbecore::uint ix);
	ListWzemMPeriod& operator=(const ListWzemMPeriod& src);
	bool operator==(const ListWzemMPeriod& comp);
	bool operator!=(const ListWzemMPeriod& comp);

public:
	std::vector<WzemMPeriod*> nodes;
};

/**
	* TblWzemMPeriod: C++ wrapper for table TblWzemMPeriod
	*/
class TblWzemMPeriod {

public:

public:
	TblWzemMPeriod();
	virtual ~TblWzemMPeriod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMPeriod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPeriod& rst);

	virtual Sbecore::ubigint insertRec(WzemMPeriod* rec);
	Sbecore::ubigint insertNewRec(WzemMPeriod** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string Version = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemMPeriod& rst, WzemMPeriod** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string Version = "", const Sbecore::uint start = 0, const Sbecore::uint stop = 0);
	virtual void insertRst(ListWzemMPeriod& rst, bool transact = false);
	virtual void updateRec(WzemMPeriod* rec);
	virtual void updateRst(ListWzemMPeriod& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMPeriod** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMPeriod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMPeriod: C++ wrapper for table TblWzemMPeriod (MySQL database)
	*/
class MyTblWzemMPeriod : public TblWzemMPeriod, public Sbecore::MyTable {

public:
	MyTblWzemMPeriod();
	~MyTblWzemMPeriod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPeriod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPeriod& rst);

	Sbecore::ubigint insertRec(WzemMPeriod* rec);
	void insertRst(ListWzemMPeriod& rst, bool transact = false);
	void updateRec(WzemMPeriod* rec);
	void updateRst(ListWzemMPeriod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPeriod** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMPeriod: C++ wrapper for table TblWzemMPeriod (PgSQL database)
	*/
class PgTblWzemMPeriod : public TblWzemMPeriod, public Sbecore::PgTable {

public:
	PgTblWzemMPeriod();
	~PgTblWzemMPeriod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMPeriod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMPeriod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMPeriod** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPeriod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPeriod& rst);

	Sbecore::ubigint insertRec(WzemMPeriod* rec);
	void insertRst(ListWzemMPeriod& rst, bool transact = false);
	void updateRec(WzemMPeriod* rec);
	void updateRst(ListWzemMPeriod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPeriod** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMPeriod: C++ wrapper for table TblWzemMPeriod (SQLite database)
	*/
class LiteTblWzemMPeriod : public TblWzemMPeriod, public Sbecore::LiteTable {

public:
	LiteTblWzemMPeriod();
	~LiteTblWzemMPeriod();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMPeriod** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMPeriod& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMPeriod** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMPeriod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMPeriod& rst);

	Sbecore::ubigint insertRec(WzemMPeriod* rec);
	void insertRst(ListWzemMPeriod& rst, bool transact = false);
	void updateRec(WzemMPeriod* rec);
	void updateRst(ListWzemMPeriod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMPeriod** rec);
};
#endif

#endif

