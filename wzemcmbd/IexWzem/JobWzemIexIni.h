/**
	* \file JobWzemIexIni.h
	* job handler for job JobWzemIexIni (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef JOBWZEMIEXINI_H
#define JOBWZEMIEXINI_H

#include "IexWzemIni.h"

// IP include.cust --- INSERT

#define VecVJobWzemIexIniSge JobWzemIexIni::VecVSge

/**
	* JobWzemIexIni
	*/
class JobWzemIexIni : public JobWzem {

public:
	/**
		* VecVSge (full: VecVJobWzemIexIniSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint PARSE = 2;
		static const Sbecore::uint PRSERR = 3;
		static const Sbecore::uint PRSDONE = 4;
		static const Sbecore::uint IMPORT = 5;
		static const Sbecore::uint IMPERR = 6;
		static const Sbecore::uint REVERSE = 7;
		static const Sbecore::uint COLLECT = 8;
		static const Sbecore::uint CLTDONE = 9;
		static const Sbecore::uint EXPORT = 10;
		static const Sbecore::uint DONE = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

public:
	JobWzemIexIni(XchgWzem* xchg, DbsWzem* dbswzem, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzemVLocale);
	~JobWzemIexIni();

public:

	std::string fullpath;
	bool xmlNotTxt;
	std::string rectpath;

	Sbecore::uint lineno;
	Sbecore::uint impcnt;

	std::map<Sbecore::uint,Sbecore::uint> icsWzemVIop;

	bool shorttags;

	IexWzemIni::ImeIAVControlPar imeiavcontrolpar;
	IexWzemIni::ImeIAVKeylistKey imeiavkeylistkey;
	IexWzemIni::ImeIAVValuelistVal imeiavvaluelistval;
	IexWzemIni::ImeIMUsergroup imeimusergroup;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void reset(DbsWzem* dbswzem);

	void parseFromFile(DbsWzem* dbswzem, const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = "");
	void import(DbsWzem* dbswzem);
	void reverse(DbsWzem* dbswzem);
	void collect(DbsWzem* dbswzem, const std::map<Sbecore::uint,Sbecore::uint>& _icsWzemVIop = IexWzemIni::icsWzemVIopInsAll());
	void exportToFile(DbsWzem* dbswzem, const std::string& _fullpath, const bool _xmlNotTxt, const bool _shorttags = true);

public:

public:
	void handleRequest(DbsWzem* dbswzem, ReqWzem* req);

private:

private:
	void changeStage(DbsWzem* dbswzem, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWzem* dbswzem);

private:
	Sbecore::uint enterSgeIdle(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeIdle(DbsWzem* dbswzem);
	Sbecore::uint enterSgeParse(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeParse(DbsWzem* dbswzem);
	Sbecore::uint enterSgePrserr(DbsWzem* dbswzem, const bool reenter);
	void leaveSgePrserr(DbsWzem* dbswzem);
	Sbecore::uint enterSgePrsdone(DbsWzem* dbswzem, const bool reenter);
	void leaveSgePrsdone(DbsWzem* dbswzem);
	Sbecore::uint enterSgeImport(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeImport(DbsWzem* dbswzem);
	Sbecore::uint enterSgeImperr(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeImperr(DbsWzem* dbswzem);
	Sbecore::uint enterSgeReverse(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeReverse(DbsWzem* dbswzem);
	Sbecore::uint enterSgeCollect(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeCollect(DbsWzem* dbswzem);
	Sbecore::uint enterSgeCltdone(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeCltdone(DbsWzem* dbswzem);
	Sbecore::uint enterSgeExport(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeExport(DbsWzem* dbswzem);
	Sbecore::uint enterSgeDone(DbsWzem* dbswzem, const bool reenter);
	void leaveSgeDone(DbsWzem* dbswzem);

};

#endif







