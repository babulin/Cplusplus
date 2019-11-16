#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	A(int a) {
		m_a = a;
		cout << "A���캯��" << a << endl;
	}

	//����
	~A() {
		cout << "A��������" << endl;
	}
};


class B {
private:
	//int m_ib = 0; �﷨����[��Ϊû���ٿռ�]
	//����ֻ���ڳ�ʼ����ֵ
	int m_b;
	int m_int;

	//����ֻ���ڳ�ʼ���б��ʼ��
	const int m_const;

	//�˴����������˳���ǹ��캯��˳��
	A m_a2;
	A m_a1;
public:
	//���캯���ĳ�ʼ���б� [����A����󣬿�������m_a1,m_a2]
	//����˳��ͳ�ʼ���б��޹�;�붨��A m_a1,A m_a2�ĳ�Ա����˳���й�
	//��Ա����Ҳ���Գ�ʼ���б��г�ʼ��
	B(A& a1, A& a2, int b):m_int(b),m_const(b),m_a1(a1),m_a2(a2) {
		m_b = b;
		cout << "B���캯��" << endl;
	}

	//���캯����[��m_a1,m_a2�����вι���]
	B(int b1, int b2, int b3) :m_a1(b1), m_a2(b2), m_const(b3) {
		m_b = b3;
		cout << "B���캯��" << endl;
	}

	~B() {
		cout << "B��������" << endl;
	}
};


int main() {

	//A a1(10),a2(100);

	//B b(a1, a2, 100);

	B b(100, 200, 300);

	A(10);//�������󣬹�������ϱ�����

	A a3 = A(10);//��������ת��
}