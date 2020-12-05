/**
	* \file PnlWzemNdeList.h
	* API code for job PnlWzemNdeList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNDELIST_H
#define PNLWZEMNDELIST_H

#include "ApiWzem_blks.h"

#include "WzemQNdeList.h"

#include "QryWzemNdeList.h"

#define VecVWzemNdeListDo PnlWzemNdeList::VecVDo

#define ContIacWzemNdeList PnlWzemNdeList::ContIac
#define ContInfWzemNdeList PnlWzemNdeList::ContInf
#define StatShrWzemNdeList PnlWzemNdeList::StatShr
#define StgIacWzemNdeList PnlWzemNdeList::StgIac
#define TagWzemNdeList PnlWzemNdeList::Tag

#define DpchAppWzemNdeListData PnlWzemNdeList::DpchAppData
#define DpchAppWzemNdeListDo PnlWzemNdeList::DpchAppDo
#define DpchEngWzemNdeListData PnlWzemNdeList::DpchEngData

/**
	* PnlWzemNdeList
	*/
namespace PnlWzemNdeList {
	/**
		* VecVDo (full: VecVWzemNdeListDo)
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
	  * ContIac (full: ContIacWzemNdeList)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

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
	  * ContInf (full: ContInfWzemNdeList)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatShr (full: StatShrWzemNdeList)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

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
	  * StgIac (full: StgIacWzemNdeList)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOPRDWIDTH = 1;
		static const Sbecore::uint TCOXNRWIDTH = 2;
		static const Sbecore::uint TCOIPWIDTH = 3;
		static const Sbecore::uint TCOSTAWIDTH = 4;
		static const Sbecore::uint TCOSTOWIDTH = 5;
		static const Sbecore::uint TCOPRTWIDTH = 6;
		static const Sbecore::uint TCOORNWIDTH = 7;

	public:
		StgIac(const Sbecore::uint TcoPrdWidth = 100, const Sbecore::uint TcoXnrWidth = 100, const Sbecore::uint TcoIpWidth = 100, const Sbecore::uint TcoStaWidth = 100, const Sbecore::uint TcoStoWidth = 100, const Sbecore::uint TcoPrtWidth = 100, const Sbecore::uint TcoOrnWidth = 100);

	public:
		Sbecore::uint TcoPrdWidth;
		Sbecore::uint TcoXnrWidth;
		Sbecore::uint TcoIpWidth;
		Sbecore::uint TcoStaWidth;
		Sbecore::uint TcoStoWidth;
		Sbecore::uint TcoPrtWidth;
		Sbecore::uint TcoOrnWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWzemNdeList)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TXTRECORD1 = 2;
		static const Sbecore::uint TXTRECORD2 = 3;
		static const Sbecore::uint TRS = 4;
		static const Sbecore::uint TXTSHOWING1 = 5;
		static const Sbecore::uint TXTSHOWING2 = 6;
		static const Sbecore::uint TCOPRD = 7;
		static const Sbecore::uint TCOXNR = 8;
		static const Sbecore::uint TCOIP = 9;
		static const Sbecore::uint TCOSTA = 10;
		static const Sbecore::uint TCOSTO = 11;
		static const Sbecore::uint TCOPRT = 12;
		static const Sbecore::uint TCOORN = 13;

	public:
		Tag(const std::string& Cpt = "", const std::string& TxtRecord1 = "", const std::string& TxtRecord2 = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoPrd = "", const std::string& TcoXnr = "", const std::string& TcoIp = "", const std::string& TcoSta = "", const std::string& TcoSto = "", const std::string& TcoPrt = "", const std::string& TcoOrn = "");

	public:
		std::string Cpt;
		std::string TxtRecord1;
		std::string TxtRecord2;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoPrd;
		std::string TcoXnr;
		std::string TcoIp;
		std::string TcoSta;
		std::string TcoSto;
		std::string TcoPrt;
		std::string TcoOrn;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemNdeListData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryWzemNdeList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWzemNdeList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNdeListDo)
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
		* DpchEngData (full: DpchEngWzemNdeListData)
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
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWzemQNdeList rst;
		QryWzemNdeList::StatApp statappqry;
		QryWzemNdeList::StatShr statshrqry;
		QryWzemNdeList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

