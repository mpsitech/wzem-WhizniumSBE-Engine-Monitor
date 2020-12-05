#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 1 Dec 2020
# IP header --- ABOVE

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wzem/_rls/wzemcmbd_ubuntu
./checkout.sh

cd $BUILDROOT/wzemcmbd

./make.sh "$@"
