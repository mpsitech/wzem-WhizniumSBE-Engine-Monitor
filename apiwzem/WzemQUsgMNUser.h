/**
	* \file WzemQUsgMNUser.h
	* API code for table TblWzemQUsgMNUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSGMNUSER_H
#define WZEMQUSGMNUSER_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsgMNUser
	*/
class WzemQUsgMNUser {

public:
	WzemQUsgMNUser(const Sbecore::uint jnum = 0, const std::string stubMref = "", const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubMref;
	std::string srefIxWzemVUserlevel;
	std::string titIxWzemVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQUsgMNUser
	*/
class ListWzemQUsgMNUser {

public:
	ListWzemQUsgMNUser();
	ListWzemQUsgMNUser(const ListWzemQUsgMNUser& src);
	ListWzemQUsgMNUser& operator=(const ListWzemQUsgMNUser& src);
	~ListWzemQUsgMNUser();

	void clear();

public:
	std::vector<WzemQUsgMNUser*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
