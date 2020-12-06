/**
	* \file WzemRMUserMUsergroup.cpp
	* database access for table TblWzemRMUserMUsergroup (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemRMUserMUsergroup.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemRMUserMUsergroup
 ******************************************************************************/

WzemRMUserMUsergroup::WzemRMUserMUsergroup(
			const ubigint ref
			, const ubigint refWzemMUser
			, const ubigint refWzemMUsergroup
			, const uint ixWzemVUserlevel
		) {

	this->ref = ref;
	this->refWzemMUser = refWzemMUser;
	this->refWzemMUsergroup = refWzemMUsergroup;
	this->ixWzemVUserlevel = ixWzemVUserlevel;
};

bool WzemRMUserMUsergroup::operator==(
			const WzemRMUserMUsergroup& comp
		) {
	return false;
};

bool WzemRMUserMUsergroup::operator!=(
			const WzemRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemRMUserMUsergroup
 ******************************************************************************/

ListWzemRMUserMUsergroup::ListWzemRMUserMUsergroup() {
};

ListWzemRMUserMUsergroup::ListWzemRMUserMUsergroup(
			const ListWzemRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemRMUserMUsergroup(*(src.nodes[i]));
};

ListWzemRMUserMUsergroup::~ListWzemRMUserMUsergroup() {
	clear();
};

void ListWzemRMUserMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListWzemRMUserMUsergroup::append(
			WzemRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

WzemRMUserMUsergroup* ListWzemRMUserMUsergroup::operator[](
			const uint ix
		) {
	WzemRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemRMUserMUsergroup& ListWzemRMUserMUsergroup::operator=(
			const ListWzemRMUserMUsergroup& src
		) {
	WzemRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemRMUserMUsergroup::operator==(
			const ListWzemRMUserMUsergroup& comp
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

bool ListWzemRMUserMUsergroup::operator!=(
			const ListWzemRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemRMUserMUsergroup
 ******************************************************************************/

TblWzemRMUserMUsergroup::TblWzemRMUserMUsergroup() {
};

TblWzemRMUserMUsergroup::~TblWzemRMUserMUsergroup() {
};

bool TblWzemRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWzemRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzemRMUserMUsergroup::insertRec(
			WzemRMUserMUsergroup* rec
		) {
	return 0;
};

ubigint TblWzemRMUserMUsergroup::insertNewRec(
			WzemRMUserMUsergroup** rec
			, const ubigint refWzemMUser
			, const ubigint refWzemMUsergroup
			, const uint ixWzemVUserlevel
		) {
	ubigint retval = 0;
	WzemRMUserMUsergroup* _rec = NULL;

	_rec = new WzemRMUserMUsergroup(0, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemRMUserMUsergroup::appendNewRecToRst(
			ListWzemRMUserMUsergroup& rst
			, WzemRMUserMUsergroup** rec
			, const ubigint refWzemMUser
			, const ubigint refWzemMUsergroup
			, const uint ixWzemVUserlevel
		) {
	ubigint retval = 0;
	WzemRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemRMUserMUsergroup::insertRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWzemRMUserMUsergroup::updateRec(
			WzemRMUserMUsergroup* rec
		) {
};

void TblWzemRMUserMUsergroup::updateRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblWzemRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzemRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblWzemRMUserMUsergroup::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzemRMUserMUsergroup::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblWzemRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	WzemRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemRMUserMUsergroup
 ******************************************************************************/

MyTblWzemRMUserMUsergroup::MyTblWzemRMUserMUsergroup() :
			TblWzemRMUserMUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemRMUserMUsergroup::~MyTblWzemRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemRMUserMUsergroup (refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemRMUserMUsergroup SET refWzemMUser = ?, refWzemMUsergroup = ?, ixWzemVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblWzemRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemRMUserMUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemRMUserMUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUser = atoll((char*) dbrow[1]); else _rec->refWzemMUser = 0;
		if (dbrow[2]) _rec->refWzemMUsergroup = atoll((char*) dbrow[2]); else _rec->refWzemMUsergroup = 0;
		if (dbrow[3]) _rec->ixWzemVUserlevel = atol((char*) dbrow[3]); else _rec->ixWzemVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemRMUserMUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemRMUserMUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUser = atoll((char*) dbrow[1]); else rec->refWzemMUser = 0;
			if (dbrow[2]) rec->refWzemMUsergroup = atoll((char*) dbrow[2]); else rec->refWzemMUsergroup = 0;
			if (dbrow[3]) rec->ixWzemVUserlevel = atol((char*) dbrow[3]); else rec->ixWzemVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemRMUserMUsergroup::insertRec(
			WzemRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzemMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWzemVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemRMUserMUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemRMUserMUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemRMUserMUsergroup::insertRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemRMUserMUsergroup::updateRec(
			WzemRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzemMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWzemVUserlevel,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemRMUserMUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemRMUserMUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemRMUserMUsergroup::updateRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemRMUserMUsergroup::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemRMUserMUsergroup::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzemRMUserMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemRMUserMUsergroup::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE refWzemMUsergroup = " + to_string(refWzemMUsergroup) + "", append, rst);
};

ubigint MyTblWzemRMUserMUsergroup::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE refWzemMUser = " + to_string(refWzemMUser) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemRMUserMUsergroup
 ******************************************************************************/

PgTblWzemRMUserMUsergroup::PgTblWzemRMUserMUsergroup() :
			TblWzemRMUserMUsergroup()
			, PgTable()
		{
};

PgTblWzemRMUserMUsergroup::~PgTblWzemRMUserMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemRMUserMUsergroup::initStatements() {
	createStatement("TblWzemRMUserMUsergroup_insertRec", "INSERT INTO TblWzemRMUserMUsergroup (refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWzemRMUserMUsergroup_updateRec", "UPDATE TblWzemRMUserMUsergroup SET refWzemMUser = $1, refWzemMUsergroup = $2, ixWzemVUserlevel = $3 WHERE ref = $4", 4);
	createStatement("TblWzemRMUserMUsergroup_removeRecByRef", "DELETE FROM TblWzemRMUserMUsergroup WHERE ref = $1", 1);

	createStatement("TblWzemRMUserMUsergroup_loadRecByRef", "SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE ref = $1", 1);
	createStatement("TblWzemRMUserMUsergroup_loadRstByUsg", "SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE refWzemMUsergroup = $1", 1);
	createStatement("TblWzemRMUserMUsergroup_loadRstByUsr", "SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE refWzemMUser = $1", 1);
};

bool PgTblWzemRMUserMUsergroup::loadRec(
			PGresult* res
			, WzemRMUserMUsergroup** rec
		) {
	char* ptr;

	WzemRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemRMUserMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "ixwzemvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWzemMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWzemVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemRMUserMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemRMUserMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "ixwzemvuserlevel")
		};

		while (numread < numrow) {
			rec = new WzemRMUserMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWzemMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWzemVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemRMUserMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemRMUserMUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemRMUserMUsergroup::insertRec(
			WzemRMUserMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_refWzemMUsergroup,
		(char*) &_ixWzemVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemRMUserMUsergroup_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemRMUserMUsergroup::insertRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemRMUserMUsergroup::updateRec(
			WzemRMUserMUsergroup* rec
		) {
	PGresult* res;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_refWzemMUsergroup,
		(char*) &_ixWzemVUserlevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemRMUserMUsergroup_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemRMUserMUsergroup::updateRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemRMUserMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemRMUserMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemRMUserMUsergroup::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzemRMUserMUsergroup** rec
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

	return loadRecByStmt("TblWzemRMUserMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemRMUserMUsergroup::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	ubigint _refWzemMUsergroup = htonl64(refWzemMUsergroup);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemRMUserMUsergroup_loadRstByUsg", 1, vals, l, f, append, rst);
};

ubigint PgTblWzemRMUserMUsergroup::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);

	const char* vals[] = {
		(char*) &_refWzemMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemRMUserMUsergroup_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemRMUserMUsergroup
 ******************************************************************************/

LiteTblWzemRMUserMUsergroup::LiteTblWzemRMUserMUsergroup() :
			TblWzemRMUserMUsergroup()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByUsg = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzemRMUserMUsergroup::~LiteTblWzemRMUserMUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByUsg) sqlite3_finalize(stmtLoadRstByUsg);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzemRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemRMUserMUsergroup (refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzemRMUserMUsergroup SET refWzemMUser = ?1, refWzemMUsergroup = ?2, ixWzemVUserlevel = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemRMUserMUsergroup WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE ref = ?1");
	stmtLoadRstByUsg = createStatement("SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE refWzemMUsergroup = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzemMUser, refWzemMUsergroup, ixWzemVUserlevel FROM TblWzemRMUserMUsergroup WHERE refWzemMUser = ?1");
};

bool LiteTblWzemRMUserMUsergroup::loadRec(
			sqlite3_stmt* stmt
			, WzemRMUserMUsergroup** rec
		) {
	int res;

	WzemRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemRMUserMUsergroup();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		_rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 2);
		_rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 3);

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

ubigint LiteTblWzemRMUserMUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	int res; ubigint numread = 0;

	WzemRMUserMUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemRMUserMUsergroup();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 2);
		rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemRMUserMUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemRMUserMUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemRMUserMUsergroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemRMUserMUsergroup** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemRMUserMUsergroup::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemRMUserMUsergroup::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemRMUserMUsergroup::insertRec(
			WzemRMUserMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUser);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ixWzemVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemRMUserMUsergroup::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemRMUserMUsergroup::insertRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemRMUserMUsergroup::updateRec(
			WzemRMUserMUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUser);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ixWzemVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemRMUserMUsergroup::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemRMUserMUsergroup::updateRst(
			ListWzemRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemRMUserMUsergroup::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, WzemRMUserMUsergroup** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemRMUserMUsergroup::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsg, 1, refWzemMUsergroup);

	return loadRstByStmt(stmtLoadRstByUsg, append, rst);
};

ubigint LiteTblWzemRMUserMUsergroup::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemRMUserMUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzemMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif

