#include "Cto.h"

Cto::Cto(string name, double fixedSalary, double total, double rate)
{
	cout << "Cto()" << endl;
	this->name = name;
	this->fixedSalary = fixedSalary;
	this->totalSales = total;
	this->rate = rate;
}

Cto::~Cto()
{
	cout << "~Cto()" << endl;
}

void Cto::setLevel(int level)
{
	this->level = level;
	switch (this->level)
	{
	case 1:
		this->fixedSalary = 8000;
	case 2:
		this->fixedSalary = 8500;
	default:
		break;
	}
}

void Cto::getPay()
{
	this->salary = fixedSalary + totalSales * rate;
}

//显示员工状态
void Cto::showStatus()
{
	cout << "====================" << endl;
	cout << "id:" << id << endl;
	cout << "姓名:" << name << endl;
	cout << "等级:" << level << endl;
	cout << "固定薪资:" << fixedSalary << endl;
	cout << "销售额:" << totalSales << endl;
	cout << "提成比例:" << rate << endl;
	cout << "月薪:" << salary << endl;
	cout << "====================" << endl;
}