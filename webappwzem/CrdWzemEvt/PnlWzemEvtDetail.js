// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzemEvtDetail", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemEvtDetail", "srefIxWzemVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWzemEvtDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemEvtDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemEvtDetail", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemEvtDetail", "srefIxWzemVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWzemEvtDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWzemEvtDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzemEvtDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWzemEvtDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptPrd", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptPrd"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptSta"));
	initCpt(contcontdoc, "CptCal", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptCal"));
	initCpt(contcontdoc, "CptCln", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptCln"));
	initCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptJob"));
	initCpt(contcontdoc, "CptNde", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptNde"));
	initCpt(contcontdoc, "CptOpx", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptOpx"));
	initCpt(contcontdoc, "CptPst", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptPst"));
	initCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptCmd"));
	initCpt(contcontdoc, "CptFnm", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptFnm"));
	initCpt(contcontdoc, "CptFeg", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptFeg"));
	initCpt(contcontdoc, "CptMtd", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptMtd"));
	initCpt(contcontdoc, "CptXsr", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptXsr"));
	initCpt(contcontdoc, "CptDchDch", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptDchDch"));
	initCpt(contcontdoc, "CptDchMsk", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptDchMsk"));
	initCpt(contcontdoc, "CptDchCnt", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptDchCnt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemEvtDetail", "srefIxWzemVExpstate");

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

	var height = 670; // full cont height

	// IP refreshBD.vars --- BEGIN
	var PupTypActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "PupTypActive") == "true");

	var TxtPrdActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtPrdActive") == "true");
	var ButPrdViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButPrdViewAvail") == "true");
	var ButPrdViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButPrdViewActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfStaActive") == "true");

	var LstCluAlt = (retrieveSi(srcdoc, "StatAppWzemEvtDetail", "LstCluAlt") == "true");
	var LstCluActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "LstCluActive") == "true");
	var ButCluViewAvail = !LstCluAlt;
	var ButCluViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButCluViewActive") == "true");
	var ButCluClusterAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButCluClusterAvail") == "true");
	var ButCluUnclusterAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButCluUnclusterAvail") == "true");

	var TxtCalActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtCalActive") == "true");
	var ButCalViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButCalViewAvail") == "true");
	var ButCalViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButCalViewActive") == "true");

	var TxtClnActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtClnActive") == "true");
	var ButClnViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButClnViewAvail") == "true");
	var ButClnViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButClnViewActive") == "true");

	var TxtJobActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtJobActive") == "true");
	var ButJobViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButJobViewAvail") == "true");
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButJobViewActive") == "true");

	var TxtNdeActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtNdeActive") == "true");
	var ButNdeViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButNdeViewAvail") == "true");
	var ButNdeViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButNdeViewActive") == "true");

	var TxtOpxActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtOpxActive") == "true");
	var ButOpxViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButOpxViewAvail") == "true");
	var ButOpxViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButOpxViewActive") == "true");

	var TxtPstActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxtPstActive") == "true");
	var ButPstViewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButPstViewAvail") == "true");
	var ButPstViewActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButPstViewActive") == "true");

	var TxfCmdActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfCmdActive") == "true");

	var TxfFnmActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfFnmActive") == "true");

	var TxfFegActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfFegActive") == "true");

	var TxfMtdActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfMtdActive") == "true");

	var TxfXsrActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfXsrActive") == "true");

	var ButDchNewAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButDchNewAvail") == "true");
	var ButDchDeleteAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButDchDeleteAvail") == "true");

	var TxfDchDchAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfDchDchAvail") == "true");
	var TxfDchDchActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfDchDchActive") == "true");

	var TxfDchMskAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfDchMskAvail") == "true");
	var TxfDchMskActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfDchMskActive") == "true");

	var TxfDchCntAvail = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfDchCntAvail") == "true");
	var TxfDchCntActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "TxfDchCntActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWzemEvtDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtPrd", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtPrd"));

	if (ButPrdViewAvail) refreshButicon(contcontdoc, "ButPrdView", "icon/view", ButPrdViewActive, false);

	refreshTxf(contcontdoc, "TxfSta", "s", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfSta"), TxfStaActive, false, true);

	height -= setCtlAvail(contcontdoc, "Clu2", !LstCluAlt, 71);
	if ( (LstCluAlt == !contcontdoc.getElementById("ButCluExpand")) || (!LstCluAlt == !contcontdoc.getElementById("ButCluCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynClu");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptClu", retrieveTi(srcdoc, "TagWzemEvtDetail", "CptClu")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstCluAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCluExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButCluCollapse", "icon/collapse"));
	};

	if ( (LstCluAlt == !contcontdoc.getElementById("TxtClu")) || (!LstCluAlt == !contcontdoc.getElementById("LstClu")) ) {
		mytd = contcontdoc.getElementById("dynClu");
		clearElem(mytd);

		if (LstCluAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtClu", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstClu", "./PnlWzemEvtDetail_LstClu.xml", false));
		};

	} else {
		if (!LstCluAlt) refreshLst(contcontdoc.getElementById("LstClu").contentWindow.document, srcdoc, 1, false, false, "FeedFLstClu",
					parseInt(retrieveSi(srcdoc, "StatAppWzemEvtDetail", "LstCluNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numFLstClu"))]);
	};

	if (LstCluAlt) refreshTxt(contcontdoc, "TxtClu", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtClu"));

	if ((ButCluViewAvail == !contcontdoc.getElementById("ButCluView")) || (ButCluClusterAvail == !contcontdoc.getElementById("ButCluCluster")) || (ButCluUnclusterAvail == !contcontdoc.getElementById("ButCluUncluster"))) {
		mytd = contcontdoc.getElementById("rdynClu");
		clearElem(mytd);

		first = true;

		if (ButCluViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluView", "icon/view"));
		};

		if (ButCluClusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluCluster", "icon/cluster"));
		};

		if (ButCluUnclusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluUncluster", "icon/uncluster"));
		};
	};

	if (ButCluViewAvail) refreshButicon(contcontdoc, "ButCluView", "icon/view", ButCluViewActive, false);

	if ((ButCalViewAvail == !contcontdoc.getElementById("ButCalView"))) {
		mytd = contcontdoc.getElementById("rdynCal");
		clearElem(mytd);

		first = true;

		if (ButCalViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCalView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCal", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtCal"));

	if (ButCalViewAvail) refreshButicon(contcontdoc, "ButCalView", "icon/view", ButCalViewActive, false);

	if ((ButClnViewAvail == !contcontdoc.getElementById("ButClnView"))) {
		mytd = contcontdoc.getElementById("rdynCln");
		clearElem(mytd);

		first = true;

		if (ButClnViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButClnView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCln", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtCln"));

	if (ButClnViewAvail) refreshButicon(contcontdoc, "ButClnView", "icon/view", ButClnViewActive, false);

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

	refreshTxt(contcontdoc, "TxtJob", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtJob"));

	if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);

	if ((ButNdeViewAvail == !contcontdoc.getElementById("ButNdeView"))) {
		mytd = contcontdoc.getElementById("rdynNde");
		clearElem(mytd);

		first = true;

		if (ButNdeViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButNdeView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtNde", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtNde"));

	if (ButNdeViewAvail) refreshButicon(contcontdoc, "ButNdeView", "icon/view", ButNdeViewActive, false);

	if ((ButOpxViewAvail == !contcontdoc.getElementById("ButOpxView"))) {
		mytd = contcontdoc.getElementById("rdynOpx");
		clearElem(mytd);

		first = true;

		if (ButOpxViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOpxView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtOpx", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtOpx"));

	if (ButOpxViewAvail) refreshButicon(contcontdoc, "ButOpxView", "icon/view", ButOpxViewActive, false);

	if ((ButPstViewAvail == !contcontdoc.getElementById("ButPstView"))) {
		mytd = contcontdoc.getElementById("rdynPst");
		clearElem(mytd);

		first = true;

		if (ButPstViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPst", retrieveCi(srcdoc, "ContInfWzemEvtDetail", "TxtPst"));

	if (ButPstViewAvail) refreshButicon(contcontdoc, "ButPstView", "icon/view", ButPstViewActive, false);

	refreshTxf(contcontdoc, "TxfCmd", "", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfCmd"), TxfCmdActive, false, true);

	refreshTxft(contcontdoc, "TxfFnm", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfFnm"), TxfFnmActive, false, true);

	refreshTxf(contcontdoc, "TxfFeg", "", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfFeg"), TxfFegActive, false, true);

	refreshTxf(contcontdoc, "TxfMtd", "", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfMtd"), TxfMtdActive, false, true);

	refreshTxf(contcontdoc, "TxfXsr", "", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfXsr"), TxfXsrActive, false, true);

	if ((ButDchNewAvail == !contcontdoc.getElementById("ButDchNew")) || (ButDchDeleteAvail == !contcontdoc.getElementById("ButDchDelete"))) {
		mytd = contcontdoc.getElementById("dynDch");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgDch", retrieveTi(srcdoc, "TagWzemEvtDetail", "HdgDch")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButDchNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDchNew", "icon/new"));
		};

		if (ButDchDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDchDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "DchDch", TxfDchDchAvail, 25);
	if (TxfDchDchAvail) {
		refreshTxf(contcontdoc, "TxfDchDch", "", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfDchDch"), TxfDchDchActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "DchMsk", TxfDchMskAvail, 25);
	if (TxfDchMskAvail) {
		refreshTxf(contcontdoc, "TxfDchMsk", "", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfDchMsk"), TxfDchMskActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "DchCnt", TxfDchCntAvail, 75);
	if (TxfDchCntAvail) {
		refreshTxft(contcontdoc, "TxfDchCnt", retrieveCi(srcdoc, "ContIacWzemEvtDetail", "TxfDchCnt"), TxfDchCntActive, false, true);

	};

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
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemEvtDetail", "srefIxWzemVExpstate");

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
	setSi(srcdoc, "StatAppWzemEvtDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzemEvtDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemEvtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemEvtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzemEvtDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzemEvtDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWzemEvtDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzemEvtDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemEvtDetailData", scrJref, "ContIacWzemEvtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzemEvtDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzemEvtDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzemEvtDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzemEvtDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemEvtDetailData", scrJref, "ContIacWzemEvtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWzemEvtDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzemEvtDetailData", scrJref, "ContIacWzemEvtDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWzemEvtDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemEvtDetailData", scrJref, "ContIacWzemEvtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWzemEvtDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemEvtDetailData", scrJref, "ContIacWzemEvtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "ContIacWzemEvtDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "ContInfWzemEvtDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "FeedFLstClu", srcdoc)) mask.push("feedFLstClu");
	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "StatAppWzemEvtDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "StatShrWzemEvtDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemEvtDetailData", "TagWzemEvtDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemEvtDetailData") {
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
			if (blk.nodeName == "DpchEngWzemEvtDetailData") {
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

			} else if (blk.nodeName == "DpchEngWzemEvtDetailData") {
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

