/**
	* \file VecWzemVTag.h
	* vector VecWzemVTag (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVTAG_H
#define VECWZEMVTAG_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVTag
	*/
namespace VecWzemVTag {
	const Sbecore::uint ABOUT = 1;
	const Sbecore::uint ALWAYS = 2;
	const Sbecore::uint CANCEL = 3;
	const Sbecore::uint CLOSE = 4;
	const Sbecore::uint CLSESS = 5;
	const Sbecore::uint CLUST = 6;
	const Sbecore::uint DETAIL = 7;
	const Sbecore::uint DONE = 8;
	const Sbecore::uint DOWNLOAD = 9;
	const Sbecore::uint EMPLONG = 10;
	const Sbecore::uint EMPSHORT = 11;
	const Sbecore::uint ERROR = 12;
	const Sbecore::uint FILENAME = 13;
	const Sbecore::uint FLS = 14;
	const Sbecore::uint GENERAL = 15;
	const Sbecore::uint GOTO = 16;
	const Sbecore::uint GRP = 17;
	const Sbecore::uint HELP = 18;
	const Sbecore::uint IMPERR = 19;
	const Sbecore::uint IMPORT = 20;
	const Sbecore::uint LOAINI = 21;
	const Sbecore::uint NAV = 22;
	const Sbecore::uint NO = 23;
	const Sbecore::uint OK = 24;
	const Sbecore::uint OPSCPLLAST = 25;
	const Sbecore::uint OPSPREP = 26;
	const Sbecore::uint OWN = 27;
	const Sbecore::uint PROGRESS = 28;
	const Sbecore::uint PRSERR = 29;
	const Sbecore::uint QUEST = 30;
	const Sbecore::uint REVERSE = 31;
	const Sbecore::uint RUN = 32;
	const Sbecore::uint SESS = 33;
	const Sbecore::uint SHOWLONG = 34;
	const Sbecore::uint SHOWSHORT = 35;
	const Sbecore::uint STOP = 36;
	const Sbecore::uint SUSPSESS = 37;
	const Sbecore::uint TRU = 38;
	const Sbecore::uint UPLOAD = 39;
	const Sbecore::uint YES = 40;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

