/**
	* \file WzemQUsr1NSession.h
	* API code for table TblWzemQUsr1NSession (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

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

