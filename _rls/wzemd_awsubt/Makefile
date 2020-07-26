# file Makefile
# make file for Wzem daemon, release wzemd_awsubt
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWZEMD

LINK = g++
LINKFLAGS = -s

INCPATH = -I$(SRCROOT)/dbswzem -I$(SRCROOT)/wzemd/VecWzem -I$(SRCROOT)/wzemd/IexWzem -I$(SRCROOT)/wzemd
INCPATH += -I$(SRCROOT)/wzemd/CrdWzemUsg -I$(SRCROOT)/wzemd/CrdWzemUsr -I$(SRCROOT)/wzemd/CrdWzemPrs -I$(SRCROOT)/wzemd/CrdWzemNav -I$(SRCROOT)/wzemd/CrdWzemPrd -I$(SRCROOT)/wzemd/CrdWzemEvt -I$(SRCROOT)/wzemd/CrdWzemJob -I$(SRCROOT)/wzemd/CrdWzemCal -I$(SRCROOT)/wzemd/CrdWzemCln -I$(SRCROOT)/wzemd/CrdWzemOpx -I$(SRCROOT)/wzemd/CrdWzemPst -I$(SRCROOT)/wzemd/CrdWzemNde
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/local/include

PCHS = Wzemd.h.gch

OBJS = Wzem.o WzemdAppsrv.o WzemdJobprc.o WzemdOpprc.o WzemdOpengcli.o WzemdOpengsrv.o Wzemd.o
OBJS += RootWzem.o SessWzem.o
OBJS += Wzemd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wzemd
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwzemusg -lcrdwzemusr -lcrdwzemprs -lcrdwzemnav -lcrdwzemprd -lcrdwzemevt -lcrdwzemjob -lcrdwzemcal -lcrdwzemcln -lcrdwzemopx -lcrdwzempst -lcrdwzemnde
LIBS += -liexwzem -lvecwzem -ldbswzem
LIBS += -lcurl -lmicrohttpd -lsbecore_mar -lsbecore_mon
LIBS += -lmariadbclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Wzemd

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
	mv $(EXE) $(BINROOT)/wzemd/

clean:
	rm -f *.gch
	rm -f *.o

