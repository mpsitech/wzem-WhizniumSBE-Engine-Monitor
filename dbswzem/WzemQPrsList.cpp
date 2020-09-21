/**
	* \file WzemQPrsList.cpp
	* Dbs and XML wrapper for table TblWzemQPrsList (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemQPrsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzemQPrsList
 ******************************************************************************/

WzemQPrsList::WzemQPrsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->ixVSex = ixVSex;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

void WzemQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WzemQPrsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "tit", Title);
		writeString(wr, "fnm", Firstname);
		writeString(wr, "lnm", Lastname);
		writeString(wr, "sex", srefIxVSex);
		writeString(wr, "sex2", titIxVSex);
		writeString(wr, "tel", telVal);
		writeString(wr, "eml", emlVal);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "Title", Title);
		writeString(wr, "Firstname", Firstname);
		writeString(wr, "Lastname", Lastname);
		writeString(wr, "srefIxVSex", srefIxVSex);
		writeString(wr, "titIxVSex", titIxVSex);
		writeString(wr, "telVal", telVal);
		writeString(wr, "emlVal", emlVal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWzemQPrsList
 ******************************************************************************/

ListWzemQPrsList::ListWzemQPrsList() {
};

ListWzemQPrsList::ListWzemQPrsList(
			const ListWzemQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemQPrsList(*(src.nodes[i]));
};

ListWzemQPrsList::~ListWzemQPrsList() {
	clear();
};

void ListWzemQPrsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemQPrsList::size() const {
	return(nodes.size());
};

void ListWzemQPrsList::append(
			WzemQPrsList* rec
		) {
	nodes.push_back(rec);
};

ListWzemQPrsList& ListWzemQPrsList::operator=(
			const ListWzemQPrsList& src
		) {
	WzemQPrsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemQPrsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWzemQPrsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWzemQPrsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWzemQPrsList
 ******************************************************************************/

TblWzemQPrsList::TblWzemQPrsList() {
};

TblWzemQPrsList::~TblWzemQPrsList() {
};

bool TblWzemQPrsList::loadRecBySQL(
			const string& sqlstr
			, WzemQPrsList** rec
		) {
	return false;
};

ubigint TblWzemQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrsList& rst
		) {
	return 0;
};

ubigint TblWzemQPrsList::insertRec(
			WzemQPrsList* rec
		) {
	return 0;
};

ubigint TblWzemQPrsList::insertNewRec(
			WzemQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	WzemQPrsList* _rec = NULL;

	_rec = new WzemQPrsList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, Title, Firstname, Lastname, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemQPrsList::appendNewRecToRst(
			ListWzemQPrsList& rst
			, WzemQPrsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const uint ixVSex
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	ubigint retval = 0;
	WzemQPrsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, Title, Firstname, Lastname, ixVSex, srefIxVSex, titIxVSex, telVal, emlVal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemQPrsList::insertRst(
			ListWzemQPrsList& rst
		) {
};

void TblWzemQPrsList::updateRec(
			WzemQPrsList* rec
		) {
};

void TblWzemQPrsList::updateRst(
			ListWzemQPrsList& rst
		) {
};

void TblWzemQPrsList::removeRecByQref(
			ubigint qref
		) {
};

void TblWzemQPrsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWzemQPrsList::loadRecByQref(
			ubigint qref
			, WzemQPrsList** rec
		) {
	return false;
};

ubigint TblWzemQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrsList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemQPrsList
 ******************************************************************************/

MyTblWzemQPrsList::MyTblWzemQPrsList() :
			TblWzemQPrsList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWzemQPrsList::~MyTblWzemQPrsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWzemQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemQPrsList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, Title = ?, Firstname = ?, Lastname = ?, ixVSex = ?, telVal = ?, emlVal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQPrsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQPrsList WHERE jref = ?", false);
};

bool MyTblWzemQPrsList::loadRecBySQL(
			const string& sqlstr
			, WzemQPrsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemQPrsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQPrsList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQPrsList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemQPrsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->Firstname.assign(dbrow[7], dblengths[7]); else _rec->Firstname = "";
		if (dbrow[8]) _rec->Lastname.assign(dbrow[8], dblengths[8]); else _rec->Lastname = "";
		if (dbrow[9]) _rec->ixVSex = atol((char*) dbrow[9]); else _rec->ixVSex = 0;
		if (dbrow[10]) _rec->telVal.assign(dbrow[10], dblengths[10]); else _rec->telVal = "";
		if (dbrow[11]) _rec->emlVal.assign(dbrow[11], dblengths[11]); else _rec->emlVal = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemQPrsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemQPrsList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemQPrsList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemQPrsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->Firstname.assign(dbrow[7], dblengths[7]); else rec->Firstname = "";
			if (dbrow[8]) rec->Lastname.assign(dbrow[8], dblengths[8]); else rec->Lastname = "";
			if (dbrow[9]) rec->ixVSex = atol((char*) dbrow[9]); else rec->ixVSex = 0;
			if (dbrow[10]) rec->telVal.assign(dbrow[10], dblengths[10]); else rec->telVal = "";
			if (dbrow[11]) rec->emlVal.assign(dbrow[11], dblengths[11]); else rec->emlVal = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemQPrsList::insertRec(
			WzemQPrsList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->Title.length();
	l[6] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[10] = rec->emlVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemQPrsList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemQPrsList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWzemQPrsList::insertRst(
			ListWzemQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWzemQPrsList::updateRec(
			WzemQPrsList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->Title.length();
	l[6] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[10] = rec->emlVal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSex,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemQPrsList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemQPrsList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQPrsList::updateRst(
			ListWzemQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemQPrsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWzemQPrsList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWzemQPrsList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemQPrsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWzemQPrsList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWzemQPrsList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemQPrsList::loadRecByQref(
			ubigint qref
			, WzemQPrsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemQPrsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWzemQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWzemQPrsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemQPrsList
 ******************************************************************************/

PgTblWzemQPrsList::PgTblWzemQPrsList() :
			TblWzemQPrsList()
			, PgTable()
		{
};

PgTblWzemQPrsList::~PgTblWzemQPrsList() {
};

void PgTblWzemQPrsList::initStatements() {
	createStatement("TblWzemQPrsList_insertRec", "INSERT INTO TblWzemQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWzemQPrsList_updateRec", "UPDATE TblWzemQPrsList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, Title = $6, Firstname = $7, Lastname = $8, ixVSex = $9, telVal = $10, emlVal = $11 WHERE qref = $12", 12);
	createStatement("TblWzemQPrsList_removeRecByQref", "DELETE FROM TblWzemQPrsList WHERE qref = $1", 1);
	createStatement("TblWzemQPrsList_removeRstByJref", "DELETE FROM TblWzemQPrsList WHERE jref = $1", 1);

	createStatement("TblWzemQPrsList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblWzemQPrsList WHERE qref = $1", 1);
	createStatement("TblWzemQPrsList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblWzemQPrsList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWzemQPrsList::loadRec(
			PGresult* res
			, WzemQPrsList** rec
		) {
	char* ptr;

	WzemQPrsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemQPrsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlval")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->telVal.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->emlVal.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemQPrsList::loadRst(
			PGresult* res
			, const bool append
			, ListWzemQPrsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemQPrsList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlval")
		};

		while (numread < numrow) {
			rec = new WzemQPrsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->telVal.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->emlVal.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemQPrsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemQPrsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPrsList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQPrsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemQPrsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPrsList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemQPrsList::loadRecBySQL(
			const string& sqlstr
			, WzemQPrsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQPrsList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemQPrsList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemQPrsList::insertRec(
			WzemQPrsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_ixVSex,
		rec->telVal.c_str(),
		rec->emlVal.c_str()
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
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemQPrsList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWzemQPrsList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWzemQPrsList::insertRst(
			ListWzemQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemQPrsList::updateRec(
			WzemQPrsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		rec->Lastname.c_str(),
		(char*) &_ixVSex,
		rec->telVal.c_str(),
		rec->emlVal.c_str(),
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
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemQPrsList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPrsList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQPrsList::updateRst(
			ListWzemQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemQPrsList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWzemQPrsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPrsList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemQPrsList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWzemQPrsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemQPrsList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemQPrsList::loadRecByQref(
			ubigint qref
			, WzemQPrsList** rec
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

	return loadRecByStmt("TblWzemQPrsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWzemQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemQPrsList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemQPrsList
 ******************************************************************************/

LiteTblWzemQPrsList::LiteTblWzemQPrsList() :
			TblWzemQPrsList()
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

LiteTblWzemQPrsList::~LiteTblWzemQPrsList() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByQref) sqlite3_finalize(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) sqlite3_finalize(stmtRemoveRstByJref);

	if (stmtLoadRecByQref) sqlite3_finalize(stmtLoadRecByQref);
	if (stmtLoadRecByJref) sqlite3_finalize(stmtLoadRecByJref);
	if (stmtLoadRstByJref) sqlite3_finalize(stmtLoadRstByJref);
};

void LiteTblWzemQPrsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemQPrsList (jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzemQPrsList SET jref = ?1, jnum = ?2, ref = ?3, grp = ?4, own = ?5, Title = ?6, Firstname = ?7, Lastname = ?8, ixVSex = ?9, telVal = ?10, emlVal = ?11 WHERE qref = ?12");
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWzemQPrsList WHERE qref = ?1");
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWzemQPrsList WHERE jref = ?1");

	stmtLoadRecByQref = createStatement("SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblWzemQPrsList WHERE qref = ?1");
	stmtLoadRstByJref = createStatement("SELECT qref, jref, jnum, ref, grp, own, Title, Firstname, Lastname, ixVSex, telVal, emlVal FROM TblWzemQPrsList WHERE jref = ?1 ORDER BY jnum ASC");
};

bool LiteTblWzemQPrsList::loadRec(
			sqlite3_stmt* stmt
			, WzemQPrsList** rec
		) {
	int res;

	WzemQPrsList* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemQPrsList();

		_rec->qref = sqlite3_column_int64(stmt, 0);
		_rec->jref = sqlite3_column_int64(stmt, 1);
		_rec->jnum = sqlite3_column_int(stmt, 2);
		_rec->ref = sqlite3_column_int64(stmt, 3);
		_rec->grp = sqlite3_column_int64(stmt, 4);
		_rec->own = sqlite3_column_int64(stmt, 5);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->Firstname.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->ixVSex = sqlite3_column_int(stmt, 9);
		_rec->telVal.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->emlVal.assign((const char*) sqlite3_column_text(stmt, 11));

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

ubigint LiteTblWzemQPrsList::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQPrsList& rst
		) {
	int res; ubigint numread = 0;

	WzemQPrsList* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemQPrsList();

		rec->qref = sqlite3_column_int64(stmt, 0);
		rec->jref = sqlite3_column_int64(stmt, 1);
		rec->jnum = sqlite3_column_int(stmt, 2);
		rec->ref = sqlite3_column_int64(stmt, 3);
		rec->grp = sqlite3_column_int64(stmt, 4);
		rec->own = sqlite3_column_int64(stmt, 5);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->Firstname.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->Lastname.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->ixVSex = sqlite3_column_int(stmt, 9);
		rec->telVal.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->emlVal.assign((const char*) sqlite3_column_text(stmt, 11));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemQPrsList::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemQPrsList** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemQPrsList::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemQPrsList& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemQPrsList::loadRecBySQL(
			const string& sqlstr
			, WzemQPrsList** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQPrsList::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQPrsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemQPrsList& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemQPrsList::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemQPrsList::insertRec(
			WzemQPrsList* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->jref);
	sqlite3_bind_int(stmtInsertRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->ref);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->own);
	sqlite3_bind_text(stmtInsertRec, 6, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 7, rec->Firstname.c_str(), rec->Firstname.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixVSex);
	sqlite3_bind_text(stmtInsertRec, 10, rec->telVal.c_str(), rec->telVal.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 11, rec->emlVal.c_str(), rec->emlVal.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrsList::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	rec->qref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->qref;
};

void LiteTblWzemQPrsList::insertRst(
			ListWzemQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemQPrsList::updateRec(
			WzemQPrsList* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->jref);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->jnum);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->ref);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->own);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->Firstname.c_str(), rec->Firstname.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Lastname.c_str(), rec->Lastname.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixVSex);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->telVal.c_str(), rec->telVal.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->emlVal.c_str(), rec->emlVal.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->qref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrsList::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemQPrsList::updateRst(
			ListWzemQPrsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemQPrsList::removeRecByQref(
			ubigint qref
		) {
	sqlite3_bind_int64(stmtRemoveRecByQref, 1, qref);

	if (sqlite3_step(stmtRemoveRecByQref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrsList::removeRecByQref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByQref);
};

void LiteTblWzemQPrsList::removeRstByJref(
			ubigint jref
		) {
	sqlite3_bind_int64(stmtRemoveRstByJref, 1, jref);

	if (sqlite3_step(stmtRemoveRstByJref) != SQLITE_DONE)	{
		string dbms = "LiteTblWzemQPrsList::removeRstByJref() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRstByJref);
};

bool LiteTblWzemQPrsList::loadRecByQref(
			ubigint qref
			, WzemQPrsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByQref, 1, qref);

	return loadRecByStmt(stmtLoadRecByQref, rec);
};

ubigint LiteTblWzemQPrsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWzemQPrsList& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJref, 1, jref);

	return loadRstByStmt(stmtLoadRstByJref, append, rst);
};
#endif

