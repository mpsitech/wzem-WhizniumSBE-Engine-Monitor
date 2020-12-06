/**
	* \file WzemQOpxList.h
	* API code for table TblWzemQOpxList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQOPXLIST_H
#define WZEMQOPXLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQOpxList
	*/
class WzemQOpxList {

public:
	WzemQOpxList(const Sbecore::uint jnum = 0, const std::string stubRefWzemMJob = "", const Sbecore::ubigint xoref = 0, const double x1Startu = 0.0, const double x1Stopu = 0.0);

public:
	Sbecore::uint jnum;
	std::string stubRefWzemMJob;
	Sbecore::ubigint xoref;
	double x1Startu;
	double x1Stopu;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQOpxList
	*/
class ListWzemQOpxList {

public:
	ListWzemQOpxList();
	ListWzemQOpxList(const ListWzemQOpxList& src);
	ListWzemQOpxList& operator=(const ListWzemQOpxList& src);
	~ListWzemQOpxList();

	void clear();

public:
	std::vector<WzemQOpxList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
