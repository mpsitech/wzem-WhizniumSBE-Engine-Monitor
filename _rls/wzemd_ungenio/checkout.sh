#!/bin/bash
# file checkout.sh
# checkout script for Wzem daemon, release wzemd_ungenio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/Users/mpsitech/src
export set LIBROOT=/Users/mpsitech/lib
export set BINROOT=/Users/mpsitech/bin
export set REPROOT=/Users/mpsitech/srcrep
export set CMBDSRCROOT=$REPROOT/wzem/wzemcmbd

mkdir $SRCROOT/wzemd
mkdir $SRCROOT/wzemd/IexWzem
mkdir $SRCROOT/wzemd/VecWzem
mkdir $SRCROOT/wzemd/CrdWzemUsg
mkdir $SRCROOT/wzemd/CrdWzemUsr
mkdir $SRCROOT/wzemd/CrdWzemPrs
mkdir $SRCROOT/wzemd/CrdWzemNav
mkdir $SRCROOT/wzemd/CrdWzemPrd
mkdir $SRCROOT/wzemd/CrdWzemEvt
mkdir $SRCROOT/wzemd/CrdWzemJob
mkdir $SRCROOT/wzemd/CrdWzemCal
mkdir $SRCROOT/wzemd/CrdWzemCln
mkdir $SRCROOT/wzemd/CrdWzemOpx
mkdir $SRCROOT/wzemd/CrdWzemPst
mkdir $SRCROOT/wzemd/CrdWzemNde

mkdir $LIBROOT/wzemd

mkdir $BINROOT/wzemd

cp make.sh $SRCROOT/wzemd/
cp remake.sh $SRCROOT/wzemd/

cp Makefile.inc $SRCROOT/wzemd/
cp Makefile $SRCROOT/wzemd/

cp ../../wzemd/Wzemd.h $SRCROOT/wzemd/
cp ../../wzemd/Wzemd.cpp $SRCROOT/wzemd/

cp ../../wzemd/WzemdAppsrv.h $SRCROOT/wzemd/
cp ../../wzemd/WzemdAppsrv.cpp $SRCROOT/wzemd/

cp ../../wzemd/WzemdJobprc.h $SRCROOT/wzemd/
cp ../../wzemd/WzemdJobprc.cpp $SRCROOT/wzemd/

cp ../../wzemd/WzemdOpprc.h $SRCROOT/wzemd/
cp ../../wzemd/WzemdOpprc.cpp $SRCROOT/wzemd/

cp ../../wzemd/WzemdOpengsrv.h $SRCROOT/wzemd/
cp ../../wzemd/WzemdOpengsrv.cpp $SRCROOT/wzemd/

cp ../../wzemd/WzemdOpengcli.h $SRCROOT/wzemd/
cp ../../wzemd/WzemdOpengcli.cpp $SRCROOT/wzemd/

cp ../../wzemd/Wzemd_exe.h $SRCROOT/wzemd/
cp ../../wzemd/Wzemd_exe.cpp $SRCROOT/wzemd/

cp $CMBDSRCROOT/Wzem.h $SRCROOT/wzemd/
cp $CMBDSRCROOT/Wzem.cpp $SRCROOT/wzemd/

cp $CMBDSRCROOT/Root*.h $SRCROOT/wzemd/
cp $CMBDSRCROOT/Root*.cpp $SRCROOT/wzemd/

cp $CMBDSRCROOT/Sess*.h $SRCROOT/wzemd/
cp $CMBDSRCROOT/Sess*.cpp $SRCROOT/wzemd/

cp $CMBDSRCROOT/gbl/*.h $SRCROOT/wzemd/
cp $CMBDSRCROOT/gbl/*.cpp $SRCROOT/wzemd/

cp Makefile_IexWzem $SRCROOT/wzemd/IexWzem/Makefile

cp $CMBDSRCROOT/IexWzem/IexWzem*.h $SRCROOT/wzemd/IexWzem/
cp $CMBDSRCROOT/IexWzem/IexWzem*.cpp $SRCROOT/wzemd/IexWzem/

cp $CMBDSRCROOT/IexWzem/JobWzemIex*.h $SRCROOT/wzemd/IexWzem/
cp $CMBDSRCROOT/IexWzem/JobWzemIex*.cpp $SRCROOT/wzemd/IexWzem/

cp Makefile_VecWzem $SRCROOT/wzemd/VecWzem/Makefile

cp $CMBDSRCROOT/VecWzem/Vec*.h $SRCROOT/wzemd/VecWzem/
cp $CMBDSRCROOT/VecWzem/Vec*.cpp $SRCROOT/wzemd/VecWzem/

cp Makefile_CrdWzemUsg $SRCROOT/wzemd/CrdWzemUsg/Makefile

cp $CMBDSRCROOT/CrdWzemUsg/*.h $SRCROOT/wzemd/CrdWzemUsg/
cp $CMBDSRCROOT/CrdWzemUsg/*.cpp $SRCROOT/wzemd/CrdWzemUsg/

cp Makefile_CrdWzemUsr $SRCROOT/wzemd/CrdWzemUsr/Makefile

cp $CMBDSRCROOT/CrdWzemUsr/*.h $SRCROOT/wzemd/CrdWzemUsr/
cp $CMBDSRCROOT/CrdWzemUsr/*.cpp $SRCROOT/wzemd/CrdWzemUsr/

cp Makefile_CrdWzemPrs $SRCROOT/wzemd/CrdWzemPrs/Makefile

cp $CMBDSRCROOT/CrdWzemPrs/*.h $SRCROOT/wzemd/CrdWzemPrs/
cp $CMBDSRCROOT/CrdWzemPrs/*.cpp $SRCROOT/wzemd/CrdWzemPrs/

cp Makefile_CrdWzemNav $SRCROOT/wzemd/CrdWzemNav/Makefile

cp $CMBDSRCROOT/CrdWzemNav/*.h $SRCROOT/wzemd/CrdWzemNav/
cp $CMBDSRCROOT/CrdWzemNav/*.cpp $SRCROOT/wzemd/CrdWzemNav/

cp Makefile_CrdWzemPrd $SRCROOT/wzemd/CrdWzemPrd/Makefile

cp $CMBDSRCROOT/CrdWzemPrd/*.h $SRCROOT/wzemd/CrdWzemPrd/
cp $CMBDSRCROOT/CrdWzemPrd/*.cpp $SRCROOT/wzemd/CrdWzemPrd/

cp Makefile_CrdWzemEvt $SRCROOT/wzemd/CrdWzemEvt/Makefile

cp $CMBDSRCROOT/CrdWzemEvt/*.h $SRCROOT/wzemd/CrdWzemEvt/
cp $CMBDSRCROOT/CrdWzemEvt/*.cpp $SRCROOT/wzemd/CrdWzemEvt/

cp Makefile_CrdWzemJob $SRCROOT/wzemd/CrdWzemJob/Makefile

cp $CMBDSRCROOT/CrdWzemJob/*.h $SRCROOT/wzemd/CrdWzemJob/
cp $CMBDSRCROOT/CrdWzemJob/*.cpp $SRCROOT/wzemd/CrdWzemJob/

cp Makefile_CrdWzemCal $SRCROOT/wzemd/CrdWzemCal/Makefile

cp $CMBDSRCROOT/CrdWzemCal/*.h $SRCROOT/wzemd/CrdWzemCal/
cp $CMBDSRCROOT/CrdWzemCal/*.cpp $SRCROOT/wzemd/CrdWzemCal/

cp Makefile_CrdWzemCln $SRCROOT/wzemd/CrdWzemCln/Makefile

cp $CMBDSRCROOT/CrdWzemCln/*.h $SRCROOT/wzemd/CrdWzemCln/
cp $CMBDSRCROOT/CrdWzemCln/*.cpp $SRCROOT/wzemd/CrdWzemCln/

cp Makefile_CrdWzemOpx $SRCROOT/wzemd/CrdWzemOpx/Makefile

cp $CMBDSRCROOT/CrdWzemOpx/*.h $SRCROOT/wzemd/CrdWzemOpx/
cp $CMBDSRCROOT/CrdWzemOpx/*.cpp $SRCROOT/wzemd/CrdWzemOpx/

cp Makefile_CrdWzemPst $SRCROOT/wzemd/CrdWzemPst/Makefile

cp $CMBDSRCROOT/CrdWzemPst/*.h $SRCROOT/wzemd/CrdWzemPst/
cp $CMBDSRCROOT/CrdWzemPst/*.cpp $SRCROOT/wzemd/CrdWzemPst/

cp Makefile_CrdWzemNde $SRCROOT/wzemd/CrdWzemNde/Makefile

cp $CMBDSRCROOT/CrdWzemNde/*.h $SRCROOT/wzemd/CrdWzemNde/
cp $CMBDSRCROOT/CrdWzemNde/*.cpp $SRCROOT/wzemd/CrdWzemNde/

