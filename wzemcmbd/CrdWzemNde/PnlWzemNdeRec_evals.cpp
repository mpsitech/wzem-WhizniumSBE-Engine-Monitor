/**
	* \file PnlWzemNdeRec_evals.cpp
	* job handler for job PnlWzemNdeRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemNdeRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refNde()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFNDE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

