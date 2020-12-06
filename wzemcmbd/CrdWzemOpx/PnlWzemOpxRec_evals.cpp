/**
	* \file PnlWzemOpxRec_evals.cpp
	* job handler for job PnlWzemOpxRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemOpxRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};







