/**
	* \file WzemQClnList.h
	* API code for table TblWzemQClnList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQCLNLIST_H
#define WZEMQCLNLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQClnList
	*/
class WzemQClnList {

public:
	WzemQClnList(const Sbecore::uint jnum = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const std::string srefIxVSge = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::uint jnum;
	std::string stubRefWzemMJob;
	std::string srefIxVCall;
	std::string srefIxVSge;
	double x1Startu;
	double x1Stopu;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQClnList
	*/
class ListWzemQClnList {

public:
	ListWzemQClnList();
	ListWzemQClnList(const ListWzemQClnList& src);
	ListWzemQClnList& operator=(const ListWzemQClnList& src);
	~ListWzemQClnList();

	void clear();

public:
	std::vector<WzemQClnList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

