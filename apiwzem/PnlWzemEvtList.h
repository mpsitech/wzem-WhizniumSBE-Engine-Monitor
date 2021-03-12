/**
	* \file PnlWzemEvtList.h
	* API code for job PnlWzemEvtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMEVTLIST_H
#define PNLWZEMEVTLIST_H

#include "ApiWzem_blks.h"

#include "WzemQEvtList.h"

#include "QryWzemEvtList.h"

#define VecVWzemEvtListDo PnlWzemEvtList::VecVDo

#define ContIacWzemEvtList PnlWzemEvtList::ContIac
#define ContInfWzemEvtList PnlWzemEvtList::ContInf
#define StatShrWzemEvtList PnlWzemEvtList::StatShr
#define StgIacWzemEvtList PnlWzemEvtList::StgIac
#define TagWzemEvtList PnlWzemEvtList::Tag

#define DpchAppWzemEvtListData PnlWzemEvtList::DpchAppData
#define DpchAppWzemEvtListDo PnlWzemEvtList::DpchAppDo
#define DpchEngWzemEvtListData PnlWzemEvtList::DpchEngData

/**
	* PnlWzemEvtList
	*/
namespace PnlWzemEvtList {
	/**
		* VecVDo (full: VecVWzemEvtListDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;
		static const Sbecore::uint BUTNEWCLICK = 3;
		static const Sbecore::uint BUTDELETECLICK = 4;
		static const Sbecore::uint BUTFILTERCLICK = 5;
		static const Sbecore::uint BUTREFRESHCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzemEvtList)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFTOS = 1;

	public:
		ContIac(const Sbecore::uint numFTos = 1);

	public:
		Sbecore::uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemEvtList)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTFILTERON = 1;
		static const Sbecore::uint NUMFCSIQST = 2;

	public:
		ContInf(const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzemEvtList)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		Sbecore::uint ixWzemVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWzemEvtList)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TCOTYPWIDTH = 1;
		static const Sbecore::uint TCOPRDWIDTH = 2;
		static const Sbecore::uint TCOSTAWIDTH = 3;
		static const Sbecore::uint TCOCMDWIDTH = 4;
		static const Sbecore::uint TCOFEGWIDTH = 5;
		static const Sbecore::uint TCOMTDWIDTH = 6;
		static const Sbecore::uint TCOXSRWIDTH = 7;

	public:
		StgIac(const Sbecore::uint TcoTypWidth = 100, const Sbecore::uint TcoPrdWidth = 100, const Sbecore::uint TcoStaWidth = 100, const Sbecore::uint TcoCmdWidth = 100, const Sbecore::uint TcoFegWidth = 100, const Sbecore::uint TcoMtdWidth = 100, const Sbecore::uint TcoXsrWidth = 100);

	public:
		Sbecore::uint TcoTypWidth;
		Sbecore::uint TcoPrdWidth;
		Sbecore::uint TcoStaWidth;
		Sbecore::uint TcoCmdWidth;
		Sbecore::uint TcoFegWidth;
		Sbecore::uint TcoMtdWidth;
		Sbecore::uint TcoXsrWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWzemEvtList)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOTYP = 7;
		static const Sbecore::uint TCOPRD = 8;
		static const Sbecore::uint TCOSTA = 9;
		static const Sbecore::uint TCOCMD = 10;
		static const Sbecore::uint TCOFEG = 11;
		static const Sbecore::uint TCOMTD = 12;
		static const Sbecore::uint TCOXSR = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoTyp = "", const std::string& TcoPrd = "", const std::string& TcoSta = "", const std::string& TcoCmd = "", const std::string& TcoFeg = "", const std::string& TcoMtd = "", const std::string& TcoXsr = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoTyp;
		std::string TcoPrd;
		std::string TcoSta;
		std::string TcoCmd;
		std::string TcoFeg;
		std::string TcoMtd;
		std::string TcoXsr;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemEvtListData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWzemEvtList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWzemEvtList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzemEvtListDo)
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
		* DpchEngData (full: DpchEngWzemEvtListData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFCSIQST = 4;
		static const Sbecore::uint FEEDFTOS = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint STGIAC = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint RST = 9;
		static const Sbecore::uint STATAPPQRY = 10;
		static const Sbecore::uint STATSHRQRY = 11;
		static const Sbecore::uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		Sbecore::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWzemQEvtList rst;
		QryWzemEvtList::StatApp statappqry;
		QryWzemEvtList::StatShr statshrqry;
		QryWzemEvtList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
