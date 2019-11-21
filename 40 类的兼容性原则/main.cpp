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

//好处
void print(A* p) {
	p->showA();
}


int main() {



	//[1]子类可以直接当作A类对象使用；可以直接调用A类方法
	//B b1;
	//b1.showA();
	//b1.showB();

	//A a1;
	//B b1 = a1;//无法父类无法给子类赋值

	//[2]子类可以给父类赋值，因为B类对象继承A对象
	//B b1;
	//A a1 = b1;//可以赋值，但变量不会被覆盖
	//a1.showA();//只能用A类方法

	A* pa = NULL;
	B* pb = NULL;

	A a1(1);
	B b1;

	//pb = &a1;//B类指针 不能存 A类指针
	//pa = &b1;//A类指针 = B类地址
	//pa->showA();//只能用A类方法

	print(&b1);

	//总结：父类 变量，可以用子类赋值；但是赋值后，父类只能调用父类的成员或函数
}