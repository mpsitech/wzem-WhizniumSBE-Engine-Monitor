#!/bin/bash
# file checkout.sh
# checkout script for Wzem database access library, release dbswzem_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src

mkdir $SRCROOT/dbswzem

cp makeall.sh $SRCROOT/dbswzem/

cp Makefile $SRCROOT/dbswzem/

cp ../../dbswzem/DbsWzem.h $SRCROOT/dbswzem/
cp ../../dbswzem/DbsWzem_vecs.cpp $SRCROOT/dbswzem/
cp ../../dbswzem/DbsWzem.cpp $SRCROOT/dbswzem/

cp ../../dbswzem/Wzem*.h $SRCROOT/dbswzem/
cp ../../dbswzem/Wzem*.cpp $SRCROOT/dbswzem/

