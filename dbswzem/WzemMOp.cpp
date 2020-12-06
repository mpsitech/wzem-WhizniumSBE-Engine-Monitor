/**
	* \file WzemMOp.cpp
	* database access for table TblWzemMOp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemMOp.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMOp
 ******************************************************************************/

WzemMOp::WzemMOp(
			const ubigint ref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const ubigint xoref
		) {

	this->ref = ref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->refWzemMJob = refWzemMJob;
	this->xoref = xoref;
};

bool WzemMOp::operator==(
			const WzemMOp& comp
		) {
	return false;
};

bool WzemMOp::operator!=(
			const WzemMOp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMOp
 ******************************************************************************/

ListWzemMOp::ListWzemMOp() {
};

ListWzemMOp::ListWzemMOp(
			const ListWzemMOp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMOp(*(src.nodes[i]));
};

ListWzemMOp::~ListWzemMOp() {
	clear();
};

void ListWzemMOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMOp::size() const {
	return(nodes.size());
};

void ListWzemMOp::append(
			WzemMOp* rec
		) {
	nodes.push_back(rec);
};

WzemMOp* ListWzemMOp::operator[](
			const uint ix
		) {
	WzemMOp* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMOp& ListWzemMOp::operator=(
			const ListWzemMOp& src
		) {
	WzemMOp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMOp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMOp::operator==(
			const ListWzemMOp& comp
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

bool ListWzemMOp::operator!=(
			const ListWzemMOp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMOp
 ******************************************************************************/

TblWzemMOp::TblWzemMOp() {
};

TblWzemMOp::~TblWzemMOp() {
};

bool TblWzemMOp::loadRecBySQL(
			const string& sqlstr
			, WzemMOp** rec
		) {
	return false;
};

ubigint TblWzemMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMOp& rst
		) {
	return 0;
};

ubigint TblWzemMOp::insertRec(
			WzemMOp* rec
		) {
	return 0;
};

ubigint TblWzemMOp::insertNewRec(
			WzemMOp** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const ubigint xoref
		) {
	ubigint retval = 0;
	WzemMOp* _rec = NULL;

	_rec = new WzemMOp(0, x1Startu, x1Stopu, refWzemMJob, xoref);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMOp::appendNewRecToRst(
			ListWzemMOp& rst
			, WzemMOp** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const ubigint xoref
		) {
	ubigint retval = 0;
	WzemMOp* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startu, x1Stopu, refWzemMJob, xoref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMOp::insertRst(
			ListWzemMOp& rst
			, bool transact
		) {
};

void TblWzemMOp::updateRec(
			WzemMOp* rec
		) {
};

void TblWzemMOp::updateRst(
			ListWzemMOp& rst
			, bool transact
		) {
};

void TblWzemMOp::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMOp::loadRecByRef(
			ubigint ref
			, WzemMOp** rec
		) {
	return false;
};

ubigint TblWzemMOp::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMOp& rst
		) {
	return 0;
};

bool TblWzemMOp::loadXorByRef(
			ubigint ref
			, string& xoref
		) {
	return false;
};

ubigint TblWzemMOp::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMOp& rst
		) {
	ubigint numload = 0;
	WzemMOp* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMOp
 ******************************************************************************/

MyTblWzemMOp::MyTblWzemMOp() :
			TblWzemMOp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMOp::~MyTblWzemMOp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMOp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMOp (x1Startu, x1Stopu, refWzemMJob, xoref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMOp SET x1Startu = ?, x1Stopu = ?, refWzemMJob = ?, xoref = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMOp WHERE ref = ?", false);
};

bool MyTblWzemMOp::loadRecBySQL(
			const string& sqlstr
			, WzemMOp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMOp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMOp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMOp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemMOp();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startu = atof((char*) dbrow[1]); else _rec->x1Startu = 0.0;
		if (dbrow[2]) _rec->x1Stopu = atof((char*) dbrow[2]); else _rec->x1Stopu = 0.0;
		if (dbrow[3]) _rec->refWzemMJob = atoll((char*) dbrow[3]); else _rec->refWzemMJob = 0;
		if (dbrow[4]) _rec->xoref = atoll((char*) dbrow[4]); else _rec->xoref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMOp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMOp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMOp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMOp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemMOp();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startu = atof((char*) dbrow[1]); else rec->x1Startu = 0.0;
			if (dbrow[2]) rec->x1Stopu = atof((char*) dbrow[2]); else rec->x1Stopu = 0.0;
			if (dbrow[3]) rec->refWzemMJob = atoll((char*) dbrow[3]); else rec->refWzemMJob = 0;
			if (dbrow[4]) rec->xoref = atoll((char*) dbrow[4]); else rec->xoref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMOp::insertRec(
			WzemMOp* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->xoref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMOp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMOp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMOp::insertRst(
			ListWzemMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMOp::updateRec(
			WzemMOp* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->xoref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMOp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMOp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMOp::updateRst(
			ListWzemMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMOp::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMOp::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMOp::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMOp::loadRecByRef(
			ubigint ref
			, WzemMOp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMOp WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemMOp::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMOp& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMJob, xoref FROM TblWzemMOp WHERE refWzemMJob = " + to_string(refWzemMJob) + "", append, rst);
};

bool MyTblWzemMOp::loadXorByRef(
			ubigint ref
			, string& xoref
		) {
	return loadStringBySQL("SELECT xoref FROM TblWzemMOp WHERE ref = " + to_string(ref) + "", xoref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMOp
 ******************************************************************************/

PgTblWzemMOp::PgTblWzemMOp() :
			TblWzemMOp()
			, PgTable()
		{
};

PgTblWzemMOp::~PgTblWzemMOp() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMOp::initStatements() {
	createStatement("TblWzemMOp_insertRec", "INSERT INTO TblWzemMOp (x1Startu, x1Stopu, refWzemMJob, xoref) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemMOp_updateRec", "UPDATE TblWzemMOp SET x1Startu = $1, x1Stopu = $2, refWzemMJob = $3, xoref = $4 WHERE ref = $5", 5);
	createStatement("TblWzemMOp_removeRecByRef", "DELETE FROM TblWzemMOp WHERE ref = $1", 1);

	createStatement("TblWzemMOp_loadRecByRef", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, xoref FROM TblWzemMOp WHERE ref = $1", 1);
	createStatement("TblWzemMOp_loadRstByJob", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, xoref FROM TblWzemMOp WHERE refWzemMJob = $1", 1);
	createStatement("TblWzemMOp_loadXorByRef", "SELECT xoref FROM TblWzemMOp WHERE ref = $1", 1);
};

bool PgTblWzemMOp::loadRec(
			PGresult* res
			, WzemMOp** rec
		) {
	char* ptr;

	WzemMOp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMOp();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "xoref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->xoref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMOp::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMOp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMOp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "xoref")
		};

		while (numread < numrow) {
			rec = new WzemMOp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->xoref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMOp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMOp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMOp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMOp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMOp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMOp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMOp::loadRecBySQL(
			const string& sqlstr
			, WzemMOp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMOp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMOp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMOp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMOp::insertRec(
			WzemMOp* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _xoref = htonl64(rec->xoref);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMJob,
		(char*) &_xoref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMOp_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMOp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMOp::insertRst(
			ListWzemMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMOp::updateRec(
			WzemMOp* rec
		) {
	PGresult* res;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _xoref = htonl64(rec->xoref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMJob,
		(char*) &_xoref,
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMOp_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMOp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMOp::updateRst(
			ListWzemMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMOp::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMOp_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMOp::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMOp::loadRecByRef(
			ubigint ref
			, WzemMOp** rec
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

	return loadRecByStmt("TblWzemMOp_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemMOp::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMOp& rst
		) {
	ubigint _refWzemMJob = htonl64(refWzemMJob);

	const char* vals[] = {
		(char*) &_refWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMOp_loadRstByJob", 1, vals, l, f, append, rst);
};

bool PgTblWzemMOp::loadXorByRef(
			ubigint ref
			, string& xoref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWzemMOp_loadXorByRef", 1, vals, l, f, xoref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMOp
 ******************************************************************************/

LiteTblWzemMOp::LiteTblWzemMOp() :
			TblWzemMOp()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByJob = NULL;
	stmtLoadXorByRef = NULL;
};

LiteTblWzemMOp::~LiteTblWzemMOp() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByJob) sqlite3_finalize(stmtLoadRstByJob);
	if (stmtLoadXorByRef) sqlite3_finalize(stmtLoadXorByRef);
};

void LiteTblWzemMOp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMOp (x1Startu, x1Stopu, refWzemMJob, xoref) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMOp SET x1Startu = ?1, x1Stopu = ?2, refWzemMJob = ?3, xoref = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMOp WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, xoref FROM TblWzemMOp WHERE ref = ?1");
	stmtLoadRstByJob = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, xoref FROM TblWzemMOp WHERE refWzemMJob = ?1");
	stmtLoadXorByRef = createStatement("SELECT xoref FROM TblWzemMOp WHERE ref = ?1");
};

bool LiteTblWzemMOp::loadRec(
			sqlite3_stmt* stmt
			, WzemMOp** rec
		) {
	int res;

	WzemMOp* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMOp();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->x1Startu = sqlite3_column_double(stmt, 1);
		_rec->x1Stopu = sqlite3_column_double(stmt, 2);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		_rec->xoref = sqlite3_column_int64(stmt, 4);

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

ubigint LiteTblWzemMOp::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMOp& rst
		) {
	int res; ubigint numread = 0;

	WzemMOp* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMOp();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->x1Startu = sqlite3_column_double(stmt, 1);
		rec->x1Stopu = sqlite3_column_double(stmt, 2);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		rec->xoref = sqlite3_column_int64(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMOp::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMOp** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMOp::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMOp& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMOp::loadRecBySQL(
			const string& sqlstr
			, WzemMOp** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMOp::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMOp& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMOp::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMOp::insertRec(
			WzemMOp* rec
		) {
	sqlite3_bind_double(stmtInsertRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMJob);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->xoref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMOp::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMOp::insertRst(
			ListWzemMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMOp::updateRec(
			WzemMOp* rec
		) {
	sqlite3_bind_double(stmtUpdateRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMJob);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->xoref);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMOp::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMOp::updateRst(
			ListWzemMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMOp::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMOp::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMOp::loadRecByRef(
			ubigint ref
			, WzemMOp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemMOp::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMOp& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJob, 1, refWzemMJob);

	return loadRstByStmt(stmtLoadRstByJob, append, rst);
};

bool LiteTblWzemMOp::loadXorByRef(
			ubigint ref
			, string& xoref
		) {
	sqlite3_bind_int64(stmtLoadXorByRef, 1, ref);

	return loadStringByStmt(stmtLoadXorByRef, xoref);
};

#endif

