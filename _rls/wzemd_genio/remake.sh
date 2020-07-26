#!/bin/bash
# file remake.sh
# re-make script for Wzem daemon, release wzemd_genio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wzem/_rls/wzemd_genio
./checkout.sh

cd $SRCROOT/wzemd

./make.sh "$@"

