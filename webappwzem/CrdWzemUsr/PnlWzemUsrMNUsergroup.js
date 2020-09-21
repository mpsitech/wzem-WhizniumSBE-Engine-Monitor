/**
  * \file PnlWzemUsrMNUsergroup.js
  * web client functionality for panel PnlWzemUsrMNUsergroup
  * \author Catherine Johnson
  * \date created: 21 Sep 2020
  * \date modified: 21 Sep 2020
  */

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate", "mind");

	getRecwnd().changeHeight("MNUsergroup", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("MNUsergroup_side").setAttribute("height", "30");
	doc.getElementById("MNUsergroup_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("MNUsergroup_side").src = "./PnlWzemUsrMNUsergroup_aside.html";
	doc.getElementById("MNUsergroup_cont").src = "./PnlWzemUsrMNUsergroup_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate", "regd");

	getRecwnd().changeHeight("MNUsergroup", 255, true);
	doc.getElementById("tdSide").setAttribute("height", "255");
	doc.getElementById("MNUsergroup_side").setAttribute("height", "255");
	doc.getElementById("MNUsergroup_cont").setAttribute("height", "255");

	// change content
	doc.getElementById("MNUsergroup_side").src = "./PnlWzemUsrMNUsergroup_bside.html";
	doc.getElementById("MNUsergroup_cont").src = "./PnlWzemUsrMNUsergroup_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("MNUsergroup_side").contentDocument;
	contdoc = doc.getElementById("MNUsergroup_cont").contentDocument;
	hdrdoc = null;
	tbldoc = null;
	ftrdoc = null;

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("MNUsergroup_side").contentDocument;
	contdoc = doc.getElementById("MNUsergroup_cont").contentDocument;
	hdrdoc = contdoc.getElementById("MNUsergroup_hdr").contentDocument;
	tbldoc = contdoc.getElementById("MNUsergroup_tbl").contentDocument;
	ftrdoc = contdoc.getElementById("MNUsergroup_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "Cpt"));

	// column headers in refreshBD() only

	setTextContent(ftrdoc, ftrdoc.getElementById("TrsGoto"), retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "Trs"));

	refreshBD(bNotD, true);
};

function init() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") initA();
	else if (srefIxWzemVExpstate == "regd") initBD(true);
	else if (srefIxWzemVExpstate == "detd") initBD(false);
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "Cpt") + " (" + retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "ntot") + ")");
};

function refreshBD(bNotD, chgcol) {
	// obtain record set characteristics
	var jnumSel = parseInt(retrieveSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnum"));
	var jnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "jnumFirstdisp"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ndisp"));
	var jnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "jnumFirstload"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "ntot"));

	var mytbl, mytr, mytd, myimg, mycg, mycol;

	var txt;
	var jnum, selclass;

	var rownode;

	var height;

	// update column characteristics
	if (chgcol) {
		// obtain column (header) characteristics
		var firstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "firstcol"));
		var ncol = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ncol"));

		var TcoMrefWidth = parseInt(retrieveSi(srcdoc, "StgIacWzemUsrMNUsergroup", "TcoMrefWidth"));
		var TcoUlvWidth = parseInt(retrieveSi(srcdoc, "StgIacWzemUsrMNUsergroup", "TcoUlvWidth"));

		// col data is stored in document variables
		doc.cols = new Array();
		doc.widths = new Array();
		doc.fs = new Array();

		var i, ix;
		var wtot = 0;
		var wmax = 425;

		for (i = firstcol, ix = 0; i <= ncol; i++) {
			ix++;

			if (i == 1) {
				doc.cols.push("TcoMref"); doc.widths.push(TcoMrefWidth); doc.fs.push("mref"); wtot += TcoMrefWidth;
			} else if (i == 2) {
				doc.cols.push("TcoUlv"); doc.widths.push(TcoUlvWidth); doc.fs.push("ulv"); wtot += TcoUlvWidth;
			} else {
				ix--;
			};

			if (wtot > wmax) break;
		};

		if (wtot > wmax) {
			wtot -= doc.widths[ix-1];
			doc.cols.pop(); doc.widths.pop(); doc.fs.pop();
			i--; ix--;
		};

		doc.widths[ix-1] = doc.widths[ix-1] + (wmax-wtot);

		// column left and right button availability
		doc.cl = false;
		doc.cr = false;

		doc.cl = (firstcol > 1);
		doc.cr = (ncol > i);

		// update colgroup
		mycg = tbldoc.getElementById("cols");
		var del = mycg.childNodes[1];
		while (del) {
			mycg.removeChild(del);
			del = mycg.childNodes[1];
		};

		mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
		mycol.setAttribute("width", "20");
		mycg.appendChild(mycol);

		for (var j = 0; j < doc.widths.length; j++) {
			mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
			mycol.setAttribute("width", "" + doc.widths[j]);
			mycg.appendChild(mycol);
		};

		mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
		mycol.setAttribute("width", "15");
		mycg.appendChild(mycol);

		// update header row
		mytr = tbldoc.getElementById("hdr");
		clearElem(mytr);

		mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("id", "rhcl");
		mytd.setAttribute("height", "20");
		mytd.setAttribute("class", "col");
		mytd.setAttribute("style", "vertical-align:bottom");

		if (doc.cl) {
			myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
			myimg.setAttribute("id", "TblCprevious");
			myimg.setAttribute("class", "but");
			myimg.setAttribute("width", "12");
			myimg.setAttribute("height", "12");
			myimg.setAttribute("alt", "cprevious");
			myimg.setAttribute("src", "../icon/cprevious.png");
			myimg.setAttribute("onmouseover", "src='../icon/cprevious_hlt.png'");
			myimg.setAttribute("onmouseout", "src='../icon/cprevious.png'");
			myimg.setAttribute("onclick", "handleTblCpreviousClick()")
			mytd.appendChild(myimg);
		};

		mytr.appendChild(mytd);

		for (var j = 0; j < doc.cols.length; j++) {
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", doc.cols[j]);
			mytd.setAttribute("class", "col");
			setTextContent(tbldoc, mytd, retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", doc.cols[j]));

			mytr.appendChild(mytd);
		};

		mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("id", "tdTsb");
		mytr.appendChild(mytd);
	};

	mytr = tbldoc.getElementById("hdr");

	// reset jnumFirstdisp if required
	if ((jnumFirstdisp < jnumFirstload) || (jnumFirstdisp > (jnumFirstload+nload-1))) {
		jnumFirstdisp = jnumFirstload;
		setSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "jnumFirstdisp", jnumFirstdisp);
	};

	// scroll bar
	mytr.removeChild(tbldoc.getElementById("tdTsb"));
	mytr.appendChild(makeTdTsb(tbldoc, (ntot > ndisp), doc.cr, ndisp, (jnumFirstdisp - 1) / (ntot - ndisp), true));

	// clear data rows
	mytbl = tbldoc.getElementById("tbl");
	
	for (var i = 1; true; i++) {
		mytr = tbldoc.getElementById("r" + i);

		if (mytr) {
			mytbl.removeChild(mytr);
		} else {
			break;
		};
	};

	// fill data rows
	for (var i = 1; i <= ndisp; i++) {
		mytr = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:tr");
		mytr.setAttribute("id", "r" + i);

		jnum = jnumFirstdisp+i-1;

		// find element in ListWzemQUsrMNUsergroup
		rownode = getRownode(srcdoc, "ListWzemQUsrMNUsergroup", jnum);

		if (rownode) {
			// regular data row
			if (jnum == jnumSel) {
				selclass = "sel";
			} else {
				if ((jnum%2) == 0) selclass = "nonsel";
				else selclass = "nonselalt";
			};

			if (jnum == jnumSel) mytr.setAttribute("onclick", "handleTblSelect(0)");
			else mytr.setAttribute("onclick", "handleTblSelect(" + jnum + ")");

			// selector
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", "r" + i + "cs");
			mytd.setAttribute("height", "18");
			mytd.setAttribute("class", selclass);

			myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
			myimg.setAttribute("id", "r" + i + "s");
			myimg.setAttribute("width", "10");
			myimg.setAttribute("height", "10");
			myimg.setAttribute("alt", "sel");
			if (jnum == jnumSel) {
				myimg.setAttribute("src", "../icon/sel_hlt.png");
			} else {
				myimg.setAttribute("src", "../icon/sel.png");
				myimg.setAttribute("onmouseover", "src='../icon/sel_hlt.png'");
				myimg.setAttribute("onmouseout", "src='../icon/sel.png'");
			};

			mytd.appendChild(myimg);
			mytr.appendChild(mytd);

			// data cells
			for (var j = 0; j < doc.fs.length; j++) {
				mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				mytd.setAttribute("id", "r" + i + "c" + (j+1));
				mytd.setAttribute("class", selclass);

				txt = replaceUesc(retrieveRowField(srcdoc, rownode, doc.fs[j]));

				if ((jnum == jnumSel) && (txt.length > Math.ceil(doc.widths[j]*0.125))) {
					txt = txt.substring(0, Math.ceil(doc.widths[j]*0.125) -3) + "...";
				} else if ((jnum != jnumSel) && (txt.length > Math.ceil(doc.widths[j]*0.15))) {
					txt = txt.substring(0, Math.ceil(doc.widths[j]*0.15) -3) + "...";
				};

				mytd.appendChild(tbldoc.createTextNode(txt));
				mytr.appendChild(mytd);
			};

		} else {
			// empty row
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", "r" + i + "cs");
			mytd.setAttribute("height", "18");
			mytd.setAttribute("colspan", "" + (doc.widths.length + 2));
			mytr.appendChild(mytd);
		};

		mytbl.appendChild(mytr);
	};

	// footer row
	var jnumLastdisp = jnumFirstdisp + ndisp - 1;
	if (jnumLastdisp > ntot) jnumLastdisp = ntot;

	setTextContent(ftrdoc, ftrdoc.getElementById("TxtShowing"), strShowing(retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "TxtShowing1"), jnumFirstdisp, jnumLastdisp, ntot, retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "TxtShowing2")));

	if (ntot == 0) {
		ftrdoc.getElementById("TrsGoto").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsGoto").setAttribute("onclick", "");
	} else {
		ftrdoc.getElementById("TrsGoto").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsGoto").setAttribute("onclick", "handleTrsGotoClick()");
	};

	if ((ntot <= 1) || (jnumSel == 1)) {
		ftrdoc.getElementById("TrsFirst").src = "../icon/first_inact.png";
		ftrdoc.getElementById("TrsFirst").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseover", "");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseout", "");
		ftrdoc.getElementById("TrsFirst").setAttribute("onclick", "");

		ftrdoc.getElementById("TrsPrevious").src = "../icon/previous_inact.png";
		ftrdoc.getElementById("TrsPrevious").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseover", "");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseout", "");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onclick", "");
	} else {
		ftrdoc.getElementById("TrsFirst").src = "../icon/first.png";
		ftrdoc.getElementById("TrsFirst").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseover", "src='../icon/first_hlt.png'");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseout", "src='../icon/first.png'");
		ftrdoc.getElementById("TrsFirst").setAttribute("onclick", "handleTrsFirstClick()");

		ftrdoc.getElementById("TrsPrevious").src = "../icon/previous.png";
		ftrdoc.getElementById("TrsPrevious").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseover", "src='../icon/previous_hlt.png'");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseout", "src='../icon/previous.png'");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onclick", "handleTrsPreviousClick()");
	};

	if ((ntot <= 1) || (jnumSel == ntot)) {
		ftrdoc.getElementById("TrsNext").src = "../icon/next_inact.png";
		ftrdoc.getElementById("TrsNext").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsNext").onmouseover = null;
		ftrdoc.getElementById("TrsNext").onmouseout = null;
		ftrdoc.getElementById("TrsNext").onclick = null;

		ftrdoc.getElementById("TrsLast").src = "../icon/last_inact.png";
		ftrdoc.getElementById("TrsLast").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsLast").onmouseover = null;
		ftrdoc.getElementById("TrsLast").onmouseout = null;
		ftrdoc.getElementById("TrsLast").onclick = null;
	} else {
		ftrdoc.getElementById("TrsNext").src = "../icon/next.png";
		ftrdoc.getElementById("TrsNext").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsNext").setAttribute("onmouseover", "src='../icon/next_hlt.png'");
		ftrdoc.getElementById("TrsNext").setAttribute("onmouseout", "src='../icon/next.png'");
		ftrdoc.getElementById("TrsNext").setAttribute("onclick", "handleTrsNextClick()");

		ftrdoc.getElementById("TrsLast").src = "../icon/last.png";
		ftrdoc.getElementById("TrsLast").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsLast").setAttribute("onmouseover", "src='../icon/last_hlt.png'");
		ftrdoc.getElementById("TrsLast").setAttribute("onmouseout", "src='../icon/last.png'");
		ftrdoc.getElementById("TrsLast").setAttribute("onclick", "handleTrsLastClick()");
	};

	refreshCsi(ftrdoc, "CsiQst", srcdoc, "FeedFCsiQst", retrieveCi(srcdoc, "ContInfWzemUsrMNUsergroup", "numFCsiQst"));

	height = 20 + 18*ndisp;

	getRecwnd().changeHeight("MNUsergroup", height+55, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+55));
	doc.getElementById("MNUsergroup_side").setAttribute("height", "" + (height+55));
	doc.getElementById("MNUsergroup_cont").setAttribute("height", "" + (height+55));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+55-30));
	contdoc.getElementById("tdTbl").setAttribute("height", "" + height);
	contdoc.getElementById("MNUsergroup_tbl").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzemVExpstate = retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate");

	if (srefIxWzemVExpstate == "mind") refreshA();
	else if (srefIxWzemVExpstate == "regd") refreshBD(true, false);
	else if (srefIxWzemVExpstate == "detd") refreshBD(false, false);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("MNUsergroup_src").contentDocument;

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

function handleButClipboardClick() {
	copyToClipboard(document, srcdoc, "WzemUsrMNUsergroup", "ListWzemQUsrMNUsergroup", retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "TxtRecord1"), retrieveTi(srcdoc, "TagWzemUsrMNUsergroup", "TxtRecord2"),
				["Mref","Ulv",""],
				["mref","ulv","ulv2"]);
};

// --- generalized event handlers for app controls

function handleTblSelect(jnum) {
	var jnumFirstdisp, jnumLastdisp, jnumFirstload;

	var oldJnum = parseInt(retrieveSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnum"));
	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "ntot"));

	if (ntot == 0) return;

	if (jnum < 0) jnum = 0;
	if (jnum > ntot) jnum = ntot;

	if (oldJnum != jnum) {
		setSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnum", jnum);

		if (jnum != 0) {
			if (!((jnum >= oldJnumFirstdisp) && (jnum <= (oldJnumFirstdisp+ndisp-1)))) {
				jnumFirstdisp = jnum - Math.ceil(0.5*ndisp) + 1;
				if ((jnumFirstdisp+ndisp-1) > ntot) jnumFirstdisp = ntot-ndisp+1;
				if (jnumFirstdisp < 1) jnumFirstdisp = 1;

				setSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "jnumFirstdisp", jnumFirstdisp);

				jnumLastdisp = jnumFirstdisp + ndisp - 1;
				if (jnumLastdisp > ntot) jnumLastdisp = ntot;

				if (!((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1)))) {
					jnumFirstload = jnum - Math.ceil(0.5*nload) + 1;
					if (jnumFirstload < 1) jnumFirstload = 1;

					setSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnumFirstload", jnumFirstload);
				};
			};
		};

		var str = serializeDpchAppData(srcdoc, "DpchAppWzemUsrMNUsergroupData", scrJref, "StgIacQryWzemUsrMNUsergroup");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function changeTblJnumFirstdisp(jnumFirstdisp, dJnumFirstdisp, dpgJnumFirstdisp) {
	var jnumLastdisp, jnumFirstload;

	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "ntot"));

	if (ntot == 0) return;

	if (dpgJnumFirstdisp < 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp + 1;
	else if (dpgJnumFirstdisp > 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp - 1;
	else if (dJnumFirstdisp != 0) jnumFirstdisp = oldJnumFirstdisp + dJnumFirstdisp;

	if (jnumFirstdisp > (ntot-ndisp+1)) jnumFirstdisp = ntot-ndisp+1;
	if (jnumFirstdisp < 1) jnumFirstdisp = 1;

	if (oldJnumFirstdisp != jnumFirstdisp) {
		setSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "jnumFirstdisp", jnumFirstdisp);

		jnumLastdisp = jnumFirstdisp + ndisp - 1;
		if (jnumLastdisp > ntot) jnumLastdisp = ntot;

		if ((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1))) {
			refreshBD((retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate") == "regd"), false);

		} else {
			jnumFirstload = jnumFirstdisp - Math.ceil(0.5*(nload-ndisp));
			if (jnumFirstload < 1) jnumFirstload = 1;

			setSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnumFirstload", jnumFirstload);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzemUsrMNUsergroupData", scrJref, "StgIacQryWzemUsrMNUsergroup");
			sendReq(str, doc, handleDpchAppDataDoReply);
		};
	};
};

function handleTblCpreviousClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "firstcol"));

	setSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "firstcol", "" + (oldFirstcol-1));

	refreshBD((retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate") == "regd"), true);
};

function handleTblCnextClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "firstcol"));

	setSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "firstcol", "" + (oldFirstcol+1));

	refreshBD((retrieveSi(srcdoc, "StatAppWzemUsrMNUsergroup", "srefIxWzemVExpstate") == "regd"), true);
};

function handleTrsFirstClick() {
	handleTblSelect(1);
};

function handleTrsPreviousClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnum"));

	handleTblSelect(jnum-1);
};

function handleTrsNextClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryWzemUsrMNUsergroup", "jnum"));

	handleTblSelect(jnum+1);
};

function handleTrsLastClick() {
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "ntot"));

	handleTblSelect(ntot);
};

function handleTrsGotoClick() {
	ftrdoc.getElementById("TrsGoto").style.display = "none";

	var elem = ftrdoc.getElementById("TrsRow");
	elem.style.display = "inline";
	elem.focus();
};

function handleTrsRowMou() {
	var elem = ftrdoc.getElementById("TrsRow");
	elem.value = "";
	elem.style.display = "none";

	ftrdoc.getElementById("TrsGoto").style.display = "inline";
};

function handleTrsRowKey(evt) {
	if (evt.keyCode == 13) {
		handleTblSelect(parseInt(ftrdoc.getElementById("TrsRow").value));

		handleTrsRowMou();
		return false;
	};

	return true;
};

function setTsbPos(pos) {
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ndisp"));
	var vpos = (18 + Math.round(pos * (18*(ndisp-2))));

	tbldoc.getElementById("TsbJpupr").setAttribute("height", "" + (vpos-10));
	tbldoc.getElementById("TsbJpupl").setAttribute("y2", "" + vpos);

	tbldoc.getElementById("TsbJpdownr").setAttribute("y", "" + vpos);
	tbldoc.getElementById("TsbJpdownr").setAttribute("height", "" + (18*ndisp-vpos-11));
	tbldoc.getElementById("TsbJpdownl").setAttribute("y1", "" + vpos);

	tbldoc.getElementById("Tsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleTsbUpClick() {
	changeTblJnumFirstdisp(0, -1, 0);
};

function handleTsbJpupClick() {
	changeTblJnumFirstdisp(0, 0, -1);
};

function handleTsbJpdownClick() {
	changeTblJnumFirstdisp(0, 0, 1);
};

function handleTsbDownClick() {
	changeTblJnumFirstdisp(0, 1, 0);
};

function handleTsbMdn() {
	tbldoc.getElementById("tdTsb").onmousemove = handleTsbMove;
	tbldoc.getElementById("tdTsb").onmouseup = handleTsbMup;
};

function handleTsbMove(evt) {
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ndisp"));

	if ((evt.clientY >= (18+20)) && (evt.clientY <= (18*(ndisp-1)+20))) {
		pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));
		setTsbPos(pos);
	};
};

function handleTsbMup(evt) {
	tbldoc.getElementById("tdTsb").removeAttribute("onmousemove");
	tbldoc.getElementById("tdTsb").removeAttribute("onmouseup");

	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWzemUsrMNUsergroup", "ntot"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWzemUsrMNUsergroup", "ndisp"));

	var pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));

	changeTblJnumFirstdisp(Math.round(pos*(ntot-ndisp))+1, 0, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemUsrMNUsergroupDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzemUsrMNUsergroupDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "ContInfWzemUsrMNUsergroup", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "FeedFCsiQst", srcdoc)) mask.push("feedFCsiQst");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "StatAppWzemUsrMNUsergroup", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "StatShrWzemUsrMNUsergroup", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "StgIacWzemUsrMNUsergroup", srcdoc)) mask.push("stgiac");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "TagWzemUsrMNUsergroup", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "ListWzemQUsrMNUsergroup", srcdoc)) mask.push("rst");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "StatAppQryWzemUsrMNUsergroup", srcdoc)) mask.push("statappqry");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "StatShrQryWzemUsrMNUsergroup", srcdoc)) mask.push("statshrqry");
	if (updateSrcblock(dom, "DpchEngWzemUsrMNUsergroupData", "StgIacQryWzemUsrMNUsergroup", srcdoc)) mask.push("stgiacqry");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzemUsrMNUsergroupData") {
		mergeDpchEngData(dom);
		refresh();
		// IP handleDpchEng --- INSERT
	};
};

// IP dpchhdls --- INSERT

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzem:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzemUsrMNUsergroupData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("MNUsergroup");
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

			} else if (blk.nodeName == "DpchEngWzemUsrMNUsergroupData") {
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

