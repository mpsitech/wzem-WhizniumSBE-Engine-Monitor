/**
	* \file WzemQUsrAAccess.cpp
	* Dbs and XML wrapper for table TblWzemQUsrAAccess (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsrAAccess
 ******************************************************************************/

WzemQUsrAAccess::WzemQUsrAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWzemVFeatgroup
			, const string srefX1IxWzemVFeatgroup
			, const string titX1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
			, const string srefsIxWzemWAccess
			, const string titsIxWzemWAccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxWzemVFeatgroup = x1IxWzemVFeatgroup;
	this->srefX1IxWzemVFeatgroup = srefX1IxWzemVFeatgroup;
	this->titX1IxWzemVFeatgroup = titX1IxWzemVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzemWAccess = ixWzemWAccess;
	this->srefsIxWzemWAccess = srefsIxWzemWAccess;
	this->titsIxWzemWAccess = titsIxWzemWAccess;
};

void WzemQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQUsrAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "feg", srefX1IxWzemVFeatgroup);
		writeString(wr, "feg2", titX1IxWzemVFeatgroup);
		writeString(wr, "fea", x2FeaSrefUix);
		writeString(wr, "acc", srefsIxWzemWAccess);
		writeString(wr, "acc2", titsIxWzemWAccess);
	} else {
		writeString(wr, "srefX1IxWzemVFeatgroup", srefX1IxWzemVFeatgroup);
		writeString(wr, "titX1IxWzemVFeatgroup", titX1IxWzemVFeatgroup);
		writeString(wr, "x2FeaSrefUix", x2FeaSrefUix);
		writeString(wr, "srefsIxWzemWAccess", srefsIxWzemWAccess);
		writeString(wr, "titsIxWzemWAccess", titsIxWzemWAccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQUsrAAccess
 ******************************************************************************/

ListWzemQUsrAAccess::ListWzemQUsrAAccess() {
};

ListWzemQUsrAAccess::ListWzemQUsrAAccess(
			const ListWzemQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrAAccess(*(src.nodes[i]));
};

ListWzemQUsrAAccess::~ListWzemQUsrAAccess() {
	clear();
};

void ListWzemQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQUsrAAccess::size() const {
	return(nodes.size());
};

void ListWzemQUsrAAccess::append(
			WzemQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListWzemQUsrAAccess& ListWzemQUsrAAccess::operator=(
			const ListWzemQUsrAAccess& src
		) {
	WzemQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQUsrAAccess
 ******************************************************************************/

TblWzemQUsrAAccess::TblWzemQUsrAAccess() {
};

TblWzemQUsrAAccess::~TblWzemQUsrAAccess() {
};

bool TblWzemQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrAAccess** rec
		) {
	return false;
};

ubigint TblWzemQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	return 0;
};

ubigint TblWzemQUsrAAccess::insertRec(
			WzemQUsrAAccess* rec
		) {
	return 0;
};

ubigint TblWzemQUsrAAccess::insertNewRec(
			WzemQUsrAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWzemVFeatgroup
			, const string srefX1IxWzemVFeatgroup
			, const string titX1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
			, const string srefsIxWzemWAccess
			, const string titsIxWzemWAccess
		) {
	ubigint retval = 0;
	WzemQUsrAAccess* _rec = NULL;

	_rec = new WzemQUsrAAccess(0, jref, jnum, ref, x1IxWzemVFeatgroup, srefX1IxWzemVFeatgroup, titX1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess, srefsIxWzemWAccess, titsIxWzemWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQUsrAAccess::appendNewRecToRst(
			ListWzemQUsrAAccess& rst
			, WzemQUsrAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWzemVFeatgroup
			, const string srefX1IxWzemVFeatgroup
			, const string titX1IxWzemVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWzemWAccess
			, const string srefsIxWzemWAccess
			, const string titsIxWzemWAccess
		) {
	ubigint retval = 0;
	WzemQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxWzemVFeatgroup, srefX1IxWzemVFeatgroup, titX1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess, srefsIxWzemWAccess, titsIxWzemWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQUsrAAccess::insertRst(
			ListWzemQUsrAAccess& rst
		) {
};

void TblWzemQUsrAAccess::updateRec(
			WzemQUsrAAccess* rec
		) {
};

void TblWzemQUsrAAccess::updateRst(
			ListWzemQUsrAAccess& rst
		) {
};

void TblWzemQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQUsrAAccess::loadRecByQref(
			ubigint qref
			, WzemQUsrAAccess** rec
		) {
	return false;
};

ubigint TblWzemQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQUsrAAccess
 ******************************************************************************/

MyTblWzemQUsrAAccess::MyTblWzemQUsrAAccess() :
			TblWzemQUsrAAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQUsrAAccess::~MyTblWzemQUsrAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQUsrAAccess (jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQUsrAAccess SET jref = ?, jnum = ?, ref = ?, x1IxWzemVFeatgroup = ?, x2FeaSrefUix = ?, ixWzemWAccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQUsrAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQUsrAAccess WHERE jref = ?", false);
};

bool MyTblWzemQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQUsrAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQUsrAAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQUsrAAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQUsrAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxWzemVFeatgroup = atol((char*) dbrow[4]); else _rec->x1IxWzemVFeatgroup = 0;
		if (dbrow[5]) _rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else _rec->x2FeaSrefUix = "";
		if (dbrow[6]) _rec->ixWzemWAccess = atol((char*) dbrow[6]); else _rec->ixWzemWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQUsrAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQUsrAAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQUsrAAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQUsrAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxWzemVFeatgroup = atol((char*) dbrow[4]); else rec->x1IxWzemVFeatgroup = 0;
			if (dbrow[5]) rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else rec->x2FeaSrefUix = "";
			if (dbrow[6]) rec->ixWzemWAccess = atol((char*) dbrow[6]); else rec->ixWzemWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQUsrAAccess::insertRec(
			WzemQUsrAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWzemVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWzemWAccess,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQUsrAAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQUsrAAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQUsrAAccess::insertRst(
			ListWzemQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQUsrAAccess::updateRec(
			WzemQUsrAAccess* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWzemVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWzemWAccess,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQUsrAAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQUsrAAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQUsrAAccess::updateRst(
			ListWzemQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQUsrAAccess::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQUsrAAccess::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQUsrAAccess::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQUsrAAccess::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQUsrAAccess::loadRecByQref(
			ubigint qref
			, WzemQUsrAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQUsrAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQUsrAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQUsrAAccess
 ******************************************************************************/

PgTblWzemQUsrAAccess::PgTblWzemQUsrAAccess() :
			TblWzemQUsrAAccess()
			, PgTable()
		{
};

PgTblWzemQUsrAAccess::~PgTblWzemQUsrAAccess() {
};

void PgTblWzemQUsrAAccess::initStatements() {
	createStatement("TblWzemQUsrAAccess_insertRec", "INSERT INTO TblWzemQUsrAAccess (jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWzemQUsrAAccess_updateRec", "UPDATE TblWzemQUsrAAccess SET jref = $1, jnum = $2, ref = $3, x1IxWzemVFeatgroup = $4, x2FeaSrefUix = $5, ixWzemWAccess = $6 WHERE qref = $7", 7);
	createStatement("TblWzemQUsrAAccess_removeRecByQref", "DELETE FROM TblWzemQUsrAAccess WHERE qref = $1", 1);
	createStatement("TblWzemQUsrAAccess_removeRstByJref", "DELETE FROM TblWzemQUsrAAccess WHERE jref = $1", 1);

	createStatement("TblWzemQUsrAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemQUsrAAccess WHERE qref = $1", 1);
	createStatement("TblWzemQUsrAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemQUsrAAccess WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQUsrAAccess::loadRec(
			PGresult* res
			, WzemQUsrAAccess** rec
		) {
	char* ptr;

	WzemQUsrAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQUsrAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixwzemvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwzemwaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxWzemVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWzemWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQUsrAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQUsrAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixwzemvfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwzemwaccess")
		};

		while (numread < numrow) {
			rec = new WzemQUsrAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxWzemVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWzemWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQUsrAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrAAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQUsrAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrAAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQUsrAAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQUsrAAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQUsrAAccess::insertRec(
			WzemQUsrAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxWzemVFeatgroup = htonl(rec->x1IxWzemVFeatgroup);
	uint _ixWzemWAccess = htonl(rec->ixWzemWAccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxWzemVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWzemWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemQUsrAAccess_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrAAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQUsrAAccess::insertRst(
			ListWzemQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQUsrAAccess::updateRec(
			WzemQUsrAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxWzemVFeatgroup = htonl(rec->x1IxWzemVFeatgroup);
	uint _ixWzemWAccess = htonl(rec->ixWzemWAccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxWzemVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWzemWAccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQUsrAAccess_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrAAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQUsrAAccess::updateRst(
			ListWzemQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQUsrAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQUsrAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrAAccess::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQUsrAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQUsrAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrAAccess::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQUsrAAccess::loadRecByQref(
			ubigint qref
			, WzemQUsrAAccess** rec
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

	return loadRecByStmt("TblWzemQUsrAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQUsrAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQUsrAAccess
 ******************************************************************************/

LiteTblWzemQUsrAAccess::LiteTblWzemQUsrAAccess() :
			TblWzemQUsrAAccess()
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

LiteTblWzemQUsrAAccess::~LiteTblWzemQUsrAAccess() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQUsrAAccess (jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess) VALUES (?1,?2,?3,?4,?5,?6)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQUsrAAccess SET jref = ?1, jnum = ?2, ref = ?3, x1IxWzemVFeatgroup = ?4, x2FeaSrefUix = ?5, ixWzemWAccess = ?6 WHERE qref = ?7");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQUsrAAccess WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQUsrAAccess WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemQUsrAAccess WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, x1IxWzemVFeatgroup, x2FeaSrefUix, ixWzemWAccess FROM TblWzemQUsrAAccess WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQUsrAAccess::loadRec(
			sqlite3_stmt* stmt
			, WzemQUsrAAccess** rec
		) {
	int res;

	WzemQUsrAAccess* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQUsrAAccess();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->x1IxWzemVFeatgroup = sqlite3_column_int(stmt, 4);
		_rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->ixWzemWAccess = sqlite3_column_int(stmt, 6);

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

ubigint LiteTblWzemQUsrAAccess::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	int res; ubigint numread = 0;

	WzemQUsrAAccess* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQUsrAAccess();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->x1IxWzemVFeatgroup = sqlite3_column_int(stmt, 4);
		rec->x2FeaSrefUix.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->ixWzemWAccess = sqlite3_column_int(stmt, 6);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQUsrAAccess::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQUsrAAccess** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrAAccess::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrAAccess** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQUsrAAccess::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQUsrAAccess::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrAAccess::insertRec(
			WzemQUsrAAccess* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->x1IxWzemVFeatgroup);
	sqlite3_bind_text(stmtInsertRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 6, rec->ixWzemWAccess);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrAAccess::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQUsrAAccess::insertRst(
			ListWzemQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQUsrAAccess::updateRec(
			WzemQUsrAAccess* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->x1IxWzemVFeatgroup);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->x2FeaSrefUix.c_str(), rec->x2FeaSrefUix.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->ixWzemWAccess);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrAAccess::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQUsrAAccess::updateRst(
			ListWzemQUsrAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrAAccess::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrAAccess::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQUsrAAccess::loadRecByQref(
			ubigint qref
			, WzemQUsrAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrAAccess& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

