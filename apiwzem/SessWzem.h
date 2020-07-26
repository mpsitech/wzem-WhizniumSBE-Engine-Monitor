/**
	* \file SessWzem.h
	* API code for job SessWzem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef SESSWZEM_H
#define SESSWZEM_H

#include "ApiWzem_blks.h"

#define StatShrSessWzem SessWzem::StatShr

#define DpchEngSessWzemData SessWzem::DpchEngData

/**
	* SessWzem
	*/
namespace SessWzem {
	/**
	  * StatShr (full: StatShrSessWzem)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const std::string& scrJrefCrdnav = "");

	public:
		std::string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWzemData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;

	public:
		DpchEngData();

	public:
		Sbecore::Xmlio::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

