#include "Programmer.h"
Programmer::Programmer()
{
	cout << "Programmer()" << endl;
}
//��ʼ��
Programmer::Programmer(string name, int fixedSalary)
{
	cout << "Programmer()" << endl;
	this->name = name;
	fixedSalary = fixedSalary;
}

//����
Programmer::~Programmer()
{
	cout << "~Programmer()" << endl;
}

//�����ȼ�
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

//���ʼ���
void Programmer::getPay()
{
	this->salary = fixedSalary;
}

//��ʾԱ��״̬
void Programmer::showStatus()
{
	cout << "====================" << endl;
	cout << "id:" << id<< endl;
	cout << "����:" << name << endl;
	cout << "�ȼ�:" << level << endl;
	cout << "��н:" << salary << endl;
	cout << "====================" << endl;
}
