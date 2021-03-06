/**
	* \file WzemQUsrAAccess.h
	* API code for table TblWzemQUsrAAccess (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSRAACCESS_H
#define WZEMQUSRAACCESS_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsrAAccess
	*/
class WzemQUsrAAccess {

public:
	WzemQUsrAAccess(const Sbecore::uint jnum = 0, const std::string srefX1IxWzemVFeatgroup = "", const std::string titX1IxWzemVFeatgroup = "", const std::string x2FeaSrefUix = "", const std::string srefsIxWzemWAccess = "", const std::string titsIxWzemWAccess = "");

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
	* ListWzemQUsrAAccess
	*/
class ListWzemQUsrAAccess {

public:
	ListWzemQUsrAAccess();
	ListWzemQUsrAAccess(const ListWzemQUsrAAccess& src);
	ListWzemQUsrAAccess& operator=(const ListWzemQUsrAAccess& src);
	~ListWzemQUsrAAccess();

	void clear();

public:
	std::vector<WzemQUsrAAccess*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
