#pragma once
#include <iostream>
using namespace std;

class IWoker
{
protected:
	string name;//Ա������
	int id;//���
	double salary;//��н
	int level;//����
	
	//Ա������
	static int sNum;
public:
	IWoker();

	//����������
	virtual ~IWoker() { cout << "~IWoker()" << endl; };

	///////////////////////
	//�����ȼ�
	virtual void setLevel(int level) = 0;
	//��ȡн��
	virtual void getPay() = 0;
	//��ʾԱ����Ϣ
	virtual void showStatus() = 0;
};

