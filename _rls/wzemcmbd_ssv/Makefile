# file Makefile
# make file for Wzem combined daemon, release wzemcmbd_ssv(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

include Makefile.inc

CPP = /home/mpsitech/emb/ssv/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
CPPFLAGS = --sysroot=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf -std=c++11 -mfloat-abi=hard -g -Wall -Os -pthread -DWZEMCMBD

LINK = /home/mpsitech/emb/ssv/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
LINKFLAGS = --sysroot=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf  -s

INCPATH = -I=$(SRCROOT)/dbswzem -I=$(SRCROOT)/wzemcmbd/VecWzem -I=$(SRCROOT)/wzemcmbd/IexWzem -I=$(SRCROOT)/wzemcmbd
INCPATH += -I=$(SRCROOT)/wzemcmbd/CrdWzemUsg -I=$(SRCROOT)/wzemcmbd/CrdWzemUsr -I=$(SRCROOT)/wzemcmbd/CrdWzemPrs -I=$(SRCROOT)/wzemcmbd/CrdWzemNav -I=$(SRCROOT)/wzemcmbd/CrdWzemPrd -I=$(SRCROOT)/wzemcmbd/CrdWzemEvt -I=$(SRCROOT)/wzemcmbd/CrdWzemJob -I=$(SRCROOT)/wzemcmbd/CrdWzemCal -I=$(SRCROOT)/wzemcmbd/CrdWzemCln -I=$(SRCROOT)/wzemcmbd/CrdWzemOpx -I=$(SRCROOT)/wzemcmbd/CrdWzemPst -I=$(SRCROOT)/wzemcmbd/CrdWzemNde
INCPATH += -I=/usr/include -I=/usr/include/libxml2 -I=/usr/local/include

PCHS = Wzemcmbd.h.gch

OBJS = Wzem.o WzemcmbdAppsrv.o WzemcmbdJobprc.o WzemcmbdOpprc.o Wzemcmbd.o
OBJS += RootWzem.o SessWzem.o
OBJS += Wzemcmbd_exe.o

LIBPATH = -L=$(LIBROOT)
LIBPATH += -L=$(LIBROOT)/wzemcmbd
LIBPATH += -L=/usr/lib -L=/usr/local/lib
LIBPATH += -L=/lib/arm-linux-gnueabihf

LIBS = -lcrdwzemusg -lcrdwzemusr -lcrdwzemprs -lcrdwzemnav -lcrdwzemprd -lcrdwzemevt -lcrdwzemjob -lcrdwzemcal -lcrdwzemcln -lcrdwzemopx -lcrdwzempst -lcrdwzemnde
LIBS += -liexwzem -lvecwzem -ldbswzem
LIBS += -lmicrohttpd -lsbecore_mon -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Wzemcmbd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) /home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf$(BINROOT)/wzemcmbd/

clean:
	rm -f *.gch
	rm -f *.o

