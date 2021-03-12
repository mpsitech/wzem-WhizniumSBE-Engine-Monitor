/**
	* \file PnlWzemPrsDetail.h
	* API code for job PnlWzemPrsDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPRSDETAIL_H
#define PNLWZEMPRSDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemPrsDetailDo PnlWzemPrsDetail::VecVDo

#define ContIacWzemPrsDetail PnlWzemPrsDetail::ContIac
#define ContInfWzemPrsDetail PnlWzemPrsDetail::ContInf
#define StatAppWzemPrsDetail PnlWzemPrsDetail::StatApp
#define StatShrWzemPrsDetail PnlWzemPrsDetail::StatShr
#define TagWzemPrsDetail PnlWzemPrsDetail::Tag

#define DpchAppWzemPrsDetailData PnlWzemPrsDetail::DpchAppData
#define DpchAppWzemPrsDetailDo PnlWzemPrsDetail::DpchAppDo
#define DpchEngWzemPrsDetailData PnlWzemPrsDetail::DpchEngData

/**
	* PnlWzemPrsDetail
	*/
namespace PnlWzemPrsDetail {
	/**
		* VecVDo (full: VecVWzemPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemPrsDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFNM = 2;
		static const Sbecore::uint NUMFPUPJ = 3;
		static const Sbecore::uint NUMSFLSTDRV = 4;
		static const Sbecore::uint NUMFPUPSEX = 5;
		static const Sbecore::uint TXFTEL = 6;
		static const Sbecore::uint TXFEML = 7;
		static const Sbecore::uint TXFSAL = 8;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFnm = "", const Sbecore::uint numFPupJ = 1, const std::vector<Sbecore::uint>& numsFLstDrv = {}, const Sbecore::uint numFPupSex = 1, const std::string& TxfTel = "", const std::string& TxfEml = "", const std::string& TxfSal = "");

	public:
		std::string TxfTit;
		std::string TxfFnm;
		Sbecore::uint numFPupJ;
		std::vector<Sbecore::uint> numsFLstDrv;
		Sbecore::uint numFPupSex;
		std::string TxfTel;
		std::string TxfEml;
		std::string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemPrsDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTLNM = 1;
		static const Sbecore::uint TXTDRV = 2;

	public:
		ContInf(const std::string& TxtLnm = "", const std::string& TxtDrv = "");

	public:
		std::string TxtLnm;
		std::string TxtDrv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemPrsDetail)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint LSTDRVALT = 2;
		static const Sbecore::uint LSTDRVNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstDrvAlt = true, const Sbecore::uint LstDrvNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzemVExpstate;
		bool LstDrvAlt;
		Sbecore::uint LstDrvNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemPrsDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFTITACTIVE = 3;
		static const Sbecore::uint TXFFNMACTIVE = 4;
		static const Sbecore::uint PUPJACTIVE = 5;
		static const Sbecore::uint BUTJEDITAVAIL = 6;
		static const Sbecore::uint TXTLNMACTIVE = 7;
		static const Sbecore::uint LSTDRVACTIVE = 8;
		static const Sbecore::uint PUPSEXACTIVE = 9;
		static const Sbecore::uint TXFTELACTIVE = 10;
		static const Sbecore::uint TXFEMLACTIVE = 11;
		static const Sbecore::uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemPrsDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTTIT = 2;
		static const Sbecore::uint CPTFNM = 3;
		static const Sbecore::uint CPTLNM = 4;
		static const Sbecore::uint CPTDRV = 5;
		static const Sbecore::uint CPTSEX = 6;
		static const Sbecore::uint CPTTEL = 7;
		static const Sbecore::uint CPTEML = 8;
		static const Sbecore::uint CPTSAL = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptTit = "", const std::string& CptFnm = "", const std::string& CptLnm = "", const std::string& CptDrv = "", const std::string& CptSex = "", const std::string& CptTel = "", const std::string& CptEml = "", const std::string& CptSal = "");

	public:
		std::string Cpt;
		std::string CptTit;
		std::string CptFnm;
		std::string CptLnm;
		std::string CptDrv;
		std::string CptSex;
		std::string CptTel;
		std::string CptEml;
		std::string CptSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemPrsDetailData)
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
		* DpchAppDo (full: DpchAppWzemPrsDetailDo)
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
		* DpchEngData (full: DpchEngWzemPrsDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDRV = 4;
		static const Sbecore::uint FEEDFPUPJ = 5;
		static const Sbecore::uint FEEDFPUPSEX = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFLstDrv;
		Sbecore::Feed feedFPupJ;
		Sbecore::Feed feedFPupSex;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
