/**
	* \file WzemQJob1NOp.h
	* Dbs and XML wrapper for table TblWzemQJob1NOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOB1NOP_H
#define WZEMQJOB1NOP_H

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
	* WzemQJob1NOp: record of TblWzemQJob1NOp
	*/
class WzemQJob1NOp {

public:
	WzemQJob1NOp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQJob1NOp: recordset of TblWzemQJob1NOp
	*/
class ListWzemQJob1NOp {

public:
	ListWzemQJob1NOp();
	ListWzemQJob1NOp(const ListWzemQJob1NOp& src);
	~ListWzemQJob1NOp();

	void clear();
	unsigned int size() const;
	void append(WzemQJob1NOp* rec);

	ListWzemQJob1NOp& operator=(const ListWzemQJob1NOp& src);

public:
	std::vector<WzemQJob1NOp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQJob1NOp: C++ wrapper for table TblWzemQJob1NOp
	*/
class TblWzemQJob1NOp {

public:
	TblWzemQJob1NOp();
	virtual ~TblWzemQJob1NOp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NOp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NOp& rst);

	virtual Sbecore::ubigint insertRec(WzemQJob1NOp* rec);
	Sbecore::ubigint insertNewRec(WzemQJob1NOp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQJob1NOp& rst, WzemQJob1NOp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQJob1NOp& rst);
	virtual void updateRec(WzemQJob1NOp* rec);
	virtual void updateRst(ListWzemQJob1NOp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NOp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NOp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQJob1NOp: C++ wrapper for table TblWzemQJob1NOp (MySQL database)
	*/
class MyTblWzemQJob1NOp : public TblWzemQJob1NOp, public Sbecore::MyTable {

public:
	MyTblWzemQJob1NOp();
	~MyTblWzemQJob1NOp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NOp& rst);

	Sbecore::ubigint insertRec(WzemQJob1NOp* rec);
	void insertRst(ListWzemQJob1NOp& rst);
	void updateRec(WzemQJob1NOp* rec);
	void updateRst(ListWzemQJob1NOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NOp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQJob1NOp: C++ wrapper for table TblWzemQJob1NOp (PgSQL database)
	*/
class PgTblWzemQJob1NOp : public TblWzemQJob1NOp, public Sbecore::PgTable {

public:
	PgTblWzemQJob1NOp();
	~PgTblWzemQJob1NOp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQJob1NOp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQJob1NOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NOp& rst);

	Sbecore::ubigint insertRec(WzemQJob1NOp* rec);
	void insertRst(ListWzemQJob1NOp& rst);
	void updateRec(WzemQJob1NOp* rec);
	void updateRst(ListWzemQJob1NOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NOp& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQJob1NOp: C++ wrapper for table TblWzemQJob1NOp (SQLite database)
	*/
class LiteTblWzemQJob1NOp : public TblWzemQJob1NOp, public Sbecore::LiteTable {

public:
	LiteTblWzemQJob1NOp();
	~LiteTblWzemQJob1NOp();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NOp& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NOp& rst);

	Sbecore::ubigint insertRec(WzemQJob1NOp* rec);
	void insertRst(ListWzemQJob1NOp& rst);
	void updateRec(WzemQJob1NOp* rec);
	void updateRst(ListWzemQJob1NOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NOp& rst);
};
#endif

#endif

