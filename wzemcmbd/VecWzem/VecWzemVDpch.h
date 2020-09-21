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
	const Sbecore::uint DPCHAPPDLGWZEMNAVLOAINIDATA = 1;
	const Sbecore::uint DPCHAPPDLGWZEMNAVLOAINIDO = 2;
	const Sbecore::uint DPCHAPPROOTWZEMLOGIN = 3;
	const Sbecore::uint DPCHAPPWZEMALERT = 4;
	const Sbecore::uint DPCHAPPWZEMCALDETAILDATA = 5;
	const Sbecore::uint DPCHAPPWZEMCALDETAILDO = 6;
	const Sbecore::uint DPCHAPPWZEMCALDO = 7;
	const Sbecore::uint DPCHAPPWZEMCALLISTDATA = 8;
	const Sbecore::uint DPCHAPPWZEMCALLISTDO = 9;
	const Sbecore::uint DPCHAPPWZEMCALRECDO = 10;
	const Sbecore::uint DPCHAPPWZEMCLNDETAILDATA = 11;
	const Sbecore::uint DPCHAPPWZEMCLNDETAILDO = 12;
	const Sbecore::uint DPCHAPPWZEMCLNDO = 13;
	const Sbecore::uint DPCHAPPWZEMCLNLISTDATA = 14;
	const Sbecore::uint DPCHAPPWZEMCLNLISTDO = 15;
	const Sbecore::uint DPCHAPPWZEMCLNRECDO = 16;
	const Sbecore::uint DPCHAPPWZEMEVTDETAILDATA = 17;
	const Sbecore::uint DPCHAPPWZEMEVTDETAILDO = 18;
	const Sbecore::uint DPCHAPPWZEMEVTDO = 19;
	const Sbecore::uint DPCHAPPWZEMEVTLISTDATA = 20;
	const Sbecore::uint DPCHAPPWZEMEVTLISTDO = 21;
	const Sbecore::uint DPCHAPPWZEMEVTRECDO = 22;
	const Sbecore::uint DPCHAPPWZEMINIT = 23;
	const Sbecore::uint DPCHAPPWZEMJOB1NCALLDATA = 24;
	const Sbecore::uint DPCHAPPWZEMJOB1NCALLDO = 25;
	const Sbecore::uint DPCHAPPWZEMJOB1NCLSTNDATA = 26;
	const Sbecore::uint DPCHAPPWZEMJOB1NCLSTNDO = 27;
	const Sbecore::uint DPCHAPPWZEMJOB1NOPDATA = 28;
	const Sbecore::uint DPCHAPPWZEMJOB1NOPDO = 29;
	const Sbecore::uint DPCHAPPWZEMJOB1NPRESETDATA = 30;
	const Sbecore::uint DPCHAPPWZEMJOB1NPRESETDO = 31;
	const Sbecore::uint DPCHAPPWZEMJOBDETAILDATA = 32;
	const Sbecore::uint DPCHAPPWZEMJOBDETAILDO = 33;
	const Sbecore::uint DPCHAPPWZEMJOBDO = 34;
	const Sbecore::uint DPCHAPPWZEMJOBLISTDATA = 35;
	const Sbecore::uint DPCHAPPWZEMJOBLISTDO = 36;
	const Sbecore::uint DPCHAPPWZEMJOBRECDO = 37;
	const Sbecore::uint DPCHAPPWZEMJOBSUP1NJOBDATA = 38;
	const Sbecore::uint DPCHAPPWZEMJOBSUP1NJOBDO = 39;
	const Sbecore::uint DPCHAPPWZEMNAVADMINDATA = 40;
	const Sbecore::uint DPCHAPPWZEMNAVADMINDO = 41;
	const Sbecore::uint DPCHAPPWZEMNAVDO = 42;
	const Sbecore::uint DPCHAPPWZEMNAVMONDATA = 43;
	const Sbecore::uint DPCHAPPWZEMNAVMONDO = 44;
	const Sbecore::uint DPCHAPPWZEMNAVPREDO = 45;
	const Sbecore::uint DPCHAPPWZEMNDEDETAILDATA = 46;
	const Sbecore::uint DPCHAPPWZEMNDEDETAILDO = 47;
	const Sbecore::uint DPCHAPPWZEMNDEDO = 48;
	const Sbecore::uint DPCHAPPWZEMNDELISTDATA = 49;
	const Sbecore::uint DPCHAPPWZEMNDELISTDO = 50;
	const Sbecore::uint DPCHAPPWZEMNDERECDO = 51;
	const Sbecore::uint DPCHAPPWZEMOPXDETAILDATA = 52;
	const Sbecore::uint DPCHAPPWZEMOPXDETAILDO = 53;
	const Sbecore::uint DPCHAPPWZEMOPXDO = 54;
	const Sbecore::uint DPCHAPPWZEMOPXLISTDATA = 55;
	const Sbecore::uint DPCHAPPWZEMOPXLISTDO = 56;
	const Sbecore::uint DPCHAPPWZEMOPXRECDO = 57;
	const Sbecore::uint DPCHAPPWZEMPRD1NEVENTDATA = 58;
	const Sbecore::uint DPCHAPPWZEMPRD1NEVENTDO = 59;
	const Sbecore::uint DPCHAPPWZEMPRD1NJOBDATA = 60;
	const Sbecore::uint DPCHAPPWZEMPRD1NJOBDO = 61;
	const Sbecore::uint DPCHAPPWZEMPRD1NNODEDATA = 62;
	const Sbecore::uint DPCHAPPWZEMPRD1NNODEDO = 63;
	const Sbecore::uint DPCHAPPWZEMPRDDETAILDATA = 64;
	const Sbecore::uint DPCHAPPWZEMPRDDETAILDO = 65;
	const Sbecore::uint DPCHAPPWZEMPRDDO = 66;
	const Sbecore::uint DPCHAPPWZEMPRDLISTDATA = 67;
	const Sbecore::uint DPCHAPPWZEMPRDLISTDO = 68;
	const Sbecore::uint DPCHAPPWZEMPRDRECDO = 69;
	const Sbecore::uint DPCHAPPWZEMPRSADETAILDATA = 70;
	const Sbecore::uint DPCHAPPWZEMPRSADETAILDO = 71;
	const Sbecore::uint DPCHAPPWZEMPRSDETAILDATA = 72;
	const Sbecore::uint DPCHAPPWZEMPRSDETAILDO = 73;
	const Sbecore::uint DPCHAPPWZEMPRSDO = 74;
	const Sbecore::uint DPCHAPPWZEMPRSLISTDATA = 75;
	const Sbecore::uint DPCHAPPWZEMPRSLISTDO = 76;
	const Sbecore::uint DPCHAPPWZEMPRSRECDO = 77;
	const Sbecore::uint DPCHAPPWZEMPSTDETAILDATA = 78;
	const Sbecore::uint DPCHAPPWZEMPSTDETAILDO = 79;
	const Sbecore::uint DPCHAPPWZEMPSTDO = 80;
	const Sbecore::uint DPCHAPPWZEMPSTLISTDATA = 81;
	const Sbecore::uint DPCHAPPWZEMPSTLISTDO = 82;
	const Sbecore::uint DPCHAPPWZEMPSTRECDO = 83;
	const Sbecore::uint DPCHAPPWZEMRESUME = 84;
	const Sbecore::uint DPCHAPPWZEMUSGAACCESSDATA = 85;
	const Sbecore::uint DPCHAPPWZEMUSGAACCESSDO = 86;
	const Sbecore::uint DPCHAPPWZEMUSGDETAILDATA = 87;
	const Sbecore::uint DPCHAPPWZEMUSGDETAILDO = 88;
	const Sbecore::uint DPCHAPPWZEMUSGDO = 89;
	const Sbecore::uint DPCHAPPWZEMUSGLISTDATA = 90;
	const Sbecore::uint DPCHAPPWZEMUSGLISTDO = 91;
	const Sbecore::uint DPCHAPPWZEMUSGMNUSERDATA = 92;
	const Sbecore::uint DPCHAPPWZEMUSGMNUSERDO = 93;
	const Sbecore::uint DPCHAPPWZEMUSGRECDO = 94;
	const Sbecore::uint DPCHAPPWZEMUSR1NSESSIONDATA = 95;
	const Sbecore::uint DPCHAPPWZEMUSR1NSESSIONDO = 96;
	const Sbecore::uint DPCHAPPWZEMUSRAACCESSDATA = 97;
	const Sbecore::uint DPCHAPPWZEMUSRAACCESSDO = 98;
	const Sbecore::uint DPCHAPPWZEMUSRDETAILDATA = 99;
	const Sbecore::uint DPCHAPPWZEMUSRDETAILDO = 100;
	const Sbecore::uint DPCHAPPWZEMUSRDO = 101;
	const Sbecore::uint DPCHAPPWZEMUSRLISTDATA = 102;
	const Sbecore::uint DPCHAPPWZEMUSRLISTDO = 103;
	const Sbecore::uint DPCHAPPWZEMUSRMNUSERGROUPDATA = 104;
	const Sbecore::uint DPCHAPPWZEMUSRMNUSERGROUPDO = 105;
	const Sbecore::uint DPCHAPPWZEMUSRRECDO = 106;
	const Sbecore::uint DPCHENGDLGWZEMNAVLOAINIDATA = 107;
	const Sbecore::uint DPCHENGROOTWZEMDATA = 108;
	const Sbecore::uint DPCHENGSESSWZEMDATA = 109;
	const Sbecore::uint DPCHENGWZEMACK = 110;
	const Sbecore::uint DPCHENGWZEMALERT = 111;
	const Sbecore::uint DPCHENGWZEMCALDATA = 112;
	const Sbecore::uint DPCHENGWZEMCALDETAILDATA = 113;
	const Sbecore::uint DPCHENGWZEMCALHEADBARDATA = 114;
	const Sbecore::uint DPCHENGWZEMCALLISTDATA = 115;
	const Sbecore::uint DPCHENGWZEMCALRECDATA = 116;
	const Sbecore::uint DPCHENGWZEMCLNDATA = 117;
	const Sbecore::uint DPCHENGWZEMCLNDETAILDATA = 118;
	const Sbecore::uint DPCHENGWZEMCLNHEADBARDATA = 119;
	const Sbecore::uint DPCHENGWZEMCLNLISTDATA = 120;
	const Sbecore::uint DPCHENGWZEMCLNRECDATA = 121;
	const Sbecore::uint DPCHENGWZEMCONFIRM = 122;
	const Sbecore::uint DPCHENGWZEMEVTDATA = 123;
	const Sbecore::uint DPCHENGWZEMEVTDETAILDATA = 124;
	const Sbecore::uint DPCHENGWZEMEVTHEADBARDATA = 125;
	const Sbecore::uint DPCHENGWZEMEVTLISTDATA = 126;
	const Sbecore::uint DPCHENGWZEMEVTRECDATA = 127;
	const Sbecore::uint DPCHENGWZEMJOB1NCALLDATA = 128;
	const Sbecore::uint DPCHENGWZEMJOB1NCLSTNDATA = 129;
	const Sbecore::uint DPCHENGWZEMJOB1NOPDATA = 130;
	const Sbecore::uint DPCHENGWZEMJOB1NPRESETDATA = 131;
	const Sbecore::uint DPCHENGWZEMJOBDATA = 132;
	const Sbecore::uint DPCHENGWZEMJOBDETAILDATA = 133;
	const Sbecore::uint DPCHENGWZEMJOBHEADBARDATA = 134;
	const Sbecore::uint DPCHENGWZEMJOBLISTDATA = 135;
	const Sbecore::uint DPCHENGWZEMJOBRECDATA = 136;
	const Sbecore::uint DPCHENGWZEMJOBSUP1NJOBDATA = 137;
	const Sbecore::uint DPCHENGWZEMNAVADMINDATA = 138;
	const Sbecore::uint DPCHENGWZEMNAVDATA = 139;
	const Sbecore::uint DPCHENGWZEMNAVHEADBARDATA = 140;
	const Sbecore::uint DPCHENGWZEMNAVMONDATA = 141;
	const Sbecore::uint DPCHENGWZEMNAVPREDATA = 142;
	const Sbecore::uint DPCHENGWZEMNDEDATA = 143;
	const Sbecore::uint DPCHENGWZEMNDEDETAILDATA = 144;
	const Sbecore::uint DPCHENGWZEMNDEHEADBARDATA = 145;
	const Sbecore::uint DPCHENGWZEMNDELISTDATA = 146;
	const Sbecore::uint DPCHENGWZEMNDERECDATA = 147;
	const Sbecore::uint DPCHENGWZEMOPXDATA = 148;
	const Sbecore::uint DPCHENGWZEMOPXDETAILDATA = 149;
	const Sbecore::uint DPCHENGWZEMOPXHEADBARDATA = 150;
	const Sbecore::uint DPCHENGWZEMOPXLISTDATA = 151;
	const Sbecore::uint DPCHENGWZEMOPXRECDATA = 152;
	const Sbecore::uint DPCHENGWZEMPRD1NEVENTDATA = 153;
	const Sbecore::uint DPCHENGWZEMPRD1NJOBDATA = 154;
	const Sbecore::uint DPCHENGWZEMPRD1NNODEDATA = 155;
	const Sbecore::uint DPCHENGWZEMPRDDATA = 156;
	const Sbecore::uint DPCHENGWZEMPRDDETAILDATA = 157;
	const Sbecore::uint DPCHENGWZEMPRDHEADBARDATA = 158;
	const Sbecore::uint DPCHENGWZEMPRDLISTDATA = 159;
	const Sbecore::uint DPCHENGWZEMPRDRECDATA = 160;
	const Sbecore::uint DPCHENGWZEMPRSADETAILDATA = 161;
	const Sbecore::uint DPCHENGWZEMPRSDATA = 162;
	const Sbecore::uint DPCHENGWZEMPRSDETAILDATA = 163;
	const Sbecore::uint DPCHENGWZEMPRSHEADBARDATA = 164;
	const Sbecore::uint DPCHENGWZEMPRSLISTDATA = 165;
	const Sbecore::uint DPCHENGWZEMPRSRECDATA = 166;
	const Sbecore::uint DPCHENGWZEMPSTDATA = 167;
	const Sbecore::uint DPCHENGWZEMPSTDETAILDATA = 168;
	const Sbecore::uint DPCHENGWZEMPSTHEADBARDATA = 169;
	const Sbecore::uint DPCHENGWZEMPSTLISTDATA = 170;
	const Sbecore::uint DPCHENGWZEMPSTRECDATA = 171;
	const Sbecore::uint DPCHENGWZEMSUSPEND = 172;
	const Sbecore::uint DPCHENGWZEMUSGAACCESSDATA = 173;
	const Sbecore::uint DPCHENGWZEMUSGDATA = 174;
	const Sbecore::uint DPCHENGWZEMUSGDETAILDATA = 175;
	const Sbecore::uint DPCHENGWZEMUSGHEADBARDATA = 176;
	const Sbecore::uint DPCHENGWZEMUSGLISTDATA = 177;
	const Sbecore::uint DPCHENGWZEMUSGMNUSERDATA = 178;
	const Sbecore::uint DPCHENGWZEMUSGRECDATA = 179;
	const Sbecore::uint DPCHENGWZEMUSR1NSESSIONDATA = 180;
	const Sbecore::uint DPCHENGWZEMUSRAACCESSDATA = 181;
	const Sbecore::uint DPCHENGWZEMUSRDATA = 182;
	const Sbecore::uint DPCHENGWZEMUSRDETAILDATA = 183;
	const Sbecore::uint DPCHENGWZEMUSRHEADBARDATA = 184;
	const Sbecore::uint DPCHENGWZEMUSRLISTDATA = 185;
	const Sbecore::uint DPCHENGWZEMUSRMNUSERGROUPDATA = 186;
	const Sbecore::uint DPCHENGWZEMUSRRECDATA = 187;
	const Sbecore::uint DPCHINVWZEM = 188;
	const Sbecore::uint DPCHRETWZEM = 189;
	const Sbecore::uint DPCHWZEMDACK = 190;
	const Sbecore::uint DPCHWZEMDQUIT = 191;
	const Sbecore::uint DPCHWZEMDREG = 192;
	const Sbecore::uint DPCHWZEMOPDREG = 193;
	const Sbecore::uint DPCHWZEMOPDUNREG = 194;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

