/**
	* \file WzemQEvtList.h
	* API code for table TblWzemQEvtList (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMQEVTLIST_H
#define WZEMQEVTLIST_H

#include <sbecore/Xmlio.h>

/**
	* WzemQEvtList
	*/
class WzemQEvtList {

public:
	WzemQEvtList(const Sbecore::uint jnum = 0, const std::string srefIxVBasetype = "", const std::string stubRefWzemMPeriod = "", const double startu = 0.0, const std::string Cmd = "", const std::string srefIxVFeatgroup = "", const std::string srefIxVMethod = "", const std::string xsref = "");

public:
	Sbecore::uint jnum;
	std::string srefIxVBasetype;
	std::string stubRefWzemMPeriod;
	double startu;
	std::string Cmd;
	std::string srefIxVFeatgroup;
	std::string srefIxVMethod;
	std::string xsref;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* ListWzemQEvtList
	*/
class ListWzemQEvtList {

public:
	ListWzemQEvtList();
	ListWzemQEvtList(const ListWzemQEvtList& src);
	ListWzemQEvtList& operator=(const ListWzemQEvtList& src);
	~ListWzemQEvtList();

	void clear();

public:
	std::vector<WzemQEvtList*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

#endif

