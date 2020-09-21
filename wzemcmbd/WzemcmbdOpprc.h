/**
	* \file WzemcmbdOpprc.h
	* operation processor for Wzem combined daemon (declarations)
	* \author Catherine Johnson
	* \date created: 21 Sep 2020
	* \date modified: 21 Sep 2020
	*/

#ifndef WZEMCMBDOPPRC_H
#define WZEMCMBDOPPRC_H

/**
	* WzemcmbdOpprc
	*/
namespace WzemcmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

