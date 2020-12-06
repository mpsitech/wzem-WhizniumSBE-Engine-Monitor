/**
	* \file VecWzemVOpengtype.h
	* vector VecWzemVOpengtype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

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







