/**
	* \file ApiWzem.cpp
	* Wzem API library global functionality (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "ApiWzem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class StgWzemapi
 ******************************************************************************/

StgWzemapi::StgWzemapi(
			const string engip
			, const uint engport
			, const string username
			, const string password
		) :
			Block()
		{
	this->engip = engip;
	this->engport = engport;
	this->username = username;
	this->password = password;

	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD};
};

bool StgWzemapi::all(
			const set<uint>& items
		) {
	if (!find(items, ENGIP)) return false;
	if (!find(items, ENGPORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgWzemapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzemapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzemapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgWzemapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzemapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemWzemapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzemapi::compare(
			const StgWzemapi* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiWzem
 ******************************************************************************/

uint ApiWzem::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngWzem** dpcheng
		) {
	uint ixWzemVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	try {
		parseBuffer(buf, buflen, &doc, &docctx);

		ixWzemVDpch = VecWzemVDpch::getIx(extractRoot(doc));

		if (ixWzemVDpch == VecWzemVDpch::DPCHENGDLGWZEMNAVLOAINIDATA) {
			*dpcheng = new DlgWzemNavLoaini::DpchEngData();
			((DlgWzemNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGROOTWZEMDATA) {
			*dpcheng = new RootWzem::DpchEngData();
			((RootWzem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGSESSWZEMDATA) {
			*dpcheng = new SessWzem::DpchEngData();
			((SessWzem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMACK) {
			*dpcheng = new DpchEngWzemAck();
			((DpchEngWzemAck*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMALERT) {
			*dpcheng = new DpchEngWzemAlert();
			((DpchEngWzemAlert*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCALDATA) {
			*dpcheng = new CrdWzemCal::DpchEngData();
			((CrdWzemCal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCALDETAILDATA) {
			*dpcheng = new PnlWzemCalDetail::DpchEngData();
			((PnlWzemCalDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCALHEADBARDATA) {
			*dpcheng = new PnlWzemCalHeadbar::DpchEngData();
			((PnlWzemCalHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCALLISTDATA) {
			*dpcheng = new PnlWzemCalList::DpchEngData();
			((PnlWzemCalList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCALRECDATA) {
			*dpcheng = new PnlWzemCalRec::DpchEngData();
			((PnlWzemCalRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCLNDATA) {
			*dpcheng = new CrdWzemCln::DpchEngData();
			((CrdWzemCln::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCLNDETAILDATA) {
			*dpcheng = new PnlWzemClnDetail::DpchEngData();
			((PnlWzemClnDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCLNHEADBARDATA) {
			*dpcheng = new PnlWzemClnHeadbar::DpchEngData();
			((PnlWzemClnHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCLNLISTDATA) {
			*dpcheng = new PnlWzemClnList::DpchEngData();
			((PnlWzemClnList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCLNRECDATA) {
			*dpcheng = new PnlWzemClnRec::DpchEngData();
			((PnlWzemClnRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMCONFIRM) {
			*dpcheng = new DpchEngWzemConfirm();
			((DpchEngWzemConfirm*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMEVTDATA) {
			*dpcheng = new CrdWzemEvt::DpchEngData();
			((CrdWzemEvt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMEVTDETAILDATA) {
			*dpcheng = new PnlWzemEvtDetail::DpchEngData();
			((PnlWzemEvtDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMEVTHEADBARDATA) {
			*dpcheng = new PnlWzemEvtHeadbar::DpchEngData();
			((PnlWzemEvtHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMEVTLISTDATA) {
			*dpcheng = new PnlWzemEvtList::DpchEngData();
			((PnlWzemEvtList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMEVTRECDATA) {
			*dpcheng = new PnlWzemEvtRec::DpchEngData();
			((PnlWzemEvtRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOB1NCALLDATA) {
			*dpcheng = new PnlWzemJob1NCall::DpchEngData();
			((PnlWzemJob1NCall::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOB1NCLSTNDATA) {
			*dpcheng = new PnlWzemJob1NClstn::DpchEngData();
			((PnlWzemJob1NClstn::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOB1NOPDATA) {
			*dpcheng = new PnlWzemJob1NOp::DpchEngData();
			((PnlWzemJob1NOp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOB1NPRESETDATA) {
			*dpcheng = new PnlWzemJob1NPreset::DpchEngData();
			((PnlWzemJob1NPreset::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOBDATA) {
			*dpcheng = new CrdWzemJob::DpchEngData();
			((CrdWzemJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOBDETAILDATA) {
			*dpcheng = new PnlWzemJobDetail::DpchEngData();
			((PnlWzemJobDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOBHEADBARDATA) {
			*dpcheng = new PnlWzemJobHeadbar::DpchEngData();
			((PnlWzemJobHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOBLISTDATA) {
			*dpcheng = new PnlWzemJobList::DpchEngData();
			((PnlWzemJobList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOBRECDATA) {
			*dpcheng = new PnlWzemJobRec::DpchEngData();
			((PnlWzemJobRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMJOBSUP1NJOBDATA) {
			*dpcheng = new PnlWzemJobSup1NJob::DpchEngData();
			((PnlWzemJobSup1NJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNAVADMINDATA) {
			*dpcheng = new PnlWzemNavAdmin::DpchEngData();
			((PnlWzemNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNAVDATA) {
			*dpcheng = new CrdWzemNav::DpchEngData();
			((CrdWzemNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNAVHEADBARDATA) {
			*dpcheng = new PnlWzemNavHeadbar::DpchEngData();
			((PnlWzemNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNAVMONDATA) {
			*dpcheng = new PnlWzemNavMon::DpchEngData();
			((PnlWzemNavMon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNAVPREDATA) {
			*dpcheng = new PnlWzemNavPre::DpchEngData();
			((PnlWzemNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNDEDATA) {
			*dpcheng = new CrdWzemNde::DpchEngData();
			((CrdWzemNde::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNDEDETAILDATA) {
			*dpcheng = new PnlWzemNdeDetail::DpchEngData();
			((PnlWzemNdeDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNDEHEADBARDATA) {
			*dpcheng = new PnlWzemNdeHeadbar::DpchEngData();
			((PnlWzemNdeHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNDELISTDATA) {
			*dpcheng = new PnlWzemNdeList::DpchEngData();
			((PnlWzemNdeList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMNDERECDATA) {
			*dpcheng = new PnlWzemNdeRec::DpchEngData();
			((PnlWzemNdeRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMOPXDATA) {
			*dpcheng = new CrdWzemOpx::DpchEngData();
			((CrdWzemOpx::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMOPXDETAILDATA) {
			*dpcheng = new PnlWzemOpxDetail::DpchEngData();
			((PnlWzemOpxDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMOPXHEADBARDATA) {
			*dpcheng = new PnlWzemOpxHeadbar::DpchEngData();
			((PnlWzemOpxHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMOPXLISTDATA) {
			*dpcheng = new PnlWzemOpxList::DpchEngData();
			((PnlWzemOpxList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMOPXRECDATA) {
			*dpcheng = new PnlWzemOpxRec::DpchEngData();
			((PnlWzemOpxRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRD1NEVENTDATA) {
			*dpcheng = new PnlWzemPrd1NEvent::DpchEngData();
			((PnlWzemPrd1NEvent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRD1NJOBDATA) {
			*dpcheng = new PnlWzemPrd1NJob::DpchEngData();
			((PnlWzemPrd1NJob::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRD1NNODEDATA) {
			*dpcheng = new PnlWzemPrd1NNode::DpchEngData();
			((PnlWzemPrd1NNode::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRDDATA) {
			*dpcheng = new CrdWzemPrd::DpchEngData();
			((CrdWzemPrd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRDDETAILDATA) {
			*dpcheng = new PnlWzemPrdDetail::DpchEngData();
			((PnlWzemPrdDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRDHEADBARDATA) {
			*dpcheng = new PnlWzemPrdHeadbar::DpchEngData();
			((PnlWzemPrdHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRDLISTDATA) {
			*dpcheng = new PnlWzemPrdList::DpchEngData();
			((PnlWzemPrdList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRDRECDATA) {
			*dpcheng = new PnlWzemPrdRec::DpchEngData();
			((PnlWzemPrdRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRSADETAILDATA) {
			*dpcheng = new PnlWzemPrsADetail::DpchEngData();
			((PnlWzemPrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRSDATA) {
			*dpcheng = new CrdWzemPrs::DpchEngData();
			((CrdWzemPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRSDETAILDATA) {
			*dpcheng = new PnlWzemPrsDetail::DpchEngData();
			((PnlWzemPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRSHEADBARDATA) {
			*dpcheng = new PnlWzemPrsHeadbar::DpchEngData();
			((PnlWzemPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRSLISTDATA) {
			*dpcheng = new PnlWzemPrsList::DpchEngData();
			((PnlWzemPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPRSRECDATA) {
			*dpcheng = new PnlWzemPrsRec::DpchEngData();
			((PnlWzemPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPSTDATA) {
			*dpcheng = new CrdWzemPst::DpchEngData();
			((CrdWzemPst::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPSTDETAILDATA) {
			*dpcheng = new PnlWzemPstDetail::DpchEngData();
			((PnlWzemPstDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPSTHEADBARDATA) {
			*dpcheng = new PnlWzemPstHeadbar::DpchEngData();
			((PnlWzemPstHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPSTLISTDATA) {
			*dpcheng = new PnlWzemPstList::DpchEngData();
			((PnlWzemPstList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMPSTRECDATA) {
			*dpcheng = new PnlWzemPstRec::DpchEngData();
			((PnlWzemPstRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMSUSPEND) {
			*dpcheng = new DpchEngWzemSuspend();
			((DpchEngWzemSuspend*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGAACCESSDATA) {
			*dpcheng = new PnlWzemUsgAAccess::DpchEngData();
			((PnlWzemUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGDATA) {
			*dpcheng = new CrdWzemUsg::DpchEngData();
			((CrdWzemUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGDETAILDATA) {
			*dpcheng = new PnlWzemUsgDetail::DpchEngData();
			((PnlWzemUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGHEADBARDATA) {
			*dpcheng = new PnlWzemUsgHeadbar::DpchEngData();
			((PnlWzemUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGLISTDATA) {
			*dpcheng = new PnlWzemUsgList::DpchEngData();
			((PnlWzemUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGMNUSERDATA) {
			*dpcheng = new PnlWzemUsgMNUser::DpchEngData();
			((PnlWzemUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSGRECDATA) {
			*dpcheng = new PnlWzemUsgRec::DpchEngData();
			((PnlWzemUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSR1NSESSIONDATA) {
			*dpcheng = new PnlWzemUsr1NSession::DpchEngData();
			((PnlWzemUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRAACCESSDATA) {
			*dpcheng = new PnlWzemUsrAAccess::DpchEngData();
			((PnlWzemUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRDATA) {
			*dpcheng = new CrdWzemUsr::DpchEngData();
			((CrdWzemUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRDETAILDATA) {
			*dpcheng = new PnlWzemUsrDetail::DpchEngData();
			((PnlWzemUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRHEADBARDATA) {
			*dpcheng = new PnlWzemUsrHeadbar::DpchEngData();
			((PnlWzemUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRLISTDATA) {
			*dpcheng = new PnlWzemUsrList::DpchEngData();
			((PnlWzemUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRMNUSERGROUPDATA) {
			*dpcheng = new PnlWzemUsrMNUsergroup::DpchEngData();
			((PnlWzemUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzemVDpch == VecWzemVDpch::DPCHENGWZEMUSRRECDATA) {
			*dpcheng = new PnlWzemUsrRec::DpchEngData();
			((PnlWzemUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		};
	} catch (SbeException e) {
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWzemVDpch;
};

void ApiWzem::writeDpchApp(
			DpchAppWzem* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};

