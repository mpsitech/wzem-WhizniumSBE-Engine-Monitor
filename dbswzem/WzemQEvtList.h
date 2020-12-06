/**
	* \file WzemQEvtList.h
	* Dbs and XML wrapper for table TblWzemQEvtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQEVTLIST_H
#define WZEMQEVTLIST_H

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
	* WzemQEvtList: record of TblWzemQEvtList
	*/
class WzemQEvtList {

public:
	WzemQEvtList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const double startu = 0.0, const Sbecore::ubigint refWzemMDpch = 0, const std::string Cmd = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	std::string srefIxVBasetype;
	Sbecore::ubigint refWzemMPeriod;
	std::string stubRefWzemMPeriod;
	double startu;
	Sbecore::ubigint refWzemMDpch;
	std::string Cmd;
	std::string srefIxVFeatgroup;
	std::string srefIxVMethod;
	std::string xsref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQEvtList: recordset of TblWzemQEvtList
	*/
class ListWzemQEvtList {

public:
	ListWzemQEvtList();
	ListWzemQEvtList(const ListWzemQEvtList& src);
	~ListWzemQEvtList();

	void clear();
	unsigned int size() const;
	void append(WzemQEvtList* rec);

	ListWzemQEvtList& operator=(const ListWzemQEvtList& src);

public:
	std::vector<WzemQEvtList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQEvtList: C++ wrapper for table TblWzemQEvtList
	*/
class TblWzemQEvtList {

public:
	TblWzemQEvtList();
	virtual ~TblWzemQEvtList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQEvtList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQEvtList& rst);

	virtual Sbecore::ubigint insertRec(WzemQEvtList* rec);
	Sbecore::ubigint insertNewRec(WzemQEvtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const double startu = 0.0, const Sbecore::ubigint refWzemMDpch = 0, const std::string Cmd = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQEvtList& rst, WzemQEvtList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const std::string srefIxVBasetype = "", const Sbecore::ubigint refWzemMPeriod = 0, const std::string stubRefWzemMPeriod = "", const double startu = 0.0, const Sbecore::ubigint refWzemMDpch = 0, const std::string Cmd = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");
	virtual void insertRst(ListWzemQEvtList& rst);
	virtual void updateRec(WzemQEvtList* rec);
	virtual void updateRst(ListWzemQEvtList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQEvtList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQEvtList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQEvtList: C++ wrapper for table TblWzemQEvtList (MySQL database)
	*/
class MyTblWzemQEvtList : public TblWzemQEvtList, public Sbecore::MyTable {

public:
	MyTblWzemQEvtList();
	~MyTblWzemQEvtList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQEvtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQEvtList& rst);

	Sbecore::ubigint insertRec(WzemQEvtList* rec);
	void insertRst(ListWzemQEvtList& rst);
	void updateRec(WzemQEvtList* rec);
	void updateRst(ListWzemQEvtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQEvtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQEvtList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQEvtList: C++ wrapper for table TblWzemQEvtList (PgSQL database)
	*/
class PgTblWzemQEvtList : public TblWzemQEvtList, public Sbecore::PgTable {

public:
	PgTblWzemQEvtList();
	~PgTblWzemQEvtList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQEvtList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQEvtList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQEvtList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQEvtList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQEvtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQEvtList& rst);

	Sbecore::ubigint insertRec(WzemQEvtList* rec);
	void insertRst(ListWzemQEvtList& rst);
	void updateRec(WzemQEvtList* rec);
	void updateRst(ListWzemQEvtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQEvtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQEvtList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQEvtList: C++ wrapper for table TblWzemQEvtList (SQLite database)
	*/
class LiteTblWzemQEvtList : public TblWzemQEvtList, public Sbecore::LiteTable {

public:
	LiteTblWzemQEvtList();
	~LiteTblWzemQEvtList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQEvtList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQEvtList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQEvtList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQEvtList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQEvtList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQEvtList& rst);

	Sbecore::ubigint insertRec(WzemQEvtList* rec);
	void insertRst(ListWzemQEvtList& rst);
	void updateRec(WzemQEvtList* rec);
	void updateRst(ListWzemQEvtList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQEvtList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQEvtList& rst);
};
#endif

#endif
