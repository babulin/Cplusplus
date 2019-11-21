#include <iostream>
using namespace std;

class Parent {
private:
	int a;//私有
protected:
	int c;//保护
public:
	int b;//公有

	Parent(int _a,int _b,int _c) {
		this->a = _a;
		this->b = _b;
		this->c = _c;
	}

	int getA() {
		return a;
	}
};

//继承
class Child :public Parent {
public:
	int a;
	Child(int p_a,int p_b,int p_c,int c_a):Parent(p_a, p_b, p_c) {
		this->a = c_a;
	}

	void show() {
		//访问父类private的a 只能通过 public 方法
		cout << "private::a = " << getA() << endl;

		//访问父类public的b 可以使用Parent::b访问
		cout << "public::b = " << Parent::b << endl;

		//访问父类protected的b 可以使用Parent::b访问
		cout << "protected::c = " << Parent::c << endl;

		cout << "Child::a = " << this->a << endl;
	}
};

int main() {

	Child c(10, 20, 30, 40);
	c.show();
}