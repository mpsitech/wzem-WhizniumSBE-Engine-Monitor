/**
	* \file WzemQUsgList.h
	* Dbs and XML wrapper for table TblWzemQUsgList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSGLIST_H
#define WZEMQUSGLIST_H

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
	* WzemQUsgList: record of TblWzemQUsgList
	*/
class WzemQUsgList {

public:
	WzemQUsgList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string sref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQUsgList: recordset of TblWzemQUsgList
	*/
class ListWzemQUsgList {

public:
	ListWzemQUsgList();
	ListWzemQUsgList(const ListWzemQUsgList& src);
	~ListWzemQUsgList();

	void clear();
	unsigned int size() const;
	void append(WzemQUsgList* rec);

	ListWzemQUsgList& operator=(const ListWzemQUsgList& src);

public:
	std::vector<WzemQUsgList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsgList: C++ wrapper for table TblWzemQUsgList
	*/
class TblWzemQUsgList {

public:
	TblWzemQUsgList();
	virtual ~TblWzemQUsgList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsgList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgList& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsgList* rec);
	Sbecore::ubigint insertNewRec(WzemQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsgList& rst, WzemQUsgList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string sref = "");
	virtual void insertRst(ListWzemQUsgList& rst);
	virtual void updateRec(WzemQUsgList* rec);
	virtual void updateRst(ListWzemQUsgList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsgList: C++ wrapper for table TblWzemQUsgList (MySQL database)
	*/
class MyTblWzemQUsgList : public TblWzemQUsgList, public Sbecore::MyTable {

public:
	MyTblWzemQUsgList();
	~MyTblWzemQUsgList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgList& rst);

	Sbecore::ubigint insertRec(WzemQUsgList* rec);
	void insertRst(ListWzemQUsgList& rst);
	void updateRec(WzemQUsgList* rec);
	void updateRst(ListWzemQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsgList: C++ wrapper for table TblWzemQUsgList (PgSQL database)
	*/
class PgTblWzemQUsgList : public TblWzemQUsgList, public Sbecore::PgTable {

public:
	PgTblWzemQUsgList();
	~PgTblWzemQUsgList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsgList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsgList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsgList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgList& rst);

	Sbecore::ubigint insertRec(WzemQUsgList* rec);
	void insertRst(ListWzemQUsgList& rst);
	void updateRec(WzemQUsgList* rec);
	void updateRst(ListWzemQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsgList: C++ wrapper for table TblWzemQUsgList (SQLite database)
	*/
class LiteTblWzemQUsgList : public TblWzemQUsgList, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsgList();
	~LiteTblWzemQUsgList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsgList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsgList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsgList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsgList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgList& rst);

	Sbecore::ubigint insertRec(WzemQUsgList* rec);
	void insertRst(ListWzemQUsgList& rst);
	void updateRec(WzemQUsgList* rec);
	void updateRst(ListWzemQUsgList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgList& rst);
};
#endif

#endif

