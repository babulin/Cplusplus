#include "Kingston.h"

Kingston::Kingston()
{
	cout << "kingston()" << endl;
	model = "金士顿8G";
}

Kingston::~Kingston()
{
	cout << "~kingston()" << endl;
}

void Kingston::showMemory()
{
	cout << "内存条型号:" << model << endl;
}
