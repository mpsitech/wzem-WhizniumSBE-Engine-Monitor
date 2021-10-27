#!/bin/bash
# file start.sh
# start script for Wzem combined daemon, release wzemcmbd_mcv
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 3 May 2021
# IP header --- ABOVE

nohup ./Wzemcmbd -nocp &
disown