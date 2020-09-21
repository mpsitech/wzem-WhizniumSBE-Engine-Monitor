/**
	* \file PnlWzemPrdHeadbar.h
	* job handler for job PnlWzemPrdHeadbar (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef PNLWZEMPRDHEADBAR_H
#define PNLWZEMPRDHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWzemPrdHeadbar PnlWzemPrdHeadbar::StgInf
#define TagWzemPrdHeadbar PnlWzemPrdHeadbar::Tag

#define DpchEngWzemPrdHeadbarData PnlWzemPrdHeadbar::DpchEngData

/**
	* PnlWzemPrdHeadbar
	*/
class PnlWzemPrdHeadbar : public JobWzem {

public:
	/**
		* StgInf (full: StgInfWzemPrdHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWzemPrdHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWzemPrdHeadbarData)
		*/
	class DpchEngData : public DpchEngWzem {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzem* dpcheng);

		void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
	};

public:
	PnlWzemPrdHeadbar(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemPrdHeadbar();

public:

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

};

#endif

