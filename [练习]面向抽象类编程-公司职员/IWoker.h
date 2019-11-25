#pragma once
#include <iostream>
using namespace std;

class IWoker
{
protected:
	string name;//员工名称
	int id;//编号
	double salary;//月薪
	int level;//级别
	
	//员工数量
	static int sNum;
public:
	IWoker();

	//虚析构函数
	virtual ~IWoker() { cout << "~IWoker()" << endl; };

	///////////////////////
	//调整等级
	virtual void setLevel(int level) = 0;
	//获取薪资
	virtual void getPay() = 0;
	//显示员工信息
	virtual void showStatus() = 0;
};

