/**
	* \file PnlWzemOpxDetail.h
	* API code for job PnlWzemOpxDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMOPXDETAIL_H
#define PNLWZEMOPXDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemOpxDetailDo PnlWzemOpxDetail::VecVDo

#define ContIacWzemOpxDetail PnlWzemOpxDetail::ContIac
#define ContInfWzemOpxDetail PnlWzemOpxDetail::ContInf
#define StatAppWzemOpxDetail PnlWzemOpxDetail::StatApp
#define StatShrWzemOpxDetail PnlWzemOpxDetail::StatShr
#define TagWzemOpxDetail PnlWzemOpxDetail::Tag

#define DpchAppWzemOpxDetailData PnlWzemOpxDetail::DpchAppData
#define DpchAppWzemOpxDetailDo PnlWzemOpxDetail::DpchAppDo
#define DpchEngWzemOpxDetailData PnlWzemOpxDetail::DpchEngData

/**
	* PnlWzemOpxDetail
	*/
namespace PnlWzemOpxDetail {
	/**
		* VecVDo (full: VecVWzemOpxDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemOpxDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFXOR = 1;
		static const Sbecore::uint TXFSTA = 2;
		static const Sbecore::uint TXFSTO = 3;

	public:
		ContIac(const std::string& TxfXor = "", const std::string& TxfSta = "", const std::string& TxfSto = "");

	public:
		std::string TxfXor;
		std::string TxfSta;
		std::string TxfSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemOpxDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTJOB = 1;

	public:
		ContInf(const std::string& TxtJob = "");

	public:
		std::string TxtJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemOpxDetail)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrWzemOpxDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTJOBACTIVE = 3;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 4;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 5;
		static const Sbecore::uint TXFXORACTIVE = 6;
		static const Sbecore::uint TXFSTAACTIVE = 7;
		static const Sbecore::uint TXFSTOACTIVE = 8;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfXorActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfXorActive;
		bool TxfStaActive;
		bool TxfStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemOpxDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTJOB = 2;
		static const Sbecore::uint CPTXOR = 3;
		static const Sbecore::uint CPTSTA = 4;
		static const Sbecore::uint CPTSTO = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptJob = "", const std::string& CptXor = "", const std::string& CptSta = "", const std::string& CptSto = "");

	public:
		std::string Cpt;
		std::string CptJob;
		std::string CptXor;
		std::string CptSta;
		std::string CptSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemOpxDetailData)
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
		* DpchAppDo (full: DpchAppWzemOpxDetailDo)
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
		* DpchEngData (full: DpchEngWzemOpxDetailData)
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
