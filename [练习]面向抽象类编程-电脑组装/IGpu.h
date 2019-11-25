#pragma once
#include <iostream>
#include <string>
using namespace std;

class IGpu
{
protected:
	//显卡型号
	string model;
public:
	//虚析构函数：被子类重写
	virtual ~IGpu() {};

	//gpu独有的运行功能
	virtual void showGPU() = 0;
};


