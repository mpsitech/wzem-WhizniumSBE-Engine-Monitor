#!/bin/bash
# file checkout.sh
# checkout script for Wzem API library, release apiwzem_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src

mkdir $SRCROOT/apiwzem

cp makeall.sh $SRCROOT/apiwzem/

cp Makefile $SRCROOT/apiwzem/

cp ../../apiwzem/*.h $SRCROOT/apiwzem/
cp ../../apiwzem/*.cpp $SRCROOT/apiwzem/

