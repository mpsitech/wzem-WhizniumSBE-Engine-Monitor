#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wzem/_rls/wzemcmbd_ubuntu
./checkout.sh

cd $BUILDROOT/wzemcmbd

./make.sh "$@"
