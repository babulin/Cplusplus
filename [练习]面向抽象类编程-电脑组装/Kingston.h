#pragma once
#include "IMemory.h"
class Kingston : public IMemory
{
public:
	Kingston();
	~Kingston();

	virtual void showMemory();
};

