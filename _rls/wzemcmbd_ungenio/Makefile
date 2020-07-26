# file Makefile
# make file for Wzem combined daemon, release wzemcmbd_ungenio
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
INCPATH += -I/Library/PostgreSQL/9.6/include -I/usr/local/include -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Wzemcmbd.h.gch

OBJS = Wzem.o WzemcmbdAppsrv.o WzemcmbdJobprc.o WzemcmbdOpprc.o Wzemcmbd.o
OBJS += RootWzem.o SessWzem.o
OBJS += Wzemcmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wzemcmbd
LIBPATH += -L/Library/PostgreSQL/9.6/lib -L/usr/local/lib -L/usr/local/mysql/lib
LIBPATH += 

LIBS = -lcrdwzemusg -lcrdwzemusr -lcrdwzemprs -lcrdwzemnav -lcrdwzemprd -lcrdwzemevt -lcrdwzemjob -lcrdwzemcal -lcrdwzemcln -lcrdwzemopx -lcrdwzempst -lcrdwzemnde
LIBS += -liexwzem -lvecwzem -ldbswzem
LIBS += -lmicrohttpd -lsbecore_mon -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += 

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

