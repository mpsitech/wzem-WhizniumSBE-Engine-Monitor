/**
	* \file VecWzemVJob.h
	* vector VecWzemVJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef VECWZEMVJOB_H
#define VECWZEMVJOB_H

#include <sbecore/Xmlio.h>

/**
	* VecWzemVJob
	*/
namespace VecWzemVJob {
	const Sbecore::uint CRDWZEMCAL = 1;
	const Sbecore::uint CRDWZEMCLN = 2;
	const Sbecore::uint CRDWZEMEVT = 3;
	const Sbecore::uint CRDWZEMJOB = 4;
	const Sbecore::uint CRDWZEMNAV = 5;
	const Sbecore::uint CRDWZEMNDE = 6;
	const Sbecore::uint CRDWZEMOPX = 7;
	const Sbecore::uint CRDWZEMPRD = 8;
	const Sbecore::uint CRDWZEMPRS = 9;
	const Sbecore::uint CRDWZEMPST = 10;
	const Sbecore::uint CRDWZEMUSG = 11;
	const Sbecore::uint CRDWZEMUSR = 12;
	const Sbecore::uint DLGWZEMNAVLOAINI = 13;
	const Sbecore::uint JOBWZEMIEXINI = 14;
	const Sbecore::uint PNLWZEMCALDETAIL = 15;
	const Sbecore::uint PNLWZEMCALHEADBAR = 16;
	const Sbecore::uint PNLWZEMCALLIST = 17;
	const Sbecore::uint PNLWZEMCALREC = 18;
	const Sbecore::uint PNLWZEMCLNDETAIL = 19;
	const Sbecore::uint PNLWZEMCLNHEADBAR = 20;
	const Sbecore::uint PNLWZEMCLNLIST = 21;
	const Sbecore::uint PNLWZEMCLNREC = 22;
	const Sbecore::uint PNLWZEMEVTDETAIL = 23;
	const Sbecore::uint PNLWZEMEVTHEADBAR = 24;
	const Sbecore::uint PNLWZEMEVTLIST = 25;
	const Sbecore::uint PNLWZEMEVTREC = 26;
	const Sbecore::uint PNLWZEMJOB1NCALL = 27;
	const Sbecore::uint PNLWZEMJOB1NCLSTN = 28;
	const Sbecore::uint PNLWZEMJOB1NOP = 29;
	const Sbecore::uint PNLWZEMJOB1NPRESET = 30;
	const Sbecore::uint PNLWZEMJOBDETAIL = 31;
	const Sbecore::uint PNLWZEMJOBHEADBAR = 32;
	const Sbecore::uint PNLWZEMJOBLIST = 33;
	const Sbecore::uint PNLWZEMJOBREC = 34;
	const Sbecore::uint PNLWZEMJOBSUP1NJOB = 35;
	const Sbecore::uint PNLWZEMNAVADMIN = 36;
	const Sbecore::uint PNLWZEMNAVHEADBAR = 37;
	const Sbecore::uint PNLWZEMNAVMON = 38;
	const Sbecore::uint PNLWZEMNAVPRE = 39;
	const Sbecore::uint PNLWZEMNDEDETAIL = 40;
	const Sbecore::uint PNLWZEMNDEHEADBAR = 41;
	const Sbecore::uint PNLWZEMNDELIST = 42;
	const Sbecore::uint PNLWZEMNDEREC = 43;
	const Sbecore::uint PNLWZEMOPXDETAIL = 44;
	const Sbecore::uint PNLWZEMOPXHEADBAR = 45;
	const Sbecore::uint PNLWZEMOPXLIST = 46;
	const Sbecore::uint PNLWZEMOPXREC = 47;
	const Sbecore::uint PNLWZEMPRD1NEVENT = 48;
	const Sbecore::uint PNLWZEMPRD1NJOB = 49;
	const Sbecore::uint PNLWZEMPRD1NNODE = 50;
	const Sbecore::uint PNLWZEMPRDDETAIL = 51;
	const Sbecore::uint PNLWZEMPRDHEADBAR = 52;
	const Sbecore::uint PNLWZEMPRDLIST = 53;
	const Sbecore::uint PNLWZEMPRDREC = 54;
	const Sbecore::uint PNLWZEMPRSADETAIL = 55;
	const Sbecore::uint PNLWZEMPRSDETAIL = 56;
	const Sbecore::uint PNLWZEMPRSHEADBAR = 57;
	const Sbecore::uint PNLWZEMPRSLIST = 58;
	const Sbecore::uint PNLWZEMPRSREC = 59;
	const Sbecore::uint PNLWZEMPSTDETAIL = 60;
	const Sbecore::uint PNLWZEMPSTHEADBAR = 61;
	const Sbecore::uint PNLWZEMPSTLIST = 62;
	const Sbecore::uint PNLWZEMPSTREC = 63;
	const Sbecore::uint PNLWZEMUSGAACCESS = 64;
	const Sbecore::uint PNLWZEMUSGDETAIL = 65;
	const Sbecore::uint PNLWZEMUSGHEADBAR = 66;
	const Sbecore::uint PNLWZEMUSGLIST = 67;
	const Sbecore::uint PNLWZEMUSGMNUSER = 68;
	const Sbecore::uint PNLWZEMUSGREC = 69;
	const Sbecore::uint PNLWZEMUSR1NSESSION = 70;
	const Sbecore::uint PNLWZEMUSRAACCESS = 71;
	const Sbecore::uint PNLWZEMUSRDETAIL = 72;
	const Sbecore::uint PNLWZEMUSRHEADBAR = 73;
	const Sbecore::uint PNLWZEMUSRLIST = 74;
	const Sbecore::uint PNLWZEMUSRMNUSERGROUP = 75;
	const Sbecore::uint PNLWZEMUSRREC = 76;
	const Sbecore::uint QRYWZEMCALLIST = 77;
	const Sbecore::uint QRYWZEMCLNLIST = 78;
	const Sbecore::uint QRYWZEMEVTLIST = 79;
	const Sbecore::uint QRYWZEMJOB1NCALL = 80;
	const Sbecore::uint QRYWZEMJOB1NCLSTN = 81;
	const Sbecore::uint QRYWZEMJOB1NOP = 82;
	const Sbecore::uint QRYWZEMJOB1NPRESET = 83;
	const Sbecore::uint QRYWZEMJOBLIST = 84;
	const Sbecore::uint QRYWZEMJOBSUP1NJOB = 85;
	const Sbecore::uint QRYWZEMNDELIST = 86;
	const Sbecore::uint QRYWZEMOPXLIST = 87;
	const Sbecore::uint QRYWZEMPRD1NEVENT = 88;
	const Sbecore::uint QRYWZEMPRD1NJOB = 89;
	const Sbecore::uint QRYWZEMPRD1NNODE = 90;
	const Sbecore::uint QRYWZEMPRDLIST = 91;
	const Sbecore::uint QRYWZEMPRSADETAIL = 92;
	const Sbecore::uint QRYWZEMPRSLIST = 93;
	const Sbecore::uint QRYWZEMPSTLIST = 94;
	const Sbecore::uint QRYWZEMUSGAACCESS = 95;
	const Sbecore::uint QRYWZEMUSGLIST = 96;
	const Sbecore::uint QRYWZEMUSGMNUSER = 97;
	const Sbecore::uint QRYWZEMUSR1NSESSION = 98;
	const Sbecore::uint QRYWZEMUSRAACCESS = 99;
	const Sbecore::uint QRYWZEMUSRLIST = 100;
	const Sbecore::uint QRYWZEMUSRMNUSERGROUP = 101;
	const Sbecore::uint ROOTWZEM = 102;
	const Sbecore::uint SESSWZEM = 103;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

