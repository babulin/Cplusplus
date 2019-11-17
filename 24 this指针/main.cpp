#include <iostream>
using namespace std;

class A {
private:
	int m_a;
	static int m_const;
public:
	A(int a) {
		this->m_a = a;
	}

	int getA() const //修饰的是this指针 [指针本身是 A * const this 本身无法被修改(this++)] 变成 const A *const this 
	{
		//当前为 A *const this 无法修改变量，变成只读
		//this->m_a = 200;

		//内部用了对象this
		return this->m_a;
	}

	//静态成员函数 只返回static成员变量
	static int getA2() {
		//this->m_a;	//没有this 所以错误
		//m_a;			//错误
		m_const = 100;	
		//只可以访问静态成员变量
		return m_const;
	}
};

//初始化
int A::m_const = 0;

int main() {
	A a1(10);

	cout << "m_a = " << a1.getA() << endl;

	//成员调用
	cout << "a1::m_const = " << a1.getA2() << endl;

	//类名调用
	cout << "A::m_const = " << A::getA2() << endl;
}