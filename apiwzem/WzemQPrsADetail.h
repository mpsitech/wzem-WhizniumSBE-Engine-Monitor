/**
	* \file WzemQPrsADetail.h
	* API code for table TblWzemQPrsADetail (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

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

