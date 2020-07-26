/**
	* \file VecWzemVOppack.h
	* vector VecWzemVOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVOPPACK_H
#define VECWZEMVOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVOppack
	*/
namespace VecWzemVOppack {

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
	std::string getComment(const Sbecore::uint ix);

	void appendToFeed(const Sbecore::uint ix, Sbecore::Xmlio::Feed& feed);
	void fillFeed(Sbecore::Xmlio::Feed& feed);
};

#endif

