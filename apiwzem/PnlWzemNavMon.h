/**
	* \file PnlWzemNavMon.h
	* API code for job PnlWzemNavMon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNAVMON_H
#define PNLWZEMNAVMON_H

#include "ApiWzem_blks.h"

#define VecVWzemNavMonDo PnlWzemNavMon::VecVDo

#define ContIacWzemNavMon PnlWzemNavMon::ContIac
#define StatAppWzemNavMon PnlWzemNavMon::StatApp
#define StatShrWzemNavMon PnlWzemNavMon::StatShr
#define TagWzemNavMon PnlWzemNavMon::Tag

#define DpchAppWzemNavMonData PnlWzemNavMon::DpchAppData
#define DpchAppWzemNavMonDo PnlWzemNavMon::DpchAppDo
#define DpchEngWzemNavMonData PnlWzemNavMon::DpchEngData

/**
	* PnlWzemNavMon
	*/
namespace PnlWzemNavMon {
	/**
		* VecVDo (full: VecVWzemNavMonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRDVIEWCLICK = 1;
		static const Sbecore::uint BUTPRDNEWCRDCLICK = 2;
		static const Sbecore::uint BUTEVTVIEWCLICK = 3;
		static const Sbecore::uint BUTEVTNEWCRDCLICK = 4;
		static const Sbecore::uint BUTJOBVIEWCLICK = 5;
		static const Sbecore::uint BUTJOBNEWCRDCLICK = 6;
		static const Sbecore::uint BUTCALVIEWCLICK = 7;
		static const Sbecore::uint BUTCALNEWCRDCLICK = 8;
		static const Sbecore::uint BUTCLNVIEWCLICK = 9;
		static const Sbecore::uint BUTCLNNEWCRDCLICK = 10;
		static const Sbecore::uint BUTOPXVIEWCLICK = 11;
		static const Sbecore::uint BUTOPXNEWCRDCLICK = 12;
		static const Sbecore::uint BUTPSTVIEWCLICK = 13;
		static const Sbecore::uint BUTPSTNEWCRDCLICK = 14;
		static const Sbecore::uint BUTNDEVIEWCLICK = 15;
		static const Sbecore::uint BUTNDENEWCRDCLICK = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemNavMon)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTPRD = 1;
		static const Sbecore::uint NUMFLSTEVT = 2;
		static const Sbecore::uint NUMFLSTJOB = 3;
		static const Sbecore::uint NUMFLSTCAL = 4;
		static const Sbecore::uint NUMFLSTCLN = 5;
		static const Sbecore::uint NUMFLSTOPX = 6;
		static const Sbecore::uint NUMFLSTPST = 7;
		static const Sbecore::uint NUMFLSTNDE = 8;

	public:
		ContIac(const Sbecore::uint numFLstPrd = 1, const Sbecore::uint numFLstEvt = 1, const Sbecore::uint numFLstJob = 1, const Sbecore::uint numFLstCal = 1, const Sbecore::uint numFLstCln = 1, const Sbecore::uint numFLstOpx = 1, const Sbecore::uint numFLstPst = 1, const Sbecore::uint numFLstNde = 1);

	public:
		Sbecore::uint numFLstPrd;
		Sbecore::uint numFLstEvt;
		Sbecore::uint numFLstJob;
		Sbecore::uint numFLstCal;
		Sbecore::uint numFLstCln;
		Sbecore::uint numFLstOpx;
		Sbecore::uint numFLstPst;
		Sbecore::uint numFLstNde;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWzemNavMon)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint LSTPRDALT = 2;
		static const Sbecore::uint LSTEVTALT = 3;
		static const Sbecore::uint LSTJOBALT = 4;
		static const Sbecore::uint LSTCALALT = 5;
		static const Sbecore::uint LSTCLNALT = 6;
		static const Sbecore::uint LSTOPXALT = 7;
		static const Sbecore::uint LSTPSTALT = 8;
		static const Sbecore::uint LSTNDEALT = 9;
		static const Sbecore::uint LSTPRDNUMFIRSTDISP = 10;
		static const Sbecore::uint LSTEVTNUMFIRSTDISP = 11;
		static const Sbecore::uint LSTJOBNUMFIRSTDISP = 12;
		static const Sbecore::uint LSTCALNUMFIRSTDISP = 13;
		static const Sbecore::uint LSTCLNNUMFIRSTDISP = 14;
		static const Sbecore::uint LSTOPXNUMFIRSTDISP = 15;
		static const Sbecore::uint LSTPSTNUMFIRSTDISP = 16;
		static const Sbecore::uint LSTNDENUMFIRSTDISP = 17;

	public:
		StatApp(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstPrdAlt = true, const bool LstEvtAlt = true, const bool LstJobAlt = true, const bool LstCalAlt = true, const bool LstClnAlt = true, const bool LstOpxAlt = true, const bool LstPstAlt = true, const bool LstNdeAlt = true, const Sbecore::uint LstPrdNumFirstdisp = 1, const Sbecore::uint LstEvtNumFirstdisp = 1, const Sbecore::uint LstJobNumFirstdisp = 1, const Sbecore::uint LstCalNumFirstdisp = 1, const Sbecore::uint LstClnNumFirstdisp = 1, const Sbecore::uint LstOpxNumFirstdisp = 1, const Sbecore::uint LstPstNumFirstdisp = 1, const Sbecore::uint LstNdeNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzemVExpstate;
		bool LstPrdAlt;
		bool LstEvtAlt;
		bool LstJobAlt;
		bool LstCalAlt;
		bool LstClnAlt;
		bool LstOpxAlt;
		bool LstPstAlt;
		bool LstNdeAlt;
		Sbecore::uint LstPrdNumFirstdisp;
		Sbecore::uint LstEvtNumFirstdisp;
		Sbecore::uint LstJobNumFirstdisp;
		Sbecore::uint LstCalNumFirstdisp;
		Sbecore::uint LstClnNumFirstdisp;
		Sbecore::uint LstOpxNumFirstdisp;
		Sbecore::uint LstPstNumFirstdisp;
		Sbecore::uint LstNdeNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemNavMon)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTPRDAVAIL = 1;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 2;
		static const Sbecore::uint LSTEVTAVAIL = 3;
		static const Sbecore::uint BUTEVTVIEWACTIVE = 4;
		static const Sbecore::uint LSTJOBAVAIL = 5;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 6;
		static const Sbecore::uint LSTCALAVAIL = 7;
		static const Sbecore::uint BUTCALVIEWACTIVE = 8;
		static const Sbecore::uint LSTCLNAVAIL = 9;
		static const Sbecore::uint BUTCLNVIEWACTIVE = 10;
		static const Sbecore::uint LSTOPXAVAIL = 11;
		static const Sbecore::uint BUTOPXVIEWACTIVE = 12;
		static const Sbecore::uint LSTPSTAVAIL = 13;
		static const Sbecore::uint BUTPSTVIEWACTIVE = 14;
		static const Sbecore::uint LSTNDEAVAIL = 15;
		static const Sbecore::uint BUTNDEVIEWACTIVE = 16;

	public:
		StatShr(const bool LstPrdAvail = true, const bool ButPrdViewActive = true, const bool LstEvtAvail = true, const bool ButEvtViewActive = true, const bool LstJobAvail = true, const bool ButJobViewActive = true, const bool LstCalAvail = true, const bool ButCalViewActive = true, const bool LstClnAvail = true, const bool ButClnViewActive = true, const bool LstOpxAvail = true, const bool ButOpxViewActive = true, const bool LstPstAvail = true, const bool ButPstViewActive = true, const bool LstNdeAvail = true, const bool ButNdeViewActive = true);

	public:
		bool LstPrdAvail;
		bool ButPrdViewActive;
		bool LstEvtAvail;
		bool ButEvtViewActive;
		bool LstJobAvail;
		bool ButJobViewActive;
		bool LstCalAvail;
		bool ButCalViewActive;
		bool LstClnAvail;
		bool ButClnViewActive;
		bool LstOpxAvail;
		bool ButOpxViewActive;
		bool LstPstAvail;
		bool ButPstViewActive;
		bool LstNdeAvail;
		bool ButNdeViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemNavMon)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRD = 2;
		static const Sbecore::uint CPTEVT = 3;
		static const Sbecore::uint CPTJOB = 4;
		static const Sbecore::uint CPTCAL = 5;
		static const Sbecore::uint CPTCLN = 6;
		static const Sbecore::uint CPTOPX = 7;
		static const Sbecore::uint CPTPST = 8;
		static const Sbecore::uint CPTNDE = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrd = "", const std::string& CptEvt = "", const std::string& CptJob = "", const std::string& CptCal = "", const std::string& CptCln = "", const std::string& CptOpx = "", const std::string& CptPst = "", const std::string& CptNde = "");

	public:
		std::string Cpt;
		std::string CptPrd;
		std::string CptEvt;
		std::string CptJob;
		std::string CptCal;
		std::string CptCln;
		std::string CptOpx;
		std::string CptPst;
		std::string CptNde;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemNavMonData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNavMonDo)
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
		* DpchEngData (full: DpchEngWzemNavMonData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTCAL = 3;
		static const Sbecore::uint FEEDFLSTCLN = 4;
		static const Sbecore::uint FEEDFLSTEVT = 5;
		static const Sbecore::uint FEEDFLSTJOB = 6;
		static const Sbecore::uint FEEDFLSTNDE = 7;
		static const Sbecore::uint FEEDFLSTOPX = 8;
		static const Sbecore::uint FEEDFLSTPRD = 9;
		static const Sbecore::uint FEEDFLSTPST = 10;
		static const Sbecore::uint STATAPP = 11;
		static const Sbecore::uint STATSHR = 12;
		static const Sbecore::uint TAG = 13;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstCal;
		Sbecore::Xmlio::Feed feedFLstCln;
		Sbecore::Xmlio::Feed feedFLstEvt;
		Sbecore::Xmlio::Feed feedFLstJob;
		Sbecore::Xmlio::Feed feedFLstNde;
		Sbecore::Xmlio::Feed feedFLstOpx;
		Sbecore::Xmlio::Feed feedFLstPrd;
		Sbecore::Xmlio::Feed feedFLstPst;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
