#!/bin/bash
# file remake.sh
# re-make script for Wzem daemon, release wzemd_awsubt
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wzem/_rls/wzemd_awsubt
./checkout.sh

cd $SRCROOT/wzemd

./make.sh "$@"

