#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_ssv(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf/root/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_ssv
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

