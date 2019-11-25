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
	//��н=������н+ ���۶�*��ɱ�����
	this->salary = baseSalary + totalSales * rate;
}

//��ʾԱ��״̬
void Saleman::showStatus()
{
	cout << "====================" << endl;
	cout << "id:" << id << endl;
	cout << "����:" << name << endl;
	cout << "�ȼ�:" << level << endl;
	cout << "��н:" << baseSalary << endl;
	cout << "���۶�:" << totalSales << endl;
	cout << "��ɱ���:" << rate << endl;
	cout << "��н:" << salary << endl;
	cout << "====================" << endl;
}
