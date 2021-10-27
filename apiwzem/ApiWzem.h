/**
	* \file ApiWzem.h
	* Wzem API library global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 6 Dec 2020
  */
// IP header --- ABOVE

#ifndef APIWZEM_H
#define APIWZEM_H

#define WZEM_VERSION "1.0.6"
#define WZEM_VERSION_MAJOR 1
#define WZEM_VERSION_MINOR 0
#define WZEM_VERSION_SUB 6

#include "ApiWzem_blks.h"

#include "WzemQCalList.h"
#include "WzemQClnList.h"
#include "WzemQEvtList.h"
#include "WzemQJob1NCall.h"
#include "WzemQJob1NClstn.h"
#include "WzemQJob1NOp.h"
#include "WzemQJob1NPreset.h"
#include "WzemQJobList.h"
#include "WzemQJobSup1NJob.h"
#include "WzemQNdeList.h"
#include "WzemQOpxList.h"
#include "WzemQPrd1NEvent.h"
#include "WzemQPrd1NJob.h"
#include "WzemQPrd1NNode.h"
#include "WzemQPrdList.h"
#include "WzemQPrsADetail.h"
#include "WzemQPrsList.h"
#include "WzemQPstList.h"
#include "WzemQUsgAAccess.h"
#include "WzemQUsgList.h"
#include "WzemQUsgMNUser.h"
#include "WzemQUsr1NSession.h"
#include "WzemQUsrAAccess.h"
#include "WzemQUsrList.h"
#include "WzemQUsrMNUsergroup.h"

#include "CrdWzemCal.h"
#include "CrdWzemCln.h"
#include "CrdWzemEvt.h"
#include "CrdWzemJob.h"
#include "CrdWzemNav.h"
#include "CrdWzemNde.h"
#include "CrdWzemOpx.h"
#include "CrdWzemPrd.h"
#include "CrdWzemPrs.h"
#include "CrdWzemPst.h"
#include "CrdWzemUsg.h"
#include "CrdWzemUsr.h"
#include "DlgWzemNavLoaini.h"
#include "PnlWzemCalDetail.h"
#include "PnlWzemCalHeadbar.h"
#include "PnlWzemCalList.h"
#include "PnlWzemCalRec.h"
#include "PnlWzemClnDetail.h"
#include "PnlWzemClnHeadbar.h"
#include "PnlWzemClnList.h"
#include "PnlWzemClnRec.h"
#include "PnlWzemEvtDetail.h"
#include "PnlWzemEvtHeadbar.h"
#include "PnlWzemEvtList.h"
#include "PnlWzemEvtRec.h"
#include "PnlWzemJob1NCall.h"
#include "PnlWzemJob1NClstn.h"
#include "PnlWzemJob1NOp.h"
#include "PnlWzemJob1NPreset.h"
#include "PnlWzemJobDetail.h"
#include "PnlWzemJobHeadbar.h"
#include "PnlWzemJobList.h"
#include "PnlWzemJobRec.h"
#include "PnlWzemJobSup1NJob.h"
#include "PnlWzemNavAdmin.h"
#include "PnlWzemNavHeadbar.h"
#include "PnlWzemNavMon.h"
#include "PnlWzemNavPre.h"
#include "PnlWzemNdeDetail.h"
#include "PnlWzemNdeHeadbar.h"
#include "PnlWzemNdeList.h"
#include "PnlWzemNdeRec.h"
#include "PnlWzemOpxDetail.h"
#include "PnlWzemOpxHeadbar.h"
#include "PnlWzemOpxList.h"
#include "PnlWzemOpxRec.h"
#include "PnlWzemPrd1NEvent.h"
#include "PnlWzemPrd1NJob.h"
#include "PnlWzemPrd1NNode.h"
#include "PnlWzemPrdDetail.h"
#include "PnlWzemPrdHeadbar.h"
#include "PnlWzemPrdList.h"
#include "PnlWzemPrdRec.h"
#include "PnlWzemPrsADetail.h"
#include "PnlWzemPrsDetail.h"
#include "PnlWzemPrsHeadbar.h"
#include "PnlWzemPrsList.h"
#include "PnlWzemPrsRec.h"
#include "PnlWzemPstDetail.h"
#include "PnlWzemPstHeadbar.h"
#include "PnlWzemPstList.h"
#include "PnlWzemPstRec.h"
#include "PnlWzemUsgAAccess.h"
#include "PnlWzemUsgDetail.h"
#include "PnlWzemUsgHeadbar.h"
#include "PnlWzemUsgList.h"
#include "PnlWzemUsgMNUser.h"
#include "PnlWzemUsgRec.h"
#include "PnlWzemUsr1NSession.h"
#include "PnlWzemUsrAAccess.h"
#include "PnlWzemUsrDetail.h"
#include "PnlWzemUsrHeadbar.h"
#include "PnlWzemUsrList.h"
#include "PnlWzemUsrMNUsergroup.h"
#include "PnlWzemUsrRec.h"
#include "QryWzemCalList.h"
#include "QryWzemClnList.h"
#include "QryWzemEvtList.h"
#include "QryWzemJob1NCall.h"
#include "QryWzemJob1NClstn.h"
#include "QryWzemJob1NOp.h"
#include "QryWzemJob1NPreset.h"
#include "QryWzemJobList.h"
#include "QryWzemJobSup1NJob.h"
#include "QryWzemNdeList.h"
#include "QryWzemOpxList.h"
#include "QryWzemPrd1NEvent.h"
#include "QryWzemPrd1NJob.h"
#include "QryWzemPrd1NNode.h"
#include "QryWzemPrdList.h"
#include "QryWzemPrsADetail.h"
#include "QryWzemPrsList.h"
#include "QryWzemPstList.h"
#include "QryWzemUsgAAccess.h"
#include "QryWzemUsgList.h"
#include "QryWzemUsgMNUser.h"
#include "QryWzemUsr1NSession.h"
#include "QryWzemUsrAAccess.h"
#include "QryWzemUsrList.h"
#include "QryWzemUsrMNUsergroup.h"
#include "RootWzem.h"
#include "SessWzem.h"

/**
	* StgWzemapi
	*/
class StgWzemapi : public Sbecore::Block {

public:
	static const Sbecore::uint ENGIP = 1;
	static const Sbecore::uint ENGPORT = 2;
	static const Sbecore::uint USERNAME = 3;
	static const Sbecore::uint PASSWORD = 4;

public:
	StgWzemapi(const std::string engip = "", const Sbecore::uint engport = 0, const std::string username = "", const std::string password = "");

public:
	std::string engip;
	Sbecore::uint engport;
	std::string username;
	std::string password;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const StgWzemapi* comp);
};

/**
	* ApiWzem
	*/
namespace ApiWzem {
	Sbecore::uint readDpchEng(char* buf, unsigned long buflen, DpchEngWzem** dpcheng);
	void writeDpchApp(DpchAppWzem* dpchapp, char** buf, unsigned long& buflen, unsigned long ofs = 0);
};

#endif
