#!/bin/bash
# file make.sh
# make script for Wzem combined daemon, release wzemcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 15 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Wzemcmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWzem" "VecWzem" "CrdWzemNav" "CrdWzemUsg" "CrdWzemUsr" "CrdWzemPrs" "CrdWzemPrd" "CrdWzemEvt" "CrdWzemJob" "CrdWzemCal" "CrdWzemCln" "CrdWzemOpx" "CrdWzemPst" "CrdWzemNde")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j4
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wzemcmbd.h.gch
