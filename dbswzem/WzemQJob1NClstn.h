/**
	* \file WzemQJob1NClstn.h
	* Dbs and XML wrapper for table TblWzemQJob1NClstn (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOB1NCLSTN_H
#define WZEMQJOB1NCLSTN_H

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
	* WzemQJob1NClstn: record of TblWzemQJob1NClstn
	*/
class WzemQJob1NClstn {

public:
	WzemQJob1NClstn(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQJob1NClstn: recordset of TblWzemQJob1NClstn
	*/
class ListWzemQJob1NClstn {

public:
	ListWzemQJob1NClstn();
	ListWzemQJob1NClstn(const ListWzemQJob1NClstn& src);
	~ListWzemQJob1NClstn();

	void clear();
	unsigned int size() const;
	void append(WzemQJob1NClstn* rec);

	ListWzemQJob1NClstn& operator=(const ListWzemQJob1NClstn& src);

public:
	std::vector<WzemQJob1NClstn*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQJob1NClstn: C++ wrapper for table TblWzemQJob1NClstn
	*/
class TblWzemQJob1NClstn {

public:
	TblWzemQJob1NClstn();
	virtual ~TblWzemQJob1NClstn();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NClstn** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NClstn& rst);

	virtual Sbecore::ubigint insertRec(WzemQJob1NClstn* rec);
	Sbecore::ubigint insertNewRec(WzemQJob1NClstn** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQJob1NClstn& rst, WzemQJob1NClstn** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQJob1NClstn& rst);
	virtual void updateRec(WzemQJob1NClstn* rec);
	virtual void updateRst(ListWzemQJob1NClstn& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NClstn** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NClstn& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQJob1NClstn: C++ wrapper for table TblWzemQJob1NClstn (MySQL database)
	*/
class MyTblWzemQJob1NClstn : public TblWzemQJob1NClstn, public Sbecore::MyTable {

public:
	MyTblWzemQJob1NClstn();
	~MyTblWzemQJob1NClstn();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NClstn& rst);

	Sbecore::ubigint insertRec(WzemQJob1NClstn* rec);
	void insertRst(ListWzemQJob1NClstn& rst);
	void updateRec(WzemQJob1NClstn* rec);
	void updateRst(ListWzemQJob1NClstn& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NClstn& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQJob1NClstn: C++ wrapper for table TblWzemQJob1NClstn (PgSQL database)
	*/
class PgTblWzemQJob1NClstn : public TblWzemQJob1NClstn, public Sbecore::PgTable {

public:
	PgTblWzemQJob1NClstn();
	~PgTblWzemQJob1NClstn();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQJob1NClstn& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQJob1NClstn& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NClstn& rst);

	Sbecore::ubigint insertRec(WzemQJob1NClstn* rec);
	void insertRst(ListWzemQJob1NClstn& rst);
	void updateRec(WzemQJob1NClstn* rec);
	void updateRst(ListWzemQJob1NClstn& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NClstn& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQJob1NClstn: C++ wrapper for table TblWzemQJob1NClstn (SQLite database)
	*/
class LiteTblWzemQJob1NClstn : public TblWzemQJob1NClstn, public Sbecore::LiteTable {

public:
	LiteTblWzemQJob1NClstn();
	~LiteTblWzemQJob1NClstn();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NClstn& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NClstn& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NClstn& rst);

	Sbecore::ubigint insertRec(WzemQJob1NClstn* rec);
	void insertRst(ListWzemQJob1NClstn& rst);
	void updateRec(WzemQJob1NClstn* rec);
	void updateRst(ListWzemQJob1NClstn& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NClstn** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NClstn& rst);
};
#endif

#endif
