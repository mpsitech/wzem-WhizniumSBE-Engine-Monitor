/**
	* \file WzemQPrd1NJob.cpp
	* Dbs and XML wrapper for table TblWzemQPrd1NJob (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQPrd1NJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPrd1NJob
 ******************************************************************************/

WzemQPrd1NJob::WzemQPrd1NJob(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void WzemQPrd1NJob::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQPrd1NJob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQPrd1NJob
 ******************************************************************************/

ListWzemQPrd1NJob::ListWzemQPrd1NJob() {
};

ListWzemQPrd1NJob::ListWzemQPrd1NJob(
			const ListWzemQPrd1NJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrd1NJob(*(src.nodes[i]));
};

ListWzemQPrd1NJob::~ListWzemQPrd1NJob() {
	clear();
};

void ListWzemQPrd1NJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQPrd1NJob::size() const {
	return(nodes.size());
};

void ListWzemQPrd1NJob::append(
			WzemQPrd1NJob* rec
		) {
	nodes.push_back(rec);
};

ListWzemQPrd1NJob& ListWzemQPrd1NJob::operator=(
			const ListWzemQPrd1NJob& src
		) {
	WzemQPrd1NJob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQPrd1NJob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQPrd1NJob::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQPrd1NJob";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQPrd1NJob
 ******************************************************************************/

TblWzemQPrd1NJob::TblWzemQPrd1NJob() {
};

TblWzemQPrd1NJob::~TblWzemQPrd1NJob() {
};

bool TblWzemQPrd1NJob::loadRecBySQL(
			const string& sqlstr
			, WzemQPrd1NJob** rec
		) {
	return false;
};

ubigint TblWzemQPrd1NJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	return 0;
};

ubigint TblWzemQPrd1NJob::insertRec(
			WzemQPrd1NJob* rec
		) {
	return 0;
};

ubigint TblWzemQPrd1NJob::insertNewRec(
			WzemQPrd1NJob** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WzemQPrd1NJob* _rec = NULL;

	_rec = new WzemQPrd1NJob(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQPrd1NJob::appendNewRecToRst(
			ListWzemQPrd1NJob& rst
			, WzemQPrd1NJob** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WzemQPrd1NJob* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQPrd1NJob::insertRst(
			ListWzemQPrd1NJob& rst
		) {
};

void TblWzemQPrd1NJob::updateRec(
			WzemQPrd1NJob* rec
		) {
};

void TblWzemQPrd1NJob::updateRst(
			ListWzemQPrd1NJob& rst
		) {
};

void TblWzemQPrd1NJob::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQPrd1NJob::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQPrd1NJob::loadRecByQref(
			ubigint qref
			, WzemQPrd1NJob** rec
		) {
	return false;
};

ubigint TblWzemQPrd1NJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQPrd1NJob
 ******************************************************************************/

MyTblWzemQPrd1NJob::MyTblWzemQPrd1NJob() :
			TblWzemQPrd1NJob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQPrd1NJob::~MyTblWzemQPrd1NJob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQPrd1NJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQPrd1NJob (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQPrd1NJob SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQPrd1NJob WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQPrd1NJob WHERE jref = ?", false);
};

bool MyTblWzemQPrd1NJob::loadRecBySQL(
			const string& sqlstr
			, WzemQPrd1NJob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQPrd1NJob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQPrd1NJob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQPrd1NJob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemQPrd1NJob();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQPrd1NJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQPrd1NJob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQPrd1NJob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQPrd1NJob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemQPrd1NJob();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQPrd1NJob::insertRec(
			WzemQPrd1NJob* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQPrd1NJob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQPrd1NJob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQPrd1NJob::insertRst(
			ListWzemQPrd1NJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQPrd1NJob::updateRec(
			WzemQPrd1NJob* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQPrd1NJob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQPrd1NJob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQPrd1NJob::updateRst(
			ListWzemQPrd1NJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQPrd1NJob::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQPrd1NJob::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQPrd1NJob::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQPrd1NJob::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQPrd1NJob::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQPrd1NJob::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQPrd1NJob::loadRecByQref(
			ubigint qref
			, WzemQPrd1NJob** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQPrd1NJob WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQPrd1NJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQPrd1NJob WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQPrd1NJob
 ******************************************************************************/

PgTblWzemQPrd1NJob::PgTblWzemQPrd1NJob() :
			TblWzemQPrd1NJob()
			, PgTable()
		{
};

PgTblWzemQPrd1NJob::~PgTblWzemQPrd1NJob() {
};

void PgTblWzemQPrd1NJob::initStatements() {
	createStatement("TblWzemQPrd1NJob_insertRec", "INSERT INTO TblWzemQPrd1NJob (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWzemQPrd1NJob_updateRec", "UPDATE TblWzemQPrd1NJob SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWzemQPrd1NJob_removeRecByQref", "DELETE FROM TblWzemQPrd1NJob WHERE qref = $1", 1);
	createStatement("TblWzemQPrd1NJob_removeRstByJref", "DELETE FROM TblWzemQPrd1NJob WHERE jref = $1", 1);

	createStatement("TblWzemQPrd1NJob_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWzemQPrd1NJob WHERE qref = $1", 1);
	createStatement("TblWzemQPrd1NJob_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWzemQPrd1NJob WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQPrd1NJob::loadRec(
			PGresult* res
			, WzemQPrd1NJob** rec
		) {
	char* ptr;

	WzemQPrd1NJob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQPrd1NJob();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQPrd1NJob::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQPrd1NJob* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WzemQPrd1NJob();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQPrd1NJob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQPrd1NJob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPrd1NJob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQPrd1NJob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPrd1NJob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQPrd1NJob::loadRecBySQL(
			const string& sqlstr
			, WzemQPrd1NJob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQPrd1NJob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQPrd1NJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQPrd1NJob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQPrd1NJob::insertRec(
			WzemQPrd1NJob* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQPrd1NJob_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPrd1NJob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQPrd1NJob::insertRst(
			ListWzemQPrd1NJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQPrd1NJob::updateRec(
			WzemQPrd1NJob* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQPrd1NJob_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPrd1NJob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQPrd1NJob::updateRst(
			ListWzemQPrd1NJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQPrd1NJob::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQPrd1NJob_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPrd1NJob::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQPrd1NJob::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQPrd1NJob_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPrd1NJob::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQPrd1NJob::loadRecByQref(
			ubigint qref
			, WzemQPrd1NJob** rec
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

	return loadRecByStmt("TblWzemQPrd1NJob_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQPrd1NJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQPrd1NJob_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQPrd1NJob
 ******************************************************************************/

LiteTblWzemQPrd1NJob::LiteTblWzemQPrd1NJob() :
			TblWzemQPrd1NJob()
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

LiteTblWzemQPrd1NJob::~LiteTblWzemQPrd1NJob() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQPrd1NJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQPrd1NJob (jref, jnum, ref) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQPrd1NJob SET jref = ?1, jnum = ?2, ref = ?3 WHERE qref = ?4");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQPrd1NJob WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQPrd1NJob WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref FROM TblWzemQPrd1NJob WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref FROM TblWzemQPrd1NJob WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQPrd1NJob::loadRec(
			sqlite3_stmt* stmt
			, WzemQPrd1NJob** rec
		) {
	int res;

	WzemQPrd1NJob* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQPrd1NJob();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);

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

ubigint LiteTblWzemQPrd1NJob::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	int res; ubigint numread = 0;

	WzemQPrd1NJob* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQPrd1NJob();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQPrd1NJob::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQPrd1NJob** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQPrd1NJob::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQPrd1NJob::loadRecBySQL(
			const string& sqlstr
			, WzemQPrd1NJob** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQPrd1NJob::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQPrd1NJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQPrd1NJob::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQPrd1NJob::insertRec(
			WzemQPrd1NJob* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrd1NJob::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQPrd1NJob::insertRst(
			ListWzemQPrd1NJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQPrd1NJob::updateRec(
			WzemQPrd1NJob* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrd1NJob::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQPrd1NJob::updateRst(
			ListWzemQPrd1NJob& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQPrd1NJob::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrd1NJob::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQPrd1NJob::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrd1NJob::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQPrd1NJob::loadRecByQref(
			ubigint qref
			, WzemQPrd1NJob** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQPrd1NJob::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrd1NJob& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

