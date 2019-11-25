#pragma once
#include "IGpu.h"
class Nvidia : public IGpu
{
public:
	Nvidia();
	~Nvidia();
	virtual void showGPU();
};

