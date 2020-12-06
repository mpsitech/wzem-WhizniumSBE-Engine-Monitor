#!/bin/bash
# file checkout.sh
# checkout script for Wzem database access library, release dbswzem_riscv(ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build

mkdir $BUILDROOT/dbswzem

cp makeall.sh $BUILDROOT/dbswzem/

cp Makefile $BUILDROOT/dbswzem/

cp ../../dbswzem/DbsWzem.h $BUILDROOT/dbswzem/
cp ../../dbswzem/DbsWzem_vecs.cpp $BUILDROOT/dbswzem/
cp ../../dbswzem/DbsWzem.cpp $BUILDROOT/dbswzem/

cp ../../dbswzem/Wzem*.h $BUILDROOT/dbswzem/
cp ../../dbswzem/Wzem*.cpp $BUILDROOT/dbswzem/

