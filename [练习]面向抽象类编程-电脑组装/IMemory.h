#pragma once
#include <iostream>
#include <string>
using namespace std;

class IMemory
{
protected:
	//�ڴ����ͺ�
	string model;
public:
	//��������������������д
	virtual ~IMemory() {};

	//���е����й���
	virtual void showMemory() = 0;
};

