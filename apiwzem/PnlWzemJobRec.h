/**
	* \file PnlWzemJobRec.h
	* API code for job PnlWzemJobRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMJOBREC_H
#define PNLWZEMJOBREC_H

#include "ApiWzem_blks.h"

#define VecVWzemJobRecDo PnlWzemJobRec::VecVDo

#define ContInfWzemJobRec PnlWzemJobRec::ContInf
#define StatAppWzemJobRec PnlWzemJobRec::StatApp
#define StatShrWzemJobRec PnlWzemJobRec::StatShr
#define TagWzemJobRec PnlWzemJobRec::Tag

#define DpchAppWzemJobRecDo PnlWzemJobRec::DpchAppDo
#define DpchEngWzemJobRecData PnlWzemJobRec::DpchEngData

/**
	* PnlWzemJobRec
	*/
namespace PnlWzemJobRec {
	/**
		* VecVDo (full: VecVWzemJobRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemJobRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatApp (full: StatAppWzemJobRec)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONEDETAIL = 1;
		static const Sbecore::uint INITDONE1NCALL = 2;
		static const Sbecore::uint INITDONE1NOP = 3;
		static const Sbecore::uint INITDONE1NCLSTN = 4;
		static const Sbecore::uint INITDONE1NPRESET = 5;
		static const Sbecore::uint INITDONESUP1NJOB = 6;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NCall = false, const bool initdone1NOp = false, const bool initdone1NClstn = false, const bool initdone1NPreset = false, const bool initdoneSup1NJob = false);

	public:
		bool initdoneDetail;
		bool initdone1NCall;
		bool initdone1NOp;
		bool initdone1NClstn;
		bool initdone1NPreset;
		bool initdoneSup1NJob;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzemJobRec)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZEMVEXPSTATE = 1;
		static const Sbecore::uint SCRJREFDETAIL = 2;
		static const Sbecore::uint SCRJREF1NCALL = 3;
		static const Sbecore::uint SCRJREF1NOP = 4;
		static const Sbecore::uint SCRJREF1NCLSTN = 5;
		static const Sbecore::uint SCRJREF1NPRESET = 6;
		static const Sbecore::uint SCRJREFSUP1NJOB = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWzemVExpstate = VecWzemVExpstate::REGD, const std::string& scrJrefDetail = "", const std::string& scrJref1NCall = "", const std::string& scrJref1NOp = "", const std::string& scrJref1NClstn = "", const std::string& scrJref1NPreset = "", const std::string& scrJrefSup1NJob = "", const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzemVExpstate;
		std::string scrJrefDetail;
		std::string scrJref1NCall;
		std::string scrJref1NOp;
		std::string scrJref1NClstn;
		std::string scrJref1NPreset;
		std::string scrJrefSup1NJob;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemJobRec)
	  */
	class Tag : public Sbecore::Xmlio::Block {

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
		* DpchAppDo (full: DpchAppWzemJobRecDo)
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
		* DpchEngData (full: DpchEngWzemJobRecData)
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

