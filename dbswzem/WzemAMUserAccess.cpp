/**
	* \file WzemAMUserAccess.cpp
	* database access for table TblWzemAMUserAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemAMUserAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAMUserAccess
 ******************************************************************************/

WzemAMUserAccess::WzemAMUserAccess(
			const ubigint ref
			, const ubigint refWzemMUser
			, const uint x1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
		) {

	this->ref = ref;
	this->refWzemMUser = refWzemMUser;
	this->x1IxWzemVFeatgroup = x1IxWzemVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzemWAccess = ixWzemWAccess;
};

bool WzemAMUserAccess::operator==(
			const WzemAMUserAccess& comp
		) {
	return false;
};

bool WzemAMUserAccess::operator!=(
			const WzemAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAMUserAccess
 ******************************************************************************/

ListWzemAMUserAccess::ListWzemAMUserAccess() {
};

ListWzemAMUserAccess::ListWzemAMUserAccess(
			const ListWzemAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAMUserAccess(*(src.nodes[i]));
};

ListWzemAMUserAccess::~ListWzemAMUserAccess() {
	clear();
};

void ListWzemAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAMUserAccess::size() const {
	return(nodes.size());
};

void ListWzemAMUserAccess::append(
			WzemAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

WzemAMUserAccess* ListWzemAMUserAccess::operator[](
			const uint ix
		) {
	WzemAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAMUserAccess& ListWzemAMUserAccess::operator=(
			const ListWzemAMUserAccess& src
		) {
	WzemAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAMUserAccess::operator==(
			const ListWzemAMUserAccess& comp
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

bool ListWzemAMUserAccess::operator!=(
			const ListWzemAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAMUserAccess
 ******************************************************************************/

TblWzemAMUserAccess::TblWzemAMUserAccess() {
};

TblWzemAMUserAccess::~TblWzemAMUserAccess() {
};

bool TblWzemAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUserAccess** rec
		) {
	return false;
};

ubigint TblWzemAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWzemAMUserAccess::insertRec(
			WzemAMUserAccess* rec
		) {
	return 0;
};

ubigint TblWzemAMUserAccess::insertNewRec(
			WzemAMUserAccess** rec
			, const ubigint refWzemMUser
			, const uint x1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
		) {
	ubigint retval = 0;
	WzemAMUserAccess* _rec = NULL;

	_rec = new WzemAMUserAccess(0, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAMUserAccess::appendNewRecToRst(
			ListWzemAMUserAccess& rst
			, WzemAMUserAccess** rec
			, const ubigint refWzemMUser
			, const uint x1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
		) {
	ubigint retval = 0;
	WzemAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAMUserAccess::insertRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
};

void TblWzemAMUserAccess::updateRec(
			WzemAMUserAccess* rec
		) {
};

void TblWzemAMUserAccess::updateRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
};

void TblWzemAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAMUserAccess::loadRecByRef(
			ubigint ref
			, WzemAMUserAccess** rec
		) {
	return false;
};

ubigint TblWzemAMUserAccess::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemAMUserAccess::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWzemAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	ubigint numload = 0;
	WzemAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAMUserAccess
 ******************************************************************************/

MyTblWzemAMUserAccess::MyTblWzemAMUserAccess() :
			TblWzemAMUserAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAMUserAccess::~MyTblWzemAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAMUserAccess (refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAMUserAccess SET refWzemMUser = ?, x1IxWzemVFeatgroup = ?, x2FeaSrefUix = ?, ixWzemWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAMUserAccess WHERE ref = ?", false);
};

bool MyTblWzemAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAMUserAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAMUserAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUser = atoll((char*) dbrow[1]); else _rec->refWzemMUser = 0;
		if (dbrow[2]) _rec->x1IxWzemVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWzemVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWzemWAccess = atol((char*) dbrow[4]); else _rec->ixWzemWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAMUserAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAMUserAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUser = atoll((char*) dbrow[1]); else rec->refWzemMUser = 0;
			if (dbrow[2]) rec->x1IxWzemVFeatgroup = atol((char*) dbrow[2]); else rec->x1IxWzemVFeatgroup = 0;
			if (dbrow[3]) rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else rec->x2FeaSrefUix = "";
			if (dbrow[4]) rec->ixWzemWAccess = atol((char*) dbrow[4]); else rec->ixWzemWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemAMUserAccess::insertRec(
			WzemAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzemVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAMUserAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAMUserAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAMUserAccess::insertRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAMUserAccess::updateRec(
			WzemAMUserAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzemVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAMUserAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAMUserAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAMUserAccess::updateRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAMUserAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAMUserAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAMUserAccess::loadRecByRef(
			ubigint ref
			, WzemAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAMUserAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemAMUserAccess::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemAMUserAccess WHERE refWzemMUser = " + to_string(refWzemMUser) + "", append, refs);
};

ubigint MyTblWzemAMUserAccess::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUserAccess WHERE refWzemMUser = " + to_string(refWzemMUser) + " ORDER BY x1IxWzemVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAMUserAccess
 ******************************************************************************/

PgTblWzemAMUserAccess::PgTblWzemAMUserAccess() :
			TblWzemAMUserAccess()
			, PgTable()
		{
};

PgTblWzemAMUserAccess::~PgTblWzemAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAMUserAccess::initStatements() {
	createStatement("TblWzemAMUserAccess_insertRec", "INSERT INTO TblWzemAMUserAccess (refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemAMUserAccess_updateRec", "UPDATE TblWzemAMUserAccess SET refWzemMUser = $1, x1IxWzemVFeatgroup = $2, x2FeaSrefUix = $3, ixWzemWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblWzemAMUserAccess_removeRecByRef", "DELETE FROM TblWzemAMUserAccess WHERE ref = $1", 1);

	createStatement("TblWzemAMUserAccess_loadRecByRef", "SELECT ref, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUserAccess WHERE ref = $1", 1);
	createStatement("TblWzemAMUserAccess_loadRefsByUsr", "SELECT ref FROM TblWzemAMUserAccess WHERE refWzemMUser = $1", 1);
	createStatement("TblWzemAMUserAccess_loadRstByUsr", "SELECT ref, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUserAccess WHERE refWzemMUser = $1 ORDER BY x1IxWzemVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblWzemAMUserAccess::loadRec(
			PGresult* res
			, WzemAMUserAccess** rec
		) {
	char* ptr;

	WzemAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "x1ixwzemvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwzemwaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWzemVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWzemWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "x1ixwzemvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwzemwaccess")
		};

		while (numread < numrow) {
			rec = new WzemAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWzemVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWzemWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUserAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAMUserAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUserAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUserAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUserAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAMUserAccess::insertRec(
			WzemAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _x1IxWzemVFeatgroup = htonl(rec->x1IxWzemVFeatgroup);
	uint _ixWzemWAccess = htonl(rec->ixWzemWAccess);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_x1IxWzemVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWzemWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemAMUserAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUserAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAMUserAccess::insertRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAMUserAccess::updateRec(
			WzemAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _x1IxWzemVFeatgroup = htonl(rec->x1IxWzemVFeatgroup);
	uint _ixWzemWAccess = htonl(rec->ixWzemWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_x1IxWzemVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWzemWAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemAMUserAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAMUserAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAMUserAccess::updateRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAMUserAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAMUserAccess::loadRecByRef(
			ubigint ref
			, WzemAMUserAccess** rec
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

	return loadRecByStmt("TblWzemAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemAMUserAccess::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);

	const char* vals[] = {
		(char*) &_refWzemMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemAMUserAccess_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemAMUserAccess::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);

	const char* vals[] = {
		(char*) &_refWzemMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemAMUserAccess_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAMUserAccess
 ******************************************************************************/

LiteTblWzemAMUserAccess::LiteTblWzemAMUserAccess() :
			TblWzemAMUserAccess()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsr = NULL;
	stmtLoadRstByUsr = NULL;
};

LiteTblWzemAMUserAccess::~LiteTblWzemAMUserAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsr) sqlite3_finalize(stmtLoadRefsByUsr);
	if (stmtLoadRstByUsr) sqlite3_finalize(stmtLoadRstByUsr);
};

void LiteTblWzemAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAMUserAccess (refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAMUserAccess SET refWzemMUser = ?1, x1IxWzemVFeatgroup = ?2, x2FeaSrefUix = ?3, ixWzemWAccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAMUserAccess WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUserAccess WHERE ref = ?1");
	stmtLoadRefsByUsr = createStatement("SELECT ref FROM TblWzemAMUserAccess WHERE refWzemMUser = ?1");
	stmtLoadRstByUsr = createStatement("SELECT ref, refWzemMUser, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUserAccess WHERE refWzemMUser = ?1 ORDER BY x1IxWzemVFeatgroup ASC, x2FeaSrefUix ASC");
};

bool LiteTblWzemAMUserAccess::loadRec(
			sqlite3_stmt* stmt
			, WzemAMUserAccess** rec
		) {
	int res;

	WzemAMUserAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAMUserAccess();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		_rec->x1IxWzemVFeatgroup = sqlite3_column_int(stmt, 2);
		_rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->ixWzemWAccess = sqlite3_column_int(stmt, 4);

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

ubigint LiteTblWzemAMUserAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	int res; ubigint numread = 0;

	WzemAMUserAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAMUserAccess();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzemVFeatgroup = sqlite3_column_int(stmt, 2);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->ixWzemWAccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAMUserAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAMUserAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemAMUserAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUserAccess** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAMUserAccess::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAMUserAccess::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAMUserAccess::insertRec(
			WzemAMUserAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzemVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzemWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMUserAccess::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAMUserAccess::insertRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAMUserAccess::updateRec(
			WzemAMUserAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzemVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzemWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMUserAccess::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAMUserAccess::updateRst(
			ListWzemAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMUserAccess::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAMUserAccess::loadRecByRef(
			ubigint ref
			, WzemAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemAMUserAccess::loadRefsByUsr(
			ubigint refWzemMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsr, 1, refWzemMUser);

	return loadRefsByStmt(stmtLoadRefsByUsr, append, refs);
};

ubigint LiteTblWzemAMUserAccess::loadRstByUsr(
			ubigint refWzemMUser
			, const bool append
			, ListWzemAMUserAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsr, 1, refWzemMUser);

	return loadRstByStmt(stmtLoadRstByUsr, append, rst);
};

#endif
