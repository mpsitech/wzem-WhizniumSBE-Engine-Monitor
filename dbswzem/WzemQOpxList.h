/**
	* \file WzemQOpxList.h
	* Dbs and XML wrapper for table TblWzemQOpxList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQOPXLIST_H
#define WZEMQOPXLIST_H

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
	* WzemQOpxList: record of TblWzemQOpxList
	*/
class WzemQOpxList {

public:
	WzemQOpxList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const Sbecore::ubigint xoref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMJob;
	std::string stubRefWzemMJob;
	Sbecore::ubigint xoref;
	double x1Startu;
	double x1Stopu;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQOpxList: recordset of TblWzemQOpxList
	*/
class ListWzemQOpxList {

public:
	ListWzemQOpxList();
	ListWzemQOpxList(const ListWzemQOpxList& src);
	~ListWzemQOpxList();

	void clear();
	unsigned int size() const;
	void append(WzemQOpxList* rec);

	ListWzemQOpxList& operator=(const ListWzemQOpxList& src);

public:
	std::vector<WzemQOpxList*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQOpxList: C++ wrapper for table TblWzemQOpxList
	*/
class TblWzemQOpxList {

public:
	TblWzemQOpxList();
	virtual ~TblWzemQOpxList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQOpxList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQOpxList& rst);

	virtual Sbecore::ubigint insertRec(WzemQOpxList* rec);
	Sbecore::ubigint insertNewRec(WzemQOpxList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const Sbecore::ubigint xoref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQOpxList& rst, WzemQOpxList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const Sbecore::ubigint xoref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0);
	virtual void insertRst(ListWzemQOpxList& rst);
	virtual void updateRec(WzemQOpxList* rec);
	virtual void updateRst(ListWzemQOpxList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQOpxList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQOpxList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQOpxList: C++ wrapper for table TblWzemQOpxList (MySQL database)
	*/
class MyTblWzemQOpxList : public TblWzemQOpxList, public Sbecore::MyTable {

public:
	MyTblWzemQOpxList();
	~MyTblWzemQOpxList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQOpxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQOpxList& rst);

	Sbecore::ubigint insertRec(WzemQOpxList* rec);
	void insertRst(ListWzemQOpxList& rst);
	void updateRec(WzemQOpxList* rec);
	void updateRst(ListWzemQOpxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQOpxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQOpxList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQOpxList: C++ wrapper for table TblWzemQOpxList (PgSQL database)
	*/
class PgTblWzemQOpxList : public TblWzemQOpxList, public Sbecore::PgTable {

public:
	PgTblWzemQOpxList();
	~PgTblWzemQOpxList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQOpxList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQOpxList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQOpxList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQOpxList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQOpxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQOpxList& rst);

	Sbecore::ubigint insertRec(WzemQOpxList* rec);
	void insertRst(ListWzemQOpxList& rst);
	void updateRec(WzemQOpxList* rec);
	void updateRst(ListWzemQOpxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQOpxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQOpxList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQOpxList: C++ wrapper for table TblWzemQOpxList (SQLite database)
	*/
class LiteTblWzemQOpxList : public TblWzemQOpxList, public Sbecore::LiteTable {

public:
	LiteTblWzemQOpxList();
	~LiteTblWzemQOpxList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQOpxList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQOpxList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQOpxList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQOpxList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQOpxList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQOpxList& rst);

	Sbecore::ubigint insertRec(WzemQOpxList* rec);
	void insertRst(ListWzemQOpxList& rst);
	void updateRec(WzemQOpxList* rec);
	void updateRst(ListWzemQOpxList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQOpxList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQOpxList& rst);
};
#endif

#endif
