#!/bin/bash
# file start.sh
# start script for Wzem combined daemon, release wzemcmbd_riscv
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

nohup ./Wzemcmbd -nocp &
disown
