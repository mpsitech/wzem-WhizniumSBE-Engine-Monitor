#!/bin/bash
# file checkout.sh
# checkout script for Wzem database access library, release dbswzem_ungenio
# author Alexander Wirthmueller
# date created: 4 Jun 2020
# modified: 4 Jun 2020

export set SRCROOT=/Users/mpsitech/src

mkdir $SRCROOT/dbswzem

cp makeall.sh $SRCROOT/dbswzem/

cp Makefile $SRCROOT/dbswzem/

cp ../../dbswzem/DbsWzem.h $SRCROOT/dbswzem/
cp ../../dbswzem/DbsWzem_vecs.cpp $SRCROOT/dbswzem/
cp ../../dbswzem/DbsWzem.cpp $SRCROOT/dbswzem/

cp ../../dbswzem/Wzem*.h $SRCROOT/dbswzem/
cp ../../dbswzem/Wzem*.cpp $SRCROOT/dbswzem/

