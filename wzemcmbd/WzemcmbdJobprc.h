/**
	* \file WzemcmbdJobprc.h
	* job processor for Wzem combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
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



