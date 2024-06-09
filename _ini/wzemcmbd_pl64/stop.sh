#!/bin/bash
# file stop.sh
# stop script for Wzem combined daemon, release wzemcmbd_pl64
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 21 Apr 2023
# IP header --- ABOVE

pid=$(pgrep Wzemcmbd)
kill -15 $pid
