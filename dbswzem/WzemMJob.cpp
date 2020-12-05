/**
	* \file WzemMJob.cpp
	* database access for table TblWzemMJob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "WzemMJob.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMJob
 ******************************************************************************/

WzemMJob::WzemMJob(
			const ubigint ref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMPeriod
			, const ubigint supRefWzemMJob
			, const string srefIxVJob
			, const ubigint xjref
			, const bool Clisrv
			, const bool srvNotCli
			, const bool Dcol
			, const bool Stmgr
		) {

	this->ref = ref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->refWzemMPeriod = refWzemMPeriod;
	this->supRefWzemMJob = supRefWzemMJob;
	this->srefIxVJob = srefIxVJob;
	this->xjref = xjref;
	this->Clisrv = Clisrv;
	this->srvNotCli = srvNotCli;
	this->Dcol = Dcol;
	this->Stmgr = Stmgr;
};

bool WzemMJob::operator==(
			const WzemMJob& comp
		) {
	return false;
};

bool WzemMJob::operator!=(
			const WzemMJob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMJob
 ******************************************************************************/

ListWzemMJob::ListWzemMJob() {
};

ListWzemMJob::ListWzemMJob(
			const ListWzemMJob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMJob(*(src.nodes[i]));
};

ListWzemMJob::~ListWzemMJob() {
	clear();
};

void ListWzemMJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMJob::size() const {
	return(nodes.size());
};

void ListWzemMJob::append(
			WzemMJob* rec
		) {
	nodes.push_back(rec);
};

WzemMJob* ListWzemMJob::operator[](
			const uint ix
		) {
	WzemMJob* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMJob& ListWzemMJob::operator=(
			const ListWzemMJob& src
		) {
	WzemMJob* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMJob(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMJob::operator==(
			const ListWzemMJob& comp
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

bool ListWzemMJob::operator!=(
			const ListWzemMJob& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMJob
 ******************************************************************************/

TblWzemMJob::TblWzemMJob() {
};

TblWzemMJob::~TblWzemMJob() {
};

bool TblWzemMJob::loadRecBySQL(
			const string& sqlstr
			, WzemMJob** rec
		) {
	return false;
};

ubigint TblWzemMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMJob& rst
		) {
	return 0;
};

ubigint TblWzemMJob::insertRec(
			WzemMJob* rec
		) {
	return 0;
};

ubigint TblWzemMJob::insertNewRec(
			WzemMJob** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMPeriod
			, const ubigint supRefWzemMJob
			, const string srefIxVJob
			, const ubigint xjref
			, const bool Clisrv
			, const bool srvNotCli
			, const bool Dcol
			, const bool Stmgr
		) {
	ubigint retval = 0;
	WzemMJob* _rec = NULL;

	_rec = new WzemMJob(0, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMJob::appendNewRecToRst(
			ListWzemMJob& rst
			, WzemMJob** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMPeriod
			, const ubigint supRefWzemMJob
			, const string srefIxVJob
			, const ubigint xjref
			, const bool Clisrv
			, const bool srvNotCli
			, const bool Dcol
			, const bool Stmgr
		) {
	ubigint retval = 0;
	WzemMJob* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMJob::insertRst(
			ListWzemMJob& rst
			, bool transact
		) {
};

void TblWzemMJob::updateRec(
			WzemMJob* rec
		) {
};

void TblWzemMJob::updateRst(
			ListWzemMJob& rst
			, bool transact
		) {
};

void TblWzemMJob::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMJob::loadRecByRef(
			ubigint ref
			, WzemMJob** rec
		) {
	return false;
};

bool TblWzemMJob::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblWzemMJob::loadRefsBySup(
			ubigint supRefWzemMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemMJob::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMJob& rst
		) {
	return 0;
};

ubigint TblWzemMJob::loadRstBySup(
			ubigint supRefWzemMJob
			, const bool append
			, ListWzemMJob& rst
		) {
	return 0;
};

bool TblWzemMJob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzemMJob
		) {
	return false;
};

bool TblWzemMJob::loadXjrByRef(
			ubigint ref
			, string& xjref
		) {
	return false;
};

ubigint TblWzemMJob::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMJob& rst
		) {
	ubigint numload = 0;
	WzemMJob* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWzemMJob::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWzemMJob::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

ubigint TblWzemMJob::loadHrstup(
			ubigint ref
			, ListWzemMJob& rst
		) {
	WzemMJob* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWzemMJob;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWzemMJob::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWzemMJob& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WzemMJob* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMJob
 ******************************************************************************/

MyTblWzemMJob::MyTblWzemMJob() :
			TblWzemMJob()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMJob::~MyTblWzemMJob() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMJob (x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMJob SET x1Startu = ?, x1Stopu = ?, refWzemMPeriod = ?, supRefWzemMJob = ?, srefIxVJob = ?, xjref = ?, Clisrv = ?, srvNotCli = ?, Dcol = ?, Stmgr = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMJob WHERE ref = ?", false);
};

bool MyTblWzemMJob::loadRecBySQL(
			const string& sqlstr
			, WzemMJob** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMJob* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMJob::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMJob::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMJob();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startu = atof((char*) dbrow[1]); else _rec->x1Startu = 0.0;
		if (dbrow[2]) _rec->x1Stopu = atof((char*) dbrow[2]); else _rec->x1Stopu = 0.0;
		if (dbrow[3]) _rec->refWzemMPeriod = atoll((char*) dbrow[3]); else _rec->refWzemMPeriod = 0;
		if (dbrow[4]) _rec->supRefWzemMJob = atoll((char*) dbrow[4]); else _rec->supRefWzemMJob = 0;
		if (dbrow[5]) _rec->srefIxVJob.assign(dbrow[5], dblengths[5]); else _rec->srefIxVJob = "";
		if (dbrow[6]) _rec->xjref = atoll((char*) dbrow[6]); else _rec->xjref = 0;
		if (dbrow[7]) _rec->Clisrv = (atoi((char*) dbrow[7]) != 0); else _rec->Clisrv = false;
		if (dbrow[8]) _rec->srvNotCli = (atoi((char*) dbrow[8]) != 0); else _rec->srvNotCli = false;
		if (dbrow[9]) _rec->Dcol = (atoi((char*) dbrow[9]) != 0); else _rec->Dcol = false;
		if (dbrow[10]) _rec->Stmgr = (atoi((char*) dbrow[10]) != 0); else _rec->Stmgr = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMJob& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMJob* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMJob::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMJob::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMJob();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startu = atof((char*) dbrow[1]); else rec->x1Startu = 0.0;
			if (dbrow[2]) rec->x1Stopu = atof((char*) dbrow[2]); else rec->x1Stopu = 0.0;
			if (dbrow[3]) rec->refWzemMPeriod = atoll((char*) dbrow[3]); else rec->refWzemMPeriod = 0;
			if (dbrow[4]) rec->supRefWzemMJob = atoll((char*) dbrow[4]); else rec->supRefWzemMJob = 0;
			if (dbrow[5]) rec->srefIxVJob.assign(dbrow[5], dblengths[5]); else rec->srefIxVJob = "";
			if (dbrow[6]) rec->xjref = atoll((char*) dbrow[6]); else rec->xjref = 0;
			if (dbrow[7]) rec->Clisrv = (atoi((char*) dbrow[7]) != 0); else rec->Clisrv = false;
			if (dbrow[8]) rec->srvNotCli = (atoi((char*) dbrow[8]) != 0); else rec->srvNotCli = false;
			if (dbrow[9]) rec->Dcol = (atoi((char*) dbrow[9]) != 0); else rec->Dcol = false;
			if (dbrow[10]) rec->Stmgr = (atoi((char*) dbrow[10]) != 0); else rec->Stmgr = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMJob::insertRec(
			WzemMJob* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->srefIxVJob.length();
	tinyint Clisrv = rec->Clisrv;
	tinyint srvNotCli = rec->srvNotCli;
	tinyint Dcol = rec->Dcol;
	tinyint Stmgr = rec->Stmgr;

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMPeriod,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->supRefWzemMJob,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefIxVJob.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->xjref,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Clisrv,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&srvNotCli,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Dcol,&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Stmgr,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMJob::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMJob::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMJob::insertRst(
			ListWzemMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMJob::updateRec(
			WzemMJob* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->srefIxVJob.length();
	tinyint Clisrv = rec->Clisrv;
	tinyint srvNotCli = rec->srvNotCli;
	tinyint Dcol = rec->Dcol;
	tinyint Stmgr = rec->Stmgr;

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMPeriod,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->supRefWzemMJob,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefIxVJob.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->xjref,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Clisrv,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&srvNotCli,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Dcol,&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Stmgr,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMJob::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMJob::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMJob::updateRst(
			ListWzemMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMJob::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMJob::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMJob::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMJob::loadRecByRef(
			ubigint ref
			, WzemMJob** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMJob WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemMJob::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWzemMJob WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblWzemMJob::loadRefsBySup(
			ubigint supRefWzemMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemMJob WHERE supRefWzemMJob = " + to_string(supRefWzemMJob) + "", append, refs);
};

ubigint MyTblWzemMJob::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMJob& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE refWzemMPeriod = " + to_string(refWzemMPeriod) + "", append, rst);
};

ubigint MyTblWzemMJob::loadRstBySup(
			ubigint supRefWzemMJob
			, const bool append
			, ListWzemMJob& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE supRefWzemMJob = " + to_string(supRefWzemMJob) + "", append, rst);
};

bool MyTblWzemMJob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzemMJob
		) {
	return loadRefBySQL("SELECT supRefWzemMJob FROM TblWzemMJob WHERE ref = " + to_string(ref) + "", supRefWzemMJob);
};

bool MyTblWzemMJob::loadXjrByRef(
			ubigint ref
			, string& xjref
		) {
	return loadStringBySQL("SELECT xjref FROM TblWzemMJob WHERE ref = " + to_string(ref) + "", xjref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMJob
 ******************************************************************************/

PgTblWzemMJob::PgTblWzemMJob() :
			TblWzemMJob()
			, PgTable()
		{
};

PgTblWzemMJob::~PgTblWzemMJob() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMJob::initStatements() {
	createStatement("TblWzemMJob_insertRec", "INSERT INTO TblWzemMJob (x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWzemMJob_updateRec", "UPDATE TblWzemMJob SET x1Startu = $1, x1Stopu = $2, refWzemMPeriod = $3, supRefWzemMJob = $4, srefIxVJob = $5, xjref = $6, Clisrv = $7, srvNotCli = $8, Dcol = $9, Stmgr = $10 WHERE ref = $11", 11);
	createStatement("TblWzemMJob_removeRecByRef", "DELETE FROM TblWzemMJob WHERE ref = $1", 1);

	createStatement("TblWzemMJob_loadRecByRef", "SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE ref = $1", 1);
	createStatement("TblWzemMJob_confirmByRef", "SELECT ref FROM TblWzemMJob WHERE ref = $1", 1);
	createStatement("TblWzemMJob_loadRefsBySup", "SELECT ref FROM TblWzemMJob WHERE supRefWzemMJob = $1", 1);
	createStatement("TblWzemMJob_loadRstByPrd", "SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE refWzemMPeriod = $1", 1);
	createStatement("TblWzemMJob_loadRstBySup", "SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE supRefWzemMJob = $1", 1);
	createStatement("TblWzemMJob_loadSupByRef", "SELECT supRefWzemMJob FROM TblWzemMJob WHERE ref = $1", 1);
	createStatement("TblWzemMJob_loadXjrByRef", "SELECT xjref FROM TblWzemMJob WHERE ref = $1", 1);
};

bool PgTblWzemMJob::loadRec(
			PGresult* res
			, WzemMJob** rec
		) {
	char* ptr;

	WzemMJob* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMJob();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "suprefwzemmjob"),
			PQfnumber(res, "srefixvjob"),
			PQfnumber(res, "xjref"),
			PQfnumber(res, "clisrv"),
			PQfnumber(res, "srvnotcli"),
			PQfnumber(res, "dcol"),
			PQfnumber(res, "stmgr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMPeriod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supRefWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefIxVJob.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->xjref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Clisrv = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srvNotCli = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Dcol = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Stmgr = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMJob::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMJob& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMJob* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "suprefwzemmjob"),
			PQfnumber(res, "srefixvjob"),
			PQfnumber(res, "xjref"),
			PQfnumber(res, "clisrv"),
			PQfnumber(res, "srvnotcli"),
			PQfnumber(res, "dcol"),
			PQfnumber(res, "stmgr")
		};

		while (numread < numrow) {
			rec = new WzemMJob();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMPeriod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supRefWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefIxVJob.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->xjref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Clisrv = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srvNotCli = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Dcol = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Stmgr = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMJob::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMJob** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMJob::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMJob::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMJob& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMJob::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMJob::loadRecBySQL(
			const string& sqlstr
			, WzemMJob** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMJob::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMJob& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMJob::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMJob::insertRec(
			WzemMJob* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _supRefWzemMJob = htonl64(rec->supRefWzemMJob);
	ubigint _xjref = htonl64(rec->xjref);
	smallint _Clisrv = htons((smallint) rec->Clisrv);
	smallint _srvNotCli = htons((smallint) rec->srvNotCli);
	smallint _Dcol = htons((smallint) rec->Dcol);
	smallint _Stmgr = htons((smallint) rec->Stmgr);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMPeriod,
		(char*) &_supRefWzemMJob,
		rec->srefIxVJob.c_str(),
		(char*) &_xjref,
		(char*) &_Clisrv,
		(char*) &_srvNotCli,
		(char*) &_Dcol,
		(char*) &_Stmgr
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(smallint)
	};
	const int f[] = {0, 0, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMJob_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMJob::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMJob::insertRst(
			ListWzemMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMJob::updateRec(
			WzemMJob* rec
		) {
	PGresult* res;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _supRefWzemMJob = htonl64(rec->supRefWzemMJob);
	ubigint _xjref = htonl64(rec->xjref);
	smallint _Clisrv = htons((smallint) rec->Clisrv);
	smallint _srvNotCli = htons((smallint) rec->srvNotCli);
	smallint _Dcol = htons((smallint) rec->Dcol);
	smallint _Stmgr = htons((smallint) rec->Stmgr);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMPeriod,
		(char*) &_supRefWzemMJob,
		rec->srefIxVJob.c_str(),
		(char*) &_xjref,
		(char*) &_Clisrv,
		(char*) &_srvNotCli,
		(char*) &_Dcol,
		(char*) &_Stmgr,
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMJob_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMJob::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMJob::updateRst(
			ListWzemMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMJob::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMJob_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMJob::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMJob::loadRecByRef(
			ubigint ref
			, WzemMJob** rec
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

	return loadRecByStmt("TblWzemMJob_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemMJob::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWzemMJob_confirmByRef", 1, vals, l, f, _ref);
};

ubigint PgTblWzemMJob::loadRefsBySup(
			ubigint supRefWzemMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWzemMJob = htonl64(supRefWzemMJob);

	const char* vals[] = {
		(char*) &_supRefWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemMJob_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemMJob::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMJob& rst
		) {
	ubigint _refWzemMPeriod = htonl64(refWzemMPeriod);

	const char* vals[] = {
		(char*) &_refWzemMPeriod
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMJob_loadRstByPrd", 1, vals, l, f, append, rst);
};

ubigint PgTblWzemMJob::loadRstBySup(
			ubigint supRefWzemMJob
			, const bool append
			, ListWzemMJob& rst
		) {
	ubigint _supRefWzemMJob = htonl64(supRefWzemMJob);

	const char* vals[] = {
		(char*) &_supRefWzemMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMJob_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWzemMJob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzemMJob
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWzemMJob_loadSupByRef", 1, vals, l, f, supRefWzemMJob);
};

bool PgTblWzemMJob::loadXjrByRef(
			ubigint ref
			, string& xjref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWzemMJob_loadXjrByRef", 1, vals, l, f, xjref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMJob
 ******************************************************************************/

LiteTblWzemMJob::LiteTblWzemMJob() :
			TblWzemMJob()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtConfirmByRef = NULL;
	stmtLoadRefsBySup = NULL;
	stmtLoadRstByPrd = NULL;
	stmtLoadRstBySup = NULL;
	stmtLoadSupByRef = NULL;
	stmtLoadXjrByRef = NULL;
};

LiteTblWzemMJob::~LiteTblWzemMJob() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtConfirmByRef) sqlite3_finalize(stmtConfirmByRef);
	if (stmtLoadRefsBySup) sqlite3_finalize(stmtLoadRefsBySup);
	if (stmtLoadRstByPrd) sqlite3_finalize(stmtLoadRstByPrd);
	if (stmtLoadRstBySup) sqlite3_finalize(stmtLoadRstBySup);
	if (stmtLoadSupByRef) sqlite3_finalize(stmtLoadSupByRef);
	if (stmtLoadXjrByRef) sqlite3_finalize(stmtLoadXjrByRef);
};

void LiteTblWzemMJob::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMJob (x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMJob SET x1Startu = ?1, x1Stopu = ?2, refWzemMPeriod = ?3, supRefWzemMJob = ?4, srefIxVJob = ?5, xjref = ?6, Clisrv = ?7, srvNotCli = ?8, Dcol = ?9, Stmgr = ?10 WHERE ref = ?11");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMJob WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE ref = ?1");
	stmtConfirmByRef = createStatement("SELECT ref FROM TblWzemMJob WHERE ref = ?1");
	stmtLoadRefsBySup = createStatement("SELECT ref FROM TblWzemMJob WHERE supRefWzemMJob = ?1");
	stmtLoadRstByPrd = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE refWzemMPeriod = ?1");
	stmtLoadRstBySup = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, supRefWzemMJob, srefIxVJob, xjref, Clisrv, srvNotCli, Dcol, Stmgr FROM TblWzemMJob WHERE supRefWzemMJob = ?1");
	stmtLoadSupByRef = createStatement("SELECT supRefWzemMJob FROM TblWzemMJob WHERE ref = ?1");
	stmtLoadXjrByRef = createStatement("SELECT xjref FROM TblWzemMJob WHERE ref = ?1");
};

bool LiteTblWzemMJob::loadRec(
			sqlite3_stmt* stmt
			, WzemMJob** rec
		) {
	int res;

	WzemMJob* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMJob();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->x1Startu = sqlite3_column_double(stmt, 1);
		_rec->x1Stopu = sqlite3_column_double(stmt, 2);
		_rec->refWzemMPeriod = sqlite3_column_int64(stmt, 3);
		_rec->supRefWzemMJob = sqlite3_column_int64(stmt, 4);
		_rec->srefIxVJob.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->xjref = sqlite3_column_int64(stmt, 6);
		_rec->Clisrv = (sqlite3_column_int(stmt, 7) != 0);
		_rec->srvNotCli = (sqlite3_column_int(stmt, 8) != 0);
		_rec->Dcol = (sqlite3_column_int(stmt, 9) != 0);
		_rec->Stmgr = (sqlite3_column_int(stmt, 10) != 0);

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

ubigint LiteTblWzemMJob::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMJob& rst
		) {
	int res; ubigint numread = 0;

	WzemMJob* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMJob();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->x1Startu = sqlite3_column_double(stmt, 1);
		rec->x1Stopu = sqlite3_column_double(stmt, 2);
		rec->refWzemMPeriod = sqlite3_column_int64(stmt, 3);
		rec->supRefWzemMJob = sqlite3_column_int64(stmt, 4);
		rec->srefIxVJob.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->xjref = sqlite3_column_int64(stmt, 6);
		rec->Clisrv = (sqlite3_column_int(stmt, 7) != 0);
		rec->srvNotCli = (sqlite3_column_int(stmt, 8) != 0);
		rec->Dcol = (sqlite3_column_int(stmt, 9) != 0);
		rec->Stmgr = (sqlite3_column_int(stmt, 10) != 0);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMJob::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMJob** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMJob::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMJob& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMJob::loadRecBySQL(
			const string& sqlstr
			, WzemMJob** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMJob::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMJob::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMJob& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMJob::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMJob::insertRec(
			WzemMJob* rec
		) {
	sqlite3_bind_double(stmtInsertRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->supRefWzemMJob);
	sqlite3_bind_text(stmtInsertRec, 5, rec->srefIxVJob.c_str(), rec->srefIxVJob.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->xjref);
	sqlite3_bind_int(stmtInsertRec, 7, rec->Clisrv);
	sqlite3_bind_int(stmtInsertRec, 8, rec->srvNotCli);
	sqlite3_bind_int(stmtInsertRec, 9, rec->Dcol);
	sqlite3_bind_int(stmtInsertRec, 10, rec->Stmgr);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMJob::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMJob::insertRst(
			ListWzemMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMJob::updateRec(
			WzemMJob* rec
		) {
	sqlite3_bind_double(stmtUpdateRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->supRefWzemMJob);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->srefIxVJob.c_str(), rec->srefIxVJob.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->xjref);
	sqlite3_bind_int(stmtUpdateRec, 7, rec->Clisrv);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->srvNotCli);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->Dcol);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->Stmgr);
	sqlite3_bind_int64(stmtUpdateRec, 11, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMJob::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMJob::updateRst(
			ListWzemMJob& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMJob::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMJob::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMJob::loadRecByRef(
			ubigint ref
			, WzemMJob** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemMJob::confirmByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtConfirmByRef, 1, ref);

	ubigint val;
	return loadRefByStmt(stmtConfirmByRef, val);
};

ubigint LiteTblWzemMJob::loadRefsBySup(
			ubigint supRefWzemMJob
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsBySup, 1, supRefWzemMJob);

	return loadRefsByStmt(stmtLoadRefsBySup, append, refs);
};

ubigint LiteTblWzemMJob::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMJob& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrd, 1, refWzemMPeriod);

	return loadRstByStmt(stmtLoadRstByPrd, append, rst);
};

ubigint LiteTblWzemMJob::loadRstBySup(
			ubigint supRefWzemMJob
			, const bool append
			, ListWzemMJob& rst
		) {
	sqlite3_bind_int64(stmtLoadRstBySup, 1, supRefWzemMJob);

	return loadRstByStmt(stmtLoadRstBySup, append, rst);
};

bool LiteTblWzemMJob::loadSupByRef(
			ubigint ref
			, ubigint& supRefWzemMJob
		) {
	sqlite3_bind_int64(stmtLoadSupByRef, 1, ref);

	return loadRefByStmt(stmtLoadSupByRef, supRefWzemMJob);
};

bool LiteTblWzemMJob::loadXjrByRef(
			ubigint ref
			, string& xjref
		) {
	sqlite3_bind_int64(stmtLoadXjrByRef, 1, ref);

	return loadStringByStmt(stmtLoadXjrByRef, xjref);
};

#endif

