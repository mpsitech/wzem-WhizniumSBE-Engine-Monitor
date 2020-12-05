#!/bin/bash
# file checkout.sh
# checkout script for Wzem API library, release apiwzem_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 1 Dec 2020
# IP header --- ABOVE

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/apiwzem

cp makeall.sh $BUILDROOT/apiwzem/

cp Makefile $BUILDROOT/apiwzem/

cp ../../apiwzem/*.h $BUILDROOT/apiwzem/
cp ../../apiwzem/*.cpp $BUILDROOT/apiwzem/

