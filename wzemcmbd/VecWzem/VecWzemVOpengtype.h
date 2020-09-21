/**
	* \file VecWzemVOpengtype.h
	* vector VecWzemVOpengtype (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef VECWZEMVOPENGTYPE_H
#define VECWZEMVOPENGTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVOpengtype
	*/
namespace VecWzemVOpengtype {

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

