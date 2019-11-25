#pragma once
#include "Programmer.h"
#include "Saleman.h"

class Cto : public Programmer,public Saleman
{
private:
public:
	Cto(string name,double fixedSalary, double total, double rate);
	~Cto();

	///////////////////////
	//调整等级
	virtual void setLevel(int level);
	//获取薪资
	virtual void getPay();
	//显示员工信息
	virtual void showStatus();
};

