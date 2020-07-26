/**
  * \file PnlWzemCalDetail.js
  * web client functionality for panel PnlWzemCalDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Jun 2020
  * \date modified: 4 Jun 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzemCalDetail", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemCalDetail", "srefIxWzemVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzemCalDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemCalDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemCalDetail", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemCalDetail", "srefIxWzemVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzemCalDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemCalDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzemCalDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWzemCalDetail", "CptJob"));
	initCpt(contcontdoc, "CptCal", retrieveTi(srcdoc, "TagWzemCalDetail", "CptCal"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagWzemCalDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagWzemCalDetail", "CptSto"));
	initCpt(contcontdoc, "CptInv", retrieveTi(srcdoc, "TagWzemCalDetail", "CptInv"));
	initCpt(contcontdoc, "CptRet", retrieveTi(srcdoc, "TagWzemCalDetail", "CptRet"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemCalDetail", "srefIxWzemVExpstate");

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

	var height = 167; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "ButJobViewActive") == "true");

	var TxfCalActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "TxfCalActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "TxfStoActive") == "true");

	var TxfInvActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "TxfInvActive") == "true");

	var TxfRetActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "TxfRetActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzemCalDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButJobViewAvail == !contcontdoc.getElementById("ButJobView"))) {
		mytd = contcontdoc.getElementById("rdynJob");
		clearElem(mytd);

		first = true;

		if (ButJobViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJobView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWzemCalDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	refreshTxf(contcontdoc, "TxfCal", "", retrieveCi(srcdoc, "ContIacWzemCalDetail", "TxfCal"), TxfCalActive, false, true);

	refreshTxf(contcontdoc, "TxfSta", "s", retrieveCi(srcdoc, "ContIacWzemCalDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "s", retrieveCi(srcdoc, "ContIacWzemCalDetail", "TxfSto"), TxfStoActive, false, true);

	refreshTxf(contcontdoc, "TxfInv", "", retrieveCi(srcdoc, "ContIacWzemCalDetail", "TxfInv"), TxfInvActive, false, true);

	refreshTxf(contcontdoc, "TxfRet", "", retrieveCi(srcdoc, "ContIacWzemCalDetail", "TxfRet"), TxfRetActive, false, true);

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
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemCalDetail", "srefIxWzemVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemCalDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemCalDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzemCalDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzemCalDetailData", scrJref, "ContIacWzemCalDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzemCalDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemCalDetailData", scrJref, "ContIacWzemCalDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemCalDetailData", "ContIacWzemCalDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzemCalDetailData", "ContInfWzemCalDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemCalDetailData", "StatAppWzemCalDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemCalDetailData", "StatShrWzemCalDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemCalDetailData", "TagWzemCalDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemCalDetailData") {
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
			if (blk.nodeName == "DpchEngWzemCalDetailData") {
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

			} else if (blk.nodeName == "DpchEngWzemCalDetailData") {
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

