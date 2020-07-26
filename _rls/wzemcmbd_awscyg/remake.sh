#!/bin/bash
# file remake.sh
# re-make script for Wzem combined daemon, release wzemcmbd_awscyg
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/Administrator/src
export set REPROOT=/home/Administrator/srcrep

cd $REPROOT/wzem/_rls/wzemcmbd_awscyg
./checkout.sh

cd $SRCROOT/wzemcmbd

./make.sh "$@"

