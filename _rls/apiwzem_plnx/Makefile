# file Makefile
# make file for Wzem API library, release apiwzem_plnx (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 21 Apr 2023
# IP header --- ABOVE

LIBROOT = ${SYSROOT}${WHIZSDKROOT}/lib

CPP = ${TCHROOT}/arm-xilinx-linux-gnueabi-g++
CPPFLAGS = --sysroot=${SYSROOT} --sysroot=${SYSROOT} -std=c++11 -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -g -Wall -Os -pthread

STATLIB = ${TCHROOT}/arm-xilinx-linux-gnueabi-ar
STATLIBFLAGS = rcs

INCPATH = -I=${WHIZSDKROOT}/build -I=/usr/include -I=/usr/include/libxml2

PCHS = ApiWzem.h.gch

OBJS = ApiWzem_blks.o ApiWzem.o
OBJS += VecWzemVDpch.o  VecWzemVExpstate.o VecWzemVReqitmode.o
OBJS += WzemQCalList.o WzemQClnList.o WzemQEvtList.o WzemQJob1NCall.o WzemQJob1NClstn.o WzemQJob1NOp.o WzemQJob1NPreset.o WzemQJobList.o WzemQJobSup1NJob.o WzemQNdeList.o WzemQOpxList.o WzemQPrd1NEvent.o WzemQPrd1NJob.o WzemQPrd1NNode.o WzemQPrdList.o WzemQPrsADetail.o WzemQPrsList.o WzemQPstList.o WzemQUsgAAccess.o WzemQUsgList.o WzemQUsgMNUser.o WzemQUsr1NSession.o WzemQUsrAAccess.o WzemQUsrList.o WzemQUsrMNUsergroup.o
OBJS += CrdWzemCal.o CrdWzemCln.o CrdWzemEvt.o CrdWzemJob.o CrdWzemNav.o CrdWzemNde.o CrdWzemOpx.o CrdWzemPrd.o CrdWzemPrs.o CrdWzemPst.o CrdWzemUsg.o CrdWzemUsr.o DlgWzemNavLoaini.o PnlWzemCalDetail.o PnlWzemCalHeadbar.o PnlWzemCalList.o PnlWzemCalRec.o PnlWzemClnDetail.o PnlWzemClnHeadbar.o PnlWzemClnList.o PnlWzemClnRec.o PnlWzemEvtDetail.o PnlWzemEvtHeadbar.o PnlWzemEvtList.o PnlWzemEvtRec.o PnlWzemJob1NCall.o PnlWzemJob1NClstn.o PnlWzemJob1NOp.o PnlWzemJob1NPreset.o PnlWzemJobDetail.o PnlWzemJobHeadbar.o PnlWzemJobList.o PnlWzemJobRec.o PnlWzemJobSup1NJob.o PnlWzemNavAdmin.o PnlWzemNavHeadbar.o PnlWzemNavMon.o PnlWzemNavPre.o PnlWzemNdeDetail.o PnlWzemNdeHeadbar.o PnlWzemNdeList.o PnlWzemNdeRec.o PnlWzemOpxDetail.o PnlWzemOpxHeadbar.o PnlWzemOpxList.o PnlWzemOpxRec.o PnlWzemPrd1NEvent.o PnlWzemPrd1NJob.o PnlWzemPrd1NNode.o PnlWzemPrdDetail.o PnlWzemPrdHeadbar.o PnlWzemPrdList.o PnlWzemPrdRec.o PnlWzemPrsADetail.o PnlWzemPrsDetail.o PnlWzemPrsHeadbar.o PnlWzemPrsList.o PnlWzemPrsRec.o PnlWzemPstDetail.o PnlWzemPstHeadbar.o PnlWzemPstList.o PnlWzemPstRec.o PnlWzemUsgAAccess.o PnlWzemUsgDetail.o PnlWzemUsgHeadbar.o PnlWzemUsgList.o PnlWzemUsgMNUser.o PnlWzemUsgRec.o PnlWzemUsr1NSession.o PnlWzemUsrAAccess.o PnlWzemUsrDetail.o PnlWzemUsrHeadbar.o PnlWzemUsrList.o PnlWzemUsrMNUsergroup.o PnlWzemUsrRec.o QryWzemCalList.o QryWzemClnList.o QryWzemEvtList.o QryWzemJob1NCall.o QryWzemJob1NClstn.o QryWzemJob1NOp.o QryWzemJob1NPreset.o QryWzemJobList.o QryWzemJobSup1NJob.o QryWzemNdeList.o QryWzemOpxList.o QryWzemPrd1NEvent.o QryWzemPrd1NJob.o QryWzemPrd1NNode.o QryWzemPrdList.o QryWzemPrsADetail.o QryWzemPrsList.o QryWzemPstList.o QryWzemUsgAAccess.o QryWzemUsgList.o QryWzemUsgMNUser.o QryWzemUsr1NSession.o QryWzemUsrAAccess.o QryWzemUsrList.o QryWzemUsrMNUsergroup.o RootWzem.o SessWzem.o

LIB = libapiwzem

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o
