/**
	* \file WzemQNdeList.h
	* Dbs and XML wrapper for table TblWzemQNdeList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQNDELIST_H
#define WZEMQNDELIST_H

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
	* WzemQNdeList: record of TblWzemQNdeList
	*/
class WzemQNdeList {

public:
	WzemQNdeList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const Sbecore::ubigint xnref = 0, const std::string Ip = "", const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMPeriod;
	std::string stubRefWzemMPeriod;
	Sbecore::ubigint xnref;
	std::string Ip;
	double x1Startu;
	double x1Stopu;
	Sbecore::usmallint Port;
	Sbecore::utinyint Opprcn;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQNdeList: recordset of TblWzemQNdeList
	*/
class ListWzemQNdeList {

public:
	ListWzemQNdeList();
	ListWzemQNdeList(const ListWzemQNdeList& src);
	~ListWzemQNdeList();

	void clear();
	unsigned int size() const;
	void append(WzemQNdeList* rec);

	ListWzemQNdeList& operator=(const ListWzemQNdeList& src);

public:
	std::vector<WzemQNdeList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQNdeList: C++ wrapper for table TblWzemQNdeList
	*/
class TblWzemQNdeList {

public:
	TblWzemQNdeList();
	virtual ~TblWzemQNdeList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQNdeList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQNdeList& rst);

	virtual Sbecore::ubigint insertRec(WzemQNdeList* rec);
	Sbecore::ubigint insertNewRec(WzemQNdeList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const Sbecore::ubigint xnref = 0, const std::string Ip = "", const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQNdeList& rst, WzemQNdeList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const Sbecore::ubigint xnref = 0, const std::string Ip = "", const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);
	virtual void insertRst(ListWzemQNdeList& rst);
	virtual void updateRec(WzemQNdeList* rec);
	virtual void updateRst(ListWzemQNdeList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQNdeList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQNdeList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQNdeList: C++ wrapper for table TblWzemQNdeList (MySQL database)
	*/
class MyTblWzemQNdeList : public TblWzemQNdeList, public Sbecore::MyTable {

public:
	MyTblWzemQNdeList();
	~MyTblWzemQNdeList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQNdeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQNdeList& rst);

	Sbecore::ubigint insertRec(WzemQNdeList* rec);
	void insertRst(ListWzemQNdeList& rst);
	void updateRec(WzemQNdeList* rec);
	void updateRst(ListWzemQNdeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQNdeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQNdeList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQNdeList: C++ wrapper for table TblWzemQNdeList (PgSQL database)
	*/
class PgTblWzemQNdeList : public TblWzemQNdeList, public Sbecore::PgTable {

public:
	PgTblWzemQNdeList();
	~PgTblWzemQNdeList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQNdeList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQNdeList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQNdeList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQNdeList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQNdeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQNdeList& rst);

	Sbecore::ubigint insertRec(WzemQNdeList* rec);
	void insertRst(ListWzemQNdeList& rst);
	void updateRec(WzemQNdeList* rec);
	void updateRst(ListWzemQNdeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQNdeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQNdeList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQNdeList: C++ wrapper for table TblWzemQNdeList (SQLite database)
	*/
class LiteTblWzemQNdeList : public TblWzemQNdeList, public Sbecore::LiteTable {

public:
	LiteTblWzemQNdeList();
	~LiteTblWzemQNdeList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQNdeList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQNdeList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQNdeList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQNdeList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQNdeList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQNdeList& rst);

	Sbecore::ubigint insertRec(WzemQNdeList* rec);
	void insertRst(ListWzemQNdeList& rst);
	void updateRec(WzemQNdeList* rec);
	void updateRst(ListWzemQNdeList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQNdeList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQNdeList& rst);
};
#endif

#endif

