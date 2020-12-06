/**
	* \file WzemMCall.cpp
	* database access for table TblWzemMCall (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemMCall.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMCall
 ******************************************************************************/

WzemMCall::WzemMCall(
			const ubigint ref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVCall
			, const string argInv
			, const string argRet
		) {

	this->ref = ref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->refWzemMJob = refWzemMJob;
	this->srefIxVCall = srefIxVCall;
	this->argInv = argInv;
	this->argRet = argRet;
};

bool WzemMCall::operator==(
			const WzemMCall& comp
		) {
	return false;
};

bool WzemMCall::operator!=(
			const WzemMCall& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMCall
 ******************************************************************************/

ListWzemMCall::ListWzemMCall() {
};

ListWzemMCall::ListWzemMCall(
			const ListWzemMCall& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMCall(*(src.nodes[i]));
};

ListWzemMCall::~ListWzemMCall() {
	clear();
};

void ListWzemMCall::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMCall::size() const {
	return(nodes.size());
};

void ListWzemMCall::append(
			WzemMCall* rec
		) {
	nodes.push_back(rec);
};

WzemMCall* ListWzemMCall::operator[](
			const uint ix
		) {
	WzemMCall* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMCall& ListWzemMCall::operator=(
			const ListWzemMCall& src
		) {
	WzemMCall* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMCall(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMCall::operator==(
			const ListWzemMCall& comp
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

bool ListWzemMCall::operator!=(
			const ListWzemMCall& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMCall
 ******************************************************************************/

TblWzemMCall::TblWzemMCall() {
};

TblWzemMCall::~TblWzemMCall() {
};

bool TblWzemMCall::loadRecBySQL(
			const string& sqlstr
			, WzemMCall** rec
		) {
	return false;
};

ubigint TblWzemMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMCall& rst
		) {
	return 0;
};

ubigint TblWzemMCall::insertRec(
			WzemMCall* rec
		) {
	return 0;
};

ubigint TblWzemMCall::insertNewRec(
			WzemMCall** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVCall
			, const string argInv
			, const string argRet
		) {
	ubigint retval = 0;
	WzemMCall* _rec = NULL;

	_rec = new WzemMCall(0, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMCall::appendNewRecToRst(
			ListWzemMCall& rst
			, WzemMCall** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVCall
			, const string argInv
			, const string argRet
		) {
	ubigint retval = 0;
	WzemMCall* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMCall::insertRst(
			ListWzemMCall& rst
			, bool transact
		) {
};

void TblWzemMCall::updateRec(
			WzemMCall* rec
		) {
};

void TblWzemMCall::updateRst(
			ListWzemMCall& rst
			, bool transact
		) {
};

void TblWzemMCall::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMCall::loadRecByRef(
			ubigint ref
			, WzemMCall** rec
		) {
	return false;
};

ubigint TblWzemMCall::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMCall& rst
		) {
	return 0;
};

ubigint TblWzemMCall::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMCall& rst
		) {
	ubigint numload = 0;
	WzemMCall* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMCall
 ******************************************************************************/

MyTblWzemMCall::MyTblWzemMCall() :
			TblWzemMCall()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMCall::~MyTblWzemMCall() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMCall::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMCall (x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMCall SET x1Startu = ?, x1Stopu = ?, refWzemMJob = ?, srefIxVCall = ?, argInv = ?, argRet = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMCall WHERE ref = ?", false);
};

bool MyTblWzemMCall::loadRecBySQL(
			const string& sqlstr
			, WzemMCall** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMCall* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMCall::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMCall::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMCall();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startu = atof((char*) dbrow[1]); else _rec->x1Startu = 0.0;
		if (dbrow[2]) _rec->x1Stopu = atof((char*) dbrow[2]); else _rec->x1Stopu = 0.0;
		if (dbrow[3]) _rec->refWzemMJob = atoll((char*) dbrow[3]); else _rec->refWzemMJob = 0;
		if (dbrow[4]) _rec->srefIxVCall.assign(dbrow[4], dblengths[4]); else _rec->srefIxVCall = "";
		if (dbrow[5]) _rec->argInv.assign(dbrow[5], dblengths[5]); else _rec->argInv = "";
		if (dbrow[6]) _rec->argRet.assign(dbrow[6], dblengths[6]); else _rec->argRet = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMCall& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMCall* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMCall::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMCall::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMCall();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startu = atof((char*) dbrow[1]); else rec->x1Startu = 0.0;
			if (dbrow[2]) rec->x1Stopu = atof((char*) dbrow[2]); else rec->x1Stopu = 0.0;
			if (dbrow[3]) rec->refWzemMJob = atoll((char*) dbrow[3]); else rec->refWzemMJob = 0;
			if (dbrow[4]) rec->srefIxVCall.assign(dbrow[4], dblengths[4]); else rec->srefIxVCall = "";
			if (dbrow[5]) rec->argInv.assign(dbrow[5], dblengths[5]); else rec->argInv = "";
			if (dbrow[6]) rec->argRet.assign(dbrow[6], dblengths[6]); else rec->argRet = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMCall::insertRec(
			WzemMCall* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->srefIxVCall.length();
	l[4] = rec->argInv.length();
	l[5] = rec->argRet.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefIxVCall.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->argInv.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->argRet.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMCall::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMCall::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMCall::insertRst(
			ListWzemMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMCall::updateRec(
			WzemMCall* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->srefIxVCall.length();
	l[4] = rec->argInv.length();
	l[5] = rec->argRet.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefIxVCall.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->argInv.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->argRet.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMCall::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMCall::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMCall::updateRst(
			ListWzemMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMCall::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMCall::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMCall::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMCall::loadRecByRef(
			ubigint ref
			, WzemMCall** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMCall WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemMCall::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMCall& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet FROM TblWzemMCall WHERE refWzemMJob = " + to_string(refWzemMJob) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMCall
 ******************************************************************************/

PgTblWzemMCall::PgTblWzemMCall() :
			TblWzemMCall()
			, PgTable()
		{
};

PgTblWzemMCall::~PgTblWzemMCall() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMCall::initStatements() {
	createStatement("TblWzemMCall_insertRec", "INSERT INTO TblWzemMCall (x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWzemMCall_updateRec", "UPDATE TblWzemMCall SET x1Startu = $1, x1Stopu = $2, refWzemMJob = $3, srefIxVCall = $4, argInv = $5, argRet = $6 WHERE ref = $7", 7);
	createStatement("TblWzemMCall_removeRecByRef", "DELETE FROM TblWzemMCall WHERE ref = $1", 1);

	createStatement("TblWzemMCall_loadRecByRef", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet FROM TblWzemMCall WHERE ref = $1", 1);
	createStatement("TblWzemMCall_loadRstByJob", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet FROM TblWzemMCall WHERE refWzemMJob = $1", 1);
};

bool PgTblWzemMCall::loadRec(
			PGresult* res
			, WzemMCall** rec
		) {
	char* ptr;

	WzemMCall* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMCall();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvcall"),
			PQfnumber(res, "arginv"),
			PQfnumber(res, "argret")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefIxVCall.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->argInv.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->argRet.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMCall::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMCall& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMCall* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvcall"),
			PQfnumber(res, "arginv"),
			PQfnumber(res, "argret")
		};

		while (numread < numrow) {
			rec = new WzemMCall();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefIxVCall.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->argInv.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->argRet.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMCall::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMCall** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMCall::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMCall::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMCall& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMCall::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMCall::loadRecBySQL(
			const string& sqlstr
			, WzemMCall** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMCall::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMCall& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMCall::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMCall::insertRec(
			WzemMCall* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMJob,
		rec->srefIxVCall.c_str(),
		rec->argInv.c_str(),
		rec->argRet.c_str()
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {0, 0, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemMCall_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMCall::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMCall::insertRst(
			ListWzemMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMCall::updateRec(
			WzemMCall* rec
		) {
	PGresult* res;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMJob,
		rec->srefIxVCall.c_str(),
		rec->argInv.c_str(),
		rec->argRet.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemMCall_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMCall::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMCall::updateRst(
			ListWzemMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMCall::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMCall_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMCall::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMCall::loadRecByRef(
			ubigint ref
			, WzemMCall** rec
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

	return loadRecByStmt("TblWzemMCall_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemMCall::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMCall& rst
		) {
	ubigint _refWzemMJob = htonl64(refWzemMJob);

	const char* vals[] = {
		(char*) &_refWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMCall_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMCall
 ******************************************************************************/

LiteTblWzemMCall::LiteTblWzemMCall() :
			TblWzemMCall()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByJob = NULL;
};

LiteTblWzemMCall::~LiteTblWzemMCall() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByJob) sqlite3_finalize(stmtLoadRstByJob);
};

void LiteTblWzemMCall::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMCall (x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMCall SET x1Startu = ?1, x1Stopu = ?2, refWzemMJob = ?3, srefIxVCall = ?4, argInv = ?5, argRet = ?6 WHERE ref = ?7");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMCall WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet FROM TblWzemMCall WHERE ref = ?1");
	stmtLoadRstByJob = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, argInv, argRet FROM TblWzemMCall WHERE refWzemMJob = ?1");
};

bool LiteTblWzemMCall::loadRec(
			sqlite3_stmt* stmt
			, WzemMCall** rec
		) {
	int res;

	WzemMCall* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMCall();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->x1Startu = sqlite3_column_double(stmt, 1);
		_rec->x1Stopu = sqlite3_column_double(stmt, 2);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		_rec->srefIxVCall.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->argInv.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->argRet.assign((const char*) sqlite3_column_text(stmt, 6));

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

ubigint LiteTblWzemMCall::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMCall& rst
		) {
	int res; ubigint numread = 0;

	WzemMCall* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMCall();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->x1Startu = sqlite3_column_double(stmt, 1);
		rec->x1Stopu = sqlite3_column_double(stmt, 2);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		rec->srefIxVCall.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->argInv.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->argRet.assign((const char*) sqlite3_column_text(stmt, 6));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMCall::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMCall** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMCall::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMCall& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMCall::loadRecBySQL(
			const string& sqlstr
			, WzemMCall** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMCall::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMCall& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMCall::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMCall::insertRec(
			WzemMCall* rec
		) {
	sqlite3_bind_double(stmtInsertRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMJob);
	sqlite3_bind_text(stmtInsertRec, 4, rec->srefIxVCall.c_str(), rec->srefIxVCall.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->argInv.c_str(), rec->argInv.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 6, rec->argRet.c_str(), rec->argRet.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMCall::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMCall::insertRst(
			ListWzemMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMCall::updateRec(
			WzemMCall* rec
		) {
	sqlite3_bind_double(stmtUpdateRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMJob);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->srefIxVCall.c_str(), rec->srefIxVCall.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->argInv.c_str(), rec->argInv.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->argRet.c_str(), rec->argRet.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMCall::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMCall::updateRst(
			ListWzemMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMCall::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMCall::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMCall::loadRecByRef(
			ubigint ref
			, WzemMCall** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemMCall::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMCall& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJob, 1, refWzemMJob);

	return loadRstByStmt(stmtLoadRstByJob, append, rst);
};

#endif
