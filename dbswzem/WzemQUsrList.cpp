/**
	* \file WzemQUsrList.cpp
	* Dbs and XML wrapper for table TblWzemQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQUsrList
 ******************************************************************************/

WzemQUsrList::WzemQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWzemMPerson
			, const string stubRefWzemMPerson
			, const string sref
			, const ubigint refWzemMUsergroup
			, const string stubRefWzemMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWzemVLocale
			, const string srefIxWzemVLocale
			, const string titIxWzemVLocale
			, const uint ixWzemVUserlevel
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refWzemMPerson = refWzemMPerson;
	this->stubRefWzemMPerson = stubRefWzemMPerson;
	this->sref = sref;
	this->refWzemMUsergroup = refWzemMUsergroup;
	this->stubRefWzemMUsergroup = stubRefWzemMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixWzemVLocale = ixWzemVLocale;
	this->srefIxWzemVLocale = srefIxWzemVLocale;
	this->titIxWzemVLocale = titIxWzemVLocale;
	this->ixWzemVUserlevel = ixWzemVUserlevel;
	this->srefIxWzemVUserlevel = srefIxWzemVUserlevel;
	this->titIxWzemVUserlevel = titIxWzemVUserlevel;
};

void WzemQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "prs", stubRefWzemMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefWzemMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxWzemVLocale);
		writeString(wr, "lcl2", titIxWzemVLocale);
		writeString(wr, "ulv", srefIxWzemVUserlevel);
		writeString(wr, "ulv2", titIxWzemVUserlevel);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefWzemMPerson", stubRefWzemMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWzemMUsergroup", stubRefWzemMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxWzemVLocale", srefIxWzemVLocale);
		writeString(wr, "titIxWzemVLocale", titIxWzemVLocale);
		writeString(wr, "srefIxWzemVUserlevel", srefIxWzemVUserlevel);
		writeString(wr, "titIxWzemVUserlevel", titIxWzemVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQUsrList
 ******************************************************************************/

ListWzemQUsrList::ListWzemQUsrList() {
};

ListWzemQUsrList::ListWzemQUsrList(
			const ListWzemQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQUsrList(*(src.nodes[i]));
};

ListWzemQUsrList::~ListWzemQUsrList() {
	clear();
};

void ListWzemQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQUsrList::size() const {
	return(nodes.size());
};

void ListWzemQUsrList::append(
			WzemQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQUsrList& ListWzemQUsrList::operator=(
			const ListWzemQUsrList& src
		) {
	WzemQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQUsrList
 ******************************************************************************/

TblWzemQUsrList::TblWzemQUsrList() {
};

TblWzemQUsrList::~TblWzemQUsrList() {
};

bool TblWzemQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrList** rec
		) {
	return false;
};

ubigint TblWzemQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrList& rst
		) {
	return 0;
};

ubigint TblWzemQUsrList::insertRec(
			WzemQUsrList* rec
		) {
	return 0;
};

ubigint TblWzemQUsrList::insertNewRec(
			WzemQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWzemMPerson
			, const string stubRefWzemMPerson
			, const string sref
			, const ubigint refWzemMUsergroup
			, const string stubRefWzemMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWzemVLocale
			, const string srefIxWzemVLocale
			, const string titIxWzemVLocale
			, const uint ixWzemVUserlevel
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	ubigint retval = 0;
	WzemQUsrList* _rec = NULL;

	_rec = new WzemQUsrList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWzemMPerson, stubRefWzemMPerson, sref, refWzemMUsergroup, stubRefWzemMUsergroup, ixVState, srefIxVState, titIxVState, ixWzemVLocale, srefIxWzemVLocale, titIxWzemVLocale, ixWzemVUserlevel, srefIxWzemVUserlevel, titIxWzemVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQUsrList::appendNewRecToRst(
			ListWzemQUsrList& rst
			, WzemQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWzemMPerson
			, const string stubRefWzemMPerson
			, const string sref
			, const ubigint refWzemMUsergroup
			, const string stubRefWzemMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWzemVLocale
			, const string srefIxWzemVLocale
			, const string titIxWzemVLocale
			, const uint ixWzemVUserlevel
			, const string srefIxWzemVUserlevel
			, const string titIxWzemVUserlevel
		) {
	ubigint retval = 0;
	WzemQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWzemMPerson, stubRefWzemMPerson, sref, refWzemMUsergroup, stubRefWzemMUsergroup, ixVState, srefIxVState, titIxVState, ixWzemVLocale, srefIxWzemVLocale, titIxWzemVLocale, ixWzemVUserlevel, srefIxWzemVUserlevel, titIxWzemVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQUsrList::insertRst(
			ListWzemQUsrList& rst
		) {
};

void TblWzemQUsrList::updateRec(
			WzemQUsrList* rec
		) {
};

void TblWzemQUsrList::updateRst(
			ListWzemQUsrList& rst
		) {
};

void TblWzemQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQUsrList::loadRecByQref(
			ubigint qref
			, WzemQUsrList** rec
		) {
	return false;
};

ubigint TblWzemQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQUsrList
 ******************************************************************************/

MyTblWzemQUsrList::MyTblWzemQUsrList() :
			TblWzemQUsrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQUsrList::~MyTblWzemQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQUsrList (jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQUsrList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refWzemMPerson = ?, sref = ?, refWzemMUsergroup = ?, ixVState = ?, ixWzemVLocale = ?, ixWzemVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQUsrList WHERE jref = ?", false);
};

bool MyTblWzemQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQUsrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQUsrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refWzemMPerson = atoll((char*) dbrow[6]); else _rec->refWzemMPerson = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->refWzemMUsergroup = atoll((char*) dbrow[8]); else _rec->refWzemMUsergroup = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->ixWzemVLocale = atol((char*) dbrow[10]); else _rec->ixWzemVLocale = 0;
		if (dbrow[11]) _rec->ixWzemVUserlevel = atol((char*) dbrow[11]); else _rec->ixWzemVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQUsrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQUsrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refWzemMPerson = atoll((char*) dbrow[6]); else rec->refWzemMPerson = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->refWzemMUsergroup = atoll((char*) dbrow[8]); else rec->refWzemMUsergroup = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->ixWzemVLocale = atol((char*) dbrow[10]); else rec->ixWzemVLocale = 0;
			if (dbrow[11]) rec->ixWzemVUserlevel = atol((char*) dbrow[11]); else rec->ixWzemVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQUsrList::insertRec(
			WzemQUsrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWzemMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWzemMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzemVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWzemVUserlevel,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQUsrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQUsrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQUsrList::insertRst(
			ListWzemQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQUsrList::updateRec(
			WzemQUsrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWzemMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWzemMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzemVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWzemVUserlevel,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQUsrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQUsrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQUsrList::updateRst(
			ListWzemQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQUsrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQUsrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQUsrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQUsrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQUsrList::loadRecByQref(
			ubigint qref
			, WzemQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQUsrList
 ******************************************************************************/

PgTblWzemQUsrList::PgTblWzemQUsrList() :
			TblWzemQUsrList()
			, PgTable()
		{
};

PgTblWzemQUsrList::~PgTblWzemQUsrList() {
};

void PgTblWzemQUsrList::initStatements() {
	createStatement("TblWzemQUsrList_insertRec", "INSERT INTO TblWzemQUsrList (jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWzemQUsrList_updateRec", "UPDATE TblWzemQUsrList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, refWzemMPerson = $6, sref = $7, refWzemMUsergroup = $8, ixVState = $9, ixWzemVLocale = $10, ixWzemVUserlevel = $11 WHERE qref = $12", 12);
	createStatement("TblWzemQUsrList_removeRecByQref", "DELETE FROM TblWzemQUsrList WHERE qref = $1", 1);
	createStatement("TblWzemQUsrList_removeRstByJref", "DELETE FROM TblWzemQUsrList WHERE jref = $1", 1);

	createStatement("TblWzemQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel FROM TblWzemQUsrList WHERE qref = $1", 1);
	createStatement("TblWzemQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel FROM TblWzemQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQUsrList::loadRec(
			PGresult* res
			, WzemQUsrList** rec
		) {
	char* ptr;

	WzemQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwzemvlocale"),
			PQfnumber(res, "ixwzemvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWzemMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWzemMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWzemVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixWzemVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQUsrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwzemvlocale"),
			PQfnumber(res, "ixwzemvuserlevel")
		};

		while (numread < numrow) {
			rec = new WzemQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWzemMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWzemMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWzemVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixWzemVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQUsrList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQUsrList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQUsrList::insertRec(
			WzemQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWzemVLocale = htonl(rec->ixWzemVLocale);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWzemMPerson,
		rec->sref.c_str(),
		(char*) &_refWzemMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixWzemVLocale,
		(char*) &_ixWzemVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQUsrList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQUsrList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQUsrList::insertRst(
			ListWzemQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQUsrList::updateRec(
			WzemQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWzemVLocale = htonl(rec->ixWzemVLocale);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWzemMPerson,
		rec->sref.c_str(),
		(char*) &_refWzemMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixWzemVLocale,
		(char*) &_ixWzemVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemQUsrList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQUsrList::updateRst(
			ListWzemQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQUsrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQUsrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQUsrList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQUsrList::loadRecByQref(
			ubigint qref
			, WzemQUsrList** rec
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

	return loadRecByStmt("TblWzemQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQUsrList
 ******************************************************************************/

LiteTblWzemQUsrList::LiteTblWzemQUsrList() :
			TblWzemQUsrList()
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

LiteTblWzemQUsrList::~LiteTblWzemQUsrList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQUsrList (jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQUsrList SET jref = ?1, jnum = ?2, ref = ?3, grp = ?4, own = ?5, refWzemMPerson = ?6, sref = ?7, refWzemMUsergroup = ?8, ixVState = ?9, ixWzemVLocale = ?10, ixWzemVUserlevel = ?11 WHERE qref = ?12");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQUsrList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQUsrList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel FROM TblWzemQUsrList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, grp, own, refWzemMPerson, sref, refWzemMUsergroup, ixVState, ixWzemVLocale, ixWzemVUserlevel FROM TblWzemQUsrList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQUsrList::loadRec(
			sqlite3_stmt* stmt
			, WzemQUsrList** rec
		) {
	int res;

	WzemQUsrList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQUsrList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->grp = sqlite3_column_int64(stmt, 4);
		_rec->own = sqlite3_column_int64(stmt, 5);
		_rec->refWzemMPerson = sqlite3_column_int64(stmt, 6);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 8);
		_rec->ixVState = sqlite3_column_int(stmt, 9);
		_rec->ixWzemVLocale = sqlite3_column_int(stmt, 10);
		_rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 11);

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

ubigint LiteTblWzemQUsrList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQUsrList& rst
		) {
	int res; ubigint numread = 0;

	WzemQUsrList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQUsrList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->grp = sqlite3_column_int64(stmt, 4);
		rec->own = sqlite3_column_int64(stmt, 5);
		rec->refWzemMPerson = sqlite3_column_int64(stmt, 6);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 8);
		rec->ixVState = sqlite3_column_int(stmt, 9);
		rec->ixWzemVLocale = sqlite3_column_int(stmt, 10);
		rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 11);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQUsrList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQUsrList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQUsrList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQUsrList::loadRecBySQL(
			const string& sqlstr
			, WzemQUsrList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQUsrList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQUsrList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQUsrList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQUsrList::insertRec(
			WzemQUsrList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->own);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->refWzemMPerson);
	sqlite3_bind_text(stmtInsertRec, 7, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 8, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixVState);
	sqlite3_bind_int(stmtInsertRec, 10, rec->ixWzemVLocale);
	sqlite3_bind_int(stmtInsertRec, 11, rec->ixWzemVUserlevel);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQUsrList::insertRst(
			ListWzemQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQUsrList::updateRec(
			WzemQUsrList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->own);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->refWzemMPerson);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->refWzemMUsergroup);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixVState);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->ixWzemVLocale);
	sqlite3_bind_int(stmtUpdateRec, 11, rec->ixWzemVUserlevel);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQUsrList::updateRst(
			ListWzemQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQUsrList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQUsrList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQUsrList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQUsrList::loadRecByQref(
			ubigint qref
			, WzemQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQUsrList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

