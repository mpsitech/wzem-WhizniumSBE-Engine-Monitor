/**
	* \file WzemQPrdList.h
	* API code for table TblWzemQPrdList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRDLIST_H
#define WZEMQPRDLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPrdList
	*/
class WzemQPrdList {

public:
	WzemQPrdList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Version = "", const std::string ftmStart = "", const std::string ftmStop = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Version;
	std::string ftmStart;
	std::string ftmStop;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPrdList
	*/
class ListWzemQPrdList {

public:
	ListWzemQPrdList();
	ListWzemQPrdList(const ListWzemQPrdList& src);
	ListWzemQPrdList& operator=(const ListWzemQPrdList& src);
	~ListWzemQPrdList();

	void clear();

public:
	std::vector<WzemQPrdList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
