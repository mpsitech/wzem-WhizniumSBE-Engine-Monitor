#!/bin/bash
# file stop.sh
# stop script for Wzem combined daemon, release wzemcmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 15 Dec 2020
# IP header --- ABOVE

pid=$(pgrep Wzemcmbd)
kill -15 $pid
