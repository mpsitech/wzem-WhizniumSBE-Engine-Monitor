/**
	* \file WzemdOpprc.h
	* operation processor for Wzem daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMDOPPRC_H
#define WZEMDOPPRC_H

/**
	* WzemdOpprc
	*/
namespace WzemdOpprc {
	void* run(void* arg);
	void cleanup(void* _arg);

	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _ret);

	void writeDpchInv(CURL* curl, XchgWzemd* xchg, ReqWzem* req);
	Sbecore::uint readDpchRet(XchgWzemd* xchg, ReqWzem* req);
};

/**
	* WzemdOpprc_arg
	*/
struct WzemdOpprc_arg {
	XchgWzemd* xchg;
	NodeWzem* node;
};

/**
	* WzemdOpprc_cuarg
	*/
struct WzemdOpprc_cuarg {
	XchgWzemd* xchg;
	ReqWzem** req;
	Sbecore::ubigint* oref;
	Sbecore::ubigint* jref;
};

#endif

