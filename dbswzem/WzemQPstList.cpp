/**
	* \file WzemQPstList.cpp
	* Dbs and XML wrapper for table TblWzemQPstList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQPstList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPstList
 ******************************************************************************/

WzemQPstList::WzemQPstList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMJob
			, const string stubRefWzemMJob
			, const string srefIxVPreset
			, const double x1Startu
			, const double x1Stopu
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refWzemMJob = refWzemMJob;
	this->stubRefWzemMJob = stubRefWzemMJob;
	this->srefIxVPreset = srefIxVPreset;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
};

void WzemQPstList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQPstList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "job", stubRefWzemMJob);
		writeString(wr, "pst", srefIxVPreset);
		writeDouble(wr, "sta", x1Startu);
		writeDouble(wr, "sto", x1Stopu);
	} else {
		writeString(wr, "stubRefWzemMJob", stubRefWzemMJob);
		writeString(wr, "srefIxVPreset", srefIxVPreset);
		writeDouble(wr, "x1Startu", x1Startu);
		writeDouble(wr, "x1Stopu", x1Stopu);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQPstList
 ******************************************************************************/

ListWzemQPstList::ListWzemQPstList() {
};

ListWzemQPstList::ListWzemQPstList(
			const ListWzemQPstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPstList(*(src.nodes[i]));
};

ListWzemQPstList::~ListWzemQPstList() {
	clear();
};

void ListWzemQPstList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQPstList::size() const {
	return(nodes.size());
};

void ListWzemQPstList::append(
			WzemQPstList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQPstList& ListWzemQPstList::operator=(
			const ListWzemQPstList& src
		) {
	WzemQPstList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQPstList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQPstList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQPstList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQPstList
 ******************************************************************************/

TblWzemQPstList::TblWzemQPstList() {
};

TblWzemQPstList::~TblWzemQPstList() {
};

bool TblWzemQPstList::loadRecBySQL(
			const string& sqlstr
			, WzemQPstList** rec
		) {
	return false;
};

ubigint TblWzemQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPstList& rst
		) {
	return 0;
};

ubigint TblWzemQPstList::insertRec(
			WzemQPstList* rec
		) {
	return 0;
};

ubigint TblWzemQPstList::insertNewRec(
			WzemQPstList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMJob
			, const string stubRefWzemMJob
			, const string srefIxVPreset
			, const double x1Startu
			, const double x1Stopu
		) {
	ubigint retval = 0;
	WzemQPstList* _rec = NULL;

	_rec = new WzemQPstList(0, jref, jnum, ref, refWzemMJob, stubRefWzemMJob, srefIxVPreset, x1Startu, x1Stopu);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQPstList::appendNewRecToRst(
			ListWzemQPstList& rst
			, WzemQPstList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMJob
			, const string stubRefWzemMJob
			, const string srefIxVPreset
			, const double x1Startu
			, const double x1Stopu
		) {
	ubigint retval = 0;
	WzemQPstList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWzemMJob, stubRefWzemMJob, srefIxVPreset, x1Startu, x1Stopu);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQPstList::insertRst(
			ListWzemQPstList& rst
		) {
};

void TblWzemQPstList::updateRec(
			WzemQPstList* rec
		) {
};

void TblWzemQPstList::updateRst(
			ListWzemQPstList& rst
		) {
};

void TblWzemQPstList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQPstList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQPstList::loadRecByQref(
			ubigint qref
			, WzemQPstList** rec
		) {
	return false;
};

ubigint TblWzemQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPstList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQPstList
 ******************************************************************************/

MyTblWzemQPstList::MyTblWzemQPstList() :
			TblWzemQPstList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQPstList::~MyTblWzemQPstList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQPstList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQPstList (jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQPstList SET jref = ?, jnum = ?, ref = ?, refWzemMJob = ?, srefIxVPreset = ?, x1Startu = ?, x1Stopu = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQPstList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQPstList WHERE jref = ?", false);
};

bool MyTblWzemQPstList::loadRecBySQL(
			const string& sqlstr
			, WzemQPstList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQPstList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQPstList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQPstList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQPstList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWzemMJob = atoll((char*) dbrow[4]); else _rec->refWzemMJob = 0;
		if (dbrow[5]) _rec->srefIxVPreset.assign(dbrow[5], dblengths[5]); else _rec->srefIxVPreset = "";
		if (dbrow[6]) _rec->x1Startu = atof((char*) dbrow[6]); else _rec->x1Startu = 0.0;
		if (dbrow[7]) _rec->x1Stopu = atof((char*) dbrow[7]); else _rec->x1Stopu = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPstList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQPstList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQPstList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQPstList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQPstList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWzemMJob = atoll((char*) dbrow[4]); else rec->refWzemMJob = 0;
			if (dbrow[5]) rec->srefIxVPreset.assign(dbrow[5], dblengths[5]); else rec->srefIxVPreset = "";
			if (dbrow[6]) rec->x1Startu = atof((char*) dbrow[6]); else rec->x1Startu = 0.0;
			if (dbrow[7]) rec->x1Stopu = atof((char*) dbrow[7]); else rec->x1Stopu = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQPstList::insertRec(
			WzemQPstList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->srefIxVPreset.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMJob,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefIxVPreset.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1Startu,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Stopu,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQPstList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQPstList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQPstList::insertRst(
			ListWzemQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQPstList::updateRec(
			WzemQPstList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->srefIxVPreset.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMJob,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefIxVPreset.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1Startu,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Stopu,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQPstList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQPstList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQPstList::updateRst(
			ListWzemQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQPstList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQPstList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQPstList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQPstList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQPstList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQPstList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQPstList::loadRecByQref(
			ubigint qref
			, WzemQPstList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQPstList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPstList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQPstList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQPstList
 ******************************************************************************/

PgTblWzemQPstList::PgTblWzemQPstList() :
			TblWzemQPstList()
			, PgTable()
		{
};

PgTblWzemQPstList::~PgTblWzemQPstList() {
};

void PgTblWzemQPstList::initStatements() {
	createStatement("TblWzemQPstList_insertRec", "INSERT INTO TblWzemQPstList (jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWzemQPstList_updateRec", "UPDATE TblWzemQPstList SET jref = $1, jnum = $2, ref = $3, refWzemMJob = $4, srefIxVPreset = $5, x1Startu = $6, x1Stopu = $7 WHERE qref = $8", 8);
	createStatement("TblWzemQPstList_removeRecByQref", "DELETE FROM TblWzemQPstList WHERE qref = $1", 1);
	createStatement("TblWzemQPstList_removeRstByJref", "DELETE FROM TblWzemQPstList WHERE jref = $1", 1);

	createStatement("TblWzemQPstList_loadRecByQref", "SELECT qref, jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu FROM TblWzemQPstList WHERE qref = $1", 1);
	createStatement("TblWzemQPstList_loadRstByJref", "SELECT qref, jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu FROM TblWzemQPstList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQPstList::loadRec(
			PGresult* res
			, WzemQPstList** rec
		) {
	char* ptr;

	WzemQPstList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQPstList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvpreset"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefIxVPreset.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x1Stopu = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQPstList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQPstList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQPstList* rec;

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
			PQfnumber(res, "srefixvpreset"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu")
		};

		while (numread < numrow) {
			rec = new WzemQPstList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefIxVPreset.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x1Stopu = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQPstList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQPstList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPstList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQPstList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQPstList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPstList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQPstList::loadRecBySQL(
			const string& sqlstr
			, WzemQPstList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQPstList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPstList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQPstList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQPstList::insertRec(
			WzemQPstList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMJob,
		rec->srefIxVPreset.c_str(),
		_x1Startu.c_str(),
		_x1Stopu.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemQPstList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPstList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQPstList::insertRst(
			ListWzemQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQPstList::updateRec(
			WzemQPstList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMJob,
		rec->srefIxVPreset.c_str(),
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemQPstList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPstList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQPstList::updateRst(
			ListWzemQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQPstList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQPstList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPstList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQPstList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQPstList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPstList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQPstList::loadRecByQref(
			ubigint qref
			, WzemQPstList** rec
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

	return loadRecByStmt("TblWzemQPstList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPstList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQPstList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQPstList
 ******************************************************************************/

LiteTblWzemQPstList::LiteTblWzemQPstList() :
			TblWzemQPstList()
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

LiteTblWzemQPstList::~LiteTblWzemQPstList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQPstList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQPstList (jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu) VALUES (?1,?2,?3,?4,?5,?6,?7)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQPstList SET jref = ?1, jnum = ?2, ref = ?3, refWzemMJob = ?4, srefIxVPreset = ?5, x1Startu = ?6, x1Stopu = ?7 WHERE qref = ?8");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQPstList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQPstList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu FROM TblWzemQPstList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refWzemMJob, srefIxVPreset, x1Startu, x1Stopu FROM TblWzemQPstList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQPstList::loadRec(
			sqlite3_stmt* stmt
			, WzemQPstList** rec
		) {
	int res;

	WzemQPstList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQPstList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 4);
		_rec->srefIxVPreset.assign((const char*) sqlite3_column_text(stmt, 5));
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

ubigint LiteTblWzemQPstList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQPstList& rst
		) {
	int res; ubigint numread = 0;

	WzemQPstList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQPstList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 4);
		rec->srefIxVPreset.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->x1Startu = sqlite3_column_double(stmt, 6);
		rec->x1Stopu = sqlite3_column_double(stmt, 7);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQPstList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQPstList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQPstList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQPstList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQPstList::loadRecBySQL(
			const string& sqlstr
			, WzemQPstList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQPstList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPstList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQPstList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQPstList::insertRec(
			WzemQPstList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzemMJob);
	sqlite3_bind_text(stmtInsertRec, 5, rec->srefIxVPreset.c_str(), rec->srefIxVPreset.length(), SQLITE_STATIC);
	sqlite3_bind_double(stmtInsertRec, 6, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 7, rec->x1Stopu);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPstList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQPstList::insertRst(
			ListWzemQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQPstList::updateRec(
			WzemQPstList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzemMJob);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->srefIxVPreset.c_str(), rec->srefIxVPreset.length(), SQLITE_STATIC);
	sqlite3_bind_double(stmtUpdateRec, 6, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 7, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPstList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQPstList::updateRst(
			ListWzemQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQPstList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPstList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQPstList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPstList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQPstList::loadRecByQref(
			ubigint qref
			, WzemQPstList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPstList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

