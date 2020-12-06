/**
	* \file WzemMUsergroup.h
	* database access for table TblWzemMUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMUSERGROUP_H
#define WZEMMUSERGROUP_H

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
	* WzemMUsergroup: record of TblWzemMUsergroup
	*/
class WzemMUsergroup {

public:
	WzemMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WzemMUsergroup& comp);
	bool operator!=(const WzemMUsergroup& comp);
};

/**
	* ListWzemMUsergroup: recordset of TblWzemMUsergroup
	*/
class ListWzemMUsergroup {

public:
	ListWzemMUsergroup();
	ListWzemMUsergroup(const ListWzemMUsergroup& src);
	~ListWzemMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WzemMUsergroup* rec);

	WzemMUsergroup* operator[](const Sbecore::uint ix);
	ListWzemMUsergroup& operator=(const ListWzemMUsergroup& src);
	bool operator==(const ListWzemMUsergroup& comp);
	bool operator!=(const ListWzemMUsergroup& comp);

public:
	std::vector<WzemMUsergroup*> nodes;
};

/**
	* TblWzemMUsergroup: C++ wrapper for table TblWzemMUsergroup
	*/
class TblWzemMUsergroup {

public:

public:
	TblWzemMUsergroup();
	virtual ~TblWzemMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WzemMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WzemMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMUsergroup& rst, WzemMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWzemMUsergroup& rst, bool transact = false);
	virtual void updateRec(WzemMUsergroup* rec);
	virtual void updateRst(ListWzemMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMUsergroup** rec);
	virtual bool loadRecBySrf(std::string sref, WzemMUsergroup** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMUsergroup: C++ wrapper for table TblWzemMUsergroup (MySQL database)
	*/
class MyTblWzemMUsergroup : public TblWzemMUsergroup, public Sbecore::MyTable {

public:
	MyTblWzemMUsergroup();
	~MyTblWzemMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUsergroup& rst);

	Sbecore::ubigint insertRec(WzemMUsergroup* rec);
	void insertRst(ListWzemMUsergroup& rst, bool transact = false);
	void updateRec(WzemMUsergroup* rec);
	void updateRst(ListWzemMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WzemMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMUsergroup: C++ wrapper for table TblWzemMUsergroup (PgSQL database)
	*/
class PgTblWzemMUsergroup : public TblWzemMUsergroup, public Sbecore::PgTable {

public:
	PgTblWzemMUsergroup();
	~PgTblWzemMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMUsergroup** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUsergroup& rst);

	Sbecore::ubigint insertRec(WzemMUsergroup* rec);
	void insertRst(ListWzemMUsergroup& rst, bool transact = false);
	void updateRec(WzemMUsergroup* rec);
	void updateRst(ListWzemMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WzemMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMUsergroup: C++ wrapper for table TblWzemMUsergroup (SQLite database)
	*/
class LiteTblWzemMUsergroup : public TblWzemMUsergroup, public Sbecore::LiteTable {

public:
	LiteTblWzemMUsergroup();
	~LiteTblWzemMUsergroup();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecBySrf;
	sqlite3_stmt* stmtLoadRefBySrf;
	sqlite3_stmt* stmtLoadSrfByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMUsergroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMUsergroup** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUsergroup& rst);

	Sbecore::ubigint insertRec(WzemMUsergroup* rec);
	void insertRst(ListWzemMUsergroup& rst, bool transact = false);
	void updateRec(WzemMUsergroup* rec);
	void updateRst(ListWzemMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMUsergroup** rec);
	bool loadRecBySrf(std::string sref, WzemMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
