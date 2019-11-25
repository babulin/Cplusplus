#include "Programmer.h"
Programmer::Programmer()
{
	cout << "Programmer()" << endl;
}
//初始化
Programmer::Programmer(string name, int fixedSalary)
{
	cout << "Programmer()" << endl;
	this->name = name;
	fixedSalary = fixedSalary;
}

//析构
Programmer::~Programmer()
{
	cout << "~Programmer()" << endl;
}

//调整等级
void Programmer::setLevel(int level)
{
	this->level = level;
	switch (this->level)
	{
	case 1:
		fixedSalary = 6000;
	case 2:
		fixedSalary = 6500;
	default:
		break;
	}
}

//工资计算
void Programmer::getPay()
{
	this->salary = fixedSalary;
}

//显示员工状态
void Programmer::showStatus()
{
	cout << "====================" << endl;
	cout << "id:" << id<< endl;
	cout << "姓名:" << name << endl;
	cout << "等级:" << level << endl;
	cout << "月薪:" << salary << endl;
	cout << "====================" << endl;
}
