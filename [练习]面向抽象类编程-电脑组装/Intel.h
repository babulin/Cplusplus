#pragma once
#include "ICpu.h"
class Intel : public ICpu
{
public:
	Intel();
	~Intel();
	//cpu独有的运行功能
	virtual void showCPU();
};

