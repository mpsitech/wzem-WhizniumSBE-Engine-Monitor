/**
	* \file VecWzemVIop.h
	* vector VecWzemVIop (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef VECWZEMVIOP_H
#define VECWZEMVIOP_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVIop
	*/
namespace VecWzemVIop {
	const Sbecore::uint INS = 1;
	const Sbecore::uint RETR = 2;
	const Sbecore::uint RETRINS = 3;
	const Sbecore::uint RETRUPD = 4;
	const Sbecore::uint RETRUPDINS = 5;
	const Sbecore::uint RMV = 6;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

	void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

