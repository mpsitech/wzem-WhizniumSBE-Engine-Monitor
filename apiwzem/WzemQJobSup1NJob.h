/**
	* \file WzemQJobSup1NJob.h
	* API code for table TblWzemQJobSup1NJob (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQJOBSUP1NJOB_H
#define WZEMQJOBSUP1NJOB_H

#include <sbecore/Xmlio.h>

/**
	* WzemQJobSup1NJob
	*/
class WzemQJobSup1NJob {

public:
	WzemQJobSup1NJob(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQJobSup1NJob
	*/
class ListWzemQJobSup1NJob {

public:
	ListWzemQJobSup1NJob();
	ListWzemQJobSup1NJob(const ListWzemQJobSup1NJob& src);
	ListWzemQJobSup1NJob& operator=(const ListWzemQJobSup1NJob& src);
	~ListWzemQJobSup1NJob();

	void clear();

public:
	std::vector<WzemQJobSup1NJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

