/**
	* \file WzemMClstn.h
	* database access for table TblWzemMClstn (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMMCLSTN_H
#define WZEMMCLSTN_H

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

#include <sbecore/Xmlio.h>

#define VecWzemVMClstnJactype TblWzemMClstn::VecVJactype
#define VecWzemVMClstnJobmask TblWzemMClstn::VecVJobmask
#define VecWzemVMClstnTarget TblWzemMClstn::VecVTarget
#define VecWzemWMClstnArgmask TblWzemMClstn::VecWArgmask

/**
	* WzemMClstn: record of TblWzemMClstn
	*/
class WzemMClstn {

public:
	WzemMClstn(const Sbecore::ubigint ref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVCall = "", const Sbecore::uint ixVTarget = 0, const Sbecore::uint ixVJobmask = 0, const Sbecore::ubigint tjbRefWzemMJob = 0, const Sbecore::uint ixVArgmask = 0, const std::string arg = "", const std::string srefIxVSge = "", const Sbecore::uint ixVJactype = 0);

public:
	Sbecore::ubigint ref;
	double x1Startu;
	double x1Stopu;
	Sbecore::ubigint refWzemMJob;
	std::string srefIxVCall;
	Sbecore::uint ixVTarget;
	Sbecore::uint ixVJobmask;
	Sbecore::ubigint tjbRefWzemMJob;
	Sbecore::uint ixVArgmask;
	std::string arg;
	std::string srefIxVSge;
	Sbecore::uint ixVJactype;

public:
	bool operator==(const WzemMClstn& comp);
	bool operator!=(const WzemMClstn& comp);
};

/**
	* ListWzemMClstn: recordset of TblWzemMClstn
	*/
class ListWzemMClstn {

public:
	ListWzemMClstn();
	ListWzemMClstn(const ListWzemMClstn& src);
	~ListWzemMClstn();

	void clear();
	unsigned int size() const;
	void append(WzemMClstn* rec);

	WzemMClstn* operator[](const Sbecore::uint ix);
	ListWzemMClstn& operator=(const ListWzemMClstn& src);
	bool operator==(const ListWzemMClstn& comp);
	bool operator!=(const ListWzemMClstn& comp);

public:
	std::vector<WzemMClstn*> nodes;
};

/**
	* TblWzemMClstn: C++ wrapper for table TblWzemMClstn
	*/
class TblWzemMClstn {

public:
	/**
		* VecVJactype (full: VecWzemVMClstnJactype)
		*/
	class VecVJactype {

	public:
		static const Sbecore::uint LOCK = 1;
		static const Sbecore::uint TRY = 2;
		static const Sbecore::uint WEAK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVJobmask (full: VecWzemVMClstnJobmask)
		*/
	class VecVJobmask {

	public:
		static const Sbecore::uint ALL = 1;
		static const Sbecore::uint IMM = 2;
		static const Sbecore::uint MAST = 3;
		static const Sbecore::uint SELF = 4;
		static const Sbecore::uint SLV = 5;
		static const Sbecore::uint SPEC = 6;
		static const Sbecore::uint TREE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVTarget (full: VecWzemVMClstnTarget)
		*/
	class VecVTarget {

	public:
		static const Sbecore::uint JOB = 1;
		static const Sbecore::uint STMGR = 2;
		static const Sbecore::uint DDSPUB = 3;
		static const Sbecore::uint UASRV = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWArgmask (full: VecWzemWMClstnArgmask)
		*/
	class VecWArgmask {

	public:
		static const Sbecore::uint IX = 1;
		static const Sbecore::uint REF = 2;
		static const Sbecore::uint REFS = 4;
		static const Sbecore::uint SREF = 8;
		static const Sbecore::uint INTVAL = 16;
		static const Sbecore::uint DBLVAL = 32;
		static const Sbecore::uint BOOLVAL = 64;
		static const Sbecore::uint TXTVAL = 128;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWzemMClstn();
	virtual ~TblWzemMClstn();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMClstn** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMClstn& rst);

	virtual Sbecore::ubigint insertRec(WzemMClstn* rec);
	Sbecore::ubigint insertNewRec(WzemMClstn** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVCall = "", const Sbecore::uint ixVTarget = 0, const Sbecore::uint ixVJobmask = 0, const Sbecore::ubigint tjbRefWzemMJob = 0, const Sbecore::uint ixVArgmask = 0, const std::string arg = "", const std::string srefIxVSge = "", const Sbecore::uint ixVJactype = 0);
	Sbecore::ubigint appendNewRecToRst(ListWzemMClstn& rst, WzemMClstn** rec = NULL, const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::ubigint refWzemMJob = 0, const std::string srefIxVCall = "", const Sbecore::uint ixVTarget = 0, const Sbecore::uint ixVJobmask = 0, const Sbecore::ubigint tjbRefWzemMJob = 0, const Sbecore::uint ixVArgmask = 0, const std::string arg = "", const std::string srefIxVSge = "", const Sbecore::uint ixVJactype = 0);
	virtual void insertRst(ListWzemMClstn& rst, bool transact = false);
	virtual void updateRec(WzemMClstn* rec);
	virtual void updateRst(ListWzemMClstn& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMClstn** rec);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMClstn& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMClstn& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMClstn: C++ wrapper for table TblWzemMClstn (MySQL database)
	*/
class MyTblWzemMClstn : public TblWzemMClstn, public Sbecore::MyTable {

public:
	MyTblWzemMClstn();
	~MyTblWzemMClstn();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMClstn& rst);

	Sbecore::ubigint insertRec(WzemMClstn* rec);
	void insertRst(ListWzemMClstn& rst, bool transact = false);
	void updateRec(WzemMClstn* rec);
	void updateRst(ListWzemMClstn& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMClstn** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMClstn& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMClstn: C++ wrapper for table TblWzemMClstn (PgSQL database)
	*/
class PgTblWzemMClstn : public TblWzemMClstn, public Sbecore::PgTable {

public:
	PgTblWzemMClstn();
	~PgTblWzemMClstn();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMClstn** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMClstn& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMClstn** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMClstn& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMClstn& rst);

	Sbecore::ubigint insertRec(WzemMClstn* rec);
	void insertRst(ListWzemMClstn& rst, bool transact = false);
	void updateRec(WzemMClstn* rec);
	void updateRst(ListWzemMClstn& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMClstn** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMClstn& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMClstn: C++ wrapper for table TblWzemMClstn (SQLite database)
	*/
class LiteTblWzemMClstn : public TblWzemMClstn, public Sbecore::LiteTable {

public:
	LiteTblWzemMClstn();
	~LiteTblWzemMClstn();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRstByJob;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMClstn** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMClstn& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMClstn** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMClstn& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMClstn** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMClstn& rst);

	Sbecore::ubigint insertRec(WzemMClstn* rec);
	void insertRst(ListWzemMClstn& rst, bool transact = false);
	void updateRec(WzemMClstn* rec);
	void updateRst(ListWzemMClstn& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMClstn** rec);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint refWzemMJob, const bool append, ListWzemMClstn& rst);
};
#endif

#endif

