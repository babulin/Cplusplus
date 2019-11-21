#include <iostream>
using namespace std;

class A {
private:
public:
	int m_a;

	void func() {
		cout << "class A" << endl;
	}
};

//类B 拥有A的成员变量；B has A [类B依赖于类A 耦合度高]
class B {
private:
public:
	A a1;
	void funcB() {
		cout << "class B" << endl;
	}
};

//耦合度：
//高内聚 -- 每个模块最好只干一件事，精准； 
//低耦合 -- 类与类之间的关系越少越好；


//类C 的成员方法，需要类A的形参 ； C use A [耦合度一般]
class C {
private:
public:
	void funcC(A * a) {
		cout << "class B" << endl;
	}

	//该方法完全不需要其他关联
	void funcC2() {
		cout << "class B" << endl;
	}
};

//D类继承A类  D is A [继承耦合度很高]
class D :public A {
public:
	void funcD() {
		cout << m_a << endl;
	}
};


int main() {

}