/**
	* \file WzemQUsr1NSession.h
	* API code for table TblWzemQUsr1NSession (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQUSR1NSESSION_H
#define WZEMQUSR1NSESSION_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsr1NSession
	*/
class WzemQUsr1NSession {

public:
	WzemQUsr1NSession(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQUsr1NSession
	*/
class ListWzemQUsr1NSession {

public:
	ListWzemQUsr1NSession();
	ListWzemQUsr1NSession(const ListWzemQUsr1NSession& src);
	ListWzemQUsr1NSession& operator=(const ListWzemQUsr1NSession& src);
	~ListWzemQUsr1NSession();

	void clear();

public:
	std::vector<WzemQUsr1NSession*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

