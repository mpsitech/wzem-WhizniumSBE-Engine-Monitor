/**
	* \file PnlWzemUsrAAccess_evals.cpp
	* job handler for job PnlWzemUsrAAccess (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemUsrAAccess::evalButNewAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemUsrAAccess::evalButDuplicateAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemUsrAAccess::evalButDuplicateActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemUsrAAccess::evalButDeleteAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCUSR, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemUsrAAccess::evalButDeleteActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

