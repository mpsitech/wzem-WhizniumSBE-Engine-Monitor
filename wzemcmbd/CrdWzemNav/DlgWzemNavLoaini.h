/**
	* \file DlgWzemNavLoaini.h
	* job handler for job DlgWzemNavLoaini (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef DLGWZEMNAVLOAINI_H
#define DLGWZEMNAVLOAINI_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzemIexIni.h"

#define VecVDlgWzemNavLoainiDit DlgWzemNavLoaini::VecVDit
#define VecVDlgWzemNavLoainiDo DlgWzemNavLoaini::VecVDo
#define VecVDlgWzemNavLoainiDoImp DlgWzemNavLoaini::VecVDoImp
#define VecVDlgWzemNavLoainiSge DlgWzemNavLoaini::VecVSge

#define ContIacDlgWzemNavLoaini DlgWzemNavLoaini::ContIac
#define ContInfDlgWzemNavLoaini DlgWzemNavLoaini::ContInf
#define ContInfDlgWzemNavLoainiImp DlgWzemNavLoaini::ContInfImp
#define ContInfDlgWzemNavLoainiLfi DlgWzemNavLoaini::ContInfLfi
#define StatAppDlgWzemNavLoaini DlgWzemNavLoaini::StatApp
#define StatShrDlgWzemNavLoaini DlgWzemNavLoaini::StatShr
#define StatShrDlgWzemNavLoainiIfi DlgWzemNavLoaini::StatShrIfi
#define StatShrDlgWzemNavLoainiImp DlgWzemNavLoaini::StatShrImp
#define StatShrDlgWzemNavLoainiLfi DlgWzemNavLoaini::StatShrLfi
#define TagDlgWzemNavLoaini DlgWzemNavLoaini::Tag
#define TagDlgWzemNavLoainiIfi DlgWzemNavLoaini::TagIfi
#define TagDlgWzemNavLoainiImp DlgWzemNavLoaini::TagImp
#define TagDlgWzemNavLoainiLfi DlgWzemNavLoaini::TagLfi

#define DpchAppDlgWzemNavLoainiData DlgWzemNavLoaini::DpchAppData
#define DpchAppDlgWzemNavLoainiDo DlgWzemNavLoaini::DpchAppDo
#define DpchEngDlgWzemNavLoainiData DlgWzemNavLoaini::DpchEngData

/**
	* DlgWzemNavLoaini
	*/
class DlgWzemNavLoaini : public JobWzem {

public:
	/**
		* VecVDit (full: VecVDlgWzemNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint LFI = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzemVLocale);

		static void fillFeed(const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgWzemNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWzemNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWzemNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PRSIDLE = 2;
		static const Sbecore::uint PARSE = 3;
		static const Sbecore::uint ALRWZEMPER = 4;
		static const Sbecore::uint PRSDONE = 5;
		static const Sbecore::uint IMPIDLE = 6;
		static const Sbecore::uint IMPORT = 7;
		static const Sbecore::uint ALRWZEMIER = 8;
		static const Sbecore::uint DONE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWzemNavLoaini)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWzemNavLoaini)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfImp (full: ContInfDlgWzemNavLoainiImp)
	  */
	class ContInfImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWzemNavLoainiLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
		* StatApp (full: StatAppDlgWzemNavLoaini)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdone = false, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWzemNavLoaini)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgWzemNavLoainiIfi)
		*/
	class StatShrIfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgWzemNavLoainiImp)
		*/
	class StatShrImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgWzemNavLoainiLfi)
		*/
	class StatShrLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
		* Tag (full: TagDlgWzemNavLoaini)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgWzemNavLoainiIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgWzemNavLoainiImp)
		*/
	class TagImp {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgWzemNavLoainiLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWzemNavLoainiData)
		*/
	class DpchAppData : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWzemNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWzemNavLoainiData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRIFI = 10;
		static const Sbecore::uint STATSHRIMP = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGIFI = 14;
		static const Sbecore::uint TAGIMP = 15;
		static const Sbecore::uint TAGLFI = 16;
		static const Sbecore::uint ALL = 17;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfLfi* continflfi = NULL, Sbecore::Xmlio::Feed* feedFDse = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

	bool evalButDneActive(DbsWzem* dbswzem);
	bool evalIfiUldActive(DbsWzem* dbswzem);
	bool evalLfiDldActive(DbsWzem* dbswzem);
	bool evalImpButRunActive(DbsWzem* dbswzem);
	bool evalImpButStoActive(DbsWzem* dbswzem);

public:
	DlgWzemNavLoaini(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~DlgWzemNavLoaini();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfLfi continflfi;
	StatShr statshr;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFDse;
	Sbecore::Xmlio::Feed feedFSge;

	JobWzemIexIni* iex;

	Sbecore::uint ixVDit;

	// IP vars.cust --- IBEGIN
	std::string infilename;
	// IP vars.cust --- IEND

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshIfi(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshImp(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshLfi(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);
	void handleDpchAppDataContiac(DbsWzem* dbswzem, ContIac* _contiac, DpchEngWzem** dpcheng);

	void handleDpchAppDoButDneClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsWzem* dbswzem, DpchEngWzem** dpcheng);
	void handleDpchAppWzemAlert(DbsWzem* dbswzem, DpchAppWzemAlert* dpchappwzemalert, DpchEngWzem** dpcheng);

	void handleUploadInSgeIdle(DbsWzem* dbswzem, const std::string& filename);

	std::string handleDownloadInSgeDone(DbsWzem* dbswzem);

	void handleTimerInSgePrsidle(DbsWzem* dbswzem, const std::string& sref);
	void handleTimerWithSrefMonInSgeImport(DbsWzem* dbswzem);
	void handleTimerInSgeImpidle(DbsWzem* dbswzem, const std::string& sref);

private:
	void changeStage(DbsWzem* dbswzem, Sbecore::uint _ixVSge, DpchEngWzem** dpcheng = NULL);

public:
	std::string getSquawk(DbsWzem* dbswzem);

private:
	Sbecore::uint enterSgeIdle(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeIdle(DbsWzem* dbswzem);
	Sbecore::uint enterSgePrsidle(DbsWzem* dbswzem, const bool reenter);
	void leaveSgePrsidle(DbsWzem* dbswzem);
	Sbecore::uint enterSgeParse(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeParse(DbsWzem* dbswzem);
	Sbecore::uint enterSgeAlrwzemper(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeAlrwzemper(DbsWzem* dbswzem);
	Sbecore::uint enterSgePrsdone(DbsWzem* dbswzem, const bool reenter);
	void leaveSgePrsdone(DbsWzem* dbswzem);
	Sbecore::uint enterSgeImpidle(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeImpidle(DbsWzem* dbswzem);
	Sbecore::uint enterSgeImport(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeImport(DbsWzem* dbswzem);
	Sbecore::uint enterSgeAlrwzemier(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeAlrwzemier(DbsWzem* dbswzem);
	Sbecore::uint enterSgeDone(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeDone(DbsWzem* dbswzem);

};

#endif




