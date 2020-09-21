#!/bin/bash
# file checkout.sh
# checkout script for Wzem combined daemon, release wzemcmbd_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set LIBROOT=${SYSROOT}${WHIZROOT}/lib
export set BINROOT=${SYSROOT}${WHIZROOT}/bin

mkdir $SRCROOT/wzemcmbd
mkdir $SRCROOT/wzemcmbd/IexWzem
mkdir $SRCROOT/wzemcmbd/VecWzem
mkdir $SRCROOT/wzemcmbd/CrdWzemUsg
mkdir $SRCROOT/wzemcmbd/CrdWzemUsr
mkdir $SRCROOT/wzemcmbd/CrdWzemPrs
mkdir $SRCROOT/wzemcmbd/CrdWzemNav
mkdir $SRCROOT/wzemcmbd/CrdWzemPrd
mkdir $SRCROOT/wzemcmbd/CrdWzemEvt
mkdir $SRCROOT/wzemcmbd/CrdWzemJob
mkdir $SRCROOT/wzemcmbd/CrdWzemCal
mkdir $SRCROOT/wzemcmbd/CrdWzemCln
mkdir $SRCROOT/wzemcmbd/CrdWzemOpx
mkdir $SRCROOT/wzemcmbd/CrdWzemPst
mkdir $SRCROOT/wzemcmbd/CrdWzemNde

mkdir $LIBROOT/wzemcmbd

mkdir $BINROOT/wzemcmbd

cp make.sh $SRCROOT/wzemcmbd/
cp remake.sh $SRCROOT/wzemcmbd/

cp Makefile.inc $SRCROOT/wzemcmbd/
cp Makefile $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/Wzemcmbd.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/Wzemcmbd.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/WzemcmbdAppsrv.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/WzemcmbdAppsrv.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/WzemcmbdJobprc.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/WzemcmbdJobprc.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/WzemcmbdOpprc.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/WzemcmbdOpprc.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/Wzemcmbd_exe.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/Wzemcmbd_exe.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/Wzem.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/Wzem.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/Root*.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/Root*.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/Sess*.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/Sess*.cpp $SRCROOT/wzemcmbd/

cp ../../wzemcmbd/gbl/*.h $SRCROOT/wzemcmbd/
cp ../../wzemcmbd/gbl/*.cpp $SRCROOT/wzemcmbd/

cp Makefile_IexWzem $SRCROOT/wzemcmbd/IexWzem/Makefile

cp ../../wzemcmbd/IexWzem/IexWzem*.h $SRCROOT/wzemcmbd/IexWzem/
cp ../../wzemcmbd/IexWzem/IexWzem*.cpp $SRCROOT/wzemcmbd/IexWzem/

cp ../../wzemcmbd/IexWzem/JobWzemIex*.h $SRCROOT/wzemcmbd/IexWzem/
cp ../../wzemcmbd/IexWzem/JobWzemIex*.cpp $SRCROOT/wzemcmbd/IexWzem/

cp Makefile_VecWzem $SRCROOT/wzemcmbd/VecWzem/Makefile

cp ../../wzemcmbd/VecWzem/Vec*.h $SRCROOT/wzemcmbd/VecWzem/
cp ../../wzemcmbd/VecWzem/Vec*.cpp $SRCROOT/wzemcmbd/VecWzem/

cp Makefile_CrdWzemUsg $SRCROOT/wzemcmbd/CrdWzemUsg/Makefile

cp ../../wzemcmbd/CrdWzemUsg/*.h $SRCROOT/wzemcmbd/CrdWzemUsg/
cp ../../wzemcmbd/CrdWzemUsg/*.cpp $SRCROOT/wzemcmbd/CrdWzemUsg/

cp Makefile_CrdWzemUsr $SRCROOT/wzemcmbd/CrdWzemUsr/Makefile

cp ../../wzemcmbd/CrdWzemUsr/*.h $SRCROOT/wzemcmbd/CrdWzemUsr/
cp ../../wzemcmbd/CrdWzemUsr/*.cpp $SRCROOT/wzemcmbd/CrdWzemUsr/

cp Makefile_CrdWzemPrs $SRCROOT/wzemcmbd/CrdWzemPrs/Makefile

cp ../../wzemcmbd/CrdWzemPrs/*.h $SRCROOT/wzemcmbd/CrdWzemPrs/
cp ../../wzemcmbd/CrdWzemPrs/*.cpp $SRCROOT/wzemcmbd/CrdWzemPrs/

cp Makefile_CrdWzemNav $SRCROOT/wzemcmbd/CrdWzemNav/Makefile

cp ../../wzemcmbd/CrdWzemNav/*.h $SRCROOT/wzemcmbd/CrdWzemNav/
cp ../../wzemcmbd/CrdWzemNav/*.cpp $SRCROOT/wzemcmbd/CrdWzemNav/

cp Makefile_CrdWzemPrd $SRCROOT/wzemcmbd/CrdWzemPrd/Makefile

cp ../../wzemcmbd/CrdWzemPrd/*.h $SRCROOT/wzemcmbd/CrdWzemPrd/
cp ../../wzemcmbd/CrdWzemPrd/*.cpp $SRCROOT/wzemcmbd/CrdWzemPrd/

cp Makefile_CrdWzemEvt $SRCROOT/wzemcmbd/CrdWzemEvt/Makefile

cp ../../wzemcmbd/CrdWzemEvt/*.h $SRCROOT/wzemcmbd/CrdWzemEvt/
cp ../../wzemcmbd/CrdWzemEvt/*.cpp $SRCROOT/wzemcmbd/CrdWzemEvt/

cp Makefile_CrdWzemJob $SRCROOT/wzemcmbd/CrdWzemJob/Makefile

cp ../../wzemcmbd/CrdWzemJob/*.h $SRCROOT/wzemcmbd/CrdWzemJob/
cp ../../wzemcmbd/CrdWzemJob/*.cpp $SRCROOT/wzemcmbd/CrdWzemJob/

cp Makefile_CrdWzemCal $SRCROOT/wzemcmbd/CrdWzemCal/Makefile

cp ../../wzemcmbd/CrdWzemCal/*.h $SRCROOT/wzemcmbd/CrdWzemCal/
cp ../../wzemcmbd/CrdWzemCal/*.cpp $SRCROOT/wzemcmbd/CrdWzemCal/

cp Makefile_CrdWzemCln $SRCROOT/wzemcmbd/CrdWzemCln/Makefile

cp ../../wzemcmbd/CrdWzemCln/*.h $SRCROOT/wzemcmbd/CrdWzemCln/
cp ../../wzemcmbd/CrdWzemCln/*.cpp $SRCROOT/wzemcmbd/CrdWzemCln/

cp Makefile_CrdWzemOpx $SRCROOT/wzemcmbd/CrdWzemOpx/Makefile

cp ../../wzemcmbd/CrdWzemOpx/*.h $SRCROOT/wzemcmbd/CrdWzemOpx/
cp ../../wzemcmbd/CrdWzemOpx/*.cpp $SRCROOT/wzemcmbd/CrdWzemOpx/

cp Makefile_CrdWzemPst $SRCROOT/wzemcmbd/CrdWzemPst/Makefile

cp ../../wzemcmbd/CrdWzemPst/*.h $SRCROOT/wzemcmbd/CrdWzemPst/
cp ../../wzemcmbd/CrdWzemPst/*.cpp $SRCROOT/wzemcmbd/CrdWzemPst/

cp Makefile_CrdWzemNde $SRCROOT/wzemcmbd/CrdWzemNde/Makefile

cp ../../wzemcmbd/CrdWzemNde/*.h $SRCROOT/wzemcmbd/CrdWzemNde/
cp ../../wzemcmbd/CrdWzemNde/*.cpp $SRCROOT/wzemcmbd/CrdWzemNde/

