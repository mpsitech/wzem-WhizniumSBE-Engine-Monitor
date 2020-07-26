#!/bin/bash
# file start.sh
# start script for Wzem combined daemon, release wzemcmbd_genio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

nohup ./Wzemcmbd -nocp &
disown

