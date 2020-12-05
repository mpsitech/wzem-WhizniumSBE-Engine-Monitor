/**
	* \file PnlWzemNavHeadbar_evals.cpp
	* job handler for job PnlWzemNavHeadbar (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemNavHeadbar::evalMenCrdAvail(
			DbsWzem* dbswzem
		) {
	// MspCrd1Avail()|MspCrd2Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbswzem);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbswzem);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMspCrd1Avail(
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

bool PnlWzemNavHeadbar::evalMitCrdUsgAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdUsrAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdPrsAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMspCrd2Avail(
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

bool PnlWzemNavHeadbar::evalMitCrdPrdAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdEvtAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdJobAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdCalAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdClnAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccCln()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdOpxAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdPstAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavHeadbar::evalMitCrdNdeAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNde()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

