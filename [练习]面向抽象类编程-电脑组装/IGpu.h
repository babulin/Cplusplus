#pragma once
#include <iostream>
#include <string>
using namespace std;

class IGpu
{
protected:
	//�Կ��ͺ�
	string model;
public:
	//��������������������д
	virtual ~IGpu() {};

	//gpu���е����й���
	virtual void showGPU() = 0;
};


