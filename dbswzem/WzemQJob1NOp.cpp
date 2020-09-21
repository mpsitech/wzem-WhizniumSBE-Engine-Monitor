/**
	* \file WzemQJob1NOp.cpp
	* Dbs and XML wrapper for table TblWzemQJob1NOp (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQJob1NOp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQJob1NOp
 ******************************************************************************/

WzemQJob1NOp::WzemQJob1NOp(
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

void WzemQJob1NOp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQJob1NOp";

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
 class ListWzemQJob1NOp
 ******************************************************************************/

ListWzemQJob1NOp::ListWzemQJob1NOp() {
};

ListWzemQJob1NOp::ListWzemQJob1NOp(
			const ListWzemQJob1NOp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQJob1NOp(*(src.nodes[i]));
};

ListWzemQJob1NOp::~ListWzemQJob1NOp() {
	clear();
};

void ListWzemQJob1NOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQJob1NOp::size() const {
	return(nodes.size());
};

void ListWzemQJob1NOp::append(
			WzemQJob1NOp* rec
		) {
	nodes.push_back(rec);
};

ListWzemQJob1NOp& ListWzemQJob1NOp::operator=(
			const ListWzemQJob1NOp& src
		) {
	WzemQJob1NOp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQJob1NOp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQJob1NOp::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQJob1NOp";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQJob1NOp
 ******************************************************************************/

TblWzemQJob1NOp::TblWzemQJob1NOp() {
};

TblWzemQJob1NOp::~TblWzemQJob1NOp() {
};

bool TblWzemQJob1NOp::loadRecBySQL(
			const string& sqlstr
			, WzemQJob1NOp** rec
		) {
	return false;
};

ubigint TblWzemQJob1NOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	return 0;
};

ubigint TblWzemQJob1NOp::insertRec(
			WzemQJob1NOp* rec
		) {
	return 0;
};

ubigint TblWzemQJob1NOp::insertNewRec(
			WzemQJob1NOp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WzemQJob1NOp* _rec = NULL;

	_rec = new WzemQJob1NOp(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQJob1NOp::appendNewRecToRst(
			ListWzemQJob1NOp& rst
			, WzemQJob1NOp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WzemQJob1NOp* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQJob1NOp::insertRst(
			ListWzemQJob1NOp& rst
		) {
};

void TblWzemQJob1NOp::updateRec(
			WzemQJob1NOp* rec
		) {
};

void TblWzemQJob1NOp::updateRst(
			ListWzemQJob1NOp& rst
		) {
};

void TblWzemQJob1NOp::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQJob1NOp::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQJob1NOp::loadRecByQref(
			ubigint qref
			, WzemQJob1NOp** rec
		) {
	return false;
};

ubigint TblWzemQJob1NOp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQJob1NOp
 ******************************************************************************/

MyTblWzemQJob1NOp::MyTblWzemQJob1NOp() :
			TblWzemQJob1NOp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQJob1NOp::~MyTblWzemQJob1NOp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQJob1NOp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQJob1NOp (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQJob1NOp SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQJob1NOp WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQJob1NOp WHERE jref = ?", false);
};

bool MyTblWzemQJob1NOp::loadRecBySQL(
			const string& sqlstr
			, WzemQJob1NOp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQJob1NOp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQJob1NOp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQJob1NOp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemQJob1NOp();

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

ubigint MyTblWzemQJob1NOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQJob1NOp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQJob1NOp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQJob1NOp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemQJob1NOp();

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

ubigint MyTblWzemQJob1NOp::insertRec(
			WzemQJob1NOp* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQJob1NOp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQJob1NOp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQJob1NOp::insertRst(
			ListWzemQJob1NOp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQJob1NOp::updateRec(
			WzemQJob1NOp* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQJob1NOp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQJob1NOp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQJob1NOp::updateRst(
			ListWzemQJob1NOp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQJob1NOp::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQJob1NOp::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQJob1NOp::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQJob1NOp::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQJob1NOp::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQJob1NOp::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQJob1NOp::loadRecByQref(
			ubigint qref
			, WzemQJob1NOp** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQJob1NOp WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQJob1NOp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQJob1NOp WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQJob1NOp
 ******************************************************************************/

PgTblWzemQJob1NOp::PgTblWzemQJob1NOp() :
			TblWzemQJob1NOp()
			, PgTable()
		{
};

PgTblWzemQJob1NOp::~PgTblWzemQJob1NOp() {
};

void PgTblWzemQJob1NOp::initStatements() {
	createStatement("TblWzemQJob1NOp_insertRec", "INSERT INTO TblWzemQJob1NOp (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWzemQJob1NOp_updateRec", "UPDATE TblWzemQJob1NOp SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWzemQJob1NOp_removeRecByQref", "DELETE FROM TblWzemQJob1NOp WHERE qref = $1", 1);
	createStatement("TblWzemQJob1NOp_removeRstByJref", "DELETE FROM TblWzemQJob1NOp WHERE jref = $1", 1);

	createStatement("TblWzemQJob1NOp_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWzemQJob1NOp WHERE qref = $1", 1);
	createStatement("TblWzemQJob1NOp_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWzemQJob1NOp WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQJob1NOp::loadRec(
			PGresult* res
			, WzemQJob1NOp** rec
		) {
	char* ptr;

	WzemQJob1NOp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQJob1NOp();

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

ubigint PgTblWzemQJob1NOp::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQJob1NOp* rec;

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
			rec = new WzemQJob1NOp();

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

bool PgTblWzemQJob1NOp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQJob1NOp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQJob1NOp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQJob1NOp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQJob1NOp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQJob1NOp::loadRecBySQL(
			const string& sqlstr
			, WzemQJob1NOp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQJob1NOp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQJob1NOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQJob1NOp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQJob1NOp::insertRec(
			WzemQJob1NOp* rec
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

	res = PQexecPrepared(dbs, "TblWzemQJob1NOp_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQJob1NOp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQJob1NOp::insertRst(
			ListWzemQJob1NOp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQJob1NOp::updateRec(
			WzemQJob1NOp* rec
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

	res = PQexecPrepared(dbs, "TblWzemQJob1NOp_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQJob1NOp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQJob1NOp::updateRst(
			ListWzemQJob1NOp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQJob1NOp::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQJob1NOp_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQJob1NOp::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQJob1NOp::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQJob1NOp_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQJob1NOp::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQJob1NOp::loadRecByQref(
			ubigint qref
			, WzemQJob1NOp** rec
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

	return loadRecByStmt("TblWzemQJob1NOp_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQJob1NOp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQJob1NOp_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQJob1NOp
 ******************************************************************************/

LiteTblWzemQJob1NOp::LiteTblWzemQJob1NOp() :
			TblWzemQJob1NOp()
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

LiteTblWzemQJob1NOp::~LiteTblWzemQJob1NOp() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQJob1NOp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQJob1NOp (jref, jnum, ref) VALUES (?1,?2,?3)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQJob1NOp SET jref = ?1, jnum = ?2, ref = ?3 WHERE qref = ?4");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQJob1NOp WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQJob1NOp WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref FROM TblWzemQJob1NOp WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref FROM TblWzemQJob1NOp WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQJob1NOp::loadRec(
			sqlite3_stmt* stmt
			, WzemQJob1NOp** rec
		) {
	int res;

	WzemQJob1NOp* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQJob1NOp();

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

ubigint LiteTblWzemQJob1NOp::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	int res; ubigint numread = 0;

	WzemQJob1NOp* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQJob1NOp();

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

bool LiteTblWzemQJob1NOp::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQJob1NOp** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQJob1NOp::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQJob1NOp::loadRecBySQL(
			const string& sqlstr
			, WzemQJob1NOp** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQJob1NOp::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQJob1NOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQJob1NOp::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQJob1NOp::insertRec(
			WzemQJob1NOp* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJob1NOp::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQJob1NOp::insertRst(
			ListWzemQJob1NOp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQJob1NOp::updateRec(
			WzemQJob1NOp* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJob1NOp::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQJob1NOp::updateRst(
			ListWzemQJob1NOp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQJob1NOp::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJob1NOp::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQJob1NOp::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJob1NOp::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQJob1NOp::loadRecByQref(
			ubigint qref
			, WzemQJob1NOp** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQJob1NOp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJob1NOp& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

