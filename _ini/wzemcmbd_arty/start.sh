#!/bin/bash
# file start.sh
# start script for Wzem combined daemon, release wzemcmbd_arty
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

nohup ./Wzemcmbd -nocp &
disown

