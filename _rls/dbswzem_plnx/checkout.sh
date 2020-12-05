#!/bin/bash
# file checkout.sh
# checkout script for Wzem database access library, release dbswzem_plnx(ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 1 Dec 2020
# IP header --- ABOVE

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build

mkdir $BUILDROOT/dbswzem

cp makeall.sh $BUILDROOT/dbswzem/

cp Makefile $BUILDROOT/dbswzem/

cp ../../dbswzem/DbsWzem.h $BUILDROOT/dbswzem/
cp ../../dbswzem/DbsWzem_vecs.cpp $BUILDROOT/dbswzem/
cp ../../dbswzem/DbsWzem.cpp $BUILDROOT/dbswzem/

cp ../../dbswzem/Wzem*.h $BUILDROOT/dbswzem/
cp ../../dbswzem/Wzem*.cpp $BUILDROOT/dbswzem/

