/**
	* \file WzemMNode.h
	* database access for table TblWzemMNode (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMMNODE_H
#define WZEMMNODE_H

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
	* WzemMNode: record of TblWzemMNode
	*/
class WzemMNode {

public:
	WzemMNode(const Sbecore::ubigint ref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint xnref = 0, const std::string Ip = "", const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);

public:
	Sbecore::ubigint ref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint refWzemMPeriod;
	Sbecore::ubigint xnref;
	std::string Ip;
	Sbecore::usmallint Port;
	Sbecore::utinyint Opprcn;

public:
	bool operator==(const WzemMNode& comp);
	bool operator!=(const WzemMNode& comp);
};

/**
	* ListWzemMNode: recordset of TblWzemMNode
	*/
class ListWzemMNode {

public:
	ListWzemMNode();
	ListWzemMNode(const ListWzemMNode& src);
	~ListWzemMNode();

	void clear();
	unsigned int size() const;
	void append(WzemMNode* rec);

	WzemMNode* operator[](const Sbecore::uint ix);
	ListWzemMNode& operator=(const ListWzemMNode& src);
	bool operator==(const ListWzemMNode& comp);
	bool operator!=(const ListWzemMNode& comp);

public:
	std::vector<WzemMNode*> nodes;
};

/**
	* TblWzemMNode: C++ wrapper for table TblWzemMNode
	*/
class TblWzemMNode {

public:

public:
	TblWzemMNode();
	virtual ~TblWzemMNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMNode& rst);

	virtual Sbecore::ubigint insertRec(WzemMNode* rec);
	Sbecore::ubigint insertNewRec(WzemMNode** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint xnref = 0, const std::string Ip = "", const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemMNode& rst, WzemMNode** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint xnref = 0, const std::string Ip = "", const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);
	virtual void insertRst(ListWzemMNode& rst, bool transact = false);
	virtual void updateRec(WzemMNode* rec);
	virtual void updateRst(ListWzemMNode& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMNode** rec);
	virtual Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMNode& rst);
	virtual bool loadXnrByRef(Sbecore::ubigint ref, std::string& xnref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMNode& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMNode: C++ wrapper for table TblWzemMNode (MySQL database)
	*/
class MyTblWzemMNode : public TblWzemMNode, public Sbecore::MyTable {

public:
	MyTblWzemMNode();
	~MyTblWzemMNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMNode& rst);

	Sbecore::ubigint insertRec(WzemMNode* rec);
	void insertRst(ListWzemMNode& rst, bool transact = false);
	void updateRec(WzemMNode* rec);
	void updateRst(ListWzemMNode& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMNode** rec);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMNode& rst);
	bool loadXnrByRef(Sbecore::ubigint ref, std::string& xnref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMNode: C++ wrapper for table TblWzemMNode (PgSQL database)
	*/
class PgTblWzemMNode : public TblWzemMNode, public Sbecore::PgTable {

public:
	PgTblWzemMNode();
	~PgTblWzemMNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMNode& rst);

	Sbecore::ubigint insertRec(WzemMNode* rec);
	void insertRst(ListWzemMNode& rst, bool transact = false);
	void updateRec(WzemMNode* rec);
	void updateRst(ListWzemMNode& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMNode** rec);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMNode& rst);
	bool loadXnrByRef(Sbecore::ubigint ref, std::string& xnref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMNode: C++ wrapper for table TblWzemMNode (SQLite database)
	*/
class LiteTblWzemMNode : public TblWzemMNode, public Sbecore::LiteTable {

public:
	LiteTblWzemMNode();
	~LiteTblWzemMNode();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByPrd;
	sqlite3_stmt* stmtLoadXnrByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMNode** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMNode& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMNode** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMNode& rst);

	Sbecore::ubigint insertRec(WzemMNode* rec);
	void insertRst(ListWzemMNode& rst, bool transact = false);
	void updateRec(WzemMNode* rec);
	void updateRst(ListWzemMNode& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMNode** rec);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMNode& rst);
	bool loadXnrByRef(Sbecore::ubigint ref, std::string& xnref);
};
#endif

#endif

