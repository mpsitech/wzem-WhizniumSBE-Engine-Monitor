#!/bin/bash
# file checkin.sh
# checkin script for Wzem web-based UI, release webappwzem_arty
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set REPROOT=${WHIZROOT_CCH}/srcrep

cp -r * $REPROOT/wzem/webappwzem/

rm $REPROOT/wzem/webappwzem/checkin.sh

