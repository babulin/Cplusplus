#pragma once
#include "Programmer.h"
#include "Saleman.h"

class Cto : public Programmer,public Saleman
{
private:
public:
	Cto(string name,double fixedSalary, double total, double rate);
	~Cto();

	///////////////////////
	//�����ȼ�
	virtual void setLevel(int level);
	//��ȡн��
	virtual void getPay();
	//��ʾԱ����Ϣ
	virtual void showStatus();
};

