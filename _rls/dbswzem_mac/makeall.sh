#!/bin/bash
# file makeall.sh
# make script for Wzem database access library, release dbswzem_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 1 Dec 2020
# IP header --- ABOVE

make DbsWzem.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

