/**
	* \file WzemcmbdJobprc.h
	* job processor for Wzem combined daemon (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMCMBDJOBPRC_H
#define WZEMCMBDJOBPRC_H

/**
	* WzemcmbdJobprc
	*/
namespace WzemcmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWzemcmbd* xchg, DbsWzem* dbswzem, ReqWzem* req);
};

#endif



