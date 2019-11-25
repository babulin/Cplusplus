#pragma once
#include "ICpu.h"
#include "IGpu.h"
#include "IMemory.h"

class Computer
{
private:
	//������������������ӿ�
	ICpu* cpu;
	IGpu* graphics;
	IMemory* memory;
public:
	Computer(ICpu* _cpu, IGpu* _graphics, IMemory* _memory);
	~Computer();

	//��ʾ����������Ϣ
	void show();
};

