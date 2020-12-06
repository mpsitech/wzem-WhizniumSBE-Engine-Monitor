/**
	* \file WzemQEvtList.cpp
	* Dbs and XML wrapper for table TblWzemQEvtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQEvtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQEvtList
 ******************************************************************************/

WzemQEvtList::WzemQEvtList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const double startu
			, const ubigint refWzemMDpch
			, const string Cmd
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->refWzemMPeriod = refWzemMPeriod;
	this->stubRefWzemMPeriod = stubRefWzemMPeriod;
	this->startu = startu;
	this->refWzemMDpch = refWzemMDpch;
	this->Cmd = Cmd;
	this->srefIxVFeatgroup = srefIxVFeatgroup;
	this->srefIxVMethod = srefIxVMethod;
	this->xsref = xsref;
};

void WzemQEvtList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQEvtList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "prd", stubRefWzemMPeriod);
		writeDouble(wr, "sta", startu);
		writeString(wr, "cmd", Cmd);
		writeString(wr, "feg", srefIxVFeatgroup);
		writeString(wr, "mtd", srefIxVMethod);
		writeString(wr, "xsr", xsref);
	} else {
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "stubRefWzemMPeriod", stubRefWzemMPeriod);
		writeDouble(wr, "startu", startu);
		writeString(wr, "Cmd", Cmd);
		writeString(wr, "srefIxVFeatgroup", srefIxVFeatgroup);
		writeString(wr, "srefIxVMethod", srefIxVMethod);
		writeString(wr, "xsref", xsref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQEvtList
 ******************************************************************************/

ListWzemQEvtList::ListWzemQEvtList() {
};

ListWzemQEvtList::ListWzemQEvtList(
			const ListWzemQEvtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQEvtList(*(src.nodes[i]));
};

ListWzemQEvtList::~ListWzemQEvtList() {
	clear();
};

void ListWzemQEvtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQEvtList::size() const {
	return(nodes.size());
};

void ListWzemQEvtList::append(
			WzemQEvtList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQEvtList& ListWzemQEvtList::operator=(
			const ListWzemQEvtList& src
		) {
	WzemQEvtList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQEvtList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQEvtList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQEvtList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQEvtList
 ******************************************************************************/

TblWzemQEvtList::TblWzemQEvtList() {
};

TblWzemQEvtList::~TblWzemQEvtList() {
};

bool TblWzemQEvtList::loadRecBySQL(
			const string& sqlstr
			, WzemQEvtList** rec
		) {
	return false;
};

ubigint TblWzemQEvtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQEvtList& rst
		) {
	return 0;
};

ubigint TblWzemQEvtList::insertRec(
			WzemQEvtList* rec
		) {
	return 0;
};

ubigint TblWzemQEvtList::insertNewRec(
			WzemQEvtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const double startu
			, const ubigint refWzemMDpch
			, const string Cmd
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {
	ubigint retval = 0;
	WzemQEvtList* _rec = NULL;

	_rec = new WzemQEvtList(0, jref, jnum, ref, ixVBasetype, srefIxVBasetype, refWzemMPeriod, stubRefWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQEvtList::appendNewRecToRst(
			ListWzemQEvtList& rst
			, WzemQEvtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const ubigint refWzemMPeriod
			, const string stubRefWzemMPeriod
			, const double startu
			, const ubigint refWzemMDpch
			, const string Cmd
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {
	ubigint retval = 0;
	WzemQEvtList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, ixVBasetype, srefIxVBasetype, refWzemMPeriod, stubRefWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQEvtList::insertRst(
			ListWzemQEvtList& rst
		) {
};

void TblWzemQEvtList::updateRec(
			WzemQEvtList* rec
		) {
};

void TblWzemQEvtList::updateRst(
			ListWzemQEvtList& rst
		) {
};

void TblWzemQEvtList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQEvtList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQEvtList::loadRecByQref(
			ubigint qref
			, WzemQEvtList** rec
		) {
	return false;
};

ubigint TblWzemQEvtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQEvtList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQEvtList
 ******************************************************************************/

MyTblWzemQEvtList::MyTblWzemQEvtList() :
			TblWzemQEvtList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQEvtList::~MyTblWzemQEvtList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQEvtList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQEvtList (jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQEvtList SET jref = ?, jnum = ?, ref = ?, ixVBasetype = ?, refWzemMPeriod = ?, startu = ?, refWzemMDpch = ?, Cmd = ?, srefIxVFeatgroup = ?, srefIxVMethod = ?, xsref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQEvtList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQEvtList WHERE jref = ?", false);
};

bool MyTblWzemQEvtList::loadRecBySQL(
			const string& sqlstr
			, WzemQEvtList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQEvtList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQEvtList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQEvtList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQEvtList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->ixVBasetype = atol((char*) dbrow[4]); else _rec->ixVBasetype = 0;
		if (dbrow[5]) _rec->refWzemMPeriod = atoll((char*) dbrow[5]); else _rec->refWzemMPeriod = 0;
		if (dbrow[6]) _rec->startu = atof((char*) dbrow[6]); else _rec->startu = 0.0;
		if (dbrow[7]) _rec->refWzemMDpch = atoll((char*) dbrow[7]); else _rec->refWzemMDpch = 0;
		if (dbrow[8]) _rec->Cmd.assign(dbrow[8], dblengths[8]); else _rec->Cmd = "";
		if (dbrow[9]) _rec->srefIxVFeatgroup.assign(dbrow[9], dblengths[9]); else _rec->srefIxVFeatgroup = "";
		if (dbrow[10]) _rec->srefIxVMethod.assign(dbrow[10], dblengths[10]); else _rec->srefIxVMethod = "";
		if (dbrow[11]) _rec->xsref.assign(dbrow[11], dblengths[11]); else _rec->xsref = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQEvtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQEvtList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQEvtList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQEvtList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQEvtList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQEvtList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->ixVBasetype = atol((char*) dbrow[4]); else rec->ixVBasetype = 0;
			if (dbrow[5]) rec->refWzemMPeriod = atoll((char*) dbrow[5]); else rec->refWzemMPeriod = 0;
			if (dbrow[6]) rec->startu = atof((char*) dbrow[6]); else rec->startu = 0.0;
			if (dbrow[7]) rec->refWzemMDpch = atoll((char*) dbrow[7]); else rec->refWzemMDpch = 0;
			if (dbrow[8]) rec->Cmd.assign(dbrow[8], dblengths[8]); else rec->Cmd = "";
			if (dbrow[9]) rec->srefIxVFeatgroup.assign(dbrow[9], dblengths[9]); else rec->srefIxVFeatgroup = "";
			if (dbrow[10]) rec->srefIxVMethod.assign(dbrow[10], dblengths[10]); else rec->srefIxVMethod = "";
			if (dbrow[11]) rec->xsref.assign(dbrow[11], dblengths[11]); else rec->xsref = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQEvtList::insertRec(
			WzemQEvtList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[7] = rec->Cmd.length();
	l[8] = rec->srefIxVFeatgroup.length();
	l[9] = rec->srefIxVMethod.length();
	l[10] = rec->xsref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzemMPeriod,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->startu,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWzemMDpch,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Cmd.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefIxVFeatgroup.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefIxVMethod.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQEvtList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQEvtList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQEvtList::insertRst(
			ListWzemQEvtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQEvtList::updateRec(
			WzemQEvtList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[7] = rec->Cmd.length();
	l[8] = rec->srefIxVFeatgroup.length();
	l[9] = rec->srefIxVMethod.length();
	l[10] = rec->xsref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzemMPeriod,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->startu,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWzemMDpch,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Cmd.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefIxVFeatgroup.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefIxVMethod.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQEvtList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQEvtList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQEvtList::updateRst(
			ListWzemQEvtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQEvtList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQEvtList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQEvtList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQEvtList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQEvtList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQEvtList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQEvtList::loadRecByQref(
			ubigint qref
			, WzemQEvtList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQEvtList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQEvtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQEvtList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQEvtList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQEvtList
 ******************************************************************************/

PgTblWzemQEvtList::PgTblWzemQEvtList() :
			TblWzemQEvtList()
			, PgTable()
		{
};

PgTblWzemQEvtList::~PgTblWzemQEvtList() {
};

void PgTblWzemQEvtList::initStatements() {
	createStatement("TblWzemQEvtList_insertRec", "INSERT INTO TblWzemQEvtList (jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWzemQEvtList_updateRec", "UPDATE TblWzemQEvtList SET jref = $1, jnum = $2, ref = $3, ixVBasetype = $4, refWzemMPeriod = $5, startu = $6, refWzemMDpch = $7, Cmd = $8, srefIxVFeatgroup = $9, srefIxVMethod = $10, xsref = $11 WHERE qref = $12", 12);
	createStatement("TblWzemQEvtList_removeRecByQref", "DELETE FROM TblWzemQEvtList WHERE qref = $1", 1);
	createStatement("TblWzemQEvtList_removeRstByJref", "DELETE FROM TblWzemQEvtList WHERE jref = $1", 1);

	createStatement("TblWzemQEvtList_loadRecByQref", "SELECT qref, jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemQEvtList WHERE qref = $1", 1);
	createStatement("TblWzemQEvtList_loadRstByJref", "SELECT qref, jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemQEvtList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQEvtList::loadRec(
			PGresult* res
			, WzemQEvtList** rec
		) {
	char* ptr;

	WzemQEvtList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQEvtList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "startu"),
			PQfnumber(res, "refwzemmdpch"),
			PQfnumber(res, "cmd"),
			PQfnumber(res, "srefixvfeatgroup"),
			PQfnumber(res, "srefixvmethod"),
			PQfnumber(res, "xsref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWzemMPeriod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWzemMDpch = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Cmd.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->srefIxVFeatgroup.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefIxVMethod.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->xsref.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQEvtList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQEvtList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQEvtList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "startu"),
			PQfnumber(res, "refwzemmdpch"),
			PQfnumber(res, "cmd"),
			PQfnumber(res, "srefixvfeatgroup"),
			PQfnumber(res, "srefixvmethod"),
			PQfnumber(res, "xsref")
		};

		while (numread < numrow) {
			rec = new WzemQEvtList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWzemMPeriod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWzemMDpch = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Cmd.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->srefIxVFeatgroup.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefIxVMethod.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->xsref.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQEvtList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQEvtList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQEvtList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQEvtList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQEvtList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQEvtList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQEvtList::loadRecBySQL(
			const string& sqlstr
			, WzemQEvtList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQEvtList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQEvtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQEvtList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQEvtList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQEvtList::insertRec(
			WzemQEvtList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	string _startu = to_string(rec->startu);
	ubigint _refWzemMDpch = htonl64(rec->refWzemMDpch);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_ixVBasetype,
		(char*) &_refWzemMPeriod,
		_startu.c_str(),
		(char*) &_refWzemMDpch,
		rec->Cmd.c_str(),
		rec->srefIxVFeatgroup.c_str(),
		rec->srefIxVMethod.c_str(),
		rec->xsref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemQEvtList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQEvtList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQEvtList::insertRst(
			ListWzemQEvtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQEvtList::updateRec(
			WzemQEvtList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	string _startu = to_string(rec->startu);
	ubigint _refWzemMDpch = htonl64(rec->refWzemMDpch);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_ixVBasetype,
		(char*) &_refWzemMPeriod,
		_startu.c_str(),
		(char*) &_refWzemMDpch,
		rec->Cmd.c_str(),
		rec->srefIxVFeatgroup.c_str(),
		rec->srefIxVMethod.c_str(),
		rec->xsref.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemQEvtList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQEvtList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQEvtList::updateRst(
			ListWzemQEvtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQEvtList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQEvtList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQEvtList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQEvtList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQEvtList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQEvtList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQEvtList::loadRecByQref(
			ubigint qref
			, WzemQEvtList** rec
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

	return loadRecByStmt("TblWzemQEvtList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQEvtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQEvtList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQEvtList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQEvtList
 ******************************************************************************/

LiteTblWzemQEvtList::LiteTblWzemQEvtList() :
			TblWzemQEvtList()
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

LiteTblWzemQEvtList::~LiteTblWzemQEvtList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQEvtList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQEvtList (jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQEvtList SET jref = ?1, jnum = ?2, ref = ?3, ixVBasetype = ?4, refWzemMPeriod = ?5, startu = ?6, refWzemMDpch = ?7, Cmd = ?8, srefIxVFeatgroup = ?9, srefIxVMethod = ?10, xsref = ?11 WHERE qref = ?12");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQEvtList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQEvtList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemQEvtList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, ixVBasetype, refWzemMPeriod, startu, refWzemMDpch, Cmd, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemQEvtList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQEvtList::loadRec(
			sqlite3_stmt* stmt
			, WzemQEvtList** rec
		) {
	int res;

	WzemQEvtList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQEvtList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->ixVBasetype = sqlite3_column_int(stmt, 4);
		_rec->refWzemMPeriod = sqlite3_column_int64(stmt, 5);
		_rec->startu = sqlite3_column_double(stmt, 6);
		_rec->refWzemMDpch = sqlite3_column_int64(stmt, 7);
		_rec->Cmd.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->srefIxVFeatgroup.assign((const char*) sqlite3_column_text(stmt, 9));
		_rec->srefIxVMethod.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->xsref.assign((const char*) sqlite3_column_text(stmt, 11));

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

ubigint LiteTblWzemQEvtList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQEvtList& rst
		) {
	int res; ubigint numread = 0;

	WzemQEvtList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQEvtList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->ixVBasetype = sqlite3_column_int(stmt, 4);
		rec->refWzemMPeriod = sqlite3_column_int64(stmt, 5);
		rec->startu = sqlite3_column_double(stmt, 6);
		rec->refWzemMDpch = sqlite3_column_int64(stmt, 7);
		rec->Cmd.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->srefIxVFeatgroup.assign((const char*) sqlite3_column_text(stmt, 9));
		rec->srefIxVMethod.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->xsref.assign((const char*) sqlite3_column_text(stmt, 11));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQEvtList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQEvtList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQEvtList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQEvtList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQEvtList::loadRecBySQL(
			const string& sqlstr
			, WzemQEvtList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQEvtList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQEvtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQEvtList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQEvtList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQEvtList::insertRec(
			WzemQEvtList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixVBasetype);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refWzemMPeriod);
	sqlite3_bind_double(stmtInsertRec, 6, rec->startu);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->refWzemMDpch);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Cmd.c_str(), rec->Cmd.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 9, rec->srefIxVFeatgroup.c_str(), rec->srefIxVFeatgroup.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 10, rec->srefIxVMethod.c_str(), rec->srefIxVMethod.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 11, rec->xsref.c_str(), rec->xsref.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQEvtList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQEvtList::insertRst(
			ListWzemQEvtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQEvtList::updateRec(
			WzemQEvtList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixVBasetype);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refWzemMPeriod);
	sqlite3_bind_double(stmtUpdateRec, 6, rec->startu);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->refWzemMDpch);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Cmd.c_str(), rec->Cmd.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 9, rec->srefIxVFeatgroup.c_str(), rec->srefIxVFeatgroup.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->srefIxVMethod.c_str(), rec->srefIxVMethod.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->xsref.c_str(), rec->xsref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQEvtList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQEvtList::updateRst(
			ListWzemQEvtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQEvtList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQEvtList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQEvtList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQEvtList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQEvtList::loadRecByQref(
			ubigint qref
			, WzemQEvtList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQEvtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQEvtList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif
