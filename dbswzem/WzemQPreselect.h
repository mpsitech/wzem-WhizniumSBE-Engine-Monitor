/**
	* \file WzemQPreselect.h
	* Dbs and XML wrapper for table TblWzemQPreselect (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRESELECT_H
#define WZEMQPRESELECT_H

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
	* WzemQPreselect: record of TblWzemQPreselect
	*/
class WzemQPreselect {

public:
	WzemQPreselect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQPreselect: recordset of TblWzemQPreselect
	*/
class ListWzemQPreselect {

public:
	ListWzemQPreselect();
	ListWzemQPreselect(const ListWzemQPreselect& src);
	~ListWzemQPreselect();

	void clear();
	unsigned int size() const;
	void append(WzemQPreselect* rec);

	ListWzemQPreselect& operator=(const ListWzemQPreselect& src);

public:
	std::vector<WzemQPreselect*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPreselect: C++ wrapper for table TblWzemQPreselect
	*/
class TblWzemQPreselect {

public:
	TblWzemQPreselect();
	virtual ~TblWzemQPreselect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPreselect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPreselect& rst);

	virtual Sbecore::ubigint insertRec(WzemQPreselect* rec);
	Sbecore::ubigint insertNewRec(WzemQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQPreselect& rst, WzemQPreselect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWzemQPreselect& rst);
	virtual void updateRec(WzemQPreselect* rec);
	virtual void updateRst(ListWzemQPreselect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPreselect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPreselect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPreselect: C++ wrapper for table TblWzemQPreselect (MySQL database)
	*/
class MyTblWzemQPreselect : public TblWzemQPreselect, public Sbecore::MyTable {

public:
	MyTblWzemQPreselect();
	~MyTblWzemQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPreselect& rst);

	Sbecore::ubigint insertRec(WzemQPreselect* rec);
	void insertRst(ListWzemQPreselect& rst);
	void updateRec(WzemQPreselect* rec);
	void updateRst(ListWzemQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPreselect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPreselect: C++ wrapper for table TblWzemQPreselect (PgSQL database)
	*/
class PgTblWzemQPreselect : public TblWzemQPreselect, public Sbecore::PgTable {

public:
	PgTblWzemQPreselect();
	~PgTblWzemQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPreselect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPreselect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPreselect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPreselect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPreselect& rst);

	Sbecore::ubigint insertRec(WzemQPreselect* rec);
	void insertRst(ListWzemQPreselect& rst);
	void updateRec(WzemQPreselect* rec);
	void updateRst(ListWzemQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPreselect& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPreselect: C++ wrapper for table TblWzemQPreselect (SQLite database)
	*/
class LiteTblWzemQPreselect : public TblWzemQPreselect, public Sbecore::LiteTable {

public:
	LiteTblWzemQPreselect();
	~LiteTblWzemQPreselect();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPreselect** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPreselect& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPreselect** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPreselect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPreselect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPreselect& rst);

	Sbecore::ubigint insertRec(WzemQPreselect* rec);
	void insertRst(ListWzemQPreselect& rst);
	void updateRec(WzemQPreselect* rec);
	void updateRst(ListWzemQPreselect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPreselect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPreselect& rst);
};
#endif

#endif
