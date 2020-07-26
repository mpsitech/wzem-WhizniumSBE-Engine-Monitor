/**
	* \file WzemQPrd1NJob.h
	* API code for table TblWzemQPrd1NJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMQPRD1NJOB_H
#define WZEMQPRD1NJOB_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPrd1NJob
	*/
class WzemQPrd1NJob {

public:
	WzemQPrd1NJob(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPrd1NJob
	*/
class ListWzemQPrd1NJob {

public:
	ListWzemQPrd1NJob();
	ListWzemQPrd1NJob(const ListWzemQPrd1NJob& src);
	ListWzemQPrd1NJob& operator=(const ListWzemQPrd1NJob& src);
	~ListWzemQPrd1NJob();

	void clear();

public:
	std::vector<WzemQPrd1NJob*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

