/**
	* \file PnlWzemJobDetail.h
	* API code for job PnlWzemJobDetail (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef PNLWZEMJOBDETAIL_H
#define PNLWZEMJOBDETAIL_H

#include "ApiWzem_blks.h"

#define VecVWzemJobDetailDo PnlWzemJobDetail::VecVDo

#define ContIacWzemJobDetail PnlWzemJobDetail::ContIac
#define ContInfWzemJobDetail PnlWzemJobDetail::ContInf
#define StatAppWzemJobDetail PnlWzemJobDetail::StatApp
#define StatShrWzemJobDetail PnlWzemJobDetail::StatShr
#define TagWzemJobDetail PnlWzemJobDetail::Tag

#define DpchAppWzemJobDetailData PnlWzemJobDetail::DpchAppData
#define DpchAppWzemJobDetailDo PnlWzemJobDetail::DpchAppDo
#define DpchEngWzemJobDetailData PnlWzemJobDetail::DpchEngData

/**
	* PnlWzemJobDetail
	*/
namespace PnlWzemJobDetail {
	/**
		* VecVDo (full: VecVWzemJobDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRDVIEWCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemJobDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFJOB = 1;
		static const Sbecore::uint TXFXJR = 2;
		static const Sbecore::uint TXFSTA = 3;
		static const Sbecore::uint TXFSTO = 4;
		static const Sbecore::uint CHKCLS = 5;
		static const Sbecore::uint CHKSNC = 6;
		static const Sbecore::uint CHKDCL = 7;
		static const Sbecore::uint CHKSTM = 8;

	public:
		ContIac(const std::string& TxfJob = "", const std::string& TxfXjr = "", const std::string& TxfSta = "", const std::string& TxfSto = "", const bool ChkCls = false, const bool ChkSnc = false, const bool ChkDcl = false, const bool ChkStm = false);

	public:
		std::string TxfJob;
		std::string TxfXjr;
		std::string TxfSta;
		std::string TxfSto;
		bool ChkCls;
		bool ChkSnc;
		bool ChkDcl;
		bool ChkStm;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemJobDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRD = 1;
		static const Sbecore::uint TXTSUP = 2;

	public:
		ContInf(const std::string& TxtPrd = "", const std::string& TxtSup = "");

	public:
		std::string TxtPrd;
		std::string TxtSup;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemJobDetail)
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
	  * StatShr (full: StatShrWzemJobDetail)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRDACTIVE = 3;
		static const Sbecore::uint BUTPRDVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRDVIEWACTIVE = 5;
		static const Sbecore::uint TXFJOBACTIVE = 6;
		static const Sbecore::uint TXFXJRACTIVE = 7;
		static const Sbecore::uint TXFSTAACTIVE = 8;
		static const Sbecore::uint TXFSTOACTIVE = 9;
		static const Sbecore::uint TXTSUPACTIVE = 10;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 11;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 12;
		static const Sbecore::uint CHKCLSACTIVE = 13;
		static const Sbecore::uint CHKSNCACTIVE = 14;
		static const Sbecore::uint CHKDCLACTIVE = 15;
		static const Sbecore::uint CHKSTMACTIVE = 16;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrdActive = true, const bool ButPrdViewAvail = true, const bool ButPrdViewActive = true, const bool TxfJobActive = true, const bool TxfXjrActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool ChkClsActive = true, const bool ChkSncActive = true, const bool ChkDclActive = true, const bool ChkStmActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrdActive;
		bool ButPrdViewAvail;
		bool ButPrdViewActive;
		bool TxfJobActive;
		bool TxfXjrActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool ChkClsActive;
		bool ChkSncActive;
		bool ChkDclActive;
		bool ChkStmActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemJobDetail)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTPRD = 2;
		static const Sbecore::uint CPTJOB = 3;
		static const Sbecore::uint CPTXJR = 4;
		static const Sbecore::uint CPTSTA = 5;
		static const Sbecore::uint CPTSTO = 6;
		static const Sbecore::uint CPTSUP = 7;
		static const Sbecore::uint CPTCLS = 8;
		static const Sbecore::uint CPTSNC = 9;
		static const Sbecore::uint CPTDCL = 10;
		static const Sbecore::uint CPTSTM = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptPrd = "", const std::string& CptJob = "", const std::string& CptXjr = "", const std::string& CptSta = "", const std::string& CptSto = "", const std::string& CptSup = "", const std::string& CptCls = "", const std::string& CptSnc = "", const std::string& CptDcl = "", const std::string& CptStm = "");

	public:
		std::string Cpt;
		std::string CptPrd;
		std::string CptJob;
		std::string CptXjr;
		std::string CptSta;
		std::string CptSto;
		std::string CptSup;
		std::string CptCls;
		std::string CptSnc;
		std::string CptDcl;
		std::string CptStm;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemJobDetailData)
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
		* DpchAppDo (full: DpchAppWzemJobDetailDo)
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
		* DpchEngData (full: DpchEngWzemJobDetailData)
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

