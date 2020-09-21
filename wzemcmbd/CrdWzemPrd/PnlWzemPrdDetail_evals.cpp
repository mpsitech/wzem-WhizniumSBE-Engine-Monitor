/**
	* \file PnlWzemPrdDetail_evals.cpp
	* job handler for job PnlWzemPrdDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemPrdDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrdDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrdDetail::evalTxfVerActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrdDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrdDetail::evalTxfStoActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

