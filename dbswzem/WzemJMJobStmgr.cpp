/**
	* \file WzemJMJobStmgr.cpp
	* database access for table TblWzemJMJobStmgr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemJMJobStmgr.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMJobStmgr
 ******************************************************************************/

WzemJMJobStmgr::WzemJMJobStmgr(
			const ubigint ref
			, const ubigint refWzemMJob
			, const double x1Startu
			, const double x1Stopu
			, const bool Stmgr
		) {

	this->ref = ref;
	this->refWzemMJob = refWzemMJob;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->Stmgr = Stmgr;
};

bool WzemJMJobStmgr::operator==(
			const WzemJMJobStmgr& comp
		) {
	return false;
};

bool WzemJMJobStmgr::operator!=(
			const WzemJMJobStmgr& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMJobStmgr
 ******************************************************************************/

ListWzemJMJobStmgr::ListWzemJMJobStmgr() {
};

ListWzemJMJobStmgr::ListWzemJMJobStmgr(
			const ListWzemJMJobStmgr& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMJobStmgr(*(src.nodes[i]));
};

ListWzemJMJobStmgr::~ListWzemJMJobStmgr() {
	clear();
};

void ListWzemJMJobStmgr::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMJobStmgr::size() const {
	return(nodes.size());
};

void ListWzemJMJobStmgr::append(
			WzemJMJobStmgr* rec
		) {
	nodes.push_back(rec);
};

WzemJMJobStmgr* ListWzemJMJobStmgr::operator[](
			const uint ix
		) {
	WzemJMJobStmgr* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMJobStmgr& ListWzemJMJobStmgr::operator=(
			const ListWzemJMJobStmgr& src
		) {
	WzemJMJobStmgr* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMJobStmgr(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMJobStmgr::operator==(
			const ListWzemJMJobStmgr& comp
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

bool ListWzemJMJobStmgr::operator!=(
			const ListWzemJMJobStmgr& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMJobStmgr
 ******************************************************************************/

TblWzemJMJobStmgr::TblWzemJMJobStmgr() {
};

TblWzemJMJobStmgr::~TblWzemJMJobStmgr() {
};

bool TblWzemJMJobStmgr::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobStmgr** rec
		) {
	return false;
};

ubigint TblWzemJMJobStmgr::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	return 0;
};

ubigint TblWzemJMJobStmgr::insertRec(
			WzemJMJobStmgr* rec
		) {
	return 0;
};

ubigint TblWzemJMJobStmgr::insertNewRec(
			WzemJMJobStmgr** rec
			, const ubigint refWzemMJob
			, const double x1Startu
			, const double x1Stopu
			, const bool Stmgr
		) {
	ubigint retval = 0;
	WzemJMJobStmgr* _rec = NULL;

	_rec = new WzemJMJobStmgr(0, refWzemMJob, x1Startu, x1Stopu, Stmgr);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMJobStmgr::appendNewRecToRst(
			ListWzemJMJobStmgr& rst
			, WzemJMJobStmgr** rec
			, const ubigint refWzemMJob
			, const double x1Startu
			, const double x1Stopu
			, const bool Stmgr
		) {
	ubigint retval = 0;
	WzemJMJobStmgr* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMJob, x1Startu, x1Stopu, Stmgr);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMJobStmgr::insertRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
};

void TblWzemJMJobStmgr::updateRec(
			WzemJMJobStmgr* rec
		) {
};

void TblWzemJMJobStmgr::updateRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
};

void TblWzemJMJobStmgr::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMJobStmgr::loadRecByRef(
			ubigint ref
			, WzemJMJobStmgr** rec
		) {
	return false;
};

ubigint TblWzemJMJobStmgr::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	return 0;
};

ubigint TblWzemJMJobStmgr::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	ubigint numload = 0;
	WzemJMJobStmgr* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMJobStmgr
 ******************************************************************************/

MyTblWzemJMJobStmgr::MyTblWzemJMJobStmgr() :
			TblWzemJMJobStmgr()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMJobStmgr::~MyTblWzemJMJobStmgr() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMJobStmgr::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMJobStmgr (refWzemMJob, x1Startu, x1Stopu, Stmgr) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMJobStmgr SET refWzemMJob = ?, x1Startu = ?, x1Stopu = ?, Stmgr = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMJobStmgr WHERE ref = ?", false);
};

bool MyTblWzemJMJobStmgr::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobStmgr** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMJobStmgr* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMJobStmgr::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMJobStmgr::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemJMJobStmgr();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMJob = atoll((char*) dbrow[1]); else _rec->refWzemMJob = 0;
		if (dbrow[2]) _rec->x1Startu = atof((char*) dbrow[2]); else _rec->x1Startu = 0.0;
		if (dbrow[3]) _rec->x1Stopu = atof((char*) dbrow[3]); else _rec->x1Stopu = 0.0;
		if (dbrow[4]) _rec->Stmgr = (atoi((char*) dbrow[4]) != 0); else _rec->Stmgr = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMJobStmgr::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMJobStmgr* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMJobStmgr::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMJobStmgr::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemJMJobStmgr();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMJob = atoll((char*) dbrow[1]); else rec->refWzemMJob = 0;
			if (dbrow[2]) rec->x1Startu = atof((char*) dbrow[2]); else rec->x1Startu = 0.0;
			if (dbrow[3]) rec->x1Stopu = atof((char*) dbrow[3]); else rec->x1Stopu = 0.0;
			if (dbrow[4]) rec->Stmgr = (atoi((char*) dbrow[4]) != 0); else rec->Stmgr = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMJobStmgr::insertRec(
			WzemJMJobStmgr* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	tinyint Stmgr = rec->Stmgr;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMJob,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Stmgr,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMJobStmgr::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMJobStmgr::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMJobStmgr::insertRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMJobStmgr::updateRec(
			WzemJMJobStmgr* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	tinyint Stmgr = rec->Stmgr;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMJob,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Stmgr,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMJobStmgr::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMJobStmgr::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMJobStmgr::updateRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMJobStmgr::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMJobStmgr::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMJobStmgr::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMJobStmgr::loadRecByRef(
			ubigint ref
			, WzemJMJobStmgr** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMJobStmgr WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemJMJobStmgr::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMJob, x1Startu, x1Stopu, Stmgr FROM TblWzemJMJobStmgr WHERE refWzemMJob = " + to_string(refWzemMJob) + " ORDER BY x1Startu ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMJobStmgr
 ******************************************************************************/

PgTblWzemJMJobStmgr::PgTblWzemJMJobStmgr() :
			TblWzemJMJobStmgr()
			, PgTable()
		{
};

PgTblWzemJMJobStmgr::~PgTblWzemJMJobStmgr() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMJobStmgr::initStatements() {
	createStatement("TblWzemJMJobStmgr_insertRec", "INSERT INTO TblWzemJMJobStmgr (refWzemMJob, x1Startu, x1Stopu, Stmgr) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemJMJobStmgr_updateRec", "UPDATE TblWzemJMJobStmgr SET refWzemMJob = $1, x1Startu = $2, x1Stopu = $3, Stmgr = $4 WHERE ref = $5", 5);
	createStatement("TblWzemJMJobStmgr_removeRecByRef", "DELETE FROM TblWzemJMJobStmgr WHERE ref = $1", 1);

	createStatement("TblWzemJMJobStmgr_loadRecByRef", "SELECT ref, refWzemMJob, x1Startu, x1Stopu, Stmgr FROM TblWzemJMJobStmgr WHERE ref = $1", 1);
	createStatement("TblWzemJMJobStmgr_loadRstByJob", "SELECT ref, refWzemMJob, x1Startu, x1Stopu, Stmgr FROM TblWzemJMJobStmgr WHERE refWzemMJob = $1 ORDER BY x1Startu ASC", 1);
};

bool PgTblWzemJMJobStmgr::loadRec(
			PGresult* res
			, WzemJMJobStmgr** rec
		) {
	char* ptr;

	WzemJMJobStmgr* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMJobStmgr();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "stmgr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Stmgr = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMJobStmgr::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMJobStmgr* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "stmgr")
		};

		while (numread < numrow) {
			rec = new WzemJMJobStmgr();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Stmgr = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMJobStmgr::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMJobStmgr** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobStmgr::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMJobStmgr::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobStmgr::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMJobStmgr::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobStmgr** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobStmgr::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMJobStmgr::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobStmgr::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMJobStmgr::insertRec(
			WzemJMJobStmgr* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	smallint _Stmgr = htons((smallint) rec->Stmgr);

	const char* vals[] = {
		(char*) &_refWzemMJob,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_Stmgr
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemJMJobStmgr_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobStmgr::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMJobStmgr::insertRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMJobStmgr::updateRec(
			WzemJMJobStmgr* rec
		) {
	PGresult* res;

	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	smallint _Stmgr = htons((smallint) rec->Stmgr);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMJob,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_Stmgr,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemJMJobStmgr_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMJobStmgr::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMJobStmgr::updateRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMJobStmgr::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMJobStmgr_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMJobStmgr::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMJobStmgr::loadRecByRef(
			ubigint ref
			, WzemJMJobStmgr** rec
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

	return loadRecByStmt("TblWzemJMJobStmgr_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemJMJobStmgr::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	ubigint _refWzemMJob = htonl64(refWzemMJob);

	const char* vals[] = {
		(char*) &_refWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMJobStmgr_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMJobStmgr
 ******************************************************************************/

LiteTblWzemJMJobStmgr::LiteTblWzemJMJobStmgr() :
			TblWzemJMJobStmgr()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByJob = NULL;
};

LiteTblWzemJMJobStmgr::~LiteTblWzemJMJobStmgr() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByJob) sqlite3_finalize(stmtLoadRstByJob);
};

void LiteTblWzemJMJobStmgr::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMJobStmgr (refWzemMJob, x1Startu, x1Stopu, Stmgr) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMJobStmgr SET refWzemMJob = ?1, x1Startu = ?2, x1Stopu = ?3, Stmgr = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMJobStmgr WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMJob, x1Startu, x1Stopu, Stmgr FROM TblWzemJMJobStmgr WHERE ref = ?1");
	stmtLoadRstByJob = createStatement("SELECT ref, refWzemMJob, x1Startu, x1Stopu, Stmgr FROM TblWzemJMJobStmgr WHERE refWzemMJob = ?1 ORDER BY x1Startu ASC");
};

bool LiteTblWzemJMJobStmgr::loadRec(
			sqlite3_stmt* stmt
			, WzemJMJobStmgr** rec
		) {
	int res;

	WzemJMJobStmgr* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMJobStmgr();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 1);
		_rec->x1Startu = sqlite3_column_double(stmt, 2);
		_rec->x1Stopu = sqlite3_column_double(stmt, 3);
		_rec->Stmgr = (sqlite3_column_int(stmt, 4) != 0);

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

ubigint LiteTblWzemJMJobStmgr::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	int res; ubigint numread = 0;

	WzemJMJobStmgr* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMJobStmgr();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 1);
		rec->x1Startu = sqlite3_column_double(stmt, 2);
		rec->x1Stopu = sqlite3_column_double(stmt, 3);
		rec->Stmgr = (sqlite3_column_int(stmt, 4) != 0);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMJobStmgr::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMJobStmgr** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMJobStmgr::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMJobStmgr::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobStmgr** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMJobStmgr::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMJobStmgr::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMJobStmgr::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMJobStmgr::insertRec(
			WzemJMJobStmgr* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMJob);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 3, rec->x1Stopu);
	sqlite3_bind_int(stmtInsertRec, 4, rec->Stmgr);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMJobStmgr::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMJobStmgr::insertRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMJobStmgr::updateRec(
			WzemJMJobStmgr* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMJob);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 3, rec->x1Stopu);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->Stmgr);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMJobStmgr::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMJobStmgr::updateRst(
			ListWzemJMJobStmgr& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMJobStmgr::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMJobStmgr::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMJobStmgr::loadRecByRef(
			ubigint ref
			, WzemJMJobStmgr** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemJMJobStmgr::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobStmgr& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJob, 1, refWzemMJob);

	return loadRstByStmt(stmtLoadRstByJob, append, rst);
};

#endif
