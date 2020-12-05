#!/bin/bash
# file stop.sh
# stop script for Wzem combined daemon, release wzemcmbd_ubuntu_mpsi
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 1 Dec 2020
# IP header --- ABOVE

pid=$(pgrep Wzemcmbd)
kill -15 $pid

