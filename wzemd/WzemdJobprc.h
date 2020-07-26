/**
	* \file WzemdJobprc.h
	* job processor for Wzem daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMDJOBPRC_H
#define WZEMDJOBPRC_H

/**
	* WzemdJobprc
	*/
namespace WzemdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWzemd* xchg, DbsWzem* dbswzem, ReqWzem* req);
};

#endif

