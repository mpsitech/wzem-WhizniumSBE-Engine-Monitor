/**
	* \file PnlWzemUsrRec_evals.cpp
	* job handler for job PnlWzemUsrRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

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

