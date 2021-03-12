/**
	* \file WzemcmbdAppsrv.cpp
	* application server for Wzem combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#include "Wzemcmbd.h"

#include "WzemcmbdAppsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzemcmbdAppsrv
 ******************************************************************************/

MHD_Daemon* WzemcmbdAppsrv::start(
			XchgWzemcmbd* xchg
		) {
	if (xchg->stgwzemappsrv.https) {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL | MHD_USE_SSL, xchg->stgwzemappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_HTTPS_MEM_KEY, xchg->key.c_str(), MHD_OPTION_HTTPS_MEM_CERT, xchg->cert.c_str(), MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	} else {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgwzemappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	};
};

void WzemcmbdAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

MHD_Result WzemcmbdAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

MHD_Result WzemcmbdAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWzem* xchg = (XchgWzem*) cls;

	MHD_Response* response;
	MHD_Result retval = MHD_YES;

	ReqWzem* req;

	uint ixVBasetype = ReqWzem::VecVBasetype::NONE;
	string filename;
	bool jsonNotXml = false;
	string scrJref;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	uint ixWzemVDpch;

	ubigint jrefNotify;

	DcolWzem* dcol;

	vector<string> ss;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		StrMod::stringToVector(string(url), ss, '/');

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << string(url) << "'" << endl;

			if (ss.size() >= 1) if (ss[0] == "") {

				if (ss.size() == 2) {
					if (ss[1] == "") ixVBasetype = ReqWzem::VecVBasetype::REDIRECT;

				} else if (ss.size() >= 3) {
					if (ss[1] == "web") {
						// ex. "/web/CrdWzemNav/CrdWzemNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url
						ixVBasetype = ReqWzem::VecVBasetype::WEB;

						filename = xchg->stgwzempath.webpath;

						for (unsigned int i = 2; i < ss.size(); i++) {
							// inhibit requests to ../ directories
							if (ss[i] != "..") filename += "/" + ss[i];
							else {
								ixVBasetype = ReqWzem::VecVBasetype::NONE;
								break;
							};
						};

						if (ixVBasetype == ReqWzem::VecVBasetype::WEB) {
							// cout << "request for '" << s << "' by html transfer" << endl;

							// check if file exists
							if (access(filename.c_str(), R_OK) != 0) ixVBasetype = ReqWzem::VecVBasetype::NONE;
						};

					} else {
						if (ss[1] == "notify") ixVBasetype = ReqWzem::VecVBasetype::NOTIFY;
						else if (ss[1] == "poll") ixVBasetype = ReqWzem::VecVBasetype::POLL;
						else if (ss[1] == "download") ixVBasetype = ReqWzem::VecVBasetype::DOWNLOAD;

						if (ixVBasetype != ReqWzem::VecVBasetype::NONE) {
							// ex. "/{notify/poll/download}[/{json vs. xml}]/abcd1234efgh5678"
							if (ss.size() == 3) scrJref = ss[2];
							else if (ss.size() == 4) {
								jsonNotXml = (ss[2] == "json");

								if (jsonNotXml || (ss[2] == "xml")) scrJref = ss[3];
								else ixVBasetype = ReqWzem::VecVBasetype::NONE;

							} else ixVBasetype = ReqWzem::VecVBasetype::NONE;
						};
					};
				};
			};

		} else if (strcmp(method, "POST") == 0) {

			if (ss.size() >= 1) if (ss[0] == "") {

				if ((ss.size() == 2) && (ss[1] == "dpch")) {
					// always "/dpch"
					ixVBasetype = ReqWzem::VecVBasetype::DPCHAPP;

				} else if ((ss.size() == 3) && (ss[1] == "upload")) {
					// ex. "/upload/abcd1234efgh5678"
					ixVBasetype = ReqWzem::VecVBasetype::UPLOAD;
					scrJref = ss[2];
				};
			};
		};

		if (ixVBasetype == ReqWzem::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else if (ixVBasetype == ReqWzem::VecVBasetype::REDIRECT) {
			response = MHD_create_response_from_buffer(0, NULL, MHD_RESPMEM_PERSISTENT);
			MHD_add_response_header(response, "Location", "/web/CrdWzemStart/CrdWzemStart.html");
			retval = MHD_queue_response(connection, MHD_HTTP_MOVED_PERMANENTLY, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqWzem(ixVBasetype, ReqWzem::VecVState::RECEIVE, ip);
			*con_cls = req;

			if (req->ixVBasetype == ReqWzem::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = filename;

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecWzemVMimetype::getTitle(VecWzemVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecWzemVMimetype::getTitle(VecWzemVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jsonNotXml = jsonNotXml;

				req->jref = Scr::descramble(scrJref);
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixWzemVLocale = dcol->ixWzemVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngWzemAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("WzemcmbdAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngWzemSuspend(req->jref);

							dcol->unlockAccess("WzemcmbdAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngWzemAck(req->jref);
							dcol->req = req;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							req->cReady.lockMutex("WzemcmbdAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("WzemcmbdAppsrv", "MhdCallback[3]");
							req->cReady.timedwait(15000000, "WzemcmbdAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							req->cReady.unlockMutex("WzemcmbdAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("WzemcmbdAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngWzemConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqWzem::VecVState::REPLY;

						// send reply ; note that the result of timedwait() doesn't matter
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("WzemcmbdAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqWzem::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jsonNotXml = jsonNotXml;

				req->jref = Scr::descramble(scrJref);
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixWzemVLocale = dcol->ixWzemVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngWzemAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("WzemcmbdAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqWzem::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(scrJref);

				// generate file in tmp directory, and open it
				req->filename = xchg->stgwzempath.tmppath + "/" + Tmp::newfile(xchg->stgwzempath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWzem::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(scrJref);

				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					req->cReady.lockMutex("WzemcmbdAppsrv", "MhdCallback[2]");
					if (req->ixVState != ReqWzem::VecVState::REPLY) req->cReady.wait("WzemcmbdAppsrv", "MhdCallback[1]");
					req->cReady.unlockMutex("WzemcmbdAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: DPCHAPP, UPLOAD)
		req = (ReqWzem*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() DPCHAPP request complete" << endl;
					valid = req->request;
					
					if (valid) {
						// cout << string(req->request, req->requestlen) << endl;
						ixWzemVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixWzemVDpch == VecWzemVDpch::DPCHAPPROOTWZEMLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("WzemcmbdAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqWzem::VecVState::REPLY) req->cReady.wait("WzemcmbdAppsrv", "MhdCallback[2]");
						req->cReady.unlockMutex("WzemcmbdAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqWzem::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						req->cReady.lockMutex("WzemcmbdAppsrv", "MhdCallback[4]");
						if (req->ixVState != ReqWzem::VecVState::REPLY) req->cReady.wait("WzemcmbdAppsrv", "MhdCallback[3]");
						req->cReady.unlockMutex("WzemcmbdAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), (void*) empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), (void*) invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int WzemcmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t WzemcmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqWzem* req = (ReqWzem*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

MHD_Result WzemcmbdAppsrv::MhdPostrecv(
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
	ReqWzem* req = (ReqWzem*) con_cls;

	// cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqWzem::VecVBasetype::DPCHAPP) {
		// --- copy data into req->request (append if required)
		req->jsonNotXml = (strcmp(key, "json") == 0);
		if (!req->jsonNotXml) if (strcmp(key, "xml") != 0) return MHD_NO;

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

	} else if (req->ixVBasetype == ReqWzem::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void WzemcmbdAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqWzem* req;

	// cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqWzem*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool WzemcmbdAppsrv::validateIp(
			XchgWzemcmbd* xchg
			, ReqWzem* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		if (xchg->getBoolvalPreset(VecWzemVPreset::PREWZEMSUSPSESS, req->jref))
					if (req->jref != xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFSESS, req->jref)) retval = false;

		if (retval) {
			ip = xchg->getTxtvalPreset(VecWzemVPreset::PREWZEMIP, req->jref);
			if (ip != req->ip) retval = false;
		};
	};

	return retval;
};

bool WzemcmbdAppsrv::validateJrefNotify(
			XchgWzemcmbd* xchg
			, ReqWzem* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolWzem* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecWzemVPreset::PREWZEMJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecWzemVCall::CALLWZEMREFPRESET, dcol->jref, VecWzemVPreset::PREWZEMJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("WzemcmbdAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint WzemcmbdAppsrv::readDpchApp(
			XchgWzemcmbd* xchg
			, ReqWzem* req
		) {
	uint ixWzemVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	istringstream str;
	Json::Value root;
	Json::Value::Members members;

	if (!req->jsonNotXml) {
		try {
			parseBuffer(req->request, req->requestlen, &doc, &docctx);

			ixWzemVDpch = VecWzemVDpch::getIx(extractRoot(doc));

			if (ixWzemVDpch == VecWzemVDpch::DPCHAPPDLGWZEMNAVLOAINIDATA) {
				req->dpchapp = new DlgWzemNavLoaini::DpchAppData();
				((DlgWzemNavLoaini::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPDLGWZEMNAVLOAINIDO) {
				req->dpchapp = new DlgWzemNavLoaini::DpchAppDo();
				((DlgWzemNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPROOTWZEMLOGIN) {
				req->dpchapp = new RootWzem::DpchAppLogin();
				((RootWzem::DpchAppLogin*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMALERT) {
				req->dpchapp = new DpchAppWzemAlert();
				((DpchAppWzemAlert*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALDETAILDATA) {
				req->dpchapp = new PnlWzemCalDetail::DpchAppData();
				((PnlWzemCalDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALDETAILDO) {
				req->dpchapp = new PnlWzemCalDetail::DpchAppDo();
				((PnlWzemCalDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALDO) {
				req->dpchapp = new CrdWzemCal::DpchAppDo();
				((CrdWzemCal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALLISTDATA) {
				req->dpchapp = new PnlWzemCalList::DpchAppData();
				((PnlWzemCalList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALLISTDO) {
				req->dpchapp = new PnlWzemCalList::DpchAppDo();
				((PnlWzemCalList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALRECDO) {
				req->dpchapp = new PnlWzemCalRec::DpchAppDo();
				((PnlWzemCalRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDETAILDATA) {
				req->dpchapp = new PnlWzemClnDetail::DpchAppData();
				((PnlWzemClnDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDETAILDO) {
				req->dpchapp = new PnlWzemClnDetail::DpchAppDo();
				((PnlWzemClnDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDO) {
				req->dpchapp = new CrdWzemCln::DpchAppDo();
				((CrdWzemCln::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNLISTDATA) {
				req->dpchapp = new PnlWzemClnList::DpchAppData();
				((PnlWzemClnList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNLISTDO) {
				req->dpchapp = new PnlWzemClnList::DpchAppDo();
				((PnlWzemClnList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNRECDO) {
				req->dpchapp = new PnlWzemClnRec::DpchAppDo();
				((PnlWzemClnRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDETAILDATA) {
				req->dpchapp = new PnlWzemEvtDetail::DpchAppData();
				((PnlWzemEvtDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDETAILDO) {
				req->dpchapp = new PnlWzemEvtDetail::DpchAppDo();
				((PnlWzemEvtDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDO) {
				req->dpchapp = new CrdWzemEvt::DpchAppDo();
				((CrdWzemEvt::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTLISTDATA) {
				req->dpchapp = new PnlWzemEvtList::DpchAppData();
				((PnlWzemEvtList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTLISTDO) {
				req->dpchapp = new PnlWzemEvtList::DpchAppDo();
				((PnlWzemEvtList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTRECDO) {
				req->dpchapp = new PnlWzemEvtRec::DpchAppDo();
				((PnlWzemEvtRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMINIT) {
				req->dpchapp = new DpchAppWzemInit();
				((DpchAppWzemInit*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCALLDATA) {
				req->dpchapp = new PnlWzemJob1NCall::DpchAppData();
				((PnlWzemJob1NCall::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCALLDO) {
				req->dpchapp = new PnlWzemJob1NCall::DpchAppDo();
				((PnlWzemJob1NCall::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCLSTNDATA) {
				req->dpchapp = new PnlWzemJob1NClstn::DpchAppData();
				((PnlWzemJob1NClstn::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCLSTNDO) {
				req->dpchapp = new PnlWzemJob1NClstn::DpchAppDo();
				((PnlWzemJob1NClstn::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NOPDATA) {
				req->dpchapp = new PnlWzemJob1NOp::DpchAppData();
				((PnlWzemJob1NOp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NOPDO) {
				req->dpchapp = new PnlWzemJob1NOp::DpchAppDo();
				((PnlWzemJob1NOp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NPRESETDATA) {
				req->dpchapp = new PnlWzemJob1NPreset::DpchAppData();
				((PnlWzemJob1NPreset::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NPRESETDO) {
				req->dpchapp = new PnlWzemJob1NPreset::DpchAppDo();
				((PnlWzemJob1NPreset::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDETAILDATA) {
				req->dpchapp = new PnlWzemJobDetail::DpchAppData();
				((PnlWzemJobDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDETAILDO) {
				req->dpchapp = new PnlWzemJobDetail::DpchAppDo();
				((PnlWzemJobDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDO) {
				req->dpchapp = new CrdWzemJob::DpchAppDo();
				((CrdWzemJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBLISTDATA) {
				req->dpchapp = new PnlWzemJobList::DpchAppData();
				((PnlWzemJobList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBLISTDO) {
				req->dpchapp = new PnlWzemJobList::DpchAppDo();
				((PnlWzemJobList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBRECDO) {
				req->dpchapp = new PnlWzemJobRec::DpchAppDo();
				((PnlWzemJobRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBSUP1NJOBDATA) {
				req->dpchapp = new PnlWzemJobSup1NJob::DpchAppData();
				((PnlWzemJobSup1NJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBSUP1NJOBDO) {
				req->dpchapp = new PnlWzemJobSup1NJob::DpchAppDo();
				((PnlWzemJobSup1NJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVADMINDATA) {
				req->dpchapp = new PnlWzemNavAdmin::DpchAppData();
				((PnlWzemNavAdmin::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVADMINDO) {
				req->dpchapp = new PnlWzemNavAdmin::DpchAppDo();
				((PnlWzemNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVDO) {
				req->dpchapp = new CrdWzemNav::DpchAppDo();
				((CrdWzemNav::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVMONDATA) {
				req->dpchapp = new PnlWzemNavMon::DpchAppData();
				((PnlWzemNavMon::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVMONDO) {
				req->dpchapp = new PnlWzemNavMon::DpchAppDo();
				((PnlWzemNavMon::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVPREDO) {
				req->dpchapp = new PnlWzemNavPre::DpchAppDo();
				((PnlWzemNavPre::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDETAILDATA) {
				req->dpchapp = new PnlWzemNdeDetail::DpchAppData();
				((PnlWzemNdeDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDETAILDO) {
				req->dpchapp = new PnlWzemNdeDetail::DpchAppDo();
				((PnlWzemNdeDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDO) {
				req->dpchapp = new CrdWzemNde::DpchAppDo();
				((CrdWzemNde::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDELISTDATA) {
				req->dpchapp = new PnlWzemNdeList::DpchAppData();
				((PnlWzemNdeList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDELISTDO) {
				req->dpchapp = new PnlWzemNdeList::DpchAppDo();
				((PnlWzemNdeList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDERECDO) {
				req->dpchapp = new PnlWzemNdeRec::DpchAppDo();
				((PnlWzemNdeRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDETAILDATA) {
				req->dpchapp = new PnlWzemOpxDetail::DpchAppData();
				((PnlWzemOpxDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDETAILDO) {
				req->dpchapp = new PnlWzemOpxDetail::DpchAppDo();
				((PnlWzemOpxDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDO) {
				req->dpchapp = new CrdWzemOpx::DpchAppDo();
				((CrdWzemOpx::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXLISTDATA) {
				req->dpchapp = new PnlWzemOpxList::DpchAppData();
				((PnlWzemOpxList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXLISTDO) {
				req->dpchapp = new PnlWzemOpxList::DpchAppDo();
				((PnlWzemOpxList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXRECDO) {
				req->dpchapp = new PnlWzemOpxRec::DpchAppDo();
				((PnlWzemOpxRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NEVENTDATA) {
				req->dpchapp = new PnlWzemPrd1NEvent::DpchAppData();
				((PnlWzemPrd1NEvent::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NEVENTDO) {
				req->dpchapp = new PnlWzemPrd1NEvent::DpchAppDo();
				((PnlWzemPrd1NEvent::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NJOBDATA) {
				req->dpchapp = new PnlWzemPrd1NJob::DpchAppData();
				((PnlWzemPrd1NJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NJOBDO) {
				req->dpchapp = new PnlWzemPrd1NJob::DpchAppDo();
				((PnlWzemPrd1NJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NNODEDATA) {
				req->dpchapp = new PnlWzemPrd1NNode::DpchAppData();
				((PnlWzemPrd1NNode::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NNODEDO) {
				req->dpchapp = new PnlWzemPrd1NNode::DpchAppDo();
				((PnlWzemPrd1NNode::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDDETAILDATA) {
				req->dpchapp = new PnlWzemPrdDetail::DpchAppData();
				((PnlWzemPrdDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDDETAILDO) {
				req->dpchapp = new PnlWzemPrdDetail::DpchAppDo();
				((PnlWzemPrdDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDDO) {
				req->dpchapp = new CrdWzemPrd::DpchAppDo();
				((CrdWzemPrd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDLISTDATA) {
				req->dpchapp = new PnlWzemPrdList::DpchAppData();
				((PnlWzemPrdList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDLISTDO) {
				req->dpchapp = new PnlWzemPrdList::DpchAppDo();
				((PnlWzemPrdList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDRECDO) {
				req->dpchapp = new PnlWzemPrdRec::DpchAppDo();
				((PnlWzemPrdRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSADETAILDATA) {
				req->dpchapp = new PnlWzemPrsADetail::DpchAppData();
				((PnlWzemPrsADetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSADETAILDO) {
				req->dpchapp = new PnlWzemPrsADetail::DpchAppDo();
				((PnlWzemPrsADetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDETAILDATA) {
				req->dpchapp = new PnlWzemPrsDetail::DpchAppData();
				((PnlWzemPrsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDETAILDO) {
				req->dpchapp = new PnlWzemPrsDetail::DpchAppDo();
				((PnlWzemPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDO) {
				req->dpchapp = new CrdWzemPrs::DpchAppDo();
				((CrdWzemPrs::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSLISTDATA) {
				req->dpchapp = new PnlWzemPrsList::DpchAppData();
				((PnlWzemPrsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSLISTDO) {
				req->dpchapp = new PnlWzemPrsList::DpchAppDo();
				((PnlWzemPrsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSRECDO) {
				req->dpchapp = new PnlWzemPrsRec::DpchAppDo();
				((PnlWzemPrsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDETAILDATA) {
				req->dpchapp = new PnlWzemPstDetail::DpchAppData();
				((PnlWzemPstDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDETAILDO) {
				req->dpchapp = new PnlWzemPstDetail::DpchAppDo();
				((PnlWzemPstDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDO) {
				req->dpchapp = new CrdWzemPst::DpchAppDo();
				((CrdWzemPst::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTLISTDATA) {
				req->dpchapp = new PnlWzemPstList::DpchAppData();
				((PnlWzemPstList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTLISTDO) {
				req->dpchapp = new PnlWzemPstList::DpchAppDo();
				((PnlWzemPstList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTRECDO) {
				req->dpchapp = new PnlWzemPstRec::DpchAppDo();
				((PnlWzemPstRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMRESUME) {
				req->dpchapp = new DpchAppWzemResume();
				((DpchAppWzemResume*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGAACCESSDATA) {
				req->dpchapp = new PnlWzemUsgAAccess::DpchAppData();
				((PnlWzemUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGAACCESSDO) {
				req->dpchapp = new PnlWzemUsgAAccess::DpchAppDo();
				((PnlWzemUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGDETAILDATA) {
				req->dpchapp = new PnlWzemUsgDetail::DpchAppData();
				((PnlWzemUsgDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGDETAILDO) {
				req->dpchapp = new PnlWzemUsgDetail::DpchAppDo();
				((PnlWzemUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGDO) {
				req->dpchapp = new CrdWzemUsg::DpchAppDo();
				((CrdWzemUsg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGLISTDATA) {
				req->dpchapp = new PnlWzemUsgList::DpchAppData();
				((PnlWzemUsgList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGLISTDO) {
				req->dpchapp = new PnlWzemUsgList::DpchAppDo();
				((PnlWzemUsgList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGMNUSERDATA) {
				req->dpchapp = new PnlWzemUsgMNUser::DpchAppData();
				((PnlWzemUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGMNUSERDO) {
				req->dpchapp = new PnlWzemUsgMNUser::DpchAppDo();
				((PnlWzemUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGRECDO) {
				req->dpchapp = new PnlWzemUsgRec::DpchAppDo();
				((PnlWzemUsgRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSR1NSESSIONDATA) {
				req->dpchapp = new PnlWzemUsr1NSession::DpchAppData();
				((PnlWzemUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSR1NSESSIONDO) {
				req->dpchapp = new PnlWzemUsr1NSession::DpchAppDo();
				((PnlWzemUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRAACCESSDATA) {
				req->dpchapp = new PnlWzemUsrAAccess::DpchAppData();
				((PnlWzemUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRAACCESSDO) {
				req->dpchapp = new PnlWzemUsrAAccess::DpchAppDo();
				((PnlWzemUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDETAILDATA) {
				req->dpchapp = new PnlWzemUsrDetail::DpchAppData();
				((PnlWzemUsrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDETAILDO) {
				req->dpchapp = new PnlWzemUsrDetail::DpchAppDo();
				((PnlWzemUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDO) {
				req->dpchapp = new CrdWzemUsr::DpchAppDo();
				((CrdWzemUsr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRLISTDATA) {
				req->dpchapp = new PnlWzemUsrList::DpchAppData();
				((PnlWzemUsrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRLISTDO) {
				req->dpchapp = new PnlWzemUsrList::DpchAppDo();
				((PnlWzemUsrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRMNUSERGROUPDATA) {
				req->dpchapp = new PnlWzemUsrMNUsergroup::DpchAppData();
				((PnlWzemUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRMNUSERGROUPDO) {
				req->dpchapp = new PnlWzemUsrMNUsergroup::DpchAppDo();
				((PnlWzemUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRRECDO) {
				req->dpchapp = new PnlWzemUsrRec::DpchAppDo();
				((PnlWzemUsrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
			};
		} catch (SbeException& e) {
		};

		if (docctx) xmlXPathFreeContext(docctx);
		if (doc) xmlFreeDoc(doc);
	
	} else {
		try {
			str.rdbuf()->pubsetbuf(req->request, req->requestlen);
			str >> root;

			members = root.getMemberNames();
			if (members.size() == 1) ixWzemVDpch = VecWzemVDpch::getIx(members[0]);

			if (ixWzemVDpch == VecWzemVDpch::DPCHAPPDLGWZEMNAVLOAINIDATA) {
				req->dpchapp = new DlgWzemNavLoaini::DpchAppData();
				((DlgWzemNavLoaini::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPDLGWZEMNAVLOAINIDO) {
				req->dpchapp = new DlgWzemNavLoaini::DpchAppDo();
				((DlgWzemNavLoaini::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPROOTWZEMLOGIN) {
				req->dpchapp = new RootWzem::DpchAppLogin();
				((RootWzem::DpchAppLogin*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMALERT) {
				req->dpchapp = new DpchAppWzemAlert();
				((DpchAppWzemAlert*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALDETAILDATA) {
				req->dpchapp = new PnlWzemCalDetail::DpchAppData();
				((PnlWzemCalDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALDETAILDO) {
				req->dpchapp = new PnlWzemCalDetail::DpchAppDo();
				((PnlWzemCalDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALDO) {
				req->dpchapp = new CrdWzemCal::DpchAppDo();
				((CrdWzemCal::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALLISTDATA) {
				req->dpchapp = new PnlWzemCalList::DpchAppData();
				((PnlWzemCalList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALLISTDO) {
				req->dpchapp = new PnlWzemCalList::DpchAppDo();
				((PnlWzemCalList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCALRECDO) {
				req->dpchapp = new PnlWzemCalRec::DpchAppDo();
				((PnlWzemCalRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDETAILDATA) {
				req->dpchapp = new PnlWzemClnDetail::DpchAppData();
				((PnlWzemClnDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDETAILDO) {
				req->dpchapp = new PnlWzemClnDetail::DpchAppDo();
				((PnlWzemClnDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNDO) {
				req->dpchapp = new CrdWzemCln::DpchAppDo();
				((CrdWzemCln::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNLISTDATA) {
				req->dpchapp = new PnlWzemClnList::DpchAppData();
				((PnlWzemClnList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNLISTDO) {
				req->dpchapp = new PnlWzemClnList::DpchAppDo();
				((PnlWzemClnList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMCLNRECDO) {
				req->dpchapp = new PnlWzemClnRec::DpchAppDo();
				((PnlWzemClnRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDETAILDATA) {
				req->dpchapp = new PnlWzemEvtDetail::DpchAppData();
				((PnlWzemEvtDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDETAILDO) {
				req->dpchapp = new PnlWzemEvtDetail::DpchAppDo();
				((PnlWzemEvtDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTDO) {
				req->dpchapp = new CrdWzemEvt::DpchAppDo();
				((CrdWzemEvt::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTLISTDATA) {
				req->dpchapp = new PnlWzemEvtList::DpchAppData();
				((PnlWzemEvtList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTLISTDO) {
				req->dpchapp = new PnlWzemEvtList::DpchAppDo();
				((PnlWzemEvtList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMEVTRECDO) {
				req->dpchapp = new PnlWzemEvtRec::DpchAppDo();
				((PnlWzemEvtRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMINIT) {
				req->dpchapp = new DpchAppWzemInit();
				((DpchAppWzemInit*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCALLDATA) {
				req->dpchapp = new PnlWzemJob1NCall::DpchAppData();
				((PnlWzemJob1NCall::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCALLDO) {
				req->dpchapp = new PnlWzemJob1NCall::DpchAppDo();
				((PnlWzemJob1NCall::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCLSTNDATA) {
				req->dpchapp = new PnlWzemJob1NClstn::DpchAppData();
				((PnlWzemJob1NClstn::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NCLSTNDO) {
				req->dpchapp = new PnlWzemJob1NClstn::DpchAppDo();
				((PnlWzemJob1NClstn::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NOPDATA) {
				req->dpchapp = new PnlWzemJob1NOp::DpchAppData();
				((PnlWzemJob1NOp::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NOPDO) {
				req->dpchapp = new PnlWzemJob1NOp::DpchAppDo();
				((PnlWzemJob1NOp::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NPRESETDATA) {
				req->dpchapp = new PnlWzemJob1NPreset::DpchAppData();
				((PnlWzemJob1NPreset::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOB1NPRESETDO) {
				req->dpchapp = new PnlWzemJob1NPreset::DpchAppDo();
				((PnlWzemJob1NPreset::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDETAILDATA) {
				req->dpchapp = new PnlWzemJobDetail::DpchAppData();
				((PnlWzemJobDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDETAILDO) {
				req->dpchapp = new PnlWzemJobDetail::DpchAppDo();
				((PnlWzemJobDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBDO) {
				req->dpchapp = new CrdWzemJob::DpchAppDo();
				((CrdWzemJob::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBLISTDATA) {
				req->dpchapp = new PnlWzemJobList::DpchAppData();
				((PnlWzemJobList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBLISTDO) {
				req->dpchapp = new PnlWzemJobList::DpchAppDo();
				((PnlWzemJobList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBRECDO) {
				req->dpchapp = new PnlWzemJobRec::DpchAppDo();
				((PnlWzemJobRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBSUP1NJOBDATA) {
				req->dpchapp = new PnlWzemJobSup1NJob::DpchAppData();
				((PnlWzemJobSup1NJob::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMJOBSUP1NJOBDO) {
				req->dpchapp = new PnlWzemJobSup1NJob::DpchAppDo();
				((PnlWzemJobSup1NJob::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVADMINDATA) {
				req->dpchapp = new PnlWzemNavAdmin::DpchAppData();
				((PnlWzemNavAdmin::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVADMINDO) {
				req->dpchapp = new PnlWzemNavAdmin::DpchAppDo();
				((PnlWzemNavAdmin::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVDO) {
				req->dpchapp = new CrdWzemNav::DpchAppDo();
				((CrdWzemNav::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVMONDATA) {
				req->dpchapp = new PnlWzemNavMon::DpchAppData();
				((PnlWzemNavMon::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVMONDO) {
				req->dpchapp = new PnlWzemNavMon::DpchAppDo();
				((PnlWzemNavMon::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNAVPREDO) {
				req->dpchapp = new PnlWzemNavPre::DpchAppDo();
				((PnlWzemNavPre::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDETAILDATA) {
				req->dpchapp = new PnlWzemNdeDetail::DpchAppData();
				((PnlWzemNdeDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDETAILDO) {
				req->dpchapp = new PnlWzemNdeDetail::DpchAppDo();
				((PnlWzemNdeDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDEDO) {
				req->dpchapp = new CrdWzemNde::DpchAppDo();
				((CrdWzemNde::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDELISTDATA) {
				req->dpchapp = new PnlWzemNdeList::DpchAppData();
				((PnlWzemNdeList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDELISTDO) {
				req->dpchapp = new PnlWzemNdeList::DpchAppDo();
				((PnlWzemNdeList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMNDERECDO) {
				req->dpchapp = new PnlWzemNdeRec::DpchAppDo();
				((PnlWzemNdeRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDETAILDATA) {
				req->dpchapp = new PnlWzemOpxDetail::DpchAppData();
				((PnlWzemOpxDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDETAILDO) {
				req->dpchapp = new PnlWzemOpxDetail::DpchAppDo();
				((PnlWzemOpxDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXDO) {
				req->dpchapp = new CrdWzemOpx::DpchAppDo();
				((CrdWzemOpx::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXLISTDATA) {
				req->dpchapp = new PnlWzemOpxList::DpchAppData();
				((PnlWzemOpxList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXLISTDO) {
				req->dpchapp = new PnlWzemOpxList::DpchAppDo();
				((PnlWzemOpxList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMOPXRECDO) {
				req->dpchapp = new PnlWzemOpxRec::DpchAppDo();
				((PnlWzemOpxRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NEVENTDATA) {
				req->dpchapp = new PnlWzemPrd1NEvent::DpchAppData();
				((PnlWzemPrd1NEvent::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NEVENTDO) {
				req->dpchapp = new PnlWzemPrd1NEvent::DpchAppDo();
				((PnlWzemPrd1NEvent::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NJOBDATA) {
				req->dpchapp = new PnlWzemPrd1NJob::DpchAppData();
				((PnlWzemPrd1NJob::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NJOBDO) {
				req->dpchapp = new PnlWzemPrd1NJob::DpchAppDo();
				((PnlWzemPrd1NJob::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NNODEDATA) {
				req->dpchapp = new PnlWzemPrd1NNode::DpchAppData();
				((PnlWzemPrd1NNode::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRD1NNODEDO) {
				req->dpchapp = new PnlWzemPrd1NNode::DpchAppDo();
				((PnlWzemPrd1NNode::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDDETAILDATA) {
				req->dpchapp = new PnlWzemPrdDetail::DpchAppData();
				((PnlWzemPrdDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDDETAILDO) {
				req->dpchapp = new PnlWzemPrdDetail::DpchAppDo();
				((PnlWzemPrdDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDDO) {
				req->dpchapp = new CrdWzemPrd::DpchAppDo();
				((CrdWzemPrd::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDLISTDATA) {
				req->dpchapp = new PnlWzemPrdList::DpchAppData();
				((PnlWzemPrdList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDLISTDO) {
				req->dpchapp = new PnlWzemPrdList::DpchAppDo();
				((PnlWzemPrdList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRDRECDO) {
				req->dpchapp = new PnlWzemPrdRec::DpchAppDo();
				((PnlWzemPrdRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSADETAILDATA) {
				req->dpchapp = new PnlWzemPrsADetail::DpchAppData();
				((PnlWzemPrsADetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSADETAILDO) {
				req->dpchapp = new PnlWzemPrsADetail::DpchAppDo();
				((PnlWzemPrsADetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDETAILDATA) {
				req->dpchapp = new PnlWzemPrsDetail::DpchAppData();
				((PnlWzemPrsDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDETAILDO) {
				req->dpchapp = new PnlWzemPrsDetail::DpchAppDo();
				((PnlWzemPrsDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSDO) {
				req->dpchapp = new CrdWzemPrs::DpchAppDo();
				((CrdWzemPrs::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSLISTDATA) {
				req->dpchapp = new PnlWzemPrsList::DpchAppData();
				((PnlWzemPrsList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSLISTDO) {
				req->dpchapp = new PnlWzemPrsList::DpchAppDo();
				((PnlWzemPrsList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPRSRECDO) {
				req->dpchapp = new PnlWzemPrsRec::DpchAppDo();
				((PnlWzemPrsRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDETAILDATA) {
				req->dpchapp = new PnlWzemPstDetail::DpchAppData();
				((PnlWzemPstDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDETAILDO) {
				req->dpchapp = new PnlWzemPstDetail::DpchAppDo();
				((PnlWzemPstDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTDO) {
				req->dpchapp = new CrdWzemPst::DpchAppDo();
				((CrdWzemPst::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTLISTDATA) {
				req->dpchapp = new PnlWzemPstList::DpchAppData();
				((PnlWzemPstList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTLISTDO) {
				req->dpchapp = new PnlWzemPstList::DpchAppDo();
				((PnlWzemPstList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMPSTRECDO) {
				req->dpchapp = new PnlWzemPstRec::DpchAppDo();
				((PnlWzemPstRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMRESUME) {
				req->dpchapp = new DpchAppWzemResume();
				((DpchAppWzemResume*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGAACCESSDATA) {
				req->dpchapp = new PnlWzemUsgAAccess::DpchAppData();
				((PnlWzemUsgAAccess::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGAACCESSDO) {
				req->dpchapp = new PnlWzemUsgAAccess::DpchAppDo();
				((PnlWzemUsgAAccess::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGDETAILDATA) {
				req->dpchapp = new PnlWzemUsgDetail::DpchAppData();
				((PnlWzemUsgDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGDETAILDO) {
				req->dpchapp = new PnlWzemUsgDetail::DpchAppDo();
				((PnlWzemUsgDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGDO) {
				req->dpchapp = new CrdWzemUsg::DpchAppDo();
				((CrdWzemUsg::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGLISTDATA) {
				req->dpchapp = new PnlWzemUsgList::DpchAppData();
				((PnlWzemUsgList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGLISTDO) {
				req->dpchapp = new PnlWzemUsgList::DpchAppDo();
				((PnlWzemUsgList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGMNUSERDATA) {
				req->dpchapp = new PnlWzemUsgMNUser::DpchAppData();
				((PnlWzemUsgMNUser::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGMNUSERDO) {
				req->dpchapp = new PnlWzemUsgMNUser::DpchAppDo();
				((PnlWzemUsgMNUser::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSGRECDO) {
				req->dpchapp = new PnlWzemUsgRec::DpchAppDo();
				((PnlWzemUsgRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSR1NSESSIONDATA) {
				req->dpchapp = new PnlWzemUsr1NSession::DpchAppData();
				((PnlWzemUsr1NSession::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSR1NSESSIONDO) {
				req->dpchapp = new PnlWzemUsr1NSession::DpchAppDo();
				((PnlWzemUsr1NSession::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRAACCESSDATA) {
				req->dpchapp = new PnlWzemUsrAAccess::DpchAppData();
				((PnlWzemUsrAAccess::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRAACCESSDO) {
				req->dpchapp = new PnlWzemUsrAAccess::DpchAppDo();
				((PnlWzemUsrAAccess::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDETAILDATA) {
				req->dpchapp = new PnlWzemUsrDetail::DpchAppData();
				((PnlWzemUsrDetail::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDETAILDO) {
				req->dpchapp = new PnlWzemUsrDetail::DpchAppDo();
				((PnlWzemUsrDetail::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRDO) {
				req->dpchapp = new CrdWzemUsr::DpchAppDo();
				((CrdWzemUsr::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRLISTDATA) {
				req->dpchapp = new PnlWzemUsrList::DpchAppData();
				((PnlWzemUsrList::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRLISTDO) {
				req->dpchapp = new PnlWzemUsrList::DpchAppDo();
				((PnlWzemUsrList::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRMNUSERGROUPDATA) {
				req->dpchapp = new PnlWzemUsrMNUsergroup::DpchAppData();
				((PnlWzemUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRMNUSERGROUPDO) {
				req->dpchapp = new PnlWzemUsrMNUsergroup::DpchAppDo();
				((PnlWzemUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			} else if (ixWzemVDpch == VecWzemVDpch::DPCHAPPWZEMUSRRECDO) {
				req->dpchapp = new PnlWzemUsrRec::DpchAppDo();
				((PnlWzemUsrRec::DpchAppDo*) (req->dpchapp))->readJSON(root, true);
			};
		} catch (exception& e) {
		};
	};
		
	return ixWzemVDpch;
};

void WzemcmbdAppsrv::writeDpchEng(
			XchgWzemcmbd* xchg
			, ReqWzem* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	Json::Value root;
	ostringstream str;

	if (!req->jsonNotXml) {
		startwriteBuffer(&wr, &buf);

		if (req->dpcheng) {
			req->dpcheng->writeXML(req->ixWzemVLocale, wr);
		} else {
			DpchEngWzemConfirm dpchconfirm(false, req->jref, "");
			dpchconfirm.writeXML(req->ixWzemVLocale, wr);
		};

		closewriteBuffer(wr);

		req->replylen = buf->use;
		req->reply = new char[req->replylen];
		memcpy(req->reply, buf->content, req->replylen);

		xmlBufferFree(buf);

	} else {
		if (req->dpcheng) {
			req->dpcheng->writeJSON(req->ixWzemVLocale, root);
		} else {
			DpchEngWzemConfirm dpchconfirm(false, req->jref, "");
			dpchconfirm.writeJSON(req->ixWzemVLocale, root);
		};

		str << root;
		// cout << root << endl;

		req->replylen = str.str().length();
		req->reply = new char[req->replylen];
		memcpy(req->reply, str.str().c_str(), req->replylen);
	};
};
