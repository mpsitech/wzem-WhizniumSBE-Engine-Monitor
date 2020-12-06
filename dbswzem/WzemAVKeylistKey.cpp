/**
	* \file WzemAVKeylistKey.cpp
	* database access for table TblWzemAVKeylistKey (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAVKeylistKey
 ******************************************************************************/

WzemAVKeylistKey::WzemAVKeylistKey(
			const ubigint ref
			, const uint klsIxWzemVKeylist
			, const uint klsNum
			, const uint x1IxWzemVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxWzemVKeylist = klsIxWzemVKeylist;
	this->klsNum = klsNum;
	this->x1IxWzemVMaintable = x1IxWzemVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool WzemAVKeylistKey::operator==(
			const WzemAVKeylistKey& comp
		) {
	return false;
};

bool WzemAVKeylistKey::operator!=(
			const WzemAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAVKeylistKey
 ******************************************************************************/

ListWzemAVKeylistKey::ListWzemAVKeylistKey() {
};

ListWzemAVKeylistKey::ListWzemAVKeylistKey(
			const ListWzemAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAVKeylistKey(*(src.nodes[i]));
};

ListWzemAVKeylistKey::~ListWzemAVKeylistKey() {
	clear();
};

void ListWzemAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWzemAVKeylistKey::append(
			WzemAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WzemAVKeylistKey* ListWzemAVKeylistKey::operator[](
			const uint ix
		) {
	WzemAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAVKeylistKey& ListWzemAVKeylistKey::operator=(
			const ListWzemAVKeylistKey& src
		) {
	WzemAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAVKeylistKey::operator==(
			const ListWzemAVKeylistKey& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWzemAVKeylistKey::operator!=(
			const ListWzemAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAVKeylistKey
 ******************************************************************************/

TblWzemAVKeylistKey::TblWzemAVKeylistKey() {
};

TblWzemAVKeylistKey::~TblWzemAVKeylistKey() {
};

bool TblWzemAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWzemAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWzemAVKeylistKey::insertRec(
			WzemAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWzemAVKeylistKey::insertNewRec(
			WzemAVKeylistKey** rec
			, const uint klsIxWzemVKeylist
			, const uint klsNum
			, const uint x1IxWzemVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzemAVKeylistKey* _rec = NULL;

	_rec = new WzemAVKeylistKey(0, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAVKeylistKey::appendNewRecToRst(
			ListWzemAVKeylistKey& rst
			, WzemAVKeylistKey** rec
			, const uint klsIxWzemVKeylist
			, const uint klsNum
			, const uint x1IxWzemVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WzemAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAVKeylistKey::insertRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzemAVKeylistKey::updateRec(
			WzemAVKeylistKey* rec
		) {
};

void TblWzemAVKeylistKey::updateRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
};

void TblWzemAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemAVKeylistKey** rec
		) {
	return false;
};

bool TblWzemAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWzemAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzemVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWzemAVKeylistKey::loadRstByKls(
			uint klsIxWzemVKeylist
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWzemAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	return 0;
};

bool TblWzemAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWzemAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WzemAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAVKeylistKey
 ******************************************************************************/

MyTblWzemAVKeylistKey::MyTblWzemAVKeylistKey() :
			TblWzemAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAVKeylistKey::~MyTblWzemAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAVKeylistKey (klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAVKeylistKey SET klsIxWzemVKeylist = ?, klsNum = ?, x1IxWzemVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWzemAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxWzemVKeylist = atol((char*) dbrow[1]); else _rec->klsIxWzemVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxWzemVMaintable = atol((char*) dbrow[3]); else _rec->x1IxWzemVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxWzemVKeylist = atol((char*) dbrow[1]); else rec->klsIxWzemVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxWzemVMaintable = atol((char*) dbrow[3]); else rec->x1IxWzemVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemAVKeylistKey::insertRec(
			WzemAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWzemVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzemVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAVKeylistKey::insertRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAVKeylistKey::updateRec(
			WzemAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWzemVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzemVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAVKeylistKey::updateRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = " + to_string(klsIxWzemVKeylist) + " AND x1IxWzemVMaintable = " + to_string(x1IxWzemVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblWzemAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzemVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = " + to_string(klsIxWzemVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWzemAVKeylistKey::loadRstByKls(
			uint klsIxWzemVKeylist
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = " + to_string(klsIxWzemVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblWzemAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = " + to_string(klsIxWzemVKeylist) + " AND x1IxWzemVMaintable = " + to_string(x1IxWzemVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblWzemAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWzemAVKeylistKey WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAVKeylistKey
 ******************************************************************************/

PgTblWzemAVKeylistKey::PgTblWzemAVKeylistKey() :
			TblWzemAVKeylistKey()
			, PgTable()
		{
};

PgTblWzemAVKeylistKey::~PgTblWzemAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAVKeylistKey::initStatements() {
	createStatement("TblWzemAVKeylistKey_insertRec", "INSERT INTO TblWzemAVKeylistKey (klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11);
	createStatement("TblWzemAVKeylistKey_updateRec", "UPDATE TblWzemAVKeylistKey SET klsIxWzemVKeylist = $1, klsNum = $2, x1IxWzemVMaintable = $3, x1Uref = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE ref = $12", 12);
	createStatement("TblWzemAVKeylistKey_removeRecByRef", "DELETE FROM TblWzemAVKeylistKey WHERE ref = $1", 1);

	createStatement("TblWzemAVKeylistKey_loadRecByRef", "SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE ref = $1", 1);
	createStatement("TblWzemAVKeylistKey_loadRefByKlsMtbUrfSrf", "SELECT ref FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = $1 AND x1IxWzemVMaintable = $2 AND x1Uref = $3 AND sref = $4", 4);
	createStatement("TblWzemAVKeylistKey_loadRefByKlsSrf", "SELECT ref FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = $1 AND sref = $2", 2);
	createStatement("TblWzemAVKeylistKey_loadRstByKls", "SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = $1 ORDER BY klsNum ASC", 1);
	createStatement("TblWzemAVKeylistKey_loadRstByKlsMtbUrf", "SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = $1 AND x1IxWzemVMaintable = $2 AND x1Uref = $3 ORDER BY klsNum ASC", 3);
	createStatement("TblWzemAVKeylistKey_loadTitByRef", "SELECT Title FROM TblWzemAVKeylistKey WHERE ref = $1", 1);
};

bool PgTblWzemAVKeylistKey::loadRec(
			PGresult* res
			, WzemAVKeylistKey** rec
		) {
	char* ptr;

	WzemAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixwzemvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixwzemvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->klsIxWzemVKeylist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxWzemVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixwzemvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixwzemvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WzemAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->klsIxWzemVKeylist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxWzemVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVKeylistKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVKeylistKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVKeylistKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVKeylistKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAVKeylistKey::insertRec(
			WzemAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	uint _klsIxWzemVKeylist = htonl(rec->klsIxWzemVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxWzemVMaintable = htonl(rec->x1IxWzemVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_klsIxWzemVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxWzemVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemAVKeylistKey_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVKeylistKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAVKeylistKey::insertRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAVKeylistKey::updateRec(
			WzemAVKeylistKey* rec
		) {
	PGresult* res;

	uint _klsIxWzemVKeylist = htonl(rec->klsIxWzemVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxWzemVMaintable = htonl(rec->x1IxWzemVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_klsIxWzemVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxWzemVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemAVKeylistKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAVKeylistKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAVKeylistKey::updateRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWzemAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAVKeylistKey::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWzemAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	uint _klsIxWzemVKeylist = htonl(klsIxWzemVKeylist);
	uint _x1IxWzemVMaintable = htonl(x1IxWzemVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxWzemVKeylist,
		(char*) &_x1IxWzemVMaintable,
		(char*) &_x1Uref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadRefByStmt("TblWzemAVKeylistKey_loadRefByKlsMtbUrfSrf", 4, vals, l, f, ref);
};

bool PgTblWzemAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzemVKeylist
			, string sref
			, ubigint& ref
		) {
	uint _klsIxWzemVKeylist = htonl(klsIxWzemVKeylist);

	const char* vals[] = {
		(char*) &_klsIxWzemVKeylist,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWzemAVKeylistKey_loadRefByKlsSrf", 2, vals, l, f, ref);
};

ubigint PgTblWzemAVKeylistKey::loadRstByKls(
			uint klsIxWzemVKeylist
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	uint _klsIxWzemVKeylist = htonl(klsIxWzemVKeylist);

	const char* vals[] = {
		(char*) &_klsIxWzemVKeylist
	};
	const int l[] = {
		sizeof(uint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemAVKeylistKey_loadRstByKls", 1, vals, l, f, append, rst);
};

ubigint PgTblWzemAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	uint _klsIxWzemVKeylist = htonl(klsIxWzemVKeylist);
	uint _x1IxWzemVMaintable = htonl(x1IxWzemVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxWzemVKeylist,
		(char*) &_x1IxWzemVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblWzemAVKeylistKey_loadRstByKlsMtbUrf", 3, vals, l, f, append, rst);
};

bool PgTblWzemAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWzemAVKeylistKey_loadTitByRef", 1, vals, l, f, Title);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAVKeylistKey
 ******************************************************************************/

LiteTblWzemAVKeylistKey::LiteTblWzemAVKeylistKey() :
			TblWzemAVKeylistKey()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefByKlsMtbUrfSrf = NULL;
	stmtLoadRefByKlsSrf = NULL;
	stmtLoadRstByKls = NULL;
	stmtLoadRstByKlsMtbUrf = NULL;
	stmtLoadTitByRef = NULL;
};

LiteTblWzemAVKeylistKey::~LiteTblWzemAVKeylistKey() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefByKlsMtbUrfSrf) sqlite3_finalize(stmtLoadRefByKlsMtbUrfSrf);
	if (stmtLoadRefByKlsSrf) sqlite3_finalize(stmtLoadRefByKlsSrf);
	if (stmtLoadRstByKls) sqlite3_finalize(stmtLoadRstByKls);
	if (stmtLoadRstByKlsMtbUrf) sqlite3_finalize(stmtLoadRstByKlsMtbUrf);
	if (stmtLoadTitByRef) sqlite3_finalize(stmtLoadTitByRef);
};

void LiteTblWzemAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAVKeylistKey (klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAVKeylistKey SET klsIxWzemVKeylist = ?1, klsNum = ?2, x1IxWzemVMaintable = ?3, x1Uref = ?4, Fixed = ?5, sref = ?6, Avail = ?7, Implied = ?8, refJ = ?9, Title = ?10, Comment = ?11 WHERE ref = ?12");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAVKeylistKey WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE ref = ?1");
	stmtLoadRefByKlsMtbUrfSrf = createStatement("SELECT ref FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = ?1 AND x1IxWzemVMaintable = ?2 AND x1Uref = ?3 AND sref = ?4");
	stmtLoadRefByKlsSrf = createStatement("SELECT ref FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = ?1 AND sref = ?2");
	stmtLoadRstByKls = createStatement("SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = ?1 ORDER BY klsNum ASC");
	stmtLoadRstByKlsMtbUrf = createStatement("SELECT ref, klsIxWzemVKeylist, klsNum, x1IxWzemVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWzemAVKeylistKey WHERE klsIxWzemVKeylist = ?1 AND x1IxWzemVMaintable = ?2 AND x1Uref = ?3 ORDER BY klsNum ASC");
	stmtLoadTitByRef = createStatement("SELECT Title FROM TblWzemAVKeylistKey WHERE ref = ?1");
};

bool LiteTblWzemAVKeylistKey::loadRec(
			sqlite3_stmt* stmt
			, WzemAVKeylistKey** rec
		) {
	int res;

	WzemAVKeylistKey* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAVKeylistKey();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->klsIxWzemVKeylist = sqlite3_column_int(stmt, 1);
		_rec->klsNum = sqlite3_column_int(stmt, 2);
		_rec->x1IxWzemVMaintable = sqlite3_column_int(stmt, 3);
		_rec->x1Uref = sqlite3_column_int64(stmt, 4);
		_rec->Fixed = (sqlite3_column_int(stmt, 5) != 0);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->Avail.assign((const char*) sqlite3_column_text(stmt, 7));
		_rec->Implied.assign((const char*) sqlite3_column_text(stmt, 8));
		_rec->refJ = sqlite3_column_int64(stmt, 9);
		_rec->Title.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 11));

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

ubigint LiteTblWzemAVKeylistKey::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	int res; ubigint numread = 0;

	WzemAVKeylistKey* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAVKeylistKey();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->klsIxWzemVKeylist = sqlite3_column_int(stmt, 1);
		rec->klsNum = sqlite3_column_int(stmt, 2);
		rec->x1IxWzemVMaintable = sqlite3_column_int(stmt, 3);
		rec->x1Uref = sqlite3_column_int64(stmt, 4);
		rec->Fixed = (sqlite3_column_int(stmt, 5) != 0);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->Avail.assign((const char*) sqlite3_column_text(stmt, 7));
		rec->Implied.assign((const char*) sqlite3_column_text(stmt, 8));
		rec->refJ = sqlite3_column_int64(stmt, 9);
		rec->Title.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 11));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAVKeylistKey::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAVKeylistKey** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemAVKeylistKey::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WzemAVKeylistKey** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAVKeylistKey::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAVKeylistKey::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAVKeylistKey::insertRec(
			WzemAVKeylistKey* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->klsIxWzemVKeylist);
	sqlite3_bind_int(stmtInsertRec, 2, rec->klsNum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x1IxWzemVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->x1Uref);
	sqlite3_bind_int(stmtInsertRec, 5, rec->Fixed);
	sqlite3_bind_text(stmtInsertRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 7, rec->Avail.c_str(), rec->Avail.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 8, rec->Implied.c_str(), rec->Implied.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 9, rec->refJ);
	sqlite3_bind_text(stmtInsertRec, 10, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 11, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVKeylistKey::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAVKeylistKey::insertRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAVKeylistKey::updateRec(
			WzemAVKeylistKey* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->klsIxWzemVKeylist);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->klsNum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x1IxWzemVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->x1Uref);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->Fixed);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 7, rec->Avail.c_str(), rec->Avail.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 8, rec->Implied.c_str(), rec->Implied.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->refJ);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->Title.c_str(), rec->Title.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVKeylistKey::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAVKeylistKey::updateRst(
			ListWzemAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVKeylistKey::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAVKeylistKey::loadRecByRef(
			ubigint ref
			, WzemAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByKlsMtbUrfSrf, 1, klsIxWzemVKeylist);
	sqlite3_bind_int(stmtLoadRefByKlsMtbUrfSrf, 2, x1IxWzemVMaintable);
	sqlite3_bind_int64(stmtLoadRefByKlsMtbUrfSrf, 3, x1Uref);
	sqlite3_bind_text(stmtLoadRefByKlsMtbUrfSrf, 4, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByKlsMtbUrfSrf, ref);
};

bool LiteTblWzemAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWzemVKeylist
			, string sref
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByKlsSrf, 1, klsIxWzemVKeylist);
	sqlite3_bind_text(stmtLoadRefByKlsSrf, 2, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByKlsSrf, ref);
};

ubigint LiteTblWzemAVKeylistKey::loadRstByKls(
			uint klsIxWzemVKeylist
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	sqlite3_bind_int(stmtLoadRstByKls, 1, klsIxWzemVKeylist);

	return loadRstByStmt(stmtLoadRstByKls, append, rst);
};

ubigint LiteTblWzemAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWzemVKeylist
			, uint x1IxWzemVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWzemAVKeylistKey& rst
		) {
	sqlite3_bind_int(stmtLoadRstByKlsMtbUrf, 1, klsIxWzemVKeylist);
	sqlite3_bind_int(stmtLoadRstByKlsMtbUrf, 2, x1IxWzemVMaintable);
	sqlite3_bind_int64(stmtLoadRstByKlsMtbUrf, 3, x1Uref);

	return loadRstByStmt(stmtLoadRstByKlsMtbUrf, append, rst);
};

bool LiteTblWzemAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	sqlite3_bind_int64(stmtLoadTitByRef, 1, ref);

	return loadStringByStmt(stmtLoadTitByRef, Title);
};

#endif
