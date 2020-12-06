/**
	* \file PnlWzemNdeDetail.h
	* API code for job PnlWzemNdeDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNDEDETAIL_H
#define PNLWZEMNDEDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemNdeDetailDo PnlWzemNdeDetail::VecVDo

#define ContIacWzemNdeDetail PnlWzemNdeDetail::ContIac
#define ContInfWzemNdeDetail PnlWzemNdeDetail::ContInf
#define StatAppWzemNdeDetail PnlWzemNdeDetail::StatApp
#define StatShrWzemNdeDetail PnlWzemNdeDetail::StatShr
#define TagWzemNdeDetail PnlWzemNdeDetail::Tag

#define DpchAppWzemNdeDetailData PnlWzemNdeDetail::DpchAppData
#define DpchAppWzemNdeDetailDo PnlWzemNdeDetail::DpchAppDo
#define DpchEngWzemNdeDetailData PnlWzemNdeDetail::DpchEngData

/**
	* PnlWzemNdeDetail
	*/
namespace PnlWzemNdeDetail {
	/**
		* VecVDo (full: VecVWzemNdeDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRDVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemNdeDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFXNR = 1;
		static const Sbecore::uint TXFIP = 2;
		static const Sbecore::uint TXFSTA = 3;
		static const Sbecore::uint TXFSTO = 4;
		static const Sbecore::uint TXFPRT = 5;
		static const Sbecore::uint TXFORN = 6;

	public:
		ContIac(const std::string& TxfXnr = "", const std::string& TxfIp = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfPrt = "", const std::string& TxfOrn = "");

	public:
		std::string TxfXnr;
		std::string TxfIp;
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfPrt;
		std::string TxfOrn;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemNdeDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRD = 1;

	public:
		ContInf(const std::string& TxtPrd = "");

	public:
		std::string TxtPrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemNdeDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;

	public:
		StatApp(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND);

	public:
		Sbecore::uint ixWzemVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemNdeDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRDACTIVE = 3;
		static const Sbecore::uint BUTPRDVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 5;
		static const Sbecore::uint TXFXNRACTIVE = 6;
		static const Sbecore::uint TXFIPACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint TXFPRTACTIVE = 10;
		static const Sbecore::uint TXFORNACTIVE = 11;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfXnrActive = true, const bool TxfIpActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfPrtActive = true, const bool TxfOrnActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfXnrActive;
		bool TxfIpActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfPrtActive;
		bool TxfOrnActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemNdeDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRD = 2;
		static const Sbecore::uint CPTXNR = 3;
		static const Sbecore::uint CPTIP = 4;
		static const Sbecore::uint CPTSTA = 5;
		static const Sbecore::uint CPTSTO = 6;
		static const Sbecore::uint CPTPRT = 7;
		static const Sbecore::uint CPTORN = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrd = "", const std::string& CptXnr = "", const std::string& CptIp = "", const std::string& CptSta = "", const std::string& CptSto = "", const std::string& CptPrt = "", const std::string& CptOrn = "");

	public:
		std::string Cpt;
		std::string CptPrd;
		std::string CptXnr;
		std::string CptIp;
		std::string CptSta;
		std::string CptSto;
		std::string CptPrt;
		std::string CptOrn;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemNdeDetailData)
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
		* DpchAppDo (full: DpchAppWzemNdeDetailDo)
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
		* DpchEngData (full: DpchEngWzemNdeDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
