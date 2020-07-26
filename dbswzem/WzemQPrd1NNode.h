/**
	* \file WzemQPrd1NNode.h
	* Dbs and XML wrapper for table TblWzemQPrd1NNode (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQPRD1NNODE_H
#define WZEMQPRD1NNODE_H

#include <sbecore/Xmlio.h>

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
	* WzemQPrd1NNode: record of TblWzemQPrd1NNode
	*/
class WzemQPrd1NNode {

public:
	WzemQPrd1NNode(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQPrd1NNode: recordset of TblWzemQPrd1NNode
	*/
class ListWzemQPrd1NNode {

public:
	ListWzemQPrd1NNode();
	ListWzemQPrd1NNode(const ListWzemQPrd1NNode& src);
	~ListWzemQPrd1NNode();

	void clear();
	unsigned int size() const;
	void append(WzemQPrd1NNode* rec);

	ListWzemQPrd1NNode& operator=(const ListWzemQPrd1NNode& src);

public:
	std::vector<WzemQPrd1NNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPrd1NNode: C++ wrapper for table TblWzemQPrd1NNode
	*/
class TblWzemQPrd1NNode {

public:
	TblWzemQPrd1NNode();
	virtual ~TblWzemQPrd1NNode();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NNode** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NNode& rst);

	virtual Sbecore::ubigint insertRec(WzemQPrd1NNode* rec);
	Sbecore::ubigint insertNewRec(WzemQPrd1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQPrd1NNode& rst, WzemQPrd1NNode** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQPrd1NNode& rst);
	virtual void updateRec(WzemQPrd1NNode* rec);
	virtual void updateRst(ListWzemQPrd1NNode& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NNode** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NNode& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPrd1NNode: C++ wrapper for table TblWzemQPrd1NNode (MySQL database)
	*/
class MyTblWzemQPrd1NNode : public TblWzemQPrd1NNode, public Sbecore::MyTable {

public:
	MyTblWzemQPrd1NNode();
	~MyTblWzemQPrd1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NNode& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NNode* rec);
	void insertRst(ListWzemQPrd1NNode& rst);
	void updateRec(WzemQPrd1NNode* rec);
	void updateRst(ListWzemQPrd1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NNode& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPrd1NNode: C++ wrapper for table TblWzemQPrd1NNode (PgSQL database)
	*/
class PgTblWzemQPrd1NNode : public TblWzemQPrd1NNode, public Sbecore::PgTable {

public:
	PgTblWzemQPrd1NNode();
	~PgTblWzemQPrd1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPrd1NNode& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPrd1NNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NNode& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NNode* rec);
	void insertRst(ListWzemQPrd1NNode& rst);
	void updateRec(WzemQPrd1NNode* rec);
	void updateRst(ListWzemQPrd1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NNode& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPrd1NNode: C++ wrapper for table TblWzemQPrd1NNode (SQLite database)
	*/
class LiteTblWzemQPrd1NNode : public TblWzemQPrd1NNode, public Sbecore::LiteTable {

public:
	LiteTblWzemQPrd1NNode();
	~LiteTblWzemQPrd1NNode();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByQref;
	sqlite3_stmt* stmtRemoveRstByJref;

	sqlite3_stmt* stmtLoadRecByQref;
	sqlite3_stmt* stmtLoadRecByJref;
	sqlite3_stmt* stmtLoadRstByJref;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPrd1NNode& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPrd1NNode& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NNode& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NNode* rec);
	void insertRst(ListWzemQPrd1NNode& rst);
	void updateRec(WzemQPrd1NNode* rec);
	void updateRst(ListWzemQPrd1NNode& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NNode** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NNode& rst);
};
#endif

#endif

