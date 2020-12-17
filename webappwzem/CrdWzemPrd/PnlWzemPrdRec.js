function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWzemPrdRec", "scrJrefDetail");
	scrJref1NJob = retrieveSi(srcdoc, "StatShrWzemPrdRec", "scrJref1NJob");
	scrJref1NNode = retrieveSi(srcdoc, "StatShrWzemPrdRec", "scrJref1NNode");
	scrJref1NEvent = retrieveSi(srcdoc, "StatShrWzemPrdRec", "scrJref1NEvent");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWzemPrdRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWzemPrdRec", "initdone1NJob", "false");
	setSi(srcdoc, "StatAppWzemPrdRec", "initdone1NNode", "false");
	setSi(srcdoc, "StatAppWzemPrdRec", "initdone1NEvent", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NJob = 30;
	height1NNode = 30;
	height1NEvent = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWzemPrdRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdoneDetail") == "true");
	var initdone1NJob = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdone1NJob") == "true");
	var initdone1NNode = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdone1NNode") == "true");
	var initdone1NEvent = (retrieveSi(srcdoc, "StatAppWzemPrdRec", "initdone1NEvent") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWzemPrdDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NJob) {
		rhsdoc.getElementById("1NJob").src = "./PnlWzemPrd1NJob.html?scrJref=" + scrJref1NJob;
	} else if (!initdone1NNode) {
		rhsdoc.getElementById("1NNode").src = "./PnlWzemPrd1NNode.html?scrJref=" + scrJref1NNode;
	} else if (!initdone1NEvent) {
		rhsdoc.getElementById("1NEvent").src = "./PnlWzemPrd1NEvent.html?scrJref=" + scrJref1NEvent;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "1NJob") height1NJob = height;
		else if (short == "1NNode") height1NNode = height;
		else if (short == "1NEvent") height1NEvent = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlWzemPrdRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzemPrdRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlWzemPrdRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzemPrdRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "1NJob") height1NJob = height;
	else if (pnlshort == "1NNode") height1NNode = height;
	else if (pnlshort == "1NEvent") height1NEvent = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NJob+13 + height1NNode+13 + height1NEvent+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzemPrdRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzemPrdRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemPrdRec", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") {
		minimize();
	} else if (srefIxWzemVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWzemPrdRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzemPrdRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzemPrdRec", "TxtRef"));

};

function refresh() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemPrdRec", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxWzemVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzemInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemPrdRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemPrdRecData", "ContInfWzemPrdRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemPrdRecData", "StatAppWzemPrdRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemPrdRecData", "StatShrWzemPrdRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemPrdRecData", "TagWzemPrdRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWzemVExpstate, newSrefIxWzemVExpstate;

	_scrJref = retrieveValue(dom, "//wzem:*/wzem:scrJref");
	srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemPrdRec", "srefIxWzemVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWzemPrdRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemPrdRec", "srefIxWzemVExpstate");

				if (newSrefIxWzemVExpstate != srefIxWzemVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxWzemVExpstate == "mind") {
						minimize();
					} else if (newSrefIxWzemVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxWzemVExpstate != "mind") {
			if (!lhsdoc) return;
			if (!rhsdoc) return;

			if (_scrJref == scrJrefDetail) {
				if (getInitdone("Detail")) lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NJob) {
				if (getInitdone("1NJob")) rhsdoc.getElementById("1NJob").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NNode) {
				if (getInitdone("1NNode")) rhsdoc.getElementById("1NNode").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NEvent) {
				if (getInitdone("1NEvent")) rhsdoc.getElementById("1NEvent").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzemPrdRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxWzemVExpstate, newSrefIxWzemVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzem:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzemConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzemPrdRecData") {
				srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemPrdRec", "srefIxWzemVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemPrdRec", "srefIxWzemVExpstate");

					if (newSrefIxWzemVExpstate != srefIxWzemVExpstate) {
						updateScrJrefs();

						if (newSrefIxWzemVExpstate == "mind") {
							minimize();
						} else if (newSrefIxWzemVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};
