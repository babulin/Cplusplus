#include <iostream>

using namespace std;

int main(void) {

	const int a = 10;
	const int& re = a;//如果想引用常量，就必须加const

	int b = 20;
	const int& re2 = b;//安全低的可以用安全高的引用
	//re2 = 300;//想用常量引用来修改值是不可能的

	cout << "B:" << b << endl;
	cout << "re2:" << re2 << endl;
	b = 300;
	cout << "B:" << b << endl;
	cout << "re2:" << re2 << endl;//re2本身常量无法修改值，但是它指向的b值改变，就一起改变

	const int& a1 = 40;//常量40 的引用

}