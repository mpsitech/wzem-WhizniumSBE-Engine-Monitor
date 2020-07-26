/**
	* \file WzemMDpch.cpp
	* database access for table TblWzemMDpch (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemMDpch.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMDpch
 ******************************************************************************/

WzemMDpch::WzemMDpch(
			const ubigint ref
			, const ubigint refWzemMEvent
			, const string srefIxVDpch
			, const string srefsMask
			, const string Content
		) {

	this->ref = ref;
	this->refWzemMEvent = refWzemMEvent;
	this->srefIxVDpch = srefIxVDpch;
	this->srefsMask = srefsMask;
	this->Content = Content;
};

bool WzemMDpch::operator==(
			const WzemMDpch& comp
		) {
	return false;
};

bool WzemMDpch::operator!=(
			const WzemMDpch& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMDpch
 ******************************************************************************/

ListWzemMDpch::ListWzemMDpch() {
};

ListWzemMDpch::ListWzemMDpch(
			const ListWzemMDpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMDpch(*(src.nodes[i]));
};

ListWzemMDpch::~ListWzemMDpch() {
	clear();
};

void ListWzemMDpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMDpch::size() const {
	return(nodes.size());
};

void ListWzemMDpch::append(
			WzemMDpch* rec
		) {
	nodes.push_back(rec);
};

WzemMDpch* ListWzemMDpch::operator[](
			const uint ix
		) {
	WzemMDpch* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMDpch& ListWzemMDpch::operator=(
			const ListWzemMDpch& src
		) {
	WzemMDpch* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMDpch(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMDpch::operator==(
			const ListWzemMDpch& comp
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

bool ListWzemMDpch::operator!=(
			const ListWzemMDpch& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMDpch
 ******************************************************************************/

TblWzemMDpch::TblWzemMDpch() {
};

TblWzemMDpch::~TblWzemMDpch() {
};

bool TblWzemMDpch::loadRecBySQL(
			const string& sqlstr
			, WzemMDpch** rec
		) {
	return false;
};

ubigint TblWzemMDpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMDpch& rst
		) {
	return 0;
};

ubigint TblWzemMDpch::insertRec(
			WzemMDpch* rec
		) {
	return 0;
};

ubigint TblWzemMDpch::insertNewRec(
			WzemMDpch** rec
			, const ubigint refWzemMEvent
			, const string srefIxVDpch
			, const string srefsMask
			, const string Content
		) {
	ubigint retval = 0;
	WzemMDpch* _rec = NULL;

	_rec = new WzemMDpch(0, refWzemMEvent, srefIxVDpch, srefsMask, Content);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMDpch::appendNewRecToRst(
			ListWzemMDpch& rst
			, WzemMDpch** rec
			, const ubigint refWzemMEvent
			, const string srefIxVDpch
			, const string srefsMask
			, const string Content
		) {
	ubigint retval = 0;
	WzemMDpch* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMEvent, srefIxVDpch, srefsMask, Content);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMDpch::insertRst(
			ListWzemMDpch& rst
			, bool transact
		) {
};

void TblWzemMDpch::updateRec(
			WzemMDpch* rec
		) {
};

void TblWzemMDpch::updateRst(
			ListWzemMDpch& rst
			, bool transact
		) {
};

void TblWzemMDpch::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMDpch::loadRecByRef(
			ubigint ref
			, WzemMDpch** rec
		) {
	return false;
};

bool TblWzemMDpch::loadDchByRef(
			ubigint ref
			, string& srefIxVDpch
		) {
	return false;
};

bool TblWzemMDpch::loadRecByEvt(
			ubigint refWzemMEvent
			, WzemMDpch** rec
		) {
	return false;
};

ubigint TblWzemMDpch::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMDpch& rst
		) {
	ubigint numload = 0;
	WzemMDpch* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMDpch
 ******************************************************************************/

MyTblWzemMDpch::MyTblWzemMDpch() :
			TblWzemMDpch()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMDpch::~MyTblWzemMDpch() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMDpch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMDpch (refWzemMEvent, srefIxVDpch, srefsMask, Content) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMDpch SET refWzemMEvent = ?, srefIxVDpch = ?, srefsMask = ?, Content = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMDpch WHERE ref = ?", false);
};

bool MyTblWzemMDpch::loadRecBySQL(
			const string& sqlstr
			, WzemMDpch** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMDpch* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMDpch::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMDpch::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMDpch();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMEvent = atoll((char*) dbrow[1]); else _rec->refWzemMEvent = 0;
		if (dbrow[2]) _rec->srefIxVDpch.assign(dbrow[2], dblengths[2]); else _rec->srefIxVDpch = "";
		if (dbrow[3]) _rec->srefsMask.assign(dbrow[3], dblengths[3]); else _rec->srefsMask = "";
		if (dbrow[4]) _rec->Content.assign(dbrow[4], dblengths[4]); else _rec->Content = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMDpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMDpch& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMDpch* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMDpch::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMDpch::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMDpch();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMEvent = atoll((char*) dbrow[1]); else rec->refWzemMEvent = 0;
			if (dbrow[2]) rec->srefIxVDpch.assign(dbrow[2], dblengths[2]); else rec->srefIxVDpch = "";
			if (dbrow[3]) rec->srefsMask.assign(dbrow[3], dblengths[3]); else rec->srefsMask = "";
			if (dbrow[4]) rec->Content.assign(dbrow[4], dblengths[4]); else rec->Content = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMDpch::insertRec(
			WzemMDpch* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->srefIxVDpch.length();
	l[2] = rec->srefsMask.length();
	l[3] = rec->Content.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMEvent,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->srefIxVDpch.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Content.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMDpch::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMDpch::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMDpch::insertRst(
			ListWzemMDpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMDpch::updateRec(
			WzemMDpch* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->srefIxVDpch.length();
	l[2] = rec->srefsMask.length();
	l[3] = rec->Content.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMEvent,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->srefIxVDpch.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefsMask.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Content.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMDpch::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMDpch::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMDpch::updateRst(
			ListWzemMDpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMDpch::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMDpch::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMDpch::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMDpch::loadRecByRef(
			ubigint ref
			, WzemMDpch** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMDpch WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemMDpch::loadDchByRef(
			ubigint ref
			, string& srefIxVDpch
		) {
	return loadStringBySQL("SELECT srefIxVDpch FROM TblWzemMDpch WHERE ref = " + to_string(ref) + "", srefIxVDpch);
};

bool MyTblWzemMDpch::loadRecByEvt(
			ubigint refWzemMEvent
			, WzemMDpch** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemMEvent, srefIxVDpch, srefsMask, Content FROM TblWzemMDpch WHERE refWzemMEvent = " + to_string(refWzemMEvent) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMDpch
 ******************************************************************************/

PgTblWzemMDpch::PgTblWzemMDpch() :
			TblWzemMDpch()
			, PgTable()
		{
};

PgTblWzemMDpch::~PgTblWzemMDpch() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMDpch::initStatements() {
	createStatement("TblWzemMDpch_insertRec", "INSERT INTO TblWzemMDpch (refWzemMEvent, srefIxVDpch, srefsMask, Content) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemMDpch_updateRec", "UPDATE TblWzemMDpch SET refWzemMEvent = $1, srefIxVDpch = $2, srefsMask = $3, Content = $4 WHERE ref = $5", 5);
	createStatement("TblWzemMDpch_removeRecByRef", "DELETE FROM TblWzemMDpch WHERE ref = $1", 1);

	createStatement("TblWzemMDpch_loadRecByRef", "SELECT ref, refWzemMEvent, srefIxVDpch, srefsMask, Content FROM TblWzemMDpch WHERE ref = $1", 1);
	createStatement("TblWzemMDpch_loadDchByRef", "SELECT srefIxVDpch FROM TblWzemMDpch WHERE ref = $1", 1);
	createStatement("TblWzemMDpch_loadRecByEvt", "SELECT ref, refWzemMEvent, srefIxVDpch, srefsMask, Content FROM TblWzemMDpch WHERE refWzemMEvent = $1", 1);
};

bool PgTblWzemMDpch::loadRec(
			PGresult* res
			, WzemMDpch** rec
		) {
	char* ptr;

	WzemMDpch* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMDpch();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmevent"),
			PQfnumber(res, "srefixvdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "content")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMEvent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->srefIxVDpch.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefsMask.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Content.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMDpch::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMDpch& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMDpch* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmevent"),
			PQfnumber(res, "srefixvdpch"),
			PQfnumber(res, "srefsmask"),
			PQfnumber(res, "content")
		};

		while (numread < numrow) {
			rec = new WzemMDpch();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMEvent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->srefIxVDpch.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefsMask.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Content.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMDpch::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMDpch** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMDpch::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWzemMDpch::loadRecBySQL(
			const string& sqlstr
			, WzemMDpch** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMDpch::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMDpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMDpch& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMDpch::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMDpch::insertRec(
			WzemMDpch* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMEvent = htonl64(rec->refWzemMEvent);

	const char* vals[] = {
		(char*) &_refWzemMEvent,
		rec->srefIxVDpch.c_str(),
		rec->srefsMask.c_str(),
		rec->Content.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemMDpch_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMDpch::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMDpch::insertRst(
			ListWzemMDpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMDpch::updateRec(
			WzemMDpch* rec
		) {
	PGresult* res;

	ubigint _refWzemMEvent = htonl64(rec->refWzemMEvent);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMEvent,
		rec->srefIxVDpch.c_str(),
		rec->srefsMask.c_str(),
		rec->Content.c_str(),
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

	res = PQexecPrepared(dbs, "TblWzemMDpch_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMDpch::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMDpch::updateRst(
			ListWzemMDpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMDpch::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMDpch_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMDpch::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMDpch::loadRecByRef(
			ubigint ref
			, WzemMDpch** rec
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

	return loadRecByStmt("TblWzemMDpch_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemMDpch::loadDchByRef(
			ubigint ref
			, string& srefIxVDpch
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWzemMDpch_loadDchByRef", 1, vals, l, f, srefIxVDpch);
};

bool PgTblWzemMDpch::loadRecByEvt(
			ubigint refWzemMEvent
			, WzemMDpch** rec
		) {
	ubigint _refWzemMEvent = htonl64(refWzemMEvent);

	const char* vals[] = {
		(char*) &_refWzemMEvent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWzemMDpch_loadRecByEvt", 1, vals, l, f, rec);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMDpch
 ******************************************************************************/

LiteTblWzemMDpch::LiteTblWzemMDpch() :
			TblWzemMDpch()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadDchByRef = NULL;
	stmtLoadRecByEvt = NULL;
};

LiteTblWzemMDpch::~LiteTblWzemMDpch() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadDchByRef) sqlite3_finalize(stmtLoadDchByRef);
	if (stmtLoadRecByEvt) sqlite3_finalize(stmtLoadRecByEvt);
};

void LiteTblWzemMDpch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMDpch (refWzemMEvent, srefIxVDpch, srefsMask, Content) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMDpch SET refWzemMEvent = ?1, srefIxVDpch = ?2, srefsMask = ?3, Content = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMDpch WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMEvent, srefIxVDpch, srefsMask, Content FROM TblWzemMDpch WHERE ref = ?1");
	stmtLoadDchByRef = createStatement("SELECT srefIxVDpch FROM TblWzemMDpch WHERE ref = ?1");
	stmtLoadRecByEvt = createStatement("SELECT ref, refWzemMEvent, srefIxVDpch, srefsMask, Content FROM TblWzemMDpch WHERE refWzemMEvent = ?1");
};

bool LiteTblWzemMDpch::loadRec(
			sqlite3_stmt* stmt
			, WzemMDpch** rec
		) {
	int res;

	WzemMDpch* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMDpch();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMEvent = sqlite3_column_int64(stmt, 1);
		_rec->srefIxVDpch.assign((const char*) sqlite3_column_text(stmt, 2));
		_rec->srefsMask.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->Content.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzemMDpch::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMDpch& rst
		) {
	int res; ubigint numread = 0;

	WzemMDpch* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMDpch();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMEvent = sqlite3_column_int64(stmt, 1);
		rec->srefIxVDpch.assign((const char*) sqlite3_column_text(stmt, 2));
		rec->srefsMask.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->Content.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMDpch::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMDpch** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMDpch::loadRecBySQL(
			const string& sqlstr
			, WzemMDpch** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMDpch::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMDpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMDpch& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMDpch::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMDpch::insertRec(
			WzemMDpch* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMEvent);
	sqlite3_bind_text(stmtInsertRec, 2, rec->srefIxVDpch.c_str(), rec->srefIxVDpch.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 3, rec->srefsMask.c_str(), rec->srefsMask.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Content.c_str(), rec->Content.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMDpch::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMDpch::insertRst(
			ListWzemMDpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMDpch::updateRec(
			WzemMDpch* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMEvent);
	sqlite3_bind_text(stmtUpdateRec, 2, rec->srefIxVDpch.c_str(), rec->srefIxVDpch.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->srefsMask.c_str(), rec->srefsMask.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Content.c_str(), rec->Content.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMDpch::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMDpch::updateRst(
			ListWzemMDpch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMDpch::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMDpch::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMDpch::loadRecByRef(
			ubigint ref
			, WzemMDpch** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemMDpch::loadDchByRef(
			ubigint ref
			, string& srefIxVDpch
		) {
	sqlite3_bind_int64(stmtLoadDchByRef, 1, ref);

	return loadStringByStmt(stmtLoadDchByRef, srefIxVDpch);
};

bool LiteTblWzemMDpch::loadRecByEvt(
			ubigint refWzemMEvent
			, WzemMDpch** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByEvt, 1, refWzemMEvent);

	return loadRecByStmt(stmtLoadRecByEvt, rec);
};

#endif

