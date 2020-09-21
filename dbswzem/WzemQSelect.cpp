/**
	* \file WzemQSelect.cpp
	* Dbs and XML wrapper for table TblWzemQSelect (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQSelect.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQSelect
 ******************************************************************************/

WzemQSelect::WzemQSelect(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const uint ix
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ix = ix;
	this->ref = ref;
};

void WzemQSelect::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQSelect";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
	} else {
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQSelect
 ******************************************************************************/

ListWzemQSelect::ListWzemQSelect() {
};

ListWzemQSelect::ListWzemQSelect(
			const ListWzemQSelect& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQSelect(*(src.nodes[i]));
};

ListWzemQSelect::~ListWzemQSelect() {
	clear();
};

void ListWzemQSelect::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQSelect::size() const {
	return(nodes.size());
};

void ListWzemQSelect::append(
			WzemQSelect* rec
		) {
	nodes.push_back(rec);
};

ListWzemQSelect& ListWzemQSelect::operator=(
			const ListWzemQSelect& src
		) {
	WzemQSelect* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQSelect(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQSelect::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQSelect";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQSelect
 ******************************************************************************/

TblWzemQSelect::TblWzemQSelect() {
};

TblWzemQSelect::~TblWzemQSelect() {
};

bool TblWzemQSelect::loadRecBySQL(
			const string& sqlstr
			, WzemQSelect** rec
		) {
	return false;
};

ubigint TblWzemQSelect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQSelect& rst
		) {
	return 0;
};

ubigint TblWzemQSelect::insertRec(
			WzemQSelect* rec
		) {
	return 0;
};

ubigint TblWzemQSelect::insertNewRec(
			WzemQSelect** rec
			, const ubigint jref
			, const uint jnum
			, const uint ix
			, const ubigint ref
		) {
	ubigint retval = 0;
	WzemQSelect* _rec = NULL;

	_rec = new WzemQSelect(0, jref, jnum, ix, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQSelect::appendNewRecToRst(
			ListWzemQSelect& rst
			, WzemQSelect** rec
			, const ubigint jref
			, const uint jnum
			, const uint ix
			, const ubigint ref
		) {
	ubigint retval = 0;
	WzemQSelect* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ix, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQSelect::insertRst(
			ListWzemQSelect& rst
		) {
};

void TblWzemQSelect::updateRec(
			WzemQSelect* rec
		) {
};

void TblWzemQSelect::updateRst(
			ListWzemQSelect& rst
		) {
};

void TblWzemQSelect::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQSelect::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQSelect::loadRecByQref(
			ubigint qref
			, WzemQSelect** rec
		) {
	return false;
};

ubigint TblWzemQSelect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQSelect& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQSelect
 ******************************************************************************/

MyTblWzemQSelect::MyTblWzemQSelect() :
			TblWzemQSelect()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQSelect::~MyTblWzemQSelect() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQSelect::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQSelect (jref, jnum, ix, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQSelect SET jref = ?, jnum = ?, ix = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQSelect WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQSelect WHERE jref = ?", false);
};

bool MyTblWzemQSelect::loadRecBySQL(
			const string& sqlstr
			, WzemQSelect** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQSelect* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQSelect::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQSelect::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemQSelect();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ix = atol((char*) dbrow[3]); else _rec->ix = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQSelect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQSelect& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQSelect* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQSelect::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQSelect::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemQSelect();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ix = atol((char*) dbrow[3]); else rec->ix = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQSelect::insertRec(
			WzemQSelect* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ix,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQSelect::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQSelect::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQSelect::insertRst(
			ListWzemQSelect& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQSelect::updateRec(
			WzemQSelect* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ix,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQSelect::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQSelect::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQSelect::updateRst(
			ListWzemQSelect& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQSelect::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQSelect::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQSelect::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQSelect::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQSelect::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQSelect::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQSelect::loadRecByQref(
			ubigint qref
			, WzemQSelect** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQSelect WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQSelect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQSelect& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQSelect WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQSelect
 ******************************************************************************/

PgTblWzemQSelect::PgTblWzemQSelect() :
			TblWzemQSelect()
			, PgTable()
		{
};

PgTblWzemQSelect::~PgTblWzemQSelect() {
};

void PgTblWzemQSelect::initStatements() {
	createStatement("TblWzemQSelect_insertRec", "INSERT INTO TblWzemQSelect (jref, jnum, ix, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWzemQSelect_updateRec", "UPDATE TblWzemQSelect SET jref = $1, jnum = $2, ix = $3, ref = $4 WHERE qref = $5", 5);
	createStatement("TblWzemQSelect_removeRecByQref", "DELETE FROM TblWzemQSelect WHERE qref = $1", 1);
	createStatement("TblWzemQSelect_removeRstByJref", "DELETE FROM TblWzemQSelect WHERE jref = $1", 1);

	createStatement("TblWzemQSelect_loadRecByQref", "SELECT qref, jref, jnum, ix, ref FROM TblWzemQSelect WHERE qref = $1", 1);
	createStatement("TblWzemQSelect_loadRstByJref", "SELECT qref, jref, jnum, ix, ref FROM TblWzemQSelect WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQSelect::loadRec(
			PGresult* res
			, WzemQSelect** rec
		) {
	char* ptr;

	WzemQSelect* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQSelect();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ix"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ix = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQSelect::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQSelect& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQSelect* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ix"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WzemQSelect();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ix = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQSelect::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQSelect** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQSelect::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQSelect::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQSelect& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQSelect::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQSelect::loadRecBySQL(
			const string& sqlstr
			, WzemQSelect** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQSelect::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQSelect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQSelect& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQSelect::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQSelect::insertRec(
			WzemQSelect* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	uint _ix = htonl(rec->ix);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ix,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQSelect_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQSelect::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQSelect::insertRst(
			ListWzemQSelect& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQSelect::updateRec(
			WzemQSelect* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	uint _ix = htonl(rec->ix);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ix,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQSelect_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQSelect::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQSelect::updateRst(
			ListWzemQSelect& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQSelect::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWzemQSelect_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQSelect::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQSelect::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWzemQSelect_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQSelect::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQSelect::loadRecByQref(
			ubigint qref
			, WzemQSelect** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWzemQSelect_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQSelect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQSelect& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQSelect_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQSelect
 ******************************************************************************/

LiteTblWzemQSelect::LiteTblWzemQSelect() :
			TblWzemQSelect()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;

	stmtLoadRecByQref = NULL;
	stmtLoadRecByJref = NULL;
	stmtLoadRstByJref = NULL;
};

LiteTblWzemQSelect::~LiteTblWzemQSelect() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQSelect::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQSelect (jref, jnum, ix, ref) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQSelect SET jref = ?1, jnum = ?2, ix = ?3, ref = ?4 WHERE qref = ?5");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQSelect WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQSelect WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ix, ref FROM TblWzemQSelect WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ix, ref FROM TblWzemQSelect WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQSelect::loadRec(
			sqlite3_stmt* stmt
			, WzemQSelect** rec
		) {
	int res;

	WzemQSelect* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQSelect();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ix = sqlite3_column_int(stmt, 3);
		_rec->ref = sqlite3_column_int64(stmt, 4);

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

ubigint LiteTblWzemQSelect::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQSelect& rst
		) {
	int res; ubigint numread = 0;

	WzemQSelect* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQSelect();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ix = sqlite3_column_int(stmt, 3);
		rec->ref = sqlite3_column_int64(stmt, 4);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQSelect::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQSelect** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQSelect::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQSelect& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQSelect::loadRecBySQL(
			const string& sqlstr
			, WzemQSelect** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQSelect::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQSelect::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQSelect& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQSelect::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQSelect::insertRec(
			WzemQSelect* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->ix);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQSelect::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQSelect::insertRst(
			ListWzemQSelect& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQSelect::updateRec(
			WzemQSelect* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->ix);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQSelect::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQSelect::updateRst(
			ListWzemQSelect& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQSelect::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQSelect::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQSelect::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQSelect::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQSelect::loadRecByQref(
			ubigint qref
			, WzemQSelect** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQSelect::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQSelect& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

