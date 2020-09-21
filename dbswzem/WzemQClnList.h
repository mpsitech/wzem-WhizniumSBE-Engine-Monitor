/**
	* \file WzemQClnList.h
	* Dbs and XML wrapper for table TblWzemQClnList (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQCLNLIST_H
#define WZEMQCLNLIST_H

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
	* WzemQClnList: record of TblWzemQClnList
	*/
class WzemQClnList {

public:
	WzemQClnList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const std::string srefIxVSge = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMJob;
	std::string stubRefWzemMJob;
	std::string srefIxVCall;
	std::string srefIxVSge;
	double x1Startu;
	double x1Stopu;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQClnList: recordset of TblWzemQClnList
	*/
class ListWzemQClnList {

public:
	ListWzemQClnList();
	ListWzemQClnList(const ListWzemQClnList& src);
	~ListWzemQClnList();

	void clear();
	unsigned int size() const;
	void append(WzemQClnList* rec);

	ListWzemQClnList& operator=(const ListWzemQClnList& src);

public:
	std::vector<WzemQClnList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQClnList: C++ wrapper for table TblWzemQClnList
	*/
class TblWzemQClnList {

public:
	TblWzemQClnList();
	virtual ~TblWzemQClnList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQClnList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQClnList& rst);

	virtual Sbecore::ubigint insertRec(WzemQClnList* rec);
	Sbecore::ubigint insertNewRec(WzemQClnList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const std::string srefIxVSge = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQClnList& rst, WzemQClnList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const std::string srefIxVSge = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);
	virtual void insertRst(ListWzemQClnList& rst);
	virtual void updateRec(WzemQClnList* rec);
	virtual void updateRst(ListWzemQClnList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQClnList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQClnList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQClnList: C++ wrapper for table TblWzemQClnList (MySQL database)
	*/
class MyTblWzemQClnList : public TblWzemQClnList, public Sbecore::MyTable {

public:
	MyTblWzemQClnList();
	~MyTblWzemQClnList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQClnList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQClnList& rst);

	Sbecore::ubigint insertRec(WzemQClnList* rec);
	void insertRst(ListWzemQClnList& rst);
	void updateRec(WzemQClnList* rec);
	void updateRst(ListWzemQClnList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQClnList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQClnList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQClnList: C++ wrapper for table TblWzemQClnList (PgSQL database)
	*/
class PgTblWzemQClnList : public TblWzemQClnList, public Sbecore::PgTable {

public:
	PgTblWzemQClnList();
	~PgTblWzemQClnList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQClnList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQClnList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQClnList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQClnList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQClnList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQClnList& rst);

	Sbecore::ubigint insertRec(WzemQClnList* rec);
	void insertRst(ListWzemQClnList& rst);
	void updateRec(WzemQClnList* rec);
	void updateRst(ListWzemQClnList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQClnList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQClnList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQClnList: C++ wrapper for table TblWzemQClnList (SQLite database)
	*/
class LiteTblWzemQClnList : public TblWzemQClnList, public Sbecore::LiteTable {

public:
	LiteTblWzemQClnList();
	~LiteTblWzemQClnList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQClnList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQClnList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQClnList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQClnList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQClnList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQClnList& rst);

	Sbecore::ubigint insertRec(WzemQClnList* rec);
	void insertRst(ListWzemQClnList& rst);
	void updateRec(WzemQClnList* rec);
	void updateRst(ListWzemQClnList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQClnList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQClnList& rst);
};
#endif

#endif

