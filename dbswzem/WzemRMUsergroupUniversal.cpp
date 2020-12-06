/**
	* \file WzemRMUsergroupUniversal.cpp
	* database access for table TblWzemRMUsergroupUniversal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemRMUsergroupUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemRMUsergroupUniversal
 ******************************************************************************/

WzemRMUsergroupUniversal::WzemRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refWzemMUsergroup
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVRecaccess
		) {

	this->ref = ref;
	this->refWzemMUsergroup = refWzemMUsergroup;
	this->unvIxWzemVMaintable = unvIxWzemVMaintable;
	this->unvUref = unvUref;
	this->ixWzemVRecaccess = ixWzemVRecaccess;
};

bool WzemRMUsergroupUniversal::operator==(
			const WzemRMUsergroupUniversal& comp
		) {
	return false;
};

bool WzemRMUsergroupUniversal::operator!=(
			const WzemRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemRMUsergroupUniversal
 ******************************************************************************/

ListWzemRMUsergroupUniversal::ListWzemRMUsergroupUniversal() {
};

ListWzemRMUsergroupUniversal::ListWzemRMUsergroupUniversal(
			const ListWzemRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemRMUsergroupUniversal(*(src.nodes[i]));
};

ListWzemRMUsergroupUniversal::~ListWzemRMUsergroupUniversal() {
	clear();
};

void ListWzemRMUsergroupUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListWzemRMUsergroupUniversal::append(
			WzemRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

WzemRMUsergroupUniversal* ListWzemRMUsergroupUniversal::operator[](
			const uint ix
		) {
	WzemRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemRMUsergroupUniversal& ListWzemRMUsergroupUniversal::operator=(
			const ListWzemRMUsergroupUniversal& src
		) {
	WzemRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemRMUsergroupUniversal::operator==(
			const ListWzemRMUsergroupUniversal& comp
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

bool ListWzemRMUsergroupUniversal::operator!=(
			const ListWzemRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemRMUsergroupUniversal
 ******************************************************************************/

TblWzemRMUsergroupUniversal::TblWzemRMUsergroupUniversal() {
};

TblWzemRMUsergroupUniversal::~TblWzemRMUsergroupUniversal() {
};

bool TblWzemRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWzemRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	return 0;
};

ubigint TblWzemRMUsergroupUniversal::insertRec(
			WzemRMUsergroupUniversal* rec
		) {
	return 0;
};

ubigint TblWzemRMUsergroupUniversal::insertNewRec(
			WzemRMUsergroupUniversal** rec
			, const ubigint refWzemMUsergroup
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVRecaccess
		) {
	ubigint retval = 0;
	WzemRMUsergroupUniversal* _rec = NULL;

	_rec = new WzemRMUsergroupUniversal(0, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemRMUsergroupUniversal::appendNewRecToRst(
			ListWzemRMUsergroupUniversal& rst
			, WzemRMUsergroupUniversal** rec
			, const ubigint refWzemMUsergroup
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVRecaccess
		) {
	ubigint retval = 0;
	WzemRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemRMUsergroupUniversal::insertRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWzemRMUsergroupUniversal::updateRec(
			WzemRMUsergroupUniversal* rec
		) {
};

void TblWzemRMUsergroupUniversal::updateRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWzemRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzemRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblWzemRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzemMUsergroup
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWzemRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	WzemRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemRMUsergroupUniversal
 ******************************************************************************/

MyTblWzemRMUsergroupUniversal::MyTblWzemRMUsergroupUniversal() :
			TblWzemRMUsergroupUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemRMUsergroupUniversal::~MyTblWzemRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemRMUsergroupUniversal (refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemRMUsergroupUniversal SET refWzemMUsergroup = ?, unvIxWzemVMaintable = ?, unvUref = ?, ixWzemVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblWzemRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemRMUsergroupUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemRMUsergroupUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUsergroup = atoll((char*) dbrow[1]); else _rec->refWzemMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxWzemVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWzemVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWzemVRecaccess = atol((char*) dbrow[4]); else _rec->ixWzemVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemRMUsergroupUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemRMUsergroupUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUsergroup = atoll((char*) dbrow[1]); else rec->refWzemMUsergroup = 0;
			if (dbrow[2]) rec->unvIxWzemVMaintable = atol((char*) dbrow[2]); else rec->unvIxWzemVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWzemVRecaccess = atol((char*) dbrow[4]); else rec->ixWzemVRecaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemRMUsergroupUniversal::insertRec(
			WzemRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzemVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemRMUsergroupUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemRMUsergroupUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemRMUsergroupUniversal::insertRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemRMUsergroupUniversal::updateRec(
			WzemRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzemVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemRMUsergroupUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemRMUsergroupUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemRMUsergroupUniversal::updateRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemRMUsergroupUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemRMUsergroupUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzemRMUsergroupUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzemMUsergroup
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemRMUsergroupUniversal WHERE refWzemMUsergroup = " + to_string(refWzemMUsergroup) + " AND unvIxWzemVMaintable = " + to_string(unvIxWzemVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemRMUsergroupUniversal
 ******************************************************************************/

PgTblWzemRMUsergroupUniversal::PgTblWzemRMUsergroupUniversal() :
			TblWzemRMUsergroupUniversal()
			, PgTable()
		{
};

PgTblWzemRMUsergroupUniversal::~PgTblWzemRMUsergroupUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemRMUsergroupUniversal::initStatements() {
	createStatement("TblWzemRMUsergroupUniversal_insertRec", "INSERT INTO TblWzemRMUsergroupUniversal (refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemRMUsergroupUniversal_updateRec", "UPDATE TblWzemRMUsergroupUniversal SET refWzemMUsergroup = $1, unvIxWzemVMaintable = $2, unvUref = $3, ixWzemVRecaccess = $4 WHERE ref = $5", 5);
	createStatement("TblWzemRMUsergroupUniversal_removeRecByRef", "DELETE FROM TblWzemRMUsergroupUniversal WHERE ref = $1", 1);

	createStatement("TblWzemRMUsergroupUniversal_loadRecByRef", "SELECT ref, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemRMUsergroupUniversal WHERE ref = $1", 1);
	createStatement("TblWzemRMUsergroupUniversal_loadRecByUsgMtbUnv", "SELECT ref, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemRMUsergroupUniversal WHERE refWzemMUsergroup = $1 AND unvIxWzemVMaintable = $2 AND unvUref = $3", 3);
};

bool PgTblWzemRMUsergroupUniversal::loadRec(
			PGresult* res
			, WzemRMUsergroupUniversal** rec
		) {
	char* ptr;

	WzemRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemRMUsergroupUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "unvixwzemvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwzemvrecaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWzemVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWzemVRecaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemRMUsergroupUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "unvixwzemvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwzemvrecaccess")
		};

		while (numread < numrow) {
			rec = new WzemRMUsergroupUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWzemVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWzemVRecaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemRMUsergroupUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUsergroupUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWzemRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUsergroupUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUsergroupUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemRMUsergroupUniversal::insertRec(
			WzemRMUsergroupUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _unvIxWzemVMaintable = htonl(rec->unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWzemVRecaccess = htonl(rec->ixWzemVRecaccess);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWzemVRecaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemRMUsergroupUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUsergroupUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemRMUsergroupUniversal::insertRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemRMUsergroupUniversal::updateRec(
			WzemRMUsergroupUniversal* rec
		) {
	PGresult* res;

	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _unvIxWzemVMaintable = htonl(rec->unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWzemVRecaccess = htonl(rec->ixWzemVRecaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWzemVRecaccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemRMUsergroupUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemRMUsergroupUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemRMUsergroupUniversal::updateRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemRMUsergroupUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemRMUsergroupUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemRMUsergroupUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzemRMUsergroupUniversal** rec
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

	return loadRecByStmt("TblWzemRMUsergroupUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzemMUsergroup
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemRMUsergroupUniversal** rec
		) {
	ubigint _refWzemMUsergroup = htonl64(refWzemMUsergroup);
	uint _unvIxWzemVMaintable = htonl(unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblWzemRMUsergroupUniversal_loadRecByUsgMtbUnv", 3, vals, l, f, rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemRMUsergroupUniversal
 ******************************************************************************/

LiteTblWzemRMUsergroupUniversal::LiteTblWzemRMUsergroupUniversal() :
			TblWzemRMUsergroupUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsgMtbUnv = NULL;
};

LiteTblWzemRMUsergroupUniversal::~LiteTblWzemRMUsergroupUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsgMtbUnv) sqlite3_finalize(stmtLoadRecByUsgMtbUnv);
};

void LiteTblWzemRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemRMUsergroupUniversal (refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemRMUsergroupUniversal SET refWzemMUsergroup = ?1, unvIxWzemVMaintable = ?2, unvUref = ?3, ixWzemVRecaccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemRMUsergroupUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemRMUsergroupUniversal WHERE ref = ?1");
	stmtLoadRecByUsgMtbUnv = createStatement("SELECT ref, refWzemMUsergroup, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemRMUsergroupUniversal WHERE refWzemMUsergroup = ?1 AND unvIxWzemVMaintable = ?2 AND unvUref = ?3");
};

bool LiteTblWzemRMUsergroupUniversal::loadRec(
			sqlite3_stmt* stmt
			, WzemRMUsergroupUniversal** rec
		) {
	int res;

	WzemRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemRMUsergroupUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 1);
		_rec->unvIxWzemVMaintable = sqlite3_column_int(stmt, 2);
		_rec->unvUref = sqlite3_column_int64(stmt, 3);
		_rec->ixWzemVRecaccess = sqlite3_column_int(stmt, 4);

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

ubigint LiteTblWzemRMUsergroupUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	int res; ubigint numread = 0;

	WzemRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemRMUsergroupUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 1);
		rec->unvIxWzemVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixWzemVRecaccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemRMUsergroupUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemRMUsergroupUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemRMUsergroupUniversal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemRMUsergroupUniversal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUsergroupUniversal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemRMUsergroupUniversal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemRMUsergroupUniversal::insertRec(
			WzemRMUsergroupUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzemVRecaccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemRMUsergroupUniversal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemRMUsergroupUniversal::insertRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemRMUsergroupUniversal::updateRec(
			WzemRMUsergroupUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzemVRecaccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemRMUsergroupUniversal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemRMUsergroupUniversal::updateRst(
			ListWzemRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemRMUsergroupUniversal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WzemRMUsergroupUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWzemMUsergroup
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemRMUsergroupUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsgMtbUnv, 1, refWzemMUsergroup);
	sqlite3_bind_int(stmtLoadRecByUsgMtbUnv, 2, unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsgMtbUnv, 3, unvUref);

	return loadRecByStmt(stmtLoadRecByUsgMtbUnv, rec);
};

#endif
