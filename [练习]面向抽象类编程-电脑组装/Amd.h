#pragma once
#include "ICpu.h"
class Amd : public ICpu
{
public:
	Amd();
	~Amd();

	virtual void showCPU();
};

