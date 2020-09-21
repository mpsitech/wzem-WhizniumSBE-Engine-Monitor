#!/bin/bash
# file makeall.sh
# make script for Wzem database access library, release dbswzem_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

make DbsWzem.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install
