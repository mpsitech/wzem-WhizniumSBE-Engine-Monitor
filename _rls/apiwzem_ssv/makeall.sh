#!/bin/bash
# file makeall.sh
# make script for Wzem API library, release apiwzem_ssv(jack (x86ubt) cross-compilation)
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

make ApiWzem.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j16
if [ $? -ne 0 ]; then
	exit
fi

make install

