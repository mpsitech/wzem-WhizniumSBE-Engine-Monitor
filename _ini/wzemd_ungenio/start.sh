#!/bin/bash
# file start.sh
# start script for Wzem daemon, release wzemd_ungenio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

nohup ./Wzemd -nocp &
disown

