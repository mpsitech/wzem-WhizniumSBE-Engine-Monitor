/**
	* \file VecWzemVStub.h
	* vector VecWzemVStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZEMVSTUB_H
#define VECWZEMVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVStub
	*/
namespace VecWzemVStub {
	const Sbecore::uint STUBWZEMCALSTD = 1;
	const Sbecore::uint STUBWZEMCLNSTD = 2;
	const Sbecore::uint STUBWZEMDCHSTD = 3;
	const Sbecore::uint STUBWZEMEVTSTD = 4;
	const Sbecore::uint STUBWZEMJOBSTD = 5;
	const Sbecore::uint STUBWZEMJOBXJREF = 6;
	const Sbecore::uint STUBWZEMOPXSTD = 7;
	const Sbecore::uint STUBWZEMNDESTD = 8;
	const Sbecore::uint STUBWZEMNDEXNREF = 9;
	const Sbecore::uint STUBWZEMPRDSTD = 10;
	const Sbecore::uint STUBWZEMPRSSTD = 11;
	const Sbecore::uint STUBWZEMPSTSTD = 12;
	const Sbecore::uint STUBWZEMSESMENU = 13;
	const Sbecore::uint STUBWZEMSESSTD = 14;
	const Sbecore::uint STUBWZEMOWNER = 15;
	const Sbecore::uint STUBWZEMUSRSTD = 16;
	const Sbecore::uint STUBWZEMGROUP = 17;
	const Sbecore::uint STUBWZEMUSGSTD = 18;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
