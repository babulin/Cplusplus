#include "IWoker.h"

//��ʼ����̬����
int IWoker::sNum = 1000;

IWoker::IWoker()
{
	cout << "IWoker()" << endl;
	id = sNum++;
	level = 1;
	salary = 0.0;
}
