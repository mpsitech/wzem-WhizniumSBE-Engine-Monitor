/**
	* \file WzemQCalList.h
	* Dbs and XML wrapper for table TblWzemQCalList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQCALLIST_H
#define WZEMQCALLIST_H

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
	* WzemQCalList: record of TblWzemQCalList
	*/
class WzemQCalList {

public:
	WzemQCalList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMJob;
	std::string stubRefWzemMJob;
	std::string srefIxVCall;
	double x1Startu;
	double x1Stopu;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQCalList: recordset of TblWzemQCalList
	*/
class ListWzemQCalList {

public:
	ListWzemQCalList();
	ListWzemQCalList(const ListWzemQCalList& src);
	~ListWzemQCalList();

	void clear();
	unsigned int size() const;
	void append(WzemQCalList* rec);

	ListWzemQCalList& operator=(const ListWzemQCalList& src);

public:
	std::vector<WzemQCalList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQCalList: C++ wrapper for table TblWzemQCalList
	*/
class TblWzemQCalList {

public:
	TblWzemQCalList();
	virtual ~TblWzemQCalList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQCalList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQCalList& rst);

	virtual Sbecore::ubigint insertRec(WzemQCalList* rec);
	Sbecore::ubigint insertNewRec(WzemQCalList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQCalList& rst, WzemQCalList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);
	virtual void insertRst(ListWzemQCalList& rst);
	virtual void updateRec(WzemQCalList* rec);
	virtual void updateRst(ListWzemQCalList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQCalList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQCalList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQCalList: C++ wrapper for table TblWzemQCalList (MySQL database)
	*/
class MyTblWzemQCalList : public TblWzemQCalList, public Sbecore::MyTable {

public:
	MyTblWzemQCalList();
	~MyTblWzemQCalList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQCalList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQCalList& rst);

	Sbecore::ubigint insertRec(WzemQCalList* rec);
	void insertRst(ListWzemQCalList& rst);
	void updateRec(WzemQCalList* rec);
	void updateRst(ListWzemQCalList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQCalList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQCalList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQCalList: C++ wrapper for table TblWzemQCalList (PgSQL database)
	*/
class PgTblWzemQCalList : public TblWzemQCalList, public Sbecore::PgTable {

public:
	PgTblWzemQCalList();
	~PgTblWzemQCalList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQCalList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQCalList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQCalList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQCalList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQCalList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQCalList& rst);

	Sbecore::ubigint insertRec(WzemQCalList* rec);
	void insertRst(ListWzemQCalList& rst);
	void updateRec(WzemQCalList* rec);
	void updateRst(ListWzemQCalList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQCalList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQCalList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQCalList: C++ wrapper for table TblWzemQCalList (SQLite database)
	*/
class LiteTblWzemQCalList : public TblWzemQCalList, public Sbecore::LiteTable {

public:
	LiteTblWzemQCalList();
	~LiteTblWzemQCalList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQCalList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQCalList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQCalList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQCalList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQCalList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQCalList& rst);

	Sbecore::ubigint insertRec(WzemQCalList* rec);
	void insertRst(ListWzemQCalList& rst);
	void updateRec(WzemQCalList* rec);
	void updateRst(ListWzemQCalList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQCalList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQCalList& rst);
};
#endif

#endif

