#!/bin/bash
# file checkout.sh
# checkout script for Wzem Vue.js UI, release vueappwzem_yocto
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${SYSROOT}${WHIZROOT}/web

mkdir $WEBROOT/vueappwzem/src

cp checkin.sh $WEBROOT/vueappwzem/src

cp ../../vueappwzem/AppWzem.vue $WEBROOT/vueappwzem/src/
cp ../../vueappwzem/main.js $WEBROOT/vueappwzem/src/

mkdir $WEBROOT/vueappwzem/src/assets

cp ../../vueappwzem/assets/* $WEBROOT/vueappwzem/src/assets/
cp ../../vueappwzem/assets/favicon.ico $WEBROOT/vueappwzem/public/

mkdir $WEBROOT/vueappwzem/src/components

cp ../../vueappwzem/SessWzem.vue $WEBROOT/vueappwzem/src/components/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemStart

cp ../../vueappwzem/CrdWzemStart/CrdWzemStart.vue $WEBROOT/vueappwzem/src/components/CrdWzemStart/

# IP cp.cars --- INSERT

mkdir $WEBROOT/vueappwzem/src/scripts

cp ../../vueappwzem/scripts/*.js $WEBROOT/vueappwzem/src/scripts/
