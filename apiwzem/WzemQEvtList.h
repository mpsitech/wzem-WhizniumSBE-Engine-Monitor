/**
	* \file WzemQEvtList.h
	* API code for table TblWzemQEvtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

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

