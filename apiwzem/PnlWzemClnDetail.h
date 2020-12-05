/**
	* \file PnlWzemClnDetail.h
	* API code for job PnlWzemClnDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMCLNDETAIL_H
#define PNLWZEMCLNDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemClnDetailDo PnlWzemClnDetail::VecVDo

#define ContIacWzemClnDetail PnlWzemClnDetail::ContIac
#define ContInfWzemClnDetail PnlWzemClnDetail::ContInf
#define StatAppWzemClnDetail PnlWzemClnDetail::StatApp
#define StatShrWzemClnDetail PnlWzemClnDetail::StatShr
#define TagWzemClnDetail PnlWzemClnDetail::Tag

#define DpchAppWzemClnDetailData PnlWzemClnDetail::DpchAppData
#define DpchAppWzemClnDetailDo PnlWzemClnDetail::DpchAppDo
#define DpchEngWzemClnDetailData PnlWzemClnDetail::DpchEngData

/**
	* PnlWzemClnDetail
	*/
namespace PnlWzemClnDetail {
	/**
		* VecVDo (full: VecVWzemClnDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJOBVIEWCLICK = 2;
		static const Sbecore::uint BUTTJBVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemClnDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFCAL = 1;
		static const Sbecore::uint TXFSGE = 2;
		static const Sbecore::uint TXFSTA = 3;
		static const Sbecore::uint TXFSTO = 4;
		static const Sbecore::uint NUMFPUPTRG = 5;
		static const Sbecore::uint NUMFPUPJMS = 6;
		static const Sbecore::uint NUMSFLSTAMS = 7;
		static const Sbecore::uint TXFARG = 8;
		static const Sbecore::uint NUMFPUPJAT = 9;

	public:
		ContIac(const std::string& TxfCal = "", const std::string& TxfSge = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const Sbecore::uint numFPupTrg = 1, const Sbecore::uint numFPupJms = 1, const std::vector<Sbecore::uint>& numsFLstAms = {}, const std::string& TxfArg = "", const Sbecore::uint numFPupJat = 1);

	public:
		std::string TxfCal;
		std::string TxfSge;
		std::string TxfSta;
		std::string TxfSto;
		Sbecore::uint numFPupTrg;
		Sbecore::uint numFPupJms;
		std::vector<Sbecore::uint> numsFLstAms;
		std::string TxfArg;
		Sbecore::uint numFPupJat;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemClnDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTJOB = 1;
		static const Sbecore::uint TXTTJB = 2;
		static const Sbecore::uint TXTAMS = 3;

	public:
		ContInf(const std::string& TxtJob = "", const std::string& TxtTjb = "", const std::string& TxtAms = "");

	public:
		std::string TxtJob;
		std::string TxtTjb;
		std::string TxtAms;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemClnDetail)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint LSTAMSALT = 2;
		static const Sbecore::uint LSTAMSNUMFIRSTDISP = 3;

	public:
		StatApp(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool LstAmsAlt = true, const Sbecore::uint LstAmsNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzemVExpstate;
		bool LstAmsAlt;
		Sbecore::uint LstAmsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemClnDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTJOBACTIVE = 3;
		static const Sbecore::uint BUTJOBVIEWAVAIL = 4;
		static const Sbecore::uint BUTJOBVIEWACTIVE = 5;
		static const Sbecore::uint TXFCALACTIVE = 6;
		static const Sbecore::uint TXFSGEACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint PUPTRGACTIVE = 10;
		static const Sbecore::uint PUPJMSACTIVE = 11;
		static const Sbecore::uint TXTTJBACTIVE = 12;
		static const Sbecore::uint BUTTJBVIEWAVAIL = 13;
		static const Sbecore::uint BUTTJBVIEWACTIVE = 14;
		static const Sbecore::uint LSTAMSACTIVE = 15;
		static const Sbecore::uint TXFARGACTIVE = 16;
		static const Sbecore::uint PUPJATACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtJobActive = true, const bool ButJobViewAvail = true, const bool ButJobViewActive = true, const bool TxfCalActive = true, const bool TxfSgeActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool PupTrgActive = true, const bool PupJmsActive = true, const bool TxtTjbActive = true, const bool ButTjbViewAvail = true, const bool ButTjbViewActive = true, const bool LstAmsActive = true, const bool TxfArgActive = true, const bool PupJatActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtJobActive;
		bool ButJobViewAvail;
		bool ButJobViewActive;
		bool TxfCalActive;
		bool TxfSgeActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool PupTrgActive;
		bool PupJmsActive;
		bool TxtTjbActive;
		bool ButTjbViewAvail;
		bool ButTjbViewActive;
		bool LstAmsActive;
		bool TxfArgActive;
		bool PupJatActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemClnDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTJOB = 2;
		static const Sbecore::uint CPTCAL = 3;
		static const Sbecore::uint CPTSGE = 4;
		static const Sbecore::uint CPTSTA = 5;
		static const Sbecore::uint CPTSTO = 6;
		static const Sbecore::uint CPTTRG = 7;
		static const Sbecore::uint CPTJMS = 8;
		static const Sbecore::uint CPTTJB = 9;
		static const Sbecore::uint CPTAMS = 10;
		static const Sbecore::uint CPTARG = 11;
		static const Sbecore::uint CPTJAT = 12;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptJob = "", const std::string& CptCal = "", const std::string& CptSge = "", const std::string& CptSta = "", const std::string& CptSto = "", const std::string& CptTrg = "", const std::string& CptJms = "", const std::string& CptTjb = "", const std::string& CptAms = "", const std::string& CptArg = "", const std::string& CptJat = "");

	public:
		std::string Cpt;
		std::string CptJob;
		std::string CptCal;
		std::string CptSge;
		std::string CptSta;
		std::string CptSto;
		std::string CptTrg;
		std::string CptJms;
		std::string CptTjb;
		std::string CptAms;
		std::string CptArg;
		std::string CptJat;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemClnDetailData)
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
		* DpchAppDo (full: DpchAppWzemClnDetailDo)
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
		* DpchEngData (full: DpchEngWzemClnDetailData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTAMS = 4;
		static const Sbecore::uint FEEDFPUPJAT = 5;
		static const Sbecore::uint FEEDFPUPJMS = 6;
		static const Sbecore::uint FEEDFPUPTRG = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstAms;
		Sbecore::Xmlio::Feed feedFPupJat;
		Sbecore::Xmlio::Feed feedFPupJms;
		Sbecore::Xmlio::Feed feedFPupTrg;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

