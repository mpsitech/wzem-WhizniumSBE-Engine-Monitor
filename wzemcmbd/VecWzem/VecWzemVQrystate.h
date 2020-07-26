/**
	* \file VecWzemVQrystate.h
	* vector VecWzemVQrystate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVQRYSTATE_H
#define VECWZEMVQRYSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVQrystate
	*/
namespace VecWzemVQrystate {
	const Sbecore::uint MNR = 1;
	const Sbecore::uint OOD = 2;
	const Sbecore::uint SLM = 3;
	const Sbecore::uint UTD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

	void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

