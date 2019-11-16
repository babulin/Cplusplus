#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
		cout << "A构造函数" << a << endl;
	}

	//析构
	~A() {
		cout << "A析构函数" << endl;
	}
};


class B {
private:
	//int m_ib = 0; 语法错误[因为没开辟空间]
	//变量只有在初始化赋值
	int m_b;
	int m_int;

	//常量只能在初始化列表初始化
	const int m_const;

	//此处定义类变量顺序是构造函数顺序
	A m_a2;
	A m_a1;
public:
	//构造函数的初始化列表 [引用A类对象，拷贝构造m_a1,m_a2]
	//构造顺序和初始化列表无关;与定义A m_a1,A m_a2的成员变量顺序有关
	//成员变量也可以初始化列表中初始化
	B(A& a1, A& a2, int b):m_int(b),m_const(b),m_a1(a1),m_a2(a2) {
		m_b = b;
		cout << "B构造函数" << endl;
	}

	//构造函数，[对m_a1,m_a2进行有参构造]
	B(int b1, int b2, int b3) :m_a1(b1), m_a2(b2), m_const(b3) {
		m_b = b3;
		cout << "B构造函数" << endl;
	}

	~B() {
		cout << "B析构函数" << endl;
	}
};


int main() {

	//A a1(10),a2(100);

	//B b(a1, a2, 100);

	B b(100, 200, 300);

	A(10);//匿名对象，构造后马上被析构

	A a3 = A(10);//匿名对象转正
}