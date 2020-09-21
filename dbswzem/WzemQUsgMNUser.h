/**
	* \file WzemQUsgMNUser.h
	* Dbs and XML wrapper for table TblWzemQUsgMNUser (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQUSGMNUSER_H
#define WZEMQUSGMNUSER_H

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
	* WzemQUsgMNUser: record of TblWzemQUsgMNUser
	*/
class WzemQUsgMNUser {

public:
	WzemQUsgMNUser(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixWzemVUserlevel;
	std::string srefIxWzemVUserlevel;
	std::string titIxWzemVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQUsgMNUser: recordset of TblWzemQUsgMNUser
	*/
class ListWzemQUsgMNUser {

public:
	ListWzemQUsgMNUser();
	ListWzemQUsgMNUser(const ListWzemQUsgMNUser& src);
	~ListWzemQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(WzemQUsgMNUser* rec);

	ListWzemQUsgMNUser& operator=(const ListWzemQUsgMNUser& src);

public:
	std::vector<WzemQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsgMNUser: C++ wrapper for table TblWzemQUsgMNUser
	*/
class TblWzemQUsgMNUser {

public:
	TblWzemQUsgMNUser();
	virtual ~TblWzemQUsgMNUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgMNUser& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsgMNUser* rec);
	Sbecore::ubigint insertNewRec(WzemQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsgMNUser& rst, WzemQUsgMNUser** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");
	virtual void insertRst(ListWzemQUsgMNUser& rst);
	virtual void updateRec(WzemQUsgMNUser* rec);
	virtual void updateRst(ListWzemQUsgMNUser& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgMNUser** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgMNUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsgMNUser: C++ wrapper for table TblWzemQUsgMNUser (MySQL database)
	*/
class MyTblWzemQUsgMNUser : public TblWzemQUsgMNUser, public Sbecore::MyTable {

public:
	MyTblWzemQUsgMNUser();
	~MyTblWzemQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WzemQUsgMNUser* rec);
	void insertRst(ListWzemQUsgMNUser& rst);
	void updateRec(WzemQUsgMNUser* rec);
	void updateRst(ListWzemQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgMNUser& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsgMNUser: C++ wrapper for table TblWzemQUsgMNUser (PgSQL database)
	*/
class PgTblWzemQUsgMNUser : public TblWzemQUsgMNUser, public Sbecore::PgTable {

public:
	PgTblWzemQUsgMNUser();
	~PgTblWzemQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsgMNUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsgMNUser& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WzemQUsgMNUser* rec);
	void insertRst(ListWzemQUsgMNUser& rst);
	void updateRec(WzemQUsgMNUser* rec);
	void updateRst(ListWzemQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgMNUser& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsgMNUser: C++ wrapper for table TblWzemQUsgMNUser (SQLite database)
	*/
class LiteTblWzemQUsgMNUser : public TblWzemQUsgMNUser, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsgMNUser();
	~LiteTblWzemQUsgMNUser();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsgMNUser& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsgMNUser& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgMNUser& rst);

	Sbecore::ubigint insertRec(WzemQUsgMNUser* rec);
	void insertRst(ListWzemQUsgMNUser& rst);
	void updateRec(WzemQUsgMNUser* rec);
	void updateRst(ListWzemQUsgMNUser& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgMNUser** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgMNUser& rst);
};
#endif

#endif

