/**
	* \file WzemMClstn.cpp
	* database access for table TblWzemMClstn (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemMClstn.h"

#include "WzemMClstn_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMClstn
 ******************************************************************************/

WzemMClstn::WzemMClstn(
			const ubigint ref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVCall
			, const uint ixVTarget
			, const uint ixVJobmask
			, const ubigint tjbRefWzemMJob
			, const uint ixVArgmask
			, const string arg
			, const string srefIxVSge
			, const uint ixVJactype
		) {

	this->ref = ref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->refWzemMJob = refWzemMJob;
	this->srefIxVCall = srefIxVCall;
	this->ixVTarget = ixVTarget;
	this->ixVJobmask = ixVJobmask;
	this->tjbRefWzemMJob = tjbRefWzemMJob;
	this->ixVArgmask = ixVArgmask;
	this->arg = arg;
	this->srefIxVSge = srefIxVSge;
	this->ixVJactype = ixVJactype;
};

bool WzemMClstn::operator==(
			const WzemMClstn& comp
		) {
	return false;
};

bool WzemMClstn::operator!=(
			const WzemMClstn& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMClstn
 ******************************************************************************/

ListWzemMClstn::ListWzemMClstn() {
};

ListWzemMClstn::ListWzemMClstn(
			const ListWzemMClstn& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMClstn(*(src.nodes[i]));
};

ListWzemMClstn::~ListWzemMClstn() {
	clear();
};

void ListWzemMClstn::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMClstn::size() const {
	return(nodes.size());
};

void ListWzemMClstn::append(
			WzemMClstn* rec
		) {
	nodes.push_back(rec);
};

WzemMClstn* ListWzemMClstn::operator[](
			const uint ix
		) {
	WzemMClstn* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMClstn& ListWzemMClstn::operator=(
			const ListWzemMClstn& src
		) {
	WzemMClstn* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMClstn(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMClstn::operator==(
			const ListWzemMClstn& comp
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

bool ListWzemMClstn::operator!=(
			const ListWzemMClstn& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMClstn
 ******************************************************************************/

TblWzemMClstn::TblWzemMClstn() {
};

TblWzemMClstn::~TblWzemMClstn() {
};

bool TblWzemMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemMClstn** rec
		) {
	return false;
};

ubigint TblWzemMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMClstn& rst
		) {
	return 0;
};

ubigint TblWzemMClstn::insertRec(
			WzemMClstn* rec
		) {
	return 0;
};

ubigint TblWzemMClstn::insertNewRec(
			WzemMClstn** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVCall
			, const uint ixVTarget
			, const uint ixVJobmask
			, const ubigint tjbRefWzemMJob
			, const uint ixVArgmask
			, const string arg
			, const string srefIxVSge
			, const uint ixVJactype
		) {
	ubigint retval = 0;
	WzemMClstn* _rec = NULL;

	_rec = new WzemMClstn(0, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMClstn::appendNewRecToRst(
			ListWzemMClstn& rst
			, WzemMClstn** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMJob
			, const string srefIxVCall
			, const uint ixVTarget
			, const uint ixVJobmask
			, const ubigint tjbRefWzemMJob
			, const uint ixVArgmask
			, const string arg
			, const string srefIxVSge
			, const uint ixVJactype
		) {
	ubigint retval = 0;
	WzemMClstn* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMClstn::insertRst(
			ListWzemMClstn& rst
			, bool transact
		) {
};

void TblWzemMClstn::updateRec(
			WzemMClstn* rec
		) {
};

void TblWzemMClstn::updateRst(
			ListWzemMClstn& rst
			, bool transact
		) {
};

void TblWzemMClstn::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMClstn::loadRecByRef(
			ubigint ref
			, WzemMClstn** rec
		) {
	return false;
};

ubigint TblWzemMClstn::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMClstn& rst
		) {
	return 0;
};

ubigint TblWzemMClstn::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMClstn& rst
		) {
	ubigint numload = 0;
	WzemMClstn* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMClstn
 ******************************************************************************/

MyTblWzemMClstn::MyTblWzemMClstn() :
			TblWzemMClstn()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMClstn::~MyTblWzemMClstn() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMClstn::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMClstn (x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMClstn SET x1Startu = ?, x1Stopu = ?, refWzemMJob = ?, srefIxVCall = ?, ixVTarget = ?, ixVJobmask = ?, tjbRefWzemMJob = ?, ixVArgmask = ?, arg = ?, srefIxVSge = ?, ixVJactype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMClstn WHERE ref = ?", false);
};

bool MyTblWzemMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemMClstn** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMClstn* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMClstn::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMClstn::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMClstn();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startu = atof((char*) dbrow[1]); else _rec->x1Startu = 0.0;
		if (dbrow[2]) _rec->x1Stopu = atof((char*) dbrow[2]); else _rec->x1Stopu = 0.0;
		if (dbrow[3]) _rec->refWzemMJob = atoll((char*) dbrow[3]); else _rec->refWzemMJob = 0;
		if (dbrow[4]) _rec->srefIxVCall.assign(dbrow[4], dblengths[4]); else _rec->srefIxVCall = "";
		if (dbrow[5]) _rec->ixVTarget = atol((char*) dbrow[5]); else _rec->ixVTarget = 0;
		if (dbrow[6]) _rec->ixVJobmask = atol((char*) dbrow[6]); else _rec->ixVJobmask = 0;
		if (dbrow[7]) _rec->tjbRefWzemMJob = atoll((char*) dbrow[7]); else _rec->tjbRefWzemMJob = 0;
		if (dbrow[8]) _rec->ixVArgmask = atol((char*) dbrow[8]); else _rec->ixVArgmask = 0;
		if (dbrow[9]) _rec->arg.assign(dbrow[9], dblengths[9]); else _rec->arg = "";
		if (dbrow[10]) _rec->srefIxVSge.assign(dbrow[10], dblengths[10]); else _rec->srefIxVSge = "";
		if (dbrow[11]) _rec->ixVJactype = atol((char*) dbrow[11]); else _rec->ixVJactype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMClstn& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMClstn* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMClstn::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMClstn::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMClstn();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startu = atof((char*) dbrow[1]); else rec->x1Startu = 0.0;
			if (dbrow[2]) rec->x1Stopu = atof((char*) dbrow[2]); else rec->x1Stopu = 0.0;
			if (dbrow[3]) rec->refWzemMJob = atoll((char*) dbrow[3]); else rec->refWzemMJob = 0;
			if (dbrow[4]) rec->srefIxVCall.assign(dbrow[4], dblengths[4]); else rec->srefIxVCall = "";
			if (dbrow[5]) rec->ixVTarget = atol((char*) dbrow[5]); else rec->ixVTarget = 0;
			if (dbrow[6]) rec->ixVJobmask = atol((char*) dbrow[6]); else rec->ixVJobmask = 0;
			if (dbrow[7]) rec->tjbRefWzemMJob = atoll((char*) dbrow[7]); else rec->tjbRefWzemMJob = 0;
			if (dbrow[8]) rec->ixVArgmask = atol((char*) dbrow[8]); else rec->ixVArgmask = 0;
			if (dbrow[9]) rec->arg.assign(dbrow[9], dblengths[9]); else rec->arg = "";
			if (dbrow[10]) rec->srefIxVSge.assign(dbrow[10], dblengths[10]); else rec->srefIxVSge = "";
			if (dbrow[11]) rec->ixVJactype = atol((char*) dbrow[11]); else rec->ixVJactype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMClstn::insertRec(
			WzemMClstn* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->srefIxVCall.length();
	l[8] = rec->arg.length();
	l[9] = rec->srefIxVSge.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefIxVCall.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVTarget,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVJobmask,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tjbRefWzemMJob,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVArgmask,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->arg.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefIxVSge.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVJactype,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMClstn::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMClstn::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMClstn::insertRst(
			ListWzemMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMClstn::updateRec(
			WzemMClstn* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->srefIxVCall.length();
	l[8] = rec->arg.length();
	l[9] = rec->srefIxVSge.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMJob,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefIxVCall.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVTarget,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVJobmask,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tjbRefWzemMJob,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVArgmask,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->arg.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefIxVSge.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVJactype,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMClstn::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMClstn::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMClstn::updateRst(
			ListWzemMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMClstn::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMClstn::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMClstn::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMClstn::loadRecByRef(
			ubigint ref
			, WzemMClstn** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMClstn WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemMClstn::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMClstn& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype FROM TblWzemMClstn WHERE refWzemMJob = " + to_string(refWzemMJob) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMClstn
 ******************************************************************************/

PgTblWzemMClstn::PgTblWzemMClstn() :
			TblWzemMClstn()
			, PgTable()
		{
};

PgTblWzemMClstn::~PgTblWzemMClstn() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMClstn::initStatements() {
	createStatement("TblWzemMClstn_insertRec", "INSERT INTO TblWzemMClstn (x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11);
	createStatement("TblWzemMClstn_updateRec", "UPDATE TblWzemMClstn SET x1Startu = $1, x1Stopu = $2, refWzemMJob = $3, srefIxVCall = $4, ixVTarget = $5, ixVJobmask = $6, tjbRefWzemMJob = $7, ixVArgmask = $8, arg = $9, srefIxVSge = $10, ixVJactype = $11 WHERE ref = $12", 12);
	createStatement("TblWzemMClstn_removeRecByRef", "DELETE FROM TblWzemMClstn WHERE ref = $1", 1);

	createStatement("TblWzemMClstn_loadRecByRef", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype FROM TblWzemMClstn WHERE ref = $1", 1);
	createStatement("TblWzemMClstn_loadRstByJob", "SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype FROM TblWzemMClstn WHERE refWzemMJob = $1", 1);
};

bool PgTblWzemMClstn::loadRec(
			PGresult* res
			, WzemMClstn** rec
		) {
	char* ptr;

	WzemMClstn* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMClstn();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvcall"),
			PQfnumber(res, "ixvtarget"),
			PQfnumber(res, "ixvjobmask"),
			PQfnumber(res, "tjbrefwzemmjob"),
			PQfnumber(res, "ixvargmask"),
			PQfnumber(res, "arg"),
			PQfnumber(res, "srefixvsge"),
			PQfnumber(res, "ixvjactype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefIxVCall.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVTarget = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVJobmask = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->tjbRefWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVArgmask = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->arg.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefIxVSge.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixVJactype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMClstn::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMClstn& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMClstn* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "srefixvcall"),
			PQfnumber(res, "ixvtarget"),
			PQfnumber(res, "ixvjobmask"),
			PQfnumber(res, "tjbrefwzemmjob"),
			PQfnumber(res, "ixvargmask"),
			PQfnumber(res, "arg"),
			PQfnumber(res, "srefixvsge"),
			PQfnumber(res, "ixvjactype")
		};

		while (numread < numrow) {
			rec = new WzemMClstn();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefIxVCall.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVTarget = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVJobmask = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->tjbRefWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVArgmask = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->arg.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefIxVSge.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixVJactype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMClstn::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMClstn** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMClstn::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMClstn::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMClstn& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMClstn::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemMClstn** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMClstn::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMClstn& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMClstn::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMClstn::insertRec(
			WzemMClstn* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	uint _ixVTarget = htonl(rec->ixVTarget);
	uint _ixVJobmask = htonl(rec->ixVJobmask);
	ubigint _tjbRefWzemMJob = htonl64(rec->tjbRefWzemMJob);
	uint _ixVArgmask = htonl(rec->ixVArgmask);
	uint _ixVJactype = htonl(rec->ixVJactype);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMJob,
		rec->srefIxVCall.c_str(),
		(char*) &_ixVTarget,
		(char*) &_ixVJobmask,
		(char*) &_tjbRefWzemMJob,
		(char*) &_ixVArgmask,
		rec->arg.c_str(),
		rec->srefIxVSge.c_str(),
		(char*) &_ixVJactype
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(uint)
	};
	const int f[] = {0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemMClstn_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMClstn::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMClstn::insertRst(
			ListWzemMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMClstn::updateRec(
			WzemMClstn* rec
		) {
	PGresult* res;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	uint _ixVTarget = htonl(rec->ixVTarget);
	uint _ixVJobmask = htonl(rec->ixVJobmask);
	ubigint _tjbRefWzemMJob = htonl64(rec->tjbRefWzemMJob);
	uint _ixVArgmask = htonl(rec->ixVArgmask);
	uint _ixVJactype = htonl(rec->ixVJactype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMJob,
		rec->srefIxVCall.c_str(),
		(char*) &_ixVTarget,
		(char*) &_ixVJobmask,
		(char*) &_tjbRefWzemMJob,
		(char*) &_ixVArgmask,
		rec->arg.c_str(),
		rec->srefIxVSge.c_str(),
		(char*) &_ixVJactype,
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMClstn_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMClstn::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMClstn::updateRst(
			ListWzemMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMClstn::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMClstn_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMClstn::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMClstn::loadRecByRef(
			ubigint ref
			, WzemMClstn** rec
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

	return loadRecByStmt("TblWzemMClstn_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemMClstn::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMClstn& rst
		) {
	ubigint _refWzemMJob = htonl64(refWzemMJob);

	const char* vals[] = {
		(char*) &_refWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMClstn_loadRstByJob", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMClstn
 ******************************************************************************/

LiteTblWzemMClstn::LiteTblWzemMClstn() :
			TblWzemMClstn()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByJob = NULL;
};

LiteTblWzemMClstn::~LiteTblWzemMClstn() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByJob) sqlite3_finalize(stmtLoadRstByJob);
};

void LiteTblWzemMClstn::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMClstn (x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMClstn SET x1Startu = ?1, x1Stopu = ?2, refWzemMJob = ?3, srefIxVCall = ?4, ixVTarget = ?5, ixVJobmask = ?6, tjbRefWzemMJob = ?7, ixVArgmask = ?8, arg = ?9, srefIxVSge = ?10, ixVJactype = ?11 WHERE ref = ?12");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMClstn WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype FROM TblWzemMClstn WHERE ref = ?1");
	stmtLoadRstByJob = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMJob, srefIxVCall, ixVTarget, ixVJobmask, tjbRefWzemMJob, ixVArgmask, arg, srefIxVSge, ixVJactype FROM TblWzemMClstn WHERE refWzemMJob = ?1");
};

bool LiteTblWzemMClstn::loadRec(
			sqlite3_stmt* stmt
			, WzemMClstn** rec
		) {
	int res;

	WzemMClstn* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMClstn();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->x1Startu = sqlite3_column_double(stmt, 1);
		_rec->x1Stopu = sqlite3_column_double(stmt, 2);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		_rec->srefIxVCall.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->ixVTarget = sqlite3_column_int(stmt, 5);
		_rec->ixVJobmask = sqlite3_column_int(stmt, 6);
		_rec->tjbRefWzemMJob = sqlite3_column_int64(stmt, 7);
		_rec->ixVArgmask = sqlite3_column_int(stmt, 8);
		_rec->arg.assign((const char*) sqlite3_column_text(stmt, 9));
		_rec->srefIxVSge.assign((const char*) sqlite3_column_text(stmt, 10));
		_rec->ixVJactype = sqlite3_column_int(stmt, 11);

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

ubigint LiteTblWzemMClstn::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMClstn& rst
		) {
	int res; ubigint numread = 0;

	WzemMClstn* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMClstn();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->x1Startu = sqlite3_column_double(stmt, 1);
		rec->x1Stopu = sqlite3_column_double(stmt, 2);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 3);
		rec->srefIxVCall.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->ixVTarget = sqlite3_column_int(stmt, 5);
		rec->ixVJobmask = sqlite3_column_int(stmt, 6);
		rec->tjbRefWzemMJob = sqlite3_column_int64(stmt, 7);
		rec->ixVArgmask = sqlite3_column_int(stmt, 8);
		rec->arg.assign((const char*) sqlite3_column_text(stmt, 9));
		rec->srefIxVSge.assign((const char*) sqlite3_column_text(stmt, 10));
		rec->ixVJactype = sqlite3_column_int(stmt, 11);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMClstn::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMClstn** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMClstn::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMClstn& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMClstn::loadRecBySQL(
			const string& sqlstr
			, WzemMClstn** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMClstn::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMClstn::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMClstn& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMClstn::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMClstn::insertRec(
			WzemMClstn* rec
		) {
	sqlite3_bind_double(stmtInsertRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMJob);
	sqlite3_bind_text(stmtInsertRec, 4, rec->srefIxVCall.c_str(), rec->srefIxVCall.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 5, rec->ixVTarget);
	sqlite3_bind_int(stmtInsertRec, 6, rec->ixVJobmask);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->tjbRefWzemMJob);
	sqlite3_bind_int(stmtInsertRec, 8, rec->ixVArgmask);
	sqlite3_bind_text(stmtInsertRec, 9, rec->arg.c_str(), rec->arg.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 10, rec->srefIxVSge.c_str(), rec->srefIxVSge.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 11, rec->ixVJactype);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMClstn::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMClstn::insertRst(
			ListWzemMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMClstn::updateRec(
			WzemMClstn* rec
		) {
	sqlite3_bind_double(stmtUpdateRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMJob);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->srefIxVCall.c_str(), rec->srefIxVCall.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 5, rec->ixVTarget);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->ixVJobmask);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->tjbRefWzemMJob);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->ixVArgmask);
	sqlite3_bind_text(stmtUpdateRec, 9, rec->arg.c_str(), rec->arg.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 10, rec->srefIxVSge.c_str(), rec->srefIxVSge.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 11, rec->ixVJactype);
	sqlite3_bind_int64(stmtUpdateRec, 12, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMClstn::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMClstn::updateRst(
			ListWzemMClstn& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMClstn::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMClstn::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMClstn::loadRecByRef(
			ubigint ref
			, WzemMClstn** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemMClstn::loadRstByJob(
			ubigint refWzemMJob
			, const bool append
			, ListWzemMClstn& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByJob, 1, refWzemMJob);

	return loadRstByStmt(stmtLoadRstByJob, append, rst);
};

#endif

