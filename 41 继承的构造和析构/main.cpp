#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	//无参数构造
	A() {
		cout << "A() 构造函数" << endl;
	}

	A(int a) {
		cout << "A(int) 构造函数" << endl;
		m_a = a;
	}

	~A() {
		cout << "~A() 析构函数" << endl;
	}
};

//继承构造 和析构
class B :public A{
private:
	int m_b;
public:
	B(int a,int b):A(a) {
		cout << "B(int,int) 构造函数" << endl;
		m_b = b;
	}

	~B() {
		cout << "~B() 析构函数" << endl;
	}

	void show() {
		cout << "m_b = " << m_b << endl;
	}
};

int main() {

	B b1(10, 20);
	b1.show();
	//顺序是： A()构造 -> B()构造 -> ~B()析构 -> ~A()析构 

}