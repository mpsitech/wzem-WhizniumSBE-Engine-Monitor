/**
	* \file WzemQUsrList.h
	* API code for table TblWzemQUsrList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSRLIST_H
#define WZEMQUSRLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsrList
	*/
class WzemQUsrList {

public:
	WzemQUsrList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string stubRefWzemMPerson = "", const std::string sref = "", const std::string stubRefWzemMUsergroup = "", const std::string srefIxVState = "", const std::string titIxVState = "", const std::string srefIxWzemVLocale = "", const std::string titIxWzemVLocale = "", const std::string srefIxWzemVUserlevel = "", const std::string titIxWzemVUserlevel = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string stubRefWzemMPerson;
	std::string sref;
	std::string stubRefWzemMUsergroup;
	std::string srefIxVState;
	std::string titIxVState;
	std::string srefIxWzemVLocale;
	std::string titIxWzemVLocale;
	std::string srefIxWzemVUserlevel;
	std::string titIxWzemVUserlevel;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQUsrList
	*/
class ListWzemQUsrList {

public:
	ListWzemQUsrList();
	ListWzemQUsrList(const ListWzemQUsrList& src);
	ListWzemQUsrList& operator=(const ListWzemQUsrList& src);
	~ListWzemQUsrList();

	void clear();

public:
	std::vector<WzemQUsrList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
