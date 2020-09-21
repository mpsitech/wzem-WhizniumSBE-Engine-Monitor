/**
	* \file WzemAVValuelistVal.h
	* database access for table TblWzemAVValuelistVal (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMAVVALUELISTVAL_H
#define WZEMAVVALUELISTVAL_H

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
	* WzemAVValuelistVal: record of TblWzemAVValuelistVal
	*/
class WzemAVValuelistVal {

public:
	WzemAVValuelistVal(const Sbecore::ubigint ref = 0, const Sbecore::uint vlsIxWzemVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint vlsIxWzemVValuelist;
	Sbecore::uint vlsNum;
	Sbecore::uint x1IxWzemVLocale;
	std::string Val;

public:
	bool operator==(const WzemAVValuelistVal& comp);
	bool operator!=(const WzemAVValuelistVal& comp);
};

/**
	* ListWzemAVValuelistVal: recordset of TblWzemAVValuelistVal
	*/
class ListWzemAVValuelistVal {

public:
	ListWzemAVValuelistVal();
	ListWzemAVValuelistVal(const ListWzemAVValuelistVal& src);
	~ListWzemAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(WzemAVValuelistVal* rec);

	WzemAVValuelistVal* operator[](const Sbecore::uint ix);
	ListWzemAVValuelistVal& operator=(const ListWzemAVValuelistVal& src);
	bool operator==(const ListWzemAVValuelistVal& comp);
	bool operator!=(const ListWzemAVValuelistVal& comp);

public:
	std::vector<WzemAVValuelistVal*> nodes;
};

/**
	* TblWzemAVValuelistVal: C++ wrapper for table TblWzemAVValuelistVal
	*/
class TblWzemAVValuelistVal {

public:

public:
	TblWzemAVValuelistVal();
	virtual ~TblWzemAVValuelistVal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVValuelistVal& rst);

	virtual Sbecore::ubigint insertRec(WzemAVValuelistVal* rec);
	Sbecore::ubigint insertNewRec(WzemAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWzemVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemAVValuelistVal& rst, WzemAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWzemVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string Val = "");
	virtual void insertRst(ListWzemAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(WzemAVValuelistVal* rec);
	virtual void updateRst(ListWzemAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzemVValuelist, Sbecore::uint x1IxWzemVLocale, const bool append, ListWzemAVValuelistVal& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAVValuelistVal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAVValuelistVal: C++ wrapper for table TblWzemAVValuelistVal (MySQL database)
	*/
class MyTblWzemAVValuelistVal : public TblWzemAVValuelistVal, public Sbecore::MyTable {

public:
	MyTblWzemAVValuelistVal();
	~MyTblWzemAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WzemAVValuelistVal* rec);
	void insertRst(ListWzemAVValuelistVal& rst, bool transact = false);
	void updateRec(WzemAVValuelistVal* rec);
	void updateRst(ListWzemAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzemVValuelist, Sbecore::uint x1IxWzemVLocale, const bool append, ListWzemAVValuelistVal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAVValuelistVal: C++ wrapper for table TblWzemAVValuelistVal (PgSQL database)
	*/
class PgTblWzemAVValuelistVal : public TblWzemAVValuelistVal, public Sbecore::PgTable {

public:
	PgTblWzemAVValuelistVal();
	~PgTblWzemAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAVValuelistVal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemAVValuelistVal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WzemAVValuelistVal* rec);
	void insertRst(ListWzemAVValuelistVal& rst, bool transact = false);
	void updateRec(WzemAVValuelistVal* rec);
	void updateRst(ListWzemAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzemVValuelist, Sbecore::uint x1IxWzemVLocale, const bool append, ListWzemAVValuelistVal& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAVValuelistVal: C++ wrapper for table TblWzemAVValuelistVal (SQLite database)
	*/
class LiteTblWzemAVValuelistVal : public TblWzemAVValuelistVal, public Sbecore::LiteTable {

public:
	LiteTblWzemAVValuelistVal();
	~LiteTblWzemAVValuelistVal();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByVlsLcl;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAVValuelistVal& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemAVValuelistVal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WzemAVValuelistVal* rec);
	void insertRst(ListWzemAVValuelistVal& rst, bool transact = false);
	void updateRec(WzemAVValuelistVal* rec);
	void updateRst(ListWzemAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWzemVValuelist, Sbecore::uint x1IxWzemVLocale, const bool append, ListWzemAVValuelistVal& rst);
};
#endif

#endif

