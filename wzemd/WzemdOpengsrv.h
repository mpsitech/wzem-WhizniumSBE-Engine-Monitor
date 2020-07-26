/**
	* \file WzemdOpengsrv.h
	* op engine server for Wzem daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#ifndef WZEMDOPENGSRV_H
#define WZEMDOPENGSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

/**
	* WzemdOpengsrv
	*/
namespace WzemdOpengsrv {
	MHD_Daemon* start(XchgWzem* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	Sbecore::uint readDpch(XchgWzemd* xchg, ReqopengconWzem* req);
	void writeDpchAck(ReqopengconWzem* req);
	void writeDpchReg(XchgWzemd* xchg, ReqopengconWzem* req, const Sbecore::ubigint nref);
};

#endif

