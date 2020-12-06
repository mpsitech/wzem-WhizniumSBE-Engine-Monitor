/**
	* \file PnlWzemClnRec_evals.cpp
	* job handler for job PnlWzemClnRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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







