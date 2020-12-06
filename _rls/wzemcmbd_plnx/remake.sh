#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_plnx(ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wzem/_rls/wzemcmbd_plnx
./checkout.sh

cd $BUILDROOT/wzemcmbd

./make.sh "$@"

