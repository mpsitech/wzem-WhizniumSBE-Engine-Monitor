# file Makefile
# make file for Wzem combined daemon, release wzemcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZEMCMBD

LINK = g++
LINKFLAGS = -s

INCPATH = -I$(BUILDROOT)/dbswzem -I$(BUILDROOT)/wzemcmbd/VecWzem -I$(BUILDROOT)/wzemcmbd/IexWzem -I$(BUILDROOT)/wzemcmbd
INCPATH += -I$(BUILDROOT)/wzemcmbd/CrdWzemUsg -I$(BUILDROOT)/wzemcmbd/CrdWzemUsr -I$(BUILDROOT)/wzemcmbd/CrdWzemPrs -I$(BUILDROOT)/wzemcmbd/CrdWzemNav -I$(BUILDROOT)/wzemcmbd/CrdWzemPrd -I$(BUILDROOT)/wzemcmbd/CrdWzemEvt -I$(BUILDROOT)/wzemcmbd/CrdWzemJob -I$(BUILDROOT)/wzemcmbd/CrdWzemCal -I$(BUILDROOT)/wzemcmbd/CrdWzemCln -I$(BUILDROOT)/wzemcmbd/CrdWzemOpx -I$(BUILDROOT)/wzemcmbd/CrdWzemPst -I$(BUILDROOT)/wzemcmbd/CrdWzemNde
INCPATH += -I${WHIZSDKROOT}/build -I/usr/include -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Wzemcmbd.h.gch

OBJS = Wzem.o WzemcmbdAppsrv.o WzemcmbdJobprc.o WzemcmbdOpprc.o Wzemcmbd.o
OBJS += RootWzem.o SessWzem.o
OBJS += Wzemcmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wzemcmbd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwzemusg -lcrdwzemusr -lcrdwzemprs -lcrdwzemnav -lcrdwzemprd -lcrdwzemevt -lcrdwzemjob -lcrdwzemcal -lcrdwzemcln -lcrdwzemopx -lcrdwzempst -lcrdwzemnde
LIBS += -liexwzem -lvecwzem -ldbswzem
LIBS += -lmicrohttpd -lsbecore_lite -lsbecore_mar -lsbecore_mon
LIBS += -lmariadbclient -lsbecore_plus -lsqlite3
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2
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
	mv $(EXE) $(BINROOT)/wzemcmbd/

clean:
	rm -f *.gch
	rm -f *.o
