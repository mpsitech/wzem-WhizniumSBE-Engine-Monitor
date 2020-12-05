// --- view initialization
function getMenAvail(short) {
	return(retrieveSi(srcdoc, "StatShrWzemNavHeadbar", "Men" + short + "Avail") == "true");
};

function getMenCptwidth(short) {
	return(parseInt(retrieveSi(srcdoc, "StgInfWzemNavHeadbar", "Men" + short + "Cptwidth")));
};

function getMenLeft(short) {
	var left = 3;

	if (short == "App") return(left);
	left += getMenCptwidth("App") + 1;

	if (short == "Ses") return(left);
	left += getMenCptwidth("Ses") + 1;

	if (short == "Crd") return(left);
	if (getMenAvail("Crd")) left += getMenCptwidth("Crd") + 1;

	return left;
};

function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var w, wFill;
	wFill = 995;

	w = getMenCptwidth("App"); contdoc.getElementById("colMenApp").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenApp"), "\\u00a0" + retrieveTi(srcdoc, "TagWzemNavHeadbar", "MenApp") + "\\u00a0");
	w = getMenCptwidth("Ses"); contdoc.getElementById("colMenSes").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenSes"), "\\u00a0" + retrieveTi(srcdoc, "TagWzemNavHeadbar", "MenSes") + "\\u00a0");
	w = getMenCptwidth("Crd"); contdoc.getElementById("colMenCrd").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagWzemNavHeadbar", "MenCrd") + "\\u00a0");
	if (!getMenAvail("Crd")) contdoc.getElementById("tdMenCrd").setAttribute("class", "hide");

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
	getCrdwnd().toggleMenu("App", getMenLeft("App"), parseInt(retrieveSi(srcdoc, "StgInfWzemNavHeadbar", "MenAppWidth")), 63);
};

function handleMenSesClick() {
	getCrdwnd().toggleMenu("Ses", getMenLeft("Ses"), parseInt(retrieveSi(srcdoc, "StgInfWzemNavHeadbar", "MenSesWidth")), 103);
};

function handleMenCrdClick() {
	getCrdwnd().toggleMenu("Crd", getMenLeft("Crd"), parseInt(retrieveSi(srcdoc, "StgInfWzemNavHeadbar", "MenCrdWidth")), 223);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemNavHeadbarData", "StatShrWzemNavHeadbar", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemNavHeadbarData", "StgInfWzemNavHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngWzemNavHeadbarData", "TagWzemNavHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzemNavHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};

