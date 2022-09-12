/**
	* \file PnlWzemPrd1NNode_evals.cpp
	* job handler for job PnlWzemPrd1NNode (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemPrd1NNode::evalButViewAvail(
			DbsWzem* dbswzem
		) {
	// !sel()|(pre.ixCrdaccNde()&pre.refPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzemPrd1NNode::evalButViewActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrd1NNode::evalButNewAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccNdeIncl(edit)&pre.refPrd()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCNDE, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWzemPrd1NNode::evalButDeleteAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccPrdIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCPRD, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemPrd1NNode::evalButDeleteActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
