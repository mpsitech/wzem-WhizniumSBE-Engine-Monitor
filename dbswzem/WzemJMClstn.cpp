/**
	* \file WzemJMClstn.cpp
	* database access for table TblWzemJMClstn (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemJMClstn.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMClstn
 ******************************************************************************/

WzemJMClstn::WzemJMClstn(
			const ubigint ref
			, const ubigint refWzemMClstn
			, const double x1Startu
			, const double x1Stopu
			, const string argMask
			, const uint ixVJactype
		) {

	this->ref = ref;
	this->refWzemMClstn = refWzemMClstn;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->argMask = argMask;
	this->ixVJactype = ixVJactype;
};

bool WzemJMClstn::operator==(
			const WzemJMClstn& comp
		) {
	return false;
};

bool WzemJMClstn::operator!=(
			const WzemJMClstn& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMClstn
 ******************************************************************************/

ListWzemJMClstn::ListWzemJMClstn() {
};

ListWzemJMClstn::ListWzemJMClstn(
			const ListWzemJMClstn& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMClstn(*(src.nodes[i]));
};

ListWzemJMClstn::~ListWzemJMClstn() {
	clear();
};

void ListWzemJMClstn::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMClstn::size() const {
	return(nodes.size());
};

void ListWzemJMClstn::append(
			WzemJMClstn* rec
		) {
	nodes.push_back(rec);
};

WzemJMClstn* ListWzemJMClstn::operator[](
			const uint ix
		) {
	WzemJMClstn* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMClstn& ListWzemJMClstn::operator=(
			const ListWzemJMClstn& src
		) {
	WzemJMClstn* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMClstn(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMClstn::operator==(
			const ListWzemJMClstn& comp
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

bool ListWzemJMClstn::operator!=(
			const ListWzemJMClstn& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMClstn
 ******************************************************************************/

TblWzemJMClstn::TblWzemJMClstn() {
};

TblWzemJMClstn::~TblWzemJMClstn() {
};

bool TblWzemJMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemJMClstn** rec
		) {
	return false;
};

ubigint TblWzemJMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMClstn& rst
		) {
	return 0;
};

ubigint TblWzemJMClstn::insertRec(
			WzemJMClstn* rec
		) {
	return 0;
};

ubigint TblWzemJMClstn::insertNewRec(
			WzemJMClstn** rec
			, const ubigint refWzemMClstn
			, const double x1Startu
			, const double x1Stopu
			, const string argMask
			, const uint ixVJactype
		) {
	ubigint retval = 0;
	WzemJMClstn* _rec = NULL;

	_rec = new WzemJMClstn(0, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMClstn::appendNewRecToRst(
			ListWzemJMClstn& rst
			, WzemJMClstn** rec
			, const ubigint refWzemMClstn
			, const double x1Startu
			, const double x1Stopu
			, const string argMask
			, const uint ixVJactype
		) {
	ubigint retval = 0;
	WzemJMClstn* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMClstn::insertRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
};

void TblWzemJMClstn::updateRec(
			WzemJMClstn* rec
		) {
};

void TblWzemJMClstn::updateRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
};

void TblWzemJMClstn::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMClstn::loadRecByRef(
			ubigint ref
			, WzemJMClstn** rec
		) {
	return false;
};

ubigint TblWzemJMClstn::loadRstByCln(
			ubigint refWzemMClstn
			, const bool append
			, ListWzemJMClstn& rst
		) {
	return 0;
};

ubigint TblWzemJMClstn::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMClstn& rst
		) {
	ubigint numload = 0;
	WzemJMClstn* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMClstn
 ******************************************************************************/

MyTblWzemJMClstn::MyTblWzemJMClstn() :
			TblWzemJMClstn()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMClstn::~MyTblWzemJMClstn() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMClstn::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMClstn (refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMClstn SET refWzemMClstn = ?, x1Startu = ?, x1Stopu = ?, argMask = ?, ixVJactype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMClstn WHERE ref = ?", false);
};

bool MyTblWzemJMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemJMClstn** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMClstn* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMClstn::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMClstn::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemJMClstn();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMClstn = atoll((char*) dbrow[1]); else _rec->refWzemMClstn = 0;
		if (dbrow[2]) _rec->x1Startu = atof((char*) dbrow[2]); else _rec->x1Startu = 0.0;
		if (dbrow[3]) _rec->x1Stopu = atof((char*) dbrow[3]); else _rec->x1Stopu = 0.0;
		if (dbrow[4]) _rec->argMask.assign(dbrow[4], dblengths[4]); else _rec->argMask = "";
		if (dbrow[5]) _rec->ixVJactype = atol((char*) dbrow[5]); else _rec->ixVJactype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMClstn& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMClstn* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMClstn::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMClstn::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemJMClstn();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMClstn = atoll((char*) dbrow[1]); else rec->refWzemMClstn = 0;
			if (dbrow[2]) rec->x1Startu = atof((char*) dbrow[2]); else rec->x1Startu = 0.0;
			if (dbrow[3]) rec->x1Stopu = atof((char*) dbrow[3]); else rec->x1Stopu = 0.0;
			if (dbrow[4]) rec->argMask.assign(dbrow[4], dblengths[4]); else rec->argMask = "";
			if (dbrow[5]) rec->ixVJactype = atol((char*) dbrow[5]); else rec->ixVJactype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMClstn::insertRec(
			WzemJMClstn* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->argMask.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMClstn,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->argMask.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVJactype,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMClstn::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMClstn::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMClstn::insertRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMClstn::updateRec(
			WzemJMClstn* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->argMask.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMClstn,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->argMask.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVJactype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMClstn::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMClstn::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMClstn::updateRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMClstn::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMClstn::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMClstn::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMClstn::loadRecByRef(
			ubigint ref
			, WzemJMClstn** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMClstn WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemJMClstn::loadRstByCln(
			ubigint refWzemMClstn
			, const bool append
			, ListWzemJMClstn& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype FROM TblWzemJMClstn WHERE refWzemMClstn = " + to_string(refWzemMClstn) + " ORDER BY x1Startu ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMClstn
 ******************************************************************************/

PgTblWzemJMClstn::PgTblWzemJMClstn() :
			TblWzemJMClstn()
			, PgTable()
		{
};

PgTblWzemJMClstn::~PgTblWzemJMClstn() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMClstn::initStatements() {
	createStatement("TblWzemJMClstn_insertRec", "INSERT INTO TblWzemJMClstn (refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWzemJMClstn_updateRec", "UPDATE TblWzemJMClstn SET refWzemMClstn = $1, x1Startu = $2, x1Stopu = $3, argMask = $4, ixVJactype = $5 WHERE ref = $6", 6);
	createStatement("TblWzemJMClstn_removeRecByRef", "DELETE FROM TblWzemJMClstn WHERE ref = $1", 1);

	createStatement("TblWzemJMClstn_loadRecByRef", "SELECT ref, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype FROM TblWzemJMClstn WHERE ref = $1", 1);
	createStatement("TblWzemJMClstn_loadRstByCln", "SELECT ref, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype FROM TblWzemJMClstn WHERE refWzemMClstn = $1 ORDER BY x1Startu ASC", 1);
};

bool PgTblWzemJMClstn::loadRec(
			PGresult* res
			, WzemJMClstn** rec
		) {
	char* ptr;

	WzemJMClstn* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMClstn();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmclstn"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "argmask"),
			PQfnumber(res, "ixvjactype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMClstn = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->argMask.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVJactype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMClstn::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMClstn& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMClstn* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmclstn"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "argmask"),
			PQfnumber(res, "ixvjactype")
		};

		while (numread < numrow) {
			rec = new WzemJMClstn();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMClstn = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->argMask.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVJactype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMClstn::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMClstn** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMClstn::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMClstn::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMClstn& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMClstn::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemJMClstn** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMClstn::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMClstn& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMClstn::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMClstn::insertRec(
			WzemJMClstn* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMClstn = htonl64(rec->refWzemMClstn);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	uint _ixVJactype = htonl(rec->ixVJactype);

	const char* vals[] = {
		(char*) &_refWzemMClstn,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		rec->argMask.c_str(),
		(char*) &_ixVJactype
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint)
	};
	const int f[] = {1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemJMClstn_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMClstn::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMClstn::insertRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMClstn::updateRec(
			WzemJMClstn* rec
		) {
	PGresult* res;

	ubigint _refWzemMClstn = htonl64(rec->refWzemMClstn);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	uint _ixVJactype = htonl(rec->ixVJactype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMClstn,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		rec->argMask.c_str(),
		(char*) &_ixVJactype,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemJMClstn_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMClstn::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMClstn::updateRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMClstn::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMClstn_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMClstn::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMClstn::loadRecByRef(
			ubigint ref
			, WzemJMClstn** rec
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

	return loadRecByStmt("TblWzemJMClstn_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemJMClstn::loadRstByCln(
			ubigint refWzemMClstn
			, const bool append
			, ListWzemJMClstn& rst
		) {
	ubigint _refWzemMClstn = htonl64(refWzemMClstn);

	const char* vals[] = {
		(char*) &_refWzemMClstn
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMClstn_loadRstByCln", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMClstn
 ******************************************************************************/

LiteTblWzemJMClstn::LiteTblWzemJMClstn() :
			TblWzemJMClstn()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByCln = NULL;
};

LiteTblWzemJMClstn::~LiteTblWzemJMClstn() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByCln) sqlite3_finalize(stmtLoadRstByCln);
};

void LiteTblWzemJMClstn::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMClstn (refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMClstn SET refWzemMClstn = ?1, x1Startu = ?2, x1Stopu = ?3, argMask = ?4, ixVJactype = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMClstn WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype FROM TblWzemJMClstn WHERE ref = ?1");
	stmtLoadRstByCln = createStatement("SELECT ref, refWzemMClstn, x1Startu, x1Stopu, argMask, ixVJactype FROM TblWzemJMClstn WHERE refWzemMClstn = ?1 ORDER BY x1Startu ASC");
};

bool LiteTblWzemJMClstn::loadRec(
			sqlite3_stmt* stmt
			, WzemJMClstn** rec
		) {
	int res;

	WzemJMClstn* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMClstn();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMClstn = sqlite3_column_int64(stmt, 1);
		_rec->x1Startu = sqlite3_column_double(stmt, 2);
		_rec->x1Stopu = sqlite3_column_double(stmt, 3);
		_rec->argMask.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->ixVJactype = sqlite3_column_int(stmt, 5);

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

ubigint LiteTblWzemJMClstn::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMClstn& rst
		) {
	int res; ubigint numread = 0;

	WzemJMClstn* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMClstn();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMClstn = sqlite3_column_int64(stmt, 1);
		rec->x1Startu = sqlite3_column_double(stmt, 2);
		rec->x1Stopu = sqlite3_column_double(stmt, 3);
		rec->argMask.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->ixVJactype = sqlite3_column_int(stmt, 5);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMClstn::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMClstn** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMClstn::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMClstn& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemJMClstn** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMClstn::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMClstn& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMClstn::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMClstn::insertRec(
			WzemJMClstn* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMClstn);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 3, rec->x1Stopu);
	sqlite3_bind_text(stmtInsertRec, 4, rec->argMask.c_str(), rec->argMask.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixVJactype);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMClstn::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMClstn::insertRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMClstn::updateRec(
			WzemJMClstn* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMClstn);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 3, rec->x1Stopu);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->argMask.c_str(), rec->argMask.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixVJactype);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMClstn::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMClstn::updateRst(
			ListWzemJMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMClstn::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMClstn::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMClstn::loadRecByRef(
			ubigint ref
			, WzemJMClstn** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemJMClstn::loadRstByCln(
			ubigint refWzemMClstn
			, const bool append
			, ListWzemJMClstn& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByCln, 1, refWzemMClstn);

	return loadRstByStmt(stmtLoadRstByCln, append, rst);
};

#endif
