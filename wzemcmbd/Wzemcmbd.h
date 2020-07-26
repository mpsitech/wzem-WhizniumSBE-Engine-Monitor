/**
	* \file Wzemcmbd.h
	* inter-thread exchange object for Wzem combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMCMBD_H
#define WZEMCMBD_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>

#include <sbecore/Txtrd.h>
#include <sbecore/TxtMon.h>

#include "Wzem.h"

// IP include.cust --- INSERT

class XchgWzemcmbd;
typedef XchgWzemcmbd XchgWzem;

/**
	* DpchAppWzem
	*/
class DpchAppWzem : public DpchWzem {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchAppWzem(const Sbecore::uint ixWzemVDpch = 0);
	virtual ~DpchAppWzem();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWzemAlert
	*/
class DpchAppWzemAlert : public DpchAppWzem {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint NUMFMCB = 2;

public:
	DpchAppWzemAlert();

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWzemInit
	*/
class DpchAppWzemInit : public DpchAppWzem {

public:
	DpchAppWzemInit();
};

/**
	* DpchAppWzemResume
	*/
class DpchAppWzemResume : public DpchAppWzem {

public:
	DpchAppWzemResume();
};

/**
	* DpchEngWzem
	*/
class DpchEngWzem : public DpchWzem {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchEngWzem(const Sbecore::uint ixWzemVDpch = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchEngWzem();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();
	virtual void merge(DpchEngWzem* dpcheng);

	virtual void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWzemAck
	*/
class DpchEngWzemAck : public DpchEngWzem {

public:
	DpchEngWzemAck(const Sbecore::ubigint jref = 0);
};

/**
	* DpchEngWzemAlert
	*/
class DpchEngWzemAlert : public DpchEngWzem {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWzemAlert(const Sbecore::ubigint jref = 0, ContInfWzemAlert* continf = NULL, Sbecore::Xmlio::Feed* feedFMcb = NULL, const std::set<Sbecore::uint>& mask = {NONE});

public:
	ContInfWzemAlert continf;
	Sbecore::Xmlio::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWzem* dpcheng);

	void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWzemConfirm
	*/
class DpchEngWzemConfirm : public DpchEngWzem {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREF = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWzemConfirm(const bool accepted = false, const Sbecore::ubigint jref = 0, const std::string& sref = "", const std::set<Sbecore::uint>& mask = {ALL});

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWzem* dpcheng);

	void writeXML(const Sbecore::uint ixWzemVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWzemSuspend
	*/
class DpchEngWzemSuspend : public DpchEngWzem {

public:
	DpchEngWzemSuspend(const Sbecore::ubigint jref = 0);
};

/**
	* StgWzemAppearance
	*/
class StgWzemAppearance : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint HISTLENGTH = 1;
	static const Sbecore::uint SUSPSESS = 2;

public:
	StgWzemAppearance(const Sbecore::usmallint histlength = 20, const bool suspsess = true);

public:
	Sbecore::usmallint histlength;
	bool suspsess;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzemAppearance* comp);
	std::set<Sbecore::uint> diff(const StgWzemAppearance* comp);
};

/**
	* StgWzemAppsrv
	*/
class StgWzemAppsrv : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint PORT = 1;
	static const Sbecore::uint HTTPS = 2;

public:
	StgWzemAppsrv(const Sbecore::usmallint port = 0, const bool https = false);

public:
	Sbecore::usmallint port;
	bool https;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzemAppsrv* comp);
	std::set<Sbecore::uint> diff(const StgWzemAppsrv* comp);
};

/**
	* StgWzemcmbd
	*/
class StgWzemcmbd : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint JOBPRCN = 1;
	static const Sbecore::uint OPPRCN = 2;
	static const Sbecore::uint APPSRV = 3;

public:
	StgWzemcmbd(const Sbecore::usmallint jobprcn = 1, const Sbecore::usmallint opprcn = 1, const bool appsrv = true);

public:
	Sbecore::usmallint jobprcn;
	Sbecore::usmallint opprcn;
	bool appsrv;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzemcmbd* comp);
	std::set<Sbecore::uint> diff(const StgWzemcmbd* comp);
};

/**
	* StgWzemDatabase
	*/
class StgWzemDatabase : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint IXDBSVDBSTYPE = 1;
	static const Sbecore::uint DBSPATH = 2;
	static const Sbecore::uint DBSNAME = 3;
	static const Sbecore::uint USERNAME = 4;
	static const Sbecore::uint PASSWORD = 5;
	static const Sbecore::uint IP = 6;
	static const Sbecore::uint PORT = 7;

public:
	StgWzemDatabase(const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "", const std::string& dbsname = "", const std::string& username = "mpsitech", const std::string& password = "f9w8feeh", const std::string& ip = "", const Sbecore::usmallint port = 0);

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzemDatabase* comp);
	std::set<Sbecore::uint> diff(const StgWzemDatabase* comp);
};

/**
	* StgWzemPath
	*/
class StgWzemPath : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint ACVPATH = 1;
	static const Sbecore::uint KEYPATH = 2;
	static const Sbecore::uint MONPATH = 3;
	static const Sbecore::uint TMPPATH = 4;
	static const Sbecore::uint WEBPATH = 5;
	static const Sbecore::uint HELPURL = 6;

public:
	StgWzemPath(const std::string& acvpath = "", const std::string& keypath = "", const std::string& monpath = "", const std::string& tmppath = "", const std::string& webpath = "", const std::string& helpurl = "");

public:
	std::string acvpath;
	std::string keypath;
	std::string monpath;
	std::string tmppath;
	std::string webpath;
	std::string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzemPath* comp);
	std::set<Sbecore::uint> diff(const StgWzemPath* comp);
};

/**
	* AlrWzem
	*/
namespace AlrWzem {
	DpchEngWzemAlert* prepareAlrAbt(const Sbecore::ubigint jref, const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feedFMcbAlert);
	DpchEngWzemAlert* prepareAlrIer(const Sbecore::ubigint jref, const Sbecore::uint ixWzemVLocale, const std::string& iexsqk, Sbecore::Xmlio::Feed& feedFMcbAlert);
	DpchEngWzemAlert* prepareAlrPer(const Sbecore::ubigint jref, const Sbecore::uint ixWzemVLocale, const std::string& iexsqk, Sbecore::Xmlio::Feed& feedFMcbAlert);
	DpchEngWzemAlert* prepareAlrSav(const Sbecore::ubigint jref, const Sbecore::uint ixWzemVLocale, Sbecore::Xmlio::Feed& feedFMcbAlert);
};

/**
	* ReqWzem
	*/
class ReqWzem {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint REDIRECT = 1; // web client triggered root request (GET)
		static const Sbecore::uint WEB = 2; // web client triggered ui file request (GET)
		static const Sbecore::uint CMD = 3; // command line request
		static const Sbecore::uint DPCHAPP = 4; // web client triggered Dpch request (POST+DpchApp)
		static const Sbecore::uint NOTIFY = 5; // web client triggered notify-on-Dpch request (GET)
		static const Sbecore::uint POLL = 6; // web client triggered Dpch poll request (GET)
		static const Sbecore::uint UPLOAD = 7; // web client triggered file upload request (POST)
		static const Sbecore::uint DOWNLOAD = 8; // web client triggered file download request (GET)
		static const Sbecore::uint DPCHRET = 9; // op engine or opprc triggered op return (DpchRet)
		static const Sbecore::uint METHOD = 10; // M2M interface triggered method request
		static const Sbecore::uint TIMER = 11; // timer triggered request
		static const Sbecore::uint EXTCALL = 12; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint RECEIVE = 1; // during data reception - appsrv internal
		static const Sbecore::uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const Sbecore::uint PRC = 3; // while being processesd by job processor ; appsrv thread waiting on cReply
		static const Sbecore::uint REPLY = 4; // after being processed by job processor
	};

public:
	ReqWzem(const Sbecore::uint ixVBasetype = VecVBasetype::NONE, const Sbecore::uint ixVState = VecVState::RECEIVE, const std::string& ip = "");
	~ReqWzem();

public:
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixVState;

	// specific data for base type CMD
	std::string cmd;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD
	std::string ip;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, DPCHAPP, NOTIFY, UPLOAD, DOWNLOAD, METHOD
	bool retain;
	Sbecore::Cond cReady; // mutex also protects compare/set of ixVState to REPLY

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	std::string filename; // full path
	std::fstream* file;
	size_t filelen;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* request;
	size_t requestlen;

	// specific data for base types CMD, DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	Sbecore::ubigint jref;

	// specific data for base type TIMER
	Sbecore::ubigint wref;
	std::string sref;

	// specific data for base type EXTCALL
	Sbecore::Call* call;

	// specific data for base types CMD, DPCHAPP, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	bool weak;

	// specific data for base type DPCHAPP
	DpchAppWzem* dpchapp;

	// specific data for base types DPCHAPP, NOTIFY, POLL
	DpchEngWzem* dpcheng;
	Sbecore::uint ixWzemVLocale;

	// specific data for base type DPCHRET
	DpchInvWzem* dpchinv;
	DpchRetWzem* dpchret;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* reply;
	size_t replylen;

	// specific data for base type METHOD
	Sbecore::Method* method;

public:
	void setStateReply();
};

/**
	* DcolWzem
	*/
class DcolWzem {

public:
	DcolWzem(const Sbecore::ubigint jref = 0, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS);
	~DcolWzem();

public:
	Sbecore::ubigint jref;

	Sbecore::uint ixWzemVLocale;

	Sbecore::Mutex mAccess;

	bool hot;

	std::list<DpchEngWzem*> dpchs;

	ReqWzem* req;

public:
	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* JobWzem
	*/
class JobWzem {

public:
	JobWzem(XchgWzem* xchg, const Sbecore::uint ixWzemVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS);
	virtual ~JobWzem();

public:
	XchgWzem* xchg;

	Sbecore::ubigint jref;

	Sbecore::uint ixWzemVJob;

	Sbecore::uint ixWzemVLocale;

	Sbecore::Mutex mAccess;

	bool muteRefresh;

	Sbecore::uint ixVSge;
	Sbecore::uint nextIxVSgeSuccess;
	Sbecore::uint nextIxVSgeFailure;

	std::string lasterror;

	Sbecore::uint opN;
	Sbecore::uint opNSuccess;
	Sbecore::uint opNFailure;

	std::vector<DpchInvWzem*> invs;

	Sbecore::Mutex mOps;
	std::list<Sbecore::Op*> ops;
	std::string opsqkLast;

	Sbecore::ubigint wrefLast;
	Sbecore::ubigint wrefMin;

	ReqWzem* reqCmd;

public:
	virtual DpchEngWzem* getNewDpchEng(std::set<Sbecore::uint> items);

	virtual void refresh(DbsWzem* dbswzem, std::set<Sbecore::uint>& moditems);
	void refreshWithDpchEng(DbsWzem* dbswzem, DpchEngWzem** dpcheng = NULL);

	virtual std::string getSquawk(DbsWzem* dbswzem);

	virtual void handleRequest(DbsWzem* dbswzem, ReqWzem* req);
	virtual void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);

	void lockAccess(const std::string& srefObject, const std::string& srefMember);
	bool trylockAccess(const std::string& srefObject, const std::string& srefMember);
	void unlockAccess(const std::string& srefObject, const std::string& srefMember);

	void lockAccess(const std::string& srefMember);
	bool trylockAccess(const std::string& srefMember);
	void unlockAccess(const std::string& srefMember);

	void setStage(DbsWzem* dbswzem, const Sbecore::uint _ixVSge);

	void clearInvs();
	Sbecore::ubigint addInv(DpchInvWzem* inv);
	void addInvs(std::vector<DpchInvWzem*>& _invs);
	void submitInvs(DbsWzem* dbswzem, const Sbecore::uint nextIxVSgeEmpty, Sbecore::uint& _ixVSge);

	void clearOps();
	void addOp(DbsWzem* dbswzem, DpchInvWzem* inv);
	void removeOp(const Sbecore::ubigint oref);
	std::string getOpsqkLast();

	void callback(const Sbecore::uint nextIxVSge);
	void invalidateWakeups();
};

/**
	* CsjobWzem
	*/
class CsjobWzem : public JobWzem {

public:
	CsjobWzem(XchgWzem* xchg, const Sbecore::uint ixWzemVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWzemVLocale = VecWzemVLocale::ENUS);

public:
	bool srvNotCli;
	CsjobWzem* srv; // client

public:
	virtual void handleClaim(DbsWzem* dbswzem, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest); // server
};

/**
	* ShrdatWzem
	*/
class ShrdatWzem {

public:
	ShrdatWzem(const std::string& srefSupclass, const std::string& srefObject);
	~ShrdatWzem();

public:
	std::string srefSupclass;
	std::string srefObject;

	Sbecore::Rwmutex rwmAccess;

public:
	virtual void init(XchgWzem* xchg, DbsWzem* dbswzem);
	virtual void term(XchgWzem* xchg);

	void rlockAccess(const std::string& srefObject, const std::string& srefMember);
	void runlockAccess(const std::string& srefObject, const std::string& srefMember);
	void rlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void runlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);

	void wlockAccess(const std::string& srefObject, const std::string& srefMember);
	void wunlockAccess(const std::string& srefObject, const std::string& srefMember);
	void wlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void wunlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
};

/**
	* StmgrWzem
	*/
class StmgrWzem {

public:
	StmgrWzem(XchgWzem* xchg, const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	~StmgrWzem();

public:
	XchgWzem* xchg;

	Sbecore::ubigint jref;
	Sbecore::uint ixVNonetype;

	Sbecore::Stcch* stcch;

	Sbecore::Mutex mAccess;

public:
	void handleCall(DbsWzem* dbswzem, Sbecore::Call* call);
	bool refresh(DbsWzem* dbswzem, Sbecore::Stcchitem* stit);

	void begin();
	void commit();

	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* WakeupWzem
	*/
class WakeupWzem {

public:
	WakeupWzem(XchgWzem* xchg, const Sbecore::ubigint wref, const Sbecore::ubigint jref, const std::string sref, const unsigned int deltat = 0, const bool weak = false);

public:
	XchgWzem* xchg;

	Sbecore::ubigint wref;

	Sbecore::ubigint jref;
	std::string sref;
	unsigned int deltat;
	bool weak;
};

/**
	* ExtcallWzem
	*/
class ExtcallWzem {

public:
	ExtcallWzem(XchgWzem* xchg, Sbecore::Call* call);

public:
	XchgWzem* xchg;
	Sbecore::Call* call;
};

/**
	* XchgWzemcmbd
	*/
class XchgWzemcmbd {

public:
	/**
		* ShrdatJobprc
		*/
	class ShrdatJobprc : public ShrdatWzem {

	public:
		// IP ShrdatJobprc.subs --- INSERT

	public:
		ShrdatJobprc();

	public:
		// IP ShrdatJobprc.vars --- INSERT

	public:
		void init(XchgWzem* xchg, DbsWzem* dbswzem);
		void term(XchgWzem* xchg);
	};

	/**
		* ShrdatOpprc
		*/
	class ShrdatOpprc : public ShrdatWzem {

	public:
		// IP ShrdatOpprc.subs --- INSERT

	public:
		ShrdatOpprc();

	public:
		// IP ShrdatOpprc.vars --- INSERT

	public:
		void init(XchgWzem* xchg, DbsWzem* dbswzem);
		void term(XchgWzem* xchg);
	};

public:
	XchgWzemcmbd();
	~XchgWzemcmbd();

public:
	StgWzemAppearance stgwzemappearance;
	StgWzemAppsrv stgwzemappsrv;
	StgWzemcmbd stgwzemcmbd;
	StgWzemDatabase stgwzemdatabase;
	StgWzemPath stgwzempath;

	ShrdatJobprc shrdatJobprc;
	ShrdatOpprc shrdatOpprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	std::string exedir;
	std::string acvpath;
	std::string tmppath;
	std::string helpurl;

	std::string key;
	std::string cert;

	// condition for thread start-up
	Sbecore::Cond cStable;

	// root job
	Sbecore::ubigint jrefRoot;

	// job receiving commands
	Sbecore::ubigint jrefCmd;

	// monitor object
	Sbecore::TxtMon mon;

	// log file
	Sbecore::Mutex mLogfile;

	// condition for job processors
	Sbecore::Cond cJobprcs;

	// condition for op processors
	Sbecore::Cond cOpprcs;

	// request list
	Sbecore::Mutex mReqs;
	std::list<ReqWzem*> reqs;

	// operation invocation list
	Sbecore::Refseq orefseq;
	Sbecore::Mutex mInvs;
	std::list<DpchInvWzem*> invs;

	// presetting list
	Sbecore::Rwmutex rwmPresets;
	std::multimap<Sbecore::presetref_t,Sbecore::Preset*> presets;

	// stub manager list
	Sbecore::Rwmutex rwmStmgrs;
	std::map<Sbecore::ubigint,StmgrWzem*> stmgrs;

	// call listener list
	Sbecore::Rwmutex rwmClstns;
	std::multimap<Sbecore::clstnref_t,Sbecore::Clstn*> clstns;
	std::multimap<Sbecore::clstnref2_t,Sbecore::clstnref_t> cref2sClstns;

	// dispatch collector list
	Sbecore::Rwmutex rwmDcols;
	std::map<Sbecore::ubigint,DcolWzem*> dcols;

	// job list
	Sbecore::Refseq jrefseq;
	Sbecore::Rwmutex rwmJobs;
	std::map<Sbecore::ubigint,JobWzem*> jobs;
	std::map<Sbecore::ubigint,Sbecore::uint> ixWzemVJobs;
	std::map<Sbecore::ubigint,Sbecore::Jobinfo*> jobinfos;

	// client/server job information
	Sbecore::Rwmutex rwmCsjobinfos;
	std::map<Sbecore::uint,Sbecore::Csjobinfo*> csjobinfos;

	// sequence for wakeup references
	Sbecore::Refseq wrefseq;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const std::string& str);

	// request list methods
	void addReq(ReqWzem* req);
	ReqWzem* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsWzem* dbswzem, JobWzem* job, std::vector<DpchInvWzem*>& dpchinvs);
	DpchInvWzem* pullFirstInv();

	// presetting methods
	Sbecore::Preset* addPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const Sbecore::Arg& arg);

	Sbecore::Preset* addIxPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const Sbecore::uint ix);
	Sbecore::Preset* addRefPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const Sbecore::ubigint ref);
	Sbecore::Preset* addRefsPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const std::vector<Sbecore::ubigint>& refs);
	Sbecore::Preset* addSrefPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const std::string& sref);
	Sbecore::Preset* addIntvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const int intval);
	Sbecore::Preset* addDblvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const double dblval);
	Sbecore::Preset* addBoolvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const bool boolval);
	Sbecore::Preset* addTxtvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref, const std::string& txtval);

	Sbecore::Preset* getPresetByPref(const Sbecore::presetref_t& pref);

	Sbecore::Arg getPreset(const Sbecore::uint ixWzemVPreset, Sbecore::ubigint jref);

	Sbecore::uint getIxPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	Sbecore::ubigint getRefPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	std::vector<Sbecore::ubigint> getRefsPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	std::string getSrefPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	int getIntvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	double getDblvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	bool getBoolvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	std::string getTxtvalPreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);

	void getPresetsByJref(const Sbecore::ubigint jref, std::vector<Sbecore::uint>& icsWzemVPreset, std::vector<Sbecore::Arg>& args);

	void removePreset(const Sbecore::uint ixWzemVPreset, const Sbecore::ubigint jref);
	void removePresetsByJref(const Sbecore::ubigint jref);

	// stub manager methods
	StmgrWzem* addStmgr(const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	StmgrWzem* getStmgrByJref(const Sbecore::ubigint jref);
	void removeStmgrByJref(const Sbecore::ubigint jref);

	// call listener list methods
	Sbecore::Clstn* addClstn(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig = 0, const bool chgarg = false, const Sbecore::Arg& arg = Sbecore::Arg(), const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addIxClstn(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addRefClstn(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefClstn(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefSrefClstn(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const std::string& sref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addClstnStmgr(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref);

	Sbecore::Clstn* getClstnByCref(const Sbecore::clstnref_t& cref);
	void getClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget, std::vector<Sbecore::uint>& icsWzemVCall, std::vector<Sbecore::uint>& icsVJobmask);

	void removeClstns(const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);
	void removeClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);

	// call methods
	void findJrefsByCall(Sbecore::Call* call, std::vector<Sbecore::ubigint>& jrefTrigs, std::vector<Sbecore::ubigint>& jrefs, std::vector<Sbecore::uint>& icsVTarget, std::vector<Sbecore::uint>& icsVJactype);

	void triggerCall(DbsWzem* dbswzem, Sbecore::Call* call);

	bool triggerArgToArgCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::Arg& argInv, Sbecore::Arg& argRet);
	bool triggerCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref);
	bool triggerIxCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv);
	bool triggerRefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv);
	bool triggerIntvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool triggerIxSrefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv);
	bool triggerIxSrefToIxCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv, Sbecore::uint& ixRet);
	bool triggerIxIntvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& txtvalInv);
	bool triggerSrefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const std::string& srefInv);
	bool triggerToBoolvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, std::string& srefRet);
	bool triggerRefToBoolvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerIxRefToRefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::ubigint& refRet);
	bool triggerIxRefSrefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool triggerRefToIxCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerSrefToRefCall(DbsWzem* dbswzem, const Sbecore::uint ixWzemVCall, const Sbecore::ubigint jref, const std::string& srefInv, Sbecore::ubigint& refRet);

	// dispatch collector list methods
	DcolWzem* addDcol(const Sbecore::ubigint jref);
	DcolWzem* getDcolByJref(Sbecore::ubigint jref, const bool tree = true);
	void removeDcolByJref(const Sbecore::ubigint jref);
	void removeDcolsByJref(const Sbecore::ubigint jref);

	void submitDpch(DpchEngWzem* dpcheng);
	DpchEngWzem* pullFirstDpch(DcolWzem* dcol);

	// job list methods
	Sbecore::ubigint addJob(DbsWzem* dbswzem, JobWzem* job, const Sbecore::ubigint jrefSup);
	JobWzem* getJobByJref(const Sbecore::ubigint jref);
	Sbecore::Jobinfo* getJobinfoByJref(const Sbecore::ubigint jref);
	void removeJobByJref(const Sbecore::ubigint jref);

	bool getJobSup(const Sbecore::ubigint jrefSup, Sbecore::ubigint jref);
	void setJobStage(DbsWzem* dbswzem, JobWzem* job, const Sbecore::uint ixVSge);

	// client/server job methods
	void addCsjobClaim(DbsWzem* dbswzem, CsjobWzem* csjob, Sbecore::Claim* claim);
	void getCsjobClaim(CsjobWzem* csjob, bool& takenNotAvailable, bool& fulfilled);
	void removeCsjobClaim(DbsWzem* dbswzem, CsjobWzem* csjob);

	bool getCsjobNotJob(const Sbecore::uint ixWzemVJob);
	std::set<Sbecore::ubigint> getCsjobClisByJref(const Sbecore::ubigint jref);

	// timer methods
	Sbecore::ubigint addWakeup(const Sbecore::ubigint jref, const std::string sref, const unsigned int deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);
};
#endif

