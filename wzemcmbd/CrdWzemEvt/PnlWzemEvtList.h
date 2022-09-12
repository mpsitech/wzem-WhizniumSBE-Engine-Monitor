/**
	* \file PnlWzemEvtList.h
	* job handler for job PnlWzemEvtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZEMEVTLIST_H
#define PNLWZEMEVTLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

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
class PnlWzemEvtList : public JobWzem {

public:
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
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzemEvtList)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTFOR = 1;
		static const Sbecore::uint TXTPRE = 2;
		static const Sbecore::uint BUTFILTERON = 3;
		static const Sbecore::uint NUMFCSIQST = 4;

	public:
		ContInf(const std::string& TxtFor = "", const std::string& TxtPre = "", const bool ButFilterOn = false, const Sbecore::uint numFCsiQst = 1);

	public:
		std::string TxtFor;
		std::string TxtPre;
		bool ButFilterOn;
		Sbecore::uint numFCsiQst;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
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
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWzemEvtList)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemEvtListData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STGIAC = 3;
		static const Sbecore::uint STGIACQRY = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		StgIac stgiac;
		QryWzemEvtList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemEvtListDo)
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
		* DpchEngData (full: DpchEngWzemEvtListData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
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
		static const Sbecore::uint ALL = 13;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFCsiQst = NULL, Sbecore::Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWzemQEvtList* rst = NULL, QryWzemEvtList::StatShr* statshrqry = NULL, QryWzemEvtList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFCsiQst;
		Sbecore::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListWzemQEvtList rst;
		QryWzemEvtList::StatShr statshrqry;
		QryWzemEvtList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeJSON(const Sbecore::uint ixWzemVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsWzem* dbswzem);

public:
	PnlWzemEvtList(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemEvtList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Feed feedFCsiQst;
	Sbecore::Feed feedFTos;

	QryWzemEvtList* qry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzem* dbswzem, const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWzem* dbswzem, const bool notif = false, DpchEngWzem** dpcheng = NULL);
	void regularize(DbsWzem* dbswzem, const bool notif = false, DpchEngWzem** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);
	void handleDpchAppDataStgiac(DbsWzem* dbswzem, StgIac* _stgiac, DpchEngWzem** dpcheng);
	void handleDpchAppDataStgiacqry(DbsWzem* dbswzem, QryWzemEvtList::StgIac* _stgiacqry, DpchEngWzem** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButNewClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButFilterClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

private:
	bool handleCallWzemStatChg(DbsWzem* dbswzem, const Sbecore::ubigint jrefTrig);

};

#endif
