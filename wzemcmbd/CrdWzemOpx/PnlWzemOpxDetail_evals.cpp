/**
	* \file PnlWzemOpxDetail_evals.cpp
	* job handler for job PnlWzemOpxDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemOpxDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemOpxDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemOpxDetail::evalTxtJobActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemOpxDetail::evalButJobViewAvail(
			DbsWzem* dbswzem
		) {
	// opx.jobEq(0)|(pre.ixCrdaccJob())

	vector<bool> args;
	bool a, b;

	a = false; a = (recOpx.refWzemMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemOpxDetail::evalButJobViewActive(
			DbsWzem* dbswzem
		) {
	// !opx.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recOpx.refWzemMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemOpxDetail::evalTxfXorActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemOpxDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemOpxDetail::evalTxfStoActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCOPX, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

