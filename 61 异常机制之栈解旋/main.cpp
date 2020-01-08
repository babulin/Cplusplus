#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "构造函数~!" << endl;
	}
	~Person() {
		cout << "析构函数~!" << endl;
	}
};


int func1(int a, int b) {

	//当发生异常时，自动析构
	Person p1, p2;

	if (b == 0)
	{
		throw b;
	}

	return a / b;
}

int main() {
	try
	{
		//栈解旋
		//try 语句块内执行的局部变量都会被释放掉
		func1(10, 0);
	}
	catch (int e)
	{
		cout << "异常已被捕获！" << endl;
	}

	cout << "这是后面的代码" << endl;
}