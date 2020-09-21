/**
	* \file WzemJMPresetArg.h
	* database access for table TblWzemJMPresetArg (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMJMPRESETARG_H
#define WZEMJMPRESETARG_H

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
	* WzemJMPresetArg: record of TblWzemJMPresetArg
	*/
class WzemJMPresetArg {

public:
	WzemJMPresetArg(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWzemMPreset = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string arg = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWzemMPreset;
	double x1Startu;
	double x1Stopu;
	std::string arg;

public:
	bool operator==(const WzemJMPresetArg& comp);
	bool operator!=(const WzemJMPresetArg& comp);
};

/**
	* ListWzemJMPresetArg: recordset of TblWzemJMPresetArg
	*/
class ListWzemJMPresetArg {

public:
	ListWzemJMPresetArg();
	ListWzemJMPresetArg(const ListWzemJMPresetArg& src);
	~ListWzemJMPresetArg();

	void clear();
	unsigned int size() const;
	void append(WzemJMPresetArg* rec);

	WzemJMPresetArg* operator[](const Sbecore::uint ix);
	ListWzemJMPresetArg& operator=(const ListWzemJMPresetArg& src);
	bool operator==(const ListWzemJMPresetArg& comp);
	bool operator!=(const ListWzemJMPresetArg& comp);

public:
	std::vector<WzemJMPresetArg*> nodes;
};

/**
	* TblWzemJMPresetArg: C++ wrapper for table TblWzemJMPresetArg
	*/
class TblWzemJMPresetArg {

public:

public:
	TblWzemJMPresetArg();
	virtual ~TblWzemJMPresetArg();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemJMPresetArg** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPresetArg& rst);

	virtual Sbecore::ubigint insertRec(WzemJMPresetArg* rec);
	Sbecore::ubigint insertNewRec(WzemJMPresetArg** rec = NULL, const Sbecore::ubigint refWzemMPreset = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string arg = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemJMPresetArg& rst, WzemJMPresetArg** rec = NULL, const Sbecore::ubigint refWzemMPreset = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string arg = "");
	virtual void insertRst(ListWzemJMPresetArg& rst, bool transact = false);
	virtual void updateRec(WzemJMPresetArg* rec);
	virtual void updateRst(ListWzemJMPresetArg& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemJMPresetArg** rec);
	virtual Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWzemMPreset, const bool append, ListWzemJMPresetArg& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemJMPresetArg& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemJMPresetArg: C++ wrapper for table TblWzemJMPresetArg (MySQL database)
	*/
class MyTblWzemJMPresetArg : public TblWzemJMPresetArg, public Sbecore::MyTable {

public:
	MyTblWzemJMPresetArg();
	~MyTblWzemJMPresetArg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPresetArg& rst);

	Sbecore::ubigint insertRec(WzemJMPresetArg* rec);
	void insertRst(ListWzemJMPresetArg& rst, bool transact = false);
	void updateRec(WzemJMPresetArg* rec);
	void updateRst(ListWzemJMPresetArg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWzemMPreset, const bool append, ListWzemJMPresetArg& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemJMPresetArg: C++ wrapper for table TblWzemJMPresetArg (PgSQL database)
	*/
class PgTblWzemJMPresetArg : public TblWzemJMPresetArg, public Sbecore::PgTable {

public:
	PgTblWzemJMPresetArg();
	~PgTblWzemJMPresetArg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemJMPresetArg& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemJMPresetArg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPresetArg& rst);

	Sbecore::ubigint insertRec(WzemJMPresetArg* rec);
	void insertRst(ListWzemJMPresetArg& rst, bool transact = false);
	void updateRec(WzemJMPresetArg* rec);
	void updateRst(ListWzemJMPresetArg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWzemMPreset, const bool append, ListWzemJMPresetArg& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemJMPresetArg: C++ wrapper for table TblWzemJMPresetArg (SQLite database)
	*/
class LiteTblWzemJMPresetArg : public TblWzemJMPresetArg, public Sbecore::LiteTable {

public:
	LiteTblWzemJMPresetArg();
	~LiteTblWzemJMPresetArg();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByPst;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemJMPresetArg& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemJMPresetArg& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemJMPresetArg& rst);

	Sbecore::ubigint insertRec(WzemJMPresetArg* rec);
	void insertRst(ListWzemJMPresetArg& rst, bool transact = false);
	void updateRec(WzemJMPresetArg* rec);
	void updateRst(ListWzemJMPresetArg& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemJMPresetArg** rec);
	Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWzemMPreset, const bool append, ListWzemJMPresetArg& rst);
};
#endif

#endif

