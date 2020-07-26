/**
	* \file PnlWzemUsgRec_evals.cpp
	* job handler for job PnlWzemUsgRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemUsgRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

