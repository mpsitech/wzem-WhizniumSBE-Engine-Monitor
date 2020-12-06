/**
	* \file WzemQUsgAAccess.h
	* API code for table TblWzemQUsgAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSGAACCESS_H
#define WZEMQUSGAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsgAAccess
	*/
class WzemQUsgAAccess {

public:
	WzemQUsgAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");

public:
	Sbecore::uint jnum;
	std::string srefX1IxWzemVFeatgroup;
	std::string titX1IxWzemVFeatgroup;
	std::string x2FeaSrefUix;
	std::string srefsIxWzemWAccess;
	std::string titsIxWzemWAccess;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQUsgAAccess
	*/
class ListWzemQUsgAAccess {

public:
	ListWzemQUsgAAccess();
	ListWzemQUsgAAccess(const ListWzemQUsgAAccess& src);
	ListWzemQUsgAAccess& operator=(const ListWzemQUsgAAccess& src);
	~ListWzemQUsgAAccess();

	void clear();

public:
	std::vector<WzemQUsgAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

