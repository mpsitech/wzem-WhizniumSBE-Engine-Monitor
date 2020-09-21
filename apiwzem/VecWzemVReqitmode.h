/**
	* \file VecWzemVReqitmode.h
	* vector VecWzemVReqitmode (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
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

