#pragma once
#include "IWoker.h"
class Saleman : virtual public IWoker
{
protected:
	//��н
	double baseSalary;
	//���۶�
	double totalSales;
	//��ɱ���
	double rate;
public:
	Saleman();
	Saleman(string name,double baseSalary,double total, double rate);
	~Saleman();
	///////////////////////
	//�����ȼ�
	virtual void setLevel(int level);
	//��ȡн��
	virtual void getPay();
	//��ʾԱ����Ϣ
	virtual void showStatus();
};

