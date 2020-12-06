/**
	* \file WzemQPrsList.h
	* API code for table TblWzemQPrsList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRSLIST_H
#define WZEMQPRSLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPrsList
	*/
class WzemQPrsList {

public:
	WzemQPrsList(const Sbecore::uint jnum = 0, const std::string stubGrp = "", const std::string stubOwn = "", const std::string Title = "", const std::string Firstname = "", const std::string Lastname = "", const std::string srefIxVSex = "", const std::string titIxVSex = "", const std::string telVal = "", const std::string emlVal = "");

public:
	Sbecore::uint jnum;
	std::string stubGrp;
	std::string stubOwn;
	std::string Title;
	std::string Firstname;
	std::string Lastname;
	std::string srefIxVSex;
	std::string titIxVSex;
	std::string telVal;
	std::string emlVal;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPrsList
	*/
class ListWzemQPrsList {

public:
	ListWzemQPrsList();
	ListWzemQPrsList(const ListWzemQPrsList& src);
	ListWzemQPrsList& operator=(const ListWzemQPrsList& src);
	~ListWzemQPrsList();

	void clear();

public:
	std::vector<WzemQPrsList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

