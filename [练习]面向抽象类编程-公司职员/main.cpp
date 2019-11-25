#include <iostream>
#include "IWoker.h"
#include "Programmer.h"
#include "Saleman.h"
#include "Cto.h"

int main() {

#if 0


	IWoker* woker = new Programmer("����", 160);
	woker->getPay();
	woker->showStatus();
	delete woker;

	cout << endl;

	IWoker* sale = new Saleman("����",2000,200000,0.02);
	sale->setLevel(2);
	sale->getPay();
	sale->showStatus();
	delete sale;

	cout << endl;

	IWoker* cto = new Cto("����",8000,200000,0.01);
	//cto->setLevel(2);
	cto->getPay();
	cto->showStatus();
	delete cto;

#endif // 0

	//ָ������
	IWoker* iwoker[] = {
		new Programmer("����", 160),
		new Saleman("����", 2000, 200000, 0.02),
		new Cto("����", 8000, 200000, 0.01)
	};

	for (int i = 0; i < 3; i++)
	{
		iwoker[i]->setLevel(2);
		iwoker[i]->getPay();
		iwoker[i]->showStatus();
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete iwoker[i];
	}
}