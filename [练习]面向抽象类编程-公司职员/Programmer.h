#pragma once
#include "IWoker.h"
class Programmer : virtual public IWoker
{
protected:
	//�̶�����
	int fixedSalary;

public:
	Programmer();
	Programmer(string name,int fixedSalary);
	~Programmer();

	///////////////////////
	//�����ȼ�
	virtual void setLevel(int level);
	//��ȡн��
	virtual void getPay();
	//��ʾԱ����Ϣ
	virtual void showStatus();

};

