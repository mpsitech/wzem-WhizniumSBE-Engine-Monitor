/**
	* \file WzemQJobSup1NJob.h
	* Dbs and XML wrapper for table TblWzemQJobSup1NJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOBSUP1NJOB_H
#define WZEMQJOBSUP1NJOB_H

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
	* WzemQJobSup1NJob: record of TblWzemQJobSup1NJob
	*/
class WzemQJobSup1NJob {

public:
	WzemQJobSup1NJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQJobSup1NJob: recordset of TblWzemQJobSup1NJob
	*/
class ListWzemQJobSup1NJob {

public:
	ListWzemQJobSup1NJob();
	ListWzemQJobSup1NJob(const ListWzemQJobSup1NJob& src);
	~ListWzemQJobSup1NJob();

	void clear();
	unsigned int size() const;
	void append(WzemQJobSup1NJob* rec);

	ListWzemQJobSup1NJob& operator=(const ListWzemQJobSup1NJob& src);

public:
	std::vector<WzemQJobSup1NJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQJobSup1NJob: C++ wrapper for table TblWzemQJobSup1NJob
	*/
class TblWzemQJobSup1NJob {

public:
	TblWzemQJobSup1NJob();
	virtual ~TblWzemQJobSup1NJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQJobSup1NJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobSup1NJob& rst);

	virtual Sbecore::ubigint insertRec(WzemQJobSup1NJob* rec);
	Sbecore::ubigint insertNewRec(WzemQJobSup1NJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQJobSup1NJob& rst, WzemQJobSup1NJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQJobSup1NJob& rst);
	virtual void updateRec(WzemQJobSup1NJob* rec);
	virtual void updateRst(ListWzemQJobSup1NJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQJobSup1NJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobSup1NJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQJobSup1NJob: C++ wrapper for table TblWzemQJobSup1NJob (MySQL database)
	*/
class MyTblWzemQJobSup1NJob : public TblWzemQJobSup1NJob, public Sbecore::MyTable {

public:
	MyTblWzemQJobSup1NJob();
	~MyTblWzemQJobSup1NJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobSup1NJob& rst);

	Sbecore::ubigint insertRec(WzemQJobSup1NJob* rec);
	void insertRst(ListWzemQJobSup1NJob& rst);
	void updateRec(WzemQJobSup1NJob* rec);
	void updateRst(ListWzemQJobSup1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobSup1NJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQJobSup1NJob: C++ wrapper for table TblWzemQJobSup1NJob (PgSQL database)
	*/
class PgTblWzemQJobSup1NJob : public TblWzemQJobSup1NJob, public Sbecore::PgTable {

public:
	PgTblWzemQJobSup1NJob();
	~PgTblWzemQJobSup1NJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQJobSup1NJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQJobSup1NJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobSup1NJob& rst);

	Sbecore::ubigint insertRec(WzemQJobSup1NJob* rec);
	void insertRst(ListWzemQJobSup1NJob& rst);
	void updateRec(WzemQJobSup1NJob* rec);
	void updateRst(ListWzemQJobSup1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobSup1NJob& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQJobSup1NJob: C++ wrapper for table TblWzemQJobSup1NJob (SQLite database)
	*/
class LiteTblWzemQJobSup1NJob : public TblWzemQJobSup1NJob, public Sbecore::LiteTable {

public:
	LiteTblWzemQJobSup1NJob();
	~LiteTblWzemQJobSup1NJob();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQJobSup1NJob& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQJobSup1NJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJobSup1NJob& rst);

	Sbecore::ubigint insertRec(WzemQJobSup1NJob* rec);
	void insertRst(ListWzemQJobSup1NJob& rst);
	void updateRec(WzemQJobSup1NJob* rec);
	void updateRst(ListWzemQJobSup1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJobSup1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJobSup1NJob& rst);
};
#endif

#endif

