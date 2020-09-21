/**
	* \file PnlWzemJobDetail_evals.cpp
	* job handler for job PnlWzemJobDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemJobDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalTxtPrdActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalButPrdViewAvail(
			DbsWzem* dbswzem
		) {
	// job.prdEq(0)|(pre.ixCrdaccPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (recJob.refWzemMPeriod == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemJobDetail::evalButPrdViewActive(
			DbsWzem* dbswzem
		) {
	// !job.prdEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recJob.refWzemMPeriod == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemJobDetail::evalTxfJobActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalTxfXjrActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalTxfStoActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalTxtSupActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalButSupViewAvail(
			DbsWzem* dbswzem
		) {
	// job.supEq(0)|(pre.ixCrdaccJob())

	vector<bool> args;
	bool a, b;

	a = false; a = (recJob.supRefWzemMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemJobDetail::evalButSupViewActive(
			DbsWzem* dbswzem
		) {
	// !job.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recJob.supRefWzemMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemJobDetail::evalChkClsActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalChkSncActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalChkDclActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJobDetail::evalChkStmActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

