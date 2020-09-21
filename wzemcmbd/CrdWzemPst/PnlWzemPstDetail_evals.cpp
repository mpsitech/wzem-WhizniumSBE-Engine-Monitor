/**
	* \file PnlWzemPstDetail_evals.cpp
	* job handler for job PnlWzemPstDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemPstDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPstDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPstDetail::evalTxtJobActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPstDetail::evalButJobViewAvail(
			DbsWzem* dbswzem
		) {
	// pst.jobEq(0)|(pre.ixCrdaccJob())

	vector<bool> args;
	bool a, b;

	a = false; a = (recPst.refWzemMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemPstDetail::evalButJobViewActive(
			DbsWzem* dbswzem
		) {
	// !pst.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPst.refWzemMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemPstDetail::evalTxfPstActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPstDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPstDetail::evalTxfStoActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPstDetail::evalTxfArgActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPST, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

