/**
	* \file Wzem.cpp
	* Wzem global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "Wzem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixWzemVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixWzemVLop == VecWzemVLop::INS) insert(refsList, refsPool, ref);
	else if (ixWzemVLop == VecWzemVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsPool.size(); i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixWzemVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixWzemVOolop == VecWzemVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixWzemVOolop == VecWzemVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixWzemVOolop == VecWzemVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixWzemVOolop == VecWzemVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixWzemVOolop == VecWzemVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixWzemVOolop == VecWzemVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref1) {
			for (auto itList2 = refsList.begin(); itList2 != refsList.end(); itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	FILE* file;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename += "." + ext;

		file = fopen(filename.c_str(), "w+x");

		if (file) {
			fclose(file);
			valid = true;
		} else if (errno != EEXIST) break;
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// mkdir() fails if folder exists
#ifdef _WIN32
		valid = (mkdir(foldername.c_str()) == 0);
#else
		valid = (mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
#endif

		if (!valid) if (errno != EEXIST) break;
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i = 0; i < 8; i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- INSERT

/******************************************************************************
 namespace Wzem
 ******************************************************************************/

// IP gbl --- INSERT

/******************************************************************************
 namespace OpengWzem
 ******************************************************************************/

void OpengWzem::getIcsWzemVOppackByIxWzemVOpengtype(
			const uint ixWzemVOpengtype
			, vector<uint>& icsWzemVOppack
		) {
	icsWzemVOppack.clear();

};

void OpengWzem::getIcsWzemVDpchByIxWzemVOppack(
			const uint ixWzemVOppack
			, set<uint>& icsWzemVDpch
		) {
};

/******************************************************************************
 namespace StubWzem
 ******************************************************************************/

string StubWzem::getStub(
			DbsWzem* dbswzem
			, const uint ixWzemVStub
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	if (ixWzemVStub == VecWzemVStub::STUBWZEMCALSTD) return getStubCalStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMCLNSTD) return getStubClnStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMDCHSTD) return getStubDchStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMEVTSTD) return getStubEvtStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMGROUP) return getStubGroup(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMJOBSTD) return getStubJobStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMJOBXJREF) return getStubJobXjref(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMNDESTD) return getStubNdeStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMNDEXNREF) return getStubNdeXnref(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMOPXSTD) return getStubOpxStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMOWNER) return getStubOwner(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMPRDSTD) return getStubPrdStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMPRSSTD) return getStubPrsStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMPSTSTD) return getStubPstStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMSESMENU) return getStubSesMenu(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMSESSTD) return getStubSesStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMUSGSTD) return getStubUsgStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzemVStub == VecWzemVStub::STUBWZEMUSRSTD) return getStubUsrStd(dbswzem, ref, ixWzemVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubWzem::getStubCalStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "CallBrlyDlgClose by:123 argInv=1 argRet=2"
	string stub;

	WzemMCall* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMCALSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no call)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmcall->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCalStd --- IBEGIN
			stub = rec->srefIxVCall + " by:" + getStubJobXjref(dbswzem, rec->refWzemMJob, ixWzemVLocale, ixVNonetype, stcch, &stref);
			if (rec->argInv != "") stub += " argInv=" + rec->argInv;
			if (rec->argRet != "") stub += " argRet=" + rec->argRet;
			// IP getStubCalStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubClnStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "stmgr CallIdecHusrRunvMod.crdUsrEq (spec:2)"
	string stub;

	WzemMClstn* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMCLNSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no call listener)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmclstn->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubClnStd --- IBEGIN
			if (rec->ixVTarget != VecWzemVMClstnTarget::JOB) stub = VecWzemVMClstnJobmask::getSref(rec->ixVTarget) + " ";

			stub += rec->srefIxVCall + " (" + VecWzemVMClstnJobmask::getSref(rec->ixVJobmask);

			if (rec->ixVJobmask == VecWzemVMClstnJobmask::SPEC) stub += ":" + getStubJobXjref(dbswzem, rec->tjbRefWzemMJob, ixWzemVLocale, ixVNonetype, stcch, &stref);

			stub += ")";
			// IP getStubClnStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubDchStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "DpchRetBrlyDnsmapCollect"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMDCHSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no dispatch)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmdpch->loadDchByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubEvtStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "[000123.456789] handleReqXyz"
	string stub;

	WzemMEvent* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMEVTSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no event)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmevent->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubEvtStd --- IBEGIN
			string s;
			vector<string> ss;

			size_t ptr;

			stub = "[" + to_string(rec->startu) + "] " + VecWzemVMEventBasetype::getSref(rec->ixVBasetype);

			if ((rec->ixVBasetype == VecWzemVMEventBasetype::ADDNODE) || (rec->ixVBasetype == VecWzemVMEventBasetype::REMOVENODE)) {
				stub += ":" + getStubNdeXnref(dbswzem, rec->refWzemMNode, ixWzemVLocale, ixVNonetype, stcch, &stref);
			} else if (rec->ixVBasetype != VecWzemVMEventBasetype::FINALIZECALL) {
				stub += ":" + getStubJobXjref(dbswzem, rec->refWzemMJob, ixWzemVLocale, ixVNonetype, stcch, &stref);
			};

			if (rec->ixVBasetype == VecWzemVMEventBasetype::ADDJOB) {
				// ex.: [122.456] addJob:1 PnlBrlyLocMap sup:1
				StrMod::stringToVector(getStubJobStd(dbswzem, rec->refWzemMJob, ixWzemVLocale, ixVNonetype, stcch, &stref), ss, ' ');
				if (ss.size() == 3) stub += " " + ss[0] + " " + ss[2];

			} else if ((rec->ixVBasetype == VecWzemVMEventBasetype::ADDCLSTN) || (rec->ixVBasetype == VecWzemVMEventBasetype::CHANGECLSTNARG) || (rec->ixVBasetype == VecWzemVMEventBasetype::REMOVECLSTN)) {
				// ex.: [122.456] addClstn:1/stmgr CallXyz spec:2
				s = getStubClnStd(dbswzem, rec->refWzemMClstn, ixWzemVLocale, ixVNonetype, stcch, &stref);

				if (s.find("stmgr ") == 0) {
					stub += "/stmgr";
					s = s.substr(6);
				};

				StrMod::stringToVector(s, ss, ' ');
				if (ss.size() == 2) {
					stub += " " + ss[0];
					if (ss[1].length() > 2) stub += " " + ss[1].substr(1, ss[1].length()-2);
				};

			} else if ((rec->ixVBasetype == VecWzemVMEventBasetype::ADDPRESET) || (rec->ixVBasetype == VecWzemVMEventBasetype::CHANGEPRESET) || (rec->ixVBasetype == VecWzemVMEventBasetype::REMOVEPRESET)) {
				// ex.: [122.456] addPreset:1 jrefSess=123
				WzemJMPresetArg* pstJarg = NULL;

				s = getStubPstStd(dbswzem, rec->refWzemMPreset, ixWzemVLocale, ixVNonetype, stcch, &stref);

				ptr = s.find('=');
				if (ptr != string::npos) {
					if (rec->ixVBasetype == VecWzemVMEventBasetype::CHANGEPRESET) {
						// jump override
						if (dbswzem->tblwzemjmpresetarg->loadRecBySQL("SELECT * FROM TblWzemJMPresetArg WHERE refWzemMPreset = " + to_string(rec->refWzemMPreset) + " AND x1Startu = " + to_string(rec->startu), &pstJarg)) {
							s = s.substr(0, ptr+1) + pstJarg->arg;
							delete pstJarg;
						};

					} else if (rec->ixVBasetype == VecWzemVMEventBasetype::REMOVEPRESET) s = s.substr(0, ptr);
				};

				stub += " " + s;

			} else if (rec->ixVBasetype == VecWzemVMEventBasetype::ADDNODE) {
				// ex.: [122.456] addNode:1 127.0.0.1:13100 x4
				s = getStubNdeStd(dbswzem, rec->refWzemMNode, ixWzemVLocale, ixVNonetype, stcch, &stref);

				StrMod::stringToVector(s, ss, ' ');
				if (ss.size() == 3) stub += " " + ss[0] + " " + ss[2];

			} else if ((rec->ixVBasetype == VecWzemVMEventBasetype::TRIGGERCALL) || (rec->ixVBasetype == VecWzemVMEventBasetype::HANDLECALL) || (rec->ixVBasetype == VecWzemVMEventBasetype::RETCALL)
						 || (rec->ixVBasetype == VecWzemVMEventBasetype::FINALIZECALL)) {
				// ex.: [122.456] triggerCall:1 CallXyz argInv=xyz
				// ex.: [122.456] handleCall:2 CallXyz by:123
				// ex.: [122.456] retCall:2 CallXyz by:123 argRet=bla
				// ex.: [122.456] finalizeCall CallXyz by:123
				WzemJMCallArgRet* calJret = NULL;

				StrMod::stringToVector(getStubCalStd(dbswzem, rec->refWzemMCall, ixWzemVLocale, ixVNonetype, stcch, &stref), ss, ' ');

				if (ss.size() > 0) stub += " " + ss[0];
				if ((ss.size() > 1) && ((rec->ixVBasetype == VecWzemVMEventBasetype::HANDLECALL) || (rec->ixVBasetype == VecWzemVMEventBasetype::RETCALL) || (rec->ixVBasetype == VecWzemVMEventBasetype::FINALIZECALL))) stub += " " + ss[1];
				if ((ss.size() > 2) && (rec->ixVBasetype == VecWzemVMEventBasetype::TRIGGERCALL)) stub += " " + ss[2];

				if (rec->ixVBasetype == VecWzemVMEventBasetype::RETCALL) {
					// jump override
					if (dbswzem->tblwzemjmcallargret->loadRecBySQL("SELECT * FROM TblWzemJMCallArgRet WHERE refWzemMCall = " + to_string(rec->refWzemMCall) + " AND x1Startu = " + to_string(rec->startu), &calJret)) {
						stub += " argRet=" + calJret->argRet;
						delete calJret;
					};
				};

			} else if (rec->ixVBasetype == VecWzemVMEventBasetype::HANDLEREQCMD) {
				if (rec->Cmd != "") stub += " " + rec->Cmd;

			} else if ((rec->ixVBasetype == VecWzemVMEventBasetype::HANDLEREQDPCHAPP) || (rec->ixVBasetype == VecWzemVMEventBasetype::REPLYREQDPCHAPP) || (rec->ixVBasetype == VecWzemVMEventBasetype::SUBMITDPCH)) {
				// ex.: [122.456] replyReqRegular:1 DpchEngBrlyConfirm
				stub += " " + getStubDchStd(dbswzem, rec->refWzemMDpch, ixWzemVLocale, ixVNonetype, stcch, &stref);

			} else if ((rec->ixVBasetype == VecWzemVMEventBasetype::HANDLEREQUPLOAD) || (rec->ixVBasetype == VecWzemVMEventBasetype::REPLYREQDOWNLOAD)) {
				// ex.: [122.456] handleReqUpload:1 xyz.txt
				if (rec->Filename != "") {
					ptr = rec->Filename.rfind('/');

					if (ptr == string::npos) stub += " " + rec->Filename;
					else stub += " " + rec->Filename.substr(ptr+1);
				};

			} else if ((rec->ixVBasetype == VecWzemVMEventBasetype::HANDLEREQDPCHRET) || (rec->ixVBasetype == VecWzemVMEventBasetype::ADDINV)) {
				// ex.: [122.456] handleReqRet:1 DpchRetBrlyDnsmapCollect op:3
				stub += " " + getStubDchStd(dbswzem, rec->refWzemMDpch, ixWzemVLocale, ixVNonetype, stcch, &stref);
				stub += " op:" + getStubOpxStd(dbswzem, rec->refWzemMOp, ixWzemVLocale, ixVNonetype, stcch, &stref);

			} else if (rec->ixVBasetype == VecWzemVMEventBasetype::HANDLEREQTIMER) {
				if (rec->xsref != "") stub += " " + rec->xsref;
			};
			// IP getStubEvtStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubGroup(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "agroup"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMGROUP, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubJobStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "PnlBrlyLocMap (7) sup:5"
	string stub;

	WzemMJob* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMJOBSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no job)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmjob->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubJobStd --- IBEGIN
			stub = rec->srefIxVJob + " (" + to_string(rec->xjref) + ")";
			if (rec->supRefWzemMJob != 0) stub += " sup:" + getStubJobXjref(dbswzem, rec->supRefWzemMJob, ixWzemVLocale, ixVNonetype, stcch, &stref);
			// IP getStubJobStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubJobXjref(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "1234"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMJOBXJREF, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no job)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmjob->loadXjrByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubNdeStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "127.0.0.1:13300 (1) x3"
	string stub;

	WzemMNode* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMNDESTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no node)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmnode->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubNdeStd --- IBEGIN
			stub = rec->Ip + ":" + to_string(rec->Port) + " (" + to_string(rec->xnref) + ") x" + to_string(rec->Opprcn);
			// IP getStubNdeStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubNdeXnref(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "3"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMNDEXNREF, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no node)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmnode->loadXnrByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubOpxStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "1234"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMOPXSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no operation)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmop->loadXorByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubOwner(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "auser"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMOWNER, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubPrdStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "BeamRelay 0.1.60 2016-01-03 12:34:56"
	string stub;

	WzemMPeriod* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMPRDSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no monitoring period)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmperiod->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPrdStd --- IBEGIN
			stub = rec->Version + " " + Ftm::stamp(rec->start);
			// IP getStubPrdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubPrsStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	WzemMPerson* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMPRSSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no person)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzemPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			// IP getStubWzemPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubPstStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "adm=true"
	string stub;

	WzemMPreset* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMPSTSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no presetting)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmpreset->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPstStd --- IBEGIN
			stub = StrMod::uncap(rec->srefIxVPreset.substr(3+4)) + "=" + rec->arg;
			// IP getStubPstStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubSesMenu(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "user fkuntz / Franz Kuntz;logged in from 127.0.0.1;since 01-01-2010 10:34"
	string stub;

	WzemMSession* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMSESMENU, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzemSesMenu --- BEGIN
			if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "user " + getStubUsrStd(dbswzem, rec->refWzemMUser, ixWzemVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			// IP getStubWzemSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubSesStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "01-01-2010 10:34 from 127.0.0.1"
	string stub;

	WzemMSession* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMSESSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzemSesStd --- BEGIN
			if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			// IP getStubWzemSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzem::getStubUsgStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "super"
	string stub;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMUSGSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzem::getStubUsrStd(
			DbsWzem* dbswzem
			, const ubigint ref
			, const uint ixWzemVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "fkuntz / Franz Kuntz"
	string stub;

	WzemMUser* rec = NULL;

	stcchitemref_t stref(VecWzemVStub::STUBWZEMUSRSTD, ref, ixWzemVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzemVLocale == VecWzemVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswzem->tblwzemmuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzemUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbswzem, rec->refWzemMPerson, ixWzemVLocale, ixVNonetype, stcch, &stref);
			// IP getStubWzemUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class WzemException
 ******************************************************************************/

WzemException::WzemException(
			const uint ix
			, const map<string,string>& vals
		) :
			SbeException(ix, vals)
		{
};

string WzemException::getSref() {
	string sref = SbeException::getSref();
	if (sref != "") return sref;
	
	
	return("");
};

/******************************************************************************
 class ContInfWzemAlert
 ******************************************************************************/

ContInfWzemAlert::ContInfWzemAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) :
			Block()
		{
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;
	this->TxtMsg11 = TxtMsg11;
	this->TxtMsg12 = TxtMsg12;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfWzemAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

void ContInfWzemAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzemAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfWzemAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg11", TxtMsg11);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg12", TxtMsg12);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfWzemAlert::compare(
			const ContInfWzemAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchWzem
 ******************************************************************************/

DpchWzem::DpchWzem(
			const uint ixWzemVDpch
		) {
	this->ixWzemVDpch = ixWzemVDpch;
};

DpchWzem::~DpchWzem() {
};

/******************************************************************************
 class DpchInvWzem
 ******************************************************************************/

DpchInvWzem::DpchInvWzem(
			const uint ixWzemVDpch
			, const ubigint oref
			, const ubigint jref
		) :
			DpchWzem(ixWzemVDpch)
		{
	this->oref = oref;
	this->jref = jref;
};

DpchInvWzem::~DpchInvWzem() {
};

void DpchInvWzem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWzem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvWzem::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWzem");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWzem
 ******************************************************************************/

DpchRetWzem::DpchRetWzem(
			const uint ixWzemVDpch
			, const string& scrOref
			, const string& scrJref
			, const utinyint ixOpVOpres
			, const utinyint pdone
		) :
			DpchWzem(ixWzemVDpch)
		{
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->ixOpVOpres = ixOpVOpres;
	this->pdone = pdone;
};

DpchRetWzem::~DpchRetWzem() {
};

void DpchRetWzem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWzem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
	};
};

void DpchRetWzem::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWzem");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzem");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
	xmlTextWriterEndElement(wr);
};







