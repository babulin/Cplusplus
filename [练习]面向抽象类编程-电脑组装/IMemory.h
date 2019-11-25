#pragma once
#include <iostream>
#include <string>
using namespace std;

class IMemory
{
protected:
	//内存条型号
	string model;
public:
	//虚析构函数：被子类重写
	virtual ~IMemory() {};

	//独有的运行功能
	virtual void showMemory() = 0;
};

