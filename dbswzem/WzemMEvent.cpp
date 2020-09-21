/**
	* \file WzemMEvent.cpp
	* database access for table TblWzemMEvent (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#include "WzemMEvent.h"

#include "WzemMEvent_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WzemMEvent
 ******************************************************************************/

WzemMEvent::WzemMEvent(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWzemCEvent
			, const ubigint refWzemMPeriod
			, const ubigint refWzemMDpch
			, const double startu
			, const ubigint refWzemMCall
			, const ubigint refWzemMClstn
			, const ubigint refWzemMJob
			, const ubigint refWzemMNode
			, const ubigint refWzemMOp
			, const ubigint refWzemMPreset
			, const string Cmd
			, const string Filename
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWzemCEvent = refWzemCEvent;
	this->refWzemMPeriod = refWzemMPeriod;
	this->refWzemMDpch = refWzemMDpch;
	this->startu = startu;
	this->refWzemMCall = refWzemMCall;
	this->refWzemMClstn = refWzemMClstn;
	this->refWzemMJob = refWzemMJob;
	this->refWzemMNode = refWzemMNode;
	this->refWzemMOp = refWzemMOp;
	this->refWzemMPreset = refWzemMPreset;
	this->Cmd = Cmd;
	this->Filename = Filename;
	this->srefIxVFeatgroup = srefIxVFeatgroup;
	this->srefIxVMethod = srefIxVMethod;
	this->xsref = xsref;
};

bool WzemMEvent::operator==(
			const WzemMEvent& comp
		) {
	return false;
};

bool WzemMEvent::operator!=(
			const WzemMEvent& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWzemMEvent
 ******************************************************************************/

ListWzemMEvent::ListWzemMEvent() {
};

ListWzemMEvent::ListWzemMEvent(
			const ListWzemMEvent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzemMEvent(*(src.nodes[i]));
};

ListWzemMEvent::~ListWzemMEvent() {
	clear();
};

void ListWzemMEvent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWzemMEvent::size() const {
	return(nodes.size());
};

void ListWzemMEvent::append(
			WzemMEvent* rec
		) {
	nodes.push_back(rec);
};

WzemMEvent* ListWzemMEvent::operator[](
			const uint ix
		) {
	WzemMEvent* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWzemMEvent& ListWzemMEvent::operator=(
			const ListWzemMEvent& src
		) {
	WzemMEvent* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WzemMEvent(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWzemMEvent::operator==(
			const ListWzemMEvent& comp
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

bool ListWzemMEvent::operator!=(
			const ListWzemMEvent& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWzemMEvent
 ******************************************************************************/

TblWzemMEvent::TblWzemMEvent() {
};

TblWzemMEvent::~TblWzemMEvent() {
};

bool TblWzemMEvent::loadRecBySQL(
			const string& sqlstr
			, WzemMEvent** rec
		) {
	return false;
};

ubigint TblWzemMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMEvent& rst
		) {
	return 0;
};

ubigint TblWzemMEvent::insertRec(
			WzemMEvent* rec
		) {
	return 0;
};

ubigint TblWzemMEvent::insertNewRec(
			WzemMEvent** rec
			, const uint ixVBasetype
			, const ubigint refWzemCEvent
			, const ubigint refWzemMPeriod
			, const ubigint refWzemMDpch
			, const double startu
			, const ubigint refWzemMCall
			, const ubigint refWzemMClstn
			, const ubigint refWzemMJob
			, const ubigint refWzemMNode
			, const ubigint refWzemMOp
			, const ubigint refWzemMPreset
			, const string Cmd
			, const string Filename
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {
	ubigint retval = 0;
	WzemMEvent* _rec = NULL;

	_rec = new WzemMEvent(0, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWzemMEvent::appendNewRecToRst(
			ListWzemMEvent& rst
			, WzemMEvent** rec
			, const uint ixVBasetype
			, const ubigint refWzemCEvent
			, const ubigint refWzemMPeriod
			, const ubigint refWzemMDpch
			, const double startu
			, const ubigint refWzemMCall
			, const ubigint refWzemMClstn
			, const ubigint refWzemMJob
			, const ubigint refWzemMNode
			, const ubigint refWzemMOp
			, const ubigint refWzemMPreset
			, const string Cmd
			, const string Filename
			, const string srefIxVFeatgroup
			, const string srefIxVMethod
			, const string xsref
		) {
	ubigint retval = 0;
	WzemMEvent* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWzemMEvent::insertRst(
			ListWzemMEvent& rst
			, bool transact
		) {
};

void TblWzemMEvent::updateRec(
			WzemMEvent* rec
		) {
};

void TblWzemMEvent::updateRst(
			ListWzemMEvent& rst
			, bool transact
		) {
};

void TblWzemMEvent::removeRecByRef(
			ubigint ref
		) {
};

bool TblWzemMEvent::loadRecByRef(
			ubigint ref
			, WzemMEvent** rec
		) {
	return false;
};

bool TblWzemMEvent::loadRecByDch(
			ubigint refWzemMDpch
			, WzemMEvent** rec
		) {
	return false;
};

ubigint TblWzemMEvent::loadRefsByClu(
			ubigint refWzemCEvent
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWzemMEvent::loadRstByClu(
			ubigint refWzemCEvent
			, const bool append
			, ListWzemMEvent& rst
		) {
	return 0;
};

ubigint TblWzemMEvent::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMEvent& rst
		) {
	return 0;
};

ubigint TblWzemMEvent::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWzemMEvent& rst
		) {
	ubigint numload = 0;
	WzemMEvent* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWzemMEvent
 ******************************************************************************/

MyTblWzemMEvent::MyTblWzemMEvent() :
			TblWzemMEvent()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWzemMEvent::~MyTblWzemMEvent() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWzemMEvent::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMEvent (ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWzemMEvent SET ixVBasetype = ?, refWzemCEvent = ?, refWzemMPeriod = ?, refWzemMDpch = ?, startu = ?, refWzemMCall = ?, refWzemMClstn = ?, refWzemMJob = ?, refWzemMNode = ?, refWzemMOp = ?, refWzemMPreset = ?, Cmd = ?, Filename = ?, srefIxVFeatgroup = ?, srefIxVMethod = ?, xsref = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMEvent WHERE ref = ?", false);
};

bool MyTblWzemMEvent::loadRecBySQL(
			const string& sqlstr
			, WzemMEvent** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WzemMEvent* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMEvent::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMEvent::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WzemMEvent();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWzemCEvent = atoll((char*) dbrow[2]); else _rec->refWzemCEvent = 0;
		if (dbrow[3]) _rec->refWzemMPeriod = atoll((char*) dbrow[3]); else _rec->refWzemMPeriod = 0;
		if (dbrow[4]) _rec->refWzemMDpch = atoll((char*) dbrow[4]); else _rec->refWzemMDpch = 0;
		if (dbrow[5]) _rec->startu = atof((char*) dbrow[5]); else _rec->startu = 0.0;
		if (dbrow[6]) _rec->refWzemMCall = atoll((char*) dbrow[6]); else _rec->refWzemMCall = 0;
		if (dbrow[7]) _rec->refWzemMClstn = atoll((char*) dbrow[7]); else _rec->refWzemMClstn = 0;
		if (dbrow[8]) _rec->refWzemMJob = atoll((char*) dbrow[8]); else _rec->refWzemMJob = 0;
		if (dbrow[9]) _rec->refWzemMNode = atoll((char*) dbrow[9]); else _rec->refWzemMNode = 0;
		if (dbrow[10]) _rec->refWzemMOp = atoll((char*) dbrow[10]); else _rec->refWzemMOp = 0;
		if (dbrow[11]) _rec->refWzemMPreset = atoll((char*) dbrow[11]); else _rec->refWzemMPreset = 0;
		if (dbrow[12]) _rec->Cmd.assign(dbrow[12], dblengths[12]); else _rec->Cmd = "";
		if (dbrow[13]) _rec->Filename.assign(dbrow[13], dblengths[13]); else _rec->Filename = "";
		if (dbrow[14]) _rec->srefIxVFeatgroup.assign(dbrow[14], dblengths[14]); else _rec->srefIxVFeatgroup = "";
		if (dbrow[15]) _rec->srefIxVMethod.assign(dbrow[15], dblengths[15]); else _rec->srefIxVMethod = "";
		if (dbrow[16]) _rec->xsref.assign(dbrow[16], dblengths[16]); else _rec->xsref = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWzemMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMEvent& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WzemMEvent* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWzemMEvent::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWzemMEvent::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WzemMEvent();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWzemCEvent = atoll((char*) dbrow[2]); else rec->refWzemCEvent = 0;
			if (dbrow[3]) rec->refWzemMPeriod = atoll((char*) dbrow[3]); else rec->refWzemMPeriod = 0;
			if (dbrow[4]) rec->refWzemMDpch = atoll((char*) dbrow[4]); else rec->refWzemMDpch = 0;
			if (dbrow[5]) rec->startu = atof((char*) dbrow[5]); else rec->startu = 0.0;
			if (dbrow[6]) rec->refWzemMCall = atoll((char*) dbrow[6]); else rec->refWzemMCall = 0;
			if (dbrow[7]) rec->refWzemMClstn = atoll((char*) dbrow[7]); else rec->refWzemMClstn = 0;
			if (dbrow[8]) rec->refWzemMJob = atoll((char*) dbrow[8]); else rec->refWzemMJob = 0;
			if (dbrow[9]) rec->refWzemMNode = atoll((char*) dbrow[9]); else rec->refWzemMNode = 0;
			if (dbrow[10]) rec->refWzemMOp = atoll((char*) dbrow[10]); else rec->refWzemMOp = 0;
			if (dbrow[11]) rec->refWzemMPreset = atoll((char*) dbrow[11]); else rec->refWzemMPreset = 0;
			if (dbrow[12]) rec->Cmd.assign(dbrow[12], dblengths[12]); else rec->Cmd = "";
			if (dbrow[13]) rec->Filename.assign(dbrow[13], dblengths[13]); else rec->Filename = "";
			if (dbrow[14]) rec->srefIxVFeatgroup.assign(dbrow[14], dblengths[14]); else rec->srefIxVFeatgroup = "";
			if (dbrow[15]) rec->srefIxVMethod.assign(dbrow[15], dblengths[15]); else rec->srefIxVMethod = "";
			if (dbrow[16]) rec->xsref.assign(dbrow[16], dblengths[16]); else rec->xsref = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWzemMEvent::insertRec(
			WzemMEvent* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	l[11] = rec->Cmd.length();
	l[12] = rec->Filename.length();
	l[13] = rec->srefIxVFeatgroup.length();
	l[14] = rec->srefIxVMethod.length();
	l[15] = rec->xsref.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzemCEvent,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMPeriod,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMDpch,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->startu,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWzemMCall,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWzemMClstn,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWzemMJob,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWzemMNode,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWzemMOp,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWzemMPreset,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Cmd.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->srefIxVFeatgroup.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->srefIxVMethod.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWzemMEvent::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWzemMEvent::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWzemMEvent::insertRst(
			ListWzemMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWzemMEvent::updateRec(
			WzemMEvent* rec
		) {
	unsigned long l[17]; my_bool n[17]; my_bool e[17];

	l[11] = rec->Cmd.length();
	l[12] = rec->Filename.length();
	l[13] = rec->srefIxVFeatgroup.length();
	l[14] = rec->srefIxVMethod.length();
	l[15] = rec->xsref.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWzemCEvent,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWzemMPeriod,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWzemMDpch,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->startu,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWzemMCall,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWzemMClstn,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWzemMJob,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWzemMNode,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWzemMOp,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWzemMPreset,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Cmd.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->srefIxVFeatgroup.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->srefIxVMethod.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->xsref.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindUbigint(&rec->ref,&(l[16]),&(n[16]),&(e[16]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWzemMEvent::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWzemMEvent::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWzemMEvent::updateRst(
			ListWzemMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWzemMEvent::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWzemMEvent::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWzemMEvent::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWzemMEvent::loadRecByRef(
			ubigint ref
			, WzemMEvent** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWzemMEvent WHERE ref = " + to_string(ref), rec);
};

bool MyTblWzemMEvent::loadRecByDch(
			ubigint refWzemMDpch
			, WzemMEvent** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemMDpch = " + to_string(refWzemMDpch) + "", rec);
};

ubigint MyTblWzemMEvent::loadRefsByClu(
			ubigint refWzemCEvent
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWzemMEvent WHERE refWzemCEvent = " + to_string(refWzemCEvent) + "", append, refs);
};

ubigint MyTblWzemMEvent::loadRstByClu(
			ubigint refWzemCEvent
			, const bool append
			, ListWzemMEvent& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemCEvent = " + to_string(refWzemCEvent) + "", append, rst);
};

ubigint MyTblWzemMEvent::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMEvent& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemMPeriod = " + to_string(refWzemMPeriod) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWzemMEvent
 ******************************************************************************/

PgTblWzemMEvent::PgTblWzemMEvent() :
			TblWzemMEvent()
			, PgTable()
		{
};

PgTblWzemMEvent::~PgTblWzemMEvent() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWzemMEvent::initStatements() {
	createStatement("TblWzemMEvent_insertRec", "INSERT INTO TblWzemMEvent (ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16) RETURNING ref", 16);
	createStatement("TblWzemMEvent_updateRec", "UPDATE TblWzemMEvent SET ixVBasetype = $1, refWzemCEvent = $2, refWzemMPeriod = $3, refWzemMDpch = $4, startu = $5, refWzemMCall = $6, refWzemMClstn = $7, refWzemMJob = $8, refWzemMNode = $9, refWzemMOp = $10, refWzemMPreset = $11, Cmd = $12, Filename = $13, srefIxVFeatgroup = $14, srefIxVMethod = $15, xsref = $16 WHERE ref = $17", 17);
	createStatement("TblWzemMEvent_removeRecByRef", "DELETE FROM TblWzemMEvent WHERE ref = $1", 1);

	createStatement("TblWzemMEvent_loadRecByRef", "SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE ref = $1", 1);
	createStatement("TblWzemMEvent_loadRecByDch", "SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemMDpch = $1", 1);
	createStatement("TblWzemMEvent_loadRefsByClu", "SELECT ref FROM TblWzemMEvent WHERE refWzemCEvent = $1", 1);
	createStatement("TblWzemMEvent_loadRstByClu", "SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemCEvent = $1", 1);
	createStatement("TblWzemMEvent_loadRstByPrd", "SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemMPeriod = $1", 1);
};

bool PgTblWzemMEvent::loadRec(
			PGresult* res
			, WzemMEvent** rec
		) {
	char* ptr;

	WzemMEvent* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WzemMEvent();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwzemcevent"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "refwzemmdpch"),
			PQfnumber(res, "startu"),
			PQfnumber(res, "refwzemmcall"),
			PQfnumber(res, "refwzemmclstn"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "refwzemmnode"),
			PQfnumber(res, "refwzemmop"),
			PQfnumber(res, "refwzemmpreset"),
			PQfnumber(res, "cmd"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "srefixvfeatgroup"),
			PQfnumber(res, "srefixvmethod"),
			PQfnumber(res, "xsref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWzemCEvent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWzemMPeriod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWzemMDpch = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->startu = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWzemMCall = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWzemMClstn = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWzemMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWzemMNode = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWzemMOp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWzemMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Cmd.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Filename.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->srefIxVFeatgroup.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->srefIxVMethod.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->xsref.assign(ptr, PQgetlength(res, 0, fnum[16]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWzemMEvent::loadRst(
			PGresult* res
			, const bool append
			, ListWzemMEvent& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WzemMEvent* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwzemcevent"),
			PQfnumber(res, "refwzemmperiod"),
			PQfnumber(res, "refwzemmdpch"),
			PQfnumber(res, "startu"),
			PQfnumber(res, "refwzemmcall"),
			PQfnumber(res, "refwzemmclstn"),
			PQfnumber(res, "refwzemmjob"),
			PQfnumber(res, "refwzemmnode"),
			PQfnumber(res, "refwzemmop"),
			PQfnumber(res, "refwzemmpreset"),
			PQfnumber(res, "cmd"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "srefixvfeatgroup"),
			PQfnumber(res, "srefixvmethod"),
			PQfnumber(res, "xsref")
		};

		while (numread < numrow) {
			rec = new WzemMEvent();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWzemCEvent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWzemMPeriod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWzemMDpch = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->startu = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWzemMCall = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWzemMClstn = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWzemMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWzemMNode = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWzemMOp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWzemMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Cmd.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Filename.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->srefIxVFeatgroup.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->srefIxVMethod.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->xsref.assign(ptr, PQgetlength(res, numread, fnum[16]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWzemMEvent::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WzemMEvent** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMEvent::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMEvent::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWzemMEvent& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMEvent::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWzemMEvent::loadRecBySQL(
			const string& sqlstr
			, WzemMEvent** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMEvent::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWzemMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMEvent& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMEvent::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWzemMEvent::insertRec(
			WzemMEvent* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWzemCEvent = htonl64(rec->refWzemCEvent);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _refWzemMDpch = htonl64(rec->refWzemMDpch);
	string _startu = to_string(rec->startu);
	ubigint _refWzemMCall = htonl64(rec->refWzemMCall);
	ubigint _refWzemMClstn = htonl64(rec->refWzemMClstn);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _refWzemMNode = htonl64(rec->refWzemMNode);
	ubigint _refWzemMOp = htonl64(rec->refWzemMOp);
	ubigint _refWzemMPreset = htonl64(rec->refWzemMPreset);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWzemCEvent,
		(char*) &_refWzemMPeriod,
		(char*) &_refWzemMDpch,
		_startu.c_str(),
		(char*) &_refWzemMCall,
		(char*) &_refWzemMClstn,
		(char*) &_refWzemMJob,
		(char*) &_refWzemMNode,
		(char*) &_refWzemMOp,
		(char*) &_refWzemMPreset,
		rec->Cmd.c_str(),
		rec->Filename.c_str(),
		rec->srefIxVFeatgroup.c_str(),
		rec->srefIxVMethod.c_str(),
		rec->xsref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWzemMEvent_insertRec", 16, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWzemMEvent::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWzemMEvent::insertRst(
			ListWzemMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWzemMEvent::updateRec(
			WzemMEvent* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWzemCEvent = htonl64(rec->refWzemCEvent);
	ubigint _refWzemMPeriod = htonl64(rec->refWzemMPeriod);
	ubigint _refWzemMDpch = htonl64(rec->refWzemMDpch);
	string _startu = to_string(rec->startu);
	ubigint _refWzemMCall = htonl64(rec->refWzemMCall);
	ubigint _refWzemMClstn = htonl64(rec->refWzemMClstn);
	ubigint _refWzemMJob = htonl64(rec->refWzemMJob);
	ubigint _refWzemMNode = htonl64(rec->refWzemMNode);
	ubigint _refWzemMOp = htonl64(rec->refWzemMOp);
	ubigint _refWzemMPreset = htonl64(rec->refWzemMPreset);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWzemCEvent,
		(char*) &_refWzemMPeriod,
		(char*) &_refWzemMDpch,
		_startu.c_str(),
		(char*) &_refWzemMCall,
		(char*) &_refWzemMClstn,
		(char*) &_refWzemMJob,
		(char*) &_refWzemMNode,
		(char*) &_refWzemMOp,
		(char*) &_refWzemMPreset,
		rec->Cmd.c_str(),
		rec->Filename.c_str(),
		rec->srefIxVFeatgroup.c_str(),
		rec->srefIxVMethod.c_str(),
		rec->xsref.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWzemMEvent_updateRec", 17, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMEvent::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWzemMEvent::updateRst(
			ListWzemMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWzemMEvent::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWzemMEvent_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWzemMEvent::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWzemMEvent::loadRecByRef(
			ubigint ref
			, WzemMEvent** rec
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

	return loadRecByStmt("TblWzemMEvent_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWzemMEvent::loadRecByDch(
			ubigint refWzemMDpch
			, WzemMEvent** rec
		) {
	ubigint _refWzemMDpch = htonl64(refWzemMDpch);

	const char* vals[] = {
		(char*) &_refWzemMDpch
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWzemMEvent_loadRecByDch", 1, vals, l, f, rec);
};

ubigint PgTblWzemMEvent::loadRefsByClu(
			ubigint refWzemCEvent
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWzemCEvent = htonl64(refWzemCEvent);

	const char* vals[] = {
		(char*) &_refWzemCEvent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWzemMEvent_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWzemMEvent::loadRstByClu(
			ubigint refWzemCEvent
			, const bool append
			, ListWzemMEvent& rst
		) {
	ubigint _refWzemCEvent = htonl64(refWzemCEvent);

	const char* vals[] = {
		(char*) &_refWzemCEvent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMEvent_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWzemMEvent::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMEvent& rst
		) {
	ubigint _refWzemMPeriod = htonl64(refWzemMPeriod);

	const char* vals[] = {
		(char*) &_refWzemMPeriod
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWzemMEvent_loadRstByPrd", 1, vals, l, f, append, rst);
};

#endif

#if defined(SBECORE_LITE)
/******************************************************************************
 class LiteTblWzemMEvent
 ******************************************************************************/

LiteTblWzemMEvent::LiteTblWzemMEvent() :
			TblWzemMEvent()
			, LiteTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;

	stmtLoadRecByDch = NULL;
	stmtLoadRefsByClu = NULL;
	stmtLoadRstByClu = NULL;
	stmtLoadRstByPrd = NULL;
};

LiteTblWzemMEvent::~LiteTblWzemMEvent() {
	if (stmtInsertRec) sqlite3_finalize(stmtInsertRec);
	if (stmtUpdateRec) sqlite3_finalize(stmtUpdateRec);
	if (stmtRemoveRecByRef) sqlite3_finalize(stmtRemoveRecByRef);

	if (stmtLoadRecByDch) sqlite3_finalize(stmtLoadRecByDch);
	if (stmtLoadRefsByClu) sqlite3_finalize(stmtLoadRefsByClu);
	if (stmtLoadRstByClu) sqlite3_finalize(stmtLoadRstByClu);
	if (stmtLoadRstByPrd) sqlite3_finalize(stmtLoadRstByPrd);
};

void LiteTblWzemMEvent::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWzemMEvent (ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref) VALUES (?1,?2,?3,?4,?5,?6,?7,?8,?9,?10,?11,?12,?13,?14,?15,?16)");
	stmtUpdateRec = createStatement("UPDATE TblWzemMEvent SET ixVBasetype = ?1, refWzemCEvent = ?2, refWzemMPeriod = ?3, refWzemMDpch = ?4, startu = ?5, refWzemMCall = ?6, refWzemMClstn = ?7, refWzemMJob = ?8, refWzemMNode = ?9, refWzemMOp = ?10, refWzemMPreset = ?11, Cmd = ?12, Filename = ?13, srefIxVFeatgroup = ?14, srefIxVMethod = ?15, xsref = ?16 WHERE ref = ?17");
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWzemMEvent WHERE ref = ?1");

	stmtLoadRecByRef = createStatement("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE ref = ?1");
	stmtLoadRecByDch = createStatement("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemMDpch = ?1");
	stmtLoadRefsByClu = createStatement("SELECT ref FROM TblWzemMEvent WHERE refWzemCEvent = ?1");
	stmtLoadRstByClu = createStatement("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemCEvent = ?1");
	stmtLoadRstByPrd = createStatement("SELECT ref, ixVBasetype, refWzemCEvent, refWzemMPeriod, refWzemMDpch, startu, refWzemMCall, refWzemMClstn, refWzemMJob, refWzemMNode, refWzemMOp, refWzemMPreset, Cmd, Filename, srefIxVFeatgroup, srefIxVMethod, xsref FROM TblWzemMEvent WHERE refWzemMPeriod = ?1");
};

bool LiteTblWzemMEvent::loadRec(
			sqlite3_stmt* stmt
			, WzemMEvent** rec
		) {
	int res;

	WzemMEvent* _rec = NULL;
	bool retval = false;

	res = sqlite3_step(stmt);
	if (res == SQLITE_ROW) {
		_rec = new WzemMEvent();

		_rec->ref = sqlite3_column_int64(stmt, 0);
		_rec->ixVBasetype = sqlite3_column_int(stmt, 1);
		_rec->refWzemCEvent = sqlite3_column_int64(stmt, 2);
		_rec->refWzemMPeriod = sqlite3_column_int64(stmt, 3);
		_rec->refWzemMDpch = sqlite3_column_int64(stmt, 4);
		_rec->startu = sqlite3_column_double(stmt, 5);
		_rec->refWzemMCall = sqlite3_column_int64(stmt, 6);
		_rec->refWzemMClstn = sqlite3_column_int64(stmt, 7);
		_rec->refWzemMJob = sqlite3_column_int64(stmt, 8);
		_rec->refWzemMNode = sqlite3_column_int64(stmt, 9);
		_rec->refWzemMOp = sqlite3_column_int64(stmt, 10);
		_rec->refWzemMPreset = sqlite3_column_int64(stmt, 11);
		_rec->Cmd.assign((const char*) sqlite3_column_text(stmt, 12));
		_rec->Filename.assign((const char*) sqlite3_column_text(stmt, 13));
		_rec->srefIxVFeatgroup.assign((const char*) sqlite3_column_text(stmt, 14));
		_rec->srefIxVMethod.assign((const char*) sqlite3_column_text(stmt, 15));
		_rec->xsref.assign((const char*) sqlite3_column_text(stmt, 16));

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

ubigint LiteTblWzemMEvent::loadRst(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMEvent& rst
		) {
	int res; ubigint numread = 0;

	WzemMEvent* rec;

	if (!append) rst.clear();

	res = sqlite3_step(stmt);
	while (res == SQLITE_ROW) {
		rec = new WzemMEvent();

		rec->ref = sqlite3_column_int64(stmt, 0);
		rec->ixVBasetype = sqlite3_column_int(stmt, 1);
		rec->refWzemCEvent = sqlite3_column_int64(stmt, 2);
		rec->refWzemMPeriod = sqlite3_column_int64(stmt, 3);
		rec->refWzemMDpch = sqlite3_column_int64(stmt, 4);
		rec->startu = sqlite3_column_double(stmt, 5);
		rec->refWzemMCall = sqlite3_column_int64(stmt, 6);
		rec->refWzemMClstn = sqlite3_column_int64(stmt, 7);
		rec->refWzemMJob = sqlite3_column_int64(stmt, 8);
		rec->refWzemMNode = sqlite3_column_int64(stmt, 9);
		rec->refWzemMOp = sqlite3_column_int64(stmt, 10);
		rec->refWzemMPreset = sqlite3_column_int64(stmt, 11);
		rec->Cmd.assign((const char*) sqlite3_column_text(stmt, 12));
		rec->Filename.assign((const char*) sqlite3_column_text(stmt, 13));
		rec->srefIxVFeatgroup.assign((const char*) sqlite3_column_text(stmt, 14));
		rec->srefIxVMethod.assign((const char*) sqlite3_column_text(stmt, 15));
		rec->xsref.assign((const char*) sqlite3_column_text(stmt, 16));

		rst.nodes.push_back(rec);

		numread++;

		res = sqlite3_step(stmt);
	};

	return(numread);
};

bool LiteTblWzemMEvent::loadRecByStmt(
			sqlite3_stmt* stmt
			, WzemMEvent** rec
		) {
	bool retval = loadRec(stmt, rec);

	sqlite3_reset(stmt);

	return retval;
};

ubigint LiteTblWzemMEvent::loadRstByStmt(
			sqlite3_stmt* stmt
			, const bool append
			, ListWzemMEvent& rst
		) {
	ubigint retval = loadRst(stmt, append, rst);

	sqlite3_reset(stmt);

	return retval;
};

bool LiteTblWzemMEvent::loadRecBySQL(
			const string& sqlstr
			, WzemMEvent** rec
		) {
	int res;
	sqlite3_stmt* stmt;

	bool retval = false;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMEvent::loadRecBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRec(stmt, rec);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMEvent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWzemMEvent& rst
		) {
	int res;
	sqlite3_stmt* stmt;

	ubigint retval = 0;

	res = sqlite3_prepare_v2(dbs, sqlstr.c_str(), sqlstr.length()+1, &stmt, NULL);
	if (res != SQLITE_OK) {
		string dbms = "LiteTblWzemMEvent::loadRstBySQL() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	retval = loadRst(stmt, append, rst);

	sqlite3_finalize(stmt);

	return retval;
};

ubigint LiteTblWzemMEvent::insertRec(
			WzemMEvent* rec
		) {
	sqlite3_bind_int(stmtInsertRec, 1, rec->ixVBasetype);
	sqlite3_bind_int64(stmtInsertRec, 2, rec->refWzemCEvent);
	sqlite3_bind_int64(stmtInsertRec, 3, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtInsertRec, 4, rec->refWzemMDpch);
	sqlite3_bind_double(stmtInsertRec, 5, rec->startu);
	sqlite3_bind_int64(stmtInsertRec, 6, rec->refWzemMCall);
	sqlite3_bind_int64(stmtInsertRec, 7, rec->refWzemMClstn);
	sqlite3_bind_int64(stmtInsertRec, 8, rec->refWzemMJob);
	sqlite3_bind_int64(stmtInsertRec, 9, rec->refWzemMNode);
	sqlite3_bind_int64(stmtInsertRec, 10, rec->refWzemMOp);
	sqlite3_bind_int64(stmtInsertRec, 11, rec->refWzemMPreset);
	sqlite3_bind_text(stmtInsertRec, 12, rec->Cmd.c_str(), rec->Cmd.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 13, rec->Filename.c_str(), rec->Filename.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 14, rec->srefIxVFeatgroup.c_str(), rec->srefIxVFeatgroup.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 15, rec->srefIxVMethod.c_str(), rec->srefIxVMethod.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtInsertRec, 16, rec->xsref.c_str(), rec->xsref.length(), SQLITE_STATIC);

	if (sqlite3_step(stmtInsertRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMEvent::insertRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = sqlite3_last_insert_rowid(dbs);

	sqlite3_reset(stmtInsertRec);
	
	return rec->ref;
};

void LiteTblWzemMEvent::insertRst(
			ListWzemMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void LiteTblWzemMEvent::updateRec(
			WzemMEvent* rec
		) {
	sqlite3_bind_int(stmtUpdateRec, 1, rec->ixVBasetype);
	sqlite3_bind_int64(stmtUpdateRec, 2, rec->refWzemCEvent);
	sqlite3_bind_int64(stmtUpdateRec, 3, rec->refWzemMPeriod);
	sqlite3_bind_int64(stmtUpdateRec, 4, rec->refWzemMDpch);
	sqlite3_bind_double(stmtUpdateRec, 5, rec->startu);
	sqlite3_bind_int64(stmtUpdateRec, 6, rec->refWzemMCall);
	sqlite3_bind_int64(stmtUpdateRec, 7, rec->refWzemMClstn);
	sqlite3_bind_int64(stmtUpdateRec, 8, rec->refWzemMJob);
	sqlite3_bind_int64(stmtUpdateRec, 9, rec->refWzemMNode);
	sqlite3_bind_int64(stmtUpdateRec, 10, rec->refWzemMOp);
	sqlite3_bind_int64(stmtUpdateRec, 11, rec->refWzemMPreset);
	sqlite3_bind_text(stmtUpdateRec, 12, rec->Cmd.c_str(), rec->Cmd.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 13, rec->Filename.c_str(), rec->Filename.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 14, rec->srefIxVFeatgroup.c_str(), rec->srefIxVFeatgroup.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 15, rec->srefIxVMethod.c_str(), rec->srefIxVMethod.length(), SQLITE_STATIC);
	sqlite3_bind_text(stmtUpdateRec, 16, rec->xsref.c_str(), rec->xsref.length(), SQLITE_STATIC);
	sqlite3_bind_int64(stmtUpdateRec, 17, rec->ref);

	if (sqlite3_step(stmtUpdateRec) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMEvent::updateRec() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtUpdateRec);
};

void LiteTblWzemMEvent::updateRst(
			ListWzemMEvent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void LiteTblWzemMEvent::removeRecByRef(
			ubigint ref
		) {
	sqlite3_bind_int64(stmtRemoveRecByRef, 1, ref);

	if (sqlite3_step(stmtRemoveRecByRef) != SQLITE_DONE) {
		string dbms = "LiteTblWzemMEvent::removeRecByRef() / " + string(sqlite3_errmsg(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	sqlite3_reset(stmtRemoveRecByRef);
};

bool LiteTblWzemMEvent::loadRecByRef(
			ubigint ref
			, WzemMEvent** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	sqlite3_bind_int64(stmtLoadRecByRef, 1, ref);

	return loadRecByStmt(stmtLoadRecByRef, rec);
};

bool LiteTblWzemMEvent::loadRecByDch(
			ubigint refWzemMDpch
			, WzemMEvent** rec
		) {
	sqlite3_bind_int64(stmtLoadRecByDch, 1, refWzemMDpch);

	return loadRecByStmt(stmtLoadRecByDch, rec);
};

ubigint LiteTblWzemMEvent::loadRefsByClu(
			ubigint refWzemCEvent
			, const bool append
			, vector<ubigint>& refs
		) {
	sqlite3_bind_int64(stmtLoadRefsByClu, 1, refWzemCEvent);

	return loadRefsByStmt(stmtLoadRefsByClu, append, refs);
};

ubigint LiteTblWzemMEvent::loadRstByClu(
			ubigint refWzemCEvent
			, const bool append
			, ListWzemMEvent& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByClu, 1, refWzemCEvent);

	return loadRstByStmt(stmtLoadRstByClu, append, rst);
};

ubigint LiteTblWzemMEvent::loadRstByPrd(
			ubigint refWzemMPeriod
			, const bool append
			, ListWzemMEvent& rst
		) {
	sqlite3_bind_int64(stmtLoadRstByPrd, 1, refWzemMPeriod);

	return loadRstByStmt(stmtLoadRstByPrd, append, rst);
};

#endif

