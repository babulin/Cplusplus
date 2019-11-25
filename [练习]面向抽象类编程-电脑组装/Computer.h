#pragma once
#include "ICpu.h"
#include "IGpu.h"
#include "IMemory.h"

class Computer
{
private:
	//电脑依赖三个抽象类接口
	ICpu* cpu;
	IGpu* graphics;
	IMemory* memory;
public:
	Computer(ICpu* _cpu, IGpu* _graphics, IMemory* _memory);
	~Computer();

	//显示电脑配置信息
	void show();
};

