/**
	* \file WzemHistRMUserUniversal.cpp
	* database access for table TblWzemHistRMUserUniversal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemHistRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemHistRMUserUniversal
 ******************************************************************************/

WzemHistRMUserUniversal::WzemHistRMUserUniversal(
			const ubigint ref
			, const ubigint refWzemMUser
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVCard
			, const uint ixWzemVPreset
			, const uint preIxWzemVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refWzemMUser = refWzemMUser;
	this->unvIxWzemVMaintable = unvIxWzemVMaintable;
	this->unvUref = unvUref;
	this->ixWzemVCard = ixWzemVCard;
	this->ixWzemVPreset = ixWzemVPreset;
	this->preIxWzemVMaintable = preIxWzemVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool WzemHistRMUserUniversal::operator==(
			const WzemHistRMUserUniversal& comp
		) {
	return false;
};

bool WzemHistRMUserUniversal::operator!=(
			const WzemHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemHistRMUserUniversal
 ******************************************************************************/

ListWzemHistRMUserUniversal::ListWzemHistRMUserUniversal() {
};

ListWzemHistRMUserUniversal::ListWzemHistRMUserUniversal(
			const ListWzemHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemHistRMUserUniversal(*(src.nodes[i]));
};

ListWzemHistRMUserUniversal::~ListWzemHistRMUserUniversal() {
	clear();
};

void ListWzemHistRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWzemHistRMUserUniversal::append(
			WzemHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WzemHistRMUserUniversal* ListWzemHistRMUserUniversal::operator[](
			const uint ix
		) {
	WzemHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemHistRMUserUniversal& ListWzemHistRMUserUniversal::operator=(
			const ListWzemHistRMUserUniversal& src
		) {
	WzemHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemHistRMUserUniversal::operator==(
			const ListWzemHistRMUserUniversal& comp
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

bool ListWzemHistRMUserUniversal::operator!=(
			const ListWzemHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemHistRMUserUniversal
 ******************************************************************************/

TblWzemHistRMUserUniversal::TblWzemHistRMUserUniversal() {
};

TblWzemHistRMUserUniversal::~TblWzemHistRMUserUniversal() {
};

bool TblWzemHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzemHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWzemHistRMUserUniversal::insertRec(
			WzemHistRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWzemHistRMUserUniversal::insertNewRec(
			WzemHistRMUserUniversal** rec
			, const ubigint refWzemMUser
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVCard
			, const uint ixWzemVPreset
			, const uint preIxWzemVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WzemHistRMUserUniversal* _rec = NULL;

	_rec = new WzemHistRMUserUniversal(0, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemHistRMUserUniversal::appendNewRecToRst(
			ListWzemHistRMUserUniversal& rst
			, WzemHistRMUserUniversal** rec
			, const ubigint refWzemMUser
			, const uint unvIxWzemVMaintable
			, const ubigint unvUref
			, const uint ixWzemVCard
			, const uint ixWzemVPreset
			, const uint preIxWzemVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WzemHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemHistRMUserUniversal::insertRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzemHistRMUserUniversal::updateRec(
			WzemHistRMUserUniversal* rec
		) {
};

void TblWzemHistRMUserUniversal::updateRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWzemHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemHistRMUserUniversal** rec
		) {
	return false;
};

bool TblWzemHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, uint ixWzemVCard
			, WzemHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWzemHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, uint ixWzemVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblWzemHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzemMUser
			, uint ixWzemVCard
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblWzemHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return false;
};

ubigint TblWzemHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WzemHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemHistRMUserUniversal
 ******************************************************************************/

MyTblWzemHistRMUserUniversal::MyTblWzemHistRMUserUniversal() :
			TblWzemHistRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemHistRMUserUniversal::~MyTblWzemHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemHistRMUserUniversal (refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemHistRMUserUniversal SET refWzemMUser = ?, unvIxWzemVMaintable = ?, unvUref = ?, ixWzemVCard = ?, ixWzemVPreset = ?, preIxWzemVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWzemHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemHistRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemHistRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WzemHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWzemMUser = atoll((char*) dbrow[1]); else _rec->refWzemMUser = 0;
		if (dbrow[2]) _rec->unvIxWzemVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWzemVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWzemVCard = atol((char*) dbrow[4]); else _rec->ixWzemVCard = 0;
		if (dbrow[5]) _rec->ixWzemVPreset = atol((char*) dbrow[5]); else _rec->ixWzemVPreset = 0;
		if (dbrow[6]) _rec->preIxWzemVMaintable = atol((char*) dbrow[6]); else _rec->preIxWzemVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemHistRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemHistRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WzemHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWzemMUser = atoll((char*) dbrow[1]); else rec->refWzemMUser = 0;
			if (dbrow[2]) rec->unvIxWzemVMaintable = atol((char*) dbrow[2]); else rec->unvIxWzemVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWzemVCard = atol((char*) dbrow[4]); else rec->ixWzemVCard = 0;
			if (dbrow[5]) rec->ixWzemVPreset = atol((char*) dbrow[5]); else rec->ixWzemVPreset = 0;
			if (dbrow[6]) rec->preIxWzemVMaintable = atol((char*) dbrow[6]); else rec->preIxWzemVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemHistRMUserUniversal::insertRec(
			WzemHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzemVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzemVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWzemVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemHistRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemHistRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemHistRMUserUniversal::insertRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemHistRMUserUniversal::updateRec(
			WzemHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWzemMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWzemVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWzemVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWzemVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWzemVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemHistRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemHistRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemHistRMUserUniversal::updateRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemHistRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemHistRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemHistRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, uint ixWzemVCard
			, WzemHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = " + to_string(refWzemMUser) + " AND unvIxWzemVMaintable = " + to_string(unvIxWzemVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixWzemVCard = " + to_string(ixWzemVCard) + "", rec);
};

ubigint MyTblWzemHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, uint ixWzemVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRefsBySQL("SELECT ref FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = " + to_string(refWzemMUser) + " AND unvIxWzemVMaintable = " + to_string(unvIxWzemVMaintable) + " AND ixWzemVCard = " + to_string(ixWzemVCard) + " ORDER BY start DESC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, refs);
};

ubigint MyTblWzemHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzemMUser
			, uint ixWzemVCard
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = " + to_string(refWzemMUser) + " AND ixWzemVCard = " + to_string(ixWzemVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblWzemHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return loadRefBySQL("SELECT unvUref FROM TblWzemHistRMUserUniversal WHERE ref = " + to_string(ref) + "", unvUref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemHistRMUserUniversal
 ******************************************************************************/

PgTblWzemHistRMUserUniversal::PgTblWzemHistRMUserUniversal() :
			TblWzemHistRMUserUniversal()
			, PgTable()
		{
};

PgTblWzemHistRMUserUniversal::~PgTblWzemHistRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemHistRMUserUniversal::initStatements() {
	createStatement("TblWzemHistRMUserUniversal_insertRec", "INSERT INTO TblWzemHistRMUserUniversal (refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWzemHistRMUserUniversal_updateRec", "UPDATE TblWzemHistRMUserUniversal SET refWzemMUser = $1, unvIxWzemVMaintable = $2, unvUref = $3, ixWzemVCard = $4, ixWzemVPreset = $5, preIxWzemVMaintable = $6, preUref = $7, start = $8 WHERE ref = $9", 9);
	createStatement("TblWzemHistRMUserUniversal_removeRecByRef", "DELETE FROM TblWzemHistRMUserUniversal WHERE ref = $1", 1);

	createStatement("TblWzemHistRMUserUniversal_loadRecByRef", "SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE ref = $1", 1);
	createStatement("TblWzemHistRMUserUniversal_loadRecByUsrMtbUnvCrd", "SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = $1 AND unvIxWzemVMaintable = $2 AND unvUref = $3 AND ixWzemVCard = $4", 4);
	createStatement("TblWzemHistRMUserUniversal_loadRefsByUsrMtbCrd", "SELECT ref FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = $1 AND unvIxWzemVMaintable = $2 AND ixWzemVCard = $3 ORDER BY start DESC OFFSET $4 LIMIT $5", 5);
	createStatement("TblWzemHistRMUserUniversal_loadRstByUsrCrd", "SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = $1 AND ixWzemVCard = $2 ORDER BY start DESC", 2);
	createStatement("TblWzemHistRMUserUniversal_loadUnuByRef", "SELECT unvUref FROM TblWzemHistRMUserUniversal WHERE ref = $1", 1);
};

bool PgTblWzemHistRMUserUniversal::loadRec(
			PGresult* res
			, WzemHistRMUserUniversal** rec
		) {
	char* ptr;

	WzemHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemHistRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "unvixwzemvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwzemvcard"),
			PQfnumber(res, "ixwzemvpreset"),
			PQfnumber(res, "preixwzemvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWzemVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWzemVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWzemVPreset = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->preIxWzemVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->preUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemHistRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemHistRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwzemmuser"),
			PQfnumber(res, "unvixwzemvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwzemvcard"),
			PQfnumber(res, "ixwzemvpreset"),
			PQfnumber(res, "preixwzemvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new WzemHistRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWzemMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWzemVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWzemVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWzemVPreset = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->preIxWzemVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->preUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemHistRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemHistRMUserUniversal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemHistRMUserUniversal::insertRec(
			WzemHistRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(rec->unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWzemVCard = htonl(rec->ixWzemVCard);
	uint _ixWzemVPreset = htonl(rec->ixWzemVPreset);
	uint _preIxWzemVMaintable = htonl(rec->preIxWzemVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWzemVCard,
		(char*) &_ixWzemVPreset,
		(char*) &_preIxWzemVMaintable,
		(char*) &_preUref,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemHistRMUserUniversal_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemHistRMUserUniversal::insertRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemHistRMUserUniversal::updateRec(
			WzemHistRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refWzemMUser = htonl64(rec->refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(rec->unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWzemVCard = htonl(rec->ixWzemVCard);
	uint _ixWzemVPreset = htonl(rec->ixWzemVPreset);
	uint _preIxWzemVMaintable = htonl(rec->preIxWzemVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWzemVCard,
		(char*) &_ixWzemVPreset,
		(char*) &_preIxWzemVMaintable,
		(char*) &_preUref,
		(char*) &_start,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemHistRMUserUniversal_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemHistRMUserUniversal::updateRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemHistRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemHistRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemHistRMUserUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemHistRMUserUniversal** rec
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

	return loadRecByStmt("TblWzemHistRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, uint ixWzemVCard
			, WzemHistRMUserUniversal** rec
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(unvIxWzemVMaintable);
	ubigint _unvUref = htonl64(unvUref);
	uint _ixWzemVCard = htonl(ixWzemVCard);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWzemVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1,1,1};

	return loadRecByStmt("TblWzemHistRMUserUniversal_loadRecByUsrMtbUnvCrd", 4, vals, l, f, rec);
};

ubigint PgTblWzemHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, uint ixWzemVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);
	uint _unvIxWzemVMaintable = htonl(unvIxWzemVMaintable);
	uint _ixWzemVCard = htonl(ixWzemVCard);
	ubigint _offset = htonl64(offset);

	ubigint _limit = htonl64(limit);
	char* _limitptr = NULL;
	int _limitl = 0;

	if (limit != 0) {
		_limitptr = (char*) &_limit;
		_limitl = sizeof(ubigint);
	};

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_unvIxWzemVMaintable,
		(char*) &_ixWzemVCard,
		(char*) &_offset,
		_limitptr
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		_limitl
	};
	const int f[] = {1,1,1,1,1};

	return loadRefsByStmt("TblWzemHistRMUserUniversal_loadRefsByUsrMtbCrd", 3, vals, l, f, append, refs);
};

ubigint PgTblWzemHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzemMUser
			, uint ixWzemVCard
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	ubigint _refWzemMUser = htonl64(refWzemMUser);
	uint _ixWzemVCard = htonl(ixWzemVCard);

	const char* vals[] = {
		(char*) &_refWzemMUser,
		(char*) &_ixWzemVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWzemHistRMUserUniversal_loadRstByUsrCrd", 2, vals, l, f, append, rst);
};

bool PgTblWzemHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWzemHistRMUserUniversal_loadUnuByRef", 1, vals, l, f, unvUref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemHistRMUserUniversal
 ******************************************************************************/

LiteTblWzemHistRMUserUniversal::LiteTblWzemHistRMUserUniversal() :
			TblWzemHistRMUserUniversal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByUsrMtbUnvCrd = NULL;
	stmtLoadRefsByUsrMtbCrd = NULL;
	stmtLoadRstByUsrCrd = NULL;
	stmtLoadUnuByRef = NULL;
};

LiteTblWzemHistRMUserUniversal::~LiteTblWzemHistRMUserUniversal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByUsrMtbUnvCrd) sqlite3_finalize(stmtLoadRecByUsrMtbUnvCrd);
	if (stmtLoadRefsByUsrMtbCrd) sqlite3_finalize(stmtLoadRefsByUsrMtbCrd);
	if (stmtLoadRstByUsrCrd) sqlite3_finalize(stmtLoadRstByUsrCrd);
	if (stmtLoadUnuByRef) sqlite3_finalize(stmtLoadUnuByRef);
};

void LiteTblWzemHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemHistRMUserUniversal (refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start) VALUES (?1,?2,?3,?4,?5,?6,?7,?8)");
	stmtUpdateRec = createStatement("UPDATE TblWzemHistRMUserUniversal SET refWzemMUser = ?1, unvIxWzemVMaintable = ?2, unvUref = ?3, ixWzemVCard = ?4, ixWzemVPreset = ?5, preIxWzemVMaintable = ?6, preUref = ?7, start = ?8 WHERE ref = ?9");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemHistRMUserUniversal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE ref = ?1");
	stmtLoadRecByUsrMtbUnvCrd = createStatement("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = ?1 AND unvIxWzemVMaintable = ?2 AND unvUref = ?3 AND ixWzemVCard = ?4");
	stmtLoadRefsByUsrMtbCrd = createStatement("SELECT ref FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = ?1 AND unvIxWzemVMaintable = ?2 AND ixWzemVCard = ?3 ORDER BY start DESC LIMIT ?,?");
	stmtLoadRstByUsrCrd = createStatement("SELECT ref, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, start FROM TblWzemHistRMUserUniversal WHERE refWzemMUser = ?1 AND ixWzemVCard = ?2 ORDER BY start DESC");
	stmtLoadUnuByRef = createStatement("SELECT unvUref FROM TblWzemHistRMUserUniversal WHERE ref = ?1");
};

bool LiteTblWzemHistRMUserUniversal::loadRec(
			sqlite3_stmt* stmt
			, WzemHistRMUserUniversal** rec
		) {
	int res;

	WzemHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemHistRMUserUniversal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		_rec->unvIxWzemVMaintable = sqlite3_column_int(stmt, 2);
		_rec->unvUref = sqlite3_column_int64(stmt, 3);
		_rec->ixWzemVCard = sqlite3_column_int(stmt, 4);
		_rec->ixWzemVPreset = sqlite3_column_int(stmt, 5);
		_rec->preIxWzemVMaintable = sqlite3_column_int(stmt, 6);
		_rec->preUref = sqlite3_column_int64(stmt, 7);
		_rec->start = sqlite3_column_int(stmt, 8);

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

ubigint LiteTblWzemHistRMUserUniversal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	int res; ubigint numread = 0;

	WzemHistRMUserUniversal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemHistRMUserUniversal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->refWzemMUser = sqlite3_column_int64(stmt, 1);
		rec->unvIxWzemVMaintable = sqlite3_column_int(stmt, 2);
		rec->unvUref = sqlite3_column_int64(stmt, 3);
		rec->ixWzemVCard = sqlite3_column_int(stmt, 4);
		rec->ixWzemVPreset = sqlite3_column_int(stmt, 5);
		rec->preIxWzemVMaintable = sqlite3_column_int(stmt, 6);
		rec->preUref = sqlite3_column_int64(stmt, 7);
		rec->start = sqlite3_column_int(stmt, 8);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemHistRMUserUniversal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemHistRMUserUniversal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemHistRMUserUniversal::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WzemHistRMUserUniversal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemHistRMUserUniversal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemHistRMUserUniversal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemHistRMUserUniversal::insertRec(
			WzemHistRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtInsertRec, 2, rec->unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtInsertRec, 4, rec->ixWzemVCard);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixWzemVPreset);
	sqlite3_bind_int(stmtInsertRec, 6, rec->preIxWzemVMaintable);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->preUref);
	sqlite3_bind_int(stmtInsertRec, 8, rec->start);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemHistRMUserUniversal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemHistRMUserUniversal::insertRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemHistRMUserUniversal::updateRec(
			WzemHistRMUserUniversal* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->refWzemMUser);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->unvUref);
	sqlite3_bind_int(stmtUpdateRec, 4, rec->ixWzemVCard);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixWzemVPreset);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->preIxWzemVMaintable);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->preUref);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->start);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemHistRMUserUniversal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemHistRMUserUniversal::updateRst(
			ListWzemHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemHistRMUserUniversal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WzemHistRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, ubigint unvUref
			, uint ixWzemVCard
			, WzemHistRMUserUniversal** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnvCrd, 1, refWzemMUser);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnvCrd, 2, unvIxWzemVMaintable);
	sqlite3_bind_int64(stmtLoadRecByUsrMtbUnvCrd, 3, unvUref);
	sqlite3_bind_int(stmtLoadRecByUsrMtbUnvCrd, 4, ixWzemVCard);

	return loadRecByStmt(stmtLoadRecByUsrMtbUnvCrd, rec);
};

ubigint LiteTblWzemHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWzemMUser
			, uint unvIxWzemVMaintable
			, uint ixWzemVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 1, refWzemMUser);
	sqlite3_bind_int(stmtLoadRefsByUsrMtbCrd, 2, unvIxWzemVMaintable);
	sqlite3_bind_int(stmtLoadRefsByUsrMtbCrd, 3, ixWzemVCard);
	sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 4, offset);
	if (limit == 0) sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 5, -1); else sqlite3_bind_int64(stmtLoadRefsByUsrMtbCrd, 5, limit);

	return loadRefsByStmt(stmtLoadRefsByUsrMtbCrd, append, refs);
};

ubigint LiteTblWzemHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWzemMUser
			, uint ixWzemVCard
			, const bool append
			, ListWzemHistRMUserUniversal& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByUsrCrd, 1, refWzemMUser);
	sqlite3_bind_int(stmtLoadRstByUsrCrd, 2, ixWzemVCard);

	return loadRstByStmt(stmtLoadRstByUsrCrd, append, rst);
};

bool LiteTblWzemHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	sqlite3_bind_int64(stmtLoadUnuByRef, 1, ref);

	return loadRefByStmt(stmtLoadUnuByRef, unvUref);
};

#endif
