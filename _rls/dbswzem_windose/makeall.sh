#!/bin/bash
# file makeall.sh
# make script for Wzem database access library, release dbswzem_windose
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

make DbsWzem.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j8
if [ $? -ne 0 ]; then
	exit
fi

make install

