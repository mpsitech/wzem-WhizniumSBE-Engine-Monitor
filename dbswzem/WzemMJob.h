/**
	* \file WzemMJob.h
	* database access for table TblWzemMJob (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMMJOB_H
#define WZEMMJOB_H

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
	* WzemMJob: record of TblWzemMJob
	*/
class WzemMJob {

public:
	WzemMJob(const Sbecore::ubigint ref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint supRefWzemMJob = 0, const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const bool Clisrv = false, const bool srvNotCli = false, const bool Dcol = false, const bool Stmgr = false);

public:
	Sbecore::ubigint ref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint refWzemMPeriod;
	Sbecore::ubigint supRefWzemMJob;
	std::string srefIxVJob;
	Sbecore::ubigint xjref;
	bool Clisrv;
	bool srvNotCli;
	bool Dcol;
	bool Stmgr;

public:
	bool operator==(const WzemMJob& comp);
	bool operator!=(const WzemMJob& comp);
};

/**
	* ListWzemMJob: recordset of TblWzemMJob
	*/
class ListWzemMJob {

public:
	ListWzemMJob();
	ListWzemMJob(const ListWzemMJob& src);
	~ListWzemMJob();

	void clear();
	unsigned int size() const;
	void append(WzemMJob* rec);

	WzemMJob* operator[](const Sbecore::uint ix);
	ListWzemMJob& operator=(const ListWzemMJob& src);
	bool operator==(const ListWzemMJob& comp);
	bool operator!=(const ListWzemMJob& comp);

public:
	std::vector<WzemMJob*> nodes;
};

/**
	* TblWzemMJob: C++ wrapper for table TblWzemMJob
	*/
class TblWzemMJob {

public:

public:
	TblWzemMJob();
	virtual ~TblWzemMJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMJob& rst);

	virtual Sbecore::ubigint insertRec(WzemMJob* rec);
	Sbecore::ubigint insertNewRec(WzemMJob** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint supRefWzemMJob = 0, const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const bool Clisrv = false, const bool srvNotCli = false, const bool Dcol = false, const bool Stmgr = false);
	Sbecore::ubigint appendNewRecToRst(ListWzemMJob& rst, WzemMJob** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint supRefWzemMJob = 0, const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const bool Clisrv = false, const bool srvNotCli = false, const bool Dcol = false, const bool Stmgr = false);
	virtual void insertRst(ListWzemMJob& rst, bool transact = false);
	virtual void updateRec(WzemMJob* rec);
	virtual void updateRst(ListWzemMJob& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMJob** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzemMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMJob& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzemMJob, const bool append, ListWzemMJob& rst);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzemMJob);
	virtual bool loadXjrByRef(Sbecore::ubigint ref, std::string& xjref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMJob& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWzemMJob& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWzemMJob& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMJob: C++ wrapper for table TblWzemMJob (MySQL database)
	*/
class MyTblWzemMJob : public TblWzemMJob, public Sbecore::MyTable {

public:
	MyTblWzemMJob();
	~MyTblWzemMJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMJob& rst);

	Sbecore::ubigint insertRec(WzemMJob* rec);
	void insertRst(ListWzemMJob& rst, bool transact = false);
	void updateRec(WzemMJob* rec);
	void updateRst(ListWzemMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMJob** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzemMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMJob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzemMJob, const bool append, ListWzemMJob& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzemMJob);
	bool loadXjrByRef(Sbecore::ubigint ref, std::string& xjref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMJob: C++ wrapper for table TblWzemMJob (PgSQL database)
	*/
class PgTblWzemMJob : public TblWzemMJob, public Sbecore::PgTable {

public:
	PgTblWzemMJob();
	~PgTblWzemMJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMJob& rst);

	Sbecore::ubigint insertRec(WzemMJob* rec);
	void insertRst(ListWzemMJob& rst, bool transact = false);
	void updateRec(WzemMJob* rec);
	void updateRst(ListWzemMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMJob** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzemMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMJob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzemMJob, const bool append, ListWzemMJob& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzemMJob);
	bool loadXjrByRef(Sbecore::ubigint ref, std::string& xjref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMJob: C++ wrapper for table TblWzemMJob (SQLite database)
	*/
class LiteTblWzemMJob : public TblWzemMJob, public Sbecore::LiteTable {

public:
	LiteTblWzemMJob();
	~LiteTblWzemMJob();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtConfirmByRef;
	sqlite3_stmt* stmtLoadRefsBySup;
	sqlite3_stmt* stmtLoadRstByPrd;
	sqlite3_stmt* stmtLoadRstBySup;
	sqlite3_stmt* stmtLoadSupByRef;
	sqlite3_stmt* stmtLoadXjrByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMJob** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMJob& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMJob** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMJob& rst);

	Sbecore::ubigint insertRec(WzemMJob* rec);
	void insertRst(ListWzemMJob& rst, bool transact = false);
	void updateRec(WzemMJob* rec);
	void updateRst(ListWzemMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMJob** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWzemMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMJob& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWzemMJob, const bool append, ListWzemMJob& rst);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWzemMJob);
	bool loadXjrByRef(Sbecore::ubigint ref, std::string& xjref);
};
#endif

#endif

