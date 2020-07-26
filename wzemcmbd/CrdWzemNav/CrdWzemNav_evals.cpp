/**
	* \file CrdWzemNav_evals.cpp
	* job handler for job CrdWzemNav (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWzemNav::evalPnlpreAvail(
			DbsWzem* dbswzem
		) {
	// pre.refPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalPnladminAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzemNav::evalPnlmonAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrd()|pre.ixCrdaccEvt()|pre.ixCrdaccJob()|pre.ixCrdaccCal()|pre.ixCrdaccCln()|pre.ixCrdaccOpx()|pre.ixCrdaccPst()|pre.ixCrdaccNde()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzemNav::evalMitSesSpsAvail(
			DbsWzem* dbswzem
		) {
	// stgwzemappearance.suspsessEq(true)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwzemappearance.suspsess == true);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMspCrd1Avail(
			DbsWzem* dbswzem
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbswzem);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdUsgAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdUsrAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdPrsAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMspCrd2Avail(
			DbsWzem* dbswzem
		) {
	// MitCrdPrdAvail()|MitCrdEvtAvail()|MitCrdJobAvail()|MitCrdCalAvail()|MitCrdClnAvail()|MitCrdOpxAvail()|MitCrdPstAvail()|MitCrdNdeAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdPrdAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdEvtAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdJobAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdCalAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdClnAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdOpxAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdPstAvail(dbswzem);
	args.push_back(a);
	a = false; a = evalMitCrdNdeAvail(dbswzem);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdPrdAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdEvtAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdJobAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdCalAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdClnAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccCln()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdOpxAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdPstAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitCrdNdeAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNde()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMspApp2Avail(
			DbsWzem* dbswzem
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbswzem);
	args.push_back(a);

	return(args.back());
};

bool CrdWzemNav::evalMitAppLoiAvail(
			DbsWzem* dbswzem
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {uint cnt = 0; dbswzem->loadUintBySQL("SELECT COUNT(ref) FROM TblWzemMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};

