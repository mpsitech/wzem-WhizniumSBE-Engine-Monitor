/**
	* \file WzemMDpch.h
	* database access for table TblWzemMDpch (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMMDPCH_H
#define WZEMMDPCH_H

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
	* WzemMDpch: record of TblWzemMDpch
	*/
class WzemMDpch {

public:
	WzemMDpch(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMEvent = 0, const std::string srefIxVDpch = "", const std::string srefsMask = "", const std::string Content = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMEvent;
	std::string srefIxVDpch;
	std::string srefsMask;
	std::string Content;

public:
	bool operator==(const WzemMDpch& comp);
	bool operator!=(const WzemMDpch& comp);
};

/**
	* ListWzemMDpch: recordset of TblWzemMDpch
	*/
class ListWzemMDpch {

public:
	ListWzemMDpch();
	ListWzemMDpch(const ListWzemMDpch& src);
	~ListWzemMDpch();

	void clear();
	unsigned int size() const;
	void append(WzemMDpch* rec);

	WzemMDpch* operator[](const Sbecore::uint ix);
	ListWzemMDpch& operator=(const ListWzemMDpch& src);
	bool operator==(const ListWzemMDpch& comp);
	bool operator!=(const ListWzemMDpch& comp);

public:
	std::vector<WzemMDpch*> nodes;
};

/**
	* TblWzemMDpch: C++ wrapper for table TblWzemMDpch
	*/
class TblWzemMDpch {

public:

public:
	TblWzemMDpch();
	virtual ~TblWzemMDpch();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMDpch** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMDpch& rst);

	virtual Sbecore::ubigint insertRec(WzemMDpch* rec);
	Sbecore::ubigint insertNewRec(WzemMDpch** rec = NULL, const Sbecore::ubigint refWzemMEvent = 0, const std::string srefIxVDpch = "", const std::string srefsMask = "", const std::string Content = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMDpch& rst, WzemMDpch** rec = NULL, const Sbecore::ubigint refWzemMEvent = 0, const std::string srefIxVDpch = "", const std::string srefsMask = "", const std::string Content = "");
	virtual void insertRst(ListWzemMDpch& rst, bool transact = false);
	virtual void updateRec(WzemMDpch* rec);
	virtual void updateRst(ListWzemMDpch& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMDpch** rec);
	virtual bool loadDchByRef(Sbecore::ubigint ref, std::string& srefIxVDpch);
	virtual bool loadRecByEvt(Sbecore::ubigint refWzemMEvent, WzemMDpch** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMDpch& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMDpch: C++ wrapper for table TblWzemMDpch (MySQL database)
	*/
class MyTblWzemMDpch : public TblWzemMDpch, public Sbecore::MyTable {

public:
	MyTblWzemMDpch();
	~MyTblWzemMDpch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMDpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMDpch& rst);

	Sbecore::ubigint insertRec(WzemMDpch* rec);
	void insertRst(ListWzemMDpch& rst, bool transact = false);
	void updateRec(WzemMDpch* rec);
	void updateRst(ListWzemMDpch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMDpch** rec);
	bool loadDchByRef(Sbecore::ubigint ref, std::string& srefIxVDpch);
	bool loadRecByEvt(Sbecore::ubigint refWzemMEvent, WzemMDpch** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMDpch: C++ wrapper for table TblWzemMDpch (PgSQL database)
	*/
class PgTblWzemMDpch : public TblWzemMDpch, public Sbecore::PgTable {

public:
	PgTblWzemMDpch();
	~PgTblWzemMDpch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMDpch** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMDpch& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMDpch** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMDpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMDpch& rst);

	Sbecore::ubigint insertRec(WzemMDpch* rec);
	void insertRst(ListWzemMDpch& rst, bool transact = false);
	void updateRec(WzemMDpch* rec);
	void updateRst(ListWzemMDpch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMDpch** rec);
	bool loadDchByRef(Sbecore::ubigint ref, std::string& srefIxVDpch);
	bool loadRecByEvt(Sbecore::ubigint refWzemMEvent, WzemMDpch** rec);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMDpch: C++ wrapper for table TblWzemMDpch (SQLite database)
	*/
class LiteTblWzemMDpch : public TblWzemMDpch, public Sbecore::LiteTable {

public:
	LiteTblWzemMDpch();
	~LiteTblWzemMDpch();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadDchByRef;
	sqlite3_stmt* stmtLoadRecByEvt;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMDpch** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMDpch& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMDpch** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMDpch** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMDpch& rst);

	Sbecore::ubigint insertRec(WzemMDpch* rec);
	void insertRst(ListWzemMDpch& rst, bool transact = false);
	void updateRec(WzemMDpch* rec);
	void updateRst(ListWzemMDpch& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMDpch** rec);
	bool loadDchByRef(Sbecore::ubigint ref, std::string& srefIxVDpch);
	bool loadRecByEvt(Sbecore::ubigint refWzemMEvent, WzemMDpch** rec);
};
#endif

#endif

