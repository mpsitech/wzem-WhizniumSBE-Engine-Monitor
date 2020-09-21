/**
	* \file JobWzemIexIni.cpp
	* job handler for job JobWzemIexIni (implementation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "JobWzemIexIni.h"

#include "JobWzemIexIni_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWzemIni;

/******************************************************************************
 class JobWzemIexIni
 ******************************************************************************/

JobWzemIexIni::JobWzemIexIni(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::JOBWZEMIEXINI, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswzem, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWzemIexIni::~JobWzemIexIni() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWzemIexIni::reset(
			DbsWzem* dbswzem
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswzem, VecVSge::IDLE);
};

void JobWzemIexIni::parseFromFile(
			DbsWzem* dbswzem
			, const string& _fullpath
			, const bool _xmlNotTxt
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;

		changeStage(dbswzem, VecVSge::PARSE);
	};
};

void JobWzemIexIni::import(
			DbsWzem* dbswzem
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswzem, VecVSge::IMPORT);
};

void JobWzemIexIni::reverse(
			DbsWzem* dbswzem
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswzem, VecVSge::REVERSE);
};

void JobWzemIexIni::collect(
			DbsWzem* dbswzem
			, const map<uint,uint>& _icsWzemVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWzemVIop = _icsWzemVIop;
		changeStage(dbswzem, VecVSge::COLLECT);
	};
};

void JobWzemIexIni::exportToFile(
			DbsWzem* dbswzem
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const bool _shorttags
		) {
	if ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		shorttags = _shorttags;

		changeStage(dbswzem, VecVSge::EXPORT);
	};
};

void JobWzemIexIni::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
	if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

void JobWzemIexIni::changeStage(
			DbsWzem* dbswzem
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzem); break;
				case VecVSge::PARSE: leaveSgeParse(dbswzem); break;
				case VecVSge::PRSERR: leaveSgePrserr(dbswzem); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswzem); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswzem); break;
				case VecVSge::IMPERR: leaveSgeImperr(dbswzem); break;
				case VecVSge::REVERSE: leaveSgeReverse(dbswzem); break;
				case VecVSge::COLLECT: leaveSgeCollect(dbswzem); break;
				case VecVSge::CLTDONE: leaveSgeCltdone(dbswzem); break;
				case VecVSge::EXPORT: leaveSgeExport(dbswzem); break;
				case VecVSge::DONE: leaveSgeDone(dbswzem); break;
			};

			setStage(dbswzem, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzem, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswzem, reenter); break;
			case VecVSge::PRSERR: _ixVSge = enterSgePrserr(dbswzem, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswzem, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswzem, reenter); break;
			case VecVSge::IMPERR: _ixVSge = enterSgeImperr(dbswzem, reenter); break;
			case VecVSge::REVERSE: _ixVSge = enterSgeReverse(dbswzem, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbswzem, reenter); break;
			case VecVSge::CLTDONE: _ixVSge = enterSgeCltdone(dbswzem, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswzem, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzem, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzemIexIni::getSquawk(
			DbsWzem* dbswzem
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing initialization data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting initialization data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "initialization data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting initialization data";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWzemIexIni::enterSgeIdle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWzemVIop.clear();

	imeiavcontrolpar.clear();
	imeiavkeylistkey.clear();
	imeiavvaluelistval.clear();
	imeimusergroup.clear();

	return retval;
};

void JobWzemIexIni::leaveSgeIdle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzemIexIni::enterSgeParse(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWzemIni::parseFromFile(fullpath, xmlNotTxt, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimusergroup);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWzemVError::getIx, VecWzemVError::getTitle, ixWzemVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWzemIexIni::leaveSgeParse(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWzemIexIni::enterSgePrserr(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWzemIexIni::leaveSgePrserr(
			DbsWzem* dbswzem
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWzemIexIni::enterSgePrsdone(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWzemIexIni::leaveSgePrsdone(
			DbsWzem* dbswzem
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWzemIexIni::enterSgeImport(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint num0;

	// IP enterSgeImport.prep --- IBEGIN
	WzemRMUserMUsergroup uru;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIAVControlPar
		for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
			ctlApar = imeiavcontrolpar.nodes[ix0];

			ctlApar->ixWzemVControl = VecWzemVControl::getIx(ctlApar->srefIxWzemVControl);
			if (ctlApar->ixWzemVControl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ctlApar->srefIxWzemVControl}, {"iel","srefIxWzemVControl"}, {"lineno",to_string(ctlApar->lineno)}});
			//ctlApar->Par: TBL
			//ctlApar->Val: TBL

			dbswzem->tblwzemavcontrolpar->insertRec(ctlApar);
			impcnt++;
		};

		// -- ImeIAVKeylistKey
		for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
			klsAkey = imeiavkeylistkey.nodes[ix0];

			klsAkey->klsIxWzemVKeylist = VecWzemVKeylist::getIx(klsAkey->srefKlsIxWzemVKeylist);
			if (klsAkey->klsIxWzemVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey->srefKlsIxWzemVKeylist}, {"iel","srefKlsIxWzemVKeylist"}, {"lineno",to_string(klsAkey->lineno)}});
			klsAkey->klsNum = (ix0+1); // TBD
			klsAkey->x1IxWzemVMaintable = VecWzemVMaintable::VOID;
			klsAkey->Fixed = true;
			//klsAkey->sref: TBL
			//klsAkey->Avail: TBL
			//klsAkey->Implied: TBL
			//klsAkey->refJ: SUB
			//klsAkey->Title: TBL
			//klsAkey->Comment: TBL

			dbswzem->tblwzemavkeylistkey->insertRec(klsAkey);
			impcnt++;

			if (((klsAkey->Title != "") || (klsAkey->Comment != "")) && klsAkey->imeijavkeylistkey.nodes.empty()) {
				kakJkey = new ImeitemIJAVKeylistKey();
				kakJkey->lineno = klsAkey->lineno;
				klsAkey->imeijavkeylistkey.nodes.push_back(kakJkey);

				kakJkey->refWzemAVKeylistKey = klsAkey->ref;
				kakJkey->Title = klsAkey->Title;
				kakJkey->Comment = klsAkey->Comment;
			};

			for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
				kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

				kakJkey->refWzemAVKeylistKey = klsAkey->ref;
				if (kakJkey->srefX1IxWzemVLocale == "") kakJkey->srefX1IxWzemVLocale = "enus";
				kakJkey->x1IxWzemVLocale = VecWzemVLocale::getIx(kakJkey->srefX1IxWzemVLocale);
				if (kakJkey->x1IxWzemVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",kakJkey->srefX1IxWzemVLocale}, {"iel","srefX1IxWzemVLocale"}, {"lineno",to_string(kakJkey->lineno)}});
				//kakJkey->Title: TBL
				//kakJkey->Comment: TBL

				dbswzem->tblwzemjavkeylistkey->insertRec(kakJkey);
				impcnt++;

				if (ix1 == 0) {
					klsAkey->refJ = kakJkey->ref;
					klsAkey->Title = kakJkey->Title;
					klsAkey->Comment = kakJkey->Comment;
					dbswzem->tblwzemavkeylistkey->updateRec(klsAkey);
				};
			};
		};

		// -- ImeIAVValuelistVal
		for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
			vlsAval = imeiavvaluelistval.nodes[ix0];

			vlsAval->vlsIxWzemVValuelist = VecWzemVValuelist::getIx(vlsAval->srefVlsIxWzemVValuelist);
			if (vlsAval->vlsIxWzemVValuelist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefVlsIxWzemVValuelist}, {"iel","srefVlsIxWzemVValuelist"}, {"lineno",to_string(vlsAval->lineno)}});
			vlsAval->vlsNum = (ix0+1); // TBD
			vlsAval->x1IxWzemVLocale = VecWzemVLocale::getIx(vlsAval->srefX1IxWzemVLocale);
			if (vlsAval->x1IxWzemVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefX1IxWzemVLocale}, {"iel","srefX1IxWzemVLocale"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->Val: TBL

			dbswzem->tblwzemavvaluelistval->insertRec(vlsAval);
			impcnt++;
		};

		// -- ImeIMUsergroup
		for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
			usg = imeimusergroup.nodes[ix0];

			//usg->sref: TBL
			//usg->Comment: TBL

			dbswzem->tblwzemmusergroup->insertRec(usg);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
				usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

				usgAacc->refWzemMUsergroup = usg->ref;
				usgAacc->x1IxWzemVFeatgroup = VecWzemVFeatgroup::getIx(usgAacc->srefX1IxWzemVFeatgroup);
				if (usgAacc->x1IxWzemVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usgAacc->srefX1IxWzemVFeatgroup}, {"iel","srefX1IxWzemVFeatgroup"}, {"lineno",to_string(usgAacc->lineno)}});
				//usgAacc->x2FeaSrefUix: TBL
				usgAacc->ixWzemWAccess = VecWzemWAccess::getIx(usgAacc->srefsIxWzemWAccess);

				dbswzem->tblwzemamusergroupaccess->insertRec(usgAacc);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
				usr = usg->imeimuser.nodes[ix1];

				//usr->refRUsergroup: IMPPP
				usr->refWzemMUsergroup = usg->ref;
				//usr->refWzemMPerson: IMPPP
				//usr->sref: TBL
				//usr->refJState: SUB
				if (usr->srefIxVState != "") {
					usr->ixVState = VecWzemVMUserState::getIx(usr->srefIxVState);
					if (usr->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usr->lineno)}});
				};
				usr->ixWzemVLocale = VecWzemVLocale::getIx(usr->srefIxWzemVLocale);
				if (usr->ixWzemVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWzemVLocale}, {"iel","srefIxWzemVLocale"}, {"lineno",to_string(usr->lineno)}});
				usr->ixWzemVUserlevel = VecWzemVUserlevel::getIx(usr->srefIxWzemVUserlevel);
				if (usr->ixWzemVUserlevel == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWzemVUserlevel}, {"iel","srefIxWzemVUserlevel"}, {"lineno",to_string(usr->lineno)}});
				//usr->Password: TBL
				//usr->Fullkey: TBL
				//usr->Comment: TBL

				dbswzem->tblwzemmuser->insertRec(usr);
				impcnt++;

				if (((usr->srefIxVState != "")) && usr->imeijmuserstate.nodes.empty()) {
					usrJste = new ImeitemIJMUserState();
					usrJste->lineno = usr->lineno;
					usr->imeijmuserstate.nodes.push_back(usrJste);

					usrJste->refWzemMUser = usr->ref;
					usrJste->srefIxVState = usr->srefIxVState;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
					usrAacc = usr->imeiamuseraccess.nodes[ix2];

					usrAacc->refWzemMUser = usr->ref;
					usrAacc->x1IxWzemVFeatgroup = VecWzemVFeatgroup::getIx(usrAacc->srefX1IxWzemVFeatgroup);
					if (usrAacc->x1IxWzemVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrAacc->srefX1IxWzemVFeatgroup}, {"iel","srefX1IxWzemVFeatgroup"}, {"lineno",to_string(usrAacc->lineno)}});
					//usrAacc->x2FeaSrefUix: TBL
					usrAacc->ixWzemWAccess = VecWzemWAccess::getIx(usrAacc->srefsIxWzemWAccess);

					dbswzem->tblwzemamuseraccess->insertRec(usrAacc);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
					usrJste = usr->imeijmuserstate.nodes[ix2];

					usrJste->refWzemMUser = usr->ref;
					usrJste->x1Start = Ftm::invstamp("&now;");
					usrJste->ixVState = VecWzemVMUserState::getIx(usrJste->srefIxVState);
					if (usrJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usrJste->lineno)}});

					dbswzem->tblwzemjmuserstate->insertRec(usrJste);
					impcnt++;

					if (ix2 == 0) {
						usr->refJState = usrJste->ref;
						usr->ixVState = usrJste->ixVState;
						dbswzem->tblwzemmuser->updateRec(usr);
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
					prs = usr->imeimperson.nodes[ix2];

					prs->ixWDerivate = VecWzemWMPersonDerivate::USR;
					prs->ixVSex = VecWzemVMPersonSex::getIx(prs->srefIxVSex);
					if (prs->ixVSex == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prs->srefIxVSex}, {"iel","srefIxVSex"}, {"lineno",to_string(prs->lineno)}});
					//prs->Title: TBL
					//prs->Firstname: TBL
					//prs->refJLastname: SUB
					//prs->Lastname: TBL

					dbswzem->tblwzemmperson->insertRec(prs);
					impcnt++;

					if (((prs->Lastname != "")) && prs->imeijmpersonlastname.nodes.empty()) {
						prsJlnm = new ImeitemIJMPersonLastname();
						prsJlnm->lineno = prs->lineno;
						prs->imeijmpersonlastname.nodes.push_back(prsJlnm);

						prsJlnm->refWzemMPerson = prs->ref;
						prsJlnm->Lastname = prs->Lastname;
					};

					if (ix2 == 0) {
						usr->refWzemMPerson = prs->ref;
						dbswzem->tblwzemmuser->updateRec(usr);
					};

					for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
						prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

						prsJlnm->refWzemMPerson = prs->ref;
						prsJlnm->x1Startd = Ftm::invdate("&today;");
						//prsJlnm->Lastname: TBL

						dbswzem->tblwzemjmpersonlastname->insertRec(prsJlnm);
						impcnt++;

						if (ix3 == 0) {
							prs->refJLastname = prsJlnm->ref;
							prs->Lastname = prsJlnm->Lastname;
							dbswzem->tblwzemmperson->updateRec(prs);
						};
					};
				};
	
				uru.refWzemMUser = usr->ref;
				uru.refWzemMUsergroup = usg->ref;
				uru.ixWzemVUserlevel = usr->ixWzemVUserlevel;
				dbswzem->tblwzemrmusermusergroup->insertRec(&uru);

				usr->refRUsergroup = uru.ref;
				usr->refWzemMUsergroup = usg->ref;
				dbswzem->tblwzemmuser->updateRec(usr);
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWzemVError::getIx, VecWzemVError::getTitle, ixWzemVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWzemIexIni::leaveSgeImport(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWzemIexIni::enterSgeImperr(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWzemIexIni::leaveSgeImperr(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWzemIexIni::enterSgeReverse(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];
		if (ctlApar->ref != 0) dbswzem->tblwzemavcontrolpar->removeRecByRef(ctlApar->ref);
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];
		if (klsAkey->ref != 0) dbswzem->tblwzemavkeylistkey->removeRecByRef(klsAkey->ref);

		for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];
			if (kakJkey->ref != 0) dbswzem->tblwzemjavkeylistkey->removeRecByRef(kakJkey->ref);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];
		if (vlsAval->ref != 0) dbswzem->tblwzemavvaluelistval->removeRecByRef(vlsAval->ref);
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];
		if (usg->ref != 0) dbswzem->tblwzemmusergroup->removeRecByRef(usg->ref);

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];
			if (usgAacc->ref != 0) dbswzem->tblwzemamusergroupaccess->removeRecByRef(usgAacc->ref);
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];
			if (usr->ref != 0) dbswzem->tblwzemmuser->removeRecByRef(usr->ref);

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];
				if (usrAacc->ref != 0) dbswzem->tblwzemamuseraccess->removeRecByRef(usrAacc->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];
				if (usrJste->ref != 0) dbswzem->tblwzemjmuserstate->removeRecByRef(usrJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];
				if (prs->ref != 0) dbswzem->tblwzemmperson->removeRecByRef(prs->ref);

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];
					if (prsJlnm->ref != 0) dbswzem->tblwzemjmpersonlastname->removeRecByRef(prsJlnm->ref);
				};
			};
		};
	};

	return retval;
};

void JobWzemIexIni::leaveSgeReverse(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWzemIexIni::enterSgeCollect(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* kakJkey = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixWzemVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey.nodes.size(); ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		if (klsAkey->ref != 0) {
		};

		if (getIxWzemVIop(icsWzemVIop, VecVIme::IMEIJAVKEYLISTKEY, ixWzemVIop)) {
			dbswzem->tblwzemjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbswzem, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < klsAkey->imeijavkeylistkey.nodes.size(); ix1++) {
			kakJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			if (kakJkey->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxWzemVIop(icsWzemVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixWzemVIop)) {
			dbswzem->tblwzemamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbswzem, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxWzemVIop(icsWzemVIop, VecVIme::IMEIMUSER, ixWzemVIop)) {
			dbswzem->tblwzemmuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbswzem, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxWzemVIop(icsWzemVIop, VecVIme::IMEIAMUSERACCESS, ixWzemVIop)) {
				dbswzem->tblwzemamuseraccess->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeiamuseraccess.nodes.push_back(new ImeitemIAMUserAccess(dbswzem, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				if (usrAacc->ref != 0) {
				};
			};

			if (getIxWzemVIop(icsWzemVIop, VecVIme::IMEIJMUSERSTATE, ixWzemVIop)) {
				dbswzem->tblwzemjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbswzem, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxWzemVIop(icsWzemVIop, VecVIme::IMEIJMPERSONLASTNAME, ixWzemVIop)) {
					dbswzem->tblwzemjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i = 0; i < refs.size(); i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbswzem, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWzemIexIni::leaveSgeCollect(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWzemIexIni::enterSgeCltdone(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWzemIexIni::leaveSgeCltdone(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWzemIexIni::enterSgeExport(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWzemIni::exportToFile(fullpath, xmlNotTxt, shorttags, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimusergroup);

	return retval;
};

void JobWzemIexIni::leaveSgeExport(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWzemIexIni::enterSgeDone(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWzemIexIni::leaveSgeDone(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeDone --- INSERT
};



