/**
	* \file WzemQUsrAAccess.h
	* Dbs and XML wrapper for table TblWzemQUsrAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSRAACCESS_H
#define WZEMQUSRAACCESS_H

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
	* WzemQUsrAAccess: record of TblWzemQUsrAAccess
	*/
class WzemQUsrAAccess {

public:
	WzemQUsrAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0, const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxWzemVFeatgroup;
	std::string srefX1IxWzemVFeatgroup;
	std::string titX1IxWzemVFeatgroup;
	std::string x2FeaSrefUix;
	Sbecore::uint ixWzemWAccess;
	std::string srefsIxWzemWAccess;
	std::string titsIxWzemWAccess;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQUsrAAccess: recordset of TblWzemQUsrAAccess
	*/
class ListWzemQUsrAAccess {

public:
	ListWzemQUsrAAccess();
	ListWzemQUsrAAccess(const ListWzemQUsrAAccess& src);
	~ListWzemQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(WzemQUsrAAccess* rec);

	ListWzemQUsrAAccess& operator=(const ListWzemQUsrAAccess& src);

public:
	std::vector<WzemQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsrAAccess: C++ wrapper for table TblWzemQUsrAAccess
	*/
class TblWzemQUsrAAccess {

public:
	TblWzemQUsrAAccess();
	virtual ~TblWzemQUsrAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrAAccess& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsrAAccess* rec);
	Sbecore::ubigint insertNewRec(WzemQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0, const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsrAAccess& rst, WzemQUsrAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0, const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");
	virtual void insertRst(ListWzemQUsrAAccess& rst);
	virtual void updateRec(WzemQUsrAAccess* rec);
	virtual void updateRst(ListWzemQUsrAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsrAAccess: C++ wrapper for table TblWzemQUsrAAccess (MySQL database)
	*/
class MyTblWzemQUsrAAccess : public TblWzemQUsrAAccess, public Sbecore::MyTable {

public:
	MyTblWzemQUsrAAccess();
	~MyTblWzemQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WzemQUsrAAccess* rec);
	void insertRst(ListWzemQUsrAAccess& rst);
	void updateRec(WzemQUsrAAccess* rec);
	void updateRst(ListWzemQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsrAAccess: C++ wrapper for table TblWzemQUsrAAccess (PgSQL database)
	*/
class PgTblWzemQUsrAAccess : public TblWzemQUsrAAccess, public Sbecore::PgTable {

public:
	PgTblWzemQUsrAAccess();
	~PgTblWzemQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsrAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsrAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WzemQUsrAAccess* rec);
	void insertRst(ListWzemQUsrAAccess& rst);
	void updateRec(WzemQUsrAAccess* rec);
	void updateRst(ListWzemQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrAAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsrAAccess: C++ wrapper for table TblWzemQUsrAAccess (SQLite database)
	*/
class LiteTblWzemQUsrAAccess : public TblWzemQUsrAAccess, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsrAAccess();
	~LiteTblWzemQUsrAAccess();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsrAAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsrAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsrAAccess& rst);

	Sbecore::ubigint insertRec(WzemQUsrAAccess* rec);
	void insertRst(ListWzemQUsrAAccess& rst);
	void updateRec(WzemQUsrAAccess* rec);
	void updateRst(ListWzemQUsrAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsrAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsrAAccess& rst);
};
#endif

#endif

