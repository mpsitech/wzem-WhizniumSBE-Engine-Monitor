/**
	* \file VecWzemVReqitmode.h
	* vector VecWzemVReqitmode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

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







