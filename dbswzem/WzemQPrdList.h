/**
	* \file WzemQPrdList.h
	* Dbs and XML wrapper for table TblWzemQPrdList (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQPRDLIST_H
#define WZEMQPRDLIST_H

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
	* WzemQPrdList: record of TblWzemQPrdList
	*/
class WzemQPrdList {

public:
	WzemQPrdList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Version = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Version;
	Sbecore::uint start;
	std::string ftmStart;
	Sbecore::uint stop;
	std::string ftmStop;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQPrdList: recordset of TblWzemQPrdList
	*/
class ListWzemQPrdList {

public:
	ListWzemQPrdList();
	ListWzemQPrdList(const ListWzemQPrdList& src);
	~ListWzemQPrdList();

	void clear();
	unsigned int size() const;
	void append(WzemQPrdList* rec);

	ListWzemQPrdList& operator=(const ListWzemQPrdList& src);

public:
	std::vector<WzemQPrdList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPrdList: C++ wrapper for table TblWzemQPrdList
	*/
class TblWzemQPrdList {

public:
	TblWzemQPrdList();
	virtual ~TblWzemQPrdList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPrdList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrdList& rst);

	virtual Sbecore::ubigint insertRec(WzemQPrdList* rec);
	Sbecore::ubigint insertNewRec(WzemQPrdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Version = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQPrdList& rst, WzemQPrdList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Version = "", const Sbecore::uint start = 0, const std::string ftmStart = "", const Sbecore::uint stop = 0, const std::string ftmStop = "");
	virtual void insertRst(ListWzemQPrdList& rst);
	virtual void updateRec(WzemQPrdList* rec);
	virtual void updateRst(ListWzemQPrdList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPrdList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrdList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPrdList: C++ wrapper for table TblWzemQPrdList (MySQL database)
	*/
class MyTblWzemQPrdList : public TblWzemQPrdList, public Sbecore::MyTable {

public:
	MyTblWzemQPrdList();
	~MyTblWzemQPrdList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrdList& rst);

	Sbecore::ubigint insertRec(WzemQPrdList* rec);
	void insertRst(ListWzemQPrdList& rst);
	void updateRec(WzemQPrdList* rec);
	void updateRst(ListWzemQPrdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrdList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPrdList: C++ wrapper for table TblWzemQPrdList (PgSQL database)
	*/
class PgTblWzemQPrdList : public TblWzemQPrdList, public Sbecore::PgTable {

public:
	PgTblWzemQPrdList();
	~PgTblWzemQPrdList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPrdList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPrdList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPrdList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPrdList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrdList& rst);

	Sbecore::ubigint insertRec(WzemQPrdList* rec);
	void insertRst(ListWzemQPrdList& rst);
	void updateRec(WzemQPrdList* rec);
	void updateRst(ListWzemQPrdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrdList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPrdList: C++ wrapper for table TblWzemQPrdList (SQLite database)
	*/
class LiteTblWzemQPrdList : public TblWzemQPrdList, public Sbecore::LiteTable {

public:
	LiteTblWzemQPrdList();
	~LiteTblWzemQPrdList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPrdList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPrdList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPrdList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPrdList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrdList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrdList& rst);

	Sbecore::ubigint insertRec(WzemQPrdList* rec);
	void insertRst(ListWzemQPrdList& rst);
	void updateRec(WzemQPrdList* rec);
	void updateRst(ListWzemQPrdList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrdList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrdList& rst);
};
#endif

#endif

