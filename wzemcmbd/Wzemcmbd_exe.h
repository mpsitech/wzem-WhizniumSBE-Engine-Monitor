/**
	* \file Wzemcmbd_exe.h
	* Wzem combined daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZEMCMBD_EXE_H
#define WZEMCMBD_EXE_H

#include <string>
#include <vector>

#include <signal.h>

#include "WzemcmbdAppsrv.h"
#include "WzemcmbdJobprc.h"
#include "WzemcmbdOpprc.h"

/**
	* Wzemcmbd
	*/
class Wzemcmbd {

public:
	Wzemcmbd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wzemcmbd();

public:
	std::string exedir;

	DbsWzem dbswzem;

	XchgWzemcmbd* xchg;
	
	RootWzem* root;

	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	std::vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif
