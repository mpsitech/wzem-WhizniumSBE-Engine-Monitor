/**
	* \file WzemQJob1NClstn.h
	* API code for table TblWzemQJob1NClstn (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOB1NCLSTN_H
#define WZEMQJOB1NCLSTN_H

#include <sbecore/Xmlio.h>

/**
	* WzemQJob1NClstn
	*/
class WzemQJob1NClstn {

public:
	WzemQJob1NClstn(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQJob1NClstn
	*/
class ListWzemQJob1NClstn {

public:
	ListWzemQJob1NClstn();
	ListWzemQJob1NClstn(const ListWzemQJob1NClstn& src);
	ListWzemQJob1NClstn& operator=(const ListWzemQJob1NClstn& src);
	~ListWzemQJob1NClstn();

	void clear();

public:
	std::vector<WzemQJob1NClstn*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
