/**
  * \file PnlWzemNdeDetail.js
  * web client functionality for panel PnlWzemNdeDetail
  * \author Catherine Johnson
  * \date created: 21 Sep 2020
  * \date modified: 21 Sep 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzemNdeDetail", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemNdeDetail", "srefIxWzemVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzemNdeDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemNdeDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemNdeDetail", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemNdeDetail", "srefIxWzemVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzemNdeDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemNdeDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzemNdeDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrd", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptPrd"));
	initCpt(contcontdoc, "CptXnr", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptXnr"));
	initCpt(contcontdoc, "CptIp", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptIp"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptSto"));
	initCpt(contcontdoc, "CptPrt", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptPrt"));
	initCpt(contcontdoc, "CptOrn", retrieveTi(srcdoc, "TagWzemNdeDetail", "CptOrn"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemNdeDetail", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") {
		initA();
	} else if (srefIxWzemVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWzemVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 192; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrdActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxtPrdActive") == "true");
	var ButPrdViewAvail = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "ButPrdViewAvail") == "true");
	var ButPrdViewActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "ButPrdViewActive") == "true");

	var TxfXnrActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxfXnrActive") == "true");

	var TxfIpActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxfIpActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxfStoActive") == "true");

	var TxfPrtActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxfPrtActive") == "true");

	var TxfOrnActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "TxfOrnActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzemNdeDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButPrdViewAvail == !contcontdoc.getElementById("ButPrdView"))) {
		mytd = contcontdoc.getElementById("rdynPrd");
		clearElem(mytd);

		first = true;

		if (ButPrdViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrdView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrd", retrieveCi(srcdoc, "ContInfWzemNdeDetail", "TxtPrd"));

	if (ButPrdViewAvail) refreshButicon(contcontdoc, "ButPrdView", "icon/view", ButPrdViewActive, false);

	refreshTxf(contcontdoc, "TxfXnr", "s", retrieveCi(srcdoc, "ContIacWzemNdeDetail", "TxfXnr"), TxfXnrActive, false, true);

	refreshTxf(contcontdoc, "TxfIp", "s", retrieveCi(srcdoc, "ContIacWzemNdeDetail", "TxfIp"), TxfIpActive, false, true);

	refreshTxf(contcontdoc, "TxfSta", "s", retrieveCi(srcdoc, "ContIacWzemNdeDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "s", retrieveCi(srcdoc, "ContIacWzemNdeDetail", "TxfSto"), TxfStoActive, false, true);

	refreshTxf(contcontdoc, "TxfPrt", "s", retrieveCi(srcdoc, "ContIacWzemNdeDetail", "TxfPrt"), TxfPrtActive, false, true);

	refreshTxf(contcontdoc, "TxfOrn", "s", retrieveCi(srcdoc, "ContIacWzemNdeDetail", "TxfOrn"), TxfOrnActive, false, true);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemNdeDetail", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") {
		refreshA();
	} else if (srefIxWzemVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWzemVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzemInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNdeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNdeDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzemNdeDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzemNdeDetailData", scrJref, "ContIacWzemNdeDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzemNdeDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemNdeDetailData", scrJref, "ContIacWzemNdeDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemNdeDetailData", "ContIacWzemNdeDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzemNdeDetailData", "ContInfWzemNdeDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemNdeDetailData", "StatAppWzemNdeDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemNdeDetailData", "StatShrWzemNdeDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemNdeDetailData", "TagWzemNdeDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemNdeDetailData") {
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
			if (blk.nodeName == "DpchEngWzemNdeDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzem:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzemConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzemNdeDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzemConfirm") {
				accepted = retrieveValue(dom, "//wzem:DpchEngWzemConfirm/wzem:accepted");
				_scrJref = retrieveValue(dom, "//wzem:DpchEngWzemConfirm/wzem:scrJref");
				sref = retrieveValue(dom, "//wzem:DpchEngWzemConfirm/wzem:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWzemAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wzem:DpchEngWzemAlert/wzem:scrJref"),
						retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:ContInfWzemAlert"),
						retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:FeedFMcbAlert"));
			};
		};
	};
};

