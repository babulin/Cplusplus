#include "Intel.h"
Intel::Intel()
{
	cout << "Intel()" << endl;
	model = "Intel";
}

void Intel::showCPU()
{
	cout << "CPUÐÍºÅ:" << model << endl;
}

Intel::~Intel()
{
	cout << "~Intel()" << endl;
}


