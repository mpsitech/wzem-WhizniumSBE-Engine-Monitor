#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_jack
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_jack
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

