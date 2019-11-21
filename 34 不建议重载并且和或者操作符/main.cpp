#include <iostream>
using namespace std;

class A {
private:
	int m_a;

public:
	A(int a) {
		cout << "A() ���캯��" << endl;
		m_a = a;
	}

	//����&&
	bool operator&&(A& other) {
		cout << "����&&()" << endl;

		if (this->m_a && other.m_a)
		{
			return true;
		}

		return false;
	}

	//����&&
	bool operator||(A& other) {
		cout << "����&&()" << endl;

		if (this->m_a || other.m_a)
		{
			return true;
		}

		return false;
	}

	//����һ����������
	A operator+(A& other) {
		A temp(this->m_a + other.m_a);
		return temp;
	}


};

int main() {

	//�����&&
	int a = 0;
	int b = 20;

	//���� ���ȼ� && a = 0 �Ͳ���ִ�� && ������
	if (a && (a = 10))
	{
		cout << "����Ϊ��" << endl;
	}
	//��������Ϊ a=0
	cout << "a=" << a << endl;

	//�������ж�
	A a1(10);
	A a2(20);
	if (a1 && a2)
	{
		cout << "����&&Ϊ��" << endl;
	}

	A a3(0);
	A a4(20);

	A a5 = (a3 + a4);
	//��������
	/*if (a3 && (a3 + a4))
	{
		cout << "����&&Ϊ��" << endl;
	}*/


	//-----------------------------------------
	//-----------------------------------------

	int ia = 1;
	int ib = 20;

	//���� ���ȼ� ||; a = 1 �Ͳ���ִ�� || ������
	if (ia || (ia = 10))
	{
		cout << "����Ϊ��" << endl;
	}
	//��������Ϊ a=0
	cout << "ia=" << ia << endl;


	//�������ж�
	A aa1(0);
	A aa2(20);
	if (aa1 || aa2)
	{
		cout << "����||Ϊ��" << endl;
	}

	A aa3(0);
	A aa4(20);

	A aa5 = (aa3 + aa4);
	//��������
	/*if (aa3 || (aa3 + aa4))
	{
		cout << "����&&Ϊ��" << endl;
	}*/
}