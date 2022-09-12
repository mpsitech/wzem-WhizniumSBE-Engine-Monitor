function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWzemNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWzemNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppWzemNav", "initdoneHeadbar") == "true");
	var initdonePre = (retrieveSi(srcdoc, "StatAppWzemNav", "initdonePre") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppWzemNav", "initdoneAdmin") == "true");
	var initdoneMon = (retrieveSi(srcdoc, "StatAppWzemNav", "initdoneMon") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlWzemNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdonePre) {
		doc.getElementById("Pre").src = "./PnlWzemNavPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlWzemNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneMon) {
		doc.getElementById("Mon").src = "./PnlWzemNavMon.html?scrJref=" + scrJrefMon;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	if (doc.getElementById("trPre").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdPre").getAttribute("height"));
	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trMon").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdMon").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppWzemNav", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWzemNav", "shortMenu", short);
	setSi(srcdoc, "StatAppWzemNav", "widthMenu", "" + (width-3));

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWzemNav", "shortMenu", "");

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspApp2Avail = (retrieveSi(srcdoc, "StatShrWzemNav", "MspApp2Avail") == "true");
	MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWzemNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagWzemNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagWzemNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagWzemNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MitSesSpsAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitSesSpsAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWzemNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfWzemNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfWzemNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfWzemNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesSps"), retrieveTi(srcdoc, "TagWzemNav", "MitSesSps"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagWzemNav", "MitSesTrm"));

	height -= setMitMspAvail("MitSesSps", MitSesSpsAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrWzemNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdUsrAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdPrsAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrWzemNav", "MspCrd2Avail") == "true");
	MitCrdPrdAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdPrdAvail") == "true");
	MitCrdEvtAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdEvtAvail") == "true");
	MitCrdEvtActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdEvtActive") == "true");
	MitCrdJobAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdJobAvail") == "true");
	MitCrdJobActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdJobActive") == "true");
	MitCrdCalAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdCalAvail") == "true");
	MitCrdCalActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdCalActive") == "true");
	MitCrdClnAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdClnAvail") == "true");
	MitCrdClnActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdClnActive") == "true");
	MitCrdOpxAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdOpxAvail") == "true");
	MitCrdOpxActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdOpxActive") == "true");
	MitCrdPstAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdPstAvail") == "true");
	MitCrdPstActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdPstActive") == "true");
	MitCrdNdeAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdNdeAvail") == "true");
	MitCrdNdeActive = (retrieveSi(srcdoc, "StatShrWzemNav", "MitCrdNdeActive") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWzemNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrd"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdPrd"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdEvt"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdEvt"));
	setMitActive("MitCrdEvt", MitCrdEvtActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdJob"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdJob"));
	setMitActive("MitCrdJob", MitCrdJobActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCal"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdCal"));
	setMitActive("MitCrdCal", MitCrdCalActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCln"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdCln"));
	setMitActive("MitCrdCln", MitCrdClnActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdOpx"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdOpx"));
	setMitActive("MitCrdOpx", MitCrdOpxActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdPst"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdPst"));
	setMitActive("MitCrdPst", MitCrdPstActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdNde"), retrieveTi(srcdoc, "TagWzemNav", "MitCrdNde"));
	setMitActive("MitCrdNde", MitCrdNdeActive);

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdPrd", MitCrdPrdAvail, 20);
	height -= setMitMspAvail("MitCrdEvt", MitCrdEvtAvail, 20);
	height -= setMitMspAvail("MitCrdJob", MitCrdJobAvail, 20);
	height -= setMitMspAvail("MitCrdCal", MitCrdCalAvail, 20);
	height -= setMitMspAvail("MitCrdCln", MitCrdClnAvail, 20);
	height -= setMitMspAvail("MitCrdOpx", MitCrdOpxAvail, 20);
	height -= setMitMspAvail("MitCrdPst", MitCrdPstAvail, 20);
	height -= setMitMspAvail("MitCrdNde", MitCrdNdeAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- detached panel functionality
function detachPnl(sref, _scrJref) {
	if ((scrJrefPnld != "") && (scrJrefPnld != _scrJref)) attachPnl();

	scrJrefPnld = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divPnldshld");
	mydiv.setAttribute("class", "pnldshld");
	mydiv.setAttribute("style", "height:" + (getHeight()-35) + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "pnld");
	mydiv.setAttribute("id", "divPnld");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Pnld");
	myif.setAttribute("src", "./" + sref + "_d.html?scrJref=" + _scrJref);
	myif.setAttribute("width", "891"); /// PRELIMINARY
	myif.setAttribute("height", "586");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function maximizePnl() {
	/// TBD
};

function attachPnl() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divPnldshld"));
	body.removeChild(doc.getElementById("divPnld"));

	scrJrefPnld = "";
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divDlgshld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgWzemNavLoaini")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divDlgshld"));
	body.removeChild(doc.getElementById("divDlg"));

	scrJrefDlg = "";
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfWzemAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divAlrshld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divAlrshld"));
	body.removeChild(doc.getElementById("divAlr"));

	scrJrefAlr = "";
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfWzemAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfWzemAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divPnldshld = doc.getElementById("divPnldshld");
	var divDlgshld = doc.getElementById("divDlgshld");
	var divAlrshld = doc.getElementById("divAlrshld");

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Mon") {
		doc.getElementById("tdMon").setAttribute("height", "" + height);
		doc.getElementById("Mon").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrWzemNav", "scrJrefDlgloaini");
	var pnlpreAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "pnlpreAvail") == "true");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "pnladminAvail") == "true");
	var pnlmonAvail = (retrieveSi(srcdoc, "StatShrWzemNav", "pnlmonAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgWzemNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Pre", pnlpreAvail);
	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Mon", pnlmonAvail);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzemInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNavDo", scrJref, "close");
	sendReq(str, doc, null, true);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfWzemNav", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemNavData", "ContInfWzemNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngWzemNavData", "StatAppWzemNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemNavData", "StatShrWzemNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemNavData", "TagWzemNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEngSub(_scrJref, dom, dpch) {
	if (_scrJref == scrJrefPnld) {
		doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefDlg) {
		doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefPre) {
		doc.getElementById("Pre").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefAdmin) {
		doc.getElementById("Admin").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefMon) {
		doc.getElementById("Mon").contentWindow.handleDpchEng(dom, dpch);

	} else {
		// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzemNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrWzemNav", "scrJrefHeadbar");
				scrJrefPre = retrieveSi(srcdoc, "StatShrWzemNav", "scrJrefPre");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrWzemNav", "scrJrefAdmin");
				scrJrefMon = retrieveSi(srcdoc, "StatShrWzemNav", "scrJrefMon");

				scrJrefPnld = "";

				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var _scrJref;

	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzem:*");

		if (blk) {
			_scrJref = retrieveValue(dom, "//wzem:*/wzem:scrJref");

			if (_scrJref != "") {
				if (_scrJref == scrJref) {
					if (blk.nodeName == "DpchEngWzemConfirm") {
						// do nothing

					} else if (blk.nodeName == "DpchEngWzemAlert") {
						// show alert with new content
						showAlr(retrieveValue(dom, "//wzem:DpchEngWzemAlert/wzem:scrJref"),
								retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:ContInfWzemAlert"),
								retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:FeedFMcbAlert"));

					} else if (blk.nodeName == "DpchEngWzemNavData") {
						mergeDpchEngData(dom);
						refresh();
					};

				} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
			};

			restartNotify();
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
				showAlr(retrieveValue(dom, "//wzem:DpchEngWzemAlert/wzem:scrJref"),
						retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:ContInfWzemAlert"),
						retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("../CrdWzemStart/CrdWzemStart.html?do=Logout", "_self");
};

function restartNotify() {
	var srefIxWzemVReqitmode = retrieveSi(srcdoc, "StatAppWzemNav", "srefIxWzemVReqitmode");

	if (srefIxWzemVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxWzemVReqitmode = "notify";
		setSi(srcdoc, "StatAppWzemNav", "srefIxWzemVReqitmode", srefIxWzemVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxWzemVReqitmode = retrieveSi(srcdoc, "StatAppWzemNav", "srefIxWzemVReqitmode");

	if (srefIxWzemVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppWzemResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");

		if (blk) if (blk.nodeName == "DpchEngWzemAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxWzemVReqitmode = retrieveSi(srcdoc, "StatAppWzemNav", "srefIxWzemVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppWzemNav", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//wzem:*");

			if (blk) {
				if (blk.nodeName == "DpchEngWzemAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngWzemSuspend") {
					// change to "poll" mode
					news = true;

					srefIxWzemVReqitmode = "poll";
					setSi(srcdoc, "StatAppWzemNav", "srefIxWzemVReqitmode", srefIxWzemVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//wzem:*/wzem:scrJref");

					if (blk.nodeName == "DpchEngWzemAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//wzem:DpchEngWzemAlert/wzem:scrJref"),
								retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:ContInfWzemAlert"),
								retrieveBlock(dom, "//wzem:DpchEngWzemAlert/wzem:FeedFMcbAlert"));

					} else if (_scrJref != "") {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngWzemConfirm") {
								accepted = retrieveValue(dom, "//wzem:DpchEngWzemConfirm/wzem:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngWzemNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
					};
				};
			};
		};
	};

	if ((srefIxWzemVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxWzemVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};
