/**
	* \file WzemQUsrMNUsergroup.h
	* API code for table TblWzemQUsrMNUsergroup (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

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

