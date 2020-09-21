/**
	* \file WzemMPeriod.cpp
	* database access for table TblWzemMPeriod (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemMPeriod.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMPeriod
 ******************************************************************************/

WzemMPeriod::WzemMPeriod(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string Version
			, const uint start
			, const uint stop
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->Version = Version;
	this->start = start;
	this->stop = stop;
};

bool WzemMPeriod::operator==(
			const WzemMPeriod& comp
		) {
	return false;
};

bool WzemMPeriod::operator!=(
			const WzemMPeriod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMPeriod
 ******************************************************************************/

ListWzemMPeriod::ListWzemMPeriod() {
};

ListWzemMPeriod::ListWzemMPeriod(
			const ListWzemMPeriod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMPeriod(*(src.nodes[i]));
};

ListWzemMPeriod::~ListWzemMPeriod() {
	clear();
};

void ListWzemMPeriod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMPeriod::size() const {
	return(nodes.size());
};

void ListWzemMPeriod::append(
			WzemMPeriod* rec
		) {
	nodes.push_back(rec);
};

WzemMPeriod* ListWzemMPeriod::operator[](
			const uint ix
		) {
	WzemMPeriod* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMPeriod& ListWzemMPeriod::operator=(
			const ListWzemMPeriod& src
		) {
	WzemMPeriod* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMPeriod(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMPeriod::operator==(
			const ListWzemMPeriod& comp
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

bool ListWzemMPeriod::operator!=(
			const ListWzemMPeriod& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMPeriod
 ******************************************************************************/

TblWzemMPeriod::TblWzemMPeriod() {
};

TblWzemMPeriod::~TblWzemMPeriod() {
};

bool TblWzemMPeriod::loadRecBySQL(
			const string& sqlstr
			, WzemMPeriod** rec
		) {
	return false;
};

ubigint TblWzemMPeriod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPeriod& rst
		) {
	return 0;
};

ubigint TblWzemMPeriod::insertRec(
			WzemMPeriod* rec
		) {
	return 0;
};

ubigint TblWzemMPeriod::insertNewRec(
			WzemMPeriod** rec
			, const ubigint grp
			, const ubigint own
			, const string Version
			, const uint start
			, const uint stop
		) {
	ubigint retval = 0;
	WzemMPeriod* _rec = NULL;

	_rec = new WzemMPeriod(0, grp, own, Version, start, stop);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMPeriod::appendNewRecToRst(
			ListWzemMPeriod& rst
			, WzemMPeriod** rec
			, const ubigint grp
			, const ubigint own
			, const string Version
			, const uint start
			, const uint stop
		) {
	ubigint retval = 0;
	WzemMPeriod* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, Version, start, stop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMPeriod::insertRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
};

void TblWzemMPeriod::updateRec(
			WzemMPeriod* rec
		) {
};

void TblWzemMPeriod::updateRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
};

void TblWzemMPeriod::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMPeriod::loadRecByRef(
			ubigint ref
			, WzemMPeriod** rec
		) {
	return false;
};

ubigint TblWzemMPeriod::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMPeriod& rst
		) {
	ubigint numload = 0;
	WzemMPeriod* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMPeriod
 ******************************************************************************/

MyTblWzemMPeriod::MyTblWzemMPeriod() :
			TblWzemMPeriod()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMPeriod::~MyTblWzemMPeriod() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMPeriod::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMPeriod (grp, own, Version, start, stop) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMPeriod SET grp = ?, own = ?, Version = ?, start = ?, stop = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMPeriod WHERE ref = ?", false);
};

bool MyTblWzemMPeriod::loadRecBySQL(
			const string& sqlstr
			, WzemMPeriod** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMPeriod* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMPeriod::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMPeriod::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMPeriod();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->Version.assign(dbrow[3], dblengths[3]); else _rec->Version = "";
		if (dbrow[4]) _rec->start = atol((char*) dbrow[4]); else _rec->start = 0;
		if (dbrow[5]) _rec->stop = atol((char*) dbrow[5]); else _rec->stop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMPeriod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPeriod& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMPeriod* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMPeriod::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMPeriod::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMPeriod();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->Version.assign(dbrow[3], dblengths[3]); else rec->Version = "";
			if (dbrow[4]) rec->start = atol((char*) dbrow[4]); else rec->start = 0;
			if (dbrow[5]) rec->stop = atol((char*) dbrow[5]); else rec->stop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMPeriod::insertRec(
			WzemMPeriod* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Version.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Version.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->start,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->stop,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMPeriod::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMPeriod::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMPeriod::insertRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMPeriod::updateRec(
			WzemMPeriod* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->Version.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Version.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->start,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->stop,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMPeriod::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMPeriod::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMPeriod::updateRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMPeriod::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMPeriod::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMPeriod::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMPeriod::loadRecByRef(
			ubigint ref
			, WzemMPeriod** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMPeriod WHERE ref = " + to_string(ref), rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMPeriod
 ******************************************************************************/

PgTblWzemMPeriod::PgTblWzemMPeriod() :
			TblWzemMPeriod()
			, PgTable()
		{
};

PgTblWzemMPeriod::~PgTblWzemMPeriod() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMPeriod::initStatements() {
	createStatement("TblWzemMPeriod_insertRec", "INSERT INTO TblWzemMPeriod (grp, own, Version, start, stop) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWzemMPeriod_updateRec", "UPDATE TblWzemMPeriod SET grp = $1, own = $2, Version = $3, start = $4, stop = $5 WHERE ref = $6", 6);
	createStatement("TblWzemMPeriod_removeRecByRef", "DELETE FROM TblWzemMPeriod WHERE ref = $1", 1);

	createStatement("TblWzemMPeriod_loadRecByRef", "SELECT ref, grp, own, Version, start, stop FROM TblWzemMPeriod WHERE ref = $1", 1);
};

bool PgTblWzemMPeriod::loadRec(
			PGresult* res
			, WzemMPeriod** rec
		) {
	char* ptr;

	WzemMPeriod* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMPeriod();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "version"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Version.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->stop = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMPeriod::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMPeriod& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMPeriod* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "version"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop")
		};

		while (numread < numrow) {
			rec = new WzemMPeriod();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Version.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->stop = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMPeriod::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMPeriod** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPeriod::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWzemMPeriod::loadRecBySQL(
			const string& sqlstr
			, WzemMPeriod** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPeriod::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMPeriod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPeriod& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPeriod::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMPeriod::insertRec(
			WzemMPeriod* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->Version.c_str(),
		(char*) &_start,
		(char*) &_stop
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMPeriod_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMPeriod::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMPeriod::insertRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMPeriod::updateRec(
			WzemMPeriod* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->Version.c_str(),
		(char*) &_start,
		(char*) &_stop,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMPeriod_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMPeriod::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMPeriod::updateRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMPeriod::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMPeriod_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMPeriod::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMPeriod::loadRecByRef(
			ubigint ref
			, WzemMPeriod** rec
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

	return loadRecByStmt("TblWzemMPeriod_loadRecByRef", 1, vals, l, f, rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMPeriod
 ******************************************************************************/

LiteTblWzemMPeriod::LiteTblWzemMPeriod() :
			TblWzemMPeriod()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

};

LiteTblWzemMPeriod::~LiteTblWzemMPeriod() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

};

void LiteTblWzemMPeriod::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMPeriod (grp, own, Version, start, stop) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMPeriod SET grp = ?1, own = ?2, Version = ?3, start = ?4, stop = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMPeriod WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, Version, start, stop FROM TblWzemMPeriod WHERE ref = ?1");
};

bool LiteTblWzemMPeriod::loadRec(
			sqlite3_stmt* stmt
			, WzemMPeriod** rec
		) {
	int res;

	WzemMPeriod* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMPeriod();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->Version.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->start = sqlite3_column_int(stmt, 4);
		_rec->stop = sqlite3_column_int(stmt, 5);

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

ubigint LiteTblWzemMPeriod::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMPeriod& rst
		) {
	int res; ubigint numread = 0;

	WzemMPeriod* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMPeriod();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->Version.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->start = sqlite3_column_int(stmt, 4);
		rec->stop = sqlite3_column_int(stmt, 5);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMPeriod::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMPeriod** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMPeriod::loadRecBySQL(
			const string& sqlstr
			, WzemMPeriod** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMPeriod::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMPeriod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMPeriod& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMPeriod::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMPeriod::insertRec(
			WzemMPeriod* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Version.c_str(), rec->Version.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->start);
	sqlite3_bind_int(stmtInsertRec, 5, rec->stop);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMPeriod::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMPeriod::insertRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMPeriod::updateRec(
			WzemMPeriod* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Version.c_str(), rec->Version.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->start);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->stop);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMPeriod::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMPeriod::updateRst(
			ListWzemMPeriod& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMPeriod::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMPeriod::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMPeriod::loadRecByRef(
			ubigint ref
			, WzemMPeriod** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

#endif

