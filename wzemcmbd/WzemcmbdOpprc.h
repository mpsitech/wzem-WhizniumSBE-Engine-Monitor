/**
	* \file WzemcmbdOpprc.h
	* operation processor for Wzem combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 4 Jun 2020
	* \date modified: 4 Jun 2020
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

