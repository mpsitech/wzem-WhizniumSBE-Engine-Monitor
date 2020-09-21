/**
	* \file PnlWzemPrsRec_evals.cpp
	* job handler for job PnlWzemPrsRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemPrsRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

