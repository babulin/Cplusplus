#include <iostream>
using namespace std;
//��Ԫ���ԣ�
//�����ԣ�A����B B����A����
//���ܱ��̳У�A����B��A1�̳�A B���ܷ���A1,B1�̳�B��B1Ҳ���ܷ���A��


//�������û�������

class A {
	//��BΪA�����Ԫ��
	friend class B;
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
	}

	void show() {
		//��Ҫ���з������� ��Ķ���˽�г�Ա ������Ԫ��
		//B ob(10);
		//cout << "B::b=" << ob.m_b << endl;
		cout << "A::a=" << m_a << endl;
	}
};


class B {
	//��AΪB�����Ԫ��
	//friend class A;
private:
	int m_b;
public:
	B(int b) {
		m_b = b;
	}

	void show() {
		//��Ҫ���з������� ��Ķ���˽�г�Ա ������Ԫ��
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