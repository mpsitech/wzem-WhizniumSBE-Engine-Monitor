/**
	* \file WzemMUser.h
	* database access for table TblWzemMUser (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMMUSER_H
#define WZEMMUSER_H

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

#define VecWzemVMUserState TblWzemMUser::VecVState

/**
	* WzemMUser: record of TblWzemMUser
	*/
class WzemMUser {

public:
	WzemMUser(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::ubigint refWzemMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzemVLocale = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refRUsergroup;
	Sbecore::ubigint refWzemMUsergroup;
	Sbecore::ubigint refWzemMPerson;
	std::string sref;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixWzemVLocale;
	Sbecore::uint ixWzemVUserlevel;
	std::string Password;
	std::string Fullkey;
	std::string Comment;

public:
	bool operator==(const WzemMUser& comp);
	bool operator!=(const WzemMUser& comp);
};

/**
	* ListWzemMUser: recordset of TblWzemMUser
	*/
class ListWzemMUser {

public:
	ListWzemMUser();
	ListWzemMUser(const ListWzemMUser& src);
	~ListWzemMUser();

	void clear();
	unsigned int size() const;
	void append(WzemMUser* rec);

	WzemMUser* operator[](const Sbecore::uint ix);
	ListWzemMUser& operator=(const ListWzemMUser& src);
	bool operator==(const ListWzemMUser& comp);
	bool operator!=(const ListWzemMUser& comp);

public:
	std::vector<WzemMUser*> nodes;
};

/**
	* TblWzemMUser: C++ wrapper for table TblWzemMUser
	*/
class TblWzemMUser {

public:
	/**
		* VecVState (full: VecWzemVMUserState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint ACT = 1;
		static const Sbecore::uint DSG = 2;
		static const Sbecore::uint DUE = 3;
		static const Sbecore::uint EXP = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWzemMUser();
	virtual ~TblWzemMUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUser& rst);

	virtual Sbecore::ubigint insertRec(WzemMUser* rec);
	Sbecore::ubigint insertNewRec(WzemMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::ubigint refWzemMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzemVLocale = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMUser& rst, WzemMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWzemMUsergroup = 0, const Sbecore::ubigint refWzemMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzemVLocale = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	virtual void insertRst(ListWzemMUser& rst, bool transact = false);
	virtual void updateRec(WzemMUser* rec);
	virtual void updateRst(ListWzemMUser& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMUser** rec);
	virtual bool loadRecByPrs(Sbecore::ubigint refWzemMPerson, WzemMUser** rec);
	virtual bool loadRecBySrf(std::string sref, WzemMUser** rec);
	virtual bool loadRecBySrfPwd(std::string sref, std::string Password, WzemMUser** rec);
	virtual bool loadRefByPrs(Sbecore::ubigint refWzemMPerson, Sbecore::ubigint& ref);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMUser: C++ wrapper for table TblWzemMUser (MySQL database)
	*/
class MyTblWzemMUser : public TblWzemMUser, public Sbecore::MyTable {

public:
	MyTblWzemMUser();
	~MyTblWzemMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUser& rst);

	Sbecore::ubigint insertRec(WzemMUser* rec);
	void insertRst(ListWzemMUser& rst, bool transact = false);
	void updateRec(WzemMUser* rec);
	void updateRst(ListWzemMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWzemMPerson, WzemMUser** rec);
	bool loadRecBySrf(std::string sref, WzemMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WzemMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWzemMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMUser: C++ wrapper for table TblWzemMUser (PgSQL database)
	*/
class PgTblWzemMUser : public TblWzemMUser, public Sbecore::PgTable {

public:
	PgTblWzemMUser();
	~PgTblWzemMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMUser** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUser& rst);

	Sbecore::ubigint insertRec(WzemMUser* rec);
	void insertRst(ListWzemMUser& rst, bool transact = false);
	void updateRec(WzemMUser* rec);
	void updateRst(ListWzemMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWzemMPerson, WzemMUser** rec);
	bool loadRecBySrf(std::string sref, WzemMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WzemMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWzemMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMUser: C++ wrapper for table TblWzemMUser (SQLite database)
	*/
class LiteTblWzemMUser : public TblWzemMUser, public Sbecore::LiteTable {

public:
	LiteTblWzemMUser();
	~LiteTblWzemMUser();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByPrs;
	sqlite3_stmt* stmtLoadRecBySrf;
	sqlite3_stmt* stmtLoadRecBySrfPwd;
	sqlite3_stmt* stmtLoadRefByPrs;
	sqlite3_stmt* stmtLoadRefBySrf;
	sqlite3_stmt* stmtLoadRefsByUsg;
	sqlite3_stmt* stmtLoadSrfByRef;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMUser** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMUser& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMUser** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMUser& rst);

	Sbecore::ubigint insertRec(WzemMUser* rec);
	void insertRst(ListWzemMUser& rst, bool transact = false);
	void updateRec(WzemMUser* rec);
	void updateRst(ListWzemMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMUser** rec);
	bool loadRecByPrs(Sbecore::ubigint refWzemMPerson, WzemMUser** rec);
	bool loadRecBySrf(std::string sref, WzemMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WzemMUser** rec);
	bool loadRefByPrs(Sbecore::ubigint refWzemMPerson, Sbecore::ubigint& ref);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWzemMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

