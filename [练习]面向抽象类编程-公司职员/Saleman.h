#pragma once
#include "IWoker.h"
class Saleman : virtual public IWoker
{
protected:
	//底薪
	double baseSalary;
	//销售额
	double totalSales;
	//提成比例
	double rate;
public:
	Saleman();
	Saleman(string name,double baseSalary,double total, double rate);
	~Saleman();
	///////////////////////
	//调整等级
	virtual void setLevel(int level);
	//获取薪资
	virtual void getPay();
	//显示员工信息
	virtual void showStatus();
};

