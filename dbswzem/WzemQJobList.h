/**
	* \file WzemQJobList.h
	* Dbs and XML wrapper for table TblWzemQJobList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQJOBLIST_H
#define WZEMQJOBLIST_H

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
	* WzemQJobList: record of TblWzemQJobList
	*/
class WzemQJobList {

public:
	WzemQJobList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint supRefWzemMJob = 0, const std::string stubSupRefWzemMJob = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMPeriod;
	std::string stubRefWzemMPeriod;
	std::string srefIxVJob;
	Sbecore::ubigint xjref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint supRefWzemMJob;
	std::string stubSupRefWzemMJob;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQJobList: recordset of TblWzemQJobList
	*/
class ListWzemQJobList {

public:
	ListWzemQJobList();
	ListWzemQJobList(const ListWzemQJobList& src);
	~ListWzemQJobList();

	void clear();
	unsigned int size() const;
	void append(WzemQJobList* rec);

	ListWzemQJobList& operator=(const ListWzemQJobList& src);

public:
	std::vector<WzemQJobList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQJobList: C++ wrapper for table TblWzemQJobList
	*/
class TblWzemQJobList {

public:
	TblWzemQJobList();
	virtual ~TblWzemQJobList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQJobList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobList& rst);

	virtual Sbecore::ubigint insertRec(WzemQJobList* rec);
	Sbecore::ubigint insertNewRec(WzemQJobList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint supRefWzemMJob = 0, const std::string stubSupRefWzemMJob = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQJobList& rst, WzemQJobList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint supRefWzemMJob = 0, const std::string stubSupRefWzemMJob = "");
	virtual void insertRst(ListWzemQJobList& rst);
	virtual void updateRec(WzemQJobList* rec);
	virtual void updateRst(ListWzemQJobList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQJobList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQJobList: C++ wrapper for table TblWzemQJobList (MySQL database)
	*/
class MyTblWzemQJobList : public TblWzemQJobList, public Sbecore::MyTable {

public:
	MyTblWzemQJobList();
	~MyTblWzemQJobList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJobList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobList& rst);

	Sbecore::ubigint insertRec(WzemQJobList* rec);
	void insertRst(ListWzemQJobList& rst);
	void updateRec(WzemQJobList* rec);
	void updateRst(ListWzemQJobList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJobList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQJobList: C++ wrapper for table TblWzemQJobList (PgSQL database)
	*/
class PgTblWzemQJobList : public TblWzemQJobList, public Sbecore::PgTable {

public:
	PgTblWzemQJobList();
	~PgTblWzemQJobList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQJobList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQJobList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQJobList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQJobList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJobList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobList& rst);

	Sbecore::ubigint insertRec(WzemQJobList* rec);
	void insertRst(ListWzemQJobList& rst);
	void updateRec(WzemQJobList* rec);
	void updateRst(ListWzemQJobList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJobList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQJobList: C++ wrapper for table TblWzemQJobList (SQLite database)
	*/
class LiteTblWzemQJobList : public TblWzemQJobList, public Sbecore::LiteTable {

public:
	LiteTblWzemQJobList();
	~LiteTblWzemQJobList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQJobList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQJobList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQJobList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQJobList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJobList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobList& rst);

	Sbecore::ubigint insertRec(WzemQJobList* rec);
	void insertRst(ListWzemQJobList& rst);
	void updateRec(WzemQJobList* rec);
	void updateRst(ListWzemQJobList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJobList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobList& rst);
};
#endif

#endif

