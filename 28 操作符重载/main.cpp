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

	//��Ա���� ��Ԫ
	A operator+(A& other) {
		A temp(m_a + other.m_a, m_b + other.m_b);
		return temp;
	}
};

//ȫ�ֺ��� ��Ԫ
#if 0
A operator+(A& a1, A& a2) {
	A temp(a1.m_a + a2.m_a, a1.m_b + a2.m_b);
	return temp;
}
#endif

int main() {

	A a1(1,2);
	A a2(1,2);

	//=������
	//operator+(a1,a2); ȫ��
	//a1.operator+(a2); ��Ա
	A a3 = a1 + a2;
	a3.show();

	A a4 = a1.operator+(a2);
	a4.show();

	//�ȼ���(ȫ��)
	//A a4 = operator+(a1,a2);
	//a4.show();

}