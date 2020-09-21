/**
	* \file PnlWzemEvtList_evals.cpp
	* job handler for job PnlWzemEvtList (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemEvtList::evalButDeleteActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

