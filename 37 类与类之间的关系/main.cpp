#include <iostream>
using namespace std;

class A {
private:
public:
	int m_a;

	void func() {
		cout << "class A" << endl;
	}
};

//��B ӵ��A�ĳ�Ա������B has A [��B��������A ��϶ȸ�]
class B {
private:
public:
	A a1;
	void funcB() {
		cout << "class B" << endl;
	}
};

//��϶ȣ�
//���ھ� -- ÿ��ģ�����ֻ��һ���£���׼�� 
//����� -- ������֮��Ĺ�ϵԽ��Խ�ã�


//��C �ĳ�Ա��������Ҫ��A���β� �� C use A [��϶�һ��]
class C {
private:
public:
	void funcC(A * a) {
		cout << "class B" << endl;
	}

	//�÷�����ȫ����Ҫ��������
	void funcC2() {
		cout << "class B" << endl;
	}
};

//D��̳�A��  D is A [�̳���϶Ⱥܸ�]
class D :public A {
public:
	void funcD() {
		cout << m_a << endl;
	}
};


int main() {

}