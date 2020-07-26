/**
	* \file WzemQNdeList.cpp
	* Dbs and XML wrapper for table TblWzemQNdeList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemQNdeList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQNdeList
 ******************************************************************************/

WzemQNdeList::WzemQNdeList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const double x1Startu
			, const double x1Stopu
			, const usmallint Port
			, const utinyint Opprcn
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refWzemMPeriod = refWzemMPeriod;
	this->stubRefWzemMPeriod = stubRefWzemMPeriod;
	this->xnref = xnref;
	this->Ip = Ip;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->Port = Port;
	this->Opprcn = Opprcn;
};

void WzemQNdeList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQNdeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prd", stubRefWzemMPeriod);
		writeUbigint(wr, "xnr", xnref);
		writeString(wr, "ip", Ip);
		writeDouble(wr, "sta", x1Startu);
		writeDouble(wr, "sto", x1Stopu);
		writeUint(wr, "prt", Port);
		writeUint(wr, "orn", Opprcn);
	} else {
		writeString(wr, "stubRefWzemMPeriod", stubRefWzemMPeriod);
		writeUbigint(wr, "xnref", xnref);
		writeString(wr, "Ip", Ip);
		writeDouble(wr, "x1Startu", x1Startu);
		writeDouble(wr, "x1Stopu", x1Stopu);
		writeUint(wr, "Port", Port);
		writeUint(wr, "Opprcn", Opprcn);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQNdeList
 ******************************************************************************/

ListWzemQNdeList::ListWzemQNdeList() {
};

ListWzemQNdeList::ListWzemQNdeList(
			const ListWzemQNdeList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQNdeList(*(src.nodes[i]));
};

ListWzemQNdeList::~ListWzemQNdeList() {
	clear();
};

void ListWzemQNdeList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQNdeList::size() const {
	return(nodes.size());
};

void ListWzemQNdeList::append(
			WzemQNdeList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQNdeList& ListWzemQNdeList::operator=(
			const ListWzemQNdeList& src
		) {
	WzemQNdeList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQNdeList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQNdeList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQNdeList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQNdeList
 ******************************************************************************/

TblWzemQNdeList::TblWzemQNdeList() {
};

TblWzemQNdeList::~TblWzemQNdeList() {
};

bool TblWzemQNdeList::loadRecBySQL(
			const string& sqlstr
			, WzemQNdeList** rec
		) {
	return false;
};

ubigint TblWzemQNdeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQNdeList& rst
		) {
	return 0;
};

ubigint TblWzemQNdeList::insertRec(
			WzemQNdeList* rec
		) {
	return 0;
};

ubigint TblWzemQNdeList::insertNewRec(
			WzemQNdeList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const double x1Startu
			, const double x1Stopu
			, const usmallint Port
			, const utinyint Opprcn
		) {
	ubigint retval = 0;
	WzemQNdeList* _rec = NULL;

	_rec = new WzemQNdeList(0, jref, jnum, ref, refWzemMPeriod, stubRefWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQNdeList::appendNewRecToRst(
			ListWzemQNdeList& rst
			, WzemQNdeList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const double x1Startu
			, const double x1Stopu
			, const usmallint Port
			, const utinyint Opprcn
		) {
	ubigint retval = 0;
	WzemQNdeList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWzemMPeriod, stubRefWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQNdeList::insertRst(
			ListWzemQNdeList& rst
		) {
};

void TblWzemQNdeList::updateRec(
			WzemQNdeList* rec
		) {
};

void TblWzemQNdeList::updateRst(
			ListWzemQNdeList& rst
		) {
};

void TblWzemQNdeList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQNdeList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQNdeList::loadRecByQref(
			ubigint qref
			, WzemQNdeList** rec
		) {
	return false;
};

ubigint TblWzemQNdeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQNdeList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQNdeList
 ******************************************************************************/

MyTblWzemQNdeList::MyTblWzemQNdeList() :
			TblWzemQNdeList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQNdeList::~MyTblWzemQNdeList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQNdeList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQNdeList (jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQNdeList SET jref = ?, jnum = ?, ref = ?, refWzemMPeriod = ?, xnref = ?, Ip = ?, x1Startu = ?, x1Stopu = ?, Port = ?, Opprcn = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQNdeList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQNdeList WHERE jref = ?", false);
};

bool MyTblWzemQNdeList::loadRecBySQL(
			const string& sqlstr
			, WzemQNdeList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQNdeList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQNdeList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQNdeList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQNdeList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWzemMPeriod = atoll((char*) dbrow[4]); else _rec->refWzemMPeriod = 0;
		if (dbrow[5]) _rec->xnref = atoll((char*) dbrow[5]); else _rec->xnref = 0;
		if (dbrow[6]) _rec->Ip.assign(dbrow[6], dblengths[6]); else _rec->Ip = "";
		if (dbrow[7]) _rec->x1Startu = atof((char*) dbrow[7]); else _rec->x1Startu = 0.0;
		if (dbrow[8]) _rec->x1Stopu = atof((char*) dbrow[8]); else _rec->x1Stopu = 0.0;
		if (dbrow[9]) _rec->Port = atoi((char*) dbrow[9]); else _rec->Port = 0;
		if (dbrow[10]) _rec->Opprcn = atoi((char*) dbrow[10]); else _rec->Opprcn = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQNdeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQNdeList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQNdeList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQNdeList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQNdeList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQNdeList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWzemMPeriod = atoll((char*) dbrow[4]); else rec->refWzemMPeriod = 0;
			if (dbrow[5]) rec->xnref = atoll((char*) dbrow[5]); else rec->xnref = 0;
			if (dbrow[6]) rec->Ip.assign(dbrow[6], dblengths[6]); else rec->Ip = "";
			if (dbrow[7]) rec->x1Startu = atof((char*) dbrow[7]); else rec->x1Startu = 0.0;
			if (dbrow[8]) rec->x1Stopu = atof((char*) dbrow[8]); else rec->x1Stopu = 0.0;
			if (dbrow[9]) rec->Port = atoi((char*) dbrow[9]); else rec->Port = 0;
			if (dbrow[10]) rec->Opprcn = atoi((char*) dbrow[10]); else rec->Opprcn = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQNdeList::insertRec(
			WzemQNdeList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMPeriod,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->xnref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Startu,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x1Stopu,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Port,&(l[8]),&(n[8]),&(e[8])),
		bindUtinyint(&rec->Opprcn,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQNdeList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQNdeList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQNdeList::insertRst(
			ListWzemQNdeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQNdeList::updateRec(
			WzemQNdeList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMPeriod,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->xnref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x1Startu,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x1Stopu,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Port,&(l[8]),&(n[8]),&(e[8])),
		bindUtinyint(&rec->Opprcn,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQNdeList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQNdeList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQNdeList::updateRst(
			ListWzemQNdeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQNdeList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQNdeList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQNdeList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQNdeList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQNdeList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQNdeList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQNdeList::loadRecByQref(
			ubigint qref
			, WzemQNdeList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQNdeList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQNdeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQNdeList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQNdeList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQNdeList
 ******************************************************************************/

PgTblWzemQNdeList::PgTblWzemQNdeList() :
			TblWzemQNdeList()
			, PgTable()
		{
};

PgTblWzemQNdeList::~PgTblWzemQNdeList() {
};

void PgTblWzemQNdeList::initStatements() {
	createStatement("TblWzemQNdeList_insertRec", "INSERT INTO TblWzemQNdeList (jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWzemQNdeList_updateRec", "UPDATE TblWzemQNdeList SET jref = $1, jnum = $2, ref = $3, refWzemMPeriod = $4, xnref = $5, Ip = $6, x1Startu = $7, x1Stopu = $8, Port = $9, Opprcn = $10 WHERE qref = $11", 11);
	createStatement("TblWzemQNdeList_removeRecByQref", "DELETE FROM TblWzemQNdeList WHERE qref = $1", 1);
	createStatement("TblWzemQNdeList_removeRstByJref", "DELETE FROM TblWzemQNdeList WHERE jref = $1", 1);

	createStatement("TblWzemQNdeList_loadRecByQref", "SELECT qref, jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn FROM TblWzemQNdeList WHERE qref = $1", 1);
	createStatement("TblWzemQNdeList_loadRstByJref", "SELECT qref, jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn FROM TblWzemQNdeList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQNdeList::loadRec(
			PGresult* res
			, WzemQNdeList** rec
		) {
	char* ptr;

	WzemQNdeList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQNdeList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "xnref"),
			PQfnumber(res, "ip"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "port"),
			PQfnumber(res, "opprcn")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWzemMPeriod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->xnref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Port = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Opprcn = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQNdeList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQNdeList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQNdeList* rec;

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
			PQfnumber(res, "xnref"),
			PQfnumber(res, "ip"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "port"),
			PQfnumber(res, "opprcn")
		};

		while (numread < numrow) {
			rec = new WzemQNdeList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWzemMPeriod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->xnref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Port = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Opprcn = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQNdeList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQNdeList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQNdeList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQNdeList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQNdeList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQNdeList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQNdeList::loadRecBySQL(
			const string& sqlstr
			, WzemQNdeList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQNdeList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQNdeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQNdeList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQNdeList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQNdeList::insertRec(
			WzemQNdeList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _xnref = htonl64(rec->xnref);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	usmallint _Port = htons(rec->Port);
	usmallint _Opprcn = htons(rec->Opprcn);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMPeriod,
		(char*) &_xnref,
		rec->Ip.c_str(),
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_Port,
		(char*) &_Opprcn
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQNdeList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQNdeList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQNdeList::insertRst(
			ListWzemQNdeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQNdeList::updateRec(
			WzemQNdeList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _xnref = htonl64(rec->xnref);
	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	usmallint _Port = htons(rec->Port);
	usmallint _Opprcn = htons(rec->Opprcn);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWzemMPeriod,
		(char*) &_xnref,
		rec->Ip.c_str(),
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_Port,
		(char*) &_Opprcn,
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
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQNdeList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQNdeList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQNdeList::updateRst(
			ListWzemQNdeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQNdeList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQNdeList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQNdeList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQNdeList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQNdeList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQNdeList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQNdeList::loadRecByQref(
			ubigint qref
			, WzemQNdeList** rec
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

	return loadRecByStmt("TblWzemQNdeList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQNdeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQNdeList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQNdeList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQNdeList
 ******************************************************************************/

LiteTblWzemQNdeList::LiteTblWzemQNdeList() :
			TblWzemQNdeList()
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

LiteTblWzemQNdeList::~LiteTblWzemQNdeList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQNdeList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQNdeList (jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQNdeList SET jref = ?1, jnum = ?2, ref = ?3, refWzemMPeriod = ?4, xnref = ?5, Ip = ?6, x1Startu = ?7, x1Stopu = ?8, Port = ?9, Opprcn = ?10 WHERE qref = ?11");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQNdeList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQNdeList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn FROM TblWzemQNdeList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, refWzemMPeriod, xnref, Ip, x1Startu, x1Stopu, Port, Opprcn FROM TblWzemQNdeList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQNdeList::loadRec(
			sqlite3_stmt* stmt
			, WzemQNdeList** rec
		) {
	int res;

	WzemQNdeList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQNdeList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->refWzemMPeriod = sqlite3_column_int64(stmt, 4);
		_rec->xnref = sqlite3_column_int64(stmt, 5);
		_rec->Ip.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->x1Startu = sqlite3_column_double(stmt, 7);
		_rec->x1Stopu = sqlite3_column_double(stmt, 8);
		_rec->Port = sqlite3_column_int(stmt, 9);
		_rec->Opprcn = sqlite3_column_int(stmt, 10);

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

ubigint LiteTblWzemQNdeList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQNdeList& rst
		) {
	int res; ubigint numread = 0;

	WzemQNdeList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQNdeList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->refWzemMPeriod = sqlite3_column_int64(stmt, 4);
		rec->xnref = sqlite3_column_int64(stmt, 5);
		rec->Ip.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->x1Startu = sqlite3_column_double(stmt, 7);
		rec->x1Stopu = sqlite3_column_double(stmt, 8);
		rec->Port = sqlite3_column_int(stmt, 9);
		rec->Opprcn = sqlite3_column_int(stmt, 10);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQNdeList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQNdeList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQNdeList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQNdeList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQNdeList::loadRecBySQL(
			const string& sqlstr
			, WzemQNdeList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQNdeList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQNdeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQNdeList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQNdeList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQNdeList::insertRec(
			WzemQNdeList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->xnref);
	sqlite3_bind_text(stmtInsertRec, 6, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_double(stmtInsertRec, 7, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 8, rec->x1Stopu);
	sqlite3_bind_int(stmtInsertRec, 9, rec->Port);
	sqlite3_bind_int(stmtInsertRec, 10, rec->Opprcn);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQNdeList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQNdeList::insertRst(
			ListWzemQNdeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQNdeList::updateRec(
			WzemQNdeList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->xnref);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_double(stmtUpdateRec, 7, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 8, rec->x1Stopu);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->Port);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->Opprcn);
	sqlite3_bind_int64(stmtUpdateRec, 11, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQNdeList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQNdeList::updateRst(
			ListWzemQNdeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQNdeList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQNdeList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQNdeList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQNdeList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQNdeList::loadRecByQref(
			ubigint qref
			, WzemQNdeList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQNdeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQNdeList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

