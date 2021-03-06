/**
	* \file WzemQUsrMNUsergroup.h
	* API code for table TblWzemQUsrMNUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSRMNUSERGROUP_H
#define WZEMQUSRMNUSERGROUP_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsrMNUsergroup
	*/
class WzemQUsrMNUsergroup {

public:
	WzemQUsrMNUsergroup(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWzemVUserlevel;
	std::string titIxWzemVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQUsrMNUsergroup
	*/
class ListWzemQUsrMNUsergroup {

public:
	ListWzemQUsrMNUsergroup();
	ListWzemQUsrMNUsergroup(const ListWzemQUsrMNUsergroup& src);
	ListWzemQUsrMNUsergroup& operator=(const ListWzemQUsrMNUsergroup& src);
	~ListWzemQUsrMNUsergroup();

	void clear();

public:
	std::vector<WzemQUsrMNUsergroup*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
