/**
	* \file PnlWzemJob1NClstn_evals.cpp
	* job handler for job PnlWzemJob1NClstn (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzemJob1NClstn::evalButViewAvail(
			DbsWzem* dbswzem
		) {
	// !sel()|(pre.ixCrdaccCln()&pre.refPrd())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) != 0);
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

bool PnlWzemJob1NClstn::evalButViewActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButNewAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccClnIncl(edit)&pre.refPrd()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCCLN, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzemVPreset::PREWZEMREFPRD, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButDeleteAvail(
			DbsWzem* dbswzem
		) {
	// pre.ixCrdaccJobIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzemVPreset::PREWZEMIXCRDACCJOB, jref) & VecWzemWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzemJob1NClstn::evalButDeleteActive(
			DbsWzem* dbswzem
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
