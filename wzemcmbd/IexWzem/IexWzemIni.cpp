/**
	* \file IexWzemIni.cpp
	* data blocks and readers/writers for import/export complex IexWzemIni (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#include "IexWzemIni.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWzemIni::VecVIme
 ******************************************************************************/

uint IexWzemIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamuseraccess") return IMEIAMUSERACCESS;
	if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	if (s == "imeimperson") return IMEIMPERSON;
	if (s == "imeimuser") return IMEIMUSER;
	if (s == "imeimusergroup") return IMEIMUSERGROUP;

	return(0);
};

string IexWzemIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMUSERACCESS) return("ImeIAMUserAccess");
	if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	if (ix == IMEIMPERSON) return("ImeIMPerson");
	if (ix == IMEIMUSER) return("ImeIMUser");
	if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");

	return("");
};

/******************************************************************************
 class IexWzemIni::ImeitemIAVControlPar
 ******************************************************************************/

IexWzemIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixWzemVControl
			, const string& Par
			, const string& Val
		) : WzemAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWzemVControl = ixWzemVControl;
	this->Par = Par;
	this->Val = Val;
};

IexWzemIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIAVControlPar()
		{
	WzemAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemavcontrolpar->loadRecByRef(ref, &rec)) {
		ixWzemVControl = rec->ixWzemVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

void IexWzemIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWzemVControl = txtrd.fields[0]; ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWZEMVCONTROL;};
	if (txtrd.fields.size() > 1) {Par = txtrd.fields[1]; ixWIelValid += ImeIAVControlPar::VecWIel::PAR;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVControlPar::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWzemVControl", "con", srefIxWzemVControl)) ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWZEMVCONTROL;
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexWzemIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecWzemVControl::getSref(ixWzemVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexWzemIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","con","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxWzemVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVControl::getSref(ixWzemVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwzemvcontrol") ix |= SREFIXWZEMVCONTROL;
		else if (ss[i] == "par") ix |= PAR;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWzemIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZEMVCONTROL) ss.push_back("srefIxWzemVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIAVControlPar
 ******************************************************************************/

IexWzemIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexWzemIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexWzemIni::ImeIAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzemIni::ImeitemIAVControlPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVControlPar.end" << endl;
	};
};

void IexWzemIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexWzemIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const uint x1IxWzemVLocale
			, const string& Title
			, const string& Comment
		) : WzemJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWzemVLocale = x1IxWzemVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWzemIni::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey()
		{
	WzemJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemjavkeylistkey->loadRecByRef(ref, &rec)) {
		refWzemAVKeylistKey = rec->refWzemAVKeylistKey;
		x1IxWzemVLocale = rec->x1IxWzemVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzemIni::ImeitemIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWzemVLocale = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXWZEMVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzemVLocale", "lcl", srefX1IxWzemVLocale)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::SREFX1IXWZEMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexWzemIni::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWzemVLocale::getSref(x1IxWzemVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexWzemIni::ImeitemIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey","srefX1IxWzemVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVLocale::getSref(x1IxWzemVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIJAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwzemvlocale") ix |= SREFX1IXWZEMVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzemIni::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIJAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZEMVLOCALE) ss.push_back("srefX1IxWzemVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIJAVKeylistKey
 ******************************************************************************/

IexWzemIni::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexWzemIni::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexWzemIni::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWzemIni::ImeitemIJAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIJAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexWzemIni::ImeIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIAVKeylistKey
 ******************************************************************************/

IexWzemIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			const uint klsIxWzemVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
			, const string& Title
			, const string& Comment
		) : WzemAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxWzemVKeylist = klsIxWzemVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

IexWzemIni::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey()
		{
	WzemAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWzemVKeylist = rec->klsIxWzemVKeylist;
		klsNum = rec->klsNum;
		x1IxWzemVMaintable = rec->x1IxWzemVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzemIni::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxWzemVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXWZEMVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Avail = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 3) {Implied = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
					imeijavkeylistkey.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxWzemVKeylist", "kls", srefKlsIxWzemVKeylist)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREFKLSIXWZEMVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexWzemIni::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << VecWzemVKeylist::getSref(klsIxWzemVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexWzemIni::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey","srefKlsIxWzemVKeylist","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVKeylist::getSref(klsIxWzemVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		writeString(wr, tags[5], Title);
		writeString(wr, tags[6], Comment);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixwzemvkeylist") ix |= SREFKLSIXWZEMVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzemIni::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIAVKeylistKey::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXWZEMVKEYLIST) ss.push_back("srefKlsIxWzemVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIAVKeylistKey
 ******************************************************************************/

IexWzemIni::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexWzemIni::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexWzemIni::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzemIni::ImeitemIAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVKeylistKey.end" << endl;
	};
};

void IexWzemIni::ImeIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexWzemIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxWzemVValuelist
			, const uint x1IxWzemVLocale
			, const string& Val
		) : WzemAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxWzemVValuelist = vlsIxWzemVValuelist;
	this->x1IxWzemVLocale = x1IxWzemVLocale;
	this->Val = Val;
};

IexWzemIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIAVValuelistVal()
		{
	WzemAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxWzemVValuelist = rec->vlsIxWzemVValuelist;
		vlsNum = rec->vlsNum;
		x1IxWzemVLocale = rec->x1IxWzemVLocale;
		Val = rec->Val;

		delete rec;
	};
};

void IexWzemIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefVlsIxWzemVValuelist = txtrd.fields[0]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWZEMVVALUELIST;};
	if (txtrd.fields.size() > 1) {srefX1IxWzemVLocale = txtrd.fields[1]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWZEMVLOCALE;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxWzemVValuelist", "vls", srefVlsIxWzemVValuelist)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWZEMVVALUELIST;
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzemVLocale", "lcl", srefX1IxWzemVLocale)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWZEMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexWzemIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecWzemVValuelist::getSref(vlsIxWzemVValuelist) << "\t" << VecWzemVLocale::getSref(x1IxWzemVLocale) << "\t" << Val << endl;
};

void IexWzemIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxWzemVValuelist","srefX1IxWzemVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVValuelist::getSref(vlsIxWzemVValuelist));
		writeString(wr, tags[2], VecWzemVLocale::getSref(x1IxWzemVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefvlsixwzemvvaluelist") ix |= SREFVLSIXWZEMVVALUELIST;
		else if (ss[i] == "srefx1ixwzemvlocale") ix |= SREFX1IXWZEMVLOCALE;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWzemIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXWZEMVVALUELIST) ss.push_back("srefVlsIxWzemVValuelist");
	if (ix & SREFX1IXWZEMVLOCALE) ss.push_back("srefX1IxWzemVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIAVValuelistVal
 ******************************************************************************/

IexWzemIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexWzemIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexWzemIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzemIni::ImeitemIAVValuelistVal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVValuelistVal.end" << endl;
	};
};

void IexWzemIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexWzemIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxWzemVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWzemWAccess
		) : WzemAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWzemVFeatgroup = x1IxWzemVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzemWAccess = ixWzemWAccess;
};

IexWzemIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIAMUsergroupAccess()
		{
	WzemAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemamusergroupaccess->loadRecByRef(ref, &rec)) {
		refWzemMUsergroup = rec->refWzemMUsergroup;
		x1IxWzemVFeatgroup = rec->x1IxWzemVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWzemWAccess = rec->ixWzemWAccess;

		delete rec;
	};
};

void IexWzemIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWzemVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWZEMVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWzemWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWZEMWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzemVFeatgroup", "feg", srefX1IxWzemVFeatgroup)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWZEMVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWzemWAccess", "acc", srefsIxWzemWAccess)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWZEMWACCESS;
	};
};

void IexWzemIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWzemVFeatgroup::getSref(x1IxWzemVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWzemWAccess::getSrefs(ixWzemWAccess) << endl;
};

void IexWzemIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxWzemVFeatgroup","x2FeaSrefUix","srefsIxWzemWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVFeatgroup::getSref(x1IxWzemVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWzemWAccess::getSrefs(ixWzemWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwzemvfeatgroup") ix |= SREFX1IXWZEMVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwzemwaccess") ix |= SREFSIXWZEMWACCESS;
	};

	return(ix);
};

void IexWzemIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWZEMWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZEMVFEATGROUP) ss.push_back("srefX1IxWzemVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWZEMWACCESS) ss.push_back("srefsIxWzemWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexWzemIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexWzemIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexWzemIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWzemIni::ImeitemIAMUsergroupAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMUsergroupAccess.end" << endl;
	};
};

void IexWzemIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIAMUserAccess
 ******************************************************************************/

IexWzemIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			const uint x1IxWzemVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWzemWAccess
		) : WzemAMUserAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWzemVFeatgroup = x1IxWzemVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWzemWAccess = ixWzemWAccess;
};

IexWzemIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIAMUserAccess()
		{
	WzemAMUserAccess* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemamuseraccess->loadRecByRef(ref, &rec)) {
		refWzemMUser = rec->refWzemMUser;
		x1IxWzemVFeatgroup = rec->x1IxWzemVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWzemWAccess = rec->ixWzemWAccess;

		delete rec;
	};
};

void IexWzemIni::ImeitemIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWzemVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWZEMVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWzemWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWZEMWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWzemVFeatgroup", "feg", srefX1IxWzemVFeatgroup)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWZEMVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWzemWAccess", "acc", srefsIxWzemWAccess)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWZEMWACCESS;
	};
};

void IexWzemIni::ImeitemIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWzemVFeatgroup::getSref(x1IxWzemVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWzemWAccess::getSrefs(ixWzemWAccess) << endl;
};

void IexWzemIni::ImeitemIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUserAccess","srefX1IxWzemVFeatgroup","x2FeaSrefUix","srefsIxWzemWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVFeatgroup::getSref(x1IxWzemVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWzemWAccess::getSrefs(ixWzemWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIAMUserAccess::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIAMUserAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwzemvfeatgroup") ix |= SREFX1IXWZEMVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwzemwaccess") ix |= SREFSIXWZEMWACCESS;
	};

	return(ix);
};

void IexWzemIni::ImeIAMUserAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWZEMWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIAMUserAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZEMVFEATGROUP) ss.push_back("srefX1IxWzemVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWZEMWACCESS) ss.push_back("srefsIxWzemWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIAMUserAccess
 ******************************************************************************/

IexWzemIni::ImeIAMUserAccess::ImeIAMUserAccess() {
};

IexWzemIni::ImeIAMUserAccess::~ImeIAMUserAccess() {
	clear();
};

void IexWzemIni::ImeIAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIAMUserAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWzemIni::ImeitemIAMUserAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIAMUserAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUserAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUserAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUserAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIAMUserAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMUserAccess." << StrMod::replaceChar(ImeIAMUserAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMUserAccess.end" << endl;
	};
};

void IexWzemIni::ImeIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUserAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIJMUserState
 ******************************************************************************/

IexWzemIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : WzemJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWzemIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIJMUserState()
		{
	WzemJMUserState* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemjmuserstate->loadRecByRef(ref, &rec)) {
		refWzemMUser = rec->refWzemMUser;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWzemIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
	};
};

void IexWzemIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWzemVMUserState::getSref(ixVState) << endl;
};

void IexWzemIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexWzemIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIJMUserState
 ******************************************************************************/

IexWzemIni::ImeIJMUserState::ImeIJMUserState() {
};

IexWzemIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexWzemIni::ImeIJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWzemIni::ImeitemIJMUserState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMUserState.end" << endl;
	};
};

void IexWzemIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexWzemIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : WzemJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexWzemIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIJMPersonLastname()
		{
	WzemJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemjmpersonlastname->loadRecByRef(ref, &rec)) {
		refWzemMPerson = rec->refWzemMPerson;
		x1Startd = rec->x1Startd;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWzemIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Lastname = txtrd.fields[0]; ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexWzemIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexWzemIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWzemIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIJMPersonLastname
 ******************************************************************************/

IexWzemIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexWzemIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexWzemIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWzemIni::ImeitemIJMPersonLastname();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPersonLastname.end" << endl;
	};
};

void IexWzemIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIMPerson
 ******************************************************************************/

IexWzemIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
			, const string& Lastname
		) : WzemMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
};

IexWzemIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIMPerson()
		{
	WzemMPerson* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemmperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWzemIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVSex = txtrd.fields[0]; ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMPerson::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Firstname = txtrd.fields[2]; ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;};
	if (txtrd.fields.size() > 3) {Lastname = txtrd.fields[3]; ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
					imeijmpersonlastname.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexWzemIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWzemVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << "\t" << Lastname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexWzemIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm","lnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWzemVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		writeString(wr, tags[4], Lastname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvsex") ix |= SREFIXVSEX;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "firstname") ix |= FIRSTNAME;
		else if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWzemIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");
	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIMPerson
 ******************************************************************************/

IexWzemIni::ImeIMPerson::ImeIMPerson() {
};

IexWzemIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexWzemIni::ImeIMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWzemIni::ImeitemIMPerson();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPERSON) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPerson.end" << endl;
	};
};

void IexWzemIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIMUser
 ******************************************************************************/

IexWzemIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixVState
			, const uint ixWzemVLocale
			, const uint ixWzemVUserlevel
			, const string& Password
			, const string& Fullkey
			, const string& Comment
		) : WzemMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVState = ixVState;
	this->ixWzemVLocale = ixWzemVLocale;
	this->ixWzemVUserlevel = ixWzemVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

IexWzemIni::ImeitemIMUser::ImeitemIMUser(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIMUser()
		{
	WzemMUser* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemmuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refWzemMUsergroup = rec->refWzemMUsergroup;
		refWzemMPerson = rec->refWzemMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixWzemVLocale = rec->ixWzemVLocale;
		ixWzemVUserlevel = rec->ixWzemVUserlevel;
		Password = rec->Password;
		Fullkey = rec->Fullkey;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzemIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUser::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVState = txtrd.fields[1]; ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 2) {srefIxWzemVLocale = txtrd.fields[2]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWZEMVLOCALE;};
	if (txtrd.fields.size() > 3) {srefIxWzemVUserlevel = txtrd.fields[3]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWZEMVUSERLEVEL;};
	if (txtrd.fields.size() > 4) {Password = txtrd.fields[4]; ixWIelValid += ImeIMUser::VecWIel::PASSWORD;};
	if (txtrd.fields.size() > 5) {Fullkey = txtrd.fields[5]; ixWIelValid += ImeIMUser::VecWIel::FULLKEY;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMUser::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS)) {
					imeiamuseraccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
					imeijmuserstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
					imeimperson.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefIxWzemVLocale", "lcl", srefIxWzemVLocale)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWZEMVLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxWzemVUserlevel", "ulv", srefIxWzemVUserlevel)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWZEMVUSERLEVEL;
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		if (extractStringUclc(docctx, basexpath, "Fullkey", "fky", Fullkey)) ixWIelValid += ImeIMUser::VecWIel::FULLKEY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUser::VecWIel::COMMENT;
		imeiamuseraccess.readXML(docctx, basexpath);
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexWzemIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecWzemVMUserState::getSref(ixVState) << "\t" << VecWzemVLocale::getSref(ixWzemVLocale) << "\t" << VecWzemVUserlevel::getSref(ixWzemVUserlevel) << "\t" << Password << "\t" << Fullkey << "\t" << Comment << endl;
	imeiamuseraccess.writeTxt(outfile);
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexWzemIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ste","lcl","ulv","pwd","fky","cmt"};
	else tags = {"ImeitemIMUser","sref","srefIxVState","srefIxWzemVLocale","srefIxWzemVUserlevel","Password","Fullkey","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWzemVMUserState::getSref(ixVState));
		writeString(wr, tags[3], VecWzemVLocale::getSref(ixWzemVLocale));
		writeString(wr, tags[4], VecWzemVUserlevel::getSref(ixWzemVUserlevel));
		writeString(wr, tags[5], Password);
		writeString(wr, tags[6], Fullkey);
		writeString(wr, tags[7], Comment);
		imeiamuseraccess.writeXML(wr, shorttags);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefixwzemvlocale") ix |= SREFIXWZEMVLOCALE;
		else if (ss[i] == "srefixwzemvuserlevel") ix |= SREFIXWZEMVUSERLEVEL;
		else if (ss[i] == "password") ix |= PASSWORD;
		else if (ss[i] == "fullkey") ix |= FULLKEY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzemIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFIXWZEMVLOCALE) ss.push_back("srefIxWzemVLocale");
	if (ix & SREFIXWZEMVUSERLEVEL) ss.push_back("srefIxWzemVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");
	if (ix & FULLKEY) ss.push_back("Fullkey");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIMUser
 ******************************************************************************/

IexWzemIni::ImeIMUser::ImeIMUser() {
};

IexWzemIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexWzemIni::ImeIMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWzemIni::ImeitemIMUser();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMUser.end" << endl;
	};
};

void IexWzemIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWzemIni::ImeitemIMUsergroup
 ******************************************************************************/

IexWzemIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : WzemMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWzemIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsWzem* dbswzem
			, const ubigint ref
		) :
			ImeitemIMUsergroup()
		{
	WzemMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbswzem->tblwzemmusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWzemIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUsergroup::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
					imeiamusergroupaccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
					imeimuser.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWzemIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexWzemIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexWzemIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWzemIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexWzemIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWzemIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWzemIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWzemIni::ImeIMUsergroup
 ******************************************************************************/

IexWzemIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexWzemIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexWzemIni::ImeIMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWzemIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexWzemIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWzemIni::ImeitemIMUsergroup();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWzemIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWzemIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWzemIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWzemIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUsergroup.end" << endl;
	};
};

void IexWzemIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWzemIni
 ******************************************************************************/

void IexWzemIni::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimusergroup);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWzemIni", Version(""), VecVIme::getIx);
			readTxt(rd, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimusergroup);
	};
};

void IexWzemIni::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimusergroup);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeiavcontrolpar, imeiavkeylistkey, imeiavvaluelistval, imeimusergroup);
		txtfile.close();
	};
};

void IexWzemIni::readTxt(
			Txtrd& txtrd
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMUsergroup& imeimusergroup
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR)) imeiavcontrolpar.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) imeiavkeylistkey.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL)) imeiavvaluelistval.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP)) imeimusergroup.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWzemIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMUsergroup& imeimusergroup
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWzemIni")) {

		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);

	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey = ImeIAVKeylistKey();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimusergroup = ImeIMUsergroup();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWzemIni"}});
	};
};

void IexWzemIni::writeTxt(
			fstream& outfile
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMUsergroup& imeimusergroup
		) {
	outfile << "IexWzemIni v" WZEM_VERSION << endl;

	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexWzemIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey& imeiavkeylistkey
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMUsergroup& imeimusergroup
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWzemIni");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZEM_VERSION);

		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWzemIni::icsWzemVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMUSERACCESS,VecWzemVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecWzemVIop::INS},{(uint)VecVIme::IMEIAVCONTROLPAR,VecWzemVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecWzemVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecWzemVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecWzemVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecWzemVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecWzemVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecWzemVIop::INS},{(uint)VecVIme::IMEIMUSER,VecWzemVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecWzemVIop::INS}};
};

uint IexWzemIni::getIxWzemVIop(
			const map<uint,uint>& icsWzemVIop
			, const uint ixVIme
			, uint& ixWzemVIop
		) {
	ixWzemVIop = 0;

	auto it = icsWzemVIop.find(ixVIme);
	if (it != icsWzemVIop.end()) ixWzemVIop = it->second;

	return ixWzemVIop;
};
