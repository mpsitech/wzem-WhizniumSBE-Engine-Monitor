/**
  * \file PnlWzemClnDetail.js
  * web client functionality for panel PnlWzemClnDetail
  * \author Catherine Johnson
  * \date created: 21 Sep 2020
  * \date modified: 21 Sep 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzemClnDetail", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemClnDetail", "srefIxWzemVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzemClnDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemClnDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemClnDetail", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemClnDetail", "srefIxWzemVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzemClnDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemClnDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzemClnDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWzemClnDetail", "CptJob"));
	initCpt(contcontdoc, "CptCal", retrieveTi(srcdoc, "TagWzemClnDetail", "CptCal"));
	initCpt(contcontdoc, "CptSge", retrieveTi(srcdoc, "TagWzemClnDetail", "CptSge"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagWzemClnDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagWzemClnDetail", "CptSto"));
	initCpt(contcontdoc, "CptTrg", retrieveTi(srcdoc, "TagWzemClnDetail", "CptTrg"));
	refreshPup(contcontdoc, srcdoc, "PupTrg", "", "FeedFPupTrg", retrieveCi(srcdoc, "ContIacWzemClnDetail", "numFPupTrg"), retrieveSi(srcdoc, "StatShrWzemClnDetail", "PupTrgActive"), false);
	initCpt(contcontdoc, "CptJms", retrieveTi(srcdoc, "TagWzemClnDetail", "CptJms"));
	refreshPup(contcontdoc, srcdoc, "PupJms", "", "FeedFPupJms", retrieveCi(srcdoc, "ContIacWzemClnDetail", "numFPupJms"), retrieveSi(srcdoc, "StatShrWzemClnDetail", "PupJmsActive"), false);
	initCpt(contcontdoc, "CptTjb", retrieveTi(srcdoc, "TagWzemClnDetail", "CptTjb"));
	initCpt(contcontdoc, "CptArg", retrieveTi(srcdoc, "TagWzemClnDetail", "CptArg"));
	initCpt(contcontdoc, "CptJat", retrieveTi(srcdoc, "TagWzemClnDetail", "CptJat"));
	refreshPup(contcontdoc, srcdoc, "PupJat", "", "FeedFPupJat", retrieveCi(srcdoc, "ContIacWzemClnDetail", "numFPupJat"), retrieveSi(srcdoc, "StatShrWzemClnDetail", "PupJatActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemClnDetail", "srefIxWzemVExpstate");

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

	var height = 363; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "ButJobViewActive") == "true");

	var TxfCalActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxfCalActive") == "true");

	var TxfSgeActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxfSgeActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxfStoActive") == "true");

	var PupTrgActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "PupTrgActive") == "true");

	var PupJmsActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "PupJmsActive") == "true");

	var TxtTjbActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxtTjbActive") == "true");
	var ButTjbViewAvail = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "ButTjbViewAvail") == "true");
	var ButTjbViewActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "ButTjbViewActive") == "true");

	var LstAmsAlt = (retrieveSi(srcdoc, "StatAppWzemClnDetail", "LstAmsAlt") == "true");
	var LstAmsActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "LstAmsActive") == "true");

	var TxfArgActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "TxfArgActive") == "true");

	var PupJatActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "PupJatActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzemClnDetail", "ButSaveActive") == "true");
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

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWzemClnDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	refreshTxf(contcontdoc, "TxfCal", "", retrieveCi(srcdoc, "ContIacWzemClnDetail", "TxfCal"), TxfCalActive, false, true);

	refreshTxf(contcontdoc, "TxfSge", "", retrieveCi(srcdoc, "ContIacWzemClnDetail", "TxfSge"), TxfSgeActive, false, true);

	refreshTxf(contcontdoc, "TxfSta", "s", retrieveCi(srcdoc, "ContIacWzemClnDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "s", retrieveCi(srcdoc, "ContIacWzemClnDetail", "TxfSto"), TxfStoActive, false, true);

	contcontdoc.getElementById("PupTrg").value = retrieveCi(srcdoc, "ContIacWzemClnDetail", "numFPupTrg");

	contcontdoc.getElementById("PupJms").value = retrieveCi(srcdoc, "ContIacWzemClnDetail", "numFPupJms");

	if ((ButTjbViewAvail == !contcontdoc.getElementById("ButTjbView"))) {
		mytd = contcontdoc.getElementById("rdynTjb");
		clearElem(mytd);

		first = true;

		if (ButTjbViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTjbView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTjb", retrieveCi(srcdoc, "ContInfWzemClnDetail", "TxtTjb"));

	if (ButTjbViewAvail) refreshButicon(contcontdoc, "ButTjbView", "icon/view", ButTjbViewActive, false);

	height -= setCtlAvail(contcontdoc, "Ams2", !LstAmsAlt, 71);
	if ( (LstAmsAlt == !contcontdoc.getElementById("ButAmsExpand")) || (!LstAmsAlt == !contcontdoc.getElementById("ButAmsCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynAms");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptAms", retrieveTi(srcdoc, "TagWzemClnDetail", "CptAms")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstAmsAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButAmsExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButAmsCollapse", "icon/collapse"));
	};

	if ( (LstAmsAlt == !contcontdoc.getElementById("TxtAms")) || (!LstAmsAlt == !contcontdoc.getElementById("LstAms")) ) {
		mytd = contcontdoc.getElementById("dynAms");
		clearElem(mytd);

		if (LstAmsAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtAms", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstAms", "./PnlWzemClnDetail_LstAms.xml", false));
		};

	} else {
		if (!LstAmsAlt) refreshLst(contcontdoc.getElementById("LstAms").contentWindow.document, srcdoc, 1, false, true, "FeedFLstAms",
					parseInt(retrieveSi(srcdoc, "StatAppWzemClnDetail", "LstAmsNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numsFLstAms")));
	};

	if (LstAmsAlt) refreshTxt(contcontdoc, "TxtAms", retrieveCi(srcdoc, "ContInfWzemClnDetail", "TxtAms"));

	refreshTxf(contcontdoc, "TxfArg", "", retrieveCi(srcdoc, "ContIacWzemClnDetail", "TxfArg"), TxfArgActive, false, true);

	contcontdoc.getElementById("PupJat").value = retrieveCi(srcdoc, "ContIacWzemClnDetail", "numFPupJat");

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
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemClnDetail", "srefIxWzemVExpstate");

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

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWzemClnDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzemClnDetail", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemClnDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemClnDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzemClnDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzemClnDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numsF" + ctlsref));

		found = false;

		for (var i = 0; i < oldNumsFLst.length; i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j = 0; j < oldNumsFLst.length; j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacWzemClnDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzemClnDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemClnDetailData", scrJref, "ContIacWzemClnDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzemClnDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzemClnDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzemClnDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzemClnDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemClnDetailData", scrJref, "ContIacWzemClnDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzemClnDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzemClnDetailData", scrJref, "ContIacWzemClnDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzemClnDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemClnDetailData", scrJref, "ContIacWzemClnDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "ContIacWzemClnDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "ContInfWzemClnDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "FeedFLstAms", srcdoc)) mask.push("feedFLstAms");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "FeedFPupJat", srcdoc)) mask.push("feedFPupJat");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "FeedFPupJms", srcdoc)) mask.push("feedFPupJms");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "FeedFPupTrg", srcdoc)) mask.push("feedFPupTrg");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "StatAppWzemClnDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "StatShrWzemClnDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemClnDetailData", "TagWzemClnDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemClnDetailData") {
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
			if (blk.nodeName == "DpchEngWzemClnDetailData") {
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

			} else if (blk.nodeName == "DpchEngWzemClnDetailData") {
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

