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
	const Sbecore::uint STUBWZEMGROUP = 2;
	const Sbecore::uint STUBWZEMUSGSTD = 3;
	const Sbecore::uint STUBWZEMOWNER = 4;
	const Sbecore::uint STUBWZEMUSRSTD = 5;
	const Sbecore::uint STUBWZEMSESMENU = 6;
	const Sbecore::uint STUBWZEMSESSTD = 7;
	const Sbecore::uint STUBWZEMPSTSTD = 8;
	const Sbecore::uint STUBWZEMPRSSTD = 9;
	const Sbecore::uint STUBWZEMPRDSTD = 10;
	const Sbecore::uint STUBWZEMNDESTD = 11;
	const Sbecore::uint STUBWZEMNDEXNREF = 12;
	const Sbecore::uint STUBWZEMOPXSTD = 13;
	const Sbecore::uint STUBWZEMJOBSTD = 14;
	const Sbecore::uint STUBWZEMJOBXJREF = 15;
	const Sbecore::uint STUBWZEMEVTSTD = 16;
	const Sbecore::uint STUBWZEMDCHSTD = 17;
	const Sbecore::uint STUBWZEMCLNSTD = 18;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif







