/**
	* \file PnlWzemCalDetail.h
	* API code for job PnlWzemCalDetail (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef PNLWZEMCALDETAIL_H
#define PNLWZEMCALDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemCalDetailDo PnlWzemCalDetail::VecVDo

#define ContIacWzemCalDetail PnlWzemCalDetail::ContIac
#define ContInfWzemCalDetail PnlWzemCalDetail::ContInf
#define StatAppWzemCalDetail PnlWzemCalDetail::StatApp
#define StatShrWzemCalDetail PnlWzemCalDetail::StatShr
#define TagWzemCalDetail PnlWzemCalDetail::Tag

#define DpchAppWzemCalDetailData PnlWzemCalDetail::DpchAppData
#define DpchAppWzemCalDetailDo PnlWzemCalDetail::DpchAppDo
#define DpchEngWzemCalDetailData PnlWzemCalDetail::DpchEngData

/**
	* PnlWzemCalDetail
	*/
namespace PnlWzemCalDetail {
	/**
		* VecVDo (full: VecVWzemCalDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemCalDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFCAL = 1;
		static const Sbecore::uint TXFSTA = 2;
		static const Sbecore::uint TXFSTO = 3;
		static const Sbecore::uint TXFINV = 4;
		static const Sbecore::uint TXFRET = 5;

	public:
		ContIac(const std::string& TxfCal = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfInv = "", const std::string& TxfRet = "");

	public:
		std::string TxfCal;
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfInv;
		std::string TxfRet;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemCalDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatApp (full: StatAppWzemCalDetail)
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
	  * StatShr (full: StatShrWzemCalDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTJOBACTIVE = 3;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 4;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 5;
		static const Sbecore::uint TXFCALACTIVE = 6;
		static const Sbecore::uint TXFSTAACTIVE = 7;
		static const Sbecore::uint TXFSTOACTIVE = 8;
		static const Sbecore::uint TXFINVACTIVE = 9;
		static const Sbecore::uint TXFRETACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfCalActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfInvActive = true, const bool TxfRetActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfCalActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfInvActive;
		bool TxfRetActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemCalDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTJOB = 2;
		static const Sbecore::uint CPTCAL = 3;
		static const Sbecore::uint CPTSTA = 4;
		static const Sbecore::uint CPTSTO = 5;
		static const Sbecore::uint CPTINV = 6;
		static const Sbecore::uint CPTRET = 7;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptJob = "", const std::string& CptCal = "", const std::string& CptSta = "", const std::string& CptSto = "", const std::string& CptInv = "", const std::string& CptRet = "");

	public:
		std::string Cpt;
		std::string CptJob;
		std::string CptCal;
		std::string CptSta;
		std::string CptSto;
		std::string CptInv;
		std::string CptRet;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemCalDetailData)
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
		* DpchAppDo (full: DpchAppWzemCalDetailDo)
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
		* DpchEngData (full: DpchEngWzemCalDetailData)
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

