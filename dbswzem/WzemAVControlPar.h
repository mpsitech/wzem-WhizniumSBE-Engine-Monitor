/**
	* \file WzemAVControlPar.h
	* database access for table TblWzemAVControlPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMAVCONTROLPAR_H
#define WZEMAVCONTROLPAR_H

#include <sbecore/Types.h>

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
	* WzemAVControlPar: record of TblWzemAVControlPar
	*/
class WzemAVControlPar {

public:
	WzemAVControlPar(const Sbecore::ubigint ref = 0, const Sbecore::uint ixWzemVControl = 0, const Sbecore::ubigint x1RefWzemMUser = 0, const Sbecore::uint x2IxWzemVLocale = 0, const std::string Par = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixWzemVControl;
	Sbecore::ubigint x1RefWzemMUser;
	Sbecore::uint x2IxWzemVLocale;
	std::string Par;
	std::string Val;

public:
	bool operator==(const WzemAVControlPar& comp);
	bool operator!=(const WzemAVControlPar& comp);
};

/**
	* ListWzemAVControlPar: recordset of TblWzemAVControlPar
	*/
class ListWzemAVControlPar {

public:
	ListWzemAVControlPar();
	ListWzemAVControlPar(const ListWzemAVControlPar& src);
	~ListWzemAVControlPar();

	void clear();
	unsigned int size() const;
	void append(WzemAVControlPar* rec);

	WzemAVControlPar* operator[](const Sbecore::uint ix);
	ListWzemAVControlPar& operator=(const ListWzemAVControlPar& src);
	bool operator==(const ListWzemAVControlPar& comp);
	bool operator!=(const ListWzemAVControlPar& comp);

public:
	std::vector<WzemAVControlPar*> nodes;
};

/**
	* TblWzemAVControlPar: C++ wrapper for table TblWzemAVControlPar
	*/
class TblWzemAVControlPar {

public:

public:
	TblWzemAVControlPar();
	virtual ~TblWzemAVControlPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemAVControlPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVControlPar& rst);

	virtual Sbecore::ubigint insertRec(WzemAVControlPar* rec);
	Sbecore::ubigint insertNewRec(WzemAVControlPar** rec = NULL, const Sbecore::uint ixWzemVControl = 0, const Sbecore::ubigint x1RefWzemMUser = 0, const Sbecore::uint x2IxWzemVLocale = 0, const std::string Par = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemAVControlPar& rst, WzemAVControlPar** rec = NULL, const Sbecore::uint ixWzemVControl = 0, const Sbecore::ubigint x1RefWzemMUser = 0, const Sbecore::uint x2IxWzemVLocale = 0, const std::string Par = "", const std::string Val = "");
	virtual void insertRst(ListWzemAVControlPar& rst, bool transact = false);
	virtual void updateRec(WzemAVControlPar* rec);
	virtual void updateRst(ListWzemAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, Sbecore::ubigint& ref);
	virtual bool loadValByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemAVControlPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemAVControlPar: C++ wrapper for table TblWzemAVControlPar (MySQL database)
	*/
class MyTblWzemAVControlPar : public TblWzemAVControlPar, public Sbecore::MyTable {

public:
	MyTblWzemAVControlPar();
	~MyTblWzemAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVControlPar& rst);

	Sbecore::ubigint insertRec(WzemAVControlPar* rec);
	void insertRst(ListWzemAVControlPar& rst, bool transact = false);
	void updateRec(WzemAVControlPar* rec);
	void updateRst(ListWzemAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemAVControlPar: C++ wrapper for table TblWzemAVControlPar (PgSQL database)
	*/
class PgTblWzemAVControlPar : public TblWzemAVControlPar, public Sbecore::PgTable {

public:
	PgTblWzemAVControlPar();
	~PgTblWzemAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemAVControlPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemAVControlPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemAVControlPar** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVControlPar& rst);

	Sbecore::ubigint insertRec(WzemAVControlPar* rec);
	void insertRst(ListWzemAVControlPar& rst, bool transact = false);
	void updateRec(WzemAVControlPar* rec);
	void updateRst(ListWzemAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, std::string& Val);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemAVControlPar: C++ wrapper for table TblWzemAVControlPar (SQLite database)
	*/
class LiteTblWzemAVControlPar : public TblWzemAVControlPar, public Sbecore::LiteTable {

public:
	LiteTblWzemAVControlPar();
	~LiteTblWzemAVControlPar();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRefByCtlUsrPar;
	sqlite3_stmt* stmtLoadValByCtlUsrPar;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemAVControlPar** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemAVControlPar& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemAVControlPar** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemAVControlPar& rst);

	Sbecore::ubigint insertRec(WzemAVControlPar* rec);
	void insertRst(ListWzemAVControlPar& rst, bool transact = false);
	void updateRec(WzemAVControlPar* rec);
	void updateRst(ListWzemAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemAVControlPar** rec);
	bool loadRefByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, Sbecore::ubigint& ref);
	bool loadValByCtlUsrPar(Sbecore::uint ixWzemVControl, Sbecore::ubigint x1RefWzemMUser, std::string Par, std::string& Val);
};
#endif

#endif
