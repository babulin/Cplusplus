#include "Nvidia.h"

Nvidia::Nvidia()
{
	cout << "Nvidia()" << endl;
	model = "Ӣΰ��GTX 960 ti";
}

Nvidia::~Nvidia()
{
	cout << "~Nvidia()" << endl;
}

void Nvidia::showGPU()
{
	cout << "�Կ��ͺ�:" << model << endl;
}
