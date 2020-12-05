/**
	* \file WzemQPrd1NEvent.h
	* API code for table TblWzemQPrd1NEvent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRD1NEVENT_H
#define WZEMQPRD1NEVENT_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPrd1NEvent
	*/
class WzemQPrd1NEvent {

public:
	WzemQPrd1NEvent(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPrd1NEvent
	*/
class ListWzemQPrd1NEvent {

public:
	ListWzemQPrd1NEvent();
	ListWzemQPrd1NEvent(const ListWzemQPrd1NEvent& src);
	ListWzemQPrd1NEvent& operator=(const ListWzemQPrd1NEvent& src);
	~ListWzemQPrd1NEvent();

	void clear();

public:
	std::vector<WzemQPrd1NEvent*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

