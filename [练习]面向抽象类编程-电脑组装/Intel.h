#pragma once
#include "ICpu.h"
class Intel : public ICpu
{
public:
	Intel();
	~Intel();
	//cpu���е����й���
	virtual void showCPU();
};

