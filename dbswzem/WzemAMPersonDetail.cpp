/**
	* \file WzemAMPersonDetail.cpp
	* database access for table TblWzemAMPersonDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemAMPersonDetail.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAMPersonDetail
 ******************************************************************************/

WzemAMPersonDetail::WzemAMPersonDetail(
			const ubigint ref
			, const ubigint refWzemMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refWzemMPerson = refWzemMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool WzemAMPersonDetail::operator==(
			const WzemAMPersonDetail& comp
		) {
	return false;
};

bool WzemAMPersonDetail::operator!=(
			const WzemAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAMPersonDetail
 ******************************************************************************/

ListWzemAMPersonDetail::ListWzemAMPersonDetail() {
};

ListWzemAMPersonDetail::ListWzemAMPersonDetail(
			const ListWzemAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAMPersonDetail(*(src.nodes[i]));
};

ListWzemAMPersonDetail::~ListWzemAMPersonDetail() {
	clear();
};

void ListWzemAMPersonDetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAMPersonDetail::size() const {
	return(nodes.size());
};

void ListWzemAMPersonDetail::append(
			WzemAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

WzemAMPersonDetail* ListWzemAMPersonDetail::operator[](
			const uint ix
		) {
	WzemAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAMPersonDetail& ListWzemAMPersonDetail::operator=(
			const ListWzemAMPersonDetail& src
		) {
	WzemAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAMPersonDetail::operator==(
			const ListWzemAMPersonDetail& comp
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

bool ListWzemAMPersonDetail::operator!=(
			const ListWzemAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAMPersonDetail
 ******************************************************************************/

TblWzemAMPersonDetail::TblWzemAMPersonDetail() {
};

TblWzemAMPersonDetail::~TblWzemAMPersonDetail() {
};

bool TblWzemAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzemAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWzemAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWzemAMPersonDetail::insertRec(
			WzemAMPersonDetail* rec
		) {
	return 0;
};

ubigint TblWzemAMPersonDetail::insertNewRec(
			WzemAMPersonDetail** rec
			, const ubigint refWzemMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WzemAMPersonDetail* _rec = NULL;

	_rec = new WzemAMPersonDetail(0, refWzemMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAMPersonDetail::appendNewRecToRst(
			ListWzemAMPersonDetail& rst
			, WzemAMPersonDetail** rec
			, const ubigint refWzemMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WzemAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAMPersonDetail::insertRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
};

void TblWzemAMPersonDetail::updateRec(
			WzemAMPersonDetail* rec
		) {
};

void TblWzemAMPersonDetail::updateRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
};

void TblWzemAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzemAMPersonDetail** rec
		) {
	return false;
};

bool TblWzemAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzemMPerson
			, string x1SrefKType
			, WzemAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWzemAMPersonDetail::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWzemAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	ubigint numload = 0;
	WzemAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAMPersonDetail
 ******************************************************************************/

MyTblWzemAMPersonDetail::MyTblWzemAMPersonDetail() :
			TblWzemAMPersonDetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAMPersonDetail::~MyTblWzemAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAMPersonDetail (refWzemMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAMPersonDetail SET refWzemMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAMPersonDetail WHERE ref = ?", false);
};

bool MyTblWzemAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzemAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAMPersonDetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAMPersonDetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMPerson = atoll((char*) dbrow[1]); else _rec->refWzemMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAMPersonDetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAMPersonDetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMPerson = atoll((char*) dbrow[1]); else rec->refWzemMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemAMPersonDetail::insertRec(
			WzemAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAMPersonDetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAMPersonDetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAMPersonDetail::insertRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAMPersonDetail::updateRec(
			WzemAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAMPersonDetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAMPersonDetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAMPersonDetail::updateRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAMPersonDetail::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAMPersonDetail::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzemAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzemMPerson
			, string x1SrefKType
			, WzemAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE refWzemMPerson = " + to_string(refWzemMPerson) + " AND x1SrefKType = '" + x1SrefKType + "'", rec);
};

ubigint MyTblWzemAMPersonDetail::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE refWzemMPerson = " + to_string(refWzemMPerson) + " ORDER BY x1SrefKType ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAMPersonDetail
 ******************************************************************************/

PgTblWzemAMPersonDetail::PgTblWzemAMPersonDetail() :
			TblWzemAMPersonDetail()
			, PgTable()
		{
};

PgTblWzemAMPersonDetail::~PgTblWzemAMPersonDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAMPersonDetail::initStatements() {
	createStatement("TblWzemAMPersonDetail_insertRec", "INSERT INTO TblWzemAMPersonDetail (refWzemMPerson, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWzemAMPersonDetail_updateRec", "UPDATE TblWzemAMPersonDetail SET refWzemMPerson = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWzemAMPersonDetail_removeRecByRef", "DELETE FROM TblWzemAMPersonDetail WHERE ref = $1", 1);

	createStatement("TblWzemAMPersonDetail_loadRecByRef", "SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE ref = $1", 1);
	createStatement("TblWzemAMPersonDetail_loadRecByPrsTyp", "SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE refWzemMPerson = $1 AND x1SrefKType = $2", 2);
	createStatement("TblWzemAMPersonDetail_loadRstByPrs", "SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE refWzemMPerson = $1 ORDER BY x1SrefKType ASC", 1);
};

bool PgTblWzemAMPersonDetail::loadRec(
			PGresult* res
			, WzemAMPersonDetail** rec
		) {
	char* ptr;

	WzemAMPersonDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAMPersonDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAMPersonDetail::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAMPersonDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WzemAMPersonDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemAMPersonDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMPersonDetail::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAMPersonDetail::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMPersonDetail::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzemAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMPersonDetail::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMPersonDetail::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAMPersonDetail::insertRec(
			WzemAMPersonDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemAMPersonDetail_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMPersonDetail::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAMPersonDetail::insertRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAMPersonDetail::updateRec(
			WzemAMPersonDetail* rec
		) {
	PGresult* res;

	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemAMPersonDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAMPersonDetail::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAMPersonDetail::updateRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAMPersonDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemAMPersonDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAMPersonDetail::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzemAMPersonDetail** rec
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

	return loadRecByStmt("TblWzemAMPersonDetail_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzemMPerson
			, string x1SrefKType
			, WzemAMPersonDetail** rec
		) {
	ubigint _refWzemMPerson = htonl64(refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson,
		x1SrefKType.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRecByStmt("TblWzemAMPersonDetail_loadRecByPrsTyp", 2, vals, l, f, rec);
};

ubigint PgTblWzemAMPersonDetail::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	ubigint _refWzemMPerson = htonl64(refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemAMPersonDetail_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAMPersonDetail
 ******************************************************************************/

LiteTblWzemAMPersonDetail::LiteTblWzemAMPersonDetail() :
			TblWzemAMPersonDetail()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrsTyp = NULL;
	stmtLoadRstByPrs = NULL;
};

LiteTblWzemAMPersonDetail::~LiteTblWzemAMPersonDetail() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrsTyp) sqlite3_finalize(stmtLoadRecByPrsTyp);
	if (stmtLoadRstByPrs) sqlite3_finalize(stmtLoadRstByPrs);
};

void LiteTblWzemAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAMPersonDetail (refWzemMPerson, x1SrefKType, Val) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAMPersonDetail SET refWzemMPerson = ?1, x1SrefKType = ?2, Val = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAMPersonDetail WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE ref = ?1");
	stmtLoadRecByPrsTyp = createStatement("SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE refWzemMPerson = ?1 AND x1SrefKType = ?2");
	stmtLoadRstByPrs = createStatement("SELECT ref, refWzemMPerson, x1SrefKType, Val FROM TblWzemAMPersonDetail WHERE refWzemMPerson = ?1 ORDER BY x1SrefKType ASC");
};

bool LiteTblWzemAMPersonDetail::loadRec(
			sqlite3_stmt* stmt
			, WzemAMPersonDetail** rec
		) {
	int res;

	WzemAMPersonDetail* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAMPersonDetail();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMPerson = sqlite3_column_int64(stmt, 1);
		_rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 2));
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblWzemAMPersonDetail::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	int res; ubigint numread = 0;

	WzemAMPersonDetail* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAMPersonDetail();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMPerson = sqlite3_column_int64(stmt, 1);
		rec->x1SrefKType.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAMPersonDetail::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAMPersonDetail** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemAMPersonDetail::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WzemAMPersonDetail** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAMPersonDetail::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAMPersonDetail::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAMPersonDetail::insertRec(
			WzemAMPersonDetail* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMPerson);
	sqlite3_bind_text(stmtInsertRec, 2, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMPersonDetail::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAMPersonDetail::insertRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAMPersonDetail::updateRec(
			WzemAMPersonDetail* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMPerson);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->x1SrefKType.c_str(), rec->x1SrefKType.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMPersonDetail::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAMPersonDetail::updateRst(
			ListWzemAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMPersonDetail::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAMPersonDetail::loadRecByRef(
			ubigint ref
			, WzemAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemAMPersonDetail::loadRecByPrsTyp(
			ubigint refWzemMPerson
			, string x1SrefKType
			, WzemAMPersonDetail** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrsTyp, 1, refWzemMPerson);
	sqlite3_bind_text(stmtLoadRecByPrsTyp, 2, x1SrefKType.c_str(), x1SrefKType.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecByPrsTyp, rec);
};

ubigint LiteTblWzemAMPersonDetail::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemAMPersonDetail& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrs, 1, refWzemMPerson);

	return loadRstByStmt(stmtLoadRstByPrs, append, rst);
};

#endif

