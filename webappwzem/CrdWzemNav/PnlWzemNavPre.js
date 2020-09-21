/**
  * \file PnlWzemNavPre.js
  * web client functionality for panel PnlWzemNavPre
  * \author Catherine Johnson
  * \date created: 21 Sep 2020
  * \date modified: 21 Sep 2020
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtPrdAvail = (retrieveSi(srcdoc, "StatShrWzemNavPre", "TxtPrdAvail") == "true"); if (TxtPrdAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtPrdAvail) {
		i++;

		line.appendChild(makeImgBut("ButPrdRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWzemNavPre", "CptPrd") + ": " + retrieveCi(srcdoc, "ContInfWzemNavPre", "TxtPrd")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWzemNavPre", "CptPrd") + ": " + retrieveCi(srcdoc, "ContInfWzemNavPre", "TxtPrd") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzemInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemNavPreData", "ContInfWzemNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemNavPreData", "StatShrWzemNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemNavPreData", "TagWzemNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemNavPreData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzemNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzem:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzemConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzemNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

