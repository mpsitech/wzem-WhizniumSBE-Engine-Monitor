#!/bin/bash
# file makeall.sh
# make script for Wzem API library, release apiwzem_mac
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

make ApiWzem.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

