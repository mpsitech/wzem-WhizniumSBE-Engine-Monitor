/**
	* \file SessWzem.h
	* job handler for job SessWzem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef SESSWZEM_H
#define SESSWZEM_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "CrdWzemNde.h"
#include "CrdWzemPst.h"
#include "CrdWzemOpx.h"
#include "CrdWzemCln.h"
#include "CrdWzemCal.h"
#include "CrdWzemJob.h"
#include "CrdWzemEvt.h"
#include "CrdWzemPrd.h"
#include "CrdWzemNav.h"
#include "CrdWzemPrs.h"
#include "CrdWzemUsr.h"
#include "CrdWzemUsg.h"

#define StatShrSessWzem SessWzem::StatShr

#define DpchEngSessWzemData SessWzem::DpchEngData

/**
	* SessWzem
	*/
class SessWzem : public JobWzem {

public:
	/**
		* StatShr (full: StatShrSessWzem)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFCRDNAV = 1;

	public:
		StatShr(const Sbecore::ubigint jrefCrdnav = 0);

	public:
		Sbecore::ubigint jrefCrdnav;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWzemData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

public:
	SessWzem(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWzemMUser, const std::string& ip);
	~SessWzem();

public:
	StatShr statshr;

	std::list<CrdWzemNde*> crdndes;
	std::list<CrdWzemPst*> crdpsts;
	std::list<CrdWzemOpx*> crdopxs;
	std::list<CrdWzemCln*> crdclns;
	std::list<CrdWzemCal*> crdcals;
	std::list<CrdWzemJob*> crdjobs;
	std::list<CrdWzemEvt*> crdevts;
	std::list<CrdWzemPrd*> crdprds;
	CrdWzemNav* crdnav;
	std::list<CrdWzemPrs*> crdprss;
	std::list<CrdWzemUsr*> crdusrs;
	std::list<CrdWzemUsg*> crdusgs;

	std::map<Sbecore::ubigint,Sbecore::uint> usgaccs;

	std::map<Sbecore::ubigint,std::string> scr;
	std::map<std::string,Sbecore::ubigint> descr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void warnTerm(DbsWzem* dbswzem);
	void term(DbsWzem* dbswzem);

	Sbecore::uint checkCrdActive(const Sbecore::uint ixWzemVCard);

	Sbecore::uint checkCrdaccess(const Sbecore::uint ixWzemVCard);
	void getIxCrdacc(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCard, const bool adm, ListWzemRMUserMUsergroup& urus, const Sbecore::ubigint refWzemMUser, Sbecore::uint& ixWzemWAccess);

	Sbecore::uint checkRecaccess(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCard, const Sbecore::ubigint ref);
	void logRecaccess(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint preUref, const Sbecore::uint ixWzemVCard, const Sbecore::ubigint unvUref);

	Sbecore::uint crdToMtb(const Sbecore::uint ixWzemVCard);
	Sbecore::uint preToMtb(const Sbecore::uint ixWzemVPreset);
	bool hasActive(const Sbecore::uint ixWzemVCard);
	bool hasGrpown(const Sbecore::uint ixWzemVMaintable);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:
	bool handleCreateCrdcal(DbsWzem* dbswzem);
	bool handleCreateCrdcln(DbsWzem* dbswzem);
	bool handleCreateCrdevt(DbsWzem* dbswzem);
	bool handleCreateCrdjob(DbsWzem* dbswzem);
	bool handleCreateCrdnde(DbsWzem* dbswzem);
	bool handleCreateCrdopx(DbsWzem* dbswzem);
	bool handleCreateCrdprd(DbsWzem* dbswzem);
	bool handleCreateCrdprs(DbsWzem* dbswzem);
	bool handleCreateCrdpst(DbsWzem* dbswzem);
	bool handleCreateCrdusg(DbsWzem* dbswzem);
	bool handleCreateCrdusr(DbsWzem* dbswzem);
	bool handleEraseCrdcal(DbsWzem* dbswzem);
	bool handleEraseCrdcln(DbsWzem* dbswzem);
	bool handleEraseCrdevt(DbsWzem* dbswzem);
	bool handleEraseCrdjob(DbsWzem* dbswzem);
	bool handleEraseCrdnde(DbsWzem* dbswzem);
	bool handleEraseCrdopx(DbsWzem* dbswzem);
	bool handleEraseCrdprd(DbsWzem* dbswzem);
	bool handleEraseCrdprs(DbsWzem* dbswzem);
	bool handleEraseCrdpst(DbsWzem* dbswzem);
	bool handleEraseCrdusg(DbsWzem* dbswzem);
	bool handleEraseCrdusr(DbsWzem* dbswzem);

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemRefPreSet(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWzemCrdActive(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, Sbecore::uint& ixRet);
	bool handleCallWzemRecaccess(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool handleCallWzemLog(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool handleCallWzemCrdOpen(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool handleCallWzemCrdClose(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);

};

#endif
