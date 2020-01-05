#include <iostream>
using namespace std;

template <class T>
class Person {
public:
	static int s_A;
};

//类模板静态变量全局声明
template<class T> int Person<T>::s_A = 0;

int main() {

	Person<int> p1, p2;
	Person<char> c1, c2;

	//根据类模板生成 2个不同的类，分别存在static s_A;
	p1.s_A = 10;
	c1.s_A = 100;
	cout << "p1:" << p1.s_A << " p2:" << p2.s_A << endl;
	cout << "c1:" << c1.s_A << " c2:" << c2.s_A << endl;
}