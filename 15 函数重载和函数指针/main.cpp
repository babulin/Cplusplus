#include <iostream>
using namespace std;

//其他函数
int func(int a, int b) {
	cout << "func a=" << a << " b=" << b << endl;
	return 0;
}

//[1]定义函数类型
typedef int(MYFUNC)(int, int);

//[2]定义一个函数类型的指针类型
typedef int(*PMYFUNC)(int, int);

//[3]函数指针的重载：参数定义匹配
int func(int a, int b,int c) {
	cout << "func a=" << a << " b=" << b << " c=" << c << endl;
	return 0;
}

int main(void) 
{
	/////////////【1】/////////////
	//该函数类型的变量
	MYFUNC *pfunc;
	pfunc = func;//函数名本身是地址

	pfunc(10, 20);
	(*pfunc)(10, 20);//同理

	/////////////【2】/////////////
	//该函数类型的指针变量
	PMYFUNC pfun = nullptr;
	pfun = func;
	pfun(100,200);

	/////////////【3】/////////////
	//直接定义一个函数指针变量
	int(*fp3)(int, int) = nullptr;
	fp3 = func;
	fp3(101, 102);
	//fp3(1, 2, 3);//不允许的

	/////////////【4】/////////////
	//函数指针定义时参数与函数匹配
	//函数指针赋值时发生函数重载的 参数无法隐式转换，必须完全匹配
	int(*fp4)(int, int, int) = nullptr;
	fp4 = func;
	fp4(1, 2, 3);

	cin.get();
	return 0;
}