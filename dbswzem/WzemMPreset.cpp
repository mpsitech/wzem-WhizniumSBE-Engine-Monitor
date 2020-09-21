/**
	* \file WzemMPreset.cpp
	* database access for table TblWzemMPreset (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemMPreset.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMPreset
 ******************************************************************************/

WzemMPreset::WzemMPreset(
			const ubigint ref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVPreset
			, const string arg
		) {

	this->ref = ref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->refWzemMJob = refWzemMJob;
	this->srefIxVPreset = srefIxVPreset;
	this->arg = arg;
};

bool WzemMPreset::operator==(
			const WzemMPreset& comp
		) {
	return false;
};

bool WzemMPreset::operator!=(
			const WzemMPreset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMPreset
 ******************************************************************************/

ListWzemMPreset::ListWzemMPreset() {
};

ListWzemMPreset::ListWzemMPreset(
			const ListWzemMPreset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMPreset(*(src.nodes[i]));
};

ListWzemMPreset::~ListWzemMPreset() {
	clear();
};

void ListWzemMPreset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMPreset::size() const {
	return(nodes.size());
};

void ListWzemMPreset::append(
			WzemMPreset* rec
		) {
	nodes.push_back(rec);
};

WzemMPreset* ListWzemMPreset::operator[](
			const uint ix
		) {
	WzemMPreset* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMPreset& ListWzemMPreset::operator=(
			const ListWzemMPreset& src
		) {
	WzemMPreset* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMPreset(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMPreset::operator==(
			const ListWzemMPreset& comp
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

bool ListWzemMPreset::operator!=(
			const ListWzemMPreset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMPreset
 ******************************************************************************/

TblWzemMPreset::TblWzemMPreset() {
};

TblWzemMPreset::~TblWzemMPreset() {
};

bool TblWzemMPreset::loadRecBySQL(
			const string& sqlstr
			, WzemMPreset** rec
		) {
	return false;
};

ubigint TblWzemMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPreset& rst
		) {
	return 0;
};

ubigint TblWzemMPreset::insertRec(
			WzemMPreset* rec
		) {
	return 0;
};

ubigint TblWzemMPreset::insertNewRec(
			WzemMPreset** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVPreset
			, const string arg
		) {
	ubigint retval = 0;
	WzemMPreset* _rec = NULL;

	_rec = new WzemMPreset(0, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMPreset::appendNewRecToRst(
			ListWzemMPreset& rst
			, WzemMPreset** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVPreset
			, const string arg
		) {
	ubigint retval = 0;
	WzemMPreset* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMPreset::insertRst(
			ListWzemMPreset& rst
			, bool transact
		) {
};

void TblWzemMPreset::updateRec(
			WzemMPreset* rec
		) {
};

void TblWzemMPreset::updateRst(
			ListWzemMPreset& rst
			, bool transact
		) {
};

void TblWzemMPreset::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMPreset::loadRecByRef(
			ubigint ref
			, WzemMPreset** rec
		) {
	return false;
};

ubigint TblWzemMPreset::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMPreset& rst
		) {
	return 0;
};

ubigint TblWzemMPreset::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMPreset& rst
		) {
	ubigint numload = 0;
	WzemMPreset* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMPreset
 ******************************************************************************/

MyTblWzemMPreset::MyTblWzemMPreset() :
			TblWzemMPreset()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMPreset::~MyTblWzemMPreset() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMPreset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMPreset (x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMPreset SET x1Startu = ?, x1Stopu = ?, refWzemMJob = ?, srefIxVPreset = ?, arg = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMPreset WHERE ref = ?", false);
};

bool MyTblWzemMPreset::loadRecBySQL(
			const string& sqlstr
			, WzemMPreset** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMPreset* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMPreset::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMPreset::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMPreset();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startu = atof((char*) dbrow[1]); else _rec->x1Startu = 0.0;
		if (dbrow[2]) _rec->x1Stopu = atof((char*) dbrow[2]); else _rec->x1Stopu = 0.0;
		if (dbrow[3]) _rec->refWzemMJob = atoll((char*) dbrow[3]); else _rec->refWzemMJob = 0;
		if (dbrow[4]) _rec->srefIxVPreset.assign(dbrow[4], dblengths[4]); else _rec->srefIxVPreset = "";
		if (dbrow[5]) _rec->arg.assign(dbrow[5], dblengths[5]); else _rec->arg = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPreset& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMPreset* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMPreset::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMPreset::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMPreset();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startu = atof((char*) dbrow[1]); else rec->x1Startu = 0.0;
			if (dbrow[2]) rec->x1Stopu = atof((char*) dbrow[2]); else rec->x1Stopu = 0.0;
			if (dbrow[3]) rec->refWzemMJob = atoll((char*) dbrow[3]); else rec->refWzemMJob = 0;
			if (dbrow[4]) rec->srefIxVPreset.assign(dbrow[4], dblengths[4]); else rec->srefIxVPreset = "";
			if (dbrow[5]) rec->arg.assign(dbrow[5], dblengths[5]); else rec->arg = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMPreset::insertRec(
			WzemMPreset* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->srefIxVPreset.length();
	l[4] = rec->arg.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefIxVPreset.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->arg.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMPreset::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMPreset::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMPreset::insertRst(
			ListWzemMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMPreset::updateRec(
			WzemMPreset* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->srefIxVPreset.length();
	l[4] = rec->arg.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefIxVPreset.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->arg.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMPreset::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMPreset::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMPreset::updateRst(
			ListWzemMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMPreset::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMPreset::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMPreset::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMPreset::loadRecByRef(
			ubigint ref
			, WzemMPreset** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMPreset WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemMPreset::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMPreset& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg FROM TblWzemMPreset WHERE refWzemMJob = " + to_string(refWzemMJob) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMPreset
 ******************************************************************************/

PgTblWzemMPreset::PgTblWzemMPreset() :
			TblWzemMPreset()
			, PgTable()
		{
};

PgTblWzemMPreset::~PgTblWzemMPreset() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMPreset::initStatements() {
	createStatement("TblWzemMPreset_insertRec", "INSERT INTO TblWzemMPreset (x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWzemMPreset_updateRec", "UPDATE TblWzemMPreset SET x1Startu = $1, x1Stopu = $2, refWzemMJob = $3, srefIxVPreset = $4, arg = $5 WHERE ref = $6", 6);
	createStatement("TblWzemMPreset_removeRecByRef", "DELETE FROM TblWzemMPreset WHERE ref = $1", 1);

	createStatement("TblWzemMPreset_loadRecByRef", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg FROM TblWzemMPreset WHERE ref = $1", 1);
	createStatement("TblWzemMPreset_loadRstByJob", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg FROM TblWzemMPreset WHERE refWzemMJob = $1", 1);
};

bool PgTblWzemMPreset::loadRec(
			PGresult* res
			, WzemMPreset** rec
		) {
	char* ptr;

	WzemMPreset* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMPreset();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvpreset"),
			PQfnumber(res, "arg")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefIxVPreset.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->arg.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMPreset::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMPreset& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMPreset* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvpreset"),
			PQfnumber(res, "arg")
		};

		while (numread < numrow) {
			rec = new WzemMPreset();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefIxVPreset.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->arg.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMPreset::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMPreset** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPreset::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMPreset::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMPreset& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPreset::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMPreset::loadRecBySQL(
			const string& sqlstr
			, WzemMPreset** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPreset::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPreset& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPreset::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMPreset::insertRec(
			WzemMPreset* rec
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
		rec->srefIxVPreset.c_str(),
		rec->arg.c_str()
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemMPreset_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPreset::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMPreset::insertRst(
			ListWzemMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMPreset::updateRec(
			WzemMPreset* rec
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
		rec->srefIxVPreset.c_str(),
		rec->arg.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemMPreset_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMPreset::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMPreset::updateRst(
			ListWzemMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMPreset::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMPreset_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMPreset::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMPreset::loadRecByRef(
			ubigint ref
			, WzemMPreset** rec
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

	return loadRecByStmt("TblWzemMPreset_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemMPreset::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMPreset& rst
		) {
	ubigint _refWzemMJob = htonl64(refWzemMJob);

	const char* vals[] = {
		(char*) &_refWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMPreset_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMPreset
 ******************************************************************************/

LiteTblWzemMPreset::LiteTblWzemMPreset() :
			TblWzemMPreset()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByJob = NULL;
};

LiteTblWzemMPreset::~LiteTblWzemMPreset() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByJob) sqlite3_finalize(stmtLoadRstByJob);
};

void LiteTblWzemMPreset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMPreset (x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMPreset SET x1Startu = ?1, x1Stopu = ?2, refWzemMJob = ?3, srefIxVPreset = ?4, arg = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMPreset WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg FROM TblWzemMPreset WHERE ref = ?1");
	stmtLoadRstByJob = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVPreset, arg FROM TblWzemMPreset WHERE refWzemMJob = ?1");
};

bool LiteTblWzemMPreset::loadRec(
			sqlite3_stmt* stmt
			, WzemMPreset** rec
		) {
	int res;

	WzemMPreset* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMPreset();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->x1Startu = sqlite3_column_double(stmt, 1);
		_rec->x1Stopu = sqlite3_column_double(stmt, 2);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		_rec->srefIxVPreset.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->arg.assign((const char*) sqlite3_column_text(stmt, 5));

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

ubigint LiteTblWzemMPreset::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMPreset& rst
		) {
	int res; ubigint numread = 0;

	WzemMPreset* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMPreset();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->x1Startu = sqlite3_column_double(stmt, 1);
		rec->x1Stopu = sqlite3_column_double(stmt, 2);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		rec->srefIxVPreset.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->arg.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMPreset::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMPreset** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMPreset::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMPreset& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMPreset::loadRecBySQL(
			const string& sqlstr
			, WzemMPreset** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMPreset::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPreset& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMPreset::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMPreset::insertRec(
			WzemMPreset* rec
		) {
	sqlite3_bind_double(stmtInsertRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMJob);
	sqlite3_bind_text(stmtInsertRec, 4, rec->srefIxVPreset.c_str(), rec->srefIxVPreset.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->arg.c_str(), rec->arg.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMPreset::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMPreset::insertRst(
			ListWzemMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMPreset::updateRec(
			WzemMPreset* rec
		) {
	sqlite3_bind_double(stmtUpdateRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMJob);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->srefIxVPreset.c_str(), rec->srefIxVPreset.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->arg.c_str(), rec->arg.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMPreset::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMPreset::updateRst(
			ListWzemMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMPreset::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMPreset::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMPreset::loadRecByRef(
			ubigint ref
			, WzemMPreset** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemMPreset::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMPreset& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJob, 1, refWzemMJob);

	return loadRstByStmt(stmtLoadRstByJob, append, rst);
};

#endif

