#!/bin/bash
# file remake.sh
# re-make script for Wzem daemon, release wzemd_ungenio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/wzem/_rls/wzemd_ungenio
./checkout.sh

cd $SRCROOT/wzemd

./make.sh "$@"

