/**
	* \file WzemQJob1NPreset.h
	* Dbs and XML wrapper for table TblWzemQJob1NPreset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQJOB1NPRESET_H
#define WZEMQJOB1NPRESET_H

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
	* WzemQJob1NPreset: record of TblWzemQJob1NPreset
	*/
class WzemQJob1NPreset {

public:
	WzemQJob1NPreset(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWzemQJob1NPreset: recordset of TblWzemQJob1NPreset
	*/
class ListWzemQJob1NPreset {

public:
	ListWzemQJob1NPreset();
	ListWzemQJob1NPreset(const ListWzemQJob1NPreset& src);
	~ListWzemQJob1NPreset();

	void clear();
	unsigned int size() const;
	void append(WzemQJob1NPreset* rec);

	ListWzemQJob1NPreset& operator=(const ListWzemQJob1NPreset& src);

public:
	std::vector<WzemQJob1NPreset*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQJob1NPreset: C++ wrapper for table TblWzemQJob1NPreset
	*/
class TblWzemQJob1NPreset {

public:
	TblWzemQJob1NPreset();
	virtual ~TblWzemQJob1NPreset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NPreset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NPreset& rst);

	virtual Sbecore::ubigint insertRec(WzemQJob1NPreset* rec);
	Sbecore::ubigint insertNewRec(WzemQJob1NPreset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQJob1NPreset& rst, WzemQJob1NPreset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWzemQJob1NPreset& rst);
	virtual void updateRec(WzemQJob1NPreset* rec);
	virtual void updateRst(ListWzemQJob1NPreset& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NPreset** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NPreset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQJob1NPreset: C++ wrapper for table TblWzemQJob1NPreset (MySQL database)
	*/
class MyTblWzemQJob1NPreset : public TblWzemQJob1NPreset, public Sbecore::MyTable {

public:
	MyTblWzemQJob1NPreset();
	~MyTblWzemQJob1NPreset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NPreset& rst);

	Sbecore::ubigint insertRec(WzemQJob1NPreset* rec);
	void insertRst(ListWzemQJob1NPreset& rst);
	void updateRec(WzemQJob1NPreset* rec);
	void updateRst(ListWzemQJob1NPreset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NPreset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQJob1NPreset: C++ wrapper for table TblWzemQJob1NPreset (PgSQL database)
	*/
class PgTblWzemQJob1NPreset : public TblWzemQJob1NPreset, public Sbecore::PgTable {

public:
	PgTblWzemQJob1NPreset();
	~PgTblWzemQJob1NPreset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQJob1NPreset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQJob1NPreset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NPreset& rst);

	Sbecore::ubigint insertRec(WzemQJob1NPreset* rec);
	void insertRst(ListWzemQJob1NPreset& rst);
	void updateRec(WzemQJob1NPreset* rec);
	void updateRst(ListWzemQJob1NPreset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NPreset& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQJob1NPreset: C++ wrapper for table TblWzemQJob1NPreset (SQLite database)
	*/
class LiteTblWzemQJob1NPreset : public TblWzemQJob1NPreset, public Sbecore::LiteTable {

public:
	LiteTblWzemQJob1NPreset();
	~LiteTblWzemQJob1NPreset();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NPreset& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQJob1NPreset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQJob1NPreset& rst);

	Sbecore::ubigint insertRec(WzemQJob1NPreset* rec);
	void insertRst(ListWzemQJob1NPreset& rst);
	void updateRec(WzemQJob1NPreset* rec);
	void updateRst(ListWzemQJob1NPreset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQJob1NPreset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQJob1NPreset& rst);
};
#endif

#endif

