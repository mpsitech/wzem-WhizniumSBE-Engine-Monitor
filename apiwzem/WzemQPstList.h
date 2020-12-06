/**
	* \file WzemQPstList.h
	* API code for table TblWzemQPstList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPSTLIST_H
#define WZEMQPSTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPstList
	*/
class WzemQPstList {

public:
	WzemQPstList(const Sbecore::uint jnum = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVPreset = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::uint jnum;
	std::string stubRefWzemMJob;
	std::string srefIxVPreset;
	double x1Startu;
	double x1Stopu;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPstList
	*/
class ListWzemQPstList {

public:
	ListWzemQPstList();
	ListWzemQPstList(const ListWzemQPstList& src);
	ListWzemQPstList& operator=(const ListWzemQPstList& src);
	~ListWzemQPstList();

	void clear();

public:
	std::vector<WzemQPstList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
