/**
	* \file WzemQPrsADetail.h
	* Dbs and XML wrapper for table TblWzemQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRSADETAIL_H
#define WZEMQPRSADETAIL_H

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
	* WzemQPrsADetail: record of TblWzemQPrsADetail
	*/
class WzemQPrsADetail {

public:
	WzemQPrsADetail(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQPrsADetail: recordset of TblWzemQPrsADetail
	*/
class ListWzemQPrsADetail {

public:
	ListWzemQPrsADetail();
	ListWzemQPrsADetail(const ListWzemQPrsADetail& src);
	~ListWzemQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(WzemQPrsADetail* rec);

	ListWzemQPrsADetail& operator=(const ListWzemQPrsADetail& src);

public:
	std::vector<WzemQPrsADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPrsADetail: C++ wrapper for table TblWzemQPrsADetail
	*/
class TblWzemQPrsADetail {

public:
	TblWzemQPrsADetail();
	virtual ~TblWzemQPrsADetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsADetail& rst);

	virtual Sbecore::ubigint insertRec(WzemQPrsADetail* rec);
	Sbecore::ubigint insertNewRec(WzemQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQPrsADetail& rst, WzemQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWzemQPrsADetail& rst);
	virtual void updateRec(WzemQPrsADetail* rec);
	virtual void updateRst(ListWzemQPrsADetail& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsADetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPrsADetail: C++ wrapper for table TblWzemQPrsADetail (MySQL database)
	*/
class MyTblWzemQPrsADetail : public TblWzemQPrsADetail, public Sbecore::MyTable {

public:
	MyTblWzemQPrsADetail();
	~MyTblWzemQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsADetail& rst);

	Sbecore::ubigint insertRec(WzemQPrsADetail* rec);
	void insertRst(ListWzemQPrsADetail& rst);
	void updateRec(WzemQPrsADetail* rec);
	void updateRst(ListWzemQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsADetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPrsADetail: C++ wrapper for table TblWzemQPrsADetail (PgSQL database)
	*/
class PgTblWzemQPrsADetail : public TblWzemQPrsADetail, public Sbecore::PgTable {

public:
	PgTblWzemQPrsADetail();
	~PgTblWzemQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPrsADetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPrsADetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsADetail& rst);

	Sbecore::ubigint insertRec(WzemQPrsADetail* rec);
	void insertRst(ListWzemQPrsADetail& rst);
	void updateRec(WzemQPrsADetail* rec);
	void updateRst(ListWzemQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsADetail& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPrsADetail: C++ wrapper for table TblWzemQPrsADetail (SQLite database)
	*/
class LiteTblWzemQPrsADetail : public TblWzemQPrsADetail, public Sbecore::LiteTable {

public:
	LiteTblWzemQPrsADetail();
	~LiteTblWzemQPrsADetail();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPrsADetail& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPrsADetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsADetail& rst);

	Sbecore::ubigint insertRec(WzemQPrsADetail* rec);
	void insertRst(ListWzemQPrsADetail& rst);
	void updateRec(WzemQPrsADetail* rec);
	void updateRst(ListWzemQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsADetail& rst);
};
#endif

#endif
