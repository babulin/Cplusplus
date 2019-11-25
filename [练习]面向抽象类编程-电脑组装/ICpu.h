#pragma once
#include <iostream>
#include <string>
using namespace std;

class ICpu
{
protected:
	//cpu型号
	string model;
public:
	//虚析构函数：被子类重写
	virtual ~ICpu() {};

	//cpu独有的运行功能
	virtual void showCPU() = 0;
};

