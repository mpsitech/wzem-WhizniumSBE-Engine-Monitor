/**
	* \file PnlWzemUsrDetail.h
	* API code for job PnlWzemUsrDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMUSRDETAIL_H
#define PNLWZEMUSRDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemUsrDetailDo PnlWzemUsrDetail::VecVDo

#define ContIacWzemUsrDetail PnlWzemUsrDetail::ContIac
#define ContInfWzemUsrDetail PnlWzemUsrDetail::ContInf
#define StatAppWzemUsrDetail PnlWzemUsrDetail::StatApp
#define StatShrWzemUsrDetail PnlWzemUsrDetail::StatShr
#define TagWzemUsrDetail PnlWzemUsrDetail::Tag

#define DpchAppWzemUsrDetailData PnlWzemUsrDetail::DpchAppData
#define DpchAppWzemUsrDetailDo PnlWzemUsrDetail::DpchAppDo
#define DpchEngWzemUsrDetailData PnlWzemUsrDetail::DpchEngData

/**
	* PnlWzemUsrDetail
	*/
namespace PnlWzemUsrDetail {
	/**
		* VecVDo (full: VecVWzemUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRSVIEWCLICK = 2;
		static const Sbecore::uint BUTUSGVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemUsrDetail)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPSTE = 1;
		static const Sbecore::uint NUMFPUPLCL = 2;
		static const Sbecore::uint NUMFPUPULV = 3;
		static const Sbecore::uint TXFPWD = 4;
		static const Sbecore::uint TXFFKY = 5;
		static const Sbecore::uint TXFCMT = 6;

	public:
		ContIac(const Sbecore::uint numFPupSte = 1, const Sbecore::uint numFPupLcl = 1, const Sbecore::uint numFPupUlv = 1, const std::string& TxfPwd = "", const std::string& TxfFky = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupSte;
		Sbecore::uint numFPupLcl;
		Sbecore::uint numFPupUlv;
		std::string TxfPwd;
		std::string TxfFky;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemUsrDetail)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRS = 1;
		static const Sbecore::uint TXTSRF = 2;
		static const Sbecore::uint TXTUSG = 3;

	public:
		ContInf(const std::string& TxtPrs = "", const std::string& TxtSrf = "", const std::string& TxtUsg = "");

	public:
		std::string TxtPrs;
		std::string TxtSrf;
		std::string TxtUsg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemUsrDetail)
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
	  * StatShr (full: StatShrWzemUsrDetail)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRSACTIVE = 3;
		static const Sbecore::uint BUTPRSVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTUSGACTIVE = 7;
		static const Sbecore::uint BUTUSGVIEWAVAIL = 8;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 9;
		static const Sbecore::uint PUPSTEACTIVE = 10;
		static const Sbecore::uint PUPLCLACTIVE = 11;
		static const Sbecore::uint PUPULVACTIVE = 12;
		static const Sbecore::uint TXFPWDACTIVE = 13;
		static const Sbecore::uint TXFFKYACTIVE = 14;
		static const Sbecore::uint TXFCMTACTIVE = 15;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemUsrDetail)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRS = 2;
		static const Sbecore::uint CPTSRF = 3;
		static const Sbecore::uint CPTUSG = 4;
		static const Sbecore::uint CPTSTE = 5;
		static const Sbecore::uint CPTLCL = 6;
		static const Sbecore::uint CPTULV = 7;
		static const Sbecore::uint CPTPWD = 8;
		static const Sbecore::uint CPTFKY = 9;
		static const Sbecore::uint CPTCMT = 10;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrs = "", const std::string& CptSrf = "", const std::string& CptUsg = "", const std::string& CptSte = "", const std::string& CptLcl = "", const std::string& CptUlv = "", const std::string& CptPwd = "", const std::string& CptFky = "", const std::string& CptCmt = "");

	public:
		std::string Cpt;
		std::string CptPrs;
		std::string CptSrf;
		std::string CptUsg;
		std::string CptSte;
		std::string CptLcl;
		std::string CptUlv;
		std::string CptPwd;
		std::string CptFky;
		std::string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemUsrDetailData)
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
		* DpchAppDo (full: DpchAppWzemUsrDetailDo)
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
		* DpchEngData (full: DpchEngWzemUsrDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPLCL = 4;
		static const Sbecore::uint FEEDFPUPSTE = 5;
		static const Sbecore::uint FEEDFPUPULV = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupLcl;
		Sbecore::Feed feedFPupSte;
		Sbecore::Feed feedFPupUlv;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
