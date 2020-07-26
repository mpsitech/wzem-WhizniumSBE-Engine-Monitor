/**
	* \file WzemQUsgList.h
	* API code for table TblWzemQUsgList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQUSGLIST_H
#define WZEMQUSGLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQUsgList
	*/
class WzemQUsgList {

public:
	WzemQUsgList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string sref = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string sref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQUsgList
	*/
class ListWzemQUsgList {

public:
	ListWzemQUsgList();
	ListWzemQUsgList(const ListWzemQUsgList& src);
	ListWzemQUsgList& operator=(const ListWzemQUsgList& src);
	~ListWzemQUsgList();

	void clear();

public:
	std::vector<WzemQUsgList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

