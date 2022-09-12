/**
	* \file PnlWzemNavPre.h
	* job handler for job PnlWzemNavPre (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMNAVPRE_H
#define PNLWZEMNAVPRE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzemNavPreDo PnlWzemNavPre::VecVDo

#define ContInfWzemNavPre PnlWzemNavPre::ContInf
#define StatShrWzemNavPre PnlWzemNavPre::StatShr
#define TagWzemNavPre PnlWzemNavPre::Tag

#define DpchAppWzemNavPreDo PnlWzemNavPre::DpchAppDo
#define DpchEngWzemNavPreData PnlWzemNavPre::DpchEngData

/**
	* PnlWzemNavPre
	*/
class PnlWzemNavPre : public JobWzem {

public:
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzemNavPre)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzemNavPreDo)
		*/
	class DpchAppDo : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzemNavPreData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalTxtPrdAvail(DbsWzem* dbswzem);

public:
	PnlWzemNavPre(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemNavPre();

public:
	ContInf continf;
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

	void handleDpchAppDoButPrdRemoveClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

};

#endif
