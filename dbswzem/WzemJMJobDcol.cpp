/**
	* \file WzemJMJobDcol.cpp
	* database access for table TblWzemJMJobDcol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemJMJobDcol.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMJobDcol
 ******************************************************************************/

WzemJMJobDcol::WzemJMJobDcol(
			const ubigint ref
			, const ubigint refWzemMJob
			, const double x1Startu
			, const double x1Stopu
			, const bool Dcol
		) {

	this->ref = ref;
	this->refWzemMJob = refWzemMJob;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->Dcol = Dcol;
};

bool WzemJMJobDcol::operator==(
			const WzemJMJobDcol& comp
		) {
	return false;
};

bool WzemJMJobDcol::operator!=(
			const WzemJMJobDcol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMJobDcol
 ******************************************************************************/

ListWzemJMJobDcol::ListWzemJMJobDcol() {
};

ListWzemJMJobDcol::ListWzemJMJobDcol(
			const ListWzemJMJobDcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMJobDcol(*(src.nodes[i]));
};

ListWzemJMJobDcol::~ListWzemJMJobDcol() {
	clear();
};

void ListWzemJMJobDcol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMJobDcol::size() const {
	return(nodes.size());
};

void ListWzemJMJobDcol::append(
			WzemJMJobDcol* rec
		) {
	nodes.push_back(rec);
};

WzemJMJobDcol* ListWzemJMJobDcol::operator[](
			const uint ix
		) {
	WzemJMJobDcol* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMJobDcol& ListWzemJMJobDcol::operator=(
			const ListWzemJMJobDcol& src
		) {
	WzemJMJobDcol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMJobDcol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMJobDcol::operator==(
			const ListWzemJMJobDcol& comp
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

bool ListWzemJMJobDcol::operator!=(
			const ListWzemJMJobDcol& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMJobDcol
 ******************************************************************************/

TblWzemJMJobDcol::TblWzemJMJobDcol() {
};

TblWzemJMJobDcol::~TblWzemJMJobDcol() {
};

bool TblWzemJMJobDcol::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobDcol** rec
		) {
	return false;
};

ubigint TblWzemJMJobDcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	return 0;
};

ubigint TblWzemJMJobDcol::insertRec(
			WzemJMJobDcol* rec
		) {
	return 0;
};

ubigint TblWzemJMJobDcol::insertNewRec(
			WzemJMJobDcol** rec
			, const ubigint refWzemMJob
			, const double x1Startu
			, const double x1Stopu
			, const bool Dcol
		) {
	ubigint retval = 0;
	WzemJMJobDcol* _rec = NULL;

	_rec = new WzemJMJobDcol(0, refWzemMJob, x1Startu, x1Stopu, Dcol);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMJobDcol::appendNewRecToRst(
			ListWzemJMJobDcol& rst
			, WzemJMJobDcol** rec
			, const ubigint refWzemMJob
			, const double x1Startu
			, const double x1Stopu
			, const bool Dcol
		) {
	ubigint retval = 0;
	WzemJMJobDcol* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMJob, x1Startu, x1Stopu, Dcol);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMJobDcol::insertRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
};

void TblWzemJMJobDcol::updateRec(
			WzemJMJobDcol* rec
		) {
};

void TblWzemJMJobDcol::updateRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
};

void TblWzemJMJobDcol::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMJobDcol::loadRecByRef(
			ubigint ref
			, WzemJMJobDcol** rec
		) {
	return false;
};

ubigint TblWzemJMJobDcol::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	return 0;
};

ubigint TblWzemJMJobDcol::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	ubigint numload = 0;
	WzemJMJobDcol* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMJobDcol
 ******************************************************************************/

MyTblWzemJMJobDcol::MyTblWzemJMJobDcol() :
			TblWzemJMJobDcol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMJobDcol::~MyTblWzemJMJobDcol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMJobDcol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMJobDcol (refWzemMJob, x1Startu, x1Stopu, Dcol) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMJobDcol SET refWzemMJob = ?, x1Startu = ?, x1Stopu = ?, Dcol = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMJobDcol WHERE ref = ?", false);
};

bool MyTblWzemJMJobDcol::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobDcol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMJobDcol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMJobDcol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMJobDcol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemJMJobDcol();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMJob = atoll((char*) dbrow[1]); else _rec->refWzemMJob = 0;
		if (dbrow[2]) _rec->x1Startu = atof((char*) dbrow[2]); else _rec->x1Startu = 0.0;
		if (dbrow[3]) _rec->x1Stopu = atof((char*) dbrow[3]); else _rec->x1Stopu = 0.0;
		if (dbrow[4]) _rec->Dcol = (atoi((char*) dbrow[4]) != 0); else _rec->Dcol = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMJobDcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMJobDcol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMJobDcol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMJobDcol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemJMJobDcol();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMJob = atoll((char*) dbrow[1]); else rec->refWzemMJob = 0;
			if (dbrow[2]) rec->x1Startu = atof((char*) dbrow[2]); else rec->x1Startu = 0.0;
			if (dbrow[3]) rec->x1Stopu = atof((char*) dbrow[3]); else rec->x1Stopu = 0.0;
			if (dbrow[4]) rec->Dcol = (atoi((char*) dbrow[4]) != 0); else rec->Dcol = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMJobDcol::insertRec(
			WzemJMJobDcol* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	tinyint Dcol = rec->Dcol;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMJob,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Dcol,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMJobDcol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMJobDcol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMJobDcol::insertRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMJobDcol::updateRec(
			WzemJMJobDcol* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	tinyint Dcol = rec->Dcol;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMJob,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Dcol,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMJobDcol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMJobDcol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMJobDcol::updateRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMJobDcol::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMJobDcol::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMJobDcol::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMJobDcol::loadRecByRef(
			ubigint ref
			, WzemJMJobDcol** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMJobDcol WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemJMJobDcol::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMJob, x1Startu, x1Stopu, Dcol FROM TblWzemJMJobDcol WHERE refWzemMJob = " + to_string(refWzemMJob) + " ORDER BY x1Startu ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMJobDcol
 ******************************************************************************/

PgTblWzemJMJobDcol::PgTblWzemJMJobDcol() :
			TblWzemJMJobDcol()
			, PgTable()
		{
};

PgTblWzemJMJobDcol::~PgTblWzemJMJobDcol() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMJobDcol::initStatements() {
	createStatement("TblWzemJMJobDcol_insertRec", "INSERT INTO TblWzemJMJobDcol (refWzemMJob, x1Startu, x1Stopu, Dcol) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemJMJobDcol_updateRec", "UPDATE TblWzemJMJobDcol SET refWzemMJob = $1, x1Startu = $2, x1Stopu = $3, Dcol = $4 WHERE ref = $5", 5);
	createStatement("TblWzemJMJobDcol_removeRecByRef", "DELETE FROM TblWzemJMJobDcol WHERE ref = $1", 1);

	createStatement("TblWzemJMJobDcol_loadRecByRef", "SELECT ref, refWzemMJob, x1Startu, x1Stopu, Dcol FROM TblWzemJMJobDcol WHERE ref = $1", 1);
	createStatement("TblWzemJMJobDcol_loadRstByJob", "SELECT ref, refWzemMJob, x1Startu, x1Stopu, Dcol FROM TblWzemJMJobDcol WHERE refWzemMJob = $1 ORDER BY x1Startu ASC", 1);
};

bool PgTblWzemJMJobDcol::loadRec(
			PGresult* res
			, WzemJMJobDcol** rec
		) {
	char* ptr;

	WzemJMJobDcol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMJobDcol();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "dcol")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Dcol = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMJobDcol::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMJobDcol* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "dcol")
		};

		while (numread < numrow) {
			rec = new WzemJMJobDcol();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Dcol = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMJobDcol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMJobDcol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobDcol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMJobDcol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobDcol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMJobDcol::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobDcol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobDcol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMJobDcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobDcol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMJobDcol::insertRec(
			WzemJMJobDcol* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	smallint _Dcol = htons((smallint) rec->Dcol);

	const char* vals[] = {
		(char*) &_refWzemMJob,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_Dcol
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemJMJobDcol_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMJobDcol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMJobDcol::insertRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMJobDcol::updateRec(
			WzemJMJobDcol* rec
		) {
	PGresult* res;

	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	smallint _Dcol = htons((smallint) rec->Dcol);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMJob,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_Dcol,
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

	res = PQexecPrepared(dbs, "TblWzemJMJobDcol_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMJobDcol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMJobDcol::updateRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMJobDcol::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMJobDcol_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMJobDcol::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMJobDcol::loadRecByRef(
			ubigint ref
			, WzemJMJobDcol** rec
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

	return loadRecByStmt("TblWzemJMJobDcol_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemJMJobDcol::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	ubigint _refWzemMJob = htonl64(refWzemMJob);

	const char* vals[] = {
		(char*) &_refWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMJobDcol_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMJobDcol
 ******************************************************************************/

LiteTblWzemJMJobDcol::LiteTblWzemJMJobDcol() :
			TblWzemJMJobDcol()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByJob = NULL;
};

LiteTblWzemJMJobDcol::~LiteTblWzemJMJobDcol() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByJob) sqlite3_finalize(stmtLoadRstByJob);
};

void LiteTblWzemJMJobDcol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMJobDcol (refWzemMJob, x1Startu, x1Stopu, Dcol) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMJobDcol SET refWzemMJob = ?1, x1Startu = ?2, x1Stopu = ?3, Dcol = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMJobDcol WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMJob, x1Startu, x1Stopu, Dcol FROM TblWzemJMJobDcol WHERE ref = ?1");
	stmtLoadRstByJob = createStatement("SELECT ref, refWzemMJob, x1Startu, x1Stopu, Dcol FROM TblWzemJMJobDcol WHERE refWzemMJob = ?1 ORDER BY x1Startu ASC");
};

bool LiteTblWzemJMJobDcol::loadRec(
			sqlite3_stmt* stmt
			, WzemJMJobDcol** rec
		) {
	int res;

	WzemJMJobDcol* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMJobDcol();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 1);
		_rec->x1Startu = sqlite3_column_double(stmt, 2);
		_rec->x1Stopu = sqlite3_column_double(stmt, 3);
		_rec->Dcol = (sqlite3_column_int(stmt, 4) != 0);

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

ubigint LiteTblWzemJMJobDcol::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	int res; ubigint numread = 0;

	WzemJMJobDcol* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMJobDcol();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 1);
		rec->x1Startu = sqlite3_column_double(stmt, 2);
		rec->x1Stopu = sqlite3_column_double(stmt, 3);
		rec->Dcol = (sqlite3_column_int(stmt, 4) != 0);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMJobDcol::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMJobDcol** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMJobDcol::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMJobDcol::loadRecBySQL(
			const string& sqlstr
			, WzemJMJobDcol** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMJobDcol::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMJobDcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMJobDcol::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMJobDcol::insertRec(
			WzemJMJobDcol* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMJob);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 3, rec->x1Stopu);
	sqlite3_bind_int(stmtInsertRec, 4, rec->Dcol);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMJobDcol::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMJobDcol::insertRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMJobDcol::updateRec(
			WzemJMJobDcol* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMJob);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 3, rec->x1Stopu);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->Dcol);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMJobDcol::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMJobDcol::updateRst(
			ListWzemJMJobDcol& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMJobDcol::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMJobDcol::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMJobDcol::loadRecByRef(
			ubigint ref
			, WzemJMJobDcol** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemJMJobDcol::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemJMJobDcol& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJob, 1, refWzemMJob);

	return loadRstByStmt(stmtLoadRstByJob, append, rst);
};

#endif
