/**
	* \file PnlWzemUsgMNUser.h
	* API code for job PnlWzemUsgMNUser (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef PNLWZEMUSGMNUSER_H
#define PNLWZEMUSGMNUSER_H

#include "ApiWzem_blks.h"

#include "WzemQUsgMNUser.h"

#include "QryWzemUsgMNUser.h"

#define VecVWzemUsgMNUserDo PnlWzemUsgMNUser::VecVDo

#define ContInfWzemUsgMNUser PnlWzemUsgMNUser::ContInf
#define StatAppWzemUsgMNUser PnlWzemUsgMNUser::StatApp
#define StatShrWzemUsgMNUser PnlWzemUsgMNUser::StatShr
#define StgIacWzemUsgMNUser PnlWzemUsgMNUser::StgIac
#define TagWzemUsgMNUser PnlWzemUsgMNUser::Tag

#define DpchAppWzemUsgMNUserData PnlWzemUsgMNUser::DpchAppData
#define DpchAppWzemUsgMNUserDo PnlWzemUsgMNUser::DpchAppDo
#define DpchEngWzemUsgMNUserData PnlWzemUsgMNUser::DpchEngData

/**
	* PnlWzemUsgMNUser
	*/
namespace PnlWzemUsgMNUser {
	/**
		* VecVDo (full: VecVWzemUsgMNUserDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTVIEWCLICK = 1;
		static const Sbecore::uint BUTADDCLICK = 2;
		static const Sbecore::uint BUTSUBCLICK = 3;
		static const Sbecore::uint BUTREFRESHCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemUsgMNUser)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFCSIQST = 1;

	public:
		ContInf(const Sbecore::uint numFCsiQst = 1);

	public:
		Sbecore::uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemUsgMNUser)
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
	  * StatShr (full: StatShrWzemUsgMNUser)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTVIEWAVAIL = 1;
		static const Sbecore::uint BUTVIEWACTIVE = 2;
		static const Sbecore::uint BUTADDAVAIL = 3;
		static const Sbecore::uint BUTSUBAVAIL = 4;
		static const Sbecore::uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacWzemUsgMNUser)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOMREFWIDTH = 1;
		static const Sbecore::uint TCOULVWIDTH = 2;

	public:
		StgIac(const Sbecore::uint TcoMrefWidth = 100, const Sbecore::uint TcoUlvWidth = 100);

	public:
		Sbecore::uint TcoMrefWidth;
		Sbecore::uint TcoUlvWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagWzemUsgMNUser)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint TRS = 2;
		static const Sbecore::uint TXTSHOWING1 = 3;
		static const Sbecore::uint TXTSHOWING2 = 4;
		static const Sbecore::uint TCOMREF = 5;
		static const Sbecore::uint TCOULV = 6;

	public:
		Tag(const std::string& Cpt = "", const std::string& Trs = "", const std::string& TxtShowing1 = "", const std::string& TxtShowing2 = "", const std::string& TcoMref = "", const std::string& TcoUlv = "");

	public:
		std::string Cpt;
		std::string Trs;
		std::string TxtShowing1;
		std::string TxtShowing2;
		std::string TcoMref;
		std::string TcoUlv;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzemUsgMNUserData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STGIAC = 2;
		static const Sbecore::uint STGIACQRY = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppData(const std::string& scrJref = "", StgIac* stgiac = NULL, QryWzemUsgMNUser::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryWzemUsgMNUser::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWzemUsgMNUserDo)
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
		* DpchEngData (full: DpchEngWzemUsgMNUserData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFCSIQST = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint STGIAC = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint RST = 8;
		static const Sbecore::uint STATAPPQRY = 9;
		static const Sbecore::uint STATSHRQRY = 10;
		static const Sbecore::uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListWzemQUsgMNUser rst;
		QryWzemUsgMNUser::StatApp statappqry;
		QryWzemUsgMNUser::StatShr statshrqry;
		QryWzemUsgMNUser::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

