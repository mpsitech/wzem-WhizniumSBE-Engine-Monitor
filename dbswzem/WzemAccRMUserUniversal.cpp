/**
	* \file WzemAccRMUserUniversal.cpp
	* database access for table TblWzemAccRMUserUniversal (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemAccRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAccRMUserUniversal
 ******************************************************************************/

WzemAccRMUserUniversal::WzemAccRMUserUniversal(
			const ubigint ref
			, const ubigint refWzemMUser
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVRecaccess
		) {

	this->ref = ref;
	this->refWzemMUser = refWzemMUser;
	this->unvIxWzemVMaintable = unvIxWzemVMaintable;
	this->unvUref = unvUref;
	this->ixWzemVRecaccess = ixWzemVRecaccess;
};

bool WzemAccRMUserUniversal::operator==(
			const WzemAccRMUserUniversal& comp
		) {
	return false;
};

bool WzemAccRMUserUniversal::operator!=(
			const WzemAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAccRMUserUniversal
 ******************************************************************************/

ListWzemAccRMUserUniversal::ListWzemAccRMUserUniversal() {
};

ListWzemAccRMUserUniversal::ListWzemAccRMUserUniversal(
			const ListWzemAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAccRMUserUniversal(*(src.nodes[i]));
};

ListWzemAccRMUserUniversal::~ListWzemAccRMUserUniversal() {
	clear();
};

void ListWzemAccRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWzemAccRMUserUniversal::append(
			WzemAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WzemAccRMUserUniversal* ListWzemAccRMUserUniversal::operator[](
			const uint ix
		) {
	WzemAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAccRMUserUniversal& ListWzemAccRMUserUniversal::operator=(
			const ListWzemAccRMUserUniversal& src
		) {
	WzemAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAccRMUserUniversal::operator==(
			const ListWzemAccRMUserUniversal& comp
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

bool ListWzemAccRMUserUniversal::operator!=(
			const ListWzemAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAccRMUserUniversal
 ******************************************************************************/

TblWzemAccRMUserUniversal::TblWzemAccRMUserUniversal() {
};

TblWzemAccRMUserUniversal::~TblWzemAccRMUserUniversal() {
};

bool TblWzemAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzemAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWzemAccRMUserUniversal::insertRec(
			WzemAccRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWzemAccRMUserUniversal::insertNewRec(
			WzemAccRMUserUniversal** rec
			, const ubigint refWzemMUser
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVRecaccess
		) {
	ubigint retval = 0;
	WzemAccRMUserUniversal* _rec = NULL;

	_rec = new WzemAccRMUserUniversal(0, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAccRMUserUniversal::appendNewRecToRst(
			ListWzemAccRMUserUniversal& rst
			, WzemAccRMUserUniversal** rec
			, const ubigint refWzemMUser
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVRecaccess
		) {
	ubigint retval = 0;
	WzemAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAccRMUserUniversal::insertRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzemAccRMUserUniversal::updateRec(
			WzemAccRMUserUniversal* rec
		) {
};

void TblWzemAccRMUserUniversal::updateRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzemAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemAccRMUserUniversal** rec
		) {
	return false;
};

bool TblWzemAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzemAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WzemAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAccRMUserUniversal
 ******************************************************************************/

MyTblWzemAccRMUserUniversal::MyTblWzemAccRMUserUniversal() :
			TblWzemAccRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAccRMUserUniversal::~MyTblWzemAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAccRMUserUniversal (refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAccRMUserUniversal SET refWzemMUser = ?, unvIxWzemVMaintable = ?, unvUref = ?, ixWzemVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWzemAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAccRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAccRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUser = atoll((char*) dbrow[1]); else _rec->refWzemMUser = 0;
		if (dbrow[2]) _rec->unvIxWzemVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWzemVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWzemVRecaccess = atol((char*) dbrow[4]); else _rec->ixWzemVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAccRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAccRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUser = atoll((char*) dbrow[1]); else rec->refWzemMUser = 0;
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

ubigint MyTblWzemAccRMUserUniversal::insertRec(
			WzemAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzemVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAccRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAccRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAccRMUserUniversal::insertRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAccRMUserUniversal::updateRec(
			WzemAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzemVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAccRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAccRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAccRMUserUniversal::updateRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAccRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAccRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemAccRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemAccRMUserUniversal WHERE refWzemMUser = " + to_string(refWzemMUser) + " AND unvIxWzemVMaintable = " + to_string(unvIxWzemVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAccRMUserUniversal
 ******************************************************************************/

PgTblWzemAccRMUserUniversal::PgTblWzemAccRMUserUniversal() :
			TblWzemAccRMUserUniversal()
			, PgTable()
		{
};

PgTblWzemAccRMUserUniversal::~PgTblWzemAccRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAccRMUserUniversal::initStatements() {
	createStatement("TblWzemAccRMUserUniversal_insertRec", "INSERT INTO TblWzemAccRMUserUniversal (refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemAccRMUserUniversal_updateRec", "UPDATE TblWzemAccRMUserUniversal SET refWzemMUser = $1, unvIxWzemVMaintable = $2, unvUref = $3, ixWzemVRecaccess = $4 WHERE ref = $5", 5);
	createStatement("TblWzemAccRMUserUniversal_removeRecByRef", "DELETE FROM TblWzemAccRMUserUniversal WHERE ref = $1", 1);

	createStatement("TblWzemAccRMUserUniversal_loadRecByRef", "SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemAccRMUserUniversal WHERE ref = $1", 1);
	createStatement("TblWzemAccRMUserUniversal_loadRecByUsrMtbUnv", "SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemAccRMUserUniversal WHERE refWzemMUser = $1 AND unvIxWzemVMaintable = $2 AND unvUref = $3", 3);
};

bool PgTblWzemAccRMUserUniversal::loadRec(
			PGresult* res
			, WzemAccRMUserUniversal** rec
		) {
	char* ptr;

	WzemAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAccRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "unvixwzemvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwzemvrecaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWzemVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWzemVRecaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAccRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAccRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "unvixwzemvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwzemvrecaccess")
		};

		while (numread < numrow) {
			rec = new WzemAccRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUser = atoll(ptr);
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

bool PgTblWzemAccRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAccRMUserUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWzemAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAccRMUserUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAccRMUserUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAccRMUserUniversal::insertRec(
			WzemAccRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(rec->unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWzemVRecaccess = htonl(rec->ixWzemVRecaccess);

	const char* vals[] = {
		(char*) &_refWzemMUser,
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

	res = PQexecPrepared(dbs, "TblWzemAccRMUserUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAccRMUserUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAccRMUserUniversal::insertRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAccRMUserUniversal::updateRec(
			WzemAccRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(rec->unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWzemVRecaccess = htonl(rec->ixWzemVRecaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
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

	res = PQexecPrepared(dbs, "TblWzemAccRMUserUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAccRMUserUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAccRMUserUniversal::updateRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAccRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemAccRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAccRMUserUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemAccRMUserUniversal** rec
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

	return loadRecByStmt("TblWzemAccRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemAccRMUserUniversal** rec
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblWzemAccRMUserUniversal_loadRecByUsrMtbUnv", 3, vals, l, f, rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAccRMUserUniversal
 ******************************************************************************/

LiteTblWzemAccRMUserUniversal::LiteTblWzemAccRMUserUniversal() :
			TblWzemAccRMUserUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrMtbUnv = NULL;
};

LiteTblWzemAccRMUserUniversal::~LiteTblWzemAccRMUserUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrMtbUnv) sqlite3_finalize(stmtLoadRecByUsrMtbUnv);
};

void LiteTblWzemAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAccRMUserUniversal (refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAccRMUserUniversal SET refWzemMUser = ?1, unvIxWzemVMaintable = ?2, unvUref = ?3, ixWzemVRecaccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAccRMUserUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemAccRMUserUniversal WHERE ref = ?1");
	stmtLoadRecByUsrMtbUnv = createStatement("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVRecaccess FROM TblWzemAccRMUserUniversal WHERE refWzemMUser = ?1 AND unvIxWzemVMaintable = ?2 AND unvUref = ?3");
};

bool LiteTblWzemAccRMUserUniversal::loadRec(
			sqlite3_stmt* stmt
			, WzemAccRMUserUniversal** rec
		) {
	int res;

	WzemAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAccRMUserUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
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

ubigint LiteTblWzemAccRMUserUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	int res; ubigint numread = 0;

	WzemAccRMUserUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAccRMUserUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		rec->unvIxWzemVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixWzemVRecaccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAccRMUserUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAccRMUserUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemAccRMUserUniversal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAccRMUserUniversal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAccRMUserUniversal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAccRMUserUniversal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAccRMUserUniversal::insertRec(
			WzemAccRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzemVRecaccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAccRMUserUniversal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAccRMUserUniversal::insertRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAccRMUserUniversal::updateRec(
			WzemAccRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzemVRecaccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAccRMUserUniversal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAccRMUserUniversal::updateRst(
			ListWzemAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAccRMUserUniversal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemAccRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, WzemAccRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnv, 1, refWzemMUser);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnv, 2, unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnv, 3, unvUref);

	return loadRecByStmt(stmtLoadRecByUsrMtbUnv, rec);
};

#endif

