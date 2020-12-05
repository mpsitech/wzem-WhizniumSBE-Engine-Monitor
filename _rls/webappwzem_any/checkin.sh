#!/bin/bash
# file checkin.sh
# checkin script for Wzem web-based UI, release webappwzem_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 1 Dec 2020
# IP header --- ABOVE

export set REPROOT=${WHIZDEVROOT}/rep

cp -r * $REPROOT/wzem/webappwzem/

rm $REPROOT/wzem/webappwzem/checkin.sh

