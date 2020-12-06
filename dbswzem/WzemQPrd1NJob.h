/**
	* \file WzemQPrd1NJob.h
	* Dbs and XML wrapper for table TblWzemQPrd1NJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRD1NJOB_H
#define WZEMQPRD1NJOB_H

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
	* WzemQPrd1NJob: record of TblWzemQPrd1NJob
	*/
class WzemQPrd1NJob {

public:
	WzemQPrd1NJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQPrd1NJob: recordset of TblWzemQPrd1NJob
	*/
class ListWzemQPrd1NJob {

public:
	ListWzemQPrd1NJob();
	ListWzemQPrd1NJob(const ListWzemQPrd1NJob& src);
	~ListWzemQPrd1NJob();

	void clear();
	unsigned int size() const;
	void append(WzemQPrd1NJob* rec);

	ListWzemQPrd1NJob& operator=(const ListWzemQPrd1NJob& src);

public:
	std::vector<WzemQPrd1NJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPrd1NJob: C++ wrapper for table TblWzemQPrd1NJob
	*/
class TblWzemQPrd1NJob {

public:
	TblWzemQPrd1NJob();
	virtual ~TblWzemQPrd1NJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NJob& rst);

	virtual Sbecore::ubigint insertRec(WzemQPrd1NJob* rec);
	Sbecore::ubigint insertNewRec(WzemQPrd1NJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQPrd1NJob& rst, WzemQPrd1NJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQPrd1NJob& rst);
	virtual void updateRec(WzemQPrd1NJob* rec);
	virtual void updateRst(ListWzemQPrd1NJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPrd1NJob: C++ wrapper for table TblWzemQPrd1NJob (MySQL database)
	*/
class MyTblWzemQPrd1NJob : public TblWzemQPrd1NJob, public Sbecore::MyTable {

public:
	MyTblWzemQPrd1NJob();
	~MyTblWzemQPrd1NJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NJob& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NJob* rec);
	void insertRst(ListWzemQPrd1NJob& rst);
	void updateRec(WzemQPrd1NJob* rec);
	void updateRst(ListWzemQPrd1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPrd1NJob: C++ wrapper for table TblWzemQPrd1NJob (PgSQL database)
	*/
class PgTblWzemQPrd1NJob : public TblWzemQPrd1NJob, public Sbecore::PgTable {

public:
	PgTblWzemQPrd1NJob();
	~PgTblWzemQPrd1NJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPrd1NJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPrd1NJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NJob& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NJob* rec);
	void insertRst(ListWzemQPrd1NJob& rst);
	void updateRec(WzemQPrd1NJob* rec);
	void updateRst(ListWzemQPrd1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NJob& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPrd1NJob: C++ wrapper for table TblWzemQPrd1NJob (SQLite database)
	*/
class LiteTblWzemQPrd1NJob : public TblWzemQPrd1NJob, public Sbecore::LiteTable {

public:
	LiteTblWzemQPrd1NJob();
	~LiteTblWzemQPrd1NJob();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPrd1NJob& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPrd1NJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrd1NJob& rst);

	Sbecore::ubigint insertRec(WzemQPrd1NJob* rec);
	void insertRst(ListWzemQPrd1NJob& rst);
	void updateRec(WzemQPrd1NJob* rec);
	void updateRst(ListWzemQPrd1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrd1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrd1NJob& rst);
};
#endif

#endif

