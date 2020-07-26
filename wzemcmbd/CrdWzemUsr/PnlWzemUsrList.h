/**
	* \file PnlWzemUsrList.h
	* job handler for job PnlWzemUsrList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef PNLWZEMUSRLIST_H
#define PNLWZEMUSRLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "QryWzemUsrList.h"

#define VecVWzemUsrListDo PnlWzemUsrList::VecVDo

#define ContIacWzemUsrList PnlWzemUsrList::ContIac
#define ContInfWzemUsrList PnlWzemUsrList::ContInf
#define StatShrWzemUsrList PnlWzemUsrList::StatShr
#define StgIacWzemUsrList PnlWzemUsrList::StgIac
#define TagWzemUsrList PnlWzemUsrList::Tag

#define DpchAppWzemUsrListData PnlWzemUsrList::DpchAppData
#define DpchAppWzemUsrListDo PnlWzemUsrList::DpchAppDo
#define DpchEngWzemUsrListData PnlWzemUsrList::DpchEngData

/**
	* PnlWzemUsrList
	*/
class PnlWzemUsrList : public JobWzem {

public:
	/**
		* VecVDo (full: VecVWzemUsrListDo)
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
	  * ContIac (full: ContIacWzemUsrList)
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
	  * ContInf (full: ContInfWzemUsrList)
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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzemUsrList)
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
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacWzemUsrList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TCOGRPWIDTH = 1;
		static const Sbecore::uint TCOOWNWIDTH = 2;
		static const Sbecore::uint TCOPRSWIDTH = 3;
		static const Sbecore::uint TCOSRFWIDTH = 4;
		static const Sbecore::uint TCOUSGWIDTH = 5;
		static const Sbecore::uint TCOSTEWIDTH = 6;
		static const Sbecore::uint TCOLCLWIDTH = 7;
		static const Sbecore::uint TCOULVWIDTH = 8;

	public:
		StgIac(const Sbecore::uint TcoGrpWidth = 100, const Sbecore::uint TcoOwnWidth = 100, const Sbecore::uint TcoPrsWidth = 100, const Sbecore::uint TcoSrfWidth = 100, const Sbecore::uint TcoUsgWidth = 100, const Sbecore::uint TcoSteWidth = 100, const Sbecore::uint TcoLclWidth = 100, const Sbecore::uint TcoUlvWidth = 100);

	public:
		Sbecore::uint TcoGrpWidth;
		Sbecore::uint TcoOwnWidth;
		Sbecore::uint TcoPrsWidth;
		Sbecore::uint TcoSrfWidth;
		Sbecore::uint TcoUsgWidth;
		Sbecore::uint TcoSteWidth;
		Sbecore::uint TcoLclWidth;
		Sbecore::uint TcoUlvWidth;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagWzemUsrList)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzemUsrListData)
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
		QryWzemUsrList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzemUsrListDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzemUsrListData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFCsiQst = NULL, Sbecore::Xmlio::Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListWzemQUsrList* rst = NULL, QryWzemUsrList::StatShr* statshrqry = NULL, QryWzemUsrList::StgIac* stgiacqry = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFCsiQst;
		Sbecore::Xmlio::Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListWzemQUsrList rst;
		QryWzemUsrList::StatShr statshrqry;
		QryWzemUsrList::StgIac stgiacqry;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsWzem* dbswzem);

public:
	PnlWzemUsrList(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemUsrList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Sbecore::Xmlio::Feed feedFCsiQst;
	Sbecore::Xmlio::Feed feedFTos;

	QryWzemUsrList* qry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

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
	void handleDpchAppDataStgiacqry(DbsWzem* dbswzem, QryWzemUsrList::StgIac* _stgiacqry, DpchEngWzem** dpcheng);

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

