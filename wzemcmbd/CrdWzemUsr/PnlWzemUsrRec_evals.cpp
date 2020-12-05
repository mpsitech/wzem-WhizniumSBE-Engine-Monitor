/**
	* \file PnlWzemUsrRec_evals.cpp
	* job handler for job PnlWzemUsrRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemUsrRec::evalButRegularizeActive(
			DbsWzem* dbswzem
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

