/**
	* \file PnlWzemClnRec_evals.cpp
	* job handler for job PnlWzemClnRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemClnRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refCln()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFCLN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

