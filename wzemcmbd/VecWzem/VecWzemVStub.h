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
	const Sbecore::uint STUBWZEMJOBSTD = 1;
	const Sbecore::uint STUBWZEMJOBXJREF = 2;
	const Sbecore::uint STUBWZEMOPXSTD = 3;
	const Sbecore::uint STUBWZEMNDESTD = 4;
	const Sbecore::uint STUBWZEMNDEXNREF = 5;
	const Sbecore::uint STUBWZEMPRDSTD = 6;
	const Sbecore::uint STUBWZEMPRSSTD = 7;
	const Sbecore::uint STUBWZEMPSTSTD = 8;
	const Sbecore::uint STUBWZEMSESMENU = 9;
	const Sbecore::uint STUBWZEMSESSTD = 10;
	const Sbecore::uint STUBWZEMOWNER = 11;
	const Sbecore::uint STUBWZEMUSRSTD = 12;
	const Sbecore::uint STUBWZEMGROUP = 13;
	const Sbecore::uint STUBWZEMUSGSTD = 14;
	const Sbecore::uint STUBWZEMEVTSTD = 15;
	const Sbecore::uint STUBWZEMDCHSTD = 16;
	const Sbecore::uint STUBWZEMCLNSTD = 17;
	const Sbecore::uint STUBWZEMCALSTD = 18;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
