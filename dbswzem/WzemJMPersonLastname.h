/**
	* \file WzemJMPersonLastname.h
	* database access for table TblWzemJMPersonLastname (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMJMPERSONLASTNAME_H
#define WZEMJMPERSONLASTNAME_H

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
	* WzemJMPersonLastname: record of TblWzemJMPersonLastname
	*/
class WzemJMPersonLastname {

public:
	WzemJMPersonLastname(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMPerson;
	Sbecore::uint x1Startd;
	std::string Lastname;

public:
	bool operator==(const WzemJMPersonLastname& comp);
	bool operator!=(const WzemJMPersonLastname& comp);
};

/**
	* ListWzemJMPersonLastname: recordset of TblWzemJMPersonLastname
	*/
class ListWzemJMPersonLastname {

public:
	ListWzemJMPersonLastname();
	ListWzemJMPersonLastname(const ListWzemJMPersonLastname& src);
	~ListWzemJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(WzemJMPersonLastname* rec);

	WzemJMPersonLastname* operator[](const Sbecore::uint ix);
	ListWzemJMPersonLastname& operator=(const ListWzemJMPersonLastname& src);
	bool operator==(const ListWzemJMPersonLastname& comp);
	bool operator!=(const ListWzemJMPersonLastname& comp);

public:
	std::vector<WzemJMPersonLastname*> nodes;
};

/**
	* TblWzemJMPersonLastname: C++ wrapper for table TblWzemJMPersonLastname
	*/
class TblWzemJMPersonLastname {

public:

public:
	TblWzemJMPersonLastname();
	virtual ~TblWzemJMPersonLastname();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPersonLastname& rst);

	virtual Sbecore::ubigint insertRec(WzemJMPersonLastname* rec);
	Sbecore::ubigint insertNewRec(WzemJMPersonLastname** rec = NULL, const Sbecore::ubigint refWzemMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemJMPersonLastname& rst, WzemJMPersonLastname** rec = NULL, const Sbecore::ubigint refWzemMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	virtual void insertRst(ListWzemJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(WzemJMPersonLastname* rec);
	virtual void updateRst(ListWzemJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzemMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemJMPersonLastname& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMPersonLastname& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMPersonLastname: C++ wrapper for table TblWzemJMPersonLastname (MySQL database)
	*/
class MyTblWzemJMPersonLastname : public TblWzemJMPersonLastname, public Sbecore::MyTable {

public:
	MyTblWzemJMPersonLastname();
	~MyTblWzemJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WzemJMPersonLastname* rec);
	void insertRst(ListWzemJMPersonLastname& rst, bool transact = false);
	void updateRec(WzemJMPersonLastname* rec);
	void updateRst(ListWzemJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzemMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemJMPersonLastname& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMPersonLastname: C++ wrapper for table TblWzemJMPersonLastname (PgSQL database)
	*/
class PgTblWzemJMPersonLastname : public TblWzemJMPersonLastname, public Sbecore::PgTable {

public:
	PgTblWzemJMPersonLastname();
	~PgTblWzemJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMPersonLastname& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMPersonLastname& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WzemJMPersonLastname* rec);
	void insertRst(ListWzemJMPersonLastname& rst, bool transact = false);
	void updateRec(WzemJMPersonLastname* rec);
	void updateRst(ListWzemJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzemMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemJMPersonLastname& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMPersonLastname: C++ wrapper for table TblWzemJMPersonLastname (SQLite database)
	*/
class LiteTblWzemJMPersonLastname : public TblWzemJMPersonLastname, public Sbecore::LiteTable {

public:
	LiteTblWzemJMPersonLastname();
	~LiteTblWzemJMPersonLastname();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefsByPrs;
	sqlite3_stmt* stmtLoadRstByPrs;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMPersonLastname& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMPersonLastname& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WzemJMPersonLastname* rec);
	void insertRst(ListWzemJMPersonLastname& rst, bool transact = false);
	void updateRec(WzemJMPersonLastname* rec);
	void updateRst(ListWzemJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWzemMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWzemMPerson, const bool append, ListWzemJMPersonLastname& rst);
};
#endif

#endif

