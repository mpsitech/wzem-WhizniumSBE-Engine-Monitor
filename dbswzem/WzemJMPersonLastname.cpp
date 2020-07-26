/**
	* \file WzemJMPersonLastname.cpp
	* database access for table TblWzemJMPersonLastname (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemJMPersonLastname.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemJMPersonLastname
 ******************************************************************************/

WzemJMPersonLastname::WzemJMPersonLastname(
			const ubigint ref
			, const ubigint refWzemMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refWzemMPerson = refWzemMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool WzemJMPersonLastname::operator==(
			const WzemJMPersonLastname& comp
		) {
	return false;
};

bool WzemJMPersonLastname::operator!=(
			const WzemJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemJMPersonLastname
 ******************************************************************************/

ListWzemJMPersonLastname::ListWzemJMPersonLastname() {
};

ListWzemJMPersonLastname::ListWzemJMPersonLastname(
			const ListWzemJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemJMPersonLastname(*(src.nodes[i]));
};

ListWzemJMPersonLastname::~ListWzemJMPersonLastname() {
	clear();
};

void ListWzemJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemJMPersonLastname::size() const {
	return(nodes.size());
};

void ListWzemJMPersonLastname::append(
			WzemJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

WzemJMPersonLastname* ListWzemJMPersonLastname::operator[](
			const uint ix
		) {
	WzemJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemJMPersonLastname& ListWzemJMPersonLastname::operator=(
			const ListWzemJMPersonLastname& src
		) {
	WzemJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemJMPersonLastname::operator==(
			const ListWzemJMPersonLastname& comp
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

bool ListWzemJMPersonLastname::operator!=(
			const ListWzemJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemJMPersonLastname
 ******************************************************************************/

TblWzemJMPersonLastname::TblWzemJMPersonLastname() {
};

TblWzemJMPersonLastname::~TblWzemJMPersonLastname() {
};

bool TblWzemJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzemJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWzemJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWzemJMPersonLastname::insertRec(
			WzemJMPersonLastname* rec
		) {
	return 0;
};

ubigint TblWzemJMPersonLastname::insertNewRec(
			WzemJMPersonLastname** rec
			, const ubigint refWzemMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WzemJMPersonLastname* _rec = NULL;

	_rec = new WzemJMPersonLastname(0, refWzemMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemJMPersonLastname::appendNewRecToRst(
			ListWzemJMPersonLastname& rst
			, WzemJMPersonLastname** rec
			, const ubigint refWzemMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WzemJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemJMPersonLastname::insertRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
};

void TblWzemJMPersonLastname::updateRec(
			WzemJMPersonLastname* rec
		) {
};

void TblWzemJMPersonLastname::updateRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
};

void TblWzemJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzemJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWzemJMPersonLastname::loadRefsByPrs(
			ubigint refWzemMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemJMPersonLastname::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWzemJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	ubigint numload = 0;
	WzemJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemJMPersonLastname
 ******************************************************************************/

MyTblWzemJMPersonLastname::MyTblWzemJMPersonLastname() :
			TblWzemJMPersonLastname()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemJMPersonLastname::~MyTblWzemJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMPersonLastname (refWzemMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemJMPersonLastname SET refWzemMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMPersonLastname WHERE ref = ?", false);
};

bool MyTblWzemJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzemJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMPersonLastname::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMPersonLastname::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMPerson = atoll((char*) dbrow[1]); else _rec->refWzemMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemJMPersonLastname::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemJMPersonLastname::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMPerson = atoll((char*) dbrow[1]); else rec->refWzemMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemJMPersonLastname::insertRec(
			WzemJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemJMPersonLastname::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemJMPersonLastname::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemJMPersonLastname::insertRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemJMPersonLastname::updateRec(
			WzemJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemJMPersonLastname::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemJMPersonLastname::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemJMPersonLastname::updateRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemJMPersonLastname::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemJMPersonLastname::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzemJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemJMPersonLastname::loadRefsByPrs(
			ubigint refWzemMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemJMPersonLastname WHERE refWzemMPerson = " + to_string(refWzemMPerson) + "", append, refs);
};

ubigint MyTblWzemJMPersonLastname::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMPerson, x1Startd, Lastname FROM TblWzemJMPersonLastname WHERE refWzemMPerson = " + to_string(refWzemMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemJMPersonLastname
 ******************************************************************************/

PgTblWzemJMPersonLastname::PgTblWzemJMPersonLastname() :
			TblWzemJMPersonLastname()
			, PgTable()
		{
};

PgTblWzemJMPersonLastname::~PgTblWzemJMPersonLastname() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemJMPersonLastname::initStatements() {
	createStatement("TblWzemJMPersonLastname_insertRec", "INSERT INTO TblWzemJMPersonLastname (refWzemMPerson, x1Startd, Lastname) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWzemJMPersonLastname_updateRec", "UPDATE TblWzemJMPersonLastname SET refWzemMPerson = $1, x1Startd = $2, Lastname = $3 WHERE ref = $4", 4);
	createStatement("TblWzemJMPersonLastname_removeRecByRef", "DELETE FROM TblWzemJMPersonLastname WHERE ref = $1", 1);

	createStatement("TblWzemJMPersonLastname_loadRecByRef", "SELECT ref, refWzemMPerson, x1Startd, Lastname FROM TblWzemJMPersonLastname WHERE ref = $1", 1);
	createStatement("TblWzemJMPersonLastname_loadRefsByPrs", "SELECT ref FROM TblWzemJMPersonLastname WHERE refWzemMPerson = $1", 1);
	createStatement("TblWzemJMPersonLastname_loadRstByPrs", "SELECT ref, refWzemMPerson, x1Startd, Lastname FROM TblWzemJMPersonLastname WHERE refWzemMPerson = $1 ORDER BY x1Startd ASC", 1);
};

bool PgTblWzemJMPersonLastname::loadRec(
			PGresult* res
			, WzemJMPersonLastname** rec
		) {
	char* ptr;

	WzemJMPersonLastname* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemJMPersonLastname();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemJMPersonLastname::loadRst(
			PGresult* res
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemJMPersonLastname* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		while (numread < numrow) {
			rec = new WzemJMPersonLastname();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemJMPersonLastname::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPersonLastname::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMPersonLastname::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPersonLastname::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzemJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPersonLastname::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPersonLastname::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemJMPersonLastname::insertRec(
			WzemJMPersonLastname* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refWzemMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWzemJMPersonLastname_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemJMPersonLastname::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemJMPersonLastname::insertRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemJMPersonLastname::updateRec(
			WzemJMPersonLastname* rec
		) {
	PGresult* res;

	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemJMPersonLastname_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMPersonLastname::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemJMPersonLastname::updateRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemJMPersonLastname::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemJMPersonLastname_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemJMPersonLastname::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzemJMPersonLastname** rec
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

	return loadRecByStmt("TblWzemJMPersonLastname_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemJMPersonLastname::loadRefsByPrs(
			ubigint refWzemMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemMPerson = htonl64(refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemJMPersonLastname_loadRefsByPrs", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemJMPersonLastname::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	ubigint _refWzemMPerson = htonl64(refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemJMPersonLastname_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemJMPersonLastname
 ******************************************************************************/

LiteTblWzemJMPersonLastname::LiteTblWzemJMPersonLastname() :
			TblWzemJMPersonLastname()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefsByPrs = NULL;
	stmtLoadRstByPrs = NULL;
};

LiteTblWzemJMPersonLastname::~LiteTblWzemJMPersonLastname() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefsByPrs) sqlite3_finalize(stmtLoadRefsByPrs);
	if (stmtLoadRstByPrs) sqlite3_finalize(stmtLoadRstByPrs);
};

void LiteTblWzemJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemJMPersonLastname (refWzemMPerson, x1Startd, Lastname) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzemJMPersonLastname SET refWzemMPerson = ?1, x1Startd = ?2, Lastname = ?3 WHERE ref = ?4");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemJMPersonLastname WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMPerson, x1Startd, Lastname FROM TblWzemJMPersonLastname WHERE ref = ?1");
	stmtLoadRefsByPrs = createStatement("SELECT ref FROM TblWzemJMPersonLastname WHERE refWzemMPerson = ?1");
	stmtLoadRstByPrs = createStatement("SELECT ref, refWzemMPerson, x1Startd, Lastname FROM TblWzemJMPersonLastname WHERE refWzemMPerson = ?1 ORDER BY x1Startd ASC");
};

bool LiteTblWzemJMPersonLastname::loadRec(
			sqlite3_stmt* stmt
			, WzemJMPersonLastname** rec
		) {
	int res;

	WzemJMPersonLastname* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemJMPersonLastname();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMPerson = sqlite3_column_int64(stmt, 1);
		_rec->x1Startd = sqlite3_column_int(stmt, 2);
		_rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 3));

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

ubigint LiteTblWzemJMPersonLastname::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	int res; ubigint numread = 0;

	WzemJMPersonLastname* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemJMPersonLastname();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMPerson = sqlite3_column_int64(stmt, 1);
		rec->x1Startd = sqlite3_column_int(stmt, 2);
		rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 3));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemJMPersonLastname::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemJMPersonLastname** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemJMPersonLastname::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WzemJMPersonLastname** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMPersonLastname::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemJMPersonLastname::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemJMPersonLastname::insertRec(
			WzemJMPersonLastname* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMPerson);
	sqlite3_bind_int(stmtInsertRec, 2, rec->x1Startd);
	sqlite3_bind_text(stmtInsertRec, 3, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMPersonLastname::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemJMPersonLastname::insertRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemJMPersonLastname::updateRec(
			WzemJMPersonLastname* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMPerson);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->x1Startd);
	sqlite3_bind_text(stmtUpdateRec, 3, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMPersonLastname::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemJMPersonLastname::updateRst(
			ListWzemJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemJMPersonLastname::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemJMPersonLastname::loadRecByRef(
			ubigint ref
			, WzemJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemJMPersonLastname::loadRefsByPrs(
			ubigint refWzemMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByPrs, 1, refWzemMPerson);

	return loadRefsByStmt(stmtLoadRefsByPrs, append, refs);
};

ubigint LiteTblWzemJMPersonLastname::loadRstByPrs(
			ubigint refWzemMPerson
			, const bool append
			, ListWzemJMPersonLastname& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrs, 1, refWzemMPerson);

	return loadRstByStmt(stmtLoadRstByPrs, append, rst);
};

#endif

