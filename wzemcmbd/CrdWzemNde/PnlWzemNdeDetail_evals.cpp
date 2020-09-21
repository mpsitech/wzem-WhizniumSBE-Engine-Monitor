/**
	* \file PnlWzemNdeDetail_evals.cpp
	* job handler for job PnlWzemNdeDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemNdeDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxtPrdActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalButPrdViewAvail(
			DbsWzem* dbswzem
		) {
	// nde.prdEq(0)|(pre.ixCrdaccPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (recNde.refWzemMPeriod == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemNdeDetail::evalButPrdViewActive(
			DbsWzem* dbswzem
		) {
	// !nde.prdEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recNde.refWzemMPeriod == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxfXnrActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxfIpActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxfStoActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxfPrtActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemNdeDetail::evalTxfOrnActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

