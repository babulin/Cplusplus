#include "Intel.h"
Intel::Intel()
{
	cout << "Intel()" << endl;
	model = "Intel";
}

void Intel::showCPU()
{
	cout << "CPU�ͺ�:" << model << endl;
}

Intel::~Intel()
{
	cout << "~Intel()" << endl;
}


