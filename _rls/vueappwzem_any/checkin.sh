#!/bin/bash
# file checkin.sh
# checkin script for Wzem Vue.js UI, release vueappwzem_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp AppWzem.vue $REPROOT/wzem/vueappwzem/
cp main.js $REPROOT/wzem/vueappwzem/

cp assets/* $REPROOT/wzem/vueappwzem/assets/
cp ../public/favicon.ico $REPROOT/wzem/vueappwzem/assets/
touch $REPROOT/wzem/vueappwzem/assets/"IP folder --- KEEP"

cp -r components/* $REPROOT/wzem/vueappwzem/

cp -r scripts $REPROOT/wzem/vueappwzem/
