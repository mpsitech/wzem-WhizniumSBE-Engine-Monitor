/**
	* \file WzemMNode.cpp
	* database access for table TblWzemMNode (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemMNode.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMNode
 ******************************************************************************/

WzemMNode::WzemMNode(
			const ubigint ref
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const usmallint Port
			, const utinyint Opprcn
		) {

	this->ref = ref;
	this->x1Startu = x1Startu;
	this->x1Stopu = x1Stopu;
	this->refWzemMPeriod = refWzemMPeriod;
	this->xnref = xnref;
	this->Ip = Ip;
	this->Port = Port;
	this->Opprcn = Opprcn;
};

bool WzemMNode::operator==(
			const WzemMNode& comp
		) {
	return false;
};

bool WzemMNode::operator!=(
			const WzemMNode& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMNode
 ******************************************************************************/

ListWzemMNode::ListWzemMNode() {
};

ListWzemMNode::ListWzemMNode(
			const ListWzemMNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMNode(*(src.nodes[i]));
};

ListWzemMNode::~ListWzemMNode() {
	clear();
};

void ListWzemMNode::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMNode::size() const {
	return(nodes.size());
};

void ListWzemMNode::append(
			WzemMNode* rec
		) {
	nodes.push_back(rec);
};

WzemMNode* ListWzemMNode::operator[](
			const uint ix
		) {
	WzemMNode* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMNode& ListWzemMNode::operator=(
			const ListWzemMNode& src
		) {
	WzemMNode* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMNode(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMNode::operator==(
			const ListWzemMNode& comp
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

bool ListWzemMNode::operator!=(
			const ListWzemMNode& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMNode
 ******************************************************************************/

TblWzemMNode::TblWzemMNode() {
};

TblWzemMNode::~TblWzemMNode() {
};

bool TblWzemMNode::loadRecBySQL(
			const string& sqlstr
			, WzemMNode** rec
		) {
	return false;
};

ubigint TblWzemMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMNode& rst
		) {
	return 0;
};

ubigint TblWzemMNode::insertRec(
			WzemMNode* rec
		) {
	return 0;
};

ubigint TblWzemMNode::insertNewRec(
			WzemMNode** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const usmallint Port
			, const utinyint Opprcn
		) {
	ubigint retval = 0;
	WzemMNode* _rec = NULL;

	_rec = new WzemMNode(0, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMNode::appendNewRecToRst(
			ListWzemMNode& rst
			, WzemMNode** rec
			, const double x1Startu
			, const double x1Stopu
			, const ubigint refWzemMPeriod
			, const ubigint xnref
			, const string Ip
			, const usmallint Port
			, const utinyint Opprcn
		) {
	ubigint retval = 0;
	WzemMNode* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMNode::insertRst(
			ListWzemMNode& rst
			, bool transact
		) {
};

void TblWzemMNode::updateRec(
			WzemMNode* rec
		) {
};

void TblWzemMNode::updateRst(
			ListWzemMNode& rst
			, bool transact
		) {
};

void TblWzemMNode::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMNode::loadRecByRef(
			ubigint ref
			, WzemMNode** rec
		) {
	return false;
};

ubigint TblWzemMNode::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMNode& rst
		) {
	return 0;
};

bool TblWzemMNode::loadXnrByRef(
			ubigint ref
			, string& xnref
		) {
	return false;
};

ubigint TblWzemMNode::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMNode& rst
		) {
	ubigint numload = 0;
	WzemMNode* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMNode
 ******************************************************************************/

MyTblWzemMNode::MyTblWzemMNode() :
			TblWzemMNode()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMNode::~MyTblWzemMNode() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMNode::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMNode (x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMNode SET x1Startu = ?, x1Stopu = ?, refWzemMPeriod = ?, xnref = ?, Ip = ?, Port = ?, Opprcn = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMNode WHERE ref = ?", false);
};

bool MyTblWzemMNode::loadRecBySQL(
			const string& sqlstr
			, WzemMNode** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMNode* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMNode::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMNode::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMNode();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startu = atof((char*) dbrow[1]); else _rec->x1Startu = 0.0;
		if (dbrow[2]) _rec->x1Stopu = atof((char*) dbrow[2]); else _rec->x1Stopu = 0.0;
		if (dbrow[3]) _rec->refWzemMPeriod = atoll((char*) dbrow[3]); else _rec->refWzemMPeriod = 0;
		if (dbrow[4]) _rec->xnref = atoll((char*) dbrow[4]); else _rec->xnref = 0;
		if (dbrow[5]) _rec->Ip.assign(dbrow[5], dblengths[5]); else _rec->Ip = "";
		if (dbrow[6]) _rec->Port = atoi((char*) dbrow[6]); else _rec->Port = 0;
		if (dbrow[7]) _rec->Opprcn = atoi((char*) dbrow[7]); else _rec->Opprcn = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMNode& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMNode* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMNode::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMNode::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMNode();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startu = atof((char*) dbrow[1]); else rec->x1Startu = 0.0;
			if (dbrow[2]) rec->x1Stopu = atof((char*) dbrow[2]); else rec->x1Stopu = 0.0;
			if (dbrow[3]) rec->refWzemMPeriod = atoll((char*) dbrow[3]); else rec->refWzemMPeriod = 0;
			if (dbrow[4]) rec->xnref = atoll((char*) dbrow[4]); else rec->xnref = 0;
			if (dbrow[5]) rec->Ip.assign(dbrow[5], dblengths[5]); else rec->Ip = "";
			if (dbrow[6]) rec->Port = atoi((char*) dbrow[6]); else rec->Port = 0;
			if (dbrow[7]) rec->Opprcn = atoi((char*) dbrow[7]); else rec->Opprcn = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMNode::insertRec(
			WzemMNode* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMPeriod,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->xnref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Port,&(l[5]),&(n[5]),&(e[5])),
		bindUtinyint(&rec->Opprcn,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMNode::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMNode::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMNode::insertRst(
			ListWzemMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMNode::updateRec(
			WzemMNode* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1Startu,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1Stopu,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMPeriod,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->xnref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Port,&(l[5]),&(n[5]),&(e[5])),
		bindUtinyint(&rec->Opprcn,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMNode::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMNode::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMNode::updateRst(
			ListWzemMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMNode::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMNode::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMNode::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMNode::loadRecByRef(
			ubigint ref
			, WzemMNode** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMNode WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWzemMNode::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMNode& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn FROM TblWzemMNode WHERE refWzemMPeriod = " + to_string(refWzemMPeriod) + "", append, rst);
};

bool MyTblWzemMNode::loadXnrByRef(
			ubigint ref
			, string& xnref
		) {
	return loadStringBySQL("SELECT xnref FROM TblWzemMNode WHERE ref = " + to_string(ref) + "", xnref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMNode
 ******************************************************************************/

PgTblWzemMNode::PgTblWzemMNode() :
			TblWzemMNode()
			, PgTable()
		{
};

PgTblWzemMNode::~PgTblWzemMNode() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMNode::initStatements() {
	createStatement("TblWzemMNode_insertRec", "INSERT INTO TblWzemMNode (x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWzemMNode_updateRec", "UPDATE TblWzemMNode SET x1Startu = $1, x1Stopu = $2, refWzemMPeriod = $3, xnref = $4, Ip = $5, Port = $6, Opprcn = $7 WHERE ref = $8", 8);
	createStatement("TblWzemMNode_removeRecByRef", "DELETE FROM TblWzemMNode WHERE ref = $1", 1);

	createStatement("TblWzemMNode_loadRecByRef", "SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn FROM TblWzemMNode WHERE ref = $1", 1);
	createStatement("TblWzemMNode_loadRstByPrd", "SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn FROM TblWzemMNode WHERE refWzemMPeriod = $1", 1);
	createStatement("TblWzemMNode_loadXnrByRef", "SELECT xnref FROM TblWzemMNode WHERE ref = $1", 1);
};

bool PgTblWzemMNode::loadRec(
			PGresult* res
			, WzemMNode** rec
		) {
	char* ptr;

	WzemMNode* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMNode();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "xnref"),
			PQfnumber(res, "ip"),
			PQfnumber(res, "port"),
			PQfnumber(res, "opprcn")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMPeriod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->xnref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Port = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Opprcn = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMNode::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMNode& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMNode* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startu"),
			PQfnumber(res, "x1stopu"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "xnref"),
			PQfnumber(res, "ip"),
			PQfnumber(res, "port"),
			PQfnumber(res, "opprcn")
		};

		while (numread < numrow) {
			rec = new WzemMNode();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMPeriod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->xnref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Port = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Opprcn = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMNode::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMNode** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMNode::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMNode::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMNode& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMNode::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMNode::loadRecBySQL(
			const string& sqlstr
			, WzemMNode** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMNode::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMNode& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMNode::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMNode::insertRec(
			WzemMNode* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _xnref = htonl64(rec->xnref);
	usmallint _Port = htons(rec->Port);
	usmallint _Opprcn = htons(rec->Opprcn);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMPeriod,
		(char*) &_xnref,
		rec->Ip.c_str(),
		(char*) &_Port,
		(char*) &_Opprcn
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		sizeof(usmallint)
	};
	const int f[] = {0, 0, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMNode_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMNode::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMNode::insertRst(
			ListWzemMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMNode::updateRec(
			WzemMNode* rec
		) {
	PGresult* res;

	string _x1Startu = to_string(rec->x1Startu);
	string _x1Stopu = to_string(rec->x1Stopu);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _xnref = htonl64(rec->xnref);
	usmallint _Port = htons(rec->Port);
	usmallint _Opprcn = htons(rec->Opprcn);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1Startu.c_str(),
		_x1Stopu.c_str(),
		(char*) &_refWzemMPeriod,
		(char*) &_xnref,
		rec->Ip.c_str(),
		(char*) &_Port,
		(char*) &_Opprcn,
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWzemMNode_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMNode::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMNode::updateRst(
			ListWzemMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMNode::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMNode_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMNode::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMNode::loadRecByRef(
			ubigint ref
			, WzemMNode** rec
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

	return loadRecByStmt("TblWzemMNode_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWzemMNode::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMNode& rst
		) {
	ubigint _refWzemMPeriod = htonl64(refWzemMPeriod);

	const char* vals[] = {
		(char*) &_refWzemMPeriod
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMNode_loadRstByPrd", 1, vals, l, f, append, rst);
};

bool PgTblWzemMNode::loadXnrByRef(
			ubigint ref
			, string& xnref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWzemMNode_loadXnrByRef", 1, vals, l, f, xnref);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMNode
 ******************************************************************************/

LiteTblWzemMNode::LiteTblWzemMNode() :
			TblWzemMNode()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRstByPrd = NULL;
	stmtLoadXnrByRef = NULL;
};

LiteTblWzemMNode::~LiteTblWzemMNode() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRstByPrd) sqlite3_finalize(stmtLoadRstByPrd);
	if (stmtLoadXnrByRef) sqlite3_finalize(stmtLoadXnrByRef);
};

void LiteTblWzemMNode::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMNode (x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn) VALUES (?1,?2,?3,?4,?5,?6,?7)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMNode SET x1Startu = ?1, x1Stopu = ?2, refWzemMPeriod = ?3, xnref = ?4, Ip = ?5, Port = ?6, Opprcn = ?7 WHERE ref = ?8");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMNode WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn FROM TblWzemMNode WHERE ref = ?1");
	stmtLoadRstByPrd = createStatement("SELECT ref, x1Startu, x1Stopu, refWzemMPeriod, xnref, Ip, Port, Opprcn FROM TblWzemMNode WHERE refWzemMPeriod = ?1");
	stmtLoadXnrByRef = createStatement("SELECT xnref FROM TblWzemMNode WHERE ref = ?1");
};

bool LiteTblWzemMNode::loadRec(
			sqlite3_stmt* stmt
			, WzemMNode** rec
		) {
	int res;

	WzemMNode* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMNode();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->x1Startu = sqlite3_column_double(stmt, 1);
		_rec->x1Stopu = sqlite3_column_double(stmt, 2);
		_rec->refWzemMPeriod = sqlite3_column_int64(stmt, 3);
		_rec->xnref = sqlite3_column_int64(stmt, 4);
		_rec->Ip.assign((const char*) sqlite3_column_text(stmt, 5));
		_rec->Port = sqlite3_column_int(stmt, 6);
		_rec->Opprcn = sqlite3_column_int(stmt, 7);

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

ubigint LiteTblWzemMNode::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMNode& rst
		) {
	int res; ubigint numread = 0;

	WzemMNode* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMNode();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->x1Startu = sqlite3_column_double(stmt, 1);
		rec->x1Stopu = sqlite3_column_double(stmt, 2);
		rec->refWzemMPeriod = sqlite3_column_int64(stmt, 3);
		rec->xnref = sqlite3_column_int64(stmt, 4);
		rec->Ip.assign((const char*) sqlite3_column_text(stmt, 5));
		rec->Port = sqlite3_column_int(stmt, 6);
		rec->Opprcn = sqlite3_column_int(stmt, 7);

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMNode::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMNode** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMNode::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMNode& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMNode::loadRecBySQL(
			const string& sqlstr
			, WzemMNode** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMNode::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMNode& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMNode::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMNode::insertRec(
			WzemMNode* rec
		) {
	sqlite3_bind_double(stmtInsertRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtInsertRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->xnref);
	sqlite3_bind_text(stmtInsertRec, 5, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtInsertRec, 6, rec->Port);
	sqlite3_bind_int(stmtInsertRec, 7, rec->Opprcn);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMNode::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMNode::insertRst(
			ListWzemMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMNode::updateRec(
			WzemMNode* rec
		) {
	sqlite3_bind_double(stmtUpdateRec, 1, rec->x1Startu);
	sqlite3_bind_double(stmtUpdateRec, 2, rec->x1Stopu);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->xnref);
	sqlite3_bind_text(stmtUpdateRec, 5, rec->Ip.c_str(), rec->Ip.length(), SQLITE_STATIC);
	sqlite3_bind_int(stmtUpdateRec, 6, rec->Port);
	sqlite3_bind_int(stmtUpdateRec, 7, rec->Opprcn);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMNode::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMNode::updateRst(
			ListWzemMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMNode::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMNode::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMNode::loadRecByRef(
			ubigint ref
			, WzemMNode** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

ubigint LiteTblWzemMNode::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMNode& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrd, 1, refWzemMPeriod);

	return loadRstByStmt(stmtLoadRstByPrd, append, rst);
};

bool LiteTblWzemMNode::loadXnrByRef(
			ubigint ref
			, string& xnref
		) {
	sqlite3_bind_int64(stmtLoadXnrByRef, 1, ref);

	return loadStringByStmt(stmtLoadXnrByRef, xnref);
};

#endif

