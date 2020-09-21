/**
	* \file VecWzemVDpch.h
	* vector VecWzemVDpch (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef VECWZEMVDPCH_H
#define VECWZEMVDPCH_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVDpch
	*/
namespace VecWzemVDpch {
	const Sbecore::uint DPCHENGDLGWZEMNAVLOAINIDATA = 1;
	const Sbecore::uint DPCHENGROOTWZEMDATA = 2;
	const Sbecore::uint DPCHENGSESSWZEMDATA = 3;
	const Sbecore::uint DPCHENGWZEMACK = 4;
	const Sbecore::uint DPCHENGWZEMALERT = 5;
	const Sbecore::uint DPCHENGWZEMCALDATA = 6;
	const Sbecore::uint DPCHENGWZEMCALDETAILDATA = 7;
	const Sbecore::uint DPCHENGWZEMCALHEADBARDATA = 8;
	const Sbecore::uint DPCHENGWZEMCALLISTDATA = 9;
	const Sbecore::uint DPCHENGWZEMCALRECDATA = 10;
	const Sbecore::uint DPCHENGWZEMCLNDATA = 11;
	const Sbecore::uint DPCHENGWZEMCLNDETAILDATA = 12;
	const Sbecore::uint DPCHENGWZEMCLNHEADBARDATA = 13;
	const Sbecore::uint DPCHENGWZEMCLNLISTDATA = 14;
	const Sbecore::uint DPCHENGWZEMCLNRECDATA = 15;
	const Sbecore::uint DPCHENGWZEMCONFIRM = 16;
	const Sbecore::uint DPCHENGWZEMEVTDATA = 17;
	const Sbecore::uint DPCHENGWZEMEVTDETAILDATA = 18;
	const Sbecore::uint DPCHENGWZEMEVTHEADBARDATA = 19;
	const Sbecore::uint DPCHENGWZEMEVTLISTDATA = 20;
	const Sbecore::uint DPCHENGWZEMEVTRECDATA = 21;
	const Sbecore::uint DPCHENGWZEMJOB1NCALLDATA = 22;
	const Sbecore::uint DPCHENGWZEMJOB1NCLSTNDATA = 23;
	const Sbecore::uint DPCHENGWZEMJOB1NOPDATA = 24;
	const Sbecore::uint DPCHENGWZEMJOB1NPRESETDATA = 25;
	const Sbecore::uint DPCHENGWZEMJOBDATA = 26;
	const Sbecore::uint DPCHENGWZEMJOBDETAILDATA = 27;
	const Sbecore::uint DPCHENGWZEMJOBHEADBARDATA = 28;
	const Sbecore::uint DPCHENGWZEMJOBLISTDATA = 29;
	const Sbecore::uint DPCHENGWZEMJOBRECDATA = 30;
	const Sbecore::uint DPCHENGWZEMJOBSUP1NJOBDATA = 31;
	const Sbecore::uint DPCHENGWZEMNAVADMINDATA = 32;
	const Sbecore::uint DPCHENGWZEMNAVDATA = 33;
	const Sbecore::uint DPCHENGWZEMNAVHEADBARDATA = 34;
	const Sbecore::uint DPCHENGWZEMNAVMONDATA = 35;
	const Sbecore::uint DPCHENGWZEMNAVPREDATA = 36;
	const Sbecore::uint DPCHENGWZEMNDEDATA = 37;
	const Sbecore::uint DPCHENGWZEMNDEDETAILDATA = 38;
	const Sbecore::uint DPCHENGWZEMNDEHEADBARDATA = 39;
	const Sbecore::uint DPCHENGWZEMNDELISTDATA = 40;
	const Sbecore::uint DPCHENGWZEMNDERECDATA = 41;
	const Sbecore::uint DPCHENGWZEMOPXDATA = 42;
	const Sbecore::uint DPCHENGWZEMOPXDETAILDATA = 43;
	const Sbecore::uint DPCHENGWZEMOPXHEADBARDATA = 44;
	const Sbecore::uint DPCHENGWZEMOPXLISTDATA = 45;
	const Sbecore::uint DPCHENGWZEMOPXRECDATA = 46;
	const Sbecore::uint DPCHENGWZEMPRD1NEVENTDATA = 47;
	const Sbecore::uint DPCHENGWZEMPRD1NJOBDATA = 48;
	const Sbecore::uint DPCHENGWZEMPRD1NNODEDATA = 49;
	const Sbecore::uint DPCHENGWZEMPRDDATA = 50;
	const Sbecore::uint DPCHENGWZEMPRDDETAILDATA = 51;
	const Sbecore::uint DPCHENGWZEMPRDHEADBARDATA = 52;
	const Sbecore::uint DPCHENGWZEMPRDLISTDATA = 53;
	const Sbecore::uint DPCHENGWZEMPRDRECDATA = 54;
	const Sbecore::uint DPCHENGWZEMPRSADETAILDATA = 55;
	const Sbecore::uint DPCHENGWZEMPRSDATA = 56;
	const Sbecore::uint DPCHENGWZEMPRSDETAILDATA = 57;
	const Sbecore::uint DPCHENGWZEMPRSHEADBARDATA = 58;
	const Sbecore::uint DPCHENGWZEMPRSLISTDATA = 59;
	const Sbecore::uint DPCHENGWZEMPRSRECDATA = 60;
	const Sbecore::uint DPCHENGWZEMPSTDATA = 61;
	const Sbecore::uint DPCHENGWZEMPSTDETAILDATA = 62;
	const Sbecore::uint DPCHENGWZEMPSTHEADBARDATA = 63;
	const Sbecore::uint DPCHENGWZEMPSTLISTDATA = 64;
	const Sbecore::uint DPCHENGWZEMPSTRECDATA = 65;
	const Sbecore::uint DPCHENGWZEMSUSPEND = 66;
	const Sbecore::uint DPCHENGWZEMUSGAACCESSDATA = 67;
	const Sbecore::uint DPCHENGWZEMUSGDATA = 68;
	const Sbecore::uint DPCHENGWZEMUSGDETAILDATA = 69;
	const Sbecore::uint DPCHENGWZEMUSGHEADBARDATA = 70;
	const Sbecore::uint DPCHENGWZEMUSGLISTDATA = 71;
	const Sbecore::uint DPCHENGWZEMUSGMNUSERDATA = 72;
	const Sbecore::uint DPCHENGWZEMUSGRECDATA = 73;
	const Sbecore::uint DPCHENGWZEMUSR1NSESSIONDATA = 74;
	const Sbecore::uint DPCHENGWZEMUSRAACCESSDATA = 75;
	const Sbecore::uint DPCHENGWZEMUSRDATA = 76;
	const Sbecore::uint DPCHENGWZEMUSRDETAILDATA = 77;
	const Sbecore::uint DPCHENGWZEMUSRHEADBARDATA = 78;
	const Sbecore::uint DPCHENGWZEMUSRLISTDATA = 79;
	const Sbecore::uint DPCHENGWZEMUSRMNUSERGROUPDATA = 80;
	const Sbecore::uint DPCHENGWZEMUSRRECDATA = 81;
	const Sbecore::uint DPCHAPPDLGWZEMNAVLOAINIDATA = 82;
	const Sbecore::uint DPCHAPPDLGWZEMNAVLOAINIDO = 83;
	const Sbecore::uint DPCHAPPROOTWZEMLOGIN = 84;
	const Sbecore::uint DPCHAPPWZEMALERT = 85;
	const Sbecore::uint DPCHAPPWZEMCALDETAILDATA = 86;
	const Sbecore::uint DPCHAPPWZEMCALDETAILDO = 87;
	const Sbecore::uint DPCHAPPWZEMCALDO = 88;
	const Sbecore::uint DPCHAPPWZEMCALLISTDATA = 89;
	const Sbecore::uint DPCHAPPWZEMCALLISTDO = 90;
	const Sbecore::uint DPCHAPPWZEMCALRECDO = 91;
	const Sbecore::uint DPCHAPPWZEMCLNDETAILDATA = 92;
	const Sbecore::uint DPCHAPPWZEMCLNDETAILDO = 93;
	const Sbecore::uint DPCHAPPWZEMCLNDO = 94;
	const Sbecore::uint DPCHAPPWZEMCLNLISTDATA = 95;
	const Sbecore::uint DPCHAPPWZEMCLNLISTDO = 96;
	const Sbecore::uint DPCHAPPWZEMCLNRECDO = 97;
	const Sbecore::uint DPCHAPPWZEMEVTDETAILDATA = 98;
	const Sbecore::uint DPCHAPPWZEMEVTDETAILDO = 99;
	const Sbecore::uint DPCHAPPWZEMEVTDO = 100;
	const Sbecore::uint DPCHAPPWZEMEVTLISTDATA = 101;
	const Sbecore::uint DPCHAPPWZEMEVTLISTDO = 102;
	const Sbecore::uint DPCHAPPWZEMEVTRECDO = 103;
	const Sbecore::uint DPCHAPPWZEMINIT = 104;
	const Sbecore::uint DPCHAPPWZEMJOB1NCALLDATA = 105;
	const Sbecore::uint DPCHAPPWZEMJOB1NCALLDO = 106;
	const Sbecore::uint DPCHAPPWZEMJOB1NCLSTNDATA = 107;
	const Sbecore::uint DPCHAPPWZEMJOB1NCLSTNDO = 108;
	const Sbecore::uint DPCHAPPWZEMJOB1NOPDATA = 109;
	const Sbecore::uint DPCHAPPWZEMJOB1NOPDO = 110;
	const Sbecore::uint DPCHAPPWZEMJOB1NPRESETDATA = 111;
	const Sbecore::uint DPCHAPPWZEMJOB1NPRESETDO = 112;
	const Sbecore::uint DPCHAPPWZEMJOBDETAILDATA = 113;
	const Sbecore::uint DPCHAPPWZEMJOBDETAILDO = 114;
	const Sbecore::uint DPCHAPPWZEMJOBDO = 115;
	const Sbecore::uint DPCHAPPWZEMJOBLISTDATA = 116;
	const Sbecore::uint DPCHAPPWZEMJOBLISTDO = 117;
	const Sbecore::uint DPCHAPPWZEMJOBRECDO = 118;
	const Sbecore::uint DPCHAPPWZEMJOBSUP1NJOBDATA = 119;
	const Sbecore::uint DPCHAPPWZEMJOBSUP1NJOBDO = 120;
	const Sbecore::uint DPCHAPPWZEMNAVADMINDATA = 121;
	const Sbecore::uint DPCHAPPWZEMNAVADMINDO = 122;
	const Sbecore::uint DPCHAPPWZEMNAVDO = 123;
	const Sbecore::uint DPCHAPPWZEMNAVMONDATA = 124;
	const Sbecore::uint DPCHAPPWZEMNAVMONDO = 125;
	const Sbecore::uint DPCHAPPWZEMNAVPREDO = 126;
	const Sbecore::uint DPCHAPPWZEMNDEDETAILDATA = 127;
	const Sbecore::uint DPCHAPPWZEMNDEDETAILDO = 128;
	const Sbecore::uint DPCHAPPWZEMNDEDO = 129;
	const Sbecore::uint DPCHAPPWZEMNDELISTDATA = 130;
	const Sbecore::uint DPCHAPPWZEMNDELISTDO = 131;
	const Sbecore::uint DPCHAPPWZEMNDERECDO = 132;
	const Sbecore::uint DPCHAPPWZEMOPXDETAILDATA = 133;
	const Sbecore::uint DPCHAPPWZEMOPXDETAILDO = 134;
	const Sbecore::uint DPCHAPPWZEMOPXDO = 135;
	const Sbecore::uint DPCHAPPWZEMOPXLISTDATA = 136;
	const Sbecore::uint DPCHAPPWZEMOPXLISTDO = 137;
	const Sbecore::uint DPCHAPPWZEMOPXRECDO = 138;
	const Sbecore::uint DPCHAPPWZEMPRD1NEVENTDATA = 139;
	const Sbecore::uint DPCHAPPWZEMPRD1NEVENTDO = 140;
	const Sbecore::uint DPCHAPPWZEMPRD1NJOBDATA = 141;
	const Sbecore::uint DPCHAPPWZEMPRD1NJOBDO = 142;
	const Sbecore::uint DPCHAPPWZEMPRD1NNODEDATA = 143;
	const Sbecore::uint DPCHAPPWZEMPRD1NNODEDO = 144;
	const Sbecore::uint DPCHAPPWZEMPRDDETAILDATA = 145;
	const Sbecore::uint DPCHAPPWZEMPRDDETAILDO = 146;
	const Sbecore::uint DPCHAPPWZEMPRDDO = 147;
	const Sbecore::uint DPCHAPPWZEMPRDLISTDATA = 148;
	const Sbecore::uint DPCHAPPWZEMPRDLISTDO = 149;
	const Sbecore::uint DPCHAPPWZEMPRDRECDO = 150;
	const Sbecore::uint DPCHAPPWZEMPRSADETAILDATA = 151;
	const Sbecore::uint DPCHAPPWZEMPRSADETAILDO = 152;
	const Sbecore::uint DPCHAPPWZEMPRSDETAILDATA = 153;
	const Sbecore::uint DPCHAPPWZEMPRSDETAILDO = 154;
	const Sbecore::uint DPCHAPPWZEMPRSDO = 155;
	const Sbecore::uint DPCHAPPWZEMPRSLISTDATA = 156;
	const Sbecore::uint DPCHAPPWZEMPRSLISTDO = 157;
	const Sbecore::uint DPCHAPPWZEMPRSRECDO = 158;
	const Sbecore::uint DPCHAPPWZEMPSTDETAILDATA = 159;
	const Sbecore::uint DPCHAPPWZEMPSTDETAILDO = 160;
	const Sbecore::uint DPCHAPPWZEMPSTDO = 161;
	const Sbecore::uint DPCHAPPWZEMPSTLISTDATA = 162;
	const Sbecore::uint DPCHAPPWZEMPSTLISTDO = 163;
	const Sbecore::uint DPCHAPPWZEMPSTRECDO = 164;
	const Sbecore::uint DPCHAPPWZEMRESUME = 165;
	const Sbecore::uint DPCHAPPWZEMUSGAACCESSDATA = 166;
	const Sbecore::uint DPCHAPPWZEMUSGAACCESSDO = 167;
	const Sbecore::uint DPCHAPPWZEMUSGDETAILDATA = 168;
	const Sbecore::uint DPCHAPPWZEMUSGDETAILDO = 169;
	const Sbecore::uint DPCHAPPWZEMUSGDO = 170;
	const Sbecore::uint DPCHAPPWZEMUSGLISTDATA = 171;
	const Sbecore::uint DPCHAPPWZEMUSGLISTDO = 172;
	const Sbecore::uint DPCHAPPWZEMUSGMNUSERDATA = 173;
	const Sbecore::uint DPCHAPPWZEMUSGMNUSERDO = 174;
	const Sbecore::uint DPCHAPPWZEMUSGRECDO = 175;
	const Sbecore::uint DPCHAPPWZEMUSR1NSESSIONDATA = 176;
	const Sbecore::uint DPCHAPPWZEMUSR1NSESSIONDO = 177;
	const Sbecore::uint DPCHAPPWZEMUSRAACCESSDATA = 178;
	const Sbecore::uint DPCHAPPWZEMUSRAACCESSDO = 179;
	const Sbecore::uint DPCHAPPWZEMUSRDETAILDATA = 180;
	const Sbecore::uint DPCHAPPWZEMUSRDETAILDO = 181;
	const Sbecore::uint DPCHAPPWZEMUSRDO = 182;
	const Sbecore::uint DPCHAPPWZEMUSRLISTDATA = 183;
	const Sbecore::uint DPCHAPPWZEMUSRLISTDO = 184;
	const Sbecore::uint DPCHAPPWZEMUSRMNUSERGROUPDATA = 185;
	const Sbecore::uint DPCHAPPWZEMUSRMNUSERGROUPDO = 186;
	const Sbecore::uint DPCHAPPWZEMUSRRECDO = 187;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

