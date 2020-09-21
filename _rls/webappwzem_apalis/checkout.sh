#!/bin/bash
# file checkout.sh
# checkout script for Wzem web-based UI, release webappwzem_apalis
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

export set WEBROOT=${SYSROOT}${WHIZROOT}/web

mkdir $WEBROOT/appwzem

cp checkin.sh $WEBROOT/appwzem/

cp -r ../../webappwzem/* $WEBROOT/appwzem/

