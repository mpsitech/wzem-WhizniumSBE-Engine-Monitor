/**
	* \file WzemCEvent.cpp
	* Dbs and XML wrapper for table TblWzemCEvent (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemCEvent.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWzemCEvent
 ******************************************************************************/

TblWzemCEvent::TblWzemCEvent() {
};

TblWzemCEvent::~TblWzemCEvent() {
};

ubigint TblWzemCEvent::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemCEvent
 ******************************************************************************/

MyTblWzemCEvent::MyTblWzemCEvent() :
			TblWzemCEvent()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWzemCEvent::~MyTblWzemCEvent() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWzemCEvent::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWzemCEvent () VALUES ()", false);
};

ubigint MyTblWzemCEvent::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWzemCEvent::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWzemCEvent::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemCEvent
 ******************************************************************************/

PgTblWzemCEvent::PgTblWzemCEvent() :
			TblWzemCEvent()
			, PgTable()
		{
};

PgTblWzemCEvent::~PgTblWzemCEvent() {
};

void PgTblWzemCEvent::initStatements() {
	createStatement("TblWzemCEvent_getNewRef", "SELECT nextval('TblWzemCEvent')", 0);
};

ubigint PgTblWzemCEvent::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWzemCEvent_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemCEvent::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemCEvent
 ******************************************************************************/

LiteTblWzemCEvent::LiteTblWzemCEvent() :
			TblWzemCEvent()
			, LiteTable()
		{
	stmtGetNewRef = NULL;
};

LiteTblWzemCEvent::~LiteTblWzemCEvent() {
	if (stmtGetNewRef) sqlite3_finalize(stmtGetNewRef);
};

void LiteTblWzemCEvent::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWzemCEvent (void) VALUES (0)");
};

ubigint LiteTblWzemCEvent::getNewRef() {
	if (sqlite3_step(stmtGetNewRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemCEvent::getNewRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return sqlite3_last_insert_rowid(dbs);
};
#endif

