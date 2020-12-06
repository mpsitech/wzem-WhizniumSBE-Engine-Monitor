/**
	* \file PnlWzemPrdDetail.h
	* API code for job PnlWzemPrdDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPRDDETAIL_H
#define PNLWZEMPRDDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemPrdDetailDo PnlWzemPrdDetail::VecVDo

#define ContIacWzemPrdDetail PnlWzemPrdDetail::ContIac
#define StatAppWzemPrdDetail PnlWzemPrdDetail::StatApp
#define StatShrWzemPrdDetail PnlWzemPrdDetail::StatShr
#define TagWzemPrdDetail PnlWzemPrdDetail::Tag

#define DpchAppWzemPrdDetailData PnlWzemPrdDetail::DpchAppData
#define DpchAppWzemPrdDetailDo PnlWzemPrdDetail::DpchAppDo
#define DpchEngWzemPrdDetailData PnlWzemPrdDetail::DpchEngData

/**
	* PnlWzemPrdDetail
	*/
namespace PnlWzemPrdDetail {
	/**
		* VecVDo (full: VecVWzemPrdDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemPrdDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFVER = 1;
		static const Sbecore::uint TXFSTA = 2;
		static const Sbecore::uint TXFSTO = 3;

	public:
		ContIac(const std::string& TxfVer = "", const std::string& TxfSta = "", const std::string& TxfSto = "");

	public:
		std::string TxfVer;
		std::string TxfSta;
		std::string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWzemPrdDetail)
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
	  * StatShr (full: StatShrWzemPrdDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFVERACTIVE = 3;
		static const Sbecore::uint TXFSTAACTIVE = 4;
		static const Sbecore::uint TXFSTOACTIVE = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfVerActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfVerActive;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemPrdDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTVER = 2;
		static const Sbecore::uint CPTSTA = 3;
		static const Sbecore::uint CPTSTO = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptVer = "", const std::string& CptSta = "", const std::string& CptSto = "");

	public:
		std::string Cpt;
		std::string CptVer;
		std::string CptSta;
		std::string CptSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemPrdDetailData)
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
		* DpchAppDo (full: DpchAppWzemPrdDetailDo)
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
		* DpchEngData (full: DpchEngWzemPrdDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
