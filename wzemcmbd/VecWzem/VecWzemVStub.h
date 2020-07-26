/**
	* \file VecWzemVStub.h
	* vector VecWzemVStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVSTUB_H
#define VECWZEMVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVStub
	*/
namespace VecWzemVStub {
	const Sbecore::uint STUBWZEMEVTSTD = 1;
	const Sbecore::uint STUBWZEMJOBSTD = 2;
	const Sbecore::uint STUBWZEMJOBXJREF = 3;
	const Sbecore::uint STUBWZEMOPXSTD = 4;
	const Sbecore::uint STUBWZEMNDESTD = 5;
	const Sbecore::uint STUBWZEMNDEXNREF = 6;
	const Sbecore::uint STUBWZEMPRDSTD = 7;
	const Sbecore::uint STUBWZEMPRSSTD = 8;
	const Sbecore::uint STUBWZEMPSTSTD = 9;
	const Sbecore::uint STUBWZEMSESMENU = 10;
	const Sbecore::uint STUBWZEMSESSTD = 11;
	const Sbecore::uint STUBWZEMOWNER = 12;
	const Sbecore::uint STUBWZEMUSRSTD = 13;
	const Sbecore::uint STUBWZEMGROUP = 14;
	const Sbecore::uint STUBWZEMUSGSTD = 15;
	const Sbecore::uint STUBWZEMDCHSTD = 16;
	const Sbecore::uint STUBWZEMCLNSTD = 17;
	const Sbecore::uint STUBWZEMCALSTD = 18;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

