/**
	* \file RootWzem.h
	* API code for job RootWzem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
	*/
// IP header --- ABOVE

#ifndef ROOTWZEM_H
#define ROOTWZEM_H

#include "ApiWzem_blks.h"

#define DpchAppRootWzemLogin RootWzem::DpchAppLogin
#define DpchEngRootWzemData RootWzem::DpchEngData

/**
	* RootWzem
	*/
namespace RootWzem {
	/**
		* DpchAppLogin (full: DpchAppRootWzemLogin)
		*/
	class DpchAppLogin : public DpchAppWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchAppLogin(const std::string& scrJref = "", const std::string& username = "", const std::string& password = "", const bool m2mNotReg = false, const bool chksuspsess = false, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngRootWzemData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;

	public:
		DpchEngData();

	public:
		Sbecore::Xmlio::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

