/**
	* \file WzemQUsgAAccess.h
	* Dbs and XML wrapper for table TblWzemQUsgAAccess (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQUSGAACCESS_H
#define WZEMQUSGAACCESS_H

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
	* WzemQUsgAAccess: record of TblWzemQUsgAAccess
	*/
class WzemQUsgAAccess {

public:
	WzemQUsgAAccess(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0, const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");

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
	* ListWzemQUsgAAccess: recordset of TblWzemQUsgAAccess
	*/
class ListWzemQUsgAAccess {

public:
	ListWzemQUsgAAccess();
	ListWzemQUsgAAccess(const ListWzemQUsgAAccess& src);
	~ListWzemQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(WzemQUsgAAccess* rec);

	ListWzemQUsgAAccess& operator=(const ListWzemQUsgAAccess& src);

public:
	std::vector<WzemQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQUsgAAccess: C++ wrapper for table TblWzemQUsgAAccess
	*/
class TblWzemQUsgAAccess {

public:
	TblWzemQUsgAAccess();
	virtual ~TblWzemQUsgAAccess();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgAAccess& rst);

	virtual Sbecore::ubigint insertRec(WzemQUsgAAccess* rec);
	Sbecore::ubigint insertNewRec(WzemQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0, const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQUsgAAccess& rst, WzemQUsgAAccess** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0, const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");
	virtual void insertRst(ListWzemQUsgAAccess& rst);
	virtual void updateRec(WzemQUsgAAccess* rec);
	virtual void updateRst(ListWzemQUsgAAccess& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgAAccess** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgAAccess& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQUsgAAccess: C++ wrapper for table TblWzemQUsgAAccess (MySQL database)
	*/
class MyTblWzemQUsgAAccess : public TblWzemQUsgAAccess, public Sbecore::MyTable {

public:
	MyTblWzemQUsgAAccess();
	~MyTblWzemQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WzemQUsgAAccess* rec);
	void insertRst(ListWzemQUsgAAccess& rst);
	void updateRec(WzemQUsgAAccess* rec);
	void updateRst(ListWzemQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgAAccess& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQUsgAAccess: C++ wrapper for table TblWzemQUsgAAccess (PgSQL database)
	*/
class PgTblWzemQUsgAAccess : public TblWzemQUsgAAccess, public Sbecore::PgTable {

public:
	PgTblWzemQUsgAAccess();
	~PgTblWzemQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQUsgAAccess& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQUsgAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WzemQUsgAAccess* rec);
	void insertRst(ListWzemQUsgAAccess& rst);
	void updateRec(WzemQUsgAAccess* rec);
	void updateRst(ListWzemQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgAAccess& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQUsgAAccess: C++ wrapper for table TblWzemQUsgAAccess (SQLite database)
	*/
class LiteTblWzemQUsgAAccess : public TblWzemQUsgAAccess, public Sbecore::LiteTable {

public:
	LiteTblWzemQUsgAAccess();
	~LiteTblWzemQUsgAAccess();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQUsgAAccess& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQUsgAAccess& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQUsgAAccess& rst);

	Sbecore::ubigint insertRec(WzemQUsgAAccess* rec);
	void insertRst(ListWzemQUsgAAccess& rst);
	void updateRec(WzemQUsgAAccess* rec);
	void updateRst(ListWzemQUsgAAccess& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQUsgAAccess** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQUsgAAccess& rst);
};
#endif

#endif

