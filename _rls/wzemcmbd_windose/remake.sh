#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_windose
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/cygdrive/o

cd $REPROOT/wzem/_rls/wzemcmbd_windose
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

