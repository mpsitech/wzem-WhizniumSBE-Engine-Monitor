#!/bin/bash
# file checkout.sh
# checkout script for Wzem web-based UI, release webappwzem_yocto
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 15 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${SYSROOT}${WHIZROOT}/web

mkdir $WEBROOT/appwzem

cp checkin.sh $WEBROOT/appwzem/

cp -r ../../webappwzem/* $WEBROOT/appwzem/
