#!/bin/bash
# file checkout.sh
# checkout script for Wzem web-based UI, release webappwzem_ssv
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set WEBROOT=/home/mpsitech/emb/ssv/sysroot-glibc-linaro-2.23-2017.05-arm-linux-gnueabihf/root/web

mkdir $WEBROOT/appwzem

cp checkin.sh $WEBROOT/appwzem/

cp -r ../../webappwzem/* $WEBROOT/appwzem/

