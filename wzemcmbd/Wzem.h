/**
	* \file Wzem.h
	* Wzem global functionality (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEM_H
#define WZEM_H

#define WZEM_VERSION "0.9.19"
#define WZEM_VERSION_MAJOR 0
#define WZEM_VERSION_MINOR 9
#define WZEM_VERSION_SUB 19

// IP include.cust --- INSERT

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "VecWzemVCall.h"
#include "VecWzemVDpch.h"
#include "VecWzemVError.h"
#include "VecWzemVExpstate.h"
#include "VecWzemVIop.h"
#include "VecWzemVJob.h"
#include "VecWzemVMimetype.h"
#include "VecWzemVOpengtype.h"
#include "VecWzemVOppack.h"
#include "VecWzemVQrystate.h"
#include "VecWzemVReqitmode.h"
#include "VecWzemVStub.h"
#include "VecWzemVTag.h"

#include <DbsWzem.h>

#include <sbecore/Engtypes.h>
#include <sbecore/Stub.h>

/**
	* Lop
	*/
namespace Lop {
	void apply(const Sbecore::uint ixWzemVLop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);

	void insert(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
};

/**
	* Oolop
	*/
namespace Oolop {
	void apply(const Sbecore::uint ixWzemVOolop, std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);

	void insertBefore(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void insertAfter(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void remove(std::vector<Sbecore::ubigint>& refsList, std::vector<Sbecore::ubigint>& refsPool, const Sbecore::ubigint ref);
	void toBefore(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void toAfter(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
	void swap(std::vector<Sbecore::ubigint>& refsList, const Sbecore::ubigint ref1, const Sbecore::ubigint ref2);
};

/**
	* Tmp
	*/
namespace Tmp {
	std::string newfile(const std::string& tmppath, const std::string& ext);
	std::string newfolder(const std::string& tmppath);
	std::string random();
};

// IP cust --- INSERT

/**
	* Wzem
	*/
namespace Wzem {
	// IP gbl --- INSERT
};

/**
	* OpengWzem
	*/
namespace OpengWzem {
	void getIcsWzemVOppackByIxWzemVOpengtype(const Sbecore::uint ixWzemVOpengtype, std::vector<Sbecore::uint>& icsWzemVOppack);
	void getIcsWzemVDpchByIxWzemVOppack(const Sbecore::uint ixWzemVOppack, std::set<Sbecore::uint>& icsWzemVDpch);
};

/**
	* StubWzem
	*/
namespace StubWzem {
	std::string getStub(DbsWzem* dbswzem, const Sbecore::uint ixWzemVStub, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);

	std::string getStubCalStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubClnStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubDchStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubEvtStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubGroup(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubJobStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubJobXjref(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubNdeStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubNdeXnref(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOpxStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubOwner(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrdStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPrsStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubPstStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesMenu(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubSesStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsgStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
	std::string getStubUsrStd(DbsWzem* dbswzem, const Sbecore::ubigint ref, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS, const Sbecore::uint ixVNonetype = Sbecore::Stub::VecVNonetype::DASH, Sbecore::Stcch* stcch = NULL, Sbecore::stcchitemref_t* strefSub = NULL, const bool refresh = false);
};

/**
	* WzemException
	*/
class WzemException : public Sbecore::SbeException {

public:

public:
	WzemException(const Sbecore::uint ix, const std::map<std::string,std::string>& vals);

public:
	std::string getSref();
};

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
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
	* DpchInvWzem
	*/
class DpchInvWzem : public DpchWzem {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchInvWzem(const Sbecore::uint ixWzemVDpch = VecWzemVDpch::DPCHINVWZEM, const Sbecore::ubigint oref = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchInvWzem();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchRetWzem
	*/
class DpchRetWzem : public DpchWzem {

public:
	static const Sbecore::uint SCROREF = 1;
	static const Sbecore::uint OREF = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint IXOPVOPRES = 3;
	static const Sbecore::uint PDONE = 4;

public:
	DpchRetWzem(const Sbecore::uint ixWzemVDpch = VecWzemVDpch::DPCHRETWZEM, const std::string& scrOref = "", const std::string& scrJref = "", const Sbecore::utinyint ixOpVOpres = Sbecore::VecOpVOpres::PROGRESS, const Sbecore::utinyint pdone = 0);
	virtual ~DpchRetWzem();

public:
	std::string scrOref;
	Sbecore::ubigint oref;
	std::string scrJref;
	Sbecore::ubigint jref;
	Sbecore::utinyint ixOpVOpres;
	Sbecore::utinyint pdone;

public:
	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif

