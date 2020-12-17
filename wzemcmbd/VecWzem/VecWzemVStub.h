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
	const Sbecore::uint STUBWZEMGROUP = 1;
	const Sbecore::uint STUBWZEMUSGSTD = 2;
	const Sbecore::uint STUBWZEMOWNER = 3;
	const Sbecore::uint STUBWZEMUSRSTD = 4;
	const Sbecore::uint STUBWZEMSESMENU = 5;
	const Sbecore::uint STUBWZEMSESSTD = 6;
	const Sbecore::uint STUBWZEMPSTSTD = 7;
	const Sbecore::uint STUBWZEMPRSSTD = 8;
	const Sbecore::uint STUBWZEMPRDSTD = 9;
	const Sbecore::uint STUBWZEMNDESTD = 10;
	const Sbecore::uint STUBWZEMNDEXNREF = 11;
	const Sbecore::uint STUBWZEMOPXSTD = 12;
	const Sbecore::uint STUBWZEMJOBSTD = 13;
	const Sbecore::uint STUBWZEMJOBXJREF = 14;
	const Sbecore::uint STUBWZEMEVTSTD = 15;
	const Sbecore::uint STUBWZEMDCHSTD = 16;
	const Sbecore::uint STUBWZEMCLNSTD = 17;
	const Sbecore::uint STUBWZEMCALSTD = 18;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
