/**
	* \file WzemQPrd1NEvent.h
	* Dbs and XML wrapper for table TblWzemQPrd1NEvent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQPRD1NEVENT_H
#define WZEMQPRD1NEVENT_H

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
	* WzemQPrd1NEvent: record of TblWzemQPrd1NEvent
	*/
class WzemQPrd1NEvent {

public:
	WzemQPrd1NEvent(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQPrd1NEvent: recordset of TblWzemQPrd1NEvent
	*/
class ListWzemQPrd1NEvent {

public:
	ListWzemQPrd1NEvent();
	ListWzemQPrd1NEvent(const ListWzemQPrd1NEvent& src);
	~ListWzemQPrd1NEvent();

	void clear();
	unsigned int size() const;
	void append(WzemQPrd1NEvent* rec);

	ListWzemQPrd1NEvent& operator=(const ListWzemQPrd1NEvent& src);

public:
	std::vector<WzemQPrd1NEvent*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPrd1NEvent: C++ wrapper for table TblWzemQPrd1NEvent
	*/
class TblWzemQPrd1NEvent {

public:
	TblWzemQPrd1NEvent();
	virtual ~TblWzemQPrd1NEvent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NEvent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NEvent& rst);

	virtual Sbecore::ubigint insertRec(WzemQPrd1NEvent* rec);
	Sbecore::ubigint insertNewRec(WzemQPrd1NEvent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQPrd1NEvent& rst, WzemQPrd1NEvent** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQPrd1NEvent& rst);
	virtual void updateRec(WzemQPrd1NEvent* rec);
	virtual void updateRst(ListWzemQPrd1NEvent& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NEvent** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NEvent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPrd1NEvent: C++ wrapper for table TblWzemQPrd1NEvent (MySQL database)
	*/
class MyTblWzemQPrd1NEvent : public TblWzemQPrd1NEvent, public Sbecore::MyTable {

public:
	MyTblWzemQPrd1NEvent();
	~MyTblWzemQPrd1NEvent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NEvent& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NEvent* rec);
	void insertRst(ListWzemQPrd1NEvent& rst);
	void updateRec(WzemQPrd1NEvent* rec);
	void updateRst(ListWzemQPrd1NEvent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NEvent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPrd1NEvent: C++ wrapper for table TblWzemQPrd1NEvent (PgSQL database)
	*/
class PgTblWzemQPrd1NEvent : public TblWzemQPrd1NEvent, public Sbecore::PgTable {

public:
	PgTblWzemQPrd1NEvent();
	~PgTblWzemQPrd1NEvent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPrd1NEvent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPrd1NEvent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NEvent& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NEvent* rec);
	void insertRst(ListWzemQPrd1NEvent& rst);
	void updateRec(WzemQPrd1NEvent* rec);
	void updateRst(ListWzemQPrd1NEvent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NEvent& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPrd1NEvent: C++ wrapper for table TblWzemQPrd1NEvent (SQLite database)
	*/
class LiteTblWzemQPrd1NEvent : public TblWzemQPrd1NEvent, public Sbecore::LiteTable {

public:
	LiteTblWzemQPrd1NEvent();
	~LiteTblWzemQPrd1NEvent();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPrd1NEvent& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPrd1NEvent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NEvent& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NEvent* rec);
	void insertRst(ListWzemQPrd1NEvent& rst);
	void updateRec(WzemQPrd1NEvent* rec);
	void updateRst(ListWzemQPrd1NEvent& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NEvent** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NEvent& rst);
};
#endif

#endif

