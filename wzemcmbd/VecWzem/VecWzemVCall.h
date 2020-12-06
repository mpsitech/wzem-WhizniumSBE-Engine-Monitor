/**
	* \file VecWzemVCall.h
	* vector VecWzemVCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZEMVCALL_H
#define VECWZEMVCALL_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVCall
	*/
namespace VecWzemVCall {
	const Sbecore::uint CALLWZEMBOOLVALPRESET = 1;
	const Sbecore::uint CALLWZEMCAL_JOBEQ = 2;
	const Sbecore::uint CALLWZEMCALJRETMOD_CALEQ = 3;
	const Sbecore::uint CALLWZEMCALMOD = 4;
	const Sbecore::uint CALLWZEMCALMOD_JOBEQ = 5;
	const Sbecore::uint CALLWZEMCALUPD_REFEQ = 6;
	const Sbecore::uint CALLWZEMCLAIMCHG = 7;
	const Sbecore::uint CALLWZEMCLN_JOBEQ = 8;
	const Sbecore::uint CALLWZEMCLN_TJBEQ = 9;
	const Sbecore::uint CALLWZEMCLNJMOD_CLNEQ = 10;
	const Sbecore::uint CALLWZEMCLNMOD = 11;
	const Sbecore::uint CALLWZEMCLNMOD_JOBEQ = 12;
	const Sbecore::uint CALLWZEMCLNUPD_REFEQ = 13;
	const Sbecore::uint CALLWZEMCRDACTIVE = 14;
	const Sbecore::uint CALLWZEMCRDCLOSE = 15;
	const Sbecore::uint CALLWZEMCRDOPEN = 16;
	const Sbecore::uint CALLWZEMCTLAPARMOD_USREQ = 17;
	const Sbecore::uint CALLWZEMDATCHG = 18;
	const Sbecore::uint CALLWZEMDBLVALPRESET = 19;
	const Sbecore::uint CALLWZEMDCHMOD = 20;
	const Sbecore::uint CALLWZEMDCHUPD_REFEQ = 21;
	const Sbecore::uint CALLWZEMDLGCLOSE = 22;
	const Sbecore::uint CALLWZEMEVT_CALEQ = 23;
	const Sbecore::uint CALLWZEMEVT_CLNEQ = 24;
	const Sbecore::uint CALLWZEMEVT_CLUEQ = 25;
	const Sbecore::uint CALLWZEMEVT_DCHEQ = 26;
	const Sbecore::uint CALLWZEMEVT_JOBEQ = 27;
	const Sbecore::uint CALLWZEMEVT_NDEEQ = 28;
	const Sbecore::uint CALLWZEMEVT_OPXEQ = 29;
	const Sbecore::uint CALLWZEMEVT_PRDEQ = 30;
	const Sbecore::uint CALLWZEMEVT_PSTEQ = 31;
	const Sbecore::uint CALLWZEMEVTMOD = 32;
	const Sbecore::uint CALLWZEMEVTMOD_CLUEQ = 33;
	const Sbecore::uint CALLWZEMEVTMOD_PRDEQ = 34;
	const Sbecore::uint CALLWZEMEVTUPD_REFEQ = 35;
	const Sbecore::uint CALLWZEMHUSRRUNVMOD_CRDUSREQ = 36;
	const Sbecore::uint CALLWZEMINTVALPRESET = 37;
	const Sbecore::uint CALLWZEMIXPRESET = 38;
	const Sbecore::uint CALLWZEMJOB_PRDEQ = 39;
	const Sbecore::uint CALLWZEMJOB_SUPEQ = 40;
	const Sbecore::uint CALLWZEMJOBJDCLMOD_JOBEQ = 41;
	const Sbecore::uint CALLWZEMJOBJSTMMOD_JOBEQ = 42;
	const Sbecore::uint CALLWZEMJOBMOD = 43;
	const Sbecore::uint CALLWZEMJOBMOD_PRDEQ = 44;
	const Sbecore::uint CALLWZEMJOBMOD_SUPEQ = 45;
	const Sbecore::uint CALLWZEMJOBUPD_REFEQ = 46;
	const Sbecore::uint CALLWZEMKAKJKEYMOD_KLSAKEYEQ = 47;
	const Sbecore::uint CALLWZEMKLSAKEYMOD_KLSEQ = 48;
	const Sbecore::uint CALLWZEMKLSAKEYMOD_KLSMTBURFEQ = 49;
	const Sbecore::uint CALLWZEMLOG = 50;
	const Sbecore::uint CALLWZEMLOGOUT = 51;
	const Sbecore::uint CALLWZEMMONSTATCHG = 52;
	const Sbecore::uint CALLWZEMNDE_PRDEQ = 53;
	const Sbecore::uint CALLWZEMNDEMOD = 54;
	const Sbecore::uint CALLWZEMNDEMOD_PRDEQ = 55;
	const Sbecore::uint CALLWZEMNDEUPD_REFEQ = 56;
	const Sbecore::uint CALLWZEMNODECHG = 57;
	const Sbecore::uint CALLWZEMOPX_JOBEQ = 58;
	const Sbecore::uint CALLWZEMOPXMOD = 59;
	const Sbecore::uint CALLWZEMOPXMOD_JOBEQ = 60;
	const Sbecore::uint CALLWZEMOPXUPD_REFEQ = 61;
	const Sbecore::uint CALLWZEMPRDMOD = 62;
	const Sbecore::uint CALLWZEMPRDUPD_REFEQ = 63;
	const Sbecore::uint CALLWZEMPRSADETMOD_PRSEQ = 64;
	const Sbecore::uint CALLWZEMPRSJLNMMOD_PRSEQ = 65;
	const Sbecore::uint CALLWZEMPRSMOD = 66;
	const Sbecore::uint CALLWZEMPRSUPD_REFEQ = 67;
	const Sbecore::uint CALLWZEMPST_JOBEQ = 68;
	const Sbecore::uint CALLWZEMPSTJARGMOD_PSTEQ = 69;
	const Sbecore::uint CALLWZEMPSTMOD = 70;
	const Sbecore::uint CALLWZEMPSTMOD_JOBEQ = 71;
	const Sbecore::uint CALLWZEMPSTUPD_REFEQ = 72;
	const Sbecore::uint CALLWZEMRECACCESS = 73;
	const Sbecore::uint CALLWZEMREFPRESET = 74;
	const Sbecore::uint CALLWZEMREFSPRESET = 75;
	const Sbecore::uint CALLWZEMSESMOD = 76;
	const Sbecore::uint CALLWZEMSESMOD_USREQ = 77;
	const Sbecore::uint CALLWZEMSESUPD_REFEQ = 78;
	const Sbecore::uint CALLWZEMSGECHG = 79;
	const Sbecore::uint CALLWZEMSHRDATCHG = 80;
	const Sbecore::uint CALLWZEMSREFPRESET = 81;
	const Sbecore::uint CALLWZEMSTATCHG = 82;
	const Sbecore::uint CALLWZEMSTGCHG = 83;
	const Sbecore::uint CALLWZEMSTUBCHG = 84;
	const Sbecore::uint CALLWZEMSUSPSESS = 85;
	const Sbecore::uint CALLWZEMTXTVALPRESET = 86;
	const Sbecore::uint CALLWZEMUSGAACCMOD_USGEQ = 87;
	const Sbecore::uint CALLWZEMUSGMOD = 88;
	const Sbecore::uint CALLWZEMUSGUPD_REFEQ = 89;
	const Sbecore::uint CALLWZEMUSR_PRSEQ = 90;
	const Sbecore::uint CALLWZEMUSR_USGEQ = 91;
	const Sbecore::uint CALLWZEMUSRAACCMOD_USREQ = 92;
	const Sbecore::uint CALLWZEMUSRJSTEMOD_USREQ = 93;
	const Sbecore::uint CALLWZEMUSRMOD = 94;
	const Sbecore::uint CALLWZEMUSRRUSGMOD_USGEQ = 95;
	const Sbecore::uint CALLWZEMUSRRUSGMOD_USREQ = 96;
	const Sbecore::uint CALLWZEMUSRUPD_REFEQ = 97;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
