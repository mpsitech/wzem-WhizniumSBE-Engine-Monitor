/**
	* \file WzemQPrd1NNode.h
	* API code for table TblWzemQPrd1NNode (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

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

