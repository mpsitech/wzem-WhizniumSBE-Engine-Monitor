#!/bin/bash
# file checkout.sh
# checkout script for Wzem web-based UI, release webappwzem_zedboard
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set WEBROOT=/home/mpsitech/emb/zedboard/avnet-digilent-zedboard-2017.2/build/tmp/sysroots/plnx_arm/home/root/web

mkdir $WEBROOT/appwzem

cp checkin.sh $WEBROOT/appwzem/

cp -r ../../webappwzem/* $WEBROOT/appwzem/

