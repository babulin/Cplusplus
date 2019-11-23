#include <iostream>
using namespace std;

class Base {
public:
	int m;//基类m
};

//虚继承Base [防止子类多继承A类，时出现Base重复成员]
class A : virtual public Base {
public:
	void showA() {
		cout << "A类的showA()" << endl;
	}
};

class B : virtual public Base {
public:
	void showB() {
		cout << "B类的showB()" << endl;
	}
};

//C 多继承A,B
class C : public A, public B {
public:
	void showC() {
		showA();
		showB();
		cout << "C类的showC()" << endl;
	}
};


int main() {
	C c1;
	c1.showC();

	//c1.m = 100;//此时A B 都有m C调用m：不明确
	//c1.A::m = 100;//表示访问A类的m
	//c1.B::m = 100;//表示访问B类的m

	//菱形继承 [虚继承 virtual 防止出现Base重复成员]
	c1.m = 100;//便直接继承 Base 的 m
}