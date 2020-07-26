/**
	* \file VecWzemVExpstate.h
	* vector VecWzemVExpstate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVEXPSTATE_H
#define VECWZEMVEXPSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVExpstate
	*/
namespace VecWzemVExpstate {
	const Sbecore::uint DETD = 1;
	const Sbecore::uint MAXD = 2;
	const Sbecore::uint MIND = 3;
	const Sbecore::uint REGD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

