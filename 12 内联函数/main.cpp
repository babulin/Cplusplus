#include <iostream>
using namespace std;

//宏函数
#define MAX(a,b) ((a)>(b)?(a):(b))

//先检查语法 编译阶段 展开代码 ，节省压栈出栈开销
//会自动则中选择，代码太多，也不会展开
inline void printA(int a) {
	cout << "a = " << a << endl;
}


int main()
{
	int a = 1;
	for (size_t i = 0; i < 10; i++)
	{
		a++;
		printA(a);
	}

	cout << MAX(a, 20) << endl;

	cin.get();
}
