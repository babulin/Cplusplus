#include <iostream>
using namespace std;

class A {
public:
	static int m_static;
};
int A::m_static = 100;//全局区域初始化

//继承
class B :public A {

};

//继承
class C :public A {

};

int main() {

	A a1;
	B b1;
	C c1;

	cout << "A::m_static = " << A::m_static << endl;
	cout << "B::m_static = " << B::m_static << endl;
	cout << "C::m_static = " << C::m_static << endl;

	b1.m_static = 200;

	cout << "A::m_static = " << A::m_static << endl;
	cout << "B::m_static = " << B::m_static << endl;
	cout << "C::m_static = " << C::m_static << endl;
	
	c1.m_static = 300;

	cout << "A::m_static = " << A::m_static << endl;
	cout << "B::m_static = " << B::m_static << endl;
	cout << "C::m_static = " << C::m_static << endl;

	//总结，父类的static 所有子类都共用；
}