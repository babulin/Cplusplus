#include <iostream>
using namespace std;
//友元特性：
//单向性（A声明B B访问A），
//不能被继承（A声明B，A1继承A B不能访问A1,B1继承B，B1也不能访问A）


//交叉引用会有问题

class A {
	//类B为A类的友元类
	friend class B;
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
	}

	void show() {
		//需要类中访问其他 类的对象私有成员 声明友元类
		//B ob(10);
		//cout << "B::b=" << ob.m_b << endl;
		cout << "A::a=" << m_a << endl;
	}
};


class B {
	//类A为B类的友元类
	//friend class A;
private:
	int m_b;
public:
	B(int b) {
		m_b = b;
	}

	void show() {
		//需要类中访问其他 类的对象私有成员 声明友元类
		A oa(10);
		cout << "A::a=" << oa.m_a << endl;
		cout << "B::b=" << m_b << endl;
	}
};

int main() {

	A a1(100);
	a1.show();

	B b1(200);
	b1.show();

}