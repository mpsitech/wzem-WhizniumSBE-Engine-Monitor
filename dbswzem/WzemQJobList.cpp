/**
	* \file WzemQJobList.cpp
	* Dbs and XML wrapper for table TblWzemQJobList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQJobList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQJobList
 ******************************************************************************/

WzemQJobList::WzemQJobList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const string srefIxVJob
			, const ubigint xjref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint supRefWzemMJob
			, const string stubSupRefWzemMJob
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refWzemMPeriod = refWzemMPeriod;
	this->stubRefWzemMPeriod = stubRefWzemMPeriod;
	this->srefIxVJob = srefIxVJob;
	this->xjref = xjref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->supRefWzemMJob = supRefWzemMJob;
	this->stubSupRefWzemMJob = stubSupRefWzemMJob;
};

void WzemQJobList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQJobList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prd", stubRefWzemMPeriod);
		writeString(wr, "job", srefIxVJob);
		writeUbigint(wr, "xjr", xjref);
		writeDouble(wr, "sta", x1Startu);
		writeDouble(wr, "sto", x1Stopu);
		writeString(wr, "sup", stubSupRefWzemMJob);
	} else {
		writeString(wr, "stubRefWzemMPeriod", stubRefWzemMPeriod);
		writeString(wr, "srefIxVJob", srefIxVJob);
		writeUbigint(wr, "xjref", xjref);
		writeDouble(wr, "x1Startu", x1Startu);
		writeDouble(wr, "x1Stopu", x1Stopu);
		writeString(wr, "stubSupRefWzemMJob", stubSupRefWzemMJob);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQJobList
 ******************************************************************************/

ListWzemQJobList::ListWzemQJobList() {
};

ListWzemQJobList::ListWzemQJobList(
			const ListWzemQJobList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQJobList(*(src.nodes[i]));
};

ListWzemQJobList::~ListWzemQJobList() {
	clear();
};

void ListWzemQJobList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQJobList::size() const {
	return(nodes.size());
};

void ListWzemQJobList::append(
			WzemQJobList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQJobList& ListWzemQJobList::operator=(
			const ListWzemQJobList& src
		) {
	WzemQJobList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQJobList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQJobList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQJobList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQJobList
 ******************************************************************************/

TblWzemQJobList::TblWzemQJobList() {
};

TblWzemQJobList::~TblWzemQJobList() {
};

bool TblWzemQJobList::loadRecBySQL(
			const string& sqlstr
			, WzemQJobList** rec
		) {
	return false;
};

ubigint TblWzemQJobList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJobList& rst
		) {
	return 0;
};

ubigint TblWzemQJobList::insertRec(
			WzemQJobList* rec
		) {
	return 0;
};

ubigint TblWzemQJobList::insertNewRec(
			WzemQJobList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const string srefIxVJob
			, const ubigint xjref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint supRefWzemMJob
			, const string stubSupRefWzemMJob
		) {
	ubigint retval = 0;
	WzemQJobList* _rec = NULL;

	_rec = new WzemQJobList(0, jref, jnum, ref, refWzemMPeriod, stubRefWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob, stubSupRefWzemMJob);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQJobList::appendNewRecToRst(
			ListWzemQJobList& rst
			, WzemQJobList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const string srefIxVJob
			, const ubigint xjref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint supRefWzemMJob
			, const string stubSupRefWzemMJob
		) {
	ubigint retval = 0;
	WzemQJobList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWzemMPeriod, stubRefWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob, stubSupRefWzemMJob);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQJobList::insertRst(
			ListWzemQJobList& rst
		) {
};

void TblWzemQJobList::updateRec(
			WzemQJobList* rec
		) {
};

void TblWzemQJobList::updateRst(
			ListWzemQJobList& rst
		) {
};

void TblWzemQJobList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQJobList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQJobList::loadRecByQref(
			ubigint qref
			, WzemQJobList** rec
		) {
	return false;
};

ubigint TblWzemQJobList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJobList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQJobList
 ******************************************************************************/

MyTblWzemQJobList::MyTblWzemQJobList() :
			TblWzemQJobList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQJobList::~MyTblWzemQJobList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQJobList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQJobList (jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQJobList SET jref = ?, jnum = ?, ref = ?, refWzemMPeriod = ?, srefIxVJob = ?, xjref = ?, x1Startu = ?, x1Stopu = ?, supRefWzemMJob = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQJobList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQJobList WHERE jref = ?", false);
};

bool MyTblWzemQJobList::loadRecBySQL(
			const string& sqlstr
			, WzemQJobList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQJobList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQJobList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQJobList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQJobList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWzemMPeriod = atoll((char*) dbrow[4]); else _rec->refWzemMPeriod = 0;
		if (dbrow[5]) _rec->srefIxVJob.assign(dbrow[5], dblengths[5]); else _rec->srefIxVJob = "";
		if (dbrow[6]) _rec->xjref = atoll((char*) dbrow[6]); else _rec->xjref = 0;
		if (dbrow[7]) _rec->x1Startu = atof((char*) dbrow[7]); else _rec->x1Startu = 0.0;
		if (dbrow[8]) _rec->x1Stopu = atof((char*) dbrow[8]); else _rec->x1Stopu = 0.0;
		if (dbrow[9]) _rec->supRefWzemMJob = atoll((char*) dbrow[9]); else _rec->supRefWzemMJob = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQJobList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJobList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQJobList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQJobList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQJobList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQJobList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWzemMPeriod = atoll((char*) dbrow[4]); else rec->refWzemMPeriod = 0;
			if (dbrow[5]) rec->srefIxVJob.assign(dbrow[5], dblengths[5]); else rec->srefIxVJob = "";
			if (dbrow[6]) rec->xjref = atoll((char*) dbrow[6]); else rec->xjref = 0;
			if (dbrow[7]) rec->x1Startu = atof((char*) dbrow[7]); else rec->x1Startu = 0.0;
			if (dbrow[8]) rec->x1Stopu = atof((char*) dbrow[8]); else rec->x1Stopu = 0.0;
			if (dbrow[9]) rec->supRefWzemMJob = atoll((char*) dbrow[9]); else rec->supRefWzemMJob = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQJobList::insertRec(
			WzemQJobList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->srefIxVJob.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMPeriod,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefIxVJob.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->xjref,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Startu,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x1Stopu,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->supRefWzemMJob,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQJobList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQJobList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQJobList::insertRst(
			ListWzemQJobList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQJobList::updateRec(
			WzemQJobList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->srefIxVJob.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMPeriod,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefIxVJob.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->xjref,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Startu,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x1Stopu,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->supRefWzemMJob,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQJobList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQJobList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQJobList::updateRst(
			ListWzemQJobList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQJobList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQJobList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQJobList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQJobList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQJobList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQJobList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQJobList::loadRecByQref(
			ubigint qref
			, WzemQJobList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQJobList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQJobList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJobList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQJobList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQJobList
 ******************************************************************************/

PgTblWzemQJobList::PgTblWzemQJobList() :
			TblWzemQJobList()
			, PgTable()
		{
};

PgTblWzemQJobList::~PgTblWzemQJobList() {
};

void PgTblWzemQJobList::initStatements() {
	createStatement("TblWzemQJobList_insertRec", "INSERT INTO TblWzemQJobList (jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWzemQJobList_updateRec", "UPDATE TblWzemQJobList SET jref = $1, jnum = $2, ref = $3, refWzemMPeriod = $4, srefIxVJob = $5, xjref = $6, x1Startu = $7, x1Stopu = $8, supRefWzemMJob = $9 WHERE qref = $10", 10);
	createStatement("TblWzemQJobList_removeRecByQref", "DELETE FROM TblWzemQJobList WHERE qref = $1", 1);
	createStatement("TblWzemQJobList_removeRstByJref", "DELETE FROM TblWzemQJobList WHERE jref = $1", 1);

	createStatement("TblWzemQJobList_loadRecByQref", "SELECT qref, jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob FROM TblWzemQJobList WHERE qref = $1", 1);
	createStatement("TblWzemQJobList_loadRstByJref", "SELECT qref, jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob FROM TblWzemQJobList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQJobList::loadRec(
			PGresult* res
			, WzemQJobList** rec
		) {
	char* ptr;

	WzemQJobList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQJobList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "srefixvjob"),
			PQfnumber(res, "xjref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "suprefwzemmjob")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWzemMPeriod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefIxVJob.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->xjref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->supRefWzemMJob = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQJobList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQJobList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQJobList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "srefixvjob"),
			PQfnumber(res, "xjref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "suprefwzemmjob")
		};

		while (numread < numrow) {
			rec = new WzemQJobList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWzemMPeriod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefIxVJob.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->xjref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->supRefWzemMJob = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQJobList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQJobList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQJobList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQJobList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQJobList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQJobList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQJobList::loadRecBySQL(
			const string& sqlstr
			, WzemQJobList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQJobList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQJobList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJobList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQJobList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQJobList::insertRec(
			WzemQJobList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _xjref = htonl64(rec->xjref);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _supRefWzemMJob = htonl64(rec->supRefWzemMJob);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMPeriod,
		rec->srefIxVJob.c_str(),
		(char*) &_xjref,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_supRefWzemMJob
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemQJobList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQJobList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQJobList::insertRst(
			ListWzemQJobList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQJobList::updateRec(
			WzemQJobList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _xjref = htonl64(rec->xjref);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _supRefWzemMJob = htonl64(rec->supRefWzemMJob);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMPeriod,
		rec->srefIxVJob.c_str(),
		(char*) &_xjref,
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_supRefWzemMJob,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQJobList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQJobList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQJobList::updateRst(
			ListWzemQJobList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQJobList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQJobList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQJobList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQJobList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQJobList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQJobList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQJobList::loadRecByQref(
			ubigint qref
			, WzemQJobList** rec
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

	return loadRecByStmt("TblWzemQJobList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQJobList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJobList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQJobList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQJobList
 ******************************************************************************/

LiteTblWzemQJobList::LiteTblWzemQJobList() :
			TblWzemQJobList()
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

LiteTblWzemQJobList::~LiteTblWzemQJobList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQJobList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQJobList (jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQJobList SET jref = ?1, jnum = ?2, ref = ?3, refWzemMPeriod = ?4, srefIxVJob = ?5, xjref = ?6, x1Startu = ?7, x1Stopu = ?8, supRefWzemMJob = ?9 WHERE qref = ?10");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQJobList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQJobList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob FROM TblWzemQJobList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refWzemMPeriod, srefIxVJob, xjref, x1Startu, x1Stopu, supRefWzemMJob FROM TblWzemQJobList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQJobList::loadRec(
			sqlite3_stmt* stmt
			, WzemQJobList** rec
		) {
	int res;

	WzemQJobList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQJobList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refWzemMPeriod = sqlite3_column_int64(stmt, 4);
		_rec->srefIxVJob.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->xjref = sqlite3_column_int64(stmt, 6);
		_rec->x1Startu = sqlite3_column_double(stmt, 7);
		_rec->x1Stopu = sqlite3_column_double(stmt, 8);
		_rec->supRefWzemMJob = sqlite3_column_int64(stmt, 9);

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

ubigint LiteTblWzemQJobList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQJobList& rst
		) {
	int res; ubigint numread = 0;

	WzemQJobList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQJobList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refWzemMPeriod = sqlite3_column_int64(stmt, 4);
		rec->srefIxVJob.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->xjref = sqlite3_column_int64(stmt, 6);
		rec->x1Startu = sqlite3_column_double(stmt, 7);
		rec->x1Stopu = sqlite3_column_double(stmt, 8);
		rec->supRefWzemMJob = sqlite3_column_int64(stmt, 9);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQJobList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQJobList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQJobList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQJobList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQJobList::loadRecBySQL(
			const string& sqlstr
			, WzemQJobList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQJobList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQJobList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQJobList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQJobList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQJobList::insertRec(
			WzemQJobList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzemMPeriod);
	sqlite3_bind_text(stmtInsertRec, 5, rec->srefIxVJob.c_str(), rec->srefIxVJob.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->xjref);
	sqlite3_bind_double(stmtInsertRec, 7, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 8, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 9, rec->supRefWzemMJob);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJobList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQJobList::insertRst(
			ListWzemQJobList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQJobList::updateRec(
			WzemQJobList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzemMPeriod);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->srefIxVJob.c_str(), rec->srefIxVJob.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->xjref);
	sqlite3_bind_double(stmtUpdateRec, 7, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 8, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->supRefWzemMJob);
	sqlite3_bind_int64(stmtUpdateRec, 10, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJobList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQJobList::updateRst(
			ListWzemQJobList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQJobList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJobList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQJobList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQJobList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQJobList::loadRecByQref(
			ubigint qref
			, WzemQJobList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQJobList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQJobList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif
