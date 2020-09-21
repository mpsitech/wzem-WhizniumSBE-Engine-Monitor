#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set REPROOT=${WHIZROOT_CCH}/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_arty
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

