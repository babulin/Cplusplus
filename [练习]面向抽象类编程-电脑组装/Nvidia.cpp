#include "Nvidia.h"

Nvidia::Nvidia()
{
	cout << "Nvidia()" << endl;
	model = "Ó¢Î°´ïGTX 960 ti";
}

Nvidia::~Nvidia()
{
	cout << "~Nvidia()" << endl;
}

void Nvidia::showGPU()
{
	cout << "ÏÔ¿¨ÐÍºÅ:" << model << endl;
}
