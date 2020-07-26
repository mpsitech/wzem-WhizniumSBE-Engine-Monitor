/**
	* \file WzemAVControlPar.cpp
	* database access for table TblWzemAVControlPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "WzemAVControlPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemAVControlPar
 ******************************************************************************/

WzemAVControlPar::WzemAVControlPar(
			const ubigint ref
			, const uint ixWzemVControl
			, const ubigint x1RefWzemMUser
			, const uint x2IxWzemVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixWzemVControl = ixWzemVControl;
	this->x1RefWzemMUser = x1RefWzemMUser;
	this->x2IxWzemVLocale = x2IxWzemVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool WzemAVControlPar::operator==(
			const WzemAVControlPar& comp
		) {
	return false;
};

bool WzemAVControlPar::operator!=(
			const WzemAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemAVControlPar
 ******************************************************************************/

ListWzemAVControlPar::ListWzemAVControlPar() {
};

ListWzemAVControlPar::ListWzemAVControlPar(
			const ListWzemAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemAVControlPar(*(src.nodes[i]));
};

ListWzemAVControlPar::~ListWzemAVControlPar() {
	clear();
};

void ListWzemAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemAVControlPar::size() const {
	return(nodes.size());
};

void ListWzemAVControlPar::append(
			WzemAVControlPar* rec
		) {
	nodes.push_back(rec);
};

WzemAVControlPar* ListWzemAVControlPar::operator[](
			const uint ix
		) {
	WzemAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemAVControlPar& ListWzemAVControlPar::operator=(
			const ListWzemAVControlPar& src
		) {
	WzemAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemAVControlPar::operator==(
			const ListWzemAVControlPar& comp
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

bool ListWzemAVControlPar::operator!=(
			const ListWzemAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemAVControlPar
 ******************************************************************************/

TblWzemAVControlPar::TblWzemAVControlPar() {
};

TblWzemAVControlPar::~TblWzemAVControlPar() {
};

bool TblWzemAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzemAVControlPar** rec
		) {
	return false;
};

ubigint TblWzemAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	return 0;
};

ubigint TblWzemAVControlPar::insertRec(
			WzemAVControlPar* rec
		) {
	return 0;
};

ubigint TblWzemAVControlPar::insertNewRec(
			WzemAVControlPar** rec
			, const uint ixWzemVControl
			, const ubigint x1RefWzemMUser
			, const uint x2IxWzemVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WzemAVControlPar* _rec = NULL;

	_rec = new WzemAVControlPar(0, ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemAVControlPar::appendNewRecToRst(
			ListWzemAVControlPar& rst
			, WzemAVControlPar** rec
			, const uint ixWzemVControl
			, const ubigint x1RefWzemMUser
			, const uint x2IxWzemVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WzemAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemAVControlPar::insertRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
};

void TblWzemAVControlPar::updateRec(
			WzemAVControlPar* rec
		) {
};

void TblWzemAVControlPar::updateRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
};

void TblWzemAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemAVControlPar::loadRecByRef(
			ubigint ref
			, WzemAVControlPar** rec
		) {
	return false;
};

bool TblWzemAVControlPar::loadRefByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, ubigint& ref
		) {
	return false;
};

bool TblWzemAVControlPar::loadValByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, string& Val
		) {
	return false;
};

ubigint TblWzemAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	ubigint numload = 0;
	WzemAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemAVControlPar
 ******************************************************************************/

MyTblWzemAVControlPar::MyTblWzemAVControlPar() :
			TblWzemAVControlPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemAVControlPar::~MyTblWzemAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAVControlPar (ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemAVControlPar SET ixWzemVControl = ?, x1RefWzemMUser = ?, x2IxWzemVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAVControlPar WHERE ref = ?", false);
};

bool MyTblWzemAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzemAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAVControlPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAVControlPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixWzemVControl = atol((char*) dbrow[1]); else _rec->ixWzemVControl = 0;
		if (dbrow[2]) _rec->x1RefWzemMUser = atoll((char*) dbrow[2]); else _rec->x1RefWzemMUser = 0;
		if (dbrow[3]) _rec->x2IxWzemVLocale = atol((char*) dbrow[3]); else _rec->x2IxWzemVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemAVControlPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemAVControlPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixWzemVControl = atol((char*) dbrow[1]); else rec->ixWzemVControl = 0;
			if (dbrow[2]) rec->x1RefWzemMUser = atoll((char*) dbrow[2]); else rec->x1RefWzemMUser = 0;
			if (dbrow[3]) rec->x2IxWzemVLocale = atol((char*) dbrow[3]); else rec->x2IxWzemVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemAVControlPar::insertRec(
			WzemAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWzemVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWzemMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWzemVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemAVControlPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemAVControlPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemAVControlPar::insertRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemAVControlPar::updateRec(
			WzemAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWzemVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWzemMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWzemVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemAVControlPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemAVControlPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemAVControlPar::updateRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemAVControlPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemAVControlPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemAVControlPar::loadRecByRef(
			ubigint ref
			, WzemAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemAVControlPar WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemAVControlPar::loadRefByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWzemAVControlPar WHERE ixWzemVControl = " + to_string(ixWzemVControl) + " AND x1RefWzemMUser = " + to_string(x1RefWzemMUser) + " AND Par = '" + Par + "'", ref);
};

bool MyTblWzemAVControlPar::loadValByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWzemAVControlPar WHERE ixWzemVControl = " + to_string(ixWzemVControl) + " AND x1RefWzemMUser = " + to_string(x1RefWzemMUser) + " AND Par = '" + Par + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemAVControlPar
 ******************************************************************************/

PgTblWzemAVControlPar::PgTblWzemAVControlPar() :
			TblWzemAVControlPar()
			, PgTable()
		{
};

PgTblWzemAVControlPar::~PgTblWzemAVControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemAVControlPar::initStatements() {
	createStatement("TblWzemAVControlPar_insertRec", "INSERT INTO TblWzemAVControlPar (ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWzemAVControlPar_updateRec", "UPDATE TblWzemAVControlPar SET ixWzemVControl = $1, x1RefWzemMUser = $2, x2IxWzemVLocale = $3, Par = $4, Val = $5 WHERE ref = $6", 6);
	createStatement("TblWzemAVControlPar_removeRecByRef", "DELETE FROM TblWzemAVControlPar WHERE ref = $1", 1);

	createStatement("TblWzemAVControlPar_loadRecByRef", "SELECT ref, ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val FROM TblWzemAVControlPar WHERE ref = $1", 1);
	createStatement("TblWzemAVControlPar_loadRefByCtlUsrPar", "SELECT ref FROM TblWzemAVControlPar WHERE ixWzemVControl = $1 AND x1RefWzemMUser = $2 AND Par = $3", 3);
	createStatement("TblWzemAVControlPar_loadValByCtlUsrPar", "SELECT Val FROM TblWzemAVControlPar WHERE ixWzemVControl = $1 AND x1RefWzemMUser = $2 AND Par = $3", 3);
};

bool PgTblWzemAVControlPar::loadRec(
			PGresult* res
			, WzemAVControlPar** rec
		) {
	char* ptr;

	WzemAVControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemAVControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwzemvcontrol"),
			PQfnumber(res, "x1refwzemmuser"),
			PQfnumber(res, "x2ixwzemvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixWzemVControl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWzemMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxWzemVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Par.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemAVControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemAVControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwzemvcontrol"),
			PQfnumber(res, "x1refwzemmuser"),
			PQfnumber(res, "x2ixwzemvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WzemAVControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixWzemVControl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWzemMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxWzemVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Par.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemAVControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemAVControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVControlPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWzemAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzemAVControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVControlPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVControlPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemAVControlPar::insertRec(
			WzemAVControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixWzemVControl = htonl(rec->ixWzemVControl);
	ubigint _x1RefWzemMUser = htonl64(rec->x1RefWzemMUser);
	uint _x2IxWzemVLocale = htonl(rec->x2IxWzemVLocale);

	const char* vals[] = {
		(char*) &_ixWzemVControl,
		(char*) &_x1RefWzemMUser,
		(char*) &_x2IxWzemVLocale,
		rec->Par.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemAVControlPar_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemAVControlPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemAVControlPar::insertRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemAVControlPar::updateRec(
			WzemAVControlPar* rec
		) {
	PGresult* res;

	uint _ixWzemVControl = htonl(rec->ixWzemVControl);
	ubigint _x1RefWzemMUser = htonl64(rec->x1RefWzemMUser);
	uint _x2IxWzemVLocale = htonl(rec->x2IxWzemVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixWzemVControl,
		(char*) &_x1RefWzemMUser,
		(char*) &_x2IxWzemVLocale,
		rec->Par.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemAVControlPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAVControlPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemAVControlPar::updateRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemAVControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemAVControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemAVControlPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemAVControlPar::loadRecByRef(
			ubigint ref
			, WzemAVControlPar** rec
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

	return loadRecByStmt("TblWzemAVControlPar_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemAVControlPar::loadRefByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, ubigint& ref
		) {
	uint _ixWzemVControl = htonl(ixWzemVControl);
	ubigint _x1RefWzemMUser = htonl64(x1RefWzemMUser);

	const char* vals[] = {
		(char*) &_ixWzemVControl,
		(char*) &_x1RefWzemMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadRefByStmt("TblWzemAVControlPar_loadRefByCtlUsrPar", 3, vals, l, f, ref);
};

bool PgTblWzemAVControlPar::loadValByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, string& Val
		) {
	uint _ixWzemVControl = htonl(ixWzemVControl);
	ubigint _x1RefWzemMUser = htonl64(x1RefWzemMUser);

	const char* vals[] = {
		(char*) &_ixWzemVControl,
		(char*) &_x1RefWzemMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadStringByStmt("TblWzemAVControlPar_loadValByCtlUsrPar", 3, vals, l, f, Val);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemAVControlPar
 ******************************************************************************/

LiteTblWzemAVControlPar::LiteTblWzemAVControlPar() :
			TblWzemAVControlPar()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRefByCtlUsrPar = NULL;
	stmtLoadValByCtlUsrPar = NULL;
};

LiteTblWzemAVControlPar::~LiteTblWzemAVControlPar() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRefByCtlUsrPar) sqlite3_finalize(stmtLoadRefByCtlUsrPar);
	if (stmtLoadValByCtlUsrPar) sqlite3_finalize(stmtLoadValByCtlUsrPar);
};

void LiteTblWzemAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemAVControlPar (ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val) VALUES (?1,?2,?3,?4,?5)");
	stmtUpdateRec = createStatement("UPDATE TblWzemAVControlPar SET ixWzemVControl = ?1, x1RefWzemMUser = ?2, x2IxWzemVLocale = ?3, Par = ?4, Val = ?5 WHERE ref = ?6");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemAVControlPar WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, ixWzemVControl, x1RefWzemMUser, x2IxWzemVLocale, Par, Val FROM TblWzemAVControlPar WHERE ref = ?1");
	stmtLoadRefByCtlUsrPar = createStatement("SELECT ref FROM TblWzemAVControlPar WHERE ixWzemVControl = ?1 AND x1RefWzemMUser = ?2 AND Par = ?3");
	stmtLoadValByCtlUsrPar = createStatement("SELECT Val FROM TblWzemAVControlPar WHERE ixWzemVControl = ?1 AND x1RefWzemMUser = ?2 AND Par = ?3");
};

bool LiteTblWzemAVControlPar::loadRec(
			sqlite3_stmt* stmt
			, WzemAVControlPar** rec
		) {
	int res;

	WzemAVControlPar* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemAVControlPar();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->ixWzemVControl = sqlite3_column_int(stmt, 1);
		_rec->x1RefWzemMUser = sqlite3_column_int64(stmt, 2);
		_rec->x2IxWzemVLocale = sqlite3_column_int(stmt, 3);
		_rec->Par.assign((const char*) sqlite3_column_text(stmt, 4));
		_rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

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

ubigint LiteTblWzemAVControlPar::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	int res; ubigint numread = 0;

	WzemAVControlPar* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemAVControlPar();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->ixWzemVControl = sqlite3_column_int(stmt, 1);
		rec->x1RefWzemMUser = sqlite3_column_int64(stmt, 2);
		rec->x2IxWzemVLocale = sqlite3_column_int(stmt, 3);
		rec->Par.assign((const char*) sqlite3_column_text(stmt, 4));
		rec->Val.assign((const char*) sqlite3_column_text(stmt, 5));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemAVControlPar::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemAVControlPar** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WzemAVControlPar** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAVControlPar::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemAVControlPar& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemAVControlPar::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemAVControlPar::insertRec(
			WzemAVControlPar* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->ixWzemVControl);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->x1RefWzemMUser);
	sqlite3_bind_int(stmtInsertRec, 3, rec->x2IxWzemVLocale);
	sqlite3_bind_text(stmtInsertRec, 4, rec->Par.c_str(), rec->Par.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVControlPar::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemAVControlPar::insertRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemAVControlPar::updateRec(
			WzemAVControlPar* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->ixWzemVControl);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->x1RefWzemMUser);
	sqlite3_bind_int(stmtUpdateRec, 3, rec->x2IxWzemVLocale);
	sqlite3_bind_text(stmtUpdateRec, 4, rec->Par.c_str(), rec->Par.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Val.c_str(), rec->Val.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVControlPar::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemAVControlPar::updateRst(
			ListWzemAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemAVControlPar::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemAVControlPar::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemAVControlPar::loadRecByRef(
			ubigint ref
			, WzemAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemAVControlPar::loadRefByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, ubigint& ref
		) {
	sqlite3_bind_int(stmtLoadRefByCtlUsrPar, 1, ixWzemVControl);
	sqlite3_bind_int64(stmtLoadRefByCtlUsrPar, 2, x1RefWzemMUser);
	sqlite3_bind_text(stmtLoadRefByCtlUsrPar, 3, Par.c_str(), Par.length(), SQLITE_STATIC);

	return loadRefByStmt(stmtLoadRefByCtlUsrPar, ref);
};

bool LiteTblWzemAVControlPar::loadValByCtlUsrPar(
			uint ixWzemVControl
			, ubigint x1RefWzemMUser
			, string Par
			, string& Val
		) {
	sqlite3_bind_int(stmtLoadValByCtlUsrPar, 1, ixWzemVControl);
	sqlite3_bind_int64(stmtLoadValByCtlUsrPar, 2, x1RefWzemMUser);
	sqlite3_bind_text(stmtLoadValByCtlUsrPar, 3, Par.c_str(), Par.length(), SQLITE_STATIC);

	return loadStringByStmt(stmtLoadValByCtlUsrPar, Val);
};

#endif

