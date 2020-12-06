/**
	* \file WzemQPrd1NNode.h
	* API code for table TblWzemQPrd1NNode (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMQPRD1NNODE_H
#define WZEMQPRD1NNODE_H

#include <sbecore/Xmlio.h>

/**
	* WzemQPrd1NNode
	*/
class WzemQPrd1NNode {

public:
	WzemQPrd1NNode(const Sbecore::uint jnum = 0, const std::string stubRef = "");

public:
	Sbecore::uint jnum;
	std::string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQPrd1NNode
	*/
class ListWzemQPrd1NNode {

public:
	ListWzemQPrd1NNode();
	ListWzemQPrd1NNode(const ListWzemQPrd1NNode& src);
	ListWzemQPrd1NNode& operator=(const ListWzemQPrd1NNode& src);
	~ListWzemQPrd1NNode();

	void clear();

public:
	std::vector<WzemQPrd1NNode*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif
