/**
	* \file WzemdOpengcli.h
	* operation engine client for Wzem daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMDOPENGCLI_H
#define WZEMDOPENGCLI_H

#include "WzemdOpprc.h"

/**
	* WzemdOpengcli
	*/
namespace WzemdOpengcli {
	void* run(void* arg);
	bool run_checkNodes(XchgWzem* xchg);

	bool CurlPostDpch(const std::string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, std::string& rplydpch);
	Sbecore::uint CurlPostrecv(void* data, Sbecore::uint size, Sbecore::uint blocksize, void* _arg);
};

/**
	* WzemdOpengcli_curlarg
	*/
struct WzemdOpengcli_curlarg {
	char* buf;
	size_t buflen;
};

#endif

