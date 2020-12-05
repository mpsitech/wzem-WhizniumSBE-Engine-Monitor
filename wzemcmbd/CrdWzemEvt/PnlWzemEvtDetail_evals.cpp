/**
	* \file PnlWzemEvtDetail_evals.cpp
	* job handler for job PnlWzemEvtDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemEvtDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalPupTypActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtPrdActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButPrdViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.prdEq(0)|(pre.ixCrdaccPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMPeriod == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButPrdViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.prdEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMPeriod == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalLstCluActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButCluViewActive(
			DbsWzem* dbswzem
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButCluClusterAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)&evt.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recEvt.refWzemCEvent == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButCluUnclusterAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)&!evt.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recEvt.refWzemCEvent == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtCalActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButCalViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.calEq(0)|(pre.ixCrdaccCal())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMCall == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCAL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButCalViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.calEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMCall == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtClnActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButClnViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.clnEq(0)|(pre.ixCrdaccCln())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMClstn == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButClnViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.clnEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMClstn == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtJobActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButJobViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.jobEq(0)|(pre.ixCrdaccJob())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButJobViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtNdeActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButNdeViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.ndeEq(0)|(pre.ixCrdaccNde())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMNode == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButNdeViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.ndeEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMNode == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtOpxActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButOpxViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.opxEq(0)|(pre.ixCrdaccOpx())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMOp == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButOpxViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.opxEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMOp == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxtPstActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButPstViewAvail(
			DbsWzem* dbswzem
		) {
	// evt.pstEq(0)|(pre.ixCrdaccPst())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWzemMPreset == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButPstViewActive(
			DbsWzem* dbswzem
		) {
	// !evt.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfCmdActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfFnmActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfFegActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfMtdActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfXsrActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButDchNewAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)&evt.dchEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recEvt.refWzemMDpch == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalButDchDeleteAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)&!evt.dchEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recEvt.refWzemMDpch == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfDchDchAvail(
			DbsWzem* dbswzem
		) {
	// !evt.dchEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMDpch == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfDchDchActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfDchMskAvail(
			DbsWzem* dbswzem
		) {
	// !evt.dchEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMDpch == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfDchMskActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfDchCntAvail(
			DbsWzem* dbswzem
		) {
	// !evt.dchEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWzemMDpch == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemEvtDetail::evalTxfDchCntActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCEVT, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

