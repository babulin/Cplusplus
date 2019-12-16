#include <iostream>
using namespace std;

//方法一 函数类型:  返回值 () (形参个数，类型，顺序)
typedef int(FUNC)(int,int);

//方法二 函数指针:
typedef int(*FUNC_P)(int, int);

//函数
int func1(int a,int b) 
{
	cout << "func1" << endl;
	cout << "a = " << a << ",b = " << b << endl;
	return 0;
}

//函数
int func2(int a, int b)
{
	cout << "func2" << endl;
	cout << "a + b = " << a + b << endl;
	return 0;
}

//函数
int func3(int a, int b)
{
	cout << "func2" << endl;
	cout << "a * b = " << a * b << endl;
	return 0;
}

//函数指针接口
//void iFunc(int(*fp)(int, int),int a,int b) {
void iFunc(FUNC * fp,int a,int b) {
	cout << "固定业务1" << endl;
	fp(a, b);
	cout << "固定业务2" << endl;
}

int main() {

	//方法一
	FUNC* fp1 = NULL;	//定义
	fp1 = func1;		//赋值
	fp1(100, 200);		//调用
	(*fp1)(100, 200);	//等效

	//方法二
	FUNC_P fp2 = NULL;	//定义
	fp2 = func1;		//赋值
	fp2(200, 300);		//调用

	//方法三
	int (*fp3)(int, int) = NULL;	//定义
	fp3 = func1;					//赋值
	fp3(300, 400);					//调用


	cout << "----------------------" << endl;
	//函数指针接口多态
	iFunc(func1, 100, 200);
	iFunc(func2, 300, 400);
	iFunc(func3, 500, 600);
}