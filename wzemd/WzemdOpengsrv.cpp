/**
	* \file WzemdOpengsrv.cpp
	* op engine server for Wzem daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "Wzemd.h"

#include "WzemdOpengsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzemdOpengsrv
 ******************************************************************************/

MHD_Daemon* WzemdOpengsrv::start(
			XchgWzemd* xchg
		) {
	return MHD_start_daemon(MHD_USE_SELECT_INTERNALLY | MHD_USE_POLL, xchg->stgwzemd.opengsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_THREAD_POOL_SIZE, 16, MHD_OPTION_END);
};

void WzemdOpengsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int WzemdOpengsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int WzemdOpengsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWzemd* xchg = (XchgWzemd*) cls;

	MHD_Response* response;
	int retval = MHD_YES;

	ReqopengconWzem* req = NULL;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	uint ixWzemVDpch;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s;

	if (*con_cls == NULL) {
		// new request
		addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

		if (addr->sa_family == AF_INET) {
#ifdef _WIN32
			ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
			inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
			ip = ipstr;
#endif
		};

		s = string(url);

		if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				req = new ReqopengconWzem(ReqopengconWzem::VecVState::RECEIVE, ip);

				*con_cls = req;

				// prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);
				retval = MHD_YES;
			};
		};

		if (req == NULL) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);
		};

	} else {
		// active request
		req = (ReqopengconWzem*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

				retval = MHD_YES;

			} else {
				// POST done
				// cout << "MhdCallback() DPCHINV request complete" << endl;

				// read dispatch, pass on to job processor, and wait for reply to be transmitted
				if (req->request) {
					//cout << string(req->request, req->requestlen) << endl;
					ixWzemVDpch = readDpch(xchg, req);

					// handle request and compose reply
					if (ixWzemVDpch == VecWzemVDpch::DPCHWZEMOPDREG) {
						// add NodeWzem
						NodeWzem* node = xchg->addNode(req->ip, ((DpchWzemopdReg*) (req->dpchopd))->port, ((DpchWzemopdReg*) (req->dpchopd))->opprcn, ((DpchWzemopdReg*) (req->dpchopd))->ixWzemVOpengtype);

						// log
						xchg->appendToLogfile("operation engine at [" + req->ip + "]:" + to_string(((DpchWzemopdReg*) (req->dpchopd))->port) + " added");

						writeDpchReg(xchg, req, node->nref);

					} else if (ixWzemVDpch == VecWzemVDpch::DPCHWZEMOPDUNREG) {
						// remove NodeWzemd
						NodeWzem* node = xchg->getNodeByNref(((DpchWzemopdUnreg*) (req->dpchopd))->nref);
						if (node) xchg->setNodeState(node, NodeWzem::VecVState::ERROR);

						writeDpchAck(req);
					};
					
					if (req->reply) {
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					} else {
						response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};

				} else {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};
	};

	return retval;
};

int WzemdOpengsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqopengconWzem* req = (ReqopengconWzem*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	// copy data into req->request (append if required)
	if (strcmp(key, "xml") != 0) return MHD_NO;

	if (size > 0) {
		if (!req->request) {
			req->request = new char[size];
			memcpy(req->request, data, size);
			req->requestlen = size;

		} else {
			olddata = req->request;

			req->request = new char[req->requestlen + size];
			memcpy(req->request, olddata, req->requestlen);
			memcpy(&(req->request[req->requestlen]), data, size);
			req->requestlen = req->requestlen + size;

			delete[] olddata;
		};
	};

	return MHD_YES;
};

void WzemdOpengsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqopengconWzem* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqopengconWzem*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

uint WzemdOpengsrv::readDpch(
			XchgWzemd* xchg
			, ReqopengconWzem* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixWzemVDpch = VecWzemVDpch::getIx(extractRoot(doc));

	if (ixWzemVDpch == VecWzemVDpch::DPCHWZEMOPDREG) {
		req->dpchopd = new DpchWzemopdReg();
		((DpchWzemopdReg*) (req->dpchopd))->readXML(docctx, "/", true);
	} else if (ixWzemVDpch == VecWzemVDpch::DPCHWZEMOPDUNREG) {
		req->dpchopd = new DpchWzemopdUnreg();
		((DpchWzemopdUnreg*) (req->dpchopd))->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWzemVDpch;
};

void WzemdOpengsrv::writeDpchAck(
			ReqopengconWzem* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchWzemdAck::writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

void WzemdOpengsrv::writeDpchReg(
			XchgWzemd* xchg
			, ReqopengconWzem* req
			, const ubigint nref
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchWzemdReg::writeXML(wr, nref);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

