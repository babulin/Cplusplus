#include "Kingston.h"

Kingston::Kingston()
{
	cout << "kingston()" << endl;
	model = "��ʿ��8G";
}

Kingston::~Kingston()
{
	cout << "~kingston()" << endl;
}

void Kingston::showMemory()
{
	cout << "�ڴ����ͺ�:" << model << endl;
}
