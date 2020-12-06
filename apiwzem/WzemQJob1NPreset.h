/**
	* \file WzemQJob1NPreset.h
	* API code for table TblWzemQJob1NPreset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQJOB1NPRESET_H
#define WZEMQJOB1NPRESET_H

#include <sbecore/Xmlio.h>

/**
	* WzemQJob1NPreset
	*/
class WzemQJob1NPreset {

public:
	WzemQJob1NPreset(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQJob1NPreset
	*/
class ListWzemQJob1NPreset {

public:
	ListWzemQJob1NPreset();
	ListWzemQJob1NPreset(const ListWzemQJob1NPreset& src);
	ListWzemQJob1NPreset& operator=(const ListWzemQJob1NPreset& src);
	~ListWzemQJob1NPreset();

	void clear();

public:
	std::vector<WzemQJob1NPreset*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
