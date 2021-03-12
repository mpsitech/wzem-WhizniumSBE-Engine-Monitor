function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWzemJobRec", "scrJrefDetail");
	scrJref1NClstn = retrieveSi(srcdoc, "StatShrWzemJobRec", "scrJref1NClstn");
	scrJref1NPreset = retrieveSi(srcdoc, "StatShrWzemJobRec", "scrJref1NPreset");
	scrJref1NCall = retrieveSi(srcdoc, "StatShrWzemJobRec", "scrJref1NCall");
	scrJref1NOp = retrieveSi(srcdoc, "StatShrWzemJobRec", "scrJref1NOp");
	scrJrefSup1NJob = retrieveSi(srcdoc, "StatShrWzemJobRec", "scrJrefSup1NJob");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWzemJobRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWzemJobRec", "initdone1NClstn", "false");
	setSi(srcdoc, "StatAppWzemJobRec", "initdone1NPreset", "false");
	setSi(srcdoc, "StatAppWzemJobRec", "initdone1NCall", "false");
	setSi(srcdoc, "StatAppWzemJobRec", "initdone1NOp", "false");
	setSi(srcdoc, "StatAppWzemJobRec", "initdoneSup1NJob", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NClstn = 30;
	height1NPreset = 30;
	height1NCall = 30;
	height1NOp = 30;
	heightSup1NJob = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWzemJobRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWzemJobRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdoneDetail") == "true");
	var initdone1NClstn = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdone1NClstn") == "true");
	var initdone1NPreset = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdone1NPreset") == "true");
	var initdone1NCall = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdone1NCall") == "true");
	var initdone1NOp = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdone1NOp") == "true");
	var initdoneSup1NJob = (retrieveSi(srcdoc, "StatAppWzemJobRec", "initdoneSup1NJob") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWzemJobDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NClstn) {
		rhsdoc.getElementById("1NClstn").src = "./PnlWzemJob1NClstn.html?scrJref=" + scrJref1NClstn;
	} else if (!initdone1NPreset) {
		rhsdoc.getElementById("1NPreset").src = "./PnlWzemJob1NPreset.html?scrJref=" + scrJref1NPreset;
	} else if (!initdone1NCall) {
		rhsdoc.getElementById("1NCall").src = "./PnlWzemJob1NCall.html?scrJref=" + scrJref1NCall;
	} else if (!initdone1NOp) {
		rhsdoc.getElementById("1NOp").src = "./PnlWzemJob1NOp.html?scrJref=" + scrJref1NOp;
	} else if (!initdoneSup1NJob) {
		rhsdoc.getElementById("Sup1NJob").src = "./PnlWzemJobSup1NJob.html?scrJref=" + scrJrefSup1NJob;

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
		else if (short == "1NClstn") height1NClstn = height;
		else if (short == "1NPreset") height1NPreset = height;
		else if (short == "1NCall") height1NCall = height;
		else if (short == "1NOp") height1NOp = height;
		else if (short == "Sup1NJob") heightSup1NJob = height;
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

	doc.getElementById("Rec_side").src = "./PnlWzemJobRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzemJobRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlWzemJobRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWzemJobRec_b.html";
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
	else if (pnlshort == "1NClstn") height1NClstn = height;
	else if (pnlshort == "1NPreset") height1NPreset = height;
	else if (pnlshort == "1NCall") height1NCall = height;
	else if (pnlshort == "1NOp") height1NOp = height;
	else if (pnlshort == "Sup1NJob") heightSup1NJob = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NClstn+13 + height1NPreset+13 + height1NCall+13 + height1NOp+13 + heightSup1NJob+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzemJobRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzemJobRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemJobRec", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") {
		minimize();
	} else if (srefIxWzemVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWzemJobRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzemJobRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWzemJobRec", "TxtRef"));

};

function refresh() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemJobRec", "srefIxWzemVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemJobRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemJobRecData", "ContInfWzemJobRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemJobRecData", "StatAppWzemJobRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemJobRecData", "StatShrWzemJobRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemJobRecData", "TagWzemJobRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWzemVExpstate, newSrefIxWzemVExpstate;

	_scrJref = retrieveValue(dom, "//wzem:*/wzem:scrJref");
	srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemJobRec", "srefIxWzemVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWzemJobRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemJobRec", "srefIxWzemVExpstate");

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
			} else if (_scrJref == scrJref1NClstn) {
				if (getInitdone("1NClstn")) rhsdoc.getElementById("1NClstn").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NPreset) {
				if (getInitdone("1NPreset")) rhsdoc.getElementById("1NPreset").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NCall) {
				if (getInitdone("1NCall")) rhsdoc.getElementById("1NCall").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NOp) {
				if (getInitdone("1NOp")) rhsdoc.getElementById("1NOp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NJob) {
				if (getInitdone("Sup1NJob")) rhsdoc.getElementById("Sup1NJob").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWzemJobRecData") {
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

			} else if (blk.nodeName == "DpchEngWzemJobRecData") {
				srefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemJobRec", "srefIxWzemVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWzemVExpstate = retrieveSi(srcdoc, "StatShrWzemJobRec", "srefIxWzemVExpstate");

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
