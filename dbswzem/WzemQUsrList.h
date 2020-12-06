/**
	* \file WzemQUsrList.h
	* Dbs and XML wrapper for table TblWzemQUsrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSRLIST_H
#define WZEMQUSRLIST_H

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
	* WzemQUsrList: record of TblWzemQUsrList
	*/
class WzemQUsrList {

public:
	WzemQUsrList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWzemMPerson = 0, const std::string stubRefWzemMPerson = "", const std::string sref = "", const Sbecore::ubigint refWzemMUsergroup = 0, const std::string stubRefWzemMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWzemVLocale = 0, const std::string srefIxWzemVLocale = "", const std::string titIxWzemVLocale = "", const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	Sbecore::ubigint refWzemMPerson;
	std::string stubRefWzemMPerson;
	std::string sref;
	Sbecore::ubigint refWzemMUsergroup;
	std::string stubRefWzemMUsergroup;
	Sbecore::uint ixVState;
	std::string srefIxVState;
	std::string titIxVState;
	Sbecore::uint ixWzemVLocale;
	std::string srefIxWzemVLocale;
	std::string titIxWzemVLocale;
	Sbecore::uint ixWzemVUserlevel;
	std::string srefIxWzemVUserlevel;
	std::string titIxWzemVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQUsrList: recordset of TblWzemQUsrList
	*/
class ListWzemQUsrList {

public:
	ListWzemQUsrList();
	ListWzemQUsrList(const ListWzemQUsrList& src);
	~ListWzemQUsrList();

	void clear();
	unsigned int size() const;
	void append(WzemQUsrList* rec);

	ListWzemQUsrList& operator=(const ListWzemQUsrList& src);

public:
	std::vector<WzemQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsrList: C++ wrapper for table TblWzemQUsrList
	*/
class TblWzemQUsrList {

public:
	TblWzemQUsrList();
	virtual ~TblWzemQUsrList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsrList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrList& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsrList* rec);
	Sbecore::ubigint insertNewRec(WzemQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWzemMPerson = 0, const std::string stubRefWzemMPerson = "", const std::string sref = "", const Sbecore::ubigint refWzemMUsergroup = 0, const std::string stubRefWzemMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWzemVLocale = 0, const std::string srefIxWzemVLocale = "", const std::string titIxWzemVLocale = "", const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsrList& rst, WzemQUsrList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const Sbecore::ubigint refWzemMPerson = 0, const std::string stubRefWzemMPerson = "", const std::string sref = "", const Sbecore::ubigint refWzemMUsergroup = 0, const std::string stubRefWzemMUsergroup = "", const Sbecore::uint ixVState = 0, const std::string srefIxVState = "", const std::string titIxVState = "", const Sbecore::uint ixWzemVLocale = 0, const std::string srefIxWzemVLocale = "", const std::string titIxWzemVLocale = "", const Sbecore::uint ixWzemVUserlevel = 0, const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");
	virtual void insertRst(ListWzemQUsrList& rst);
	virtual void updateRec(WzemQUsrList* rec);
	virtual void updateRst(ListWzemQUsrList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsrList: C++ wrapper for table TblWzemQUsrList (MySQL database)
	*/
class MyTblWzemQUsrList : public TblWzemQUsrList, public Sbecore::MyTable {

public:
	MyTblWzemQUsrList();
	~MyTblWzemQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrList& rst);

	Sbecore::ubigint insertRec(WzemQUsrList* rec);
	void insertRst(ListWzemQUsrList& rst);
	void updateRec(WzemQUsrList* rec);
	void updateRst(ListWzemQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsrList: C++ wrapper for table TblWzemQUsrList (PgSQL database)
	*/
class PgTblWzemQUsrList : public TblWzemQUsrList, public Sbecore::PgTable {

public:
	PgTblWzemQUsrList();
	~PgTblWzemQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsrList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsrList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsrList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrList& rst);

	Sbecore::ubigint insertRec(WzemQUsrList* rec);
	void insertRst(ListWzemQUsrList& rst);
	void updateRec(WzemQUsrList* rec);
	void updateRst(ListWzemQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsrList: C++ wrapper for table TblWzemQUsrList (SQLite database)
	*/
class LiteTblWzemQUsrList : public TblWzemQUsrList, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsrList();
	~LiteTblWzemQUsrList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsrList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsrList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsrList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsrList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrList& rst);

	Sbecore::ubigint insertRec(WzemQUsrList* rec);
	void insertRst(ListWzemQUsrList& rst);
	void updateRec(WzemQUsrList* rec);
	void updateRst(ListWzemQUsrList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrList& rst);
};
#endif

#endif

