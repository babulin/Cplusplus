#include <iostream>
using namespace std;

//可以抛出对象
class MException {
public:
	void show() {
		cout << "对象输出异常错误" << endl;
	}
};
int func1(int a,int b) {

	if (b == 0)
	{
		MException ome;
		throw ome;
		//throw b;//按抛出的类型匹配
	}

	return a / b;
}

void func2(int x,int y) {
	//try
	//{
	//	func1(x, y);
	//}
	//catch (int e)
	//{
	//	cout << "除数不能为" << e << "!" << endl;
	//}

	func1(x, y);
}



int main() {

	//异常捕获，可以逐级向上抛，直至被捕获并处理
	//func2(10, 0);

	try
	{
		func2(10, 0);
	}
	catch (MException e)
	{
		e.show();
		cout << "除数不能为" << "!" << endl;
	}
}