#!/bin/bash
# file checkout.sh
# checkout script for Wzem API library, release apiwzem_mcv (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 3 May 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build

mkdir $BUILDROOT/apiwzem

cp makeall.sh $BUILDROOT/apiwzem/

cp Makefile $BUILDROOT/apiwzem/

cp ../../apiwzem/*.h $BUILDROOT/apiwzem/
cp ../../apiwzem/*.cpp $BUILDROOT/apiwzem/