#include <iostream>
using namespace std;

//函数重载 [1]函数名相同，参数个数，参数类型，参数顺序不同
//[2]返回值并不是构成函数重载的条件

int func(int a,int b) {
	cout << "func1" << endl;
	return 0;
}

//函数重载，[3]不要写默认参数，为了避免调用时产生歧义，函数匹配
//func(10, 10); 产生歧义
char func(int a,int b,int = 0) {
	cout << "func2" << endl;
	return 0;
}

//函数重载：[4]如果参数能隐式转换，也会匹配
void print(int a) {
	cout << "int类型:" << a << endl;
}

#if 1
void print(char a) {
	cout << "char类型:" << a << endl;
}
#endif // 0

int main()
{
	func(10, 10, 0);//可以和func2匹配

	//char 也可以隐式转换成int 所以可以匹配。
	//如果有char 完全匹配，会优先
	print(10);
	print('a');

	cin.get();
}
