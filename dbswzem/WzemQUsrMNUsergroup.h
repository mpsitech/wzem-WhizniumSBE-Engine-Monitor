/**
	* \file WzemQUsrMNUsergroup.h
	* Dbs and XML wrapper for table TblWzemQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSRMNUSERGROUP_H
#define WZEMQUSRMNUSERGROUP_H

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
	* WzemQUsrMNUsergroup: record of TblWzemQUsrMNUsergroup
	*/
class WzemQUsrMNUsergroup {

public:
	WzemQUsrMNUsergroup(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");

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
	* ListWzemQUsrMNUsergroup: recordset of TblWzemQUsrMNUsergroup
	*/
class ListWzemQUsrMNUsergroup {

public:
	ListWzemQUsrMNUsergroup();
	ListWzemQUsrMNUsergroup(const ListWzemQUsrMNUsergroup& src);
	~ListWzemQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(WzemQUsrMNUsergroup* rec);

	ListWzemQUsrMNUsergroup& operator=(const ListWzemQUsrMNUsergroup& src);

public:
	std::vector<WzemQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsrMNUsergroup: C++ wrapper for table TblWzemQUsrMNUsergroup
	*/
class TblWzemQUsrMNUsergroup {

public:
	TblWzemQUsrMNUsergroup();
	virtual ~TblWzemQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrMNUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsrMNUsergroup* rec);
	Sbecore::ubigint insertNewRec(WzemQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsrMNUsergroup& rst, WzemQUsrMNUsergroup** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");
	virtual void insertRst(ListWzemQUsrMNUsergroup& rst);
	virtual void updateRec(WzemQUsrMNUsergroup* rec);
	virtual void updateRst(ListWzemQUsrMNUsergroup& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrMNUsergroup** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrMNUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsrMNUsergroup: C++ wrapper for table TblWzemQUsrMNUsergroup (MySQL database)
	*/
class MyTblWzemQUsrMNUsergroup : public TblWzemQUsrMNUsergroup, public Sbecore::MyTable {

public:
	MyTblWzemQUsrMNUsergroup();
	~MyTblWzemQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WzemQUsrMNUsergroup* rec);
	void insertRst(ListWzemQUsrMNUsergroup& rst);
	void updateRec(WzemQUsrMNUsergroup* rec);
	void updateRst(ListWzemQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrMNUsergroup& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsrMNUsergroup: C++ wrapper for table TblWzemQUsrMNUsergroup (PgSQL database)
	*/
class PgTblWzemQUsrMNUsergroup : public TblWzemQUsrMNUsergroup, public Sbecore::PgTable {

public:
	PgTblWzemQUsrMNUsergroup();
	~PgTblWzemQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsrMNUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WzemQUsrMNUsergroup* rec);
	void insertRst(ListWzemQUsrMNUsergroup& rst);
	void updateRec(WzemQUsrMNUsergroup* rec);
	void updateRst(ListWzemQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrMNUsergroup& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsrMNUsergroup: C++ wrapper for table TblWzemQUsrMNUsergroup (SQLite database)
	*/
class LiteTblWzemQUsrMNUsergroup : public TblWzemQUsrMNUsergroup, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsrMNUsergroup();
	~LiteTblWzemQUsrMNUsergroup();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsrMNUsergroup& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrMNUsergroup& rst);

	Sbecore::ubigint insertRec(WzemQUsrMNUsergroup* rec);
	void insertRst(ListWzemQUsrMNUsergroup& rst);
	void updateRec(WzemQUsrMNUsergroup* rec);
	void updateRst(ListWzemQUsrMNUsergroup& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrMNUsergroup** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrMNUsergroup& rst);
};
#endif

#endif
