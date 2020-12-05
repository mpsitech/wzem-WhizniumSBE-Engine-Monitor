// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzemJobDetail", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemJobDetail", "srefIxWzemVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzemJobDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemJobDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemJobDetail", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemJobDetail", "srefIxWzemVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzemJobDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemJobDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzemJobDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrd", retrieveTi(srcdoc, "TagWzemJobDetail", "CptPrd"));
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWzemJobDetail", "CptJob"));
	initCpt(contcontdoc, "CptXjr", retrieveTi(srcdoc, "TagWzemJobDetail", "CptXjr"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagWzemJobDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagWzemJobDetail", "CptSto"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWzemJobDetail", "CptSup"));
	initCpt(contcontdoc, "CptCls", retrieveTi(srcdoc, "TagWzemJobDetail", "CptCls"));
	initCpt(contcontdoc, "CptSnc", retrieveTi(srcdoc, "TagWzemJobDetail", "CptSnc"));
	initCpt(contcontdoc, "CptDcl", retrieveTi(srcdoc, "TagWzemJobDetail", "CptDcl"));
	initCpt(contcontdoc, "CptStm", retrieveTi(srcdoc, "TagWzemJobDetail", "CptStm"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemJobDetail", "srefIxWzemVExpstate");

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

	var height = 267; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrdActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "TxtPrdActive") == "true");
	var ButPrdViewAvail = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ButPrdViewAvail") == "true");
	var ButPrdViewActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ButPrdViewActive") == "true");

	var TxfJobActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "TxfJobActive") == "true");

	var TxfXjrActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "TxfXjrActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "TxfStoActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ButSupViewActive") == "true");

	var ChkClsActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ChkClsActive") == "true");

	var ChkSncActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ChkSncActive") == "true");

	var ChkDclActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ChkDclActive") == "true");

	var ChkStmActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ChkStmActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzemJobDetail", "ButSaveActive") == "true");
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

	refreshTxt(contcontdoc, "TxtPrd", retrieveCi(srcdoc, "ContInfWzemJobDetail", "TxtPrd"));

	if (ButPrdViewAvail) refreshButicon(contcontdoc, "ButPrdView", "icon/view", ButPrdViewActive, false);

	refreshTxf(contcontdoc, "TxfJob", "", retrieveCi(srcdoc, "ContIacWzemJobDetail", "TxfJob"), TxfJobActive, false, true);

	refreshTxf(contcontdoc, "TxfXjr", "s", retrieveCi(srcdoc, "ContIacWzemJobDetail", "TxfXjr"), TxfXjrActive, false, true);

	refreshTxf(contcontdoc, "TxfSta", "s", retrieveCi(srcdoc, "ContIacWzemJobDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "s", retrieveCi(srcdoc, "ContIacWzemJobDetail", "TxfSto"), TxfStoActive, false, true);

	if ((ButSupViewAvail == !contcontdoc.getElementById("ButSupView"))) {
		mytd = contcontdoc.getElementById("rdynSup");
		clearElem(mytd);

		first = true;

		if (ButSupViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSupView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWzemJobDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

	refreshChk(contcontdoc, "ChkCls", (retrieveCi(srcdoc, "ContIacWzemJobDetail", "ChkCls") == "true"), ChkClsActive);

	refreshChk(contcontdoc, "ChkSnc", (retrieveCi(srcdoc, "ContIacWzemJobDetail", "ChkSnc") == "true"), ChkSncActive);

	refreshChk(contcontdoc, "ChkDcl", (retrieveCi(srcdoc, "ContIacWzemJobDetail", "ChkDcl") == "true"), ChkDclActive);

	refreshChk(contcontdoc, "ChkStm", (retrieveCi(srcdoc, "ContIacWzemJobDetail", "ChkStm") == "true"), ChkStmActive);

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
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemJobDetail", "srefIxWzemVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemJobDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemJobDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWzemJobDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemJobDetailData", scrJref, "ContIacWzemJobDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzemJobDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzemJobDetailData", scrJref, "ContIacWzemJobDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzemJobDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemJobDetailData", scrJref, "ContIacWzemJobDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemJobDetailData", "ContIacWzemJobDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzemJobDetailData", "ContInfWzemJobDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemJobDetailData", "StatAppWzemJobDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemJobDetailData", "StatShrWzemJobDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemJobDetailData", "TagWzemJobDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemJobDetailData") {
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
			if (blk.nodeName == "DpchEngWzemJobDetailData") {
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

			} else if (blk.nodeName == "DpchEngWzemJobDetailData") {
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

