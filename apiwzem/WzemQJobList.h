/**
	* \file WzemQJobList.h
	* API code for table TblWzemQJobList (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQJOBLIST_H
#define WZEMQJOBLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQJobList
	*/
class WzemQJobList {

public:
	WzemQJobList(const Sbecore::uint jnum = 0, const std::string stubRefWzemMPeriod = "", const std::string srefIxVJob = "", const Sbecore::ubigint xjref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0, const std::string stubSupRefWzemMJob = "");

public:
	Sbecore::uint jnum;
	std::string stubRefWzemMPeriod;
	std::string srefIxVJob;
	Sbecore::ubigint xjref;
	double x1Startu;
	double x1Stopu;
	std::string stubSupRefWzemMJob;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQJobList
	*/
class ListWzemQJobList {

public:
	ListWzemQJobList();
	ListWzemQJobList(const ListWzemQJobList& src);
	ListWzemQJobList& operator=(const ListWzemQJobList& src);
	~ListWzemQJobList();

	void clear();

public:
	std::vector<WzemQJobList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

