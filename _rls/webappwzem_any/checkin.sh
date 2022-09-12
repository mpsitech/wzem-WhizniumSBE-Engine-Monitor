#!/bin/bash
# file checkin.sh
# checkin script for Wzem web-based UI, release webappwzem_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp -r * $REPROOT/wzem/webappwzem/
mv $REPROOT/wzem/webappwzem/favicon.ico $REPROOT/wzem/webappwzem/iconwzem/
touch $REPROOT/wzem/webappwzem/iconwzem/"IP folder --- KEEP"

rm $REPROOT/wzem/webappwzem/checkin.sh
