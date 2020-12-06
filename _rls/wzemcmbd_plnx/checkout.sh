#!/bin/bash
# file checkout.sh
# checkout script for Wzem combined daemon, release wzemcmbd_plnx(ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build
export set LIBROOT=${SYSROOT}${WHIZSDKROOT}/lib
export set BINROOT=${SYSROOT}${WHIZROOT}/bin

mkdir $BUILDROOT/wzemcmbd
mkdir $BUILDROOT/wzemcmbd/IexWzem
mkdir $BUILDROOT/wzemcmbd/VecWzem
mkdir $BUILDROOT/wzemcmbd/CrdWzemUsg
mkdir $BUILDROOT/wzemcmbd/CrdWzemUsr
mkdir $BUILDROOT/wzemcmbd/CrdWzemPrs
mkdir $BUILDROOT/wzemcmbd/CrdWzemNav
mkdir $BUILDROOT/wzemcmbd/CrdWzemPrd
mkdir $BUILDROOT/wzemcmbd/CrdWzemEvt
mkdir $BUILDROOT/wzemcmbd/CrdWzemJob
mkdir $BUILDROOT/wzemcmbd/CrdWzemCal
mkdir $BUILDROOT/wzemcmbd/CrdWzemCln
mkdir $BUILDROOT/wzemcmbd/CrdWzemOpx
mkdir $BUILDROOT/wzemcmbd/CrdWzemPst
mkdir $BUILDROOT/wzemcmbd/CrdWzemNde

mkdir $LIBROOT/wzemcmbd

mkdir $BINROOT/wzemcmbd

cp make.sh $BUILDROOT/wzemcmbd/
cp remake.sh $BUILDROOT/wzemcmbd/

cp Makefile.inc $BUILDROOT/wzemcmbd/
cp Makefile $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/Wzemcmbd.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/Wzemcmbd.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/WzemcmbdAppsrv.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/WzemcmbdAppsrv.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/WzemcmbdJobprc.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/WzemcmbdJobprc.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/WzemcmbdOpprc.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/WzemcmbdOpprc.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/Wzemcmbd_exe.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/Wzemcmbd_exe.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/Wzem.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/Wzem.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/Root*.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/Root*.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/Sess*.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/Sess*.cpp $BUILDROOT/wzemcmbd/

cp ../../wzemcmbd/gbl/*.h $BUILDROOT/wzemcmbd/
cp ../../wzemcmbd/gbl/*.cpp $BUILDROOT/wzemcmbd/

cp Makefile_IexWzem $BUILDROOT/wzemcmbd/IexWzem/Makefile

cp ../../wzemcmbd/IexWzem/IexWzem*.h $BUILDROOT/wzemcmbd/IexWzem/
cp ../../wzemcmbd/IexWzem/IexWzem*.cpp $BUILDROOT/wzemcmbd/IexWzem/

cp ../../wzemcmbd/IexWzem/JobWzemIex*.h $BUILDROOT/wzemcmbd/IexWzem/
cp ../../wzemcmbd/IexWzem/JobWzemIex*.cpp $BUILDROOT/wzemcmbd/IexWzem/

cp Makefile_VecWzem $BUILDROOT/wzemcmbd/VecWzem/Makefile

cp ../../wzemcmbd/VecWzem/Vec*.h $BUILDROOT/wzemcmbd/VecWzem/
cp ../../wzemcmbd/VecWzem/Vec*.cpp $BUILDROOT/wzemcmbd/VecWzem/

cp Makefile_CrdWzemUsg $BUILDROOT/wzemcmbd/CrdWzemUsg/Makefile

cp ../../wzemcmbd/CrdWzemUsg/*.h $BUILDROOT/wzemcmbd/CrdWzemUsg/
cp ../../wzemcmbd/CrdWzemUsg/*.cpp $BUILDROOT/wzemcmbd/CrdWzemUsg/

cp Makefile_CrdWzemUsr $BUILDROOT/wzemcmbd/CrdWzemUsr/Makefile

cp ../../wzemcmbd/CrdWzemUsr/*.h $BUILDROOT/wzemcmbd/CrdWzemUsr/
cp ../../wzemcmbd/CrdWzemUsr/*.cpp $BUILDROOT/wzemcmbd/CrdWzemUsr/

cp Makefile_CrdWzemPrs $BUILDROOT/wzemcmbd/CrdWzemPrs/Makefile

cp ../../wzemcmbd/CrdWzemPrs/*.h $BUILDROOT/wzemcmbd/CrdWzemPrs/
cp ../../wzemcmbd/CrdWzemPrs/*.cpp $BUILDROOT/wzemcmbd/CrdWzemPrs/

cp Makefile_CrdWzemNav $BUILDROOT/wzemcmbd/CrdWzemNav/Makefile

cp ../../wzemcmbd/CrdWzemNav/*.h $BUILDROOT/wzemcmbd/CrdWzemNav/
cp ../../wzemcmbd/CrdWzemNav/*.cpp $BUILDROOT/wzemcmbd/CrdWzemNav/

cp Makefile_CrdWzemPrd $BUILDROOT/wzemcmbd/CrdWzemPrd/Makefile

cp ../../wzemcmbd/CrdWzemPrd/*.h $BUILDROOT/wzemcmbd/CrdWzemPrd/
cp ../../wzemcmbd/CrdWzemPrd/*.cpp $BUILDROOT/wzemcmbd/CrdWzemPrd/

cp Makefile_CrdWzemEvt $BUILDROOT/wzemcmbd/CrdWzemEvt/Makefile

cp ../../wzemcmbd/CrdWzemEvt/*.h $BUILDROOT/wzemcmbd/CrdWzemEvt/
cp ../../wzemcmbd/CrdWzemEvt/*.cpp $BUILDROOT/wzemcmbd/CrdWzemEvt/

cp Makefile_CrdWzemJob $BUILDROOT/wzemcmbd/CrdWzemJob/Makefile

cp ../../wzemcmbd/CrdWzemJob/*.h $BUILDROOT/wzemcmbd/CrdWzemJob/
cp ../../wzemcmbd/CrdWzemJob/*.cpp $BUILDROOT/wzemcmbd/CrdWzemJob/

cp Makefile_CrdWzemCal $BUILDROOT/wzemcmbd/CrdWzemCal/Makefile

cp ../../wzemcmbd/CrdWzemCal/*.h $BUILDROOT/wzemcmbd/CrdWzemCal/
cp ../../wzemcmbd/CrdWzemCal/*.cpp $BUILDROOT/wzemcmbd/CrdWzemCal/

cp Makefile_CrdWzemCln $BUILDROOT/wzemcmbd/CrdWzemCln/Makefile

cp ../../wzemcmbd/CrdWzemCln/*.h $BUILDROOT/wzemcmbd/CrdWzemCln/
cp ../../wzemcmbd/CrdWzemCln/*.cpp $BUILDROOT/wzemcmbd/CrdWzemCln/

cp Makefile_CrdWzemOpx $BUILDROOT/wzemcmbd/CrdWzemOpx/Makefile

cp ../../wzemcmbd/CrdWzemOpx/*.h $BUILDROOT/wzemcmbd/CrdWzemOpx/
cp ../../wzemcmbd/CrdWzemOpx/*.cpp $BUILDROOT/wzemcmbd/CrdWzemOpx/

cp Makefile_CrdWzemPst $BUILDROOT/wzemcmbd/CrdWzemPst/Makefile

cp ../../wzemcmbd/CrdWzemPst/*.h $BUILDROOT/wzemcmbd/CrdWzemPst/
cp ../../wzemcmbd/CrdWzemPst/*.cpp $BUILDROOT/wzemcmbd/CrdWzemPst/

cp Makefile_CrdWzemNde $BUILDROOT/wzemcmbd/CrdWzemNde/Makefile

cp ../../wzemcmbd/CrdWzemNde/*.h $BUILDROOT/wzemcmbd/CrdWzemNde/
cp ../../wzemcmbd/CrdWzemNde/*.cpp $BUILDROOT/wzemcmbd/CrdWzemNde/
