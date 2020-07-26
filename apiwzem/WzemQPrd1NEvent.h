/**
	* \file WzemQPrd1NEvent.h
	* API code for table TblWzemQPrd1NEvent (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

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

