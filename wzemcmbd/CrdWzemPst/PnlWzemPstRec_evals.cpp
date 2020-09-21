/**
	* \file PnlWzemPstRec_evals.cpp
	* job handler for job PnlWzemPstRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemPstRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};
