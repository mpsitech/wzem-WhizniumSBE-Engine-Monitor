/**
	* \file PnlWzemPstHeadbar.h
	* job handler for job PnlWzemPstHeadbar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef PNLWZEMPSTHEADBAR_H
#define PNLWZEMPSTHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWzemPstHeadbar PnlWzemPstHeadbar::StgInf
#define TagWzemPstHeadbar PnlWzemPstHeadbar::Tag

#define DpchEngWzemPstHeadbarData PnlWzemPstHeadbar::DpchEngData

/**
	* PnlWzemPstHeadbar
	*/
class PnlWzemPstHeadbar : public JobWzem {

public:
	/**
		* StgInf (full: StgInfWzemPstHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWzemPstHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWzemPstHeadbarData)
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
	PnlWzemPstHeadbar(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~PnlWzemPstHeadbar();

public:

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

	void handleDpchAppWzemInit(DbsWzem* dbswzem, DpchAppWzemInit* dpchappwzeminit, DpchEngWzem** dpcheng);

};

#endif

