#!/bin/bash
# file stop.sh
# stop script for Wzem daemon, release wzemd_awsubt
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

pid=$(pgrep Wzemd)
kill -15 $pid

