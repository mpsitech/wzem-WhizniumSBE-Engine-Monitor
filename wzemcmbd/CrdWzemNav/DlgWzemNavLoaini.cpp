/**
	* \file DlgWzemNavLoaini.cpp
	* job handler for job DlgWzemNavLoaini (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZEMCMBD
	#include <Wzemcmbd.h>
#else
	#include <Wzemd.h>
#endif

#include "DlgWzemNavLoaini.h"

#include "DlgWzemNavLoaini_blks.cpp"
#include "DlgWzemNavLoaini_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWzemNavLoaini
 ******************************************************************************/

DlgWzemNavLoaini::DlgWzemNavLoaini(
			XchgWzem* xchg
			, DbsWzem* dbswzem
			, const ubigint jrefSup
			, const uint ixWzemVLocale
		) :
			JobWzem(xchg, VecWzemVJob::DLGWZEMNAVLOAINI, jrefSup, ixWzemVLocale)
		{
	jref = xchg->addJob(dbswzem, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWzemVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new JobWzemIexIni(xchg, dbswzem, jref, ixWzemVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzem, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWzemNavLoaini::~DlgWzemNavLoaini() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzem* DlgWzemNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzem* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzemConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWzemNavLoaini::refreshIfi(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

	// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbswzem);

	// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgWzemNavLoaini::refreshImp(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	StatShrImp oldStatshrimp(statshrimp);
	ContInfImp oldContinfimp(continfimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswzem);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswzem);
	statshrimp.ButStoActive = evalImpButStoActive(dbswzem);

	// IP refreshImp --- REND
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
};

void DlgWzemNavLoaini::refreshLfi(
			DbsWzem* dbswzem
			, set<uint>& moditems
		) {
	ContInfLfi oldContinflfi(continflfi);
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- BEGIN
	// continflfi

	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswzem);

	// IP refreshLfi --- END
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgWzemNavLoaini::refresh(
			DbsWzem* dbswzem
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswzem);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshIfi(dbswzem, moditems);
	refreshImp(dbswzem, moditems);
	refreshLfi(dbswzem, moditems);

	muteRefresh = false;
};

void DlgWzemNavLoaini::handleRequest(
			DbsWzem* dbswzem
			, ReqWzem* req
		) {
	if (req->ixVBasetype == ReqWzem::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMINIT) {
			handleDpchAppWzemInit(dbswzem, (DpchAppWzemInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPDLGWZEMNAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzem, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPDLGWZEMNAVLOAINIDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswzem, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbswzem, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbswzem, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMALERT) {
			handleDpchAppWzemAlert(dbswzem, (DpchAppWzemAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswzem, req->filename);

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswzem);

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswzem, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswzem);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswzem, req->sref);
	};
};

void DlgWzemNavLoaini::handleDpchAppWzemInit(
			DbsWzem* dbswzem
			, DpchAppWzemInit* dpchappwzeminit
			, DpchEngWzem** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWzemNavLoaini::handleDpchAppDataContiac(
			DbsWzem* dbswzem
			, ContIac* _contiac
			, DpchEngWzem** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswzem, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWzemNavLoaini::handleDpchAppDoButDneClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngWzemConfirm(true, jref, "");
		xchg->triggerCall(dbswzem, VecWzemVCall::CALLWZEMDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgWzemNavLoaini::handleDpchAppDoImpButRunClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswzem, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWzemNavLoaini::handleDpchAppDoImpButStoClick(
			DbsWzem* dbswzem
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWzemNavLoaini::handleDpchAppWzemAlert(
			DbsWzem* dbswzem
			, DpchAppWzemAlert* dpchappwzemalert
			, DpchEngWzem** dpcheng
		) {
	// IP handleDpchAppWzemAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRWZEMPER) {
		changeStage(dbswzem, nextIxVSgeSuccess);
	} else if (ixVSge == VecVSge::ALRWZEMIER) {
		if (dpchappwzemalert->numFMcb == 2) iex->reverse(dbswzem);
		changeStage(dbswzem, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWzemAlert --- IEND
};

void DlgWzemNavLoaini::handleUploadInSgeIdle(
			DbsWzem* dbswzem
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswzem, VecVSge::PRSIDLE);
};

string DlgWzemNavLoaini::handleDownloadInSgeDone(
			DbsWzem* dbswzem
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

void DlgWzemNavLoaini::handleTimerInSgePrsidle(
			DbsWzem* dbswzem
			, const string& sref
		) {
	changeStage(dbswzem, nextIxVSgeSuccess);
};

void DlgWzemNavLoaini::handleTimerWithSrefMonInSgeImport(
			DbsWzem* dbswzem
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswzem); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWzemNavLoaini::handleTimerInSgeImpidle(
			DbsWzem* dbswzem
			, const string& sref
		) {
	changeStage(dbswzem, nextIxVSgeSuccess);
};

void DlgWzemNavLoaini::changeStage(
			DbsWzem* dbswzem
			, uint _ixVSge
			, DpchEngWzem** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzem); break;
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbswzem); break;
				case VecVSge::PARSE: leaveSgeParse(dbswzem); break;
				case VecVSge::ALRWZEMPER: leaveSgeAlrwzemper(dbswzem); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswzem); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbswzem); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswzem); break;
				case VecVSge::ALRWZEMIER: leaveSgeAlrwzemier(dbswzem); break;
				case VecVSge::DONE: leaveSgeDone(dbswzem); break;
			};

			setStage(dbswzem, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswzem, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzem, reenter); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbswzem, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswzem, reenter); break;
			case VecVSge::ALRWZEMPER: _ixVSge = enterSgeAlrwzemper(dbswzem, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswzem, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbswzem, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswzem, reenter); break;
			case VecVSge::ALRWZEMIER: _ixVSge = enterSgeAlrwzemier(dbswzem, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzem, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWzemNavLoaini::getSquawk(
			DbsWzem* dbswzem
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWZEMPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWZEMIER) ) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRWZEMPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWZEMIER) retval = "import error";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWzemNavLoaini::enterSgeIdle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWzemNavLoaini::leaveSgeIdle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWzemNavLoaini::enterSgePrsidle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWzemNavLoaini::leaveSgePrsidle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWzemNavLoaini::enterSgeParse(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZEMPER;

	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	iex->reset(dbswzem);

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("IexWzemIni") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) iex->parseFromFile(dbswzem, infilename, false, "");
	else if (ifixml) iex->parseFromFile(dbswzem, infilename, true, "");

	if (iex->ixVSge != JobWzemIexIni::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWzemIexIni::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswzem) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWzemNavLoaini::leaveSgeParse(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWzemNavLoaini::enterSgeAlrwzemper(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZEMPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwzemper --- RBEGIN
	ContInfWzemAlert continf;

	continf.TxtCpt = VecWzemVTag::getTitle(VecWzemVTag::ERROR, ixWzemVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWzemIexIni::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswzem);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWzemVTag::appendToFeed(VecWzemVTag::OK, ixWzemVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWzemAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzemAlert::ALL}));
	// IP enterSgeAlrwzemper --- REND

	return retval;
};

void DlgWzemNavLoaini::leaveSgeAlrwzemper(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeAlrwzemper --- INSERT
};

uint DlgWzemNavLoaini::enterSgePrsdone(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWzemNavLoaini::leaveSgePrsdone(
			DbsWzem* dbswzem
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWzemNavLoaini::enterSgeImpidle(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWzemNavLoaini::leaveSgeImpidle(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWzemNavLoaini::enterSgeImport(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZEMIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- IBEGIN
	iex->import(dbswzem);

	if (iex->ixVSge == JobWzemIexIni::VecVSge::IMPERR) retval = nextIxVSgeFailure;
	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWzemNavLoaini::leaveSgeImport(
			DbsWzem* dbswzem
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWzemNavLoaini::enterSgeAlrwzemier(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZEMIER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwzemier --- RBEGIN
	if (reqCmd) {
		cout << "\t" << iex->getSquawk(dbswzem) << endl;
		retval = nextIxVSgeSuccess;
	} else {
		xchg->submitDpch(AlrWzem::prepareAlrIer(jref, ixWzemVLocale, iex->getSquawk(dbswzem), feedFMcbAlert));
	};
	// IP enterSgeAlrwzemier --- REND

	return retval;
};

void DlgWzemNavLoaini::leaveSgeAlrwzemier(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeAlrwzemier --- INSERT
};

uint DlgWzemNavLoaini::enterSgeDone(
			DbsWzem* dbswzem
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWzemNavLoaini::leaveSgeDone(
			DbsWzem* dbswzem
		) {
	// IP leaveSgeDone --- INSERT
};
