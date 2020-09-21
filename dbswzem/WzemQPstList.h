/**
	* \file WzemQPstList.h
	* Dbs and XML wrapper for table TblWzemQPstList (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQPSTLIST_H
#define WZEMQPSTLIST_H

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
	* WzemQPstList: record of TblWzemQPstList
	*/
class WzemQPstList {

public:
	WzemQPstList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVPreset = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMJob;
	std::string stubRefWzemMJob;
	std::string srefIxVPreset;
	double x1Startu;
	double x1Stopu;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQPstList: recordset of TblWzemQPstList
	*/
class ListWzemQPstList {

public:
	ListWzemQPstList();
	ListWzemQPstList(const ListWzemQPstList& src);
	~ListWzemQPstList();

	void clear();
	unsigned int size() const;
	void append(WzemQPstList* rec);

	ListWzemQPstList& operator=(const ListWzemQPstList& src);

public:
	std::vector<WzemQPstList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPstList: C++ wrapper for table TblWzemQPstList
	*/
class TblWzemQPstList {

public:
	TblWzemQPstList();
	virtual ~TblWzemQPstList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPstList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPstList& rst);

	virtual Sbecore::ubigint insertRec(WzemQPstList* rec);
	Sbecore::ubigint insertNewRec(WzemQPstList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVPreset = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQPstList& rst, WzemQPstList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMJob = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVPreset = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);
	virtual void insertRst(ListWzemQPstList& rst);
	virtual void updateRec(WzemQPstList* rec);
	virtual void updateRst(ListWzemQPstList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPstList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPstList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPstList: C++ wrapper for table TblWzemQPstList (MySQL database)
	*/
class MyTblWzemQPstList : public TblWzemQPstList, public Sbecore::MyTable {

public:
	MyTblWzemQPstList();
	~MyTblWzemQPstList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPstList& rst);

	Sbecore::ubigint insertRec(WzemQPstList* rec);
	void insertRst(ListWzemQPstList& rst);
	void updateRec(WzemQPstList* rec);
	void updateRst(ListWzemQPstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPstList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPstList: C++ wrapper for table TblWzemQPstList (PgSQL database)
	*/
class PgTblWzemQPstList : public TblWzemQPstList, public Sbecore::PgTable {

public:
	PgTblWzemQPstList();
	~PgTblWzemQPstList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPstList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPstList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPstList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPstList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPstList& rst);

	Sbecore::ubigint insertRec(WzemQPstList* rec);
	void insertRst(ListWzemQPstList& rst);
	void updateRec(WzemQPstList* rec);
	void updateRst(ListWzemQPstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPstList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPstList: C++ wrapper for table TblWzemQPstList (SQLite database)
	*/
class LiteTblWzemQPstList : public TblWzemQPstList, public Sbecore::LiteTable {

public:
	LiteTblWzemQPstList();
	~LiteTblWzemQPstList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPstList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPstList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPstList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPstList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPstList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPstList& rst);

	Sbecore::ubigint insertRec(WzemQPstList* rec);
	void insertRst(ListWzemQPstList& rst);
	void updateRec(WzemQPstList* rec);
	void updateRst(ListWzemQPstList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPstList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPstList& rst);
};
#endif

#endif

