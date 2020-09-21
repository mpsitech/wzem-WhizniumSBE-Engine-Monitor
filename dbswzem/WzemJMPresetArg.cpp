/**
	* \file WzemJMPresetArg.cpp
	* database access for table TblWzemJMPresetArg (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemJMPresetArg.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMPresetArg
 ******************************************************************************/

WzemJMPresetArg::WzemJMPresetArg(
			const ubigint ref
			, const ubigint refWzemMPreset
			, const double x1Startu
			, const double x1Stopu
			, const string arg
		) {

	this->ref = ref;
	this->refWzemMPreset = refWzemMPreset;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->arg = arg;
};

bool WzemJMPresetArg::operator==(
			const WzemJMPresetArg& comp
		) {
	return false;
};

bool WzemJMPresetArg::operator!=(
			const WzemJMPresetArg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMPresetArg
 ******************************************************************************/

ListWzemJMPresetArg::ListWzemJMPresetArg() {
};

ListWzemJMPresetArg::ListWzemJMPresetArg(
			const ListWzemJMPresetArg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMPresetArg(*(src.nodes[i]));
};

ListWzemJMPresetArg::~ListWzemJMPresetArg() {
	clear();
};

void ListWzemJMPresetArg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMPresetArg::size() const {
	return(nodes.size());
};

void ListWzemJMPresetArg::append(
			WzemJMPresetArg* rec
		) {
	nodes.push_back(rec);
};

WzemJMPresetArg* ListWzemJMPresetArg::operator[](
			const uint ix
		) {
	WzemJMPresetArg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMPresetArg& ListWzemJMPresetArg::operator=(
			const ListWzemJMPresetArg& src
		) {
	WzemJMPresetArg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMPresetArg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMPresetArg::operator==(
			const ListWzemJMPresetArg& comp
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

bool ListWzemJMPresetArg::operator!=(
			const ListWzemJMPresetArg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMPresetArg
 ******************************************************************************/

TblWzemJMPresetArg::TblWzemJMPresetArg() {
};

TblWzemJMPresetArg::~TblWzemJMPresetArg() {
};

bool TblWzemJMPresetArg::loadRecBySQL(
			const string& sqlstr
			, WzemJMPresetArg** rec
		) {
	return false;
};

ubigint TblWzemJMPresetArg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	return 0;
};

ubigint TblWzemJMPresetArg::insertRec(
			WzemJMPresetArg* rec
		) {
	return 0;
};

ubigint TblWzemJMPresetArg::insertNewRec(
			WzemJMPresetArg** rec
			, const ubigint refWzemMPreset
			, const double x1Startu
			, const double x1Stopu
			, const string arg
		) {
	ubigint retval = 0;
	WzemJMPresetArg* _rec = NULL;

	_rec = new WzemJMPresetArg(0, refWzemMPreset, x1Startu, x1Stopu, arg);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMPresetArg::appendNewRecToRst(
			ListWzemJMPresetArg& rst
			, WzemJMPresetArg** rec
			, const ubigint refWzemMPreset
			, const double x1Startu
			, const double x1Stopu
			, const string arg
		) {
	ubigint retval = 0;
	WzemJMPresetArg* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMPreset, x1Startu, x1Stopu, arg);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMPresetArg::insertRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
};

void TblWzemJMPresetArg::updateRec(
			WzemJMPresetArg* rec
		) {
};

void TblWzemJMPresetArg::updateRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
};

void TblWzemJMPresetArg::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMPresetArg::loadRecByRef(
			ubigint ref
			, WzemJMPresetArg** rec
		) {
	return false;
};

ubigint TblWzemJMPresetArg::loadRstByPst(
			ubigint refWzemMPreset
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	return 0;
};

ubigint TblWzemJMPresetArg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	ubigint numload = 0;
	WzemJMPresetArg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMPresetArg
 ******************************************************************************/

MyTblWzemJMPresetArg::MyTblWzemJMPresetArg() :
			TblWzemJMPresetArg()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMPresetArg::~MyTblWzemJMPresetArg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMPresetArg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMPresetArg (refWzemMPreset, x1Startu, x1Stopu, arg) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMPresetArg SET refWzemMPreset = ?, x1Startu = ?, x1Stopu = ?, arg = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMPresetArg WHERE ref = ?", false);
};

bool MyTblWzemJMPresetArg::loadRecBySQL(
			const string& sqlstr
			, WzemJMPresetArg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMPresetArg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMPresetArg::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMPresetArg::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemJMPresetArg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMPreset = atoll((char*) dbrow[1]); else _rec->refWzemMPreset = 0;
		if (dbrow[2]) _rec->x1Startu = atof((char*) dbrow[2]); else _rec->x1Startu = 0.0;
		if (dbrow[3]) _rec->x1Stopu = atof((char*) dbrow[3]); else _rec->x1Stopu = 0.0;
		if (dbrow[4]) _rec->arg.assign(dbrow[4], dblengths[4]); else _rec->arg = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMPresetArg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMPresetArg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMPresetArg::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMPresetArg::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemJMPresetArg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMPreset = atoll((char*) dbrow[1]); else rec->refWzemMPreset = 0;
			if (dbrow[2]) rec->x1Startu = atof((char*) dbrow[2]); else rec->x1Startu = 0.0;
			if (dbrow[3]) rec->x1Stopu = atof((char*) dbrow[3]); else rec->x1Stopu = 0.0;
			if (dbrow[4]) rec->arg.assign(dbrow[4], dblengths[4]); else rec->arg = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMPresetArg::insertRec(
			WzemJMPresetArg* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->arg.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMPreset,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->arg.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMPresetArg::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMPresetArg::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMPresetArg::insertRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMPresetArg::updateRec(
			WzemJMPresetArg* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->arg.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMPreset,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->arg.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMPresetArg::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMPresetArg::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMPresetArg::updateRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMPresetArg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMPresetArg::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMPresetArg::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMPresetArg::loadRecByRef(
			ubigint ref
			, WzemJMPresetArg** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMPresetArg WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemJMPresetArg::loadRstByPst(
			ubigint refWzemMPreset
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMPreset, x1Startu, x1Stopu, arg FROM TblWzemJMPresetArg WHERE refWzemMPreset = " + to_string(refWzemMPreset) + " ORDER BY x1Startu ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMPresetArg
 ******************************************************************************/

PgTblWzemJMPresetArg::PgTblWzemJMPresetArg() :
			TblWzemJMPresetArg()
			, PgTable()
		{
};

PgTblWzemJMPresetArg::~PgTblWzemJMPresetArg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMPresetArg::initStatements() {
	createStatement("TblWzemJMPresetArg_insertRec", "INSERT INTO TblWzemJMPresetArg (refWzemMPreset, x1Startu, x1Stopu, arg) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemJMPresetArg_updateRec", "UPDATE TblWzemJMPresetArg SET refWzemMPreset = $1, x1Startu = $2, x1Stopu = $3, arg = $4 WHERE ref = $5", 5);
	createStatement("TblWzemJMPresetArg_removeRecByRef", "DELETE FROM TblWzemJMPresetArg WHERE ref = $1", 1);

	createStatement("TblWzemJMPresetArg_loadRecByRef", "SELECT ref, refWzemMPreset, x1Startu, x1Stopu, arg FROM TblWzemJMPresetArg WHERE ref = $1", 1);
	createStatement("TblWzemJMPresetArg_loadRstByPst", "SELECT ref, refWzemMPreset, x1Startu, x1Stopu, arg FROM TblWzemJMPresetArg WHERE refWzemMPreset = $1 ORDER BY x1Startu ASC", 1);
};

bool PgTblWzemJMPresetArg::loadRec(
			PGresult* res
			, WzemJMPresetArg** rec
		) {
	char* ptr;

	WzemJMPresetArg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMPresetArg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmpreset"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "arg")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->arg.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMPresetArg::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMPresetArg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmpreset"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "arg")
		};

		while (numread < numrow) {
			rec = new WzemJMPresetArg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->arg.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMPresetArg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMPresetArg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPresetArg::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMPresetArg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPresetArg::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMPresetArg::loadRecBySQL(
			const string& sqlstr
			, WzemJMPresetArg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPresetArg::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMPresetArg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPresetArg::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMPresetArg::insertRec(
			WzemJMPresetArg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMPreset = htonl64(rec->refWzemMPreset);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);

	const char* vals[] = {
		(char*) &_refWzemMPreset,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		rec->arg.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemJMPresetArg_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPresetArg::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMPresetArg::insertRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMPresetArg::updateRec(
			WzemJMPresetArg* rec
		) {
	PGresult* res;

	ubigint _refWzemMPreset = htonl64(rec->refWzemMPreset);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMPreset,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		rec->arg.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemJMPresetArg_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMPresetArg::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMPresetArg::updateRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMPresetArg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMPresetArg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMPresetArg::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMPresetArg::loadRecByRef(
			ubigint ref
			, WzemJMPresetArg** rec
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

	return loadRecByStmt("TblWzemJMPresetArg_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemJMPresetArg::loadRstByPst(
			ubigint refWzemMPreset
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	ubigint _refWzemMPreset = htonl64(refWzemMPreset);

	const char* vals[] = {
		(char*) &_refWzemMPreset
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMPresetArg_loadRstByPst", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMPresetArg
 ******************************************************************************/

LiteTblWzemJMPresetArg::LiteTblWzemJMPresetArg() :
			TblWzemJMPresetArg()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByPst = NULL;
};

LiteTblWzemJMPresetArg::~LiteTblWzemJMPresetArg() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByPst) sqlite3_finalize(stmtLoadRstByPst);
};

void LiteTblWzemJMPresetArg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMPresetArg (refWzemMPreset, x1Startu, x1Stopu, arg) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMPresetArg SET refWzemMPreset = ?1, x1Startu = ?2, x1Stopu = ?3, arg = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMPresetArg WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMPreset, x1Startu, x1Stopu, arg FROM TblWzemJMPresetArg WHERE ref = ?1");
	stmtLoadRstByPst = createStatement("SELECT ref, refWzemMPreset, x1Startu, x1Stopu, arg FROM TblWzemJMPresetArg WHERE refWzemMPreset = ?1 ORDER BY x1Startu ASC");
};

bool LiteTblWzemJMPresetArg::loadRec(
			sqlite3_stmt* stmt
			, WzemJMPresetArg** rec
		) {
	int res;

	WzemJMPresetArg* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMPresetArg();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMPreset = sqlite3_column_int64(stmt, 1);
		_rec->x1Startu = sqlite3_column_double(stmt, 2);
		_rec->x1Stopu = sqlite3_column_double(stmt, 3);
		_rec->arg.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzemJMPresetArg::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	int res; ubigint numread = 0;

	WzemJMPresetArg* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMPresetArg();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMPreset = sqlite3_column_int64(stmt, 1);
		rec->x1Startu = sqlite3_column_double(stmt, 2);
		rec->x1Stopu = sqlite3_column_double(stmt, 3);
		rec->arg.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMPresetArg::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMPresetArg** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMPresetArg::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMPresetArg::loadRecBySQL(
			const string& sqlstr
			, WzemJMPresetArg** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMPresetArg::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMPresetArg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMPresetArg::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMPresetArg::insertRec(
			WzemJMPresetArg* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMPreset);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 3, rec->x1Stopu);
	sqlite3_bind_text(stmtInsertRec, 4, rec->arg.c_str(), rec->arg.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMPresetArg::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMPresetArg::insertRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMPresetArg::updateRec(
			WzemJMPresetArg* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMPreset);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 3, rec->x1Stopu);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->arg.c_str(), rec->arg.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMPresetArg::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMPresetArg::updateRst(
			ListWzemJMPresetArg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMPresetArg::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMPresetArg::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMPresetArg::loadRecByRef(
			ubigint ref
			, WzemJMPresetArg** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemJMPresetArg::loadRstByPst(
			ubigint refWzemMPreset
			, const bool append
			, ListWzemJMPresetArg& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPst, 1, refWzemMPreset);

	return loadRstByStmt(stmtLoadRstByPst, append, rst);
};

#endif

