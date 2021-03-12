/**
	* \file PnlWzemPrdRec.h
	* API code for job PnlWzemPrdRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMPRDREC_H
#define PNLWZEMPRDREC_H

#include "ApiWzem_blks.h"

#define VecVWzemPrdRecDo PnlWzemPrdRec::VecVDo

#define ContInfWzemPrdRec PnlWzemPrdRec::ContInf
#define StatAppWzemPrdRec PnlWzemPrdRec::StatApp
#define StatShrWzemPrdRec PnlWzemPrdRec::StatShr
#define TagWzemPrdRec PnlWzemPrdRec::Tag

#define DpchAppWzemPrdRecDo PnlWzemPrdRec::DpchAppDo
#define DpchEngWzemPrdRecData PnlWzemPrdRec::DpchEngData

/**
	* PnlWzemPrdRec
	*/
namespace PnlWzemPrdRec {
	/**
		* VecVDo (full: VecVWzemPrdRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemPrdRec)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzemPrdRec)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NNODE = 2;
		static const Sbecore::uint INITDONE1NJOB = 3;
		static const Sbecore::uint INITDONE1NEVENT = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NNode = false, const bool initdone1NJob = false, const bool initdone1NEvent = false);

	public:
		bool initdoneDetail;
		bool initdone1NNode;
		bool initdone1NJob;
		bool initdone1NEvent;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemPrdRec)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NNODE = 3;
		static const Sbecore::uint SCRJREF1NJOB = 4;
		static const Sbecore::uint SCRJREF1NEVENT = 5;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NNode = "", const std::string& scrJref1NJob = "", const std::string& scrJref1NEvent = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzemVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NNode;
		std::string scrJref1NJob;
		std::string scrJref1NEvent;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemPrdRec)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;

	public:
		Tag(const std::string& Cpt = "");

	public:
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemPrdRecDo)
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
		* DpchEngData (full: DpchEngWzemPrdRecData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
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
