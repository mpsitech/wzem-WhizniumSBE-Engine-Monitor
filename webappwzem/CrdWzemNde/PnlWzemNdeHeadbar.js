/**
  * \file PnlWzemNdeHeadbar.js
  * web client functionality for panel PnlWzemNdeHeadbar
  * \author Catherine Johnson
  * \date created: 21 Sep 2020
  * \date modified: 21 Sep 2020
  */

// --- view initialization
function getMenAvail(short) {
	return(retrieveSi(srcdoc, "StatShrWzemNdeHeadbar", "Men" + short + "Avail") == "true");
};

function getMenCptwidth(short) {
	return(parseInt(retrieveSi(srcdoc, "StgInfWzemNdeHeadbar", "Men" + short + "Cptwidth")));
};

function getMenLeft(short) {
	var left = 3;

	if (short == "App") return(left);
	left += getMenCptwidth("App") + 1;

	if (short == "Crd") return(left);
	left += getMenCptwidth("Crd") + 1;

	return left;
};

function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var w, wFill;
	wFill = 995;

	w = getMenCptwidth("App"); contdoc.getElementById("colMenApp").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenApp"), "\\u00a0" + retrieveTi(srcdoc, "TagWzemNdeHeadbar", "MenApp") + "\\u00a0");
	w = getMenCptwidth("Crd"); contdoc.getElementById("colMenCrd").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagWzemNdeHeadbar", "MenCrd") + "\\u00a0");

	contdoc.getElementById("colFill").setAttribute("width", "" + wFill);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Headbar_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzemInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleMenAppClick() {
	getCrdwnd().toggleMenu("App", getMenLeft("App"), parseInt(retrieveSi(srcdoc, "StgInfWzemNdeHeadbar", "MenAppWidth")), 42);
};

function handleMenCrdClick() {
	getCrdwnd().toggleMenu("Crd", getMenLeft("Crd"), parseInt(retrieveSi(srcdoc, "StgInfWzemNdeHeadbar", "MenCrdWidth")), 22);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemNdeHeadbarData", "StgInfWzemNdeHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngWzemNdeHeadbarData", "TagWzemNdeHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzemNdeHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};

