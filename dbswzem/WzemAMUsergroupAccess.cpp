/**
	* \file WzemAMUsergroupAccess.cpp
	* database access for table TblWzemAMUsergroupAccess (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemAMUsergroupAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAMUsergroupAccess
 ******************************************************************************/

WzemAMUsergroupAccess::WzemAMUsergroupAccess(
			const ubigint ref
			, const ubigint refWzemMUsergroup
			, const uint x1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
		) {

	this->ref = ref;
	this->refWzemMUsergroup = refWzemMUsergroup;
	this->x1IxWzemVFeatgroup = x1IxWzemVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzemWAccess = ixWzemWAccess;
};

bool WzemAMUsergroupAccess::operator==(
			const WzemAMUsergroupAccess& comp
		) {
	return false;
};

bool WzemAMUsergroupAccess::operator!=(
			const WzemAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAMUsergroupAccess
 ******************************************************************************/

ListWzemAMUsergroupAccess::ListWzemAMUsergroupAccess() {
};

ListWzemAMUsergroupAccess::ListWzemAMUsergroupAccess(
			const ListWzemAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAMUsergroupAccess(*(src.nodes[i]));
};

ListWzemAMUsergroupAccess::~ListWzemAMUsergroupAccess() {
	clear();
};

void ListWzemAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListWzemAMUsergroupAccess::append(
			WzemAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

WzemAMUsergroupAccess* ListWzemAMUsergroupAccess::operator[](
			const uint ix
		) {
	WzemAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAMUsergroupAccess& ListWzemAMUsergroupAccess::operator=(
			const ListWzemAMUsergroupAccess& src
		) {
	WzemAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAMUsergroupAccess::operator==(
			const ListWzemAMUsergroupAccess& comp
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

bool ListWzemAMUsergroupAccess::operator!=(
			const ListWzemAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAMUsergroupAccess
 ******************************************************************************/

TblWzemAMUsergroupAccess::TblWzemAMUsergroupAccess() {
};

TblWzemAMUsergroupAccess::~TblWzemAMUsergroupAccess() {
};

bool TblWzemAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWzemAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWzemAMUsergroupAccess::insertRec(
			WzemAMUsergroupAccess* rec
		) {
	return 0;
};

ubigint TblWzemAMUsergroupAccess::insertNewRec(
			WzemAMUsergroupAccess** rec
			, const ubigint refWzemMUsergroup
			, const uint x1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
		) {
	ubigint retval = 0;
	WzemAMUsergroupAccess* _rec = NULL;

	_rec = new WzemAMUsergroupAccess(0, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAMUsergroupAccess::appendNewRecToRst(
			ListWzemAMUsergroupAccess& rst
			, WzemAMUsergroupAccess** rec
			, const ubigint refWzemMUsergroup
			, const uint x1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
		) {
	ubigint retval = 0;
	WzemAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAMUsergroupAccess::insertRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWzemAMUsergroupAccess::updateRec(
			WzemAMUsergroupAccess* rec
		) {
};

void TblWzemAMUsergroupAccess::updateRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWzemAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzemAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWzemAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemAMUsergroupAccess::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWzemAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	WzemAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAMUsergroupAccess
 ******************************************************************************/

MyTblWzemAMUsergroupAccess::MyTblWzemAMUsergroupAccess() :
			TblWzemAMUsergroupAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAMUsergroupAccess::~MyTblWzemAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAMUsergroupAccess (refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAMUsergroupAccess SET refWzemMUsergroup = ?, x1IxWzemVFeatgroup = ?, x2FeaSrefUix = ?, ixWzemWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblWzemAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAMUsergroupAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAMUsergroupAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUsergroup = atoll((char*) dbrow[1]); else _rec->refWzemMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxWzemVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWzemVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWzemWAccess = atol((char*) dbrow[4]); else _rec->ixWzemWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAMUsergroupAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAMUsergroupAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUsergroup = atoll((char*) dbrow[1]); else rec->refWzemMUsergroup = 0;
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

ubigint MyTblWzemAMUsergroupAccess::insertRec(
			WzemAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzemVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAMUsergroupAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAMUsergroupAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAMUsergroupAccess::insertRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAMUsergroupAccess::updateRec(
			WzemAMUsergroupAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWzemVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAMUsergroupAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAMUsergroupAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAMUsergroupAccess::updateRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAMUsergroupAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAMUsergroupAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzemAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = " + to_string(refWzemMUsergroup) + "", append, refs);
};

ubigint MyTblWzemAMUsergroupAccess::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = " + to_string(refWzemMUsergroup) + " ORDER BY x1IxWzemVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAMUsergroupAccess
 ******************************************************************************/

PgTblWzemAMUsergroupAccess::PgTblWzemAMUsergroupAccess() :
			TblWzemAMUsergroupAccess()
			, PgTable()
		{
};

PgTblWzemAMUsergroupAccess::~PgTblWzemAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAMUsergroupAccess::initStatements() {
	createStatement("TblWzemAMUsergroupAccess_insertRec", "INSERT INTO TblWzemAMUsergroupAccess (refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemAMUsergroupAccess_updateRec", "UPDATE TblWzemAMUsergroupAccess SET refWzemMUsergroup = $1, x1IxWzemVFeatgroup = $2, x2FeaSrefUix = $3, ixWzemWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblWzemAMUsergroupAccess_removeRecByRef", "DELETE FROM TblWzemAMUsergroupAccess WHERE ref = $1", 1);

	createStatement("TblWzemAMUsergroupAccess_loadRecByRef", "SELECT ref, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUsergroupAccess WHERE ref = $1", 1);
	createStatement("TblWzemAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = $1", 1);
	createStatement("TblWzemAMUsergroupAccess_loadRstByUsg", "SELECT ref, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = $1 ORDER BY x1IxWzemVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblWzemAMUsergroupAccess::loadRec(
			PGresult* res
			, WzemAMUsergroupAccess** rec
		) {
	char* ptr;

	WzemAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "x1ixwzemvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwzemwaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWzemVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWzemWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "x1ixwzemvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwzemwaccess")
		};

		while (numread < numrow) {
			rec = new WzemAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUsergroup = atoll(ptr);
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

bool PgTblWzemAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAMUsergroupAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAMUsergroupAccess::insertRec(
			WzemAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _x1IxWzemVFeatgroup = htonl(rec->x1IxWzemVFeatgroup);
	uint _ixWzemWAccess = htonl(rec->ixWzemWAccess);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWzemAMUsergroupAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAMUsergroupAccess::insertRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAMUsergroupAccess::updateRec(
			WzemAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _x1IxWzemVFeatgroup = htonl(rec->x1IxWzemVFeatgroup);
	uint _ixWzemWAccess = htonl(rec->ixWzemWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWzemAMUsergroupAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAMUsergroupAccess::updateRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAMUsergroupAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzemAMUsergroupAccess** rec
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

	return loadRecByStmt("TblWzemAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemMUsergroup = htonl64(refWzemMUsergroup);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemAMUsergroupAccess::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	ubigint _refWzemMUsergroup = htonl64(refWzemMUsergroup);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemAMUsergroupAccess_loadRstByUsg", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAMUsergroupAccess
 ******************************************************************************/

LiteTblWzemAMUsergroupAccess::LiteTblWzemAMUsergroupAccess() :
			TblWzemAMUsergroupAccess()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByUsg = NULL;
	stmtLoadRstByUsg = NULL;
};

LiteTblWzemAMUsergroupAccess::~LiteTblWzemAMUsergroupAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByUsg) sqlite3_finalize(stmtLoadRefsByUsg);
	if (stmtLoadRstByUsg) sqlite3_finalize(stmtLoadRstByUsg);
};

void LiteTblWzemAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAMUsergroupAccess (refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAMUsergroupAccess SET refWzemMUsergroup = ?1, x1IxWzemVFeatgroup = ?2, x2FeaSrefUix = ?3, ixWzemWAccess = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAMUsergroupAccess WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUsergroupAccess WHERE ref = ?1");
	stmtLoadRefsByUsg = createStatement("SELECT ref FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = ?1");
	stmtLoadRstByUsg = createStatement("SELECT ref, refWzemMUsergroup, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = ?1 ORDER BY x1IxWzemVFeatgroup ASC, x2FeaSrefUix ASC");
};

bool LiteTblWzemAMUsergroupAccess::loadRec(
			sqlite3_stmt* stmt
			, WzemAMUsergroupAccess** rec
		) {
	int res;

	WzemAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAMUsergroupAccess();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 1);
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

ubigint LiteTblWzemAMUsergroupAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	int res; ubigint numread = 0;

	WzemAMUsergroupAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAMUsergroupAccess();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 1);
		rec->x1IxWzemVFeatgroup = sqlite3_column_int(stmt, 2);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 3));
		rec->ixWzemWAccess = sqlite3_column_int(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAMUsergroupAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAMUsergroupAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemAMUsergroupAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WzemAMUsergroupAccess** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAMUsergroupAccess::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAMUsergroupAccess::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAMUsergroupAccess::insertRec(
			WzemAMUsergroupAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1IxWzemVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzemWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMUsergroupAccess::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAMUsergroupAccess::insertRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAMUsergroupAccess::updateRec(
			WzemAMUsergroupAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1IxWzemVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzemWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMUsergroupAccess::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAMUsergroupAccess::updateRst(
			ListWzemAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAMUsergroupAccess::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WzemAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemAMUsergroupAccess::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsg, 1, refWzemMUsergroup);

	return loadRefsByStmt(stmtLoadRefsByUsg, append, refs);
};

ubigint LiteTblWzemAMUsergroupAccess::loadRstByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, ListWzemAMUsergroupAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsg, 1, refWzemMUsergroup);

	return loadRstByStmt(stmtLoadRstByUsg, append, rst);
};

#endif

