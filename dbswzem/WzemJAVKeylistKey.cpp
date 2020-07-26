/**
	* \file WzemJAVKeylistKey.cpp
	* database access for table TblWzemJAVKeylistKey (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemJAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJAVKeylistKey
 ******************************************************************************/

WzemJAVKeylistKey::WzemJAVKeylistKey(
			const ubigint ref
			, const ubigint refWzemAVKeylistKey
			, const uint x1IxWzemVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refWzemAVKeylistKey = refWzemAVKeylistKey;
	this->x1IxWzemVLocale = x1IxWzemVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool WzemJAVKeylistKey::operator==(
			const WzemJAVKeylistKey& comp
		) {
	return false;
};

bool WzemJAVKeylistKey::operator!=(
			const WzemJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJAVKeylistKey
 ******************************************************************************/

ListWzemJAVKeylistKey::ListWzemJAVKeylistKey() {
};

ListWzemJAVKeylistKey::ListWzemJAVKeylistKey(
			const ListWzemJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJAVKeylistKey(*(src.nodes[i]));
};

ListWzemJAVKeylistKey::~ListWzemJAVKeylistKey() {
	clear();
};

void ListWzemJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWzemJAVKeylistKey::append(
			WzemJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WzemJAVKeylistKey* ListWzemJAVKeylistKey::operator[](
			const uint ix
		) {
	WzemJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJAVKeylistKey& ListWzemJAVKeylistKey::operator=(
			const ListWzemJAVKeylistKey& src
		) {
	WzemJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJAVKeylistKey::operator==(
			const ListWzemJAVKeylistKey& comp
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

bool ListWzemJAVKeylistKey::operator!=(
			const ListWzemJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJAVKeylistKey
 ******************************************************************************/

TblWzemJAVKeylistKey::TblWzemJAVKeylistKey() {
};

TblWzemJAVKeylistKey::~TblWzemJAVKeylistKey() {
};

bool TblWzemJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWzemJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWzemJAVKeylistKey::insertRec(
			WzemJAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWzemJAVKeylistKey::insertNewRec(
			WzemJAVKeylistKey** rec
			, const ubigint refWzemAVKeylistKey
			, const uint x1IxWzemVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzemJAVKeylistKey* _rec = NULL;

	_rec = new WzemJAVKeylistKey(0, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJAVKeylistKey::appendNewRecToRst(
			ListWzemJAVKeylistKey& rst
			, WzemJAVKeylistKey** rec
			, const ubigint refWzemAVKeylistKey
			, const uint x1IxWzemVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzemJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJAVKeylistKey::insertRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzemJAVKeylistKey::updateRec(
			WzemJAVKeylistKey* rec
		) {
};

void TblWzemJAVKeylistKey::updateRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzemJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemJAVKeylistKey** rec
		) {
	return false;
};

bool TblWzemJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, WzemJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWzemJAVKeylistKey::loadRefsByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemJAVKeylistKey::loadRstByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	return 0;
};

bool TblWzemJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, string& Title
		) {
	return false;
};

ubigint TblWzemJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WzemJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJAVKeylistKey
 ******************************************************************************/

MyTblWzemJAVKeylistKey::MyTblWzemJAVKeylistKey() :
			TblWzemJAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJAVKeylistKey::~MyTblWzemJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJAVKeylistKey (refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJAVKeylistKey SET refWzemAVKeylistKey = ?, x1IxWzemVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWzemJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refWzemAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxWzemVLocale = atol((char*) dbrow[2]); else _rec->x1IxWzemVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemAVKeylistKey = atoll((char*) dbrow[1]); else rec->refWzemAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxWzemVLocale = atol((char*) dbrow[2]); else rec->x1IxWzemVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJAVKeylistKey::insertRec(
			WzemJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzemVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJAVKeylistKey::insertRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJAVKeylistKey::updateRec(
			WzemJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzemVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJAVKeylistKey::updateRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemJAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, WzemJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = " + to_string(refWzemAVKeylistKey) + " AND x1IxWzemVLocale = " + to_string(x1IxWzemVLocale) + "", rec);
};

ubigint MyTblWzemJAVKeylistKey::loadRefsByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = " + to_string(refWzemAVKeylistKey) + "", append, refs);
};

ubigint MyTblWzemJAVKeylistKey::loadRstByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = " + to_string(refWzemAVKeylistKey) + " ORDER BY x1IxWzemVLocale ASC", append, rst);
};

bool MyTblWzemJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = " + to_string(refWzemAVKeylistKey) + " AND x1IxWzemVLocale = " + to_string(x1IxWzemVLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJAVKeylistKey
 ******************************************************************************/

PgTblWzemJAVKeylistKey::PgTblWzemJAVKeylistKey() :
			TblWzemJAVKeylistKey()
			, PgTable()
		{
};

PgTblWzemJAVKeylistKey::~PgTblWzemJAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJAVKeylistKey::initStatements() {
	createStatement("TblWzemJAVKeylistKey_insertRec", "INSERT INTO TblWzemJAVKeylistKey (refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemJAVKeylistKey_updateRec", "UPDATE TblWzemJAVKeylistKey SET refWzemAVKeylistKey = $1, x1IxWzemVLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWzemJAVKeylistKey_removeRecByRef", "DELETE FROM TblWzemJAVKeylistKey WHERE ref = $1", 1);

	createStatement("TblWzemJAVKeylistKey_loadRecByRef", "SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE ref = $1", 1);
	createStatement("TblWzemJAVKeylistKey_loadRecByKlkLcl", "SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = $1 AND x1IxWzemVLocale = $2", 2);
	createStatement("TblWzemJAVKeylistKey_loadRefsByKlk", "SELECT ref FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = $1", 1);
	createStatement("TblWzemJAVKeylistKey_loadRstByKlk", "SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = $1 ORDER BY x1IxWzemVLocale ASC", 1);
	createStatement("TblWzemJAVKeylistKey_loadTitByKlkLcl", "SELECT Title FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = $1 AND x1IxWzemVLocale = $2", 2);
};

bool PgTblWzemJAVKeylistKey::loadRec(
			PGresult* res
			, WzemJAVKeylistKey** rec
		) {
	char* ptr;

	WzemJAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemavkeylistkey"),
			PQfnumber(res, "x1ixwzemvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemAVKeylistKey = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWzemVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemavkeylistkey"),
			PQfnumber(res, "x1ixwzemvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WzemJAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemAVKeylistKey = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWzemVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJAVKeylistKey::insertRec(
			WzemJAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemAVKeylistKey = htonl64(rec->refWzemAVKeylistKey);
	uint _x1IxWzemVLocale = htonl(rec->x1IxWzemVLocale);

	const char* vals[] = {
		(char*) &_refWzemAVKeylistKey,
		(char*) &_x1IxWzemVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemJAVKeylistKey_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJAVKeylistKey::insertRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJAVKeylistKey::updateRec(
			WzemJAVKeylistKey* rec
		) {
	PGresult* res;

	ubigint _refWzemAVKeylistKey = htonl64(rec->refWzemAVKeylistKey);
	uint _x1IxWzemVLocale = htonl(rec->x1IxWzemVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemAVKeylistKey,
		(char*) &_x1IxWzemVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemJAVKeylistKey_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJAVKeylistKey::updateRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJAVKeylistKey::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemJAVKeylistKey** rec
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

	return loadRecByStmt("TblWzemJAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, WzemJAVKeylistKey** rec
		) {
	ubigint _refWzemAVKeylistKey = htonl64(refWzemAVKeylistKey);
	uint _x1IxWzemVLocale = htonl(x1IxWzemVLocale);

	const char* vals[] = {
		(char*) &_refWzemAVKeylistKey,
		(char*) &_x1IxWzemVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWzemJAVKeylistKey_loadRecByKlkLcl", 2, vals, l, f, rec);
};

ubigint PgTblWzemJAVKeylistKey::loadRefsByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemAVKeylistKey = htonl64(refWzemAVKeylistKey);

	const char* vals[] = {
		(char*) &_refWzemAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemJAVKeylistKey_loadRefsByKlk", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemJAVKeylistKey::loadRstByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	ubigint _refWzemAVKeylistKey = htonl64(refWzemAVKeylistKey);

	const char* vals[] = {
		(char*) &_refWzemAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJAVKeylistKey_loadRstByKlk", 1, vals, l, f, append, rst);
};

bool PgTblWzemJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, string& Title
		) {
	ubigint _refWzemAVKeylistKey = htonl64(refWzemAVKeylistKey);
	uint _x1IxWzemVLocale = htonl(x1IxWzemVLocale);

	const char* vals[] = {
		(char*) &_refWzemAVKeylistKey,
		(char*) &_x1IxWzemVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWzemJAVKeylistKey_loadTitByKlkLcl", 2, vals, l, f, Title);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJAVKeylistKey
 ******************************************************************************/

LiteTblWzemJAVKeylistKey::LiteTblWzemJAVKeylistKey() :
			TblWzemJAVKeylistKey()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByKlkLcl = NULL;
	stmtLoadRefsByKlk = NULL;
	stmtLoadRstByKlk = NULL;
	stmtLoadTitByKlkLcl = NULL;
};

LiteTblWzemJAVKeylistKey::~LiteTblWzemJAVKeylistKey() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByKlkLcl) sqlite3_finalize(stmtLoadRecByKlkLcl);
	if (stmtLoadRefsByKlk) sqlite3_finalize(stmtLoadRefsByKlk);
	if (stmtLoadRstByKlk) sqlite3_finalize(stmtLoadRstByKlk);
	if (stmtLoadTitByKlkLcl) sqlite3_finalize(stmtLoadTitByKlkLcl);
};

void LiteTblWzemJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJAVKeylistKey (refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJAVKeylistKey SET refWzemAVKeylistKey = ?1, x1IxWzemVLocale = ?2, Title = ?3, Comment = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJAVKeylistKey WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE ref = ?1");
	stmtLoadRecByKlkLcl = createStatement("SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = ?1 AND x1IxWzemVLocale = ?2");
	stmtLoadRefsByKlk = createStatement("SELECT ref FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = ?1");
	stmtLoadRstByKlk = createStatement("SELECT ref, refWzemAVKeylistKey, x1IxWzemVLocale, Title, Comment FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = ?1 ORDER BY x1IxWzemVLocale ASC");
	stmtLoadTitByKlkLcl = createStatement("SELECT Title FROM TblWzemJAVKeylistKey WHERE refWzemAVKeylistKey = ?1 AND x1IxWzemVLocale = ?2");
};

bool LiteTblWzemJAVKeylistKey::loadRec(
			sqlite3_stmt* stmt
			, WzemJAVKeylistKey** rec
		) {
	int res;

	WzemJAVKeylistKey* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJAVKeylistKey();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemAVKeylistKey = sqlite3_column_int64(stmt, 1);
		_rec->x1IxWzemVLocale = sqlite3_column_int(stmt, 2);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzemJAVKeylistKey::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	int res; ubigint numread = 0;

	WzemJAVKeylistKey* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJAVKeylistKey();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemAVKeylistKey = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzemVLocale = sqlite3_column_int(stmt, 2);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJAVKeylistKey::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJAVKeylistKey** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJAVKeylistKey::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemJAVKeylistKey** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJAVKeylistKey::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJAVKeylistKey::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJAVKeylistKey::insertRec(
			WzemJAVKeylistKey* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemAVKeylistKey);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzemVLocale);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJAVKeylistKey::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJAVKeylistKey::insertRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJAVKeylistKey::updateRec(
			WzemJAVKeylistKey* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemAVKeylistKey);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzemVLocale);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJAVKeylistKey::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJAVKeylistKey::updateRst(
			ListWzemJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJAVKeylistKey::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemJAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, WzemJAVKeylistKey** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByKlkLcl, 1, refWzemAVKeylistKey);
	sqlite3_bind_int(stmtLoadRecByKlkLcl, 2, x1IxWzemVLocale);

	return loadRecByStmt(stmtLoadRecByKlkLcl, rec);
};

ubigint LiteTblWzemJAVKeylistKey::loadRefsByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByKlk, 1, refWzemAVKeylistKey);

	return loadRefsByStmt(stmtLoadRefsByKlk, append, refs);
};

ubigint LiteTblWzemJAVKeylistKey::loadRstByKlk(
			ubigint refWzemAVKeylistKey
			, const bool append
			, ListWzemJAVKeylistKey& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByKlk, 1, refWzemAVKeylistKey);

	return loadRstByStmt(stmtLoadRstByKlk, append, rst);
};

bool LiteTblWzemJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWzemAVKeylistKey
			, uint x1IxWzemVLocale
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByKlkLcl, 1, refWzemAVKeylistKey);
	sqlite3_bind_int(stmtLoadTitByKlkLcl, 2, x1IxWzemVLocale);

	return loadStringByStmt(stmtLoadTitByKlkLcl, Title);
};

#endif

