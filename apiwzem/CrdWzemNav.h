/**
	* \file CrdWzemNav.h
	* API code for job CrdWzemNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZEMNAV_H
#define CRDWZEMNAV_H

#include "ApiWzem_blks.h"

#define VecVWzemNavDo CrdWzemNav::VecVDo
#define VecVWzemNavSge CrdWzemNav::VecVSge

#define ContInfWzemNav CrdWzemNav::ContInf
#define StatAppWzemNav CrdWzemNav::StatApp
#define StatShrWzemNav CrdWzemNav::StatShr
#define TagWzemNav CrdWzemNav::Tag

#define DpchAppWzemNavDo CrdWzemNav::DpchAppDo
#define DpchEngWzemNavData CrdWzemNav::DpchEngData

/**
	* CrdWzemNav
	*/
namespace CrdWzemNav {
	/**
		* VecVDo (full: VecVWzemNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDPRDCLICK = 8;
		static const Sbecore::uint MITCRDEVTCLICK = 9;
		static const Sbecore::uint MITCRDJOBCLICK = 10;
		static const Sbecore::uint MITCRDCALCLICK = 11;
		static const Sbecore::uint MITCRDCLNCLICK = 12;
		static const Sbecore::uint MITCRDOPXCLICK = 13;
		static const Sbecore::uint MITCRDPSTCLICK = 14;
		static const Sbecore::uint MITCRDNDECLICK = 15;
		static const Sbecore::uint MITAPPLOICLICK = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzemNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZEMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemNav)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemNav)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZEMVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONEPRE = 6;
		static const Sbecore::uint INITDONEADMIN = 7;
		static const Sbecore::uint INITDONEMON = 8;

	public:
		StatApp(const Sbecore::uint ixWzemVReqitmode = VecWzemVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneMon = false);

	public:
		Sbecore::uint ixWzemVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneMon;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemNav)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFDLGLOAINI = 1;
		static const Sbecore::uint SCRJREFHEADBAR = 2;
		static const Sbecore::uint SCRJREFPRE = 3;
		static const Sbecore::uint PNLPREAVAIL = 4;
		static const Sbecore::uint SCRJREFADMIN = 5;
		static const Sbecore::uint PNLADMINAVAIL = 6;
		static const Sbecore::uint SCRJREFMON = 7;
		static const Sbecore::uint PNLMONAVAIL = 8;
		static const Sbecore::uint MITSESSPSAVAIL = 9;
		static const Sbecore::uint MSPCRD1AVAIL = 10;
		static const Sbecore::uint MITCRDUSGAVAIL = 11;
		static const Sbecore::uint MITCRDUSRAVAIL = 12;
		static const Sbecore::uint MITCRDPRSAVAIL = 13;
		static const Sbecore::uint MSPCRD2AVAIL = 14;
		static const Sbecore::uint MITCRDPRDAVAIL = 15;
		static const Sbecore::uint MITCRDEVTAVAIL = 16;
		static const Sbecore::uint MITCRDJOBAVAIL = 17;
		static const Sbecore::uint MITCRDCALAVAIL = 18;
		static const Sbecore::uint MITCRDCLNAVAIL = 19;
		static const Sbecore::uint MITCRDOPXAVAIL = 20;
		static const Sbecore::uint MITCRDPSTAVAIL = 21;
		static const Sbecore::uint MITCRDNDEAVAIL = 22;
		static const Sbecore::uint MSPAPP2AVAIL = 23;
		static const Sbecore::uint MITAPPLOIAVAIL = 24;

	public:
		StatShr(const std::string& scrJrefDlgloaini = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefPre = "", const bool pnlpreAvail = false, const std::string& scrJrefAdmin = "", const bool pnladminAvail = false, const std::string& scrJrefMon = "", const bool pnlmonAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MspCrd2Avail = true, const bool MitCrdPrdAvail = true, const bool MitCrdEvtAvail = true, const bool MitCrdJobAvail = true, const bool MitCrdCalAvail = true, const bool MitCrdClnAvail = true, const bool MitCrdOpxAvail = true, const bool MitCrdPstAvail = true, const bool MitCrdNdeAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		std::string scrJrefDlgloaini;
		std::string scrJrefHeadbar;
		std::string scrJrefPre;
		bool pnlpreAvail;
		std::string scrJrefAdmin;
		bool pnladminAvail;
		std::string scrJrefMon;
		bool pnlmonAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MspCrd2Avail;
		bool MitCrdPrdAvail;
		bool MitCrdEvtAvail;
		bool MitCrdJobAvail;
		bool MitCrdCalAvail;
		bool MitCrdClnAvail;
		bool MitCrdOpxAvail;
		bool MitCrdPstAvail;
		bool MitCrdNdeAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemNav)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITSESSPS = 3;
		static const Sbecore::uint MITSESTRM = 4;
		static const Sbecore::uint MITCRDUSG = 5;
		static const Sbecore::uint MITCRDUSR = 6;
		static const Sbecore::uint MITCRDPRS = 7;
		static const Sbecore::uint MITCRDPRD = 8;
		static const Sbecore::uint MITCRDEVT = 9;
		static const Sbecore::uint MITCRDJOB = 10;
		static const Sbecore::uint MITCRDCAL = 11;
		static const Sbecore::uint MITCRDCLN = 12;
		static const Sbecore::uint MITCRDOPX = 13;
		static const Sbecore::uint MITCRDPST = 14;
		static const Sbecore::uint MITCRDNDE = 15;
		static const Sbecore::uint MITAPPLOI = 16;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitSesSps = "", const std::string& MitSesTrm = "", const std::string& MitCrdUsg = "", const std::string& MitCrdUsr = "", const std::string& MitCrdPrs = "", const std::string& MitCrdPrd = "", const std::string& MitCrdEvt = "", const std::string& MitCrdJob = "", const std::string& MitCrdCal = "", const std::string& MitCrdCln = "", const std::string& MitCrdOpx = "", const std::string& MitCrdPst = "", const std::string& MitCrdNde = "", const std::string& MitAppLoi = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitSesSps;
		std::string MitSesTrm;
		std::string MitCrdUsg;
		std::string MitCrdUsr;
		std::string MitCrdPrs;
		std::string MitCrdPrd;
		std::string MitCrdEvt;
		std::string MitCrdJob;
		std::string MitCrdCal;
		std::string MitCrdCln;
		std::string MitCrdOpx;
		std::string MitCrdPst;
		std::string MitCrdNde;
		std::string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNavDo)
		*/
	class DpchAppDo : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWzemNavData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

