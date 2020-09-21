/**
	* \file WzemQCalList.h
	* API code for table TblWzemQCalList (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQCALLIST_H
#define WZEMQCALLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQCalList
	*/
class WzemQCalList {

public:
	WzemQCalList(const Sbecore::uint jnum = 0, const std::string stubRefWzemMJob = "", const std::string srefIxVCall = "", const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::uint jnum;
	std::string stubRefWzemMJob;
	std::string srefIxVCall;
	double x1Startu;
	double x1Stopu;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQCalList
	*/
class ListWzemQCalList {

public:
	ListWzemQCalList();
	ListWzemQCalList(const ListWzemQCalList& src);
	ListWzemQCalList& operator=(const ListWzemQCalList& src);
	~ListWzemQCalList();

	void clear();

public:
	std::vector<WzemQCalList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

