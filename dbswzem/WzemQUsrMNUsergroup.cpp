/**
	* \file WzemQUsrMNUsergroup.cpp
	* Dbs and XML wrapper for table TblWzemQUsrMNUsergroup (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQUsrMNUsergroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsrMNUsergroup
 ******************************************************************************/

WzemQUsrMNUsergroup::WzemQUsrMNUsergroup(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWzemVUserlevel
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixWzemVUserlevel = ixWzemVUserlevel;
	this->srefIxWzemVUserlevel = srefIxWzemVUserlevel;
	this->titIxWzemVUserlevel = titIxWzemVUserlevel;
};

void WzemQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQUsrMNUsergroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxWzemVUserlevel);
		writeString(wr, "ulv2", titIxWzemVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxWzemVUserlevel", srefIxWzemVUserlevel);
		writeString(wr, "titIxWzemVUserlevel", titIxWzemVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQUsrMNUsergroup
 ******************************************************************************/

ListWzemQUsrMNUsergroup::ListWzemQUsrMNUsergroup() {
};

ListWzemQUsrMNUsergroup::ListWzemQUsrMNUsergroup(
			const ListWzemQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrMNUsergroup(*(src.nodes[i]));
};

ListWzemQUsrMNUsergroup::~ListWzemQUsrMNUsergroup() {
	clear();
};

void ListWzemQUsrMNUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQUsrMNUsergroup::size() const {
	return(nodes.size());
};

void ListWzemQUsrMNUsergroup::append(
			WzemQUsrMNUsergroup* rec
		) {
	nodes.push_back(rec);
};

ListWzemQUsrMNUsergroup& ListWzemQUsrMNUsergroup::operator=(
			const ListWzemQUsrMNUsergroup& src
		) {
	WzemQUsrMNUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQUsrMNUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQUsrMNUsergroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQUsrMNUsergroup
 ******************************************************************************/

TblWzemQUsrMNUsergroup::TblWzemQUsrMNUsergroup() {
};

TblWzemQUsrMNUsergroup::~TblWzemQUsrMNUsergroup() {
};

bool TblWzemQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblWzemQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	return 0;
};

ubigint TblWzemQUsrMNUsergroup::insertRec(
			WzemQUsrMNUsergroup* rec
		) {
	return 0;
};

ubigint TblWzemQUsrMNUsergroup::insertNewRec(
			WzemQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWzemVUserlevel
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	ubigint retval = 0;
	WzemQUsrMNUsergroup* _rec = NULL;

	_rec = new WzemQUsrMNUsergroup(0, jref, jnum, mref, stubMref, ref, ixWzemVUserlevel, srefIxWzemVUserlevel, titIxWzemVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQUsrMNUsergroup::appendNewRecToRst(
			ListWzemQUsrMNUsergroup& rst
			, WzemQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixWzemVUserlevel
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	ubigint retval = 0;
	WzemQUsrMNUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixWzemVUserlevel, srefIxWzemVUserlevel, titIxWzemVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQUsrMNUsergroup::insertRst(
			ListWzemQUsrMNUsergroup& rst
		) {
};

void TblWzemQUsrMNUsergroup::updateRec(
			WzemQUsrMNUsergroup* rec
		) {
};

void TblWzemQUsrMNUsergroup::updateRst(
			ListWzemQUsrMNUsergroup& rst
		) {
};

void TblWzemQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WzemQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblWzemQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQUsrMNUsergroup
 ******************************************************************************/

MyTblWzemQUsrMNUsergroup::MyTblWzemQUsrMNUsergroup() :
			TblWzemQUsrMNUsergroup()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQUsrMNUsergroup::~MyTblWzemQUsrMNUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQUsrMNUsergroup (jref, jnum, mref, ref, ixWzemVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQUsrMNUsergroup SET jref = ?, jnum = ?, mref = ?, ref = ?, ixWzemVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQUsrMNUsergroup WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQUsrMNUsergroup WHERE jref = ?", false);
};

bool MyTblWzemQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrMNUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQUsrMNUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQUsrMNUsergroup::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQUsrMNUsergroup::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemQUsrMNUsergroup();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixWzemVUserlevel = atol((char*) dbrow[5]); else _rec->ixWzemVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQUsrMNUsergroup::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQUsrMNUsergroup::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemQUsrMNUsergroup();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixWzemVUserlevel = atol((char*) dbrow[5]); else rec->ixWzemVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQUsrMNUsergroup::insertRec(
			WzemQUsrMNUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzemVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQUsrMNUsergroup::insertRst(
			ListWzemQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQUsrMNUsergroup::updateRec(
			WzemQUsrMNUsergroup* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzemVUserlevel,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQUsrMNUsergroup::updateRst(
			ListWzemQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQUsrMNUsergroup::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WzemQUsrMNUsergroup** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQUsrMNUsergroup WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQUsrMNUsergroup WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQUsrMNUsergroup
 ******************************************************************************/

PgTblWzemQUsrMNUsergroup::PgTblWzemQUsrMNUsergroup() :
			TblWzemQUsrMNUsergroup()
			, PgTable()
		{
};

PgTblWzemQUsrMNUsergroup::~PgTblWzemQUsrMNUsergroup() {
};

void PgTblWzemQUsrMNUsergroup::initStatements() {
	createStatement("TblWzemQUsrMNUsergroup_insertRec", "INSERT INTO TblWzemQUsrMNUsergroup (jref, jnum, mref, ref, ixWzemVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWzemQUsrMNUsergroup_updateRec", "UPDATE TblWzemQUsrMNUsergroup SET jref = $1, jnum = $2, mref = $3, ref = $4, ixWzemVUserlevel = $5 WHERE qref = $6", 6);
	createStatement("TblWzemQUsrMNUsergroup_removeRecByQref", "DELETE FROM TblWzemQUsrMNUsergroup WHERE qref = $1", 1);
	createStatement("TblWzemQUsrMNUsergroup_removeRstByJref", "DELETE FROM TblWzemQUsrMNUsergroup WHERE jref = $1", 1);

	createStatement("TblWzemQUsrMNUsergroup_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixWzemVUserlevel FROM TblWzemQUsrMNUsergroup WHERE qref = $1", 1);
	createStatement("TblWzemQUsrMNUsergroup_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixWzemVUserlevel FROM TblWzemQUsrMNUsergroup WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQUsrMNUsergroup::loadRec(
			PGresult* res
			, WzemQUsrMNUsergroup** rec
		) {
	char* ptr;

	WzemQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQUsrMNUsergroup();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwzemvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWzemVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQUsrMNUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwzemvuserlevel")
		};

		while (numread < numrow) {
			rec = new WzemQUsrMNUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWzemVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQUsrMNUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrMNUsergroup::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQUsrMNUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrMNUsergroup::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQUsrMNUsergroup::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQUsrMNUsergroup::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQUsrMNUsergroup::insertRec(
			WzemQUsrMNUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixWzemVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQUsrMNUsergroup_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrMNUsergroup::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQUsrMNUsergroup::insertRst(
			ListWzemQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQUsrMNUsergroup::updateRec(
			WzemQUsrMNUsergroup* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixWzemVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQUsrMNUsergroup_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrMNUsergroup::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQUsrMNUsergroup::updateRst(
			ListWzemQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQUsrMNUsergroup::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQUsrMNUsergroup_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrMNUsergroup::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQUsrMNUsergroup::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQUsrMNUsergroup_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrMNUsergroup::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WzemQUsrMNUsergroup** rec
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

	return loadRecByStmt("TblWzemQUsrMNUsergroup_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQUsrMNUsergroup_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQUsrMNUsergroup
 ******************************************************************************/

LiteTblWzemQUsrMNUsergroup::LiteTblWzemQUsrMNUsergroup() :
			TblWzemQUsrMNUsergroup()
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

LiteTblWzemQUsrMNUsergroup::~LiteTblWzemQUsrMNUsergroup() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQUsrMNUsergroup (jref, jnum, mref, ref, ixWzemVUserlevel) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQUsrMNUsergroup SET jref = ?1, jnum = ?2, mref = ?3, ref = ?4, ixWzemVUserlevel = ?5 WHERE qref = ?6");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQUsrMNUsergroup WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQUsrMNUsergroup WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, mref, ref, ixWzemVUserlevel FROM TblWzemQUsrMNUsergroup WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, mref, ref, ixWzemVUserlevel FROM TblWzemQUsrMNUsergroup WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQUsrMNUsergroup::loadRec(
			sqlite3_stmt* stmt
			, WzemQUsrMNUsergroup** rec
		) {
	int res;

	WzemQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQUsrMNUsergroup();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->mref = sqlite3_column_int64(stmt, 3);
		_rec->ref = sqlite3_column_int64(stmt, 4);
		_rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 5);

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

ubigint LiteTblWzemQUsrMNUsergroup::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	int res; ubigint numread = 0;

	WzemQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQUsrMNUsergroup();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->mref = sqlite3_column_int64(stmt, 3);
		rec->ref = sqlite3_column_int64(stmt, 4);
		rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 5);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQUsrMNUsergroup::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQUsrMNUsergroup** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrMNUsergroup::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrMNUsergroup** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQUsrMNUsergroup::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQUsrMNUsergroup::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrMNUsergroup::insertRec(
			WzemQUsrMNUsergroup* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->mref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixWzemVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrMNUsergroup::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQUsrMNUsergroup::insertRst(
			ListWzemQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQUsrMNUsergroup::updateRec(
			WzemQUsrMNUsergroup* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->mref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixWzemVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrMNUsergroup::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQUsrMNUsergroup::updateRst(
			ListWzemQUsrMNUsergroup& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrMNUsergroup::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrMNUsergroup::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, WzemQUsrMNUsergroup** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrMNUsergroup& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

