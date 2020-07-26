/**
	* \file WzemQUsr1NSession.h
	* Dbs and XML wrapper for table TblWzemQUsr1NSession (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQUSR1NSESSION_H
#define WZEMQUSR1NSESSION_H

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
	* WzemQUsr1NSession: record of TblWzemQUsr1NSession
	*/
class WzemQUsr1NSession {

public:
	WzemQUsr1NSession(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQUsr1NSession: recordset of TblWzemQUsr1NSession
	*/
class ListWzemQUsr1NSession {

public:
	ListWzemQUsr1NSession();
	ListWzemQUsr1NSession(const ListWzemQUsr1NSession& src);
	~ListWzemQUsr1NSession();

	void clear();
	unsigned int size() const;
	void append(WzemQUsr1NSession* rec);

	ListWzemQUsr1NSession& operator=(const ListWzemQUsr1NSession& src);

public:
	std::vector<WzemQUsr1NSession*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsr1NSession: C++ wrapper for table TblWzemQUsr1NSession
	*/
class TblWzemQUsr1NSession {

public:
	TblWzemQUsr1NSession();
	virtual ~TblWzemQUsr1NSession();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsr1NSession& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsr1NSession* rec);
	Sbecore::ubigint insertNewRec(WzemQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsr1NSession& rst, WzemQUsr1NSession** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQUsr1NSession& rst);
	virtual void updateRec(WzemQUsr1NSession* rec);
	virtual void updateRst(ListWzemQUsr1NSession& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsr1NSession** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsr1NSession& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsr1NSession: C++ wrapper for table TblWzemQUsr1NSession (MySQL database)
	*/
class MyTblWzemQUsr1NSession : public TblWzemQUsr1NSession, public Sbecore::MyTable {

public:
	MyTblWzemQUsr1NSession();
	~MyTblWzemQUsr1NSession();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WzemQUsr1NSession* rec);
	void insertRst(ListWzemQUsr1NSession& rst);
	void updateRec(WzemQUsr1NSession* rec);
	void updateRst(ListWzemQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsr1NSession& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsr1NSession: C++ wrapper for table TblWzemQUsr1NSession (PgSQL database)
	*/
class PgTblWzemQUsr1NSession : public TblWzemQUsr1NSession, public Sbecore::PgTable {

public:
	PgTblWzemQUsr1NSession();
	~PgTblWzemQUsr1NSession();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsr1NSession& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsr1NSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WzemQUsr1NSession* rec);
	void insertRst(ListWzemQUsr1NSession& rst);
	void updateRec(WzemQUsr1NSession* rec);
	void updateRst(ListWzemQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsr1NSession& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsr1NSession: C++ wrapper for table TblWzemQUsr1NSession (SQLite database)
	*/
class LiteTblWzemQUsr1NSession : public TblWzemQUsr1NSession, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsr1NSession();
	~LiteTblWzemQUsr1NSession();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsr1NSession& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsr1NSession& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsr1NSession& rst);

	Sbecore::ubigint insertRec(WzemQUsr1NSession* rec);
	void insertRst(ListWzemQUsr1NSession& rst);
	void updateRec(WzemQUsr1NSession* rec);
	void updateRst(ListWzemQUsr1NSession& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsr1NSession** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsr1NSession& rst);
};
#endif

#endif

