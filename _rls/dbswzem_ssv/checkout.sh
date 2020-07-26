#!/bin/bash
# file checkout.sh
# checkout script for Wzem database access library, release dbswzem_ssv(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf/root/src

mkdir $SRCROOT/dbswzem

cp makeall.sh $SRCROOT/dbswzem/

cp Makefile $SRCROOT/dbswzem/

cp ../../dbswzem/DbsWzem.h $SRCROOT/dbswzem/
cp ../../dbswzem/DbsWzem_vecs.cpp $SRCROOT/dbswzem/
cp ../../dbswzem/DbsWzem.cpp $SRCROOT/dbswzem/

cp ../../dbswzem/Wzem*.h $SRCROOT/dbswzem/
cp ../../dbswzem/Wzem*.cpp $SRCROOT/dbswzem/

