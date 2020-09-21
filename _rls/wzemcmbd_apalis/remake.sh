#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set REPROOT=${WHIZROOT_CCH}/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_apalis
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

