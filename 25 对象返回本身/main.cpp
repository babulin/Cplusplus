#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
	}

	//���ص�ǰ���ö��������
	A& add(int a) {
		m_a += a;
		return *this;
	}

	//���ص�ǰ���ö����ָ��
	A* add2(int a) {
		m_a += a;
		return this;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
	}
};

int main() {
	//����
	A a1(10);
	a1.add(1).add(1);
	a1.show();

	//ָ��
	A* a2 = new A(10);
	a2->add2(1)->add2(1);
	a2->show();

	delete a2;
}