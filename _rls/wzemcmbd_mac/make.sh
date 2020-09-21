#!/bin/bash
# file make.sh
# make script for Wzem combined daemon, release wzemcmbd_mac
# author Catherine Johnson
# date created: 21 Sep 2020
# modified: 21 Sep 2020

make Wzemcmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWzem" "VecWzem" "CrdWzemUsg" "CrdWzemUsr" "CrdWzemPrs" "CrdWzemNav" "CrdWzemPrd" "CrdWzemEvt" "CrdWzemJob" "CrdWzemCal" "CrdWzemCln" "CrdWzemOpx" "CrdWzemPst" "CrdWzemNde")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j${NCORE}
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wzemcmbd.h.gch

