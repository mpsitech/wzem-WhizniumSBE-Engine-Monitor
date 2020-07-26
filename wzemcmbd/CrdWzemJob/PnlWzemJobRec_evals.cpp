/**
	* \file PnlWzemJobRec_evals.cpp
	* job handler for job PnlWzemJobRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemJobRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

