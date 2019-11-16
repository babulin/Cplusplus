#include <iostream>

using namespace std;

void getA(int* a)
{
	int b = 30;
	*a = b;
}

int getA1() 
{
	int a = 10;
	return a;
}

char* getA2(int num)
{
	char* p = NULL;
	p = (char*)malloc(num);
	return p;
}

void getA3(char** pp, int num)
{
	char* p = NULL;
	p = (char*)malloc(num);
	*pp = p; //将指针pp指向的值变更为 p指向的值【改变指向】
}

//引用作为返回值，不要返回局部变量引用
int& getA4() {
	int b = 20;
	return b;//返回
}

//静态变量的引用是可以的
int& getA5() {
	static int sa = 10;
	return sa;
}

int main(void) {
	int a = 10;
	char* pp = NULL;
	
	getA(&a);//值传递 指针改变a的值

	a = getA1();//属于值拷贝
	
	pp = getA2(10);//属于指针值拷贝

	getA3(&pp,10);//将指针pp的地址传进去

	int b = 0;
	b = getA4();//b = temp 值拷贝

	int &bre = getA4();//返回局部变量引用后，函数执行完毕被销毁

	cout << bre << endl;
	cout << bre << endl;

	int& sbre = getA5();//返回局部变量引用后，函数执行完毕被销毁

	cout << sbre << endl;
	cout << sbre << endl;

	//如果能返回引用那就可以这样做
	getA5() = 1000;//引用返回的是变量别名
	cout << sbre << endl;
}