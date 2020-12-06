/**
	* \file PnlWzemNavMon_evals.cpp
	* job handler for job PnlWzemNavMon (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemNavMon::evalLstPrdAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButPrdViewActive(
			DbsWzem* dbswzem
		) {
	// LstPrd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstEvtAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButEvtViewActive(
			DbsWzem* dbswzem
		) {
	// LstEvt.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstEvt != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstJobAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButJobViewActive(
			DbsWzem* dbswzem
		) {
	// LstJob.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstJob != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstCalAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButCalViewActive(
			DbsWzem* dbswzem
		) {
	// LstCal.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCal != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstClnAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccCln()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButClnViewActive(
			DbsWzem* dbswzem
		) {
	// LstCln.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCln != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstOpxAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButOpxViewActive(
			DbsWzem* dbswzem
		) {
	// LstOpx.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOpx != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstPstAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButPstViewActive(
			DbsWzem* dbswzem
		) {
	// LstPst.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPst != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalLstNdeAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNde()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNavMon::evalButNdeViewActive(
			DbsWzem* dbswzem
		) {
	// LstNde.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstNde != 0);
	args.push_back(a);

	return(args.back());
};







