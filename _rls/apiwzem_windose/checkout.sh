#!/bin/bash
# file checkout.sh
# checkout script for Wzem API library, release apiwzem_windose
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/src

mkdir $SRCROOT/apiwzem

cp makeall.sh $SRCROOT/apiwzem/

cp Makefile $SRCROOT/apiwzem/

cp ../../apiwzem/*.h $SRCROOT/apiwzem/
cp ../../apiwzem/*.cpp $SRCROOT/apiwzem/

