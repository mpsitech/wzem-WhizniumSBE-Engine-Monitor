/**
	* \file WzemQPrsADetail.h
	* API code for table TblWzemQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRSADETAIL_H
#define WZEMQPRSADETAIL_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPrsADetail
	*/
class WzemQPrsADetail {

public:
	WzemQPrsADetail(const Sbecore::uint jnum = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::uint jnum;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPrsADetail
	*/
class ListWzemQPrsADetail {

public:
	ListWzemQPrsADetail();
	ListWzemQPrsADetail(const ListWzemQPrsADetail& src);
	ListWzemQPrsADetail& operator=(const ListWzemQPrsADetail& src);
	~ListWzemQPrsADetail();

	void clear();

public:
	std::vector<WzemQPrsADetail*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

