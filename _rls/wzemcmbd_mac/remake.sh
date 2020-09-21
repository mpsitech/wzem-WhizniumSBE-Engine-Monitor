#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_mac
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set SRCROOT=${WHIZROOT}/src
export set REPROOT=${WHIZROOT}/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_mac
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

