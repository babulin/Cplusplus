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

	int getA() const //���ε���thisָ�� [ָ�뱾���� A * const this �����޷����޸�(this++)] ��� const A *const this 
	{
		//��ǰΪ A *const this �޷��޸ı��������ֻ��
		//this->m_a = 200;

		//�ڲ����˶���this
		return this->m_a;
	}

	//��̬��Ա���� ֻ����static��Ա����
	static int getA2() {
		//this->m_a;	//û��this ���Դ���
		//m_a;			//����
		m_const = 100;	
		//ֻ���Է��ʾ�̬��Ա����
		return m_const;
	}
};

//��ʼ��
int A::m_const = 0;

int main() {
	A a1(10);

	cout << "m_a = " << a1.getA() << endl;

	//��Ա����
	cout << "a1::m_const = " << a1.getA2() << endl;

	//��������
	cout << "A::m_const = " << A::getA2() << endl;
}