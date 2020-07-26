#!/bin/bash
# file stop.sh
# stop script for Wzem combined daemon, release wzemcmbd_awsubt
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

pid=$(pgrep Wzemcmbd)
kill -15 $pid

