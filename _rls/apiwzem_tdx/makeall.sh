#!/bin/bash
# file makeall.sh
# make script for Wzem API library, release apiwzem_tdx (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 21 Apr 2023
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make ApiWzem.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install
