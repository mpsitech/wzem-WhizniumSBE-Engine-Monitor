/**
	* \file WzemJMUserState.cpp
	* database access for table TblWzemJMUserState (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemJMUserState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMUserState
 ******************************************************************************/

WzemJMUserState::WzemJMUserState(
			const ubigint ref
			, const ubigint refWzemMUser
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refWzemMUser = refWzemMUser;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool WzemJMUserState::operator==(
			const WzemJMUserState& comp
		) {
	return false;
};

bool WzemJMUserState::operator!=(
			const WzemJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMUserState
 ******************************************************************************/

ListWzemJMUserState::ListWzemJMUserState() {
};

ListWzemJMUserState::ListWzemJMUserState(
			const ListWzemJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMUserState(*(src.nodes[i]));
};

ListWzemJMUserState::~ListWzemJMUserState() {
	clear();
};

void ListWzemJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMUserState::size() const {
	return(nodes.size());
};

void ListWzemJMUserState::append(
			WzemJMUserState* rec
		) {
	nodes.push_back(rec);
};

WzemJMUserState* ListWzemJMUserState::operator[](
			const uint ix
		) {
	WzemJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMUserState& ListWzemJMUserState::operator=(
			const ListWzemJMUserState& src
		) {
	WzemJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMUserState::operator==(
			const ListWzemJMUserState& comp
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

bool ListWzemJMUserState::operator!=(
			const ListWzemJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMUserState
 ******************************************************************************/

TblWzemJMUserState::TblWzemJMUserState() {
};

TblWzemJMUserState::~TblWzemJMUserState() {
};

bool TblWzemJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzemJMUserState** rec
		) {
	return false;
};

ubigint TblWzemJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMUserState& rst
		) {
	return 0;
};

ubigint TblWzemJMUserState::insertRec(
			WzemJMUserState* rec
		) {
	return 0;
};

ubigint TblWzemJMUserState::insertNewRec(
			WzemJMUserState** rec
			, const ubigint refWzemMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WzemJMUserState* _rec = NULL;

	_rec = new WzemJMUserState(0, refWzemMUser, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMUserState::appendNewRecToRst(
			ListWzemJMUserState& rst
			, WzemJMUserState** rec
			, const ubigint refWzemMUser
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	WzemJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUser, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMUserState::insertRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
};

void TblWzemJMUserState::updateRec(
			WzemJMUserState* rec
		) {
};

void TblWzemJMUserState::updateRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
};

void TblWzemJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMUserState::loadRecByRef(
			ubigint ref
			, WzemJMUserState** rec
		) {
	return false;
};

bool TblWzemJMUserState::loadRecByUsrSta(
			ubigint refWzemMUser
			, uint x1Start
			, WzemJMUserState** rec
		) {
	return false;
};

ubigint TblWzemJMUserState::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemJMUserState::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemJMUserState& rst
		) {
	return 0;
};

ubigint TblWzemJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMUserState& rst
		) {
	ubigint numload = 0;
	WzemJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMUserState
 ******************************************************************************/

MyTblWzemJMUserState::MyTblWzemJMUserState() :
			TblWzemJMUserState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMUserState::~MyTblWzemJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMUserState (refWzemMUser, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMUserState SET refWzemMUser = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMUserState WHERE ref = ?", false);
};

bool MyTblWzemJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzemJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMUserState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMUserState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUser = atoll((char*) dbrow[1]); else _rec->refWzemMUser = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMUserState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMUserState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUser = atoll((char*) dbrow[1]); else rec->refWzemMUser = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMUserState::insertRec(
			WzemJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMUserState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMUserState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMUserState::insertRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMUserState::updateRec(
			WzemJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMUserState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMUserState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMUserState::updateRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMUserState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMUserState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMUserState::loadRecByRef(
			ubigint ref
			, WzemJMUserState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemJMUserState::loadRecByUsrSta(
			ubigint refWzemMUser
			, uint x1Start
			, WzemJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE refWzemMUser = " + to_string(refWzemMUser) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblWzemJMUserState::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemJMUserState WHERE refWzemMUser = " + to_string(refWzemMUser) + "", append, refs);
};

ubigint MyTblWzemJMUserState::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE refWzemMUser = " + to_string(refWzemMUser) + " ORDER BY x1Start ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMUserState
 ******************************************************************************/

PgTblWzemJMUserState::PgTblWzemJMUserState() :
			TblWzemJMUserState()
			, PgTable()
		{
};

PgTblWzemJMUserState::~PgTblWzemJMUserState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMUserState::initStatements() {
	createStatement("TblWzemJMUserState_insertRec", "INSERT INTO TblWzemJMUserState (refWzemMUser, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWzemJMUserState_updateRec", "UPDATE TblWzemJMUserState SET refWzemMUser = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4);
	createStatement("TblWzemJMUserState_removeRecByRef", "DELETE FROM TblWzemJMUserState WHERE ref = $1", 1);

	createStatement("TblWzemJMUserState_loadRecByRef", "SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE ref = $1", 1);
	createStatement("TblWzemJMUserState_loadRecByUsrSta", "SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE refWzemMUser = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWzemJMUserState_loadRefsByUsr", "SELECT ref FROM TblWzemJMUserState WHERE refWzemMUser = $1", 1);
	createStatement("TblWzemJMUserState_loadRstByUsr", "SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE refWzemMUser = $1 ORDER BY x1Start ASC", 1);
};

bool PgTblWzemJMUserState::loadRec(
			PGresult* res
			, WzemJMUserState** rec
		) {
	char* ptr;

	WzemJMUserState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMUserState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMUserState::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMUserState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMUserState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WzemJMUserState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMUserState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMUserState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMUserState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMUserState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMUserState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMUserState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzemJMUserState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMUserState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMUserState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMUserState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMUserState::insertRec(
			WzemJMUserState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemJMUserState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMUserState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMUserState::insertRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMUserState::updateRec(
			WzemJMUserState* rec
		) {
	PGresult* res;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_x1Start,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemJMUserState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMUserState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMUserState::updateRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMUserState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMUserState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMUserState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMUserState::loadRecByRef(
			ubigint ref
			, WzemJMUserState** rec
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

	return loadRecByStmt("TblWzemJMUserState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemJMUserState::loadRecByUsrSta(
			ubigint refWzemMUser
			, uint x1Start
			, WzemJMUserState** rec
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWzemJMUserState_loadRecByUsrSta", 2, vals, l, f, rec);
};

ubigint PgTblWzemJMUserState::loadRefsByUsr(
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

	return loadRefsByStmt("TblWzemJMUserState_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemJMUserState::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemJMUserState& rst
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);

	const char* vals[] = {
		(char*) &_refWzemMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMUserState_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMUserState
 ******************************************************************************/

LiteTblWzemJMUserState::LiteTblWzemJMUserState() :
			TblWzemJMUserState()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrSta = NULL;
	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzemJMUserState::~LiteTblWzemJMUserState() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrSta) sqlite3_finalize(stmtLoadRecByUsrSta);
	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzemJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMUserState (refWzemMUser, x1Start, ixVState) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMUserState SET refWzemMUser = ?1, x1Start = ?2, ixVState = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMUserState WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE ref = ?1");
	stmtLoadRecByUsrSta = createStatement("SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE refWzemMUser = ?1 AND x1Start <= ?2 ORDER BY x1Start DESC LIMIT 0,1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblWzemJMUserState WHERE refWzemMUser = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzemMUser, x1Start, ixVState FROM TblWzemJMUserState WHERE refWzemMUser = ?1 ORDER BY x1Start ASC");
};

bool LiteTblWzemJMUserState::loadRec(
			sqlite3_stmt* stmt
			, WzemJMUserState** rec
		) {
	int res;

	WzemJMUserState* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMUserState();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		_rec->x1Start = sqlite3_column_int(stmt, 2);
		_rec->ixVState = sqlite3_column_int(stmt, 3);

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

ubigint LiteTblWzemJMUserState::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMUserState& rst
		) {
	int res; ubigint numread = 0;

	WzemJMUserState* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMUserState();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		rec->x1Start = sqlite3_column_int(stmt, 2);
		rec->ixVState = sqlite3_column_int(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMUserState::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMUserState** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMUserState::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMUserState& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMUserState::loadRecBySQL(
			const string& sqlstr
			, WzemJMUserState** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMUserState::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMUserState& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMUserState::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMUserState::insertRec(
			WzemJMUserState* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1Start);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixVState);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMUserState::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMUserState::insertRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMUserState::updateRec(
			WzemJMUserState* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1Start);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixVState);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMUserState::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMUserState::updateRst(
			ListWzemJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMUserState::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMUserState::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMUserState::loadRecByRef(
			ubigint ref
			, WzemJMUserState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemJMUserState::loadRecByUsrSta(
			ubigint refWzemMUser
			, uint x1Start
			, WzemJMUserState** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrSta, 1, refWzemMUser);
	sqlite3_bind_int(stmtLoadRecByUsrSta, 2, x1Start);

	return loadRecByStmt(stmtLoadRecByUsrSta, rec);
};

ubigint LiteTblWzemJMUserState::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refWzemMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblWzemJMUserState::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemJMUserState& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzemMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif

