/**
	* \file Wzemd_exe.h
	* Wzem daemon main (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMD_EXE_H
#define WZEMD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

#include <signal.h>

#include "WzemdAppsrv.h"
#include "WzemdJobprc.h"
#include "WzemdOpengcli.h"
#include "WzemdOpengsrv.h"

/**
	* Wzemd
	*/
class Wzemd {

public:
	Wzemd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wzemd();

public:
	std::string exedir;

	DbsWzem dbswzem;

	XchgWzemd* xchg;
	
	RootWzem* root;

	MHD_Daemon* opengsrv;
	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	pthread_t opengcli;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif

