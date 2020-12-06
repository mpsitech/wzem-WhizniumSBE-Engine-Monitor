/**
	* \file WzemQJob1NOp.h
	* API code for table TblWzemQJob1NOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOB1NOP_H
#define WZEMQJOB1NOP_H

#include <sbecore/Xmlio.h>

/**
	* WzemQJob1NOp
	*/
class WzemQJob1NOp {

public:
	WzemQJob1NOp(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQJob1NOp
	*/
class ListWzemQJob1NOp {

public:
	ListWzemQJob1NOp();
	ListWzemQJob1NOp(const ListWzemQJob1NOp& src);
	ListWzemQJob1NOp& operator=(const ListWzemQJob1NOp& src);
	~ListWzemQJob1NOp();

	void clear();

public:
	std::vector<WzemQJob1NOp*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
