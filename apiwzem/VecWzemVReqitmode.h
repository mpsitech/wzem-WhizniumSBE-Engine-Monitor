/**
	* \file VecWzemVReqitmode.h
	* vector VecWzemVReqitmode (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVREQITMODE_H
#define VECWZEMVREQITMODE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVReqitmode
	*/
namespace VecWzemVReqitmode {
	const Sbecore::uint IDLE = 1;
	const Sbecore::uint NOTIFY = 2;
	const Sbecore::uint POLL = 3;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

