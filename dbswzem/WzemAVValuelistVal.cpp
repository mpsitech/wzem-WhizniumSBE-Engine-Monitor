/**
	* \file WzemAVValuelistVal.cpp
	* database access for table TblWzemAVValuelistVal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#include "WzemAVValuelistVal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAVValuelistVal
 ******************************************************************************/

WzemAVValuelistVal::WzemAVValuelistVal(
			const ubigint ref
			, const uint vlsIxWzemVValuelist
			, const uint vlsNum
			, const uint x1IxWzemVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxWzemVValuelist = vlsIxWzemVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxWzemVLocale = x1IxWzemVLocale;
	this->Val = Val;
};

bool WzemAVValuelistVal::operator==(
			const WzemAVValuelistVal& comp
		) {
	return false;
};

bool WzemAVValuelistVal::operator!=(
			const WzemAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAVValuelistVal
 ******************************************************************************/

ListWzemAVValuelistVal::ListWzemAVValuelistVal() {
};

ListWzemAVValuelistVal::ListWzemAVValuelistVal(
			const ListWzemAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAVValuelistVal(*(src.nodes[i]));
};

ListWzemAVValuelistVal::~ListWzemAVValuelistVal() {
	clear();
};

void ListWzemAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAVValuelistVal::size() const {
	return(nodes.size());
};

void ListWzemAVValuelistVal::append(
			WzemAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

WzemAVValuelistVal* ListWzemAVValuelistVal::operator[](
			const uint ix
		) {
	WzemAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAVValuelistVal& ListWzemAVValuelistVal::operator=(
			const ListWzemAVValuelistVal& src
		) {
	WzemAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAVValuelistVal::operator==(
			const ListWzemAVValuelistVal& comp
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

bool ListWzemAVValuelistVal::operator!=(
			const ListWzemAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAVValuelistVal
 ******************************************************************************/

TblWzemAVValuelistVal::TblWzemAVValuelistVal() {
};

TblWzemAVValuelistVal::~TblWzemAVValuelistVal() {
};

bool TblWzemAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzemAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWzemAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWzemAVValuelistVal::insertRec(
			WzemAVValuelistVal* rec
		) {
	return 0;
};

ubigint TblWzemAVValuelistVal::insertNewRec(
			WzemAVValuelistVal** rec
			, const uint vlsIxWzemVValuelist
			, const uint vlsNum
			, const uint x1IxWzemVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WzemAVValuelistVal* _rec = NULL;

	_rec = new WzemAVValuelistVal(0, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAVValuelistVal::appendNewRecToRst(
			ListWzemAVValuelistVal& rst
			, WzemAVValuelistVal** rec
			, const uint vlsIxWzemVValuelist
			, const uint vlsNum
			, const uint x1IxWzemVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WzemAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAVValuelistVal::insertRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
};

void TblWzemAVValuelistVal::updateRec(
			WzemAVValuelistVal* rec
		) {
};

void TblWzemAVValuelistVal::updateRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
};

void TblWzemAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzemAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWzemAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzemVValuelist
			, uint x1IxWzemVLocale
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWzemAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	ubigint numload = 0;
	WzemAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAVValuelistVal
 ******************************************************************************/

MyTblWzemAVValuelistVal::MyTblWzemAVValuelistVal() :
			TblWzemAVValuelistVal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAVValuelistVal::~MyTblWzemAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAVValuelistVal (vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAVValuelistVal SET vlsIxWzemVValuelist = ?, vlsNum = ?, x1IxWzemVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAVValuelistVal WHERE ref = ?", false);
};

bool MyTblWzemAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzemAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAVValuelistVal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAVValuelistVal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxWzemVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxWzemVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxWzemVLocale = atol((char*) dbrow[3]); else _rec->x1IxWzemVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAVValuelistVal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAVValuelistVal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxWzemVValuelist = atol((char*) dbrow[1]); else rec->vlsIxWzemVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxWzemVLocale = atol((char*) dbrow[3]); else rec->x1IxWzemVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemAVValuelistVal::insertRec(
			WzemAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWzemVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzemVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAVValuelistVal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAVValuelistVal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAVValuelistVal::insertRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAVValuelistVal::updateRec(
			WzemAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWzemVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWzemVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAVValuelistVal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAVValuelistVal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAVValuelistVal::updateRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAVValuelistVal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAVValuelistVal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzemAVValuelistVal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzemVValuelist
			, uint x1IxWzemVLocale
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val FROM TblWzemAVValuelistVal WHERE vlsIxWzemVValuelist = " + to_string(vlsIxWzemVValuelist) + " AND x1IxWzemVLocale = " + to_string(x1IxWzemVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAVValuelistVal
 ******************************************************************************/

PgTblWzemAVValuelistVal::PgTblWzemAVValuelistVal() :
			TblWzemAVValuelistVal()
			, PgTable()
		{
};

PgTblWzemAVValuelistVal::~PgTblWzemAVValuelistVal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAVValuelistVal::initStatements() {
	createStatement("TblWzemAVValuelistVal_insertRec", "INSERT INTO TblWzemAVValuelistVal (vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWzemAVValuelistVal_updateRec", "UPDATE TblWzemAVValuelistVal SET vlsIxWzemVValuelist = $1, vlsNum = $2, x1IxWzemVLocale = $3, Val = $4 WHERE ref = $5", 5);
	createStatement("TblWzemAVValuelistVal_removeRecByRef", "DELETE FROM TblWzemAVValuelistVal WHERE ref = $1", 1);

	createStatement("TblWzemAVValuelistVal_loadRecByRef", "SELECT ref, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val FROM TblWzemAVValuelistVal WHERE ref = $1", 1);
	createStatement("TblWzemAVValuelistVal_loadRstByVlsLcl", "SELECT ref, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val FROM TblWzemAVValuelistVal WHERE vlsIxWzemVValuelist = $1 AND x1IxWzemVLocale = $2 ORDER BY vlsNum ASC", 2);
};

bool PgTblWzemAVValuelistVal::loadRec(
			PGresult* res
			, WzemAVValuelistVal** rec
		) {
	char* ptr;

	WzemAVValuelistVal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAVValuelistVal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixwzemvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixwzemvlocale"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vlsIxWzemVValuelist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vlsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxWzemVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAVValuelistVal::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAVValuelistVal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixwzemvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixwzemvlocale"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WzemAVValuelistVal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vlsIxWzemVValuelist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vlsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxWzemVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemAVValuelistVal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVValuelistVal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAVValuelistVal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVValuelistVal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzemAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVValuelistVal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVValuelistVal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAVValuelistVal::insertRec(
			WzemAVValuelistVal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _vlsIxWzemVValuelist = htonl(rec->vlsIxWzemVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxWzemVLocale = htonl(rec->x1IxWzemVLocale);

	const char* vals[] = {
		(char*) &_vlsIxWzemVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxWzemVLocale,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWzemAVValuelistVal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVValuelistVal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAVValuelistVal::insertRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAVValuelistVal::updateRec(
			WzemAVValuelistVal* rec
		) {
	PGresult* res;

	uint _vlsIxWzemVValuelist = htonl(rec->vlsIxWzemVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxWzemVLocale = htonl(rec->x1IxWzemVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vlsIxWzemVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxWzemVLocale,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemAVValuelistVal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAVValuelistVal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAVValuelistVal::updateRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAVValuelistVal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemAVValuelistVal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAVValuelistVal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzemAVValuelistVal** rec
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

	return loadRecByStmt("TblWzemAVValuelistVal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzemVValuelist
			, uint x1IxWzemVLocale
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	uint _vlsIxWzemVValuelist = htonl(vlsIxWzemVValuelist);
	uint _x1IxWzemVLocale = htonl(x1IxWzemVLocale);

	const char* vals[] = {
		(char*) &_vlsIxWzemVValuelist,
		(char*) &_x1IxWzemVLocale
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWzemAVValuelistVal_loadRstByVlsLcl", 2, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAVValuelistVal
 ******************************************************************************/

LiteTblWzemAVValuelistVal::LiteTblWzemAVValuelistVal() :
			TblWzemAVValuelistVal()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByVlsLcl = NULL;
};

LiteTblWzemAVValuelistVal::~LiteTblWzemAVValuelistVal() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByVlsLcl) sqlite3_finalize(stmtLoadRstByVlsLcl);
};

void LiteTblWzemAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAVValuelistVal (vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val) VALUES (?1,?2,?3,?4)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAVValuelistVal SET vlsIxWzemVValuelist = ?1, vlsNum = ?2, x1IxWzemVLocale = ?3, Val = ?4 WHERE ref = ?5");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAVValuelistVal WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val FROM TblWzemAVValuelistVal WHERE ref = ?1");
	stmtLoadRstByVlsLcl = createStatement("SELECT ref, vlsIxWzemVValuelist, vlsNum, x1IxWzemVLocale, Val FROM TblWzemAVValuelistVal WHERE vlsIxWzemVValuelist = ?1 AND x1IxWzemVLocale = ?2 ORDER BY vlsNum ASC");
};

bool LiteTblWzemAVValuelistVal::loadRec(
			sqlite3_stmt* stmt
			, WzemAVValuelistVal** rec
		) {
	int res;

	WzemAVValuelistVal* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAVValuelistVal();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->vlsIxWzemVValuelist = sqlite3_column_int(stmt, 1);
		_rec->vlsNum = sqlite3_column_int(stmt, 2);
		_rec->x1IxWzemVLocale = sqlite3_column_int(stmt, 3);
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 4));

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

ubigint LiteTblWzemAVValuelistVal::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	int res; ubigint numread = 0;

	WzemAVValuelistVal* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAVValuelistVal();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->vlsIxWzemVValuelist = sqlite3_column_int(stmt, 1);
		rec->vlsNum = sqlite3_column_int(stmt, 2);
		rec->x1IxWzemVLocale = sqlite3_column_int(stmt, 3);
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 4));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAVValuelistVal::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAVValuelistVal** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemAVValuelistVal::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WzemAVValuelistVal** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAVValuelistVal::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAVValuelistVal::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAVValuelistVal::insertRec(
			WzemAVValuelistVal* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->vlsIxWzemVValuelist);
	sqlite3_bind_int(stmtInsertRec, 2, rec->vlsNum);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x1IxWzemVLocale);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVValuelistVal::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAVValuelistVal::insertRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAVValuelistVal::updateRec(
			WzemAVValuelistVal* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->vlsIxWzemVValuelist);
	sqlite3_bind_int(stmtUpdateRec, 2, rec->vlsNum);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x1IxWzemVLocale);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 5, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVValuelistVal::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAVValuelistVal::updateRst(
			ListWzemAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVValuelistVal::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAVValuelistVal::loadRecByRef(
			ubigint ref
			, WzemAVValuelistVal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWzemVValuelist
			, uint x1IxWzemVLocale
			, const bool append
			, ListWzemAVValuelistVal& rst
		) {
	sqlite3_bind_int(stmtLoadRstByVlsLcl, 1, vlsIxWzemVValuelist);
	sqlite3_bind_int(stmtLoadRstByVlsLcl, 2, x1IxWzemVLocale);

	return loadRstByStmt(stmtLoadRstByVlsLcl, append, rst);
};

#endif

