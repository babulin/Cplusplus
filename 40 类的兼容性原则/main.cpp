#include <iostream>
using namespace std;

class A {
private:
	int m_int = 1;
public:
	A(int i) {
		m_int = i;
	}

	void showA() {
		cout << m_int << endl;
	}
};

class B :public A{
private:
	int m_int = 2;
public:
	B() :A(10){

	}
	void showB() {
		cout << m_int << endl;
	}
};

//�ô�
void print(A* p) {
	p->showA();
}


int main() {



	//[1]�������ֱ�ӵ���A�����ʹ�ã�����ֱ�ӵ���A�෽��
	//B b1;
	//b1.showA();
	//b1.showB();

	//A a1;
	//B b1 = a1;//�޷������޷������ำֵ

	//[2]������Ը����ำֵ����ΪB�����̳�A����
	//B b1;
	//A a1 = b1;//���Ը�ֵ�����������ᱻ����
	//a1.showA();//ֻ����A�෽��

	A* pa = NULL;
	B* pb = NULL;

	A a1(1);
	B b1;

	//pb = &a1;//B��ָ�� ���ܴ� A��ָ��
	//pa = &b1;//A��ָ�� = B���ַ
	//pa->showA();//ֻ����A�෽��

	print(&b1);

	//�ܽ᣺���� ���������������ำֵ�����Ǹ�ֵ�󣬸���ֻ�ܵ��ø���ĳ�Ա����
}