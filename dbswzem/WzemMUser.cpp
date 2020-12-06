/**
	* \file WzemMUser.cpp
	* database access for table TblWzemMUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemMUser.h"

#include "WzemMUser_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMUser
 ******************************************************************************/

WzemMUser::WzemMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWzemMUsergroup
			, const ubigint refWzemMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWzemVLocale
			, const uint ixWzemVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refWzemMUsergroup = refWzemMUsergroup;
	this->refWzemMPerson = refWzemMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixWzemVLocale = ixWzemVLocale;
	this->ixWzemVUserlevel = ixWzemVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

bool WzemMUser::operator==(
			const WzemMUser& comp
		) {
	return false;
};

bool WzemMUser::operator!=(
			const WzemMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMUser
 ******************************************************************************/

ListWzemMUser::ListWzemMUser() {
};

ListWzemMUser::ListWzemMUser(
			const ListWzemMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMUser(*(src.nodes[i]));
};

ListWzemMUser::~ListWzemMUser() {
	clear();
};

void ListWzemMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMUser::size() const {
	return(nodes.size());
};

void ListWzemMUser::append(
			WzemMUser* rec
		) {
	nodes.push_back(rec);
};

WzemMUser* ListWzemMUser::operator[](
			const uint ix
		) {
	WzemMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMUser& ListWzemMUser::operator=(
			const ListWzemMUser& src
		) {
	WzemMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMUser::operator==(
			const ListWzemMUser& comp
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

bool ListWzemMUser::operator!=(
			const ListWzemMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMUser
 ******************************************************************************/

TblWzemMUser::TblWzemMUser() {
};

TblWzemMUser::~TblWzemMUser() {
};

bool TblWzemMUser::loadRecBySQL(
			const string& sqlstr
			, WzemMUser** rec
		) {
	return false;
};

ubigint TblWzemMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMUser& rst
		) {
	return 0;
};

ubigint TblWzemMUser::insertRec(
			WzemMUser* rec
		) {
	return 0;
};

ubigint TblWzemMUser::insertNewRec(
			WzemMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWzemMUsergroup
			, const ubigint refWzemMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWzemVLocale
			, const uint ixWzemVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WzemMUser* _rec = NULL;

	_rec = new WzemMUser(0, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMUser::appendNewRecToRst(
			ListWzemMUser& rst
			, WzemMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWzemMUsergroup
			, const ubigint refWzemMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWzemVLocale
			, const uint ixWzemVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WzemMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMUser::insertRst(
			ListWzemMUser& rst
			, bool transact
		) {
};

void TblWzemMUser::updateRec(
			WzemMUser* rec
		) {
};

void TblWzemMUser::updateRst(
			ListWzemMUser& rst
			, bool transact
		) {
};

void TblWzemMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMUser::loadRecByRef(
			ubigint ref
			, WzemMUser** rec
		) {
	return false;
};

bool TblWzemMUser::loadRecByPrs(
			ubigint refWzemMPerson
			, WzemMUser** rec
		) {
	return false;
};

bool TblWzemMUser::loadRecBySrf(
			string sref
			, WzemMUser** rec
		) {
	return false;
};

bool TblWzemMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzemMUser** rec
		) {
	return false;
};

bool TblWzemMUser::loadRefByPrs(
			ubigint refWzemMPerson
			, ubigint& ref
		) {
	return false;
};

bool TblWzemMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWzemMUser::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblWzemMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWzemMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMUser& rst
		) {
	ubigint numload = 0;
	WzemMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMUser
 ******************************************************************************/

MyTblWzemMUser::MyTblWzemMUser() :
			TblWzemMUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMUser::~MyTblWzemMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMUser (grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMUser SET grp = ?, own = ?, refRUsergroup = ?, refWzemMUsergroup = ?, refWzemMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixWzemVLocale = ?, ixWzemVUserlevel = ?, Password = ?, Fullkey = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMUser WHERE ref = ?", false);
};

bool MyTblWzemMUser::loadRecBySQL(
			const string& sqlstr
			, WzemMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refWzemMUsergroup = atoll((char*) dbrow[4]); else _rec->refWzemMUsergroup = 0;
		if (dbrow[5]) _rec->refWzemMPerson = atoll((char*) dbrow[5]); else _rec->refWzemMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixWzemVLocale = atol((char*) dbrow[9]); else _rec->ixWzemVLocale = 0;
		if (dbrow[10]) _rec->ixWzemVUserlevel = atol((char*) dbrow[10]); else _rec->ixWzemVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";
		if (dbrow[12]) _rec->Fullkey.assign(dbrow[12], dblengths[12]); else _rec->Fullkey = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refWzemMUsergroup = atoll((char*) dbrow[4]); else rec->refWzemMUsergroup = 0;
			if (dbrow[5]) rec->refWzemMPerson = atoll((char*) dbrow[5]); else rec->refWzemMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixWzemVLocale = atol((char*) dbrow[9]); else rec->ixWzemVLocale = 0;
			if (dbrow[10]) rec->ixWzemVUserlevel = atol((char*) dbrow[10]); else rec->ixWzemVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			if (dbrow[12]) rec->Fullkey.assign(dbrow[12], dblengths[12]); else rec->Fullkey = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMUser::insertRec(
			WzemMUser* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzemMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWzemVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzemVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMUser::insertRst(
			ListWzemMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMUser::updateRec(
			WzemMUser* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWzemMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWzemVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWzemVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMUser::updateRst(
			ListWzemMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMUser::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMUser::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMUser::loadRecByRef(
			ubigint ref
			, WzemMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemMUser::loadRecByPrs(
			ubigint refWzemMPerson
			, WzemMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE refWzemMPerson = " + to_string(refWzemMPerson) + "", rec);
};

bool MyTblWzemMUser::loadRecBySrf(
			string sref
			, WzemMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE sref = '" + sref + "'", rec);
};

bool MyTblWzemMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzemMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", rec);
};

bool MyTblWzemMUser::loadRefByPrs(
			ubigint refWzemMPerson
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzemMUser WHERE refWzemMPerson = " + to_string(refWzemMPerson) + "", ref);
};

bool MyTblWzemMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzemMUser WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblWzemMUser::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemMUser WHERE refWzemMUsergroup = " + to_string(refWzemMUsergroup) + "", append, refs);
};

bool MyTblWzemMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWzemMUser WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMUser
 ******************************************************************************/

PgTblWzemMUser::PgTblWzemMUser() :
			TblWzemMUser()
			, PgTable()
		{
};

PgTblWzemMUser::~PgTblWzemMUser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMUser::initStatements() {
	createStatement("TblWzemMUser_insertRec", "INSERT INTO TblWzemMUser (grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWzemMUser_updateRec", "UPDATE TblWzemMUser SET grp = $1, own = $2, refRUsergroup = $3, refWzemMUsergroup = $4, refWzemMPerson = $5, sref = $6, refJState = $7, ixVState = $8, ixWzemVLocale = $9, ixWzemVUserlevel = $10, Password = $11, Fullkey = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblWzemMUser_removeRecByRef", "DELETE FROM TblWzemMUser WHERE ref = $1", 1);

	createStatement("TblWzemMUser_loadRecByRef", "SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE ref = $1", 1);
	createStatement("TblWzemMUser_loadRecByPrs", "SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE refWzemMPerson = $1", 1);
	createStatement("TblWzemMUser_loadRecBySrf", "SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE sref = $1", 1);
	createStatement("TblWzemMUser_loadRecBySrfPwd", "SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE sref = $1 AND Password = $2", 2);
	createStatement("TblWzemMUser_loadRefByPrs", "SELECT ref FROM TblWzemMUser WHERE refWzemMPerson = $1", 1);
	createStatement("TblWzemMUser_loadRefBySrf", "SELECT ref FROM TblWzemMUser WHERE sref = $1", 1);
	createStatement("TblWzemMUser_loadRefsByUsg", "SELECT ref FROM TblWzemMUser WHERE refWzemMUsergroup = $1", 1);
	createStatement("TblWzemMUser_loadSrfByRef", "SELECT sref FROM TblWzemMUser WHERE ref = $1", 1);
};

bool PgTblWzemMUser::loadRec(
			PGresult* res
			, WzemMUser** rec
		) {
	char* ptr;

	WzemMUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMUser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwzemvlocale"),
			PQfnumber(res, "ixwzemvuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refRUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWzemMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWzemMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixWzemVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWzemVUserlevel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Password.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Fullkey.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMUser::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMUser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refwzemmusergroup"),
			PQfnumber(res, "refwzemmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwzemvlocale"),
			PQfnumber(res, "ixwzemvuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WzemMUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refRUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWzemMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWzemMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixWzemVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWzemVUserlevel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Password.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Fullkey.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMUser::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWzemMUser::loadRecBySQL(
			const string& sqlstr
			, WzemMUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMUser::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMUser::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMUser::insertRec(
			WzemMUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWzemVLocale = htonl(rec->ixWzemVLocale);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refWzemMUsergroup,
		(char*) &_refWzemMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWzemVLocale,
		(char*) &_ixWzemVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemMUser_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMUser::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMUser::insertRst(
			ListWzemMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMUser::updateRec(
			WzemMUser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refWzemMUsergroup = htonl64(rec->refWzemMUsergroup);
	ubigint _refWzemMPerson = htonl64(rec->refWzemMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWzemVLocale = htonl(rec->ixWzemVLocale);
	uint _ixWzemVUserlevel = htonl(rec->ixWzemVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refWzemMUsergroup,
		(char*) &_refWzemMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWzemVLocale,
		(char*) &_ixWzemVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemMUser_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMUser::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMUser::updateRst(
			ListWzemMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMUser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMUser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMUser::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMUser::loadRecByRef(
			ubigint ref
			, WzemMUser** rec
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

	return loadRecByStmt("TblWzemMUser_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemMUser::loadRecByPrs(
			ubigint refWzemMPerson
			, WzemMUser** rec
		) {
	ubigint _refWzemMPerson = htonl64(refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWzemMUser_loadRecByPrs", 1, vals, l, f, rec);
};

bool PgTblWzemMUser::loadRecBySrf(
			string sref
			, WzemMUser** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblWzemMUser_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblWzemMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzemMUser** rec
		) {

	const char* vals[] = {
		sref.c_str(),
		Password.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadRecByStmt("TblWzemMUser_loadRecBySrfPwd", 2, vals, l, f, rec);
};

bool PgTblWzemMUser::loadRefByPrs(
			ubigint refWzemMPerson
			, ubigint& ref
		) {
	ubigint _refWzemMPerson = htonl64(refWzemMPerson);

	const char* vals[] = {
		(char*) &_refWzemMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWzemMUser_loadRefByPrs", 1, vals, l, f, ref);
};

bool PgTblWzemMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWzemMUser_loadRefBySrf", 1, vals, l, f, ref);
};

ubigint PgTblWzemMUser::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemMUsergroup = htonl64(refWzemMUsergroup);

	const char* vals[] = {
		(char*) &_refWzemMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemMUser_loadRefsByUsg", 1, vals, l, f, append, refs);
};

bool PgTblWzemMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWzemMUser_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMUser
 ******************************************************************************/

LiteTblWzemMUser::LiteTblWzemMUser() :
			TblWzemMUser()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByPrs = NULL;
	stmtLoadRecBySrf = NULL;
	stmtLoadRecBySrfPwd = NULL;
	stmtLoadRefByPrs = NULL;
	stmtLoadRefBySrf = NULL;
	stmtLoadRefsByUsg = NULL;
	stmtLoadSrfByRef = NULL;
};

LiteTblWzemMUser::~LiteTblWzemMUser() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByPrs) sqlite3_finalize(stmtLoadRecByPrs);
	if (stmtLoadRecBySrf) sqlite3_finalize(stmtLoadRecBySrf);
	if (stmtLoadRecBySrfPwd) sqlite3_finalize(stmtLoadRecBySrfPwd);
	if (stmtLoadRefByPrs) sqlite3_finalize(stmtLoadRefByPrs);
	if (stmtLoadRefBySrf) sqlite3_finalize(stmtLoadRefBySrf);
	if (stmtLoadRefsByUsg) sqlite3_finalize(stmtLoadRefsByUsg);
	if (stmtLoadSrfByRef) sqlite3_finalize(stmtLoadSrfByRef);
};

void LiteTblWzemMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMUser (grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11,?12,?13)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMUser SET grp = ?1, own = ?2, refRUsergroup = ?3, refWzemMUsergroup = ?4, refWzemMPerson = ?5, sref = ?6, refJState = ?7, ixVState = ?8, ixWzemVLocale = ?9, ixWzemVUserlevel = ?10, Password = ?11, Fullkey = ?12, Comment = ?13 WHERE ref = ?14");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMUser WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE ref = ?1");
	stmtLoadRecByPrs = createStatement("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE refWzemMPerson = ?1");
	stmtLoadRecBySrf = createStatement("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE sref = ?1");
	stmtLoadRecBySrfPwd = createStatement("SELECT ref, grp, own, refRUsergroup, refWzemMUsergroup, refWzemMPerson, sref, refJState, ixVState, ixWzemVLocale, ixWzemVUserlevel, Password, Fullkey, Comment FROM TblWzemMUser WHERE sref = ?1 AND Password = ?2");
	stmtLoadRefByPrs = createStatement("SELECT ref FROM TblWzemMUser WHERE refWzemMPerson = ?1");
	stmtLoadRefBySrf = createStatement("SELECT ref FROM TblWzemMUser WHERE sref = ?1");
	stmtLoadRefsByUsg = createStatement("SELECT ref FROM TblWzemMUser WHERE refWzemMUsergroup = ?1");
	stmtLoadSrfByRef = createStatement("SELECT sref FROM TblWzemMUser WHERE ref = ?1");
};

bool LiteTblWzemMUser::loadRec(
			sqlite3_stmt* stmt
			, WzemMUser** rec
		) {
	int res;

	WzemMUser* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMUser();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->grp = sqlite3_column_int64(stmt, 1);
		_rec->own = sqlite3_column_int64(stmt, 2);
		_rec->refRUsergroup = sqlite3_column_int64(stmt, 3);
		_rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 4);
		_rec->refWzemMPerson = sqlite3_column_int64(stmt, 5);
		_rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		_rec->refJState = sqlite3_column_int64(stmt, 7);
		_rec->ixVState = sqlite3_column_int(stmt, 8);
		_rec->ixWzemVLocale = sqlite3_column_int(stmt, 9);
		_rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 10);
		_rec->Password.assign((const char*) sqlite3_column_text(stmt, 11));
		_rec->Fullkey.assign((const char*) sqlite3_column_text(stmt, 12));
		_rec->Comment.assign((const char*) sqlite3_column_text(stmt, 13));

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

ubigint LiteTblWzemMUser::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMUser& rst
		) {
	int res; ubigint numread = 0;

	WzemMUser* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMUser();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->grp = sqlite3_column_int64(stmt, 1);
		rec->own = sqlite3_column_int64(stmt, 2);
		rec->refRUsergroup = sqlite3_column_int64(stmt, 3);
		rec->refWzemMUsergroup = sqlite3_column_int64(stmt, 4);
		rec->refWzemMPerson = sqlite3_column_int64(stmt, 5);
		rec->sref.assign((const char*) sqlite3_column_text(stmt, 6));
		rec->refJState = sqlite3_column_int64(stmt, 7);
		rec->ixVState = sqlite3_column_int(stmt, 8);
		rec->ixWzemVLocale = sqlite3_column_int(stmt, 9);
		rec->ixWzemVUserlevel = sqlite3_column_int(stmt, 10);
		rec->Password.assign((const char*) sqlite3_column_text(stmt, 11));
		rec->Fullkey.assign((const char*) sqlite3_column_text(stmt, 12));
		rec->Comment.assign((const char*) sqlite3_column_text(stmt, 13));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMUser::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMUser** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMUser::loadRecBySQL(
			const string& sqlstr
			, WzemMUser** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMUser::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMUser& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMUser::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMUser::insertRec(
			WzemMUser* rec
		) {
	sqlite3_bind_int64(stmtInsertRec, 1, rec->grp);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->own);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refRUsergroup);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzemMUsergroup);
	sqlite3_bind_int64(stmtInsertRec, 5, rec->refWzemMPerson);
	sqlite3_bind_text(stmtInsertRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->refJState);
	sqlite3_bind_int(stmtInsertRec, 8, rec->ixVState);
	sqlite3_bind_int(stmtInsertRec, 9, rec->ixWzemVLocale);
	sqlite3_bind_int(stmtInsertRec, 10, rec->ixWzemVUserlevel);
	sqlite3_bind_text(stmtInsertRec, 11, rec->Password.c_str(), rec->Password.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 12, rec->Fullkey.c_str(), rec->Fullkey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 13, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMUser::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMUser::insertRst(
			ListWzemMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMUser::updateRec(
			WzemMUser* rec
		) {
	sqlite3_bind_int64(stmtUpdateRec, 1, rec->grp);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->own);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refRUsergroup);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzemMUsergroup);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->refWzemMPerson);
	sqlite3_bind_text(stmtUpdateRec, 6, rec->sref.c_str(), rec->sref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->refJState);
	sqlite3_bind_int(stmtUpdateRec, 8, rec->ixVState);
	sqlite3_bind_int(stmtUpdateRec, 9, rec->ixWzemVLocale);
	sqlite3_bind_int(stmtUpdateRec, 10, rec->ixWzemVUserlevel);
	sqlite3_bind_text(stmtUpdateRec, 11, rec->Password.c_str(), rec->Password.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 12, rec->Fullkey.c_str(), rec->Fullkey.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 13, rec->Comment.c_str(), rec->Comment.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 14, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMUser::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMUser::updateRst(
			ListWzemMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMUser::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMUser::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMUser::loadRecByRef(
			ubigint ref
			, WzemMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemMUser::loadRecByPrs(
			ubigint refWzemMPerson
			, WzemMUser** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByPrs, 1, refWzemMPerson);

	return loadRecByStmt(stmtLoadRecByPrs, rec);
};

bool LiteTblWzemMUser::loadRecBySrf(
			string sref
			, WzemMUser** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrf, rec);
};

bool LiteTblWzemMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WzemMUser** rec
		) {
	sqlite3_bind_text(stmtLoadRecBySrfPwd, 1, sref.c_str(), sref.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtLoadRecBySrfPwd, 2, Password.c_str(), Password.length(), SQLITE_STATIC);

	return loadRecByStmt(stmtLoadRecBySrfPwd, rec);
};

bool LiteTblWzemMUser::loadRefByPrs(
			ubigint refWzemMPerson
			, ubigint& ref
		) {
	sqlite3_bind_int64(stmtLoadRefByPrs, 1, refWzemMPerson);

	return loadRefByStmt(stmtLoadRefByPrs, ref);
};

bool LiteTblWzemMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	sqlite3_bind_text(stmtLoadRefBySrf, 1, sref.c_str(), sref.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefBySrf, ref);
};

ubigint LiteTblWzemMUser::loadRefsByUsg(
			ubigint refWzemMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByUsg, 1, refWzemMUsergroup);

	return loadRefsByStmt(stmtLoadRefsByUsg, append, refs);
};

bool LiteTblWzemMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	sqlite3_bind_int64(stmtLoadSrfByRef, 1, ref);

	return loadStringByStmt(stmtLoadSrfByRef, sref);
};

#endif
