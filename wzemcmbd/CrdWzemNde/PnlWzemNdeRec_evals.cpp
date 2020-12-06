/**
	* \file PnlWzemNdeRec_evals.cpp
	* job handler for job PnlWzemNdeRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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







