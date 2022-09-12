// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWzemNavMon", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemNavMon", "srefIxWzemVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Mon", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Mon_side").setAttribute("height", "30");
	doc.getElementById("Mon_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Mon_side").src = "./PnlWzemNavMon_aside.html";
	doc.getElementById("Mon_cont").src = "./PnlWzemNavMon_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemNavMon", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemNavMon", "srefIxWzemVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Mon_side").src = "./PnlWzemNavMon_bside.html";
	doc.getElementById("Mon_cont").src = "./PnlWzemNavMon_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Mon_side").contentDocument;
	contdoc = doc.getElementById("Mon_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzemNavMon", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Mon_side").contentDocument;
	contdoc = doc.getElementById("Mon_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Mon_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Mon_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzemNavMon", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemNavMon", "srefIxWzemVExpstate");

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

	var height = 778; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstPrdAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstPrdAlt") == "true");
	var LstPrdAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstPrdAvail") == "true");
	var ButPrdViewAvail = !LstPrdAlt;
	var ButPrdViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButPrdViewActive") == "true");

	var LstEvtAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstEvtAlt") == "true");
	var LstEvtAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstEvtAvail") == "true");
	var ButEvtViewAvail = !LstEvtAlt;
	var ButEvtViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButEvtViewActive") == "true");
	var ButEvtNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButEvtNewcrdActive") == "true");

	var LstJobAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstJobAlt") == "true");
	var LstJobAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstJobAvail") == "true");
	var ButJobViewAvail = !LstJobAlt;
	var ButJobViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButJobViewActive") == "true");
	var ButJobNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButJobNewcrdActive") == "true");

	var LstCalAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstCalAlt") == "true");
	var LstCalAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstCalAvail") == "true");
	var ButCalViewAvail = !LstCalAlt;
	var ButCalViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButCalViewActive") == "true");
	var ButCalNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButCalNewcrdActive") == "true");

	var LstClnAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstClnAlt") == "true");
	var LstClnAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstClnAvail") == "true");
	var ButClnViewAvail = !LstClnAlt;
	var ButClnViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButClnViewActive") == "true");
	var ButClnNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButClnNewcrdActive") == "true");

	var LstOpxAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstOpxAlt") == "true");
	var LstOpxAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstOpxAvail") == "true");
	var ButOpxViewAvail = !LstOpxAlt;
	var ButOpxViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButOpxViewActive") == "true");
	var ButOpxNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButOpxNewcrdActive") == "true");

	var LstPstAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstPstAlt") == "true");
	var LstPstAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstPstAvail") == "true");
	var ButPstViewAvail = !LstPstAlt;
	var ButPstViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButPstViewActive") == "true");
	var ButPstNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButPstNewcrdActive") == "true");

	var LstNdeAlt = (retrieveSi(srcdoc, "StatAppWzemNavMon", "LstNdeAlt") == "true");
	var LstNdeAvail = (retrieveSi(srcdoc, "StatShrWzemNavMon", "LstNdeAvail") == "true");
	var ButNdeViewAvail = !LstNdeAlt;
	var ButNdeViewActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButNdeViewActive") == "true");
	var ButNdeNewcrdActive = (retrieveSi(srcdoc, "StatShrWzemNavMon", "ButNdeNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Prd", LstPrdAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prd2", LstPrdAvail && !LstPrdAlt, (LstPrdAvail) ? 71 : 0);
	if (LstPrdAvail) {
		if ( (LstPrdAlt == !contcontdoc.getElementById("ButPrdExpand")) || (!LstPrdAlt == !contcontdoc.getElementById("ButPrdCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrd");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrd", retrieveTi(srcdoc, "TagWzemNavMon", "CptPrd")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrdAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrdExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrdCollapse", "icon/collapse"));
		};

		if (!LstPrdAlt == !contcontdoc.getElementById("LstPrd")) {
			mytd = contcontdoc.getElementById("rdynPrd");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrd");
			clearElem(mytd);

			if (LstPrdAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrd", "./PnlWzemNavMon_LstPrd.xml", true));
			};

		} else {
			if (!LstPrdAlt) refreshLst(contcontdoc.getElementById("LstPrd").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrd",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstPrdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstPrd"))]);
		};

		if ((ButPrdViewAvail == !contcontdoc.getElementById("ButPrdView")) || !contcontdoc.getElementById("ButPrdNewcrd")) {
			if (LstPrdAlt) mytd = contcontdoc.getElementById("dynPrd");
			else mytd = contcontdoc.getElementById("rdynPrd");
			clearElem(mytd);

			first = true;

			if (ButPrdViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrdView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrdNewcrd", "icon/newcrd"));
		};

		if (ButPrdViewAvail) refreshButicon(contcontdoc, "ButPrdView", "icon/view", ButPrdViewActive, false);

	} else setCtlAvail(contcontdoc, "Prd2", false, 0);

	height -= setCtlAvail(contcontdoc, "Evt", LstEvtAvail, 96);
	height -= setCtlAvail(contcontdoc, "Evt2", LstEvtAvail && !LstEvtAlt, (LstEvtAvail) ? 71 : 0);
	if (LstEvtAvail) {
		if ( (LstEvtAlt == !contcontdoc.getElementById("ButEvtExpand")) || (!LstEvtAlt == !contcontdoc.getElementById("ButEvtCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynEvt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptEvt", retrieveTi(srcdoc, "TagWzemNavMon", "CptEvt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstEvtAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButEvtExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButEvtCollapse", "icon/collapse"));
		};

		if (!LstEvtAlt == !contcontdoc.getElementById("LstEvt")) {
			mytd = contcontdoc.getElementById("rdynEvt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynEvt");
			clearElem(mytd);

			if (LstEvtAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstEvt", "./PnlWzemNavMon_LstEvt.xml", true));
			};

		} else {
			if (!LstEvtAlt) refreshLst(contcontdoc.getElementById("LstEvt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstEvt",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstEvtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstEvt"))]);
		};

		if ((ButEvtViewAvail == !contcontdoc.getElementById("ButEvtView")) || !contcontdoc.getElementById("ButEvtNewcrd")) {
			if (LstEvtAlt) mytd = contcontdoc.getElementById("dynEvt");
			else mytd = contcontdoc.getElementById("rdynEvt");
			clearElem(mytd);

			first = true;

			if (ButEvtViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButEvtView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEvtNewcrd", "icon/newcrd"));
		};

		if (ButEvtViewAvail) refreshButicon(contcontdoc, "ButEvtView", "icon/view", ButEvtViewActive, false);
		refreshButicon(contcontdoc, "ButEvtNewcrd", "icon/newcrd", ButEvtNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Evt2", false, 0);

	height -= setCtlAvail(contcontdoc, "Job", LstJobAvail, 96);
	height -= setCtlAvail(contcontdoc, "Job2", LstJobAvail && !LstJobAlt, (LstJobAvail) ? 71 : 0);
	if (LstJobAvail) {
		if ( (LstJobAlt == !contcontdoc.getElementById("ButJobExpand")) || (!LstJobAlt == !contcontdoc.getElementById("ButJobCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynJob");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptJob", retrieveTi(srcdoc, "TagWzemNavMon", "CptJob")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstJobAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButJobExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButJobCollapse", "icon/collapse"));
		};

		if (!LstJobAlt == !contcontdoc.getElementById("LstJob")) {
			mytd = contcontdoc.getElementById("rdynJob");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynJob");
			clearElem(mytd);

			if (LstJobAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstJob", "./PnlWzemNavMon_LstJob.xml", true));
			};

		} else {
			if (!LstJobAlt) refreshLst(contcontdoc.getElementById("LstJob").contentWindow.document, srcdoc, 1, true, false, "FeedFLstJob",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstJobNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstJob"))]);
		};

		if ((ButJobViewAvail == !contcontdoc.getElementById("ButJobView")) || !contcontdoc.getElementById("ButJobNewcrd")) {
			if (LstJobAlt) mytd = contcontdoc.getElementById("dynJob");
			else mytd = contcontdoc.getElementById("rdynJob");
			clearElem(mytd);

			first = true;

			if (ButJobViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButJobView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJobNewcrd", "icon/newcrd"));
		};

		if (ButJobViewAvail) refreshButicon(contcontdoc, "ButJobView", "icon/view", ButJobViewActive, false);
		refreshButicon(contcontdoc, "ButJobNewcrd", "icon/newcrd", ButJobNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Job2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cal", LstCalAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cal2", LstCalAvail && !LstCalAlt, (LstCalAvail) ? 71 : 0);
	if (LstCalAvail) {
		if ( (LstCalAlt == !contcontdoc.getElementById("ButCalExpand")) || (!LstCalAlt == !contcontdoc.getElementById("ButCalCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCal");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCal", retrieveTi(srcdoc, "TagWzemNavMon", "CptCal")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCalAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCalExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCalCollapse", "icon/collapse"));
		};

		if (!LstCalAlt == !contcontdoc.getElementById("LstCal")) {
			mytd = contcontdoc.getElementById("rdynCal");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCal");
			clearElem(mytd);

			if (LstCalAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCal", "./PnlWzemNavMon_LstCal.xml", true));
			};

		} else {
			if (!LstCalAlt) refreshLst(contcontdoc.getElementById("LstCal").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCal",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstCalNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstCal"))]);
		};

		if ((ButCalViewAvail == !contcontdoc.getElementById("ButCalView")) || !contcontdoc.getElementById("ButCalNewcrd")) {
			if (LstCalAlt) mytd = contcontdoc.getElementById("dynCal");
			else mytd = contcontdoc.getElementById("rdynCal");
			clearElem(mytd);

			first = true;

			if (ButCalViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCalView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCalNewcrd", "icon/newcrd"));
		};

		if (ButCalViewAvail) refreshButicon(contcontdoc, "ButCalView", "icon/view", ButCalViewActive, false);
		refreshButicon(contcontdoc, "ButCalNewcrd", "icon/newcrd", ButCalNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Cal2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cln", LstClnAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cln2", LstClnAvail && !LstClnAlt, (LstClnAvail) ? 71 : 0);
	if (LstClnAvail) {
		if ( (LstClnAlt == !contcontdoc.getElementById("ButClnExpand")) || (!LstClnAlt == !contcontdoc.getElementById("ButClnCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCln");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCln", retrieveTi(srcdoc, "TagWzemNavMon", "CptCln")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstClnAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButClnExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButClnCollapse", "icon/collapse"));
		};

		if (!LstClnAlt == !contcontdoc.getElementById("LstCln")) {
			mytd = contcontdoc.getElementById("rdynCln");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCln");
			clearElem(mytd);

			if (LstClnAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCln", "./PnlWzemNavMon_LstCln.xml", true));
			};

		} else {
			if (!LstClnAlt) refreshLst(contcontdoc.getElementById("LstCln").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCln",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstClnNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstCln"))]);
		};

		if ((ButClnViewAvail == !contcontdoc.getElementById("ButClnView")) || !contcontdoc.getElementById("ButClnNewcrd")) {
			if (LstClnAlt) mytd = contcontdoc.getElementById("dynCln");
			else mytd = contcontdoc.getElementById("rdynCln");
			clearElem(mytd);

			first = true;

			if (ButClnViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButClnView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButClnNewcrd", "icon/newcrd"));
		};

		if (ButClnViewAvail) refreshButicon(contcontdoc, "ButClnView", "icon/view", ButClnViewActive, false);
		refreshButicon(contcontdoc, "ButClnNewcrd", "icon/newcrd", ButClnNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Cln2", false, 0);

	height -= setCtlAvail(contcontdoc, "Opx", LstOpxAvail, 96);
	height -= setCtlAvail(contcontdoc, "Opx2", LstOpxAvail && !LstOpxAlt, (LstOpxAvail) ? 71 : 0);
	if (LstOpxAvail) {
		if ( (LstOpxAlt == !contcontdoc.getElementById("ButOpxExpand")) || (!LstOpxAlt == !contcontdoc.getElementById("ButOpxCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynOpx");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptOpx", retrieveTi(srcdoc, "TagWzemNavMon", "CptOpx")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstOpxAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButOpxExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButOpxCollapse", "icon/collapse"));
		};

		if (!LstOpxAlt == !contcontdoc.getElementById("LstOpx")) {
			mytd = contcontdoc.getElementById("rdynOpx");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynOpx");
			clearElem(mytd);

			if (LstOpxAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstOpx", "./PnlWzemNavMon_LstOpx.xml", true));
			};

		} else {
			if (!LstOpxAlt) refreshLst(contcontdoc.getElementById("LstOpx").contentWindow.document, srcdoc, 1, true, false, "FeedFLstOpx",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstOpxNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstOpx"))]);
		};

		if ((ButOpxViewAvail == !contcontdoc.getElementById("ButOpxView")) || !contcontdoc.getElementById("ButOpxNewcrd")) {
			if (LstOpxAlt) mytd = contcontdoc.getElementById("dynOpx");
			else mytd = contcontdoc.getElementById("rdynOpx");
			clearElem(mytd);

			first = true;

			if (ButOpxViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButOpxView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButOpxNewcrd", "icon/newcrd"));
		};

		if (ButOpxViewAvail) refreshButicon(contcontdoc, "ButOpxView", "icon/view", ButOpxViewActive, false);
		refreshButicon(contcontdoc, "ButOpxNewcrd", "icon/newcrd", ButOpxNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Opx2", false, 0);

	height -= setCtlAvail(contcontdoc, "Pst", LstPstAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pst2", LstPstAvail && !LstPstAlt, (LstPstAvail) ? 71 : 0);
	if (LstPstAvail) {
		if ( (LstPstAlt == !contcontdoc.getElementById("ButPstExpand")) || (!LstPstAlt == !contcontdoc.getElementById("ButPstCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPst");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPst", retrieveTi(srcdoc, "TagWzemNavMon", "CptPst")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPstAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPstExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPstCollapse", "icon/collapse"));
		};

		if (!LstPstAlt == !contcontdoc.getElementById("LstPst")) {
			mytd = contcontdoc.getElementById("rdynPst");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPst");
			clearElem(mytd);

			if (LstPstAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPst", "./PnlWzemNavMon_LstPst.xml", true));
			};

		} else {
			if (!LstPstAlt) refreshLst(contcontdoc.getElementById("LstPst").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPst",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstPstNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstPst"))]);
		};

		if ((ButPstViewAvail == !contcontdoc.getElementById("ButPstView")) || !contcontdoc.getElementById("ButPstNewcrd")) {
			if (LstPstAlt) mytd = contcontdoc.getElementById("dynPst");
			else mytd = contcontdoc.getElementById("rdynPst");
			clearElem(mytd);

			first = true;

			if (ButPstViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPstView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPstNewcrd", "icon/newcrd"));
		};

		if (ButPstViewAvail) refreshButicon(contcontdoc, "ButPstView", "icon/view", ButPstViewActive, false);
		refreshButicon(contcontdoc, "ButPstNewcrd", "icon/newcrd", ButPstNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Pst2", false, 0);

	height -= setCtlAvail(contcontdoc, "Nde", LstNdeAvail, 96);
	height -= setCtlAvail(contcontdoc, "Nde2", LstNdeAvail && !LstNdeAlt, (LstNdeAvail) ? 71 : 0);
	if (LstNdeAvail) {
		if ( (LstNdeAlt == !contcontdoc.getElementById("ButNdeExpand")) || (!LstNdeAlt == !contcontdoc.getElementById("ButNdeCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynNde");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptNde", retrieveTi(srcdoc, "TagWzemNavMon", "CptNde")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstNdeAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButNdeExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButNdeCollapse", "icon/collapse"));
		};

		if (!LstNdeAlt == !contcontdoc.getElementById("LstNde")) {
			mytd = contcontdoc.getElementById("rdynNde");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynNde");
			clearElem(mytd);

			if (LstNdeAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstNde", "./PnlWzemNavMon_LstNde.xml", true));
			};

		} else {
			if (!LstNdeAlt) refreshLst(contcontdoc.getElementById("LstNde").contentWindow.document, srcdoc, 1, true, false, "FeedFLstNde",
						parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", "LstNdeNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numFLstNde"))]);
		};

		if ((ButNdeViewAvail == !contcontdoc.getElementById("ButNdeView")) || !contcontdoc.getElementById("ButNdeNewcrd")) {
			if (LstNdeAlt) mytd = contcontdoc.getElementById("dynNde");
			else mytd = contcontdoc.getElementById("rdynNde");
			clearElem(mytd);

			first = true;

			if (ButNdeViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButNdeView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButNdeNewcrd", "icon/newcrd"));
		};

		if (ButNdeViewAvail) refreshButicon(contcontdoc, "ButNdeView", "icon/view", ButNdeViewActive, false);
		refreshButicon(contcontdoc, "ButNdeNewcrd", "icon/newcrd", ButNdeNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Nde2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Mon", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Mon_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Mon_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Mon_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemNavMon", "srefIxWzemVExpstate");

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
	srcdoc = doc.getElementById("Mon_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzemInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWzemNavMon", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWzemNavMon", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNavMonDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemNavMonDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWzemNavMon", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWzemNavMon", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWzemNavMon", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWzemNavMon", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWzemNavMonData", scrJref, "ContIacWzemNavMon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWzemNavMon", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWzemNavMon", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWzemNavMon", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWzemNavMon", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "ContIacWzemNavMon", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstCal", srcdoc)) mask.push("feedFLstCal");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstCln", srcdoc)) mask.push("feedFLstCln");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstEvt", srcdoc)) mask.push("feedFLstEvt");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstJob", srcdoc)) mask.push("feedFLstJob");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstNde", srcdoc)) mask.push("feedFLstNde");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstOpx", srcdoc)) mask.push("feedFLstOpx");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstPrd", srcdoc)) mask.push("feedFLstPrd");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "FeedFLstPst", srcdoc)) mask.push("feedFLstPst");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "StatAppWzemNavMon", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "StatShrWzemNavMon", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemNavMonData", "TagWzemNavMon", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemNavMonData") {
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
			if (blk.nodeName == "DpchEngWzemNavMonData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Mon");
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

			} else if (blk.nodeName == "DpchEngWzemNavMonData") {
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
