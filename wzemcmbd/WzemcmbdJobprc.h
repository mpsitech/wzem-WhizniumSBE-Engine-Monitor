/**
	* \file WzemcmbdJobprc.h
	* job processor for Wzem combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

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









