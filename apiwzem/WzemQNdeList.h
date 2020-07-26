/**
	* \file WzemQNdeList.h
	* API code for table TblWzemQNdeList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQNDELIST_H
#define WZEMQNDELIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQNdeList
	*/
class WzemQNdeList {

public:
	WzemQNdeList(const Sbecore::uint jnum = 0, const std::string stubRefWzemMPeriod = "", const Sbecore::ubigint xnref = 0, const std::string Ip = "", const double x1Startu = 0.0, const double x1Stopu = 0.0, const Sbecore::usmallint Port = 0, const Sbecore::utinyint Opprcn = 0);

public:
	Sbecore::uint jnum;
	std::string stubRefWzemMPeriod;
	Sbecore::ubigint xnref;
	std::string Ip;
	double x1Startu;
	double x1Stopu;
	Sbecore::usmallint Port;
	Sbecore::utinyint Opprcn;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQNdeList
	*/
class ListWzemQNdeList {

public:
	ListWzemQNdeList();
	ListWzemQNdeList(const ListWzemQNdeList& src);
	ListWzemQNdeList& operator=(const ListWzemQNdeList& src);
	~ListWzemQNdeList();

	void clear();

public:
	std::vector<WzemQNdeList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

