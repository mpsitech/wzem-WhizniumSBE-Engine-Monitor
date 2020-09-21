/**
	* \file PnlWzemCalRec_evals.cpp
	* job handler for job PnlWzemCalRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemCalRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};
