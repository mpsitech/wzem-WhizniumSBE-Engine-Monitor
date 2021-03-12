/**
	* \file WzemMEvent.h
	* database access for table TblWzemMEvent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMMEVENT_H
#define WZEMMEVENT_H

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

#define VecWzemVMEventBasetype TblWzemMEvent::VecVBasetype

/**
	* WzemMEvent: record of TblWzemMEvent
	*/
class WzemMEvent {

public:
	WzemMEvent(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWzemCEvent = 0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint refWzemMDpch = 0, const double startu = 0.0, const Sbecore::ubigint refWzemMCall = 0, const Sbecore::ubigint refWzemMClstn = 0, const Sbecore::ubigint refWzemMJob = 0, const Sbecore::ubigint refWzemMNode = 0, const Sbecore::ubigint refWzemMOp = 0, const Sbecore::ubigint refWzemMPreset = 0, const std::string Cmd = "", const std::string Filename = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWzemCEvent;
	Sbecore::ubigint refWzemMPeriod;
	Sbecore::ubigint refWzemMDpch;
	double startu;
	Sbecore::ubigint refWzemMCall;
	Sbecore::ubigint refWzemMClstn;
	Sbecore::ubigint refWzemMJob;
	Sbecore::ubigint refWzemMNode;
	Sbecore::ubigint refWzemMOp;
	Sbecore::ubigint refWzemMPreset;
	std::string Cmd;
	std::string Filename;
	std::string srefIxVFeatgroup;
	std::string srefIxVMethod;
	std::string xsref;

public:
	bool operator==(const WzemMEvent& comp);
	bool operator!=(const WzemMEvent& comp);
};

/**
	* ListWzemMEvent: recordset of TblWzemMEvent
	*/
class ListWzemMEvent {

public:
	ListWzemMEvent();
	ListWzemMEvent(const ListWzemMEvent& src);
	~ListWzemMEvent();

	void clear();
	unsigned int size() const;
	void append(WzemMEvent* rec);

	WzemMEvent* operator[](const Sbecore::uint ix);
	ListWzemMEvent& operator=(const ListWzemMEvent& src);
	bool operator==(const ListWzemMEvent& comp);
	bool operator!=(const ListWzemMEvent& comp);

public:
	std::vector<WzemMEvent*> nodes;
};

/**
	* TblWzemMEvent: C++ wrapper for table TblWzemMEvent
	*/
class TblWzemMEvent {

public:
	/**
		* VecVBasetype (full: VecWzemVMEventBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint ADDJOB = 1;
		static const Sbecore::uint REMOVEJOB = 2;
		static const Sbecore::uint ADDDCOL = 3;
		static const Sbecore::uint REMOVEDCOL = 4;
		static const Sbecore::uint ADDSTMGR = 5;
		static const Sbecore::uint REMOVESTMGR = 6;
		static const Sbecore::uint ADDCLSTN = 7;
		static const Sbecore::uint CHANGECLSTNARG = 8;
		static const Sbecore::uint REMOVECLSTN = 9;
		static const Sbecore::uint ADDPRESET = 10;
		static const Sbecore::uint CHANGEPRESET = 11;
		static const Sbecore::uint REMOVEPRESET = 12;
		static const Sbecore::uint ADDNODE = 13;
		static const Sbecore::uint REMOVENODE = 14;
		static const Sbecore::uint TRIGGERCALL = 15;
		static const Sbecore::uint HANDLECALL = 16;
		static const Sbecore::uint RETCALL = 17;
		static const Sbecore::uint FINALIZECALL = 18;
		static const Sbecore::uint HANDLEREQCMD = 19;
		static const Sbecore::uint HANDLEREQDPCHAPP = 20;
		static const Sbecore::uint REPLYREQDPCHAPP = 21;
		static const Sbecore::uint HANDLEREQUPLOAD = 22;
		static const Sbecore::uint HANDLEREQDOWNLOAD = 23;
		static const Sbecore::uint REPLYREQDOWNLOAD = 24;
		static const Sbecore::uint HANDLEREQDPCHRET = 25;
		static const Sbecore::uint HANDLEREQMETHOD = 26;
		static const Sbecore::uint HANDLEREQTIMER = 27;
		static const Sbecore::uint SUBMITDPCH = 28;
		static const Sbecore::uint ADDINV = 29;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

public:
	TblWzemMEvent();
	virtual ~TblWzemMEvent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WzemMEvent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMEvent& rst);

	virtual Sbecore::ubigint insertRec(WzemMEvent* rec);
	Sbecore::ubigint insertNewRec(WzemMEvent** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWzemCEvent = 0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint refWzemMDpch = 0, const double startu = 0.0, const Sbecore::ubigint refWzemMCall = 0, const Sbecore::ubigint refWzemMClstn = 0, const Sbecore::ubigint refWzemMJob = 0, const Sbecore::ubigint refWzemMNode = 0, const Sbecore::ubigint refWzemMOp = 0, const Sbecore::ubigint refWzemMPreset = 0, const std::string Cmd = "", const std::string Filename = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");
	Sbecore::ubigint appendNewRecToRst(ListWzemMEvent& rst, WzemMEvent** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWzemCEvent = 0, const Sbecore::ubigint refWzemMPeriod = 0, const Sbecore::ubigint refWzemMDpch = 0, const double startu = 0.0, const Sbecore::ubigint refWzemMCall = 0, const Sbecore::ubigint refWzemMClstn = 0, const Sbecore::ubigint refWzemMJob = 0, const Sbecore::ubigint refWzemMNode = 0, const Sbecore::ubigint refWzemMOp = 0, const Sbecore::ubigint refWzemMPreset = 0, const std::string Cmd = "", const std::string Filename = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");
	virtual void insertRst(ListWzemMEvent& rst, bool transact = false);
	virtual void updateRec(WzemMEvent* rec);
	virtual void updateRst(ListWzemMEvent& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WzemMEvent** rec);
	virtual bool loadRecByDch(Sbecore::ubigint refWzemMDpch, WzemMEvent** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzemCEvent, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzemCEvent, const bool append, ListWzemMEvent& rst);
	virtual Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMEvent& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWzemMEvent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWzemMEvent: C++ wrapper for table TblWzemMEvent (MySQL database)
	*/
class MyTblWzemMEvent : public TblWzemMEvent, public Sbecore::MyTable {

public:
	MyTblWzemMEvent();
	~MyTblWzemMEvent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMEvent& rst);

	Sbecore::ubigint insertRec(WzemMEvent* rec);
	void insertRst(ListWzemMEvent& rst, bool transact = false);
	void updateRec(WzemMEvent* rec);
	void updateRst(ListWzemMEvent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMEvent** rec);
	bool loadRecByDch(Sbecore::ubigint refWzemMDpch, WzemMEvent** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzemCEvent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzemCEvent, const bool append, ListWzemMEvent& rst);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMEvent& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWzemMEvent: C++ wrapper for table TblWzemMEvent (PgSQL database)
	*/
class PgTblWzemMEvent : public TblWzemMEvent, public Sbecore::PgTable {

public:
	PgTblWzemMEvent();
	~PgTblWzemMEvent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WzemMEvent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWzemMEvent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WzemMEvent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWzemMEvent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMEvent& rst);

	Sbecore::ubigint insertRec(WzemMEvent* rec);
	void insertRst(ListWzemMEvent& rst, bool transact = false);
	void updateRec(WzemMEvent* rec);
	void updateRst(ListWzemMEvent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMEvent** rec);
	bool loadRecByDch(Sbecore::ubigint refWzemMDpch, WzemMEvent** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzemCEvent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzemCEvent, const bool append, ListWzemMEvent& rst);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMEvent& rst);
};
#endif

#if defined(SBECORE_LITE)
/**
	* LiteTblWzemMEvent: C++ wrapper for table TblWzemMEvent (SQLite database)
	*/
class LiteTblWzemMEvent : public TblWzemMEvent, public Sbecore::LiteTable {

public:
	LiteTblWzemMEvent();
	~LiteTblWzemMEvent();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtInsertRec;
	sqlite3_stmt* stmtUpdateRec;
	sqlite3_stmt* stmtRemoveRecByRef;

	sqlite3_stmt* stmtLoadRecByRef;
	sqlite3_stmt* stmtLoadRecByDch;
	sqlite3_stmt* stmtLoadRefsByClu;
	sqlite3_stmt* stmtLoadRstByClu;
	sqlite3_stmt* stmtLoadRstByPrd;

private:
	bool loadRec(sqlite3_stmt* stmt, WzemMEvent** rec);
	Sbecore::ubigint loadRst(sqlite3_stmt* stmt, const bool append, ListWzemMEvent& rst);
	bool loadRecByStmt(sqlite3_stmt* stmt, WzemMEvent** rec);
	Sbecore::ubigint loadRstByStmt(sqlite3_stmt* stmt, const bool append, ListWzemMEvent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WzemMEvent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWzemMEvent& rst);

	Sbecore::ubigint insertRec(WzemMEvent* rec);
	void insertRst(ListWzemMEvent& rst, bool transact = false);
	void updateRec(WzemMEvent* rec);
	void updateRst(ListWzemMEvent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WzemMEvent** rec);
	bool loadRecByDch(Sbecore::ubigint refWzemMDpch, WzemMEvent** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWzemCEvent, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWzemCEvent, const bool append, ListWzemMEvent& rst);
	Sbecore::ubigint loadRstByPrd(Sbecore::ubigint refWzemMPeriod, const bool append, ListWzemMEvent& rst);
};
#endif

#endif
