#include <iostream>
using namespace std;

class Base {
public:
	int m;//����m
};

//��̳�Base [��ֹ�����̳�A�࣬ʱ����Base�ظ���Ա]
class A : virtual public Base {
public:
	void showA() {
		cout << "A���showA()" << endl;
	}
};

class B : virtual public Base {
public:
	void showB() {
		cout << "B���showB()" << endl;
	}
};

//C ��̳�A,B
class C : public A, public B {
public:
	void showC() {
		showA();
		showB();
		cout << "C���showC()" << endl;
	}
};


int main() {
	C c1;
	c1.showC();

	//c1.m = 100;//��ʱA B ����m C����m������ȷ
	//c1.A::m = 100;//��ʾ����A���m
	//c1.B::m = 100;//��ʾ����B���m

	//���μ̳� [��̳� virtual ��ֹ����Base�ظ���Ա]
	c1.m = 100;//��ֱ�Ӽ̳� Base �� m
}