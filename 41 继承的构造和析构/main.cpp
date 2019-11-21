#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	//�޲�������
	A() {
		cout << "A() ���캯��" << endl;
	}

	A(int a) {
		cout << "A(int) ���캯��" << endl;
		m_a = a;
	}

	~A() {
		cout << "~A() ��������" << endl;
	}
};

//�̳й��� ������
class B :public A{
private:
	int m_b;
public:
	B(int a,int b):A(a) {
		cout << "B(int,int) ���캯��" << endl;
		m_b = b;
	}

	~B() {
		cout << "~B() ��������" << endl;
	}

	void show() {
		cout << "m_b = " << m_b << endl;
	}
};

int main() {

	B b1(10, 20);
	b1.show();
	//˳���ǣ� A()���� -> B()���� -> ~B()���� -> ~A()���� 

}