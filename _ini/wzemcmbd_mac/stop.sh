#!/bin/bash
# file stop.sh
# stop script for Wzem combined daemon, release wzemcmbd_mac
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

pid=$(pgrep Wzemcmbd)
kill -15 $pid

