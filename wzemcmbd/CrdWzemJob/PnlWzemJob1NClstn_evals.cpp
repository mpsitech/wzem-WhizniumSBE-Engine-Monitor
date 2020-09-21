/**
	* \file PnlWzemJob1NClstn_evals.cpp
	* job handler for job PnlWzemJob1NClstn (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemJob1NClstn::evalButViewAvail(
			DbsWzem* dbswzem
		) {
	// !sel()|(pre.ixCrdaccCln())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButViewActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButNewAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButDeleteAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButDeleteActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

