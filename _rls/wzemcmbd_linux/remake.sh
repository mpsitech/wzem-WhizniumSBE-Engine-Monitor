#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_linux
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${WHIZROOT}/src
export set REPROOT=${WHIZROOT}/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_linux
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

