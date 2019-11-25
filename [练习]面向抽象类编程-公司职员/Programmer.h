#pragma once
#include "IWoker.h"
class Programmer : virtual public IWoker
{
protected:
	//固定工资
	int fixedSalary;

public:
	Programmer();
	Programmer(string name,int fixedSalary);
	~Programmer();

	///////////////////////
	//调整等级
	virtual void setLevel(int level);
	//获取薪资
	virtual void getPay();
	//显示员工信息
	virtual void showStatus();

};

