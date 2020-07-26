#!/bin/bash
# file checkout.sh
# checkout script for Wzem API library, release apiwzem_ssv(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf/root/src

mkdir $SRCROOT/apiwzem

cp makeall.sh $SRCROOT/apiwzem/

cp Makefile $SRCROOT/apiwzem/

cp ../../apiwzem/*.h $SRCROOT/apiwzem/
cp ../../apiwzem/*.cpp $SRCROOT/apiwzem/

