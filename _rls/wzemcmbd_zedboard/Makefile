# file Makefile
# make file for Wzem combined daemon, release wzemcmbd_zedboard(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

include Makefile.inc

CPP = /opt/Xilinx/petalinux-v2017.2/tools/linux-i386/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-g++
CPPFLAGS = --sysroot=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm -std=c++11 -mfloat-abi=hard -g -Wall -Os -pthread -DWZEMCMBD

LINK = /opt/Xilinx/petalinux-v2017.2/tools/linux-i386/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-g++
LINKFLAGS = --sysroot=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm -s

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
	mv $(EXE) /home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm$(BINROOT)/wzemcmbd/

clean:
	rm -f *.gch
	rm -f *.o

