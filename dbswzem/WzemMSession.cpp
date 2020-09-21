/**
	* \file WzemMSession.cpp
	* database access for table TblWzemMSession (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemMSession.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMSession
 ******************************************************************************/

WzemMSession::WzemMSession(
			const ubigint ref
			, const ubigint refWzemMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refWzemMUser = refWzemMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool WzemMSession::operator==(
			const WzemMSession& comp
		) {
	return false;
};

bool WzemMSession::operator!=(
			const WzemMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMSession
 ******************************************************************************/

ListWzemMSession::ListWzemMSession() {
};

ListWzemMSession::ListWzemMSession(
			const ListWzemMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMSession(*(src.nodes[i]));
};

ListWzemMSession::~ListWzemMSession() {
	clear();
};

void ListWzemMSession::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMSession::size() const {
	return(nodes.size());
};

void ListWzemMSession::append(
			WzemMSession* rec
		) {
	nodes.push_back(rec);
};

WzemMSession* ListWzemMSession::operator[](
			const uint ix
		) {
	WzemMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMSession& ListWzemMSession::operator=(
			const ListWzemMSession& src
		) {
	WzemMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMSession::operator==(
			const ListWzemMSession& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWzemMSession::operator!=(
			const ListWzemMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMSession
 ******************************************************************************/

TblWzemMSession::TblWzemMSession() {
};

TblWzemMSession::~TblWzemMSession() {
};

bool TblWzemMSession::loadRecBySQL(
			const string& sqlstr
			, WzemMSession** rec
		) {
	return false;
};

ubigint TblWzemMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMSession& rst
		) {
	return 0;
};

ubigint TblWzemMSession::insertRec(
			WzemMSession* rec
		) {
	return 0;
};

ubigint TblWzemMSession::insertNewRec(
			WzemMSession** rec
			, const ubigint refWzemMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WzemMSession* _rec = NULL;

	_rec = new WzemMSession(0, refWzemMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMSession::appendNewRecToRst(
			ListWzemMSession& rst
			, WzemMSession** rec
			, const ubigint refWzemMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	WzemMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMSession::insertRst(
			ListWzemMSession& rst
			, bool transact
		) {
};

void TblWzemMSession::updateRec(
			WzemMSession* rec
		) {
};

void TblWzemMSession::updateRst(
			ListWzemMSession& rst
			, bool transact
		) {
};

void TblWzemMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMSession::loadRecByRef(
			ubigint ref
			, WzemMSession** rec
		) {
	return false;
};

ubigint TblWzemMSession::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemMSession::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemMSession& rst
		) {
	return 0;
};

ubigint TblWzemMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMSession& rst
		) {
	ubigint numload = 0;
	WzemMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMSession
 ******************************************************************************/

MyTblWzemMSession::MyTblWzemMSession() :
			TblWzemMSession()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMSession::~MyTblWzemMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMSession (refWzemMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMSession SET refWzemMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMSession WHERE ref = ?", false);
};

bool MyTblWzemMSession::loadRecBySQL(
			const string& sqlstr
			, WzemMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMSession::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMSession::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUser = atoll((char*) dbrow[1]); else _rec->refWzemMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMSession::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMSession::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUser = atoll((char*) dbrow[1]); else rec->refWzemMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMSession::insertRec(
			WzemMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMSession::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMSession::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMSession::insertRst(
			ListWzemMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMSession::updateRec(
			WzemMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMSession::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMSession::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMSession::updateRst(
			ListWzemMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMSession::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMSession::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMSession::loadRecByRef(
			ubigint ref
			, WzemMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMSession WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemMSession::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemMSession WHERE refWzemMUser = " + to_string(refWzemMUser) + " ORDER BY start ASC", append, refs);
};

ubigint MyTblWzemMSession::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemMSession& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUser, start, stop, Ip FROM TblWzemMSession WHERE refWzemMUser = " + to_string(refWzemMUser) + " ORDER BY start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMSession
 ******************************************************************************/

PgTblWzemMSession::PgTblWzemMSession() :
			TblWzemMSession()
			, PgTable()
		{
};

PgTblWzemMSession::~PgTblWzemMSession() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMSession::initStatements() {
	createStatement("TblWzemMSession_insertRec", "INSERT INTO TblWzemMSession (refWzemMUser, start, stop, Ip) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemMSession_updateRec", "UPDATE TblWzemMSession SET refWzemMUser = $1, start = $2, stop = $3, Ip = $4 WHERE ref = $5", 5);
	createStatement("TblWzemMSession_removeRecByRef", "DELETE FROM TblWzemMSession WHERE ref = $1", 1);

	createStatement("TblWzemMSession_loadRecByRef", "SELECT ref, refWzemMUser, start, stop, Ip FROM TblWzemMSession WHERE ref = $1", 1);
	createStatement("TblWzemMSession_loadRefsByUsr", "SELECT ref FROM TblWzemMSession WHERE refWzemMUser = $1 ORDER BY start ASC", 1);
	createStatement("TblWzemMSession_loadRstByUsr", "SELECT ref, refWzemMUser, start, stop, Ip FROM TblWzemMSession WHERE refWzemMUser = $1 ORDER BY start ASC", 1);
};

bool PgTblWzemMSession::loadRec(
			PGresult* res
			, WzemMSession** rec
		) {
	char* ptr;

	WzemMSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMSession();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMSession::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		while (numread < numrow) {
			rec = new WzemMSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMSession::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMSession::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMSession& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMSession::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMSession::loadRecBySQL(
			const string& sqlstr
			, WzemMSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMSession::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMSession::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMSession::insertRec(
			WzemMSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWzemMSession_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMSession::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMSession::insertRst(
			ListWzemMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMSession::updateRec(
			WzemMSession* rec
		) {
	PGresult* res;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemMSession_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMSession::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMSession::updateRst(
			ListWzemMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMSession::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWzemMSession_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMSession::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMSession::loadRecByRef(
			ubigint ref
			, WzemMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWzemMSession_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemMSession::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);

	const char* vals[] = {
		(char*) &_refWzemMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemMSession_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemMSession::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemMSession& rst
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);

	const char* vals[] = {
		(char*) &_refWzemMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMSession_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMSession
 ******************************************************************************/

LiteTblWzemMSession::LiteTblWzemMSession() :
			TblWzemMSession()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzemMSession::~LiteTblWzemMSession() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzemMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMSession (refWzemMUser, start, stop, Ip) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMSession SET refWzemMUser = ?1, start = ?2, stop = ?3, Ip = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMSession WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUser, start, stop, Ip FROM TblWzemMSession WHERE ref = ?1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblWzemMSession WHERE refWzemMUser = ?1 ORDER BY start ASC");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzemMUser, start, stop, Ip FROM TblWzemMSession WHERE refWzemMUser = ?1 ORDER BY start ASC");
};

bool LiteTblWzemMSession::loadRec(
			sqlite3_stmt* stmt
			, WzemMSession** rec
		) {
	int res;

	WzemMSession* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMSession();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		_rec->start = sqlite3_column_int(stmt, 2);
		_rec->stop = sqlite3_column_int(stmt, 3);
		_rec->Ip.assign((const char*) sqlite3_column_text(stmt, 4));

		res = sqlite3_step(stmt);
		if (res == SQLITE_DONE) {
			*rec = _rec;
			retval = true;
		} else {
			delete _rec;
		};
	};

	return retval;
};

ubigint LiteTblWzemMSession::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMSession& rst
		) {
	int res; ubigint numread = 0;

	WzemMSession* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMSession();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		rec->start = sqlite3_column_int(stmt, 2);
		rec->stop = sqlite3_column_int(stmt, 3);
		rec->Ip.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMSession::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMSession** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMSession::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMSession& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMSession::loadRecBySQL(
			const string& sqlstr
			, WzemMSession** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMSession::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMSession& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMSession::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMSession::insertRec(
			WzemMSession* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->start);
	sqlite3_bind_int(stmtInsertRec, 3, rec->stop);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMSession::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMSession::insertRst(
			ListWzemMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMSession::updateRec(
			WzemMSession* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->stop);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMSession::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMSession::updateRst(
			ListWzemMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMSession::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMSession::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMSession::loadRecByRef(
			ubigint ref
			, WzemMSession** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemMSession::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refWzemMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblWzemMSession::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemMSession& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzemMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif

