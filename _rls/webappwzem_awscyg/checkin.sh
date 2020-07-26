#!/bin/bash
# file checkin.sh
# checkin script for Wzem web-based UI, release webappwzem_awscyg
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set REPROOT=/home/Administrator/srcrep

cp -r * $REPROOT/wzem/webappwzem/

rm $REPROOT/wzem/webappwzem/checkin.sh

