/**
	* \file PnlWzemUsgRec_evals.cpp
	* job handler for job PnlWzemUsgRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

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
