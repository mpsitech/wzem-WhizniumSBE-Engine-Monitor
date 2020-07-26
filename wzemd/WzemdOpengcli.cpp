/**
	* \file WzemdOpengcli.cpp
	* operation engine client for Wzem daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
	*/

#include "Wzemd.h"

#include "WzemdOpengcli.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzemdOpengcli
 ******************************************************************************/

void* WzemdOpengcli::run(
			void* arg
		) {
	XchgWzemd* xchg = (XchgWzemd*) arg;

	NodeWzem* node = NULL;

	pthread_attr_t attr;

	WzemdOpprc_arg* opprc_arg = NULL;

	multimap<ubigint,pthread_t> opprcs;

	string url;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	ubigint nref_backup;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DISABLE, 0);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	xchg->cStable.signal("WzemdOpengcli", "run");

	while (true) {
		xchg->cOpengcli.lockMutex("WzemdOpengcli", "run");
		while (!xchg->termOpengcli && !run_checkNodes(xchg)) xchg->cOpengcli.wait("WzemdOpengcli", "run");

		xchg->rwmNodes.wlock("WzemdOpengcli", "run");

		for (auto it = xchg->nodes.begin(); it != xchg->nodes.end(); it++) {
			node = it->second;
			
			if (xchg->termOpengcli || (node->ixVState == NodeWzem::VecVState::ERROR) || (node->ixVState == NodeWzem::VecVState::TERM)) {
				auto rng = opprcs.equal_range(node->nref);
				for (auto it2 = rng.first; it2 != rng.second; it2++) {
					pthread_cancel(it2->second);
					pthread_join(it2->second, NULL);
				};
				opprcs.erase(rng.first, rng.second);

				if ((node->ixVState == NodeWzem::VecVState::READY) || (node->ixVState == NodeWzem::VecVState::TERM)) {
					// POST content (DpchWzemdQuit)
					Xmlio::startwriteBuffer(&wr, &xbuf);
						DpchWzemdQuit::writeXML(wr);
					Xmlio::closewriteBuffer(wr);

					if (CurlPostDpch("http://" + node->ip + ":" + to_string(node->port) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
						// evaluate reply
						if (rplydpch == "dpchwzemopdack") {
							// acknowledged
						};

					} else {
						// cout << "\terror notifying op engine!" << endl;
					};

					if (docctx) xmlXPathFreeContext(docctx);
					if (doc) xmlFreeDoc(doc);
					xmlBufferFree(xbuf);
				};

				node->ixVState = NodeWzem::VecVState::DONE;

			} else if (node->ixVState == NodeWzem::VecVState::IDLE) {
				for (unsigned int i = 0; i < node->opprcn; i++) {
					opprc_arg = new WzemdOpprc_arg(); // will be deleted by new thread

					opprc_arg->xchg = xchg;
					opprc_arg->node = node;

					auto it2 = opprcs.insert(pair<ubigint,pthread_t>(node->nref, 0));
					pthread_create(&(it2->second), &attr, &WzemdOpprc::run, (void*) opprc_arg);
				};

				node->ixVState = NodeWzem::VecVState::READY;
			};
		};

		for (auto it = xchg->nodes.begin(); it != xchg->nodes.end();) {
			node = it->second;

			if (xchg->termOpengcli || (node->ixVState == NodeWzem::VecVState::DONE)) {
				nref_backup = it->first;

				delete it->second;
				it = xchg->nodes.erase(it);

				xchg->mon.eventRemoveNode(nref_backup);

				xchg->triggerCall(NULL, VecWzemVCall::CALLWZEMNODECHG, xchg->jrefRoot);

			} else it++;
		};

		xchg->rwmNodes.wunlock("WzemdOpengcli", "run");
		xchg->cOpengcli.unlockMutex("WzemdOpengcli", "run");

		if (xchg->termOpengcli) break;
	};

	return NULL;
};

bool WzemdOpengcli::run_checkNodes(
			XchgWzem* xchg
		) {
	bool retval = false;

	NodeWzem* node = NULL;

	xchg->rwmNodes.rlock("WzemdOpengcli", "run_checkNodes");

	for (auto it = xchg->nodes.begin(); it != xchg->nodes.end(); it++) {
		node = it->second;

		if ((node->ixVState == NodeWzem::VecVState::IDLE) || (node->ixVState == NodeWzem::VecVState::ERROR) || (node->ixVState == NodeWzem::VecVState::TERM)) {
			retval = true;
			break;
		};
	};

	xchg->rwmNodes.runlock("WzemdOpengcli", "run_checkNodes");

	return retval;
};

bool WzemdOpengcli::CurlPostDpch(
			const string& url
			, xmlBuffer* xbuf
			, xmlDoc** rplydoc
			, xmlXPathContext** rplydocctx
			, string& rplydpch
		) {
	bool retval = false;

	CURL* curl;
	CURLcode curlres;
	curl_slist* chunk = NULL;

	WzemdOpengcli_curlarg curlarg = {.buf = NULL, .buflen = 0};

	char* buf;
	char* buf_old;
	size_t buflen;

	curl = curl_easy_init();

	if (curl) {
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		chunk = curl_slist_append(chunk, "Content-type: application/x-www-form-urlencoded");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

		curl_easy_setopt(curl, CURLOPT_POST, 1);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
  	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlarg);

		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);

		// string to be sent is "xml=<xbuf>"
		buflen = xbuf->use + 4;
		buf = new char[buflen];

		buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '-';
		memcpy(&(buf[4]), xbuf->content, xbuf->use);

		buf_old = buf;
		buf = curl_easy_escape(curl, buf, buflen);
		delete[] buf_old;

		buf[3] = '=';

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);

		curlres = curl_easy_perform(curl);

		delete[] buf;

		// evaluate result
		if ((curlres == CURLE_OK) && curlarg.buf) {
			// check for root XML node
			Xmlio::parseBuffer(curlarg.buf, curlarg.buflen, rplydoc, rplydocctx);
			rplydpch = StrMod::lc(Xmlio::extractRoot(*rplydoc));

			retval = true;
		};

		if (curlarg.buf) {
			delete[] curlarg.buf;
			curlarg.buf = NULL;

			curlarg.buflen = 0;
		};

		curl_slist_free_all(chunk);

		curl_easy_cleanup(curl);
	};

	return retval;
};

uint WzemdOpengcli::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _arg
		) {
	WzemdOpengcli_curlarg* arg = (WzemdOpengcli_curlarg*) _arg;

	char* olddata;

	if (size > 0) {
		if (!arg->buf) {
			arg->buf = new char[size*blocksize];
			memcpy(arg->buf, data, size*blocksize);
			arg->buflen = size*blocksize;

		} else {
			olddata = arg->buf;

			arg->buf = new char[arg->buflen + size*blocksize];
			memcpy(arg->buf, olddata, arg->buflen);
			memcpy(&(arg->buf[arg->buflen]), data, size*blocksize);
			arg->buflen = arg->buflen + size*blocksize;

			delete[] olddata;
		};
	};

	return(size*blocksize);
};

