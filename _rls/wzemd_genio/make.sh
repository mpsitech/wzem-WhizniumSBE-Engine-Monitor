#!/bin/bash
# file make.sh
# make script for Wzem daemon, release wzemd_genio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

make Wzemd.h.gch
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

rm Wzemd.h.gch

