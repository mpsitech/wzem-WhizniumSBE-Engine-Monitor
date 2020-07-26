#!/bin/bash
# file checkout.sh
# checkout script for Wzem web-based UI, release webappwzem_genio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set WEBROOT=/home/mpsitech/web

mkdir $WEBROOT/appwzem

cp checkin.sh $WEBROOT/appwzem/

cp -r ../../webappwzem/* $WEBROOT/appwzem/

