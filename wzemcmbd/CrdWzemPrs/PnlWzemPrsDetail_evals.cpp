/**
	* \file PnlWzemPrsDetail_evals.cpp
	* job handler for job PnlWzemPrsDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemPrsDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalTxfTitActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalTxfFnmActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalPupJActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalButJEditAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalTxtLnmActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalLstDrvActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalPupSexActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalTxfTelActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalTxfEmlActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrsDetail::evalTxfSalActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRS, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

