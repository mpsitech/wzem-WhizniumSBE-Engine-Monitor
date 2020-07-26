/**
	* \file WzemQPrsList.h
	* Dbs and XML wrapper for table TblWzemQPrsList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQPRSLIST_H
#define WZEMQPRSLIST_H

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
	* WzemQPrsList: record of TblWzemQPrsList
	*/
class WzemQPrsList {

public:
	WzemQPrsList(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	std::string stubGrp;
	Sbecore::ubigint own;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	Sbecore::uint ixVSex;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWzemQPrsList: recordset of TblWzemQPrsList
	*/
class ListWzemQPrsList {

public:
	ListWzemQPrsList();
	ListWzemQPrsList(const ListWzemQPrsList& src);
	~ListWzemQPrsList();

	void clear();
	unsigned int size() const;
	void append(WzemQPrsList* rec);

	ListWzemQPrsList& operator=(const ListWzemQPrsList& src);

public:
	std::vector<WzemQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWzemQPrsList: C++ wrapper for table TblWzemQPrsList
	*/
class TblWzemQPrsList {

public:
	TblWzemQPrsList();
	virtual ~TblWzemQPrsList();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemQPrsList** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsList& rst);

	virtual Sbecore::ubigint insertRec(WzemQPrsList* rec);
	Sbecore::ubigint insertNewRec(WzemQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemQPrsList& rst, WzemQPrsList** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const std::string stubGrp = "", const Sbecore::ubigint own = 0, const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const Sbecore::uint ixVSex = 0, const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");
	virtual void insertRst(ListWzemQPrsList& rst);
	virtual void updateRec(WzemQPrsList* rec);
	virtual void updateRst(ListWzemQPrsList& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsList** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsList& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemQPrsList: C++ wrapper for table TblWzemQPrsList (MySQL database)
	*/
class MyTblWzemQPrsList : public TblWzemQPrsList, public Sbecore::MyTable {

public:
	MyTblWzemQPrsList();
	~MyTblWzemQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsList& rst);

	Sbecore::ubigint insertRec(WzemQPrsList* rec);
	void insertRst(ListWzemQPrsList& rst);
	void updateRec(WzemQPrsList* rec);
	void updateRst(ListWzemQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsList& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemQPrsList: C++ wrapper for table TblWzemQPrsList (PgSQL database)
	*/
class PgTblWzemQPrsList : public TblWzemQPrsList, public Sbecore::PgTable {

public:
	PgTblWzemQPrsList();
	~PgTblWzemQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemQPrsList** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemQPrsList& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemQPrsList** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemQPrsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsList& rst);

	Sbecore::ubigint insertRec(WzemQPrsList* rec);
	void insertRst(ListWzemQPrsList& rst);
	void updateRec(WzemQPrsList* rec);
	void updateRst(ListWzemQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsList& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteWzemQPrsList: C++ wrapper for table TblWzemQPrsList (SQLite database)
	*/
class LiteTblWzemQPrsList : public TblWzemQPrsList, public Sbecore::LiteTable {

public:
	LiteTblWzemQPrsList();
	~LiteTblWzemQPrsList();

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
	bool loadRec(sqlite3_stmt* stmt, WzemQPrsList** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemQPrsList& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemQPrsList** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemQPrsList& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemQPrsList** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemQPrsList& rst);

	Sbecore::ubigint insertRec(WzemQPrsList* rec);
	void insertRst(ListWzemQPrsList& rst);
	void updateRec(WzemQPrsList* rec);
	void updateRst(ListWzemQPrsList& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WzemQPrsList** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWzemQPrsList& rst);
};
#endif

#endif

