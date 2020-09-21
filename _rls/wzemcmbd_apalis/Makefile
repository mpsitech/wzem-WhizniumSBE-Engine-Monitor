# file Makefile
# make file for Wzem combined daemon, release wzemcmbd_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

include Makefile.inc

CPP = ${TCHROOT}/arm-tdx-linux-gnueabi-g++
CPPFLAGS = --sysroot=${SYSROOT} -std=c++11 -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -g -Wall -Os -pthread -DWZEMCMBD

LINK = ${TCHROOT}/arm-tdx-linux-gnueabi-g++
LINKFLAGS = --sysroot=${SYSROOT} -s

INCPATH = -I=$(SRCROOT)/dbswzem -I=$(SRCROOT)/wzemcmbd/VecWzem -I=$(SRCROOT)/wzemcmbd/IexWzem -I=$(SRCROOT)/wzemcmbd
INCPATH += -I=$(SRCROOT)/wzemcmbd/CrdWzemUsg -I=$(SRCROOT)/wzemcmbd/CrdWzemUsr -I=$(SRCROOT)/wzemcmbd/CrdWzemPrs -I=$(SRCROOT)/wzemcmbd/CrdWzemNav -I=$(SRCROOT)/wzemcmbd/CrdWzemPrd -I=$(SRCROOT)/wzemcmbd/CrdWzemEvt -I=$(SRCROOT)/wzemcmbd/CrdWzemJob -I=$(SRCROOT)/wzemcmbd/CrdWzemCal -I=$(SRCROOT)/wzemcmbd/CrdWzemCln -I=$(SRCROOT)/wzemcmbd/CrdWzemOpx -I=$(SRCROOT)/wzemcmbd/CrdWzemPst -I=$(SRCROOT)/wzemcmbd/CrdWzemNde
INCPATH += -I=${WHIZROOT}/src -I=/usr/include -I=/usr/include/libxml2

PCHS = Wzemcmbd.h.gch

OBJS = Wzem.o WzemcmbdAppsrv.o WzemcmbdJobprc.o WzemcmbdOpprc.o Wzemcmbd.o
OBJS += RootWzem.o SessWzem.o
OBJS += Wzemcmbd_exe.o

LIBPATH = -L=$(LIBROOT)
LIBPATH += -L=$(LIBROOT)/wzemcmbd
LIBPATH += -L=${WHIZROOT}/lib -L=/usr/lib
LIBPATH += -L=/lib

LIBS = -lcrdwzemusg -lcrdwzemusr -lcrdwzemprs -lcrdwzemnav -lcrdwzemprd -lcrdwzemevt -lcrdwzemjob -lcrdwzemcal -lcrdwzemcln -lcrdwzemopx -lcrdwzempst -lcrdwzemnde
LIBS += -liexwzem -lvecwzem -ldbswzem
LIBS += -lmicrohttpd -lsbecore_lite -lsbecore_mon
LIBS += -lsbecore_plus -lsqlite3
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
	mv $(EXE) ${SYSROOT}$(BINROOT)/wzemcmbd/

clean:
	rm -f *.gch
	rm -f *.o

