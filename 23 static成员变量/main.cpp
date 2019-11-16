#include <iostream>
using namespace std;

//�����ڽ����ڱ��ļ�
static void func() {

}

class A {
private:
	int m_a;
	int m_b;

	//˽�о�̬�ⲿ A::m_const2 �޷�����
	static int m_const2;
public:
	//���о�̬����
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

//��̬������ʼ��
int A::m_const = 0;
//˽�о�̬������ȫ��������Գ�ʼ��
int A::m_const2 = 0;

int main() {

	A a1(1, 2);
	A a2(10, 20);

	cout << "a1.m_const = " << a1.getConst() << endl;
	cout << "a2.m_const = " << a2.getConst() << endl;

	//���Զ������
	a1.m_const = 200;

	//�����
	A::m_const = 200;

	//˽�о�̬�޷��ⲿ���� [���ʾ�̬��Ա����]
	//a1.m_const2
	//A::m_const2
	
	//����Ҳ���Է��ʾ�̬��Ա�������;�̬��Ա����
	cout << "a1.m_const2 = " << a1.getConst2() << endl;
	a1.getConst2() = 200;
	cout << "a2.m_const2 = " << a2.getConst2() << endl;
	A::getConst2() = 300;
	cout << "a2.m_const2 = " << a2.getConst2() << endl;

}