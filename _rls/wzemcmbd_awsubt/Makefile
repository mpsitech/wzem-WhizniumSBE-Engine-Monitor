# file Makefile
# make file for Wzem combined daemon, release wzemcmbd_awsubt
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZEMCMBD

LINK = g++
LINKFLAGS = -s

INCPATH = -I$(SRCROOT)/dbswzem -I$(SRCROOT)/wzemcmbd/VecWzem -I$(SRCROOT)/wzemcmbd/IexWzem -I$(SRCROOT)/wzemcmbd
INCPATH += -I$(SRCROOT)/wzemcmbd/CrdWzemUsg -I$(SRCROOT)/wzemcmbd/CrdWzemUsr -I$(SRCROOT)/wzemcmbd/CrdWzemPrs -I$(SRCROOT)/wzemcmbd/CrdWzemNav -I$(SRCROOT)/wzemcmbd/CrdWzemPrd -I$(SRCROOT)/wzemcmbd/CrdWzemEvt -I$(SRCROOT)/wzemcmbd/CrdWzemJob -I$(SRCROOT)/wzemcmbd/CrdWzemCal -I$(SRCROOT)/wzemcmbd/CrdWzemCln -I$(SRCROOT)/wzemcmbd/CrdWzemOpx -I$(SRCROOT)/wzemcmbd/CrdWzemPst -I$(SRCROOT)/wzemcmbd/CrdWzemNde
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/local/include

PCHS = Wzemcmbd.h.gch

OBJS = Wzem.o WzemcmbdAppsrv.o WzemcmbdJobprc.o WzemcmbdOpprc.o Wzemcmbd.o
OBJS += RootWzem.o SessWzem.o
OBJS += Wzemcmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wzemcmbd
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwzemusg -lcrdwzemusr -lcrdwzemprs -lcrdwzemnav -lcrdwzemprd -lcrdwzemevt -lcrdwzemjob -lcrdwzemcal -lcrdwzemcln -lcrdwzemopx -lcrdwzempst -lcrdwzemnde
LIBS += -liexwzem -lvecwzem -ldbswzem
LIBS += -lmicrohttpd -lsbecore_mar -lsbecore_mon
LIBS += -lmariadbclient -lsbecore_plus
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
	mv $(EXE) $(BINROOT)/wzemcmbd/

clean:
	rm -f *.gch
	rm -f *.o

