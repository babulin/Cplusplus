#include "Amd.h"
Amd::Amd()
{
	cout << "Amd()" << endl;
	model = "AMD";
}

Amd::~Amd()
{
	cout << "~Amd()" << endl;
}

void Amd::showCPU()
{
	cout << "CPUÐÍºÅ:" << model << endl;
}
