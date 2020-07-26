#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_zedboard(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_zedboard
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

