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

//��ʾԱ��״̬
void Cto::showStatus()
{
	cout << "====================" << endl;
	cout << "id:" << id << endl;
	cout << "����:" << name << endl;
	cout << "�ȼ�:" << level << endl;
	cout << "�̶�н��:" << fixedSalary << endl;
	cout << "���۶�:" << totalSales << endl;
	cout << "��ɱ���:" << rate << endl;
	cout << "��н:" << salary << endl;
	cout << "====================" << endl;
}