# file Makefile
# make file for Wzem database access library, release dbswzem_ssv(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

LIBROOT = /home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf/root/lib

CPP = /home/mpsitech/emb/ssv/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
CPPFLAGS = --sysroot=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf -std=c++11 -mfloat-abi=hard -g -Wall -Os -pthread

STATLIB = /home/mpsitech/emb/ssv/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-ar
STATLIBFLAGS = rcs

INCPATH = -I=/usr/include/libxml2 -I=/usr/local/include

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
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

