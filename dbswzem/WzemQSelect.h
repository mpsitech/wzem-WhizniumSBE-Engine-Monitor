/**
	* \file WzemQSelect.h
	* Dbs and XML wrapper for table TblWzemQSelect (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQSELECT_H
#define WZEMQSELECT_H

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
	* WzemQSelect: record of TblWzemQSelect
	*/
class WzemQSelect {

public:
	WzemQSelect(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::uint ix;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQSelect: recordset of TblWzemQSelect
	*/
class ListWzemQSelect {

public:
	ListWzemQSelect();
	ListWzemQSelect(const ListWzemQSelect& src);
	~ListWzemQSelect();

	void clear();
	unsigned int size() const;
	void append(WzemQSelect* rec);

	ListWzemQSelect& operator=(const ListWzemQSelect& src);

public:
	std::vector<WzemQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQSelect: C++ wrapper for table TblWzemQSelect
	*/
class TblWzemQSelect {

public:
	TblWzemQSelect();
	virtual ~TblWzemQSelect();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQSelect** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQSelect& rst);

	virtual Sbecore::ubigint insertRec(WzemQSelect* rec);
	Sbecore::ubigint insertNewRec(WzemQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemQSelect& rst, WzemQSelect** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::uint ix = 0, const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWzemQSelect& rst);
	virtual void updateRec(WzemQSelect* rec);
	virtual void updateRst(ListWzemQSelect& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQSelect** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQSelect& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQSelect: C++ wrapper for table TblWzemQSelect (MySQL database)
	*/
class MyTblWzemQSelect : public TblWzemQSelect, public Sbecore::MyTable {

public:
	MyTblWzemQSelect();
	~MyTblWzemQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQSelect& rst);

	Sbecore::ubigint insertRec(WzemQSelect* rec);
	void insertRst(ListWzemQSelect& rst);
	void updateRec(WzemQSelect* rec);
	void updateRst(ListWzemQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQSelect& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQSelect: C++ wrapper for table TblWzemQSelect (PgSQL database)
	*/
class PgTblWzemQSelect : public TblWzemQSelect, public Sbecore::PgTable {

public:
	PgTblWzemQSelect();
	~PgTblWzemQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQSelect** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQSelect& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQSelect** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQSelect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQSelect& rst);

	Sbecore::ubigint insertRec(WzemQSelect* rec);
	void insertRst(ListWzemQSelect& rst);
	void updateRec(WzemQSelect* rec);
	void updateRst(ListWzemQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQSelect& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQSelect: C++ wrapper for table TblWzemQSelect (SQLite database)
	*/
class LiteTblWzemQSelect : public TblWzemQSelect, public Sbecore::LiteTable {

public:
	LiteTblWzemQSelect();
	~LiteTblWzemQSelect();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQSelect** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQSelect& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQSelect** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQSelect& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQSelect** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQSelect& rst);

	Sbecore::ubigint insertRec(WzemQSelect* rec);
	void insertRst(ListWzemQSelect& rst);
	void updateRec(WzemQSelect* rec);
	void updateRst(ListWzemQSelect& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQSelect** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQSelect& rst);
};
#endif

#endif

