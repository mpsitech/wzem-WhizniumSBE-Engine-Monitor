#!/bin/bash
# file checkout.sh
# checkout script for Wzem Vue.js UI, release vueappwzem_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 21 Apr 2023
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

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

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemUsg

cp ../../vueappwzem/CrdWzemUsg/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemUsg/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemUsr

cp ../../vueappwzem/CrdWzemUsr/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemUsr/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemPrs

cp ../../vueappwzem/CrdWzemPrs/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemPrs/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemNav

cp ../../vueappwzem/CrdWzemNav/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemNav/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemPrd

cp ../../vueappwzem/CrdWzemPrd/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemPrd/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemEvt

cp ../../vueappwzem/CrdWzemEvt/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemEvt/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemJob

cp ../../vueappwzem/CrdWzemJob/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemJob/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemCal

cp ../../vueappwzem/CrdWzemCal/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemCal/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemCln

cp ../../vueappwzem/CrdWzemCln/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemCln/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemOpx

cp ../../vueappwzem/CrdWzemOpx/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemOpx/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemPst

cp ../../vueappwzem/CrdWzemPst/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemPst/

mkdir $WEBROOT/vueappwzem/src/components/CrdWzemNde

cp ../../vueappwzem/CrdWzemNde/*.vue $WEBROOT/vueappwzem/src/components/CrdWzemNde/

mkdir $WEBROOT/vueappwzem/src/scripts

cp ../../vueappwzem/scripts/*.js $WEBROOT/vueappwzem/src/scripts/
