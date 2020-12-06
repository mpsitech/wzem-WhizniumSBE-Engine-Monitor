/**
	* \file WzemJMCallArgRet.cpp
	* database access for table TblWzemJMCallArgRet (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemJMCallArgRet.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMCallArgRet
 ******************************************************************************/

WzemJMCallArgRet::WzemJMCallArgRet(
			const ubigint ref
			, const ubigint refWzemMCall
			, const double x1Startu
			, const double x1Stopu
			, const string argRet
		) {

	this->ref = ref;
	this->refWzemMCall = refWzemMCall;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->argRet = argRet;
};

bool WzemJMCallArgRet::operator==(
			const WzemJMCallArgRet& comp
		) {
	return false;
};

bool WzemJMCallArgRet::operator!=(
			const WzemJMCallArgRet& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMCallArgRet
 ******************************************************************************/

ListWzemJMCallArgRet::ListWzemJMCallArgRet() {
};

ListWzemJMCallArgRet::ListWzemJMCallArgRet(
			const ListWzemJMCallArgRet& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMCallArgRet(*(src.nodes[i]));
};

ListWzemJMCallArgRet::~ListWzemJMCallArgRet() {
	clear();
};

void ListWzemJMCallArgRet::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMCallArgRet::size() const {
	return(nodes.size());
};

void ListWzemJMCallArgRet::append(
			WzemJMCallArgRet* rec
		) {
	nodes.push_back(rec);
};

WzemJMCallArgRet* ListWzemJMCallArgRet::operator[](
			const uint ix
		) {
	WzemJMCallArgRet* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMCallArgRet& ListWzemJMCallArgRet::operator=(
			const ListWzemJMCallArgRet& src
		) {
	WzemJMCallArgRet* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMCallArgRet(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMCallArgRet::operator==(
			const ListWzemJMCallArgRet& comp
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

bool ListWzemJMCallArgRet::operator!=(
			const ListWzemJMCallArgRet& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMCallArgRet
 ******************************************************************************/

TblWzemJMCallArgRet::TblWzemJMCallArgRet() {
};

TblWzemJMCallArgRet::~TblWzemJMCallArgRet() {
};

bool TblWzemJMCallArgRet::loadRecBySQL(
			const string& sqlstr
			, WzemJMCallArgRet** rec
		) {
	return false;
};

ubigint TblWzemJMCallArgRet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	return 0;
};

ubigint TblWzemJMCallArgRet::insertRec(
			WzemJMCallArgRet* rec
		) {
	return 0;
};

ubigint TblWzemJMCallArgRet::insertNewRec(
			WzemJMCallArgRet** rec
			, const ubigint refWzemMCall
			, const double x1Startu
			, const double x1Stopu
			, const string argRet
		) {
	ubigint retval = 0;
	WzemJMCallArgRet* _rec = NULL;

	_rec = new WzemJMCallArgRet(0, refWzemMCall, x1Startu, x1Stopu, argRet);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMCallArgRet::appendNewRecToRst(
			ListWzemJMCallArgRet& rst
			, WzemJMCallArgRet** rec
			, const ubigint refWzemMCall
			, const double x1Startu
			, const double x1Stopu
			, const string argRet
		) {
	ubigint retval = 0;
	WzemJMCallArgRet* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMCall, x1Startu, x1Stopu, argRet);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMCallArgRet::insertRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
};

void TblWzemJMCallArgRet::updateRec(
			WzemJMCallArgRet* rec
		) {
};

void TblWzemJMCallArgRet::updateRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
};

void TblWzemJMCallArgRet::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMCallArgRet::loadRecByRef(
			ubigint ref
			, WzemJMCallArgRet** rec
		) {
	return false;
};

ubigint TblWzemJMCallArgRet::loadRstByCal(
			ubigint refWzemMCall
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	return 0;
};

ubigint TblWzemJMCallArgRet::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	ubigint numload = 0;
	WzemJMCallArgRet* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMCallArgRet
 ******************************************************************************/

MyTblWzemJMCallArgRet::MyTblWzemJMCallArgRet() :
			TblWzemJMCallArgRet()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMCallArgRet::~MyTblWzemJMCallArgRet() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMCallArgRet::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMCallArgRet (refWzemMCall, x1Startu, x1Stopu, argRet) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMCallArgRet SET refWzemMCall = ?, x1Startu = ?, x1Stopu = ?, argRet = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMCallArgRet WHERE ref = ?", false);
};

bool MyTblWzemJMCallArgRet::loadRecBySQL(
			const string& sqlstr
			, WzemJMCallArgRet** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMCallArgRet* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMCallArgRet::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMCallArgRet::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemJMCallArgRet();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMCall = atoll((char*) dbrow[1]); else _rec->refWzemMCall = 0;
		if (dbrow[2]) _rec->x1Startu = atof((char*) dbrow[2]); else _rec->x1Startu = 0.0;
		if (dbrow[3]) _rec->x1Stopu = atof((char*) dbrow[3]); else _rec->x1Stopu = 0.0;
		if (dbrow[4]) _rec->argRet.assign(dbrow[4], dblengths[4]); else _rec->argRet = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMCallArgRet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMCallArgRet* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMCallArgRet::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMCallArgRet::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemJMCallArgRet();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMCall = atoll((char*) dbrow[1]); else rec->refWzemMCall = 0;
			if (dbrow[2]) rec->x1Startu = atof((char*) dbrow[2]); else rec->x1Startu = 0.0;
			if (dbrow[3]) rec->x1Stopu = atof((char*) dbrow[3]); else rec->x1Stopu = 0.0;
			if (dbrow[4]) rec->argRet.assign(dbrow[4], dblengths[4]); else rec->argRet = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMCallArgRet::insertRec(
			WzemJMCallArgRet* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->argRet.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMCall,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->argRet.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMCallArgRet::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMCallArgRet::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMCallArgRet::insertRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMCallArgRet::updateRec(
			WzemJMCallArgRet* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->argRet.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMCall,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Startu,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x1Stopu,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->argRet.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMCallArgRet::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMCallArgRet::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMCallArgRet::updateRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMCallArgRet::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMCallArgRet::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMCallArgRet::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMCallArgRet::loadRecByRef(
			ubigint ref
			, WzemJMCallArgRet** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMCallArgRet WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemJMCallArgRet::loadRstByCal(
			ubigint refWzemMCall
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMCall, x1Startu, x1Stopu, argRet FROM TblWzemJMCallArgRet WHERE refWzemMCall = " + to_string(refWzemMCall) + " ORDER BY x1Startu ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMCallArgRet
 ******************************************************************************/

PgTblWzemJMCallArgRet::PgTblWzemJMCallArgRet() :
			TblWzemJMCallArgRet()
			, PgTable()
		{
};

PgTblWzemJMCallArgRet::~PgTblWzemJMCallArgRet() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMCallArgRet::initStatements() {
	createStatement("TblWzemJMCallArgRet_insertRec", "INSERT INTO TblWzemJMCallArgRet (refWzemMCall, x1Startu, x1Stopu, argRet) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemJMCallArgRet_updateRec", "UPDATE TblWzemJMCallArgRet SET refWzemMCall = $1, x1Startu = $2, x1Stopu = $3, argRet = $4 WHERE ref = $5", 5);
	createStatement("TblWzemJMCallArgRet_removeRecByRef", "DELETE FROM TblWzemJMCallArgRet WHERE ref = $1", 1);

	createStatement("TblWzemJMCallArgRet_loadRecByRef", "SELECT ref, refWzemMCall, x1Startu, x1Stopu, argRet FROM TblWzemJMCallArgRet WHERE ref = $1", 1);
	createStatement("TblWzemJMCallArgRet_loadRstByCal", "SELECT ref, refWzemMCall, x1Startu, x1Stopu, argRet FROM TblWzemJMCallArgRet WHERE refWzemMCall = $1 ORDER BY x1Startu ASC", 1);
};

bool PgTblWzemJMCallArgRet::loadRec(
			PGresult* res
			, WzemJMCallArgRet** rec
		) {
	char* ptr;

	WzemJMCallArgRet* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMCallArgRet();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmcall"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "argret")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMCall = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->argRet.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMCallArgRet::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMCallArgRet* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmcall"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "argret")
		};

		while (numread < numrow) {
			rec = new WzemJMCallArgRet();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMCall = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->argRet.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMCallArgRet::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMCallArgRet** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMCallArgRet::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMCallArgRet::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMCallArgRet::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMCallArgRet::loadRecBySQL(
			const string& sqlstr
			, WzemJMCallArgRet** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMCallArgRet::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMCallArgRet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMCallArgRet::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMCallArgRet::insertRec(
			WzemJMCallArgRet* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMCall = htonl64(rec->refWzemMCall);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);

	const char* vals[] = {
		(char*) &_refWzemMCall,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		rec->argRet.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemJMCallArgRet_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMCallArgRet::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMCallArgRet::insertRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMCallArgRet::updateRec(
			WzemJMCallArgRet* rec
		) {
	PGresult* res;

	ubigint _refWzemMCall = htonl64(rec->refWzemMCall);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMCall,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		rec->argRet.c_str(),
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

	res = PQexecPrepared(dbs, "TblWzemJMCallArgRet_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMCallArgRet::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMCallArgRet::updateRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMCallArgRet::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMCallArgRet_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMCallArgRet::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMCallArgRet::loadRecByRef(
			ubigint ref
			, WzemJMCallArgRet** rec
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

	return loadRecByStmt("TblWzemJMCallArgRet_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemJMCallArgRet::loadRstByCal(
			ubigint refWzemMCall
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	ubigint _refWzemMCall = htonl64(refWzemMCall);

	const char* vals[] = {
		(char*) &_refWzemMCall
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMCallArgRet_loadRstByCal", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMCallArgRet
 ******************************************************************************/

LiteTblWzemJMCallArgRet::LiteTblWzemJMCallArgRet() :
			TblWzemJMCallArgRet()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByCal = NULL;
};

LiteTblWzemJMCallArgRet::~LiteTblWzemJMCallArgRet() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByCal) sqlite3_finalize(stmtLoadRstByCal);
};

void LiteTblWzemJMCallArgRet::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMCallArgRet (refWzemMCall, x1Startu, x1Stopu, argRet) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMCallArgRet SET refWzemMCall = ?1, x1Startu = ?2, x1Stopu = ?3, argRet = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMCallArgRet WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMCall, x1Startu, x1Stopu, argRet FROM TblWzemJMCallArgRet WHERE ref = ?1");
	stmtLoadRstByCal = createStatement("SELECT ref, refWzemMCall, x1Startu, x1Stopu, argRet FROM TblWzemJMCallArgRet WHERE refWzemMCall = ?1 ORDER BY x1Startu ASC");
};

bool LiteTblWzemJMCallArgRet::loadRec(
			sqlite3_stmt* stmt
			, WzemJMCallArgRet** rec
		) {
	int res;

	WzemJMCallArgRet* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMCallArgRet();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMCall = sqlite3_column_int64(stmt, 1);
		_rec->x1Startu = sqlite3_column_double(stmt, 2);
		_rec->x1Stopu = sqlite3_column_double(stmt, 3);
		_rec->argRet.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzemJMCallArgRet::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	int res; ubigint numread = 0;

	WzemJMCallArgRet* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMCallArgRet();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMCall = sqlite3_column_int64(stmt, 1);
		rec->x1Startu = sqlite3_column_double(stmt, 2);
		rec->x1Stopu = sqlite3_column_double(stmt, 3);
		rec->argRet.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMCallArgRet::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMCallArgRet** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMCallArgRet::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMCallArgRet::loadRecBySQL(
			const string& sqlstr
			, WzemJMCallArgRet** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMCallArgRet::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMCallArgRet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMCallArgRet::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMCallArgRet::insertRec(
			WzemJMCallArgRet* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMCall);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 3, rec->x1Stopu);
	sqlite3_bind_text(stmtInsertRec, 4, rec->argRet.c_str(), rec->argRet.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMCallArgRet::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMCallArgRet::insertRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMCallArgRet::updateRec(
			WzemJMCallArgRet* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMCall);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 3, rec->x1Stopu);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->argRet.c_str(), rec->argRet.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMCallArgRet::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMCallArgRet::updateRst(
			ListWzemJMCallArgRet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMCallArgRet::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMCallArgRet::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMCallArgRet::loadRecByRef(
			ubigint ref
			, WzemJMCallArgRet** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemJMCallArgRet::loadRstByCal(
			ubigint refWzemMCall
			, const bool append
			, ListWzemJMCallArgRet& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByCal, 1, refWzemMCall);

	return loadRstByStmt(stmtLoadRstByCal, append, rst);
};

#endif
