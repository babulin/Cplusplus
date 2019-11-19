#include <iostream>
using namespace std;

class A {
	//friend A operator+(A& a1, A& a2);
private:
	int m_a;
	int m_b;
public:
	A(int a, int b) :m_a(a), m_b(b) {

	}

	void show() {
		cout << "m_a = " << m_a << " m_b = " << m_b << endl;
	}

	//成员函数 友元
	A operator+(A& other) {
		A temp(m_a + other.m_a, m_b + other.m_b);
		return temp;
	}
};

//全局函数 友元
#if 0
A operator+(A& a1, A& a2) {
	A temp(a1.m_a + a2.m_a, a1.m_b + a2.m_b);
	return temp;
}
#endif

int main() {

	A a1(1,2);
	A a2(1,2);

	//=号重载
	//operator+(a1,a2); 全局
	//a1.operator+(a2); 成员
	A a3 = a1 + a2;
	a3.show();

	A a4 = a1.operator+(a2);
	a4.show();

	//等价于(全局)
	//A a4 = operator+(a1,a2);
	//a4.show();

}