#pragma once
#include <iostream>
#include <string>
using namespace std;

class ICpu
{
protected:
	//cpu�ͺ�
	string model;
public:
	//��������������������д
	virtual ~ICpu() {};

	//cpu���е����й���
	virtual void showCPU() = 0;
};

