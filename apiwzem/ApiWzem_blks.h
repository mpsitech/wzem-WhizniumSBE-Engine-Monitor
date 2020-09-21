/**
	* \file ApiWzem_blks.h
	* Wzem API library global data blocks (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef APIWZEM_BLKS_H
#define APIWZEM_BLKS_H

#include "VecWzemVExpstate.h"
#include "VecWzemVReqitmode.h"

#include "VecWzemVDpch.h"

/**
	* ContInfWzemAlert
	*/
class ContInfWzemAlert : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint TXTCPT = 1;
	static const Sbecore::uint TXTMSG1 = 2;
	static const Sbecore::uint TXTMSG2 = 3;
	static const Sbecore::uint TXTMSG3 = 4;
	static const Sbecore::uint TXTMSG4 = 5;
	static const Sbecore::uint TXTMSG5 = 6;
	static const Sbecore::uint TXTMSG6 = 7;
	static const Sbecore::uint TXTMSG7 = 8;
	static const Sbecore::uint TXTMSG8 = 9;
	static const Sbecore::uint TXTMSG9 = 10;
	static const Sbecore::uint TXTMSG10 = 11;
	static const Sbecore::uint TXTMSG11 = 12;
	static const Sbecore::uint TXTMSG12 = 13;

public:
	ContInfWzemAlert(const std::string& TxtCpt = "", const std::string& TxtMsg1 = "", const std::string& TxtMsg2 = "", const std::string& TxtMsg3 = "", const std::string& TxtMsg4 = "", const std::string& TxtMsg5 = "", const std::string& TxtMsg6 = "", const std::string& TxtMsg7 = "", const std::string& TxtMsg8 = "", const std::string& TxtMsg9 = "", const std::string& TxtMsg10 = "", const std::string& TxtMsg11 = "", const std::string& TxtMsg12 = "");

public:
	std::string TxtCpt;
	std::string TxtMsg1;
	std::string TxtMsg2;
	std::string TxtMsg3;
	std::string TxtMsg4;
	std::string TxtMsg5;
	std::string TxtMsg6;
	std::string TxtMsg7;
	std::string TxtMsg8;
	std::string TxtMsg9;
	std::string TxtMsg10;
	std::string TxtMsg11;
	std::string TxtMsg12;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	std::set<Sbecore::uint> compare(const ContInfWzemAlert* comp);
};

/**
	* DpchWzem
	*/
class DpchWzem : public Sbecore::Xmlio::Block {

public:
	DpchWzem(const Sbecore::uint ixWzemVDpch = 0);
	virtual ~DpchWzem();

public:
	Sbecore::uint ixWzemVDpch;
};

/**
	* DpchAppWzem
	*/
class DpchAppWzem : public DpchWzem {

public:
	static const Sbecore::uint SCRJREF = 1;

public:
	DpchAppWzem(const Sbecore::uint ixWzemVDpch = 0, const std::string& scrJref = "");
	virtual ~DpchAppWzem();

public:
	std::string scrJref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppWzemAlert
	*/
class DpchAppWzemAlert : public DpchAppWzem {

public:
	static const Sbecore::uint SCRJREF = 1;
	static const Sbecore::uint NUMFMCB = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchAppWzemAlert(const std::string& scrJref = "", const Sbecore::uint numFMcb = 0, const std::set<Sbecore::uint>& mask = {NONE});

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppWzemInit
	*/
class DpchAppWzemInit : public DpchAppWzem {

public:
	DpchAppWzemInit(const std::string& scrJref = "");
};

/**
	* DpchAppWzemResume
	*/
class DpchAppWzemResume : public DpchAppWzem {

public:
	DpchAppWzemResume(const std::string& scrJref = "");
};

/**
	* DpchEngWzem
	*/
class DpchEngWzem : public DpchWzem {

public:
	static const Sbecore::uint SCRJREF = 1;

public:
	DpchEngWzem(const Sbecore::uint ixWzemVDpch = 0);
	virtual ~DpchEngWzem();

public:
	std::string scrJref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWzemAck
	*/
class DpchEngWzemAck : public DpchEngWzem {

public:
	DpchEngWzemAck();
};

/**
	* DpchEngWzemAlert
	*/
class DpchEngWzemAlert : public DpchEngWzem {

public:
	static const Sbecore::uint SCRJREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;

public:
	DpchEngWzemAlert();

public:
	ContInfWzemAlert continf;
	Sbecore::Xmlio::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWzemConfirm
	*/
class DpchEngWzemConfirm : public DpchEngWzem {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint SREF = 3;

public:
	DpchEngWzemConfirm();

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWzemSuspend
	*/
class DpchEngWzemSuspend : public DpchEngWzem {

public:
	DpchEngWzemSuspend();
};

#endif

