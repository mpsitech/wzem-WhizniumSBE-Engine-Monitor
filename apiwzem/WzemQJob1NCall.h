/**
	* \file WzemQJob1NCall.h
	* API code for table TblWzemQJob1NCall (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

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

