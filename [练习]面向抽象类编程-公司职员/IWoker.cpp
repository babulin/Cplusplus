#include "IWoker.h"

//初始化静态变量
int IWoker::sNum = 1000;

IWoker::IWoker()
{
	cout << "IWoker()" << endl;
	id = sNum++;
	level = 1;
	salary = 0.0;
}
