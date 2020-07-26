/**
	* \file WzemQJob1NCall.h
	* Dbs and XML wrapper for table TblWzemQJob1NCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQJOB1NCALL_H
#define WZEMQJOB1NCALL_H

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
	* WzemQJob1NCall: record of TblWzemQJob1NCall
	*/
class WzemQJob1NCall {

public:
	WzemQJob1NCall(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQJob1NCall: recordset of TblWzemQJob1NCall
	*/
class ListWzemQJob1NCall {

public:
	ListWzemQJob1NCall();
	ListWzemQJob1NCall(const ListWzemQJob1NCall& src);
	~ListWzemQJob1NCall();

	void clear();
	unsigned int size() const;
	void append(WzemQJob1NCall* rec);

	ListWzemQJob1NCall& operator=(const ListWzemQJob1NCall& src);

public:
	std::vector<WzemQJob1NCall*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQJob1NCall: C++ wrapper for table TblWzemQJob1NCall
	*/
class TblWzemQJob1NCall {

public:
	TblWzemQJob1NCall();
	virtual ~TblWzemQJob1NCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NCall& rst);

	virtual Sbecore::ubigint insertRec(WzemQJob1NCall* rec);
	Sbecore::ubigint insertNewRec(WzemQJob1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQJob1NCall& rst, WzemQJob1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQJob1NCall& rst);
	virtual void updateRec(WzemQJob1NCall* rec);
	virtual void updateRst(ListWzemQJob1NCall& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NCall** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQJob1NCall: C++ wrapper for table TblWzemQJob1NCall (MySQL database)
	*/
class MyTblWzemQJob1NCall : public TblWzemQJob1NCall, public Sbecore::MyTable {

public:
	MyTblWzemQJob1NCall();
	~MyTblWzemQJob1NCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NCall& rst);

	Sbecore::ubigint insertRec(WzemQJob1NCall* rec);
	void insertRst(ListWzemQJob1NCall& rst);
	void updateRec(WzemQJob1NCall* rec);
	void updateRst(ListWzemQJob1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NCall& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQJob1NCall: C++ wrapper for table TblWzemQJob1NCall (PgSQL database)
	*/
class PgTblWzemQJob1NCall : public TblWzemQJob1NCall, public Sbecore::PgTable {

public:
	PgTblWzemQJob1NCall();
	~PgTblWzemQJob1NCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQJob1NCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQJob1NCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NCall& rst);

	Sbecore::ubigint insertRec(WzemQJob1NCall* rec);
	void insertRst(ListWzemQJob1NCall& rst);
	void updateRec(WzemQJob1NCall* rec);
	void updateRst(ListWzemQJob1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NCall& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQJob1NCall: C++ wrapper for table TblWzemQJob1NCall (SQLite database)
	*/
class LiteTblWzemQJob1NCall : public TblWzemQJob1NCall, public Sbecore::LiteTable {

public:
	LiteTblWzemQJob1NCall();
	~LiteTblWzemQJob1NCall();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NCall& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NCall& rst);

	Sbecore::ubigint insertRec(WzemQJob1NCall* rec);
	void insertRst(ListWzemQJob1NCall& rst);
	void updateRec(WzemQJob1NCall* rec);
	void updateRst(ListWzemQJob1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NCall& rst);
};
#endif

#endif

