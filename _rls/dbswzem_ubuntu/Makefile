# file Makefile
# make file for Wzem database access library, release dbswzem_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 21 Apr 2023
# IP header --- ABOVE

LIBROOT = ${WHIZSDKROOT}/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -fPIC

STATLIB = ar
STATLIBFLAGS = rcs

DYNLIB = g++
DYNLIBFLAGS = -shared
DYNLIBEXT = so

INCPATH = -I${WHIZSDKROOT}/build -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = DbsWzem.h.gch

OBJS = DbsWzem.o
OBJS += WzemAccRMUserUniversal.o WzemAMPersonDetail.o WzemAMUserAccess.o WzemAMUsergroupAccess.o WzemAVControlPar.o WzemAVKeylistKey.o WzemAVValuelistVal.o WzemCEvent.o WzemHistRMUserUniversal.o WzemJAVKeylistKey.o WzemJMCallArgRet.o WzemJMClstn.o WzemJMJobDcol.o WzemJMJobStmgr.o WzemJMPersonLastname.o WzemJMPresetArg.o WzemJMUserState.o WzemMCall.o WzemMClstn.o WzemMDpch.o WzemMEvent.o WzemMJob.o WzemMNode.o WzemMOp.o WzemMPeriod.o WzemMPerson.o WzemMPreset.o WzemMSession.o WzemMUser.o WzemMUsergroup.o WzemRMUsergroupUniversal.o WzemRMUserMUsergroup.o
OBJS += WzemQCalList.o WzemQClnList.o WzemQEvtList.o WzemQJob1NCall.o WzemQJob1NClstn.o WzemQJob1NOp.o WzemQJob1NPreset.o WzemQJobList.o WzemQJobSup1NJob.o WzemQNdeList.o WzemQOpxList.o WzemQPrd1NEvent.o WzemQPrd1NJob.o WzemQPrd1NNode.o WzemQPrdList.o WzemQPreselect.o WzemQPrsADetail.o WzemQPrsList.o WzemQPstList.o WzemQSelect.o WzemQUsgAAccess.o WzemQUsgList.o WzemQUsgMNUser.o WzemQUsr1NSession.o WzemQUsrAAccess.o WzemQUsrList.o WzemQUsrMNUsergroup.o

LIB = libdbswzem

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)
	$(DYNLIB) $(DYNLIBFLAGS) $(OBJS) -o $(LIB).$(DYNLIBEXT)

install:
	mv $(LIB).a $(LIBROOT)/
	mv $(LIB).$(DYNLIBEXT) $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o
