#include <iostream>
using namespace std;

class A {
private:
	int ma;
public:
	A(int a) {
		ma = a;
	}

	virtual void show() {
		cout << "A::show() ma = " << ma << endl;
	}

	void showII() {
		cout << "A::showII()" << endl;
	}
};

class B :public A {
private:
	int mb;
public:
	B(int a,int b):A(a) {
		mb = b;
	}

	//��д���ຯ��
	virtual void show() {
		cout << "B::show() mb = " << mb << endl;
	}

	//�ض��常�ຯ��
	void showII() {
		cout << "B::showII()" << endl;
	}

	//����showII();
	void showII(int a) {
		cout << "B::showII(int) a = " << a << endl;
	}
};

class C :public B {
private:
	int mc;
public:
	C(int a,int b,int c) :B(a,b){
		mc = c;
	}

	virtual void show() {
		cout << "C::show() ma = " << mc << endl;
	}

	void showII() {
		cout << "C::showII()" << endl;
	}
};

int main() {
	
	//����ָ�� �����������ʱ
	//���ຯ������д����������ຯ��
	A* pp = new B(10,20);
	pp->show();
	pp->A::show();

	//C�� Ҳ��д���麯��
	C* ppp = new C(10, 20, 30);
	ppp->show();
	ppp->B::show();
	ppp->A::show();

	//pp->A::show();
}