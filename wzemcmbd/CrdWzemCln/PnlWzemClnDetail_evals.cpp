/**
	* \file PnlWzemClnDetail_evals.cpp
	* job handler for job PnlWzemClnDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemClnDetail::evalButSaveAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalButSaveActive(
			DbsWzem* dbswzem
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxtJobActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalButJobViewAvail(
			DbsWzem* dbswzem
		) {
	// cln.jobEq(0)|(pre.ixCrdaccJob())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCln.refWzemMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemClnDetail::evalButJobViewActive(
			DbsWzem* dbswzem
		) {
	// !cln.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCln.refWzemMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxfCalActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxfSgeActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxfStaActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxfStoActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalPupTrgActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalPupJmsActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxtTjbActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalButTjbViewAvail(
			DbsWzem* dbswzem
		) {
	// cln.tjbEq(0)|(pre.ixCrdaccJob())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCln.tjbRefWzemMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemClnDetail::evalButTjbViewActive(
			DbsWzem* dbswzem
		) {
	// !cln.tjbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCln.tjbRefWzemMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzemClnDetail::evalLstAmsActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalTxfArgActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemClnDetail::evalPupJatActive(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};







