#include "Saleman.h"

Saleman::Saleman()
{
	cout << "Saleman()" << endl;
}

Saleman::Saleman(string name, double baseSalary,double total,double rate)
{
	cout << "Saleman()" << endl;
	this->name = name;
	this->baseSalary = baseSalary;
	this->totalSales = total;
	this->rate = rate;
}

Saleman::~Saleman()
{
	cout << "~Saleman()" << endl;
}

void Saleman::setLevel(int level)
{
	this->level = level;

	switch (this->level)
	{
	case 1:
		this->baseSalary = 2000;
	case 2:
		this->baseSalary = 2500;
	default:
		break;
	}
}

void Saleman::getPay()
{
	//月薪=基本底薪+ 销售额*提成比例；
	this->salary = baseSalary + totalSales * rate;
}

//显示员工状态
void Saleman::showStatus()
{
	cout << "====================" << endl;
	cout << "id:" << id << endl;
	cout << "姓名:" << name << endl;
	cout << "等级:" << level << endl;
	cout << "底薪:" << baseSalary << endl;
	cout << "销售额:" << totalSales << endl;
	cout << "提成比例:" << rate << endl;
	cout << "月薪:" << salary << endl;
	cout << "====================" << endl;
}
