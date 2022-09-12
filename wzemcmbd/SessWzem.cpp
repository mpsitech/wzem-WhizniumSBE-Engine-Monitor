/**
	* \file SessWzem.cpp
	* job handler for job SessWzem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "SessWzem.h"

#include "SessWzem_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class SessWzem
 ******************************************************************************/

SessWzem::SessWzem(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const ubigint refWzemMUser
			, const string& ip
		) :
			JobWzem(xchg, VecWzemVJob::SESSWZEM, jrefSup)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	crdnav = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	WzemMUser* usr = NULL;

	bool adm;

	ListWzemRMUserMUsergroup urus;
	WzemRMUserMUsergroup* uru = NULL;

	uint ixWzemWAccessBase, ixWzemWAccess;

	uint jnum;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbswzem->tblwzemmsession->insertNewRec(NULL, refWzemMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecWzemVPreset::PREWZEMSESS, jref, refSes);
	xchg->addTxtvalPreset(VecWzemVPreset::PREWZEMIP, jref, ip);

	// set locale and presetings corresponding to user
	dbswzem->tblwzemmuser->loadRecByRef(refWzemMUser, &usr);

	ixWzemVLocale = usr->ixWzemVLocale;
	adm = (usr->ixWzemVUserlevel == VecWzemVUserlevel::ADM);

	xchg->addBoolvalPreset(VecWzemVPreset::PREWZEMADMIN, jref, adm);
	xchg->addBoolvalPreset(VecWzemVPreset::PREWZEMNOADM, jref, (usr->ixWzemVUserlevel == VecWzemVUserlevel::REG));

	xchg->addRefPreset(VecWzemVPreset::PREWZEMGROUP, jref, usr->refWzemMUsergroup);
	xchg->addRefPreset(VecWzemVPreset::PREWZEMOWNER, jref, refWzemMUser);

	delete usr;

	// set jrefSess (for access to WzemQSelect from rst-type panel queries)
	xchg->addRefPreset(VecWzemVPreset::PREWZEMJREFSESS, jref, jref);

	// fill query in WzemQSelect with all applicable user groups
	jnum = 1;

	dbswzem->tblwzemqselect->insertNewRec(NULL, jref, jnum++, 0, 0);

	if (adm) {
		dbswzem->loadRefsBySQL("SELECT ref FROM TblWzemMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) dbswzem->tblwzemqselect->insertNewRec(NULL, jref, jnum++, 0, refs[i]);

	} else {
		dbswzem->tblwzemrmusermusergroup->loadRstByUsr(refWzemMUser, false, urus);

		for (unsigned int i = 0; i < urus.nodes.size(); i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refWzemMUsergroup] = uru->ixWzemVUserlevel;
			dbswzem->tblwzemqselect->insertNewRec(NULL, jref, jnum++, 0, uru->refWzemMUsergroup);
		};
	};

	// determine access rights for each card
	ixWzemWAccessBase = 0;
	getIxCrdacc(dbswzem, 0, adm, urus, refWzemMUser, ixWzemWAccessBase);

	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMUSG, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMUSR, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMPRS, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMPRD, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMEVT, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMJOB, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMCAL, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMCLN, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMOPX, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMPST, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref, ixWzemWAccess);
	ixWzemWAccess = ixWzemWAccessBase; if (!adm) getIxCrdacc(dbswzem, VecWzemVCard::CRDWZEMNDE, adm, urus, refWzemMUser, ixWzemWAccess); xchg->addIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref, ixWzemWAccess);

	crdnav = new CrdWzemNav(xchg, dbswzem, jref, ixWzemVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWzemVCall::CALLWZEMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzemVCall::CALLWZEMRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessWzem::~SessWzem() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void SessWzem::warnTerm(
			DbsWzem* dbswzem
		) {
	crdnav->warnTerm(dbswzem);
};

void SessWzem::term(
			DbsWzem* dbswzem
		) {
	WzemMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	if (dbswzem->tblwzemmsession->loadRecByRef(xchg->getRefPreset(VecWzemVPreset::PREWZEMSESS, jref), &ses)) {
		ses->stop = rawtime;
		dbswzem->tblwzemmsession->updateRec(ses);

		delete ses;
	};
};

void SessWzem::eraseCrd(
			map<ubigint, JobWzem*>& subjobs
		) {
	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoll(input.c_str());

	if (!eraseSubjobByJref(subjobs, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tcard erased." << endl;
};

uint SessWzem::checkCrdActive(
			const uint ixWzemVCard
		) {
	if (ixWzemVCard == VecWzemVCard::CRDWZEMEVT) return evalCrdevtActive();
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMJOB) return evalCrdjobActive();
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMCAL) return evalCrdcalActive();
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMCLN) return evalCrdclnActive();
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMOPX) return evalCrdopxActive();
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPST) return evalCrdpstActive();
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMNDE) return evalCrdndeActive();

	return 0;
};

uint SessWzem::evalCrdevtActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::evalCrdjobActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::evalCrdcalActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::evalCrdclnActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::evalCrdopxActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::evalCrdpstActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::evalCrdndeActive() {
	// pre.refPrd()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref)) ? VecWzemVPreset::PREWZEMREFPRD : 0);

	return(args.back());
};

uint SessWzem::checkCrdaccess(
			const uint ixWzemVCard
		) {
	if (ixWzemVCard == VecWzemVCard::CRDWZEMUSG) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMUSR) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPRS) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPRD) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMEVT) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMJOB) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMCAL) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMCLN) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMOPX) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPST) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref);
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMNDE) return xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref);

	return 0;
};

void SessWzem::getIxCrdacc(
			DbsWzem* dbswzem
			, const uint ixWzemVCard
			, const bool adm
			, ListWzemRMUserMUsergroup& urus
			, const ubigint refWzemMUser
			, uint& ixWzemWAccess
		) {
	WzemRMUserMUsergroup* uru = NULL;
	WzemAMUsergroupAccess* usgAacc = NULL;
	WzemAMUserAccess* usrAacc = NULL;

	uint ixCrdacc = 0;

	bool first = true;

	if (adm) {
		ixWzemWAccess = VecWzemWAccess::EDIT + VecWzemWAccess::EXEC + VecWzemWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i = 0; i < urus.nodes.size(); i++) {
		uru = urus.nodes[i];

		if (dbswzem->tblwzemamusergroupaccess->loadRecBySQL("SELECT * FROM TblWzemAMUsergroupAccess WHERE refWzemMUsergroup = " + to_string(uru->refWzemMUsergroup) + " AND x1IxWzemVFeatgroup = " + to_string(VecWzemVFeatgroup::VECWZEMVCARD) + " AND x2FeaSrefUix = '" + VecWzemVCard::getSref(ixWzemVCard) + "'", &usgAacc)) {
			ixCrdacc |= usgAacc->ixWzemWAccess;
			first = false;

			delete usgAacc;
			if (ixCrdacc == (VecWzemWAccess::EDIT + VecWzemWAccess::EXEC + VecWzemWAccess::VIEW)) break;
		};
	};

	if (!first) ixWzemWAccess = ixCrdacc;

	// user access rights override user group access rights
	if (dbswzem->tblwzemamuseraccess->loadRecBySQL("SELECT * FROM TblWzemAMUserAccess WHERE refWzemMUser = " + to_string(refWzemMUser) + " AND x1IxWzemVFeatgroup = " + to_string(VecWzemVFeatgroup::VECWZEMVCARD) + " AND x2FeaSrefUix = '" + VecWzemVCard::getSref(ixWzemVCard) + "'", &usrAacc)) {
		ixWzemWAccess = usrAacc->ixWzemWAccess;
		delete usrAacc;
	};

};

uint SessWzem::checkRecaccess(
			DbsWzem* dbswzem
			, const uint ixWzemVCard
			, const ubigint ref
		) {
	uint retval = VecWzemVRecaccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refWzemMUser;
	uint ixWzemVMaintable;

	WzemAccRMUserUniversal* ausrRunv = NULL;
	WzemRMUsergroupUniversal* usgRunv = NULL;

	ixWzemVMaintable = crdToMtb(ixWzemVCard);

	if (ixWzemVMaintable == VecWzemVMaintable::VOID) {
		retval = VecWzemVRecaccess::FULL;

	} else if (hasGrpown(ixWzemVMaintable) && (ref != 0)) {
		// find record's group and owner
		dbswzem->loadRefBySQL("SELECT grp FROM " + VecWzemVMaintable::getSref(ixWzemVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbswzem->loadRefBySQL("SELECT own FROM " + VecWzemVMaintable::getSref(ixWzemVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMADMIN, jref)) retval = VecWzemVRecaccess::FULL;

		if (retval == VecWzemVRecaccess::NONE) {
			refWzemMUser = xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref);

			// a record's owner has full rights on his records
			if (refWzemMUser == own) retval = VecWzemVRecaccess::FULL;

			if (retval != VecWzemVRecaccess::FULL) {
				// individual record access right
				if (dbswzem->tblwzemaccrmuseruniversal->loadRecByUsrMtbUnv(refWzemMUser, ixWzemVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixWzemVRecaccess;
					delete ausrRunv;
				};
			};

			if (retval != VecWzemVRecaccess::FULL) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecWzemVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecWzemVRecaccess::FULL;
					};
				};
			};

			if (retval != VecWzemVRecaccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin(); it != usgaccs.end(); it++) {

					if (it->second == VecWzemVUserlevel::GADM) {
						if (dbswzem->tblwzemrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixWzemVMaintable, ref, &usgRunv)) {
							if (usgRunv->ixWzemVRecaccess == VecWzemVRecaccess::FULL) retval = VecWzemVRecaccess::FULL;
							else retval = VecWzemVRecaccess::VIEW;

							delete usgRunv;
						};
					};

					if (retval == VecWzemVRecaccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMADMIN, jref)) retval = VecWzemVRecaccess::FULL;
		else retval = VecWzemVRecaccess::VIEW;
	};

	return retval;
};

void SessWzem::logRecaccess(
			DbsWzem* dbswzem
			, const uint ixWzemVPreset
			, const ubigint preUref
			, const uint ixWzemVCard
			, const ubigint unvUref
		) {
	vector<ubigint> refs;

	ubigint refWzemMUser;
	uint unvIxWzemVMaintable;
	uint preIxWzemVMaintable;

	WzemHistRMUserUniversal* husrRunv = NULL;

	if (xchg->stgwzemappearance.histlength > 0) {
		refWzemMUser = xchg->getRefPreset(VecWzemVPreset::PREWZEMOWNER, jref);
		unvIxWzemVMaintable = crdToMtb(ixWzemVCard);
		preIxWzemVMaintable = preToMtb(ixWzemVPreset);

		if (!dbswzem->tblwzemhistrmuseruniversal->loadRecByUsrMtbUnvCrd(refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, &husrRunv)) {
			husrRunv = new WzemHistRMUserUniversal(0, refWzemMUser, unvIxWzemVMaintable, unvUref, ixWzemVCard, ixWzemVPreset, preIxWzemVMaintable, preUref, 0);
		};

		husrRunv->start = time(NULL);

		if (husrRunv->ref == 0) {
			dbswzem->tblwzemhistrmuseruniversal->insertRec(husrRunv);

			dbswzem->tblwzemhistrmuseruniversal->loadRefsByUsrMtbCrd(refWzemMUser, unvIxWzemVMaintable, ixWzemVCard, false, refs, 4294967296, xchg->stgwzemappearance.histlength);
			for (unsigned int i = 0; i < refs.size(); i++) dbswzem->tblwzemhistrmuseruniversal->removeRecByRef(refs[i]);

		} else dbswzem->tblwzemhistrmuseruniversal->updateRec(husrRunv);

		xchg->triggerIxRefCall(dbswzem, VecWzemVCall::CALLWZEMHUSRRUNVMOD_CRDUSREQ, jref, ixWzemVCard, refWzemMUser);
	};

	delete husrRunv;
};

uint SessWzem::crdToMtb(
			const uint ixWzemVCard
		) {
	if (ixWzemVCard == VecWzemVCard::CRDWZEMUSG) return VecWzemVMaintable::TBLWZEMMUSERGROUP;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMUSR) return VecWzemVMaintable::TBLWZEMMUSER;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPRS) return VecWzemVMaintable::TBLWZEMMPERSON;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPRD) return VecWzemVMaintable::TBLWZEMMPERIOD;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMEVT) return VecWzemVMaintable::TBLWZEMMEVENT;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMJOB) return VecWzemVMaintable::TBLWZEMMJOB;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMCAL) return VecWzemVMaintable::TBLWZEMMCALL;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMCLN) return VecWzemVMaintable::TBLWZEMMCLSTN;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMOPX) return VecWzemVMaintable::TBLWZEMMOP;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMPST) return VecWzemVMaintable::TBLWZEMMPRESET;
	else if (ixWzemVCard == VecWzemVCard::CRDWZEMNDE) return VecWzemVMaintable::TBLWZEMMNODE;

	return VecWzemVMaintable::VOID;
};

uint SessWzem::preToMtb(
			const uint ixWzemVPreset
		) {
	if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFCAL) return VecWzemVMaintable::TBLWZEMMCALL;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFCLN) return VecWzemVMaintable::TBLWZEMMCLSTN;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFDCH) return VecWzemVMaintable::TBLWZEMMDPCH;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFEVT) return VecWzemVMaintable::TBLWZEMMEVENT;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFJOB) return VecWzemVMaintable::TBLWZEMMJOB;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFNDE) return VecWzemVMaintable::TBLWZEMMNODE;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFOPX) return VecWzemVMaintable::TBLWZEMMOP;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFPRD) return VecWzemVMaintable::TBLWZEMMPERIOD;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFPRS) return VecWzemVMaintable::TBLWZEMMPERSON;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFPST) return VecWzemVMaintable::TBLWZEMMPRESET;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFSES) return VecWzemVMaintable::TBLWZEMMSESSION;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFUSG) return VecWzemVMaintable::TBLWZEMMUSERGROUP;
	else if (ixWzemVPreset == VecWzemVPreset::PREWZEMREFUSR) return VecWzemVMaintable::TBLWZEMMUSER;

	return VecWzemVMaintable::VOID;
};

bool SessWzem::hasActive(
			const uint ixWzemVCard
		) {
	return((ixWzemVCard == VecWzemVCard::CRDWZEMEVT) || (ixWzemVCard == VecWzemVCard::CRDWZEMJOB) || (ixWzemVCard == VecWzemVCard::CRDWZEMCAL) || (ixWzemVCard == VecWzemVCard::CRDWZEMCLN) || (ixWzemVCard == VecWzemVCard::CRDWZEMOPX) || (ixWzemVCard == VecWzemVCard::CRDWZEMPST) || (ixWzemVCard == VecWzemVCard::CRDWZEMNDE));
};

bool SessWzem::hasGrpown(
			const uint ixWzemVMaintable
		) {
	return((ixWzemVMaintable == VecWzemVMaintable::TBLWZEMMPERIOD) || (ixWzemVMaintable == VecWzemVMaintable::TBLWZEMMPERSON) || (ixWzemVMaintable == VecWzemVMaintable::TBLWZEMMUSER) || (ixWzemVMaintable == VecWzemVMaintable::TBLWZEMMUSERGROUP));
};

void SessWzem::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
	if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tcreateCrdcal" << endl;
			cout << "\tcreateCrdcln" << endl;
			cout << "\tcreateCrdevt" << endl;
			cout << "\tcreateCrdjob" << endl;
			cout << "\tcreateCrdnde" << endl;
			cout << "\tcreateCrdopx" << endl;
			cout << "\tcreateCrdprd" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdpst" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\teraseCrdcal" << endl;
			cout << "\teraseCrdcln" << endl;
			cout << "\teraseCrdevt" << endl;
			cout << "\teraseCrdjob" << endl;
			cout << "\teraseCrdnde" << endl;
			cout << "\teraseCrdopx" << endl;
			cout << "\teraseCrdprd" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdpst" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
		} else if (req->cmd == "createCrdcal") {
			req->retain = handleCreateCrdcal(dbswzem);

		} else if (req->cmd == "createCrdcln") {
			req->retain = handleCreateCrdcln(dbswzem);

		} else if (req->cmd == "createCrdevt") {
			req->retain = handleCreateCrdevt(dbswzem);

		} else if (req->cmd == "createCrdjob") {
			req->retain = handleCreateCrdjob(dbswzem);

		} else if (req->cmd == "createCrdnde") {
			req->retain = handleCreateCrdnde(dbswzem);

		} else if (req->cmd == "createCrdopx") {
			req->retain = handleCreateCrdopx(dbswzem);

		} else if (req->cmd == "createCrdprd") {
			req->retain = handleCreateCrdprd(dbswzem);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbswzem);

		} else if (req->cmd == "createCrdpst") {
			req->retain = handleCreateCrdpst(dbswzem);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbswzem);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbswzem);

		} else if (req->cmd == "eraseCrdcal") {
			req->retain = handleEraseCrdcal(dbswzem);

		} else if (req->cmd == "eraseCrdcln") {
			req->retain = handleEraseCrdcln(dbswzem);

		} else if (req->cmd == "eraseCrdevt") {
			req->retain = handleEraseCrdevt(dbswzem);

		} else if (req->cmd == "eraseCrdjob") {
			req->retain = handleEraseCrdjob(dbswzem);

		} else if (req->cmd == "eraseCrdnde") {
			req->retain = handleEraseCrdnde(dbswzem);

		} else if (req->cmd == "eraseCrdopx") {
			req->retain = handleEraseCrdopx(dbswzem);

		} else if (req->cmd == "eraseCrdprd") {
			req->retain = handleEraseCrdprd(dbswzem);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbswzem);

		} else if (req->cmd == "eraseCrdpst") {
			req->retain = handleEraseCrdpst(dbswzem);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbswzem);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbswzem);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMINIT) {
			handleDpchAppWzemInit(dbswzem, (DpchAppWzemInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessWzem::handleCreateCrdcal(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdcalActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcals, new CrdWzemCal(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdcln(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdclnActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdclns, new CrdWzemCln(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdevt(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdevtActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdevts, new CrdWzemEvt(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdjob(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdjobActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdjobs, new CrdWzemJob(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdnde(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdndeActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdndes, new CrdWzemNde(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdopx(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdopxActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdopxs, new CrdWzemOpx(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdprd(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprds, new CrdWzemPrd(xchg, dbswzem, jref, ixWzemVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzem::handleCreateCrdprs(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprss, new CrdWzemPrs(xchg, dbswzem, jref, ixWzemVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzem::handleCreateCrdpst(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	uint ixWzemVPreset = evalCrdpstActive();

	if (ixWzemVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdpsts, new CrdWzemPst(xchg, dbswzem, jref, ixWzemVLocale, 0, ixWzemVPreset, xchg->getRefPreset(ixWzemVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWzem::handleCreateCrdusg(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusgs, new CrdWzemUsg(xchg, dbswzem, jref, ixWzemVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzem::handleCreateCrdusr(
			DbsWzem* dbswzem
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusrs, new CrdWzemUsr(xchg, dbswzem, jref, ixWzemVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWzem::handleEraseCrdcal(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdcals);
	return retval;
};

bool SessWzem::handleEraseCrdcln(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdclns);
	return retval;
};

bool SessWzem::handleEraseCrdevt(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdevts);
	return retval;
};

bool SessWzem::handleEraseCrdjob(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdjobs);
	return retval;
};

bool SessWzem::handleEraseCrdnde(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdndes);
	return retval;
};

bool SessWzem::handleEraseCrdopx(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdopxs);
	return retval;
};

bool SessWzem::handleEraseCrdprd(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdprds);
	return retval;
};

bool SessWzem::handleEraseCrdprs(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdprss);
	return retval;
};

bool SessWzem::handleEraseCrdpst(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdpsts);
	return retval;
};

bool SessWzem::handleEraseCrdusg(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdusgs);
	return retval;
};

bool SessWzem::handleEraseCrdusr(
			DbsWzem* dbswzem
		) {
	bool retval = false;
	eraseCrd(crdusrs);
	return retval;
};

void SessWzem::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	Feed feedFEnsSec("FeedFEnsSec");

	// resume session
	xchg->removePreset(VecWzemVPreset::PREWZEMSUSPSESS, jref);

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemPrs");
	for (auto it = crdprds.begin(); it != crdprds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemPrd");
	for (auto it = crdevts.begin(); it != crdevts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemEvt");
	for (auto it = crdjobs.begin(); it != crdjobs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemJob");
	for (auto it = crdcals.begin(); it != crdcals.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemCal");
	for (auto it = crdclns.begin(); it != crdclns.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemCln");
	for (auto it = crdopxs.begin(); it != crdopxs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemOpx");
	for (auto it = crdpsts.begin(); it != crdpsts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemPst");
	for (auto it = crdndes.begin(); it != crdndes.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWzemNde");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWzem::handleCall(
			DbsWzem* dbswzem
			, Call* call
		) {
	if (call->ixVCall == VecWzemVCall::CALLWZEMREFPRESET) {
		call->abort = handleCallWzemRefPreSet(dbswzem, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMLOG) {
		call->abort = handleCallWzemLog(dbswzem, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCRDACTIVE) {
		call->abort = handleCallWzemCrdActive(dbswzem, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCRDCLOSE) {
		call->abort = handleCallWzemCrdClose(dbswzem, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMCRDOPEN) {
		call->abort = handleCallWzemCrdOpen(dbswzem, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWzemVCall::CALLWZEMRECACCESS) {
		call->abort = handleCallWzemRecaccess(dbswzem, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	};
};

bool SessWzem::handleCallWzemRefPreSet(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallWzemRefPreSet --- BEGIN
	if (ixInv == VecWzemVPreset::PREWZEMJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngWzemSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if (ixInv == VecWzemVPreset::PREWZEMTLAST) {
		if (xchg->stgwzemappearance.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);

	} else if ((ixInv == VecWzemVPreset::PREWZEMREFPRD)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbswzem, ixInv, jrefTrig, true);
	};
// IP handleCallWzemRefPreSet --- END
	return retval;
};

bool SessWzem::handleCallWzemLog(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logRecaccess(dbswzem, ixInv, refInv, VecWzemVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessWzem::handleCallWzemCrdActive(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessWzem::handleCallWzemCrdClose(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// delete only if card is not part of a suspended session
	if (xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMSUSPSESS, jrefTrig)) return retval;

	ubigint jrefNotif = xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecWzemVPreset::PREWZEMJREFNOTIFY, jref);

	if (ixInv == VecWzemVCard::CRDWZEMUSG) eraseSubjobByJref(crdusgs, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMUSR) eraseSubjobByJref(crdusrs, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMPRS) eraseSubjobByJref(crdprss, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} 
else if (ixInv == VecWzemVCard::CRDWZEMPRD) eraseSubjobByJref(crdprds, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMEVT) eraseSubjobByJref(crdevts, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMJOB) eraseSubjobByJref(crdjobs, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMCAL) eraseSubjobByJref(crdcals, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMCLN) eraseSubjobByJref(crdclns, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMOPX) eraseSubjobByJref(crdopxs, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMPST) eraseSubjobByJref(crdpsts, jrefTrig);
	else if (ixInv == VecWzemVCard::CRDWZEMNDE) eraseSubjobByJref(crdndes, jrefTrig);
	return retval;
};

bool SessWzem::handleCallWzemCrdOpen(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixWzemVCard = VecWzemVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixWzemVPreset;
	ubigint preUref = 0;

	uint ixWzemWAccess;
	uint ixWzemVRecaccess;

	if (hasActive(ixWzemVCard)) {
		if (ixInv == 0) {
			ixWzemVPreset = checkCrdActive(ixWzemVCard);
			if (ixWzemVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixWzemVPreset, jref);
			};

		} else {
			ixWzemVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixWzemWAccess = checkCrdaccess(ixWzemVCard);
		denied = (ixWzemWAccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixWzemWAccess & VecWzemWAccess::EDIT) == 0) || ((ixWzemWAccess & VecWzemWAccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixWzemVRecaccess = checkRecaccess(dbswzem, ixWzemVCard, intvalInv);
			denied = (ixWzemVRecaccess == VecWzemVRecaccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixWzemVCard == VecWzemVCard::CRDWZEMUSG) refRet = insertSubjob(crdusgs, new CrdWzemUsg(xchg, dbswzem, jref, ixWzemVLocale, ref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMUSR) refRet = insertSubjob(crdusrs, new CrdWzemUsr(xchg, dbswzem, jref, ixWzemVLocale, ref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMPRS) refRet = insertSubjob(crdprss, new CrdWzemPrs(xchg, dbswzem, jref, ixWzemVLocale, ref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMPRD) refRet = insertSubjob(crdprds, new CrdWzemPrd(xchg, dbswzem, jref, ixWzemVLocale, ref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMEVT) refRet = insertSubjob(crdevts, new CrdWzemEvt(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMJOB) refRet = insertSubjob(crdjobs, new CrdWzemJob(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMCAL) refRet = insertSubjob(crdcals, new CrdWzemCal(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMCLN) refRet = insertSubjob(crdclns, new CrdWzemCln(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMOPX) refRet = insertSubjob(crdopxs, new CrdWzemOpx(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMPST) refRet = insertSubjob(crdpsts, new CrdWzemPst(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
		else if (ixWzemVCard == VecWzemVCard::CRDWZEMNDE) refRet = insertSubjob(crdndes, new CrdWzemNde(xchg, dbswzem, jref, ixWzemVLocale, ref, ixWzemVPreset, preUref));
	};

	return retval;
};

bool SessWzem::handleCallWzemRecaccess(
			DbsWzem* dbswzem
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkRecaccess(dbswzem, ixInv, refInv);
	return retval;
};
