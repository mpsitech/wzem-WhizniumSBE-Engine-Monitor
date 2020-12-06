/**
	* \file WzemQJob1NCall.h
	* API code for table TblWzemQJob1NCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOB1NCALL_H
#define WZEMQJOB1NCALL_H

#include <sbecore/Xmlio.h>

/**
	* WzemQJob1NCall
	*/
class WzemQJob1NCall {

public:
	WzemQJob1NCall(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQJob1NCall
	*/
class ListWzemQJob1NCall {

public:
	ListWzemQJob1NCall();
	ListWzemQJob1NCall(const ListWzemQJob1NCall& src);
	ListWzemQJob1NCall& operator=(const ListWzemQJob1NCall& src);
	~ListWzemQJob1NCall();

	void clear();

public:
	std::vector<WzemQJob1NCall*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
