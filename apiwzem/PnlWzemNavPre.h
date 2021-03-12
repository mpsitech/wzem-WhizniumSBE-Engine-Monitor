/**
	* \file PnlWzemNavPre.h
	* API code for job PnlWzemNavPre (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNAVPRE_H
#define PNLWZEMNAVPRE_H

#include "ApiWzem_blks.h"

#define VecVWzemNavPreDo PnlWzemNavPre::VecVDo

#define ContInfWzemNavPre PnlWzemNavPre::ContInf
#define StatShrWzemNavPre PnlWzemNavPre::StatShr
#define TagWzemNavPre PnlWzemNavPre::Tag

#define DpchAppWzemNavPreDo PnlWzemNavPre::DpchAppDo
#define DpchEngWzemNavPreData PnlWzemNavPre::DpchEngData

/**
	* PnlWzemNavPre
	*/
namespace PnlWzemNavPre {
	/**
		* VecVDo (full: VecVWzemNavPreDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTPRDREMOVECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzemNavPre)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRD = 1;

	public:
		ContInf(const std::string& TxtPrd = "");

	public:
		std::string TxtPrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzemNavPre)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRDAVAIL = 1;

	public:
		StatShr(const bool TxtPrdAvail = true);

	public:
		bool TxtPrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzemNavPre)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTPRD = 1;

	public:
		Tag(const std::string& CptPrd = "");

	public:
		std::string CptPrd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNavPreDo)
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
		* DpchEngData (full: DpchEngWzemNavPreData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
