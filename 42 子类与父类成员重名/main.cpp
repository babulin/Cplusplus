#include <iostream>
using namespace std;

class Parent {
private:
	int a;//˽��
protected:
	int c;//����
public:
	int b;//����

	Parent(int _a,int _b,int _c) {
		this->a = _a;
		this->b = _b;
		this->c = _c;
	}

	int getA() {
		return a;
	}
};

//�̳�
class Child :public Parent {
public:
	int a;
	Child(int p_a,int p_b,int p_c,int c_a):Parent(p_a, p_b, p_c) {
		this->a = c_a;
	}

	void show() {
		//���ʸ���private��a ֻ��ͨ�� public ����
		cout << "private::a = " << getA() << endl;

		//���ʸ���public��b ����ʹ��Parent::b����
		cout << "public::b = " << Parent::b << endl;

		//���ʸ���protected��b ����ʹ��Parent::b����
		cout << "protected::c = " << Parent::c << endl;

		cout << "Child::a = " << this->a << endl;
	}
};

int main() {

	Child c(10, 20, 30, 40);
	c.show();
}