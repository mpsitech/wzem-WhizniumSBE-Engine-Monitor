/**
	* \file PnlWzemOpxRec_evals.cpp
	* job handler for job PnlWzemOpxRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemOpxRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

