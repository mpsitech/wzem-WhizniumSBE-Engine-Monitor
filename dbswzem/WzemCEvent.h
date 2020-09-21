/**
	* \file WzemCEvent.h
	* Dbs and XML wrapper for table TblWzemCEvent (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMCEVENT_H
#define WZEMCEVENT_H

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
	* TblWzemCEvent: C++ wrapper for table TblWzemCEvent
	*/
class TblWzemCEvent {

public:
	TblWzemCEvent();
	virtual ~TblWzemCEvent();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWzemCEvent: C++ wrapper for table TblWzemCEvent (MySQL database)
	*/
class MyTblWzemCEvent : public TblWzemCEvent, public Sbecore::MyTable {

public:
	MyTblWzemCEvent();
	~MyTblWzemCEvent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_PG)
/**
	* PgTblWzemCEvent: C++ wrapper for table TblWzemCEvent (PgSQL database)
	*/
class PgTblWzemCEvent : public TblWzemCEvent, public Sbecore::PgTable {

public:
	PgTblWzemCEvent();
	~PgTblWzemCEvent();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_LITE)

/**
	* LiteTblWzemCEvent: C++ wrapper for table TblWzemCEvent (SQLite database)
	*/
class LiteTblWzemCEvent : public TblWzemCEvent, public Sbecore::LiteTable {

public:
	LiteTblWzemCEvent();
	~LiteTblWzemCEvent();

public:
	void initStatements();

public:
	sqlite3_stmt* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

