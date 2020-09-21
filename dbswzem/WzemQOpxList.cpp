/**
	* \file WzemQOpxList.cpp
	* Dbs and XML wrapper for table TblWzemQOpxList (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQOpxList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQOpxList
 ******************************************************************************/

WzemQOpxList::WzemQOpxList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMJob
			, const string stubRefWzemMJob
			, const ubigint xoref
			, const double x1Startu
			, const double x1Stopu
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refWzemMJob = refWzemMJob;
	this->stubRefWzemMJob = stubRefWzemMJob;
	this->xoref = xoref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
};

void WzemQOpxList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQOpxList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "job", stubRefWzemMJob);
		writeUbigint(wr, "xor", xoref);
		writeDouble(wr, "sta", x1Startu);
		writeDouble(wr, "sto", x1Stopu);
	} else {
		writeString(wr, "stubRefWzemMJob", stubRefWzemMJob);
		writeUbigint(wr, "xoref", xoref);
		writeDouble(wr, "x1Startu", x1Startu);
		writeDouble(wr, "x1Stopu", x1Stopu);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQOpxList
 ******************************************************************************/

ListWzemQOpxList::ListWzemQOpxList() {
};

ListWzemQOpxList::ListWzemQOpxList(
			const ListWzemQOpxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQOpxList(*(src.nodes[i]));
};

ListWzemQOpxList::~ListWzemQOpxList() {
	clear();
};

void ListWzemQOpxList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQOpxList::size() const {
	return(nodes.size());
};

void ListWzemQOpxList::append(
			WzemQOpxList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQOpxList& ListWzemQOpxList::operator=(
			const ListWzemQOpxList& src
		) {
	WzemQOpxList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQOpxList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQOpxList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQOpxList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQOpxList
 ******************************************************************************/

TblWzemQOpxList::TblWzemQOpxList() {
};

TblWzemQOpxList::~TblWzemQOpxList() {
};

bool TblWzemQOpxList::loadRecBySQL(
			const string& sqlstr
			, WzemQOpxList** rec
		) {
	return false;
};

ubigint TblWzemQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQOpxList& rst
		) {
	return 0;
};

ubigint TblWzemQOpxList::insertRec(
			WzemQOpxList* rec
		) {
	return 0;
};

ubigint TblWzemQOpxList::insertNewRec(
			WzemQOpxList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMJob
			, const string stubRefWzemMJob
			, const ubigint xoref
			, const double x1Startu
			, const double x1Stopu
		) {
	ubigint retval = 0;
	WzemQOpxList* _rec = NULL;

	_rec = new WzemQOpxList(0, jref, jnum, ref, refWzemMJob, stubRefWzemMJob, xoref, x1Startu, x1Stopu);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQOpxList::appendNewRecToRst(
			ListWzemQOpxList& rst
			, WzemQOpxList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMJob
			, const string stubRefWzemMJob
			, const ubigint xoref
			, const double x1Startu
			, const double x1Stopu
		) {
	ubigint retval = 0;
	WzemQOpxList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWzemMJob, stubRefWzemMJob, xoref, x1Startu, x1Stopu);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQOpxList::insertRst(
			ListWzemQOpxList& rst
		) {
};

void TblWzemQOpxList::updateRec(
			WzemQOpxList* rec
		) {
};

void TblWzemQOpxList::updateRst(
			ListWzemQOpxList& rst
		) {
};

void TblWzemQOpxList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQOpxList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQOpxList::loadRecByQref(
			ubigint qref
			, WzemQOpxList** rec
		) {
	return false;
};

ubigint TblWzemQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQOpxList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQOpxList
 ******************************************************************************/

MyTblWzemQOpxList::MyTblWzemQOpxList() :
			TblWzemQOpxList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQOpxList::~MyTblWzemQOpxList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQOpxList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQOpxList (jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQOpxList SET jref = ?, jnum = ?, ref = ?, refWzemMJob = ?, xoref = ?, x1Startu = ?, x1Stopu = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQOpxList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQOpxList WHERE jref = ?", false);
};

bool MyTblWzemQOpxList::loadRecBySQL(
			const string& sqlstr
			, WzemQOpxList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQOpxList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQOpxList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQOpxList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemQOpxList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWzemMJob = atoll((char*) dbrow[4]); else _rec->refWzemMJob = 0;
		if (dbrow[5]) _rec->xoref = atoll((char*) dbrow[5]); else _rec->xoref = 0;
		if (dbrow[6]) _rec->x1Startu = atof((char*) dbrow[6]); else _rec->x1Startu = 0.0;
		if (dbrow[7]) _rec->x1Stopu = atof((char*) dbrow[7]); else _rec->x1Stopu = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQOpxList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQOpxList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQOpxList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQOpxList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemQOpxList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWzemMJob = atoll((char*) dbrow[4]); else rec->refWzemMJob = 0;
			if (dbrow[5]) rec->xoref = atoll((char*) dbrow[5]); else rec->xoref = 0;
			if (dbrow[6]) rec->x1Startu = atof((char*) dbrow[6]); else rec->x1Startu = 0.0;
			if (dbrow[7]) rec->x1Stopu = atof((char*) dbrow[7]); else rec->x1Stopu = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQOpxList::insertRec(
			WzemQOpxList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMJob,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->xoref,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1Startu,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Stopu,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQOpxList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQOpxList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQOpxList::insertRst(
			ListWzemQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQOpxList::updateRec(
			WzemQOpxList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMJob,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->xoref,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1Startu,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Stopu,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQOpxList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQOpxList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQOpxList::updateRst(
			ListWzemQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQOpxList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQOpxList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQOpxList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQOpxList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQOpxList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQOpxList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQOpxList::loadRecByQref(
			ubigint qref
			, WzemQOpxList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQOpxList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQOpxList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQOpxList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQOpxList
 ******************************************************************************/

PgTblWzemQOpxList::PgTblWzemQOpxList() :
			TblWzemQOpxList()
			, PgTable()
		{
};

PgTblWzemQOpxList::~PgTblWzemQOpxList() {
};

void PgTblWzemQOpxList::initStatements() {
	createStatement("TblWzemQOpxList_insertRec", "INSERT INTO TblWzemQOpxList (jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWzemQOpxList_updateRec", "UPDATE TblWzemQOpxList SET jref = $1, jnum = $2, ref = $3, refWzemMJob = $4, xoref = $5, x1Startu = $6, x1Stopu = $7 WHERE qref = $8", 8);
	createStatement("TblWzemQOpxList_removeRecByQref", "DELETE FROM TblWzemQOpxList WHERE qref = $1", 1);
	createStatement("TblWzemQOpxList_removeRstByJref", "DELETE FROM TblWzemQOpxList WHERE jref = $1", 1);

	createStatement("TblWzemQOpxList_loadRecByQref", "SELECT qref, jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu FROM TblWzemQOpxList WHERE qref = $1", 1);
	createStatement("TblWzemQOpxList_loadRstByJref", "SELECT qref, jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu FROM TblWzemQOpxList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQOpxList::loadRec(
			PGresult* res
			, WzemQOpxList** rec
		) {
	char* ptr;

	WzemQOpxList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQOpxList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "xoref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->xoref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x1Stopu = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQOpxList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQOpxList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQOpxList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "xoref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu")
		};

		while (numread < numrow) {
			rec = new WzemQOpxList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->xoref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x1Stopu = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQOpxList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQOpxList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQOpxList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQOpxList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQOpxList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQOpxList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQOpxList::loadRecBySQL(
			const string& sqlstr
			, WzemQOpxList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQOpxList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQOpxList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQOpxList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQOpxList::insertRec(
			WzemQOpxList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _xoref = htonl64(rec->xoref);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMJob,
		(char*) &_xoref,
		_x1Startu.c_str(),
		_x1Stopu.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemQOpxList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQOpxList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQOpxList::insertRst(
			ListWzemQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQOpxList::updateRec(
			WzemQOpxList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _xoref = htonl64(rec->xoref);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMJob,
		(char*) &_xoref,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemQOpxList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQOpxList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQOpxList::updateRst(
			ListWzemQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQOpxList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQOpxList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQOpxList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQOpxList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQOpxList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQOpxList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQOpxList::loadRecByQref(
			ubigint qref
			, WzemQOpxList** rec
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

	return loadRecByStmt("TblWzemQOpxList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQOpxList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQOpxList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQOpxList
 ******************************************************************************/

LiteTblWzemQOpxList::LiteTblWzemQOpxList() :
			TblWzemQOpxList()
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

LiteTblWzemQOpxList::~LiteTblWzemQOpxList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQOpxList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQOpxList (jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu) VALUES (?1,?2,?3,?4,?5,?6,?7)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQOpxList SET jref = ?1, jnum = ?2, ref = ?3, refWzemMJob = ?4, xoref = ?5, x1Startu = ?6, x1Stopu = ?7 WHERE qref = ?8");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQOpxList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQOpxList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu FROM TblWzemQOpxList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refWzemMJob, xoref, x1Startu, x1Stopu FROM TblWzemQOpxList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQOpxList::loadRec(
			sqlite3_stmt* stmt
			, WzemQOpxList** rec
		) {
	int res;

	WzemQOpxList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQOpxList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 4);
		_rec->xoref = sqlite3_column_int64(stmt, 5);
		_rec->x1Startu = sqlite3_column_double(stmt, 6);
		_rec->x1Stopu = sqlite3_column_double(stmt, 7);

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

ubigint LiteTblWzemQOpxList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQOpxList& rst
		) {
	int res; ubigint numread = 0;

	WzemQOpxList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQOpxList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 4);
		rec->xoref = sqlite3_column_int64(stmt, 5);
		rec->x1Startu = sqlite3_column_double(stmt, 6);
		rec->x1Stopu = sqlite3_column_double(stmt, 7);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQOpxList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQOpxList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQOpxList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQOpxList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQOpxList::loadRecBySQL(
			const string& sqlstr
			, WzemQOpxList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQOpxList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQOpxList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQOpxList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQOpxList::insertRec(
			WzemQOpxList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzemMJob);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->xoref);
	sqlite3_bind_double(stmtInsertRec, 6, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 7, rec->x1Stopu);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQOpxList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQOpxList::insertRst(
			ListWzemQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQOpxList::updateRec(
			WzemQOpxList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzemMJob);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->xoref);
	sqlite3_bind_double(stmtUpdateRec, 6, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 7, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQOpxList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQOpxList::updateRst(
			ListWzemQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQOpxList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQOpxList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQOpxList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQOpxList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQOpxList::loadRecByQref(
			ubigint qref
			, WzemQOpxList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQOpxList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

