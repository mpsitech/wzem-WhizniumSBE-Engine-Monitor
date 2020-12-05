/**
	* \file IexWzemIni.h
	* data blocks and readers/writers for import/export complex IexWzemIni (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifndef IEXWZEMINI_H
#define IEXWZEMINI_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWzem.h"
#include "VecWzemVIop.h"

#define VecVIexWzemIniIme IexWzemIni::VecVIme

#define ImeitemIWzemIniAVControlPar IexWzemIni::ImeitemIAVControlPar
#define ImeIWzemIniAVControlPar IexWzemIni::ImeIAVControlPar
#define VecWImeIWzemIniAVControlParIel IexWzemIni::ImeIAVControlPar::VecWIel

#define ImeitemIWzemIniJAVKeylistKey IexWzemIni::ImeitemIJAVKeylistKey
#define ImeIWzemIniJAVKeylistKey IexWzemIni::ImeIJAVKeylistKey
#define VecWImeIWzemIniJAVKeylistKeyIel IexWzemIni::ImeIJAVKeylistKey::VecWIel

#define ImeitemIWzemIniAVKeylistKey IexWzemIni::ImeitemIAVKeylistKey
#define ImeIWzemIniAVKeylistKey IexWzemIni::ImeIAVKeylistKey
#define VecWImeIWzemIniAVKeylistKeyIel IexWzemIni::ImeIAVKeylistKey::VecWIel

#define ImeitemIWzemIniAVValuelistVal IexWzemIni::ImeitemIAVValuelistVal
#define ImeIWzemIniAVValuelistVal IexWzemIni::ImeIAVValuelistVal
#define VecWImeIWzemIniAVValuelistValIel IexWzemIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIWzemIniAMUsergroupAccess IexWzemIni::ImeitemIAMUsergroupAccess
#define ImeIWzemIniAMUsergroupAccess IexWzemIni::ImeIAMUsergroupAccess
#define VecWImeIWzemIniAMUsergroupAccessIel IexWzemIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIWzemIniAMUserAccess IexWzemIni::ImeitemIAMUserAccess
#define ImeIWzemIniAMUserAccess IexWzemIni::ImeIAMUserAccess
#define VecWImeIWzemIniAMUserAccessIel IexWzemIni::ImeIAMUserAccess::VecWIel

#define ImeitemIWzemIniJMUserState IexWzemIni::ImeitemIJMUserState
#define ImeIWzemIniJMUserState IexWzemIni::ImeIJMUserState
#define VecWImeIWzemIniJMUserStateIel IexWzemIni::ImeIJMUserState::VecWIel

#define ImeitemIWzemIniJMPersonLastname IexWzemIni::ImeitemIJMPersonLastname
#define ImeIWzemIniJMPersonLastname IexWzemIni::ImeIJMPersonLastname
#define VecWImeIWzemIniJMPersonLastnameIel IexWzemIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIWzemIniMPerson IexWzemIni::ImeitemIMPerson
#define ImeIWzemIniMPerson IexWzemIni::ImeIMPerson
#define VecWImeIWzemIniMPersonIel IexWzemIni::ImeIMPerson::VecWIel

#define ImeitemIWzemIniMUser IexWzemIni::ImeitemIMUser
#define ImeIWzemIniMUser IexWzemIni::ImeIMUser
#define VecWImeIWzemIniMUserIel IexWzemIni::ImeIMUser::VecWIel

#define ImeitemIWzemIniMUsergroup IexWzemIni::ImeitemIMUsergroup
#define ImeIWzemIniMUsergroup IexWzemIni::ImeIMUsergroup
#define VecWImeIWzemIniMUsergroupIel IexWzemIni::ImeIMUsergroup::VecWIel

/**
	* IexWzemIni
	*/
namespace IexWzemIni {
	/**
		* VecVIme (full: VecVIexWzemIniIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMUSERACCESS = 1;
		static const Sbecore::uint IMEIAMUSERGROUPACCESS = 2;
		static const Sbecore::uint IMEIAVCONTROLPAR = 3;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 4;
		static const Sbecore::uint IMEIAVVALUELISTVAL = 5;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 6;
		static const Sbecore::uint IMEIJMPERSONLASTNAME = 7;
		static const Sbecore::uint IMEIJMUSERSTATE = 8;
		static const Sbecore::uint IMEIMPERSON = 9;
		static const Sbecore::uint IMEIMUSER = 10;
		static const Sbecore::uint IMEIMUSERGROUP = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAVControlPar (full: ImeitemIWzemIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public WzemAVControlPar {

	public:
		ImeitemIAVControlPar(const Sbecore::uint ixWzemVControl = 0, const std::string& Par = "", const std::string& Val = "");
		ImeitemIAVControlPar(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWzemVControl;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIWzemIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZEMVCONTROL = 1;
			static const Sbecore::uint PAR = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		std::vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIWzemIniJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public WzemJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const Sbecore::uint x1IxWzemVLocale = 0, const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWzemVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey (full: ImeIWzemIniJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniJAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZEMVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		std::vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIWzemIniAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public WzemAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const Sbecore::uint klsIxWzemVKeylist = 0, const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxWzemVKeylist;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIWzemIniAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXWZEMVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint AVAIL = 4;
			static const Sbecore::uint IMPLIED = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		std::vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIWzemIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public WzemAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const Sbecore::uint vlsIxWzemVValuelist = 0, const Sbecore::uint x1IxWzemVLocale = 0, const std::string& Val = "");
		ImeitemIAVValuelistVal(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefVlsIxWzemVValuelist;
		std::string srefX1IxWzemVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIWzemIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFVLSIXWZEMVVALUELIST = 1;
			static const Sbecore::uint SREFX1IXWZEMVLOCALE = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		std::vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIWzemIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public WzemAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);
		ImeitemIAMUsergroupAccess(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWzemVFeatgroup;
		std::string srefsIxWzemWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIWzemIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZEMVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWZEMWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		std::vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUserAccess (full: ImeitemIWzemIniAMUserAccess)
		*/
	class ImeitemIAMUserAccess : public WzemAMUserAccess {

	public:
		ImeitemIAMUserAccess(const Sbecore::uint x1IxWzemVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWzemWAccess = 0);
		ImeitemIAMUserAccess(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWzemVFeatgroup;
		std::string srefsIxWzemWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUserAccess (full: ImeIWzemIniAMUserAccess)
		*/
	class ImeIAMUserAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniAMUserAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZEMVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWZEMWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUserAccess();
		~ImeIAMUserAccess();

	public:
		std::vector<ImeitemIAMUserAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIWzemIniJMUserState)
		*/
	class ImeitemIJMUserState : public WzemJMUserState {

	public:
		ImeitemIJMUserState(const Sbecore::uint ixVState = 0);
		ImeitemIJMUserState(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIWzemIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		std::vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIWzemIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public WzemJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const std::string& Lastname = "");
		ImeitemIJMPersonLastname(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIWzemIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint LASTNAME = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		std::vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIWzemIniMPerson)
		*/
	class ImeitemIMPerson : public WzemMPerson {

	public:
		ImeitemIMPerson(const Sbecore::uint ixVSex = 0, const std::string& Title = "", const std::string& Firstname = "", const std::string& Lastname = "");
		ImeitemIMPerson(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVSex;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIWzemIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSEX = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint FIRSTNAME = 4;
			static const Sbecore::uint LASTNAME = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		std::vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIWzemIniMUser)
		*/
	class ImeitemIMUser : public WzemMUser {

	public:
		ImeitemIMUser(const std::string& sref = "", const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzemVLocale = 0, const Sbecore::uint ixWzemVUserlevel = 0, const std::string& Password = "", const std::string& Fullkey = "", const std::string& Comment = "");
		ImeitemIMUser(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefIxWzemVLocale;
		std::string srefIxWzemVUserlevel;

		ImeIAMUserAccess imeiamuseraccess;
		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIWzemIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniMUserIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVSTATE = 2;
			static const Sbecore::uint SREFIXWZEMVLOCALE = 4;
			static const Sbecore::uint SREFIXWZEMVUSERLEVEL = 8;
			static const Sbecore::uint PASSWORD = 16;
			static const Sbecore::uint FULLKEY = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		std::vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIWzemIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public WzemMUsergroup {

	public:
		ImeitemIMUsergroup(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMUsergroup(DbsWzem* dbswzem, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIWzemIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIWzemIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		std::vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMUsergroup& imeimusergroup);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMUsergroup& imeimusergroup);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMUsergroup& imeimusergroup);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMUsergroup& imeimusergroup);

	void writeTxt(std::fstream& outfile, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMUsergroup& imeimusergroup);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMUsergroup& imeimusergroup);

	std::map<Sbecore::uint,Sbecore::uint> icsWzemVIopInsAll();
	Sbecore::uint getIxWzemVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWzemVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWzemVIop);
};

#endif

