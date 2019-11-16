#include <iostream>
using namespace std;

//作用于仅限于本文件
static void func() {

}

class A {
private:
	int m_a;
	int m_b;

	//私有静态外部 A::m_const2 无法访问
	static int m_const2;
public:
	//共有静态变量
	static int m_const;

	A(int a,int b) {
		m_a = a;
		m_b = b;
	}

	int getConst() {
		m_const++;
		return m_const;
	}

	static int& getConst2() {
		m_const2++;
		return m_const2;
	}
};

//静态变量初始化
int A::m_const = 0;
//私有静态变量，全局区域可以初始化
int A::m_const2 = 0;

int main() {

	A a1(1, 2);
	A a2(10, 20);

	cout << "a1.m_const = " << a1.getConst() << endl;
	cout << "a2.m_const = " << a2.getConst() << endl;

	//可以对象访问
	a1.m_const = 200;

	//类访问
	A::m_const = 200;

	//私有静态无法外部访问 [访问静态成员函数]
	//a1.m_const2
	//A::m_const2
	
	//对象也可以访问静态成员变量，和静态成员函数
	cout << "a1.m_const2 = " << a1.getConst2() << endl;
	a1.getConst2() = 200;
	cout << "a2.m_const2 = " << a2.getConst2() << endl;
	A::getConst2() = 300;
	cout << "a2.m_const2 = " << a2.getConst2() << endl;

}