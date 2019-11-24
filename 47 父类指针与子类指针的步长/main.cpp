#include <iostream>
using namespace std;

//父类简单的类
class Parent {
public:
	int a;
public:
	Parent(int a) {
		this->a = a;
	}

	virtual void show() {
		cout << "Parent::show() a = " << a << endl;
	}
};

//子类继承父类 
class Child : public Parent {
public:
	//增加变量
	int b;
public:
	Child(int a) :Parent(a) {

	}
	virtual void show() {
		cout << "Child::show() a = " << a << endl;
	}
};

int main() {
	
	//此时父类空间与子类空间一样大
	cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
	cout << "sizeof(Child) = " << sizeof(Child) << endl;

	cout << "--------------------------" << endl;

	//构建一个子类对象数组
	Child carr[] = { Child(0),Child(1), Child(2) };

	//子类指针指向子类对象数组
	Child* pc = carr;
	for (int i = 0; i < 3; i++)
	{
		//调用子类重写的函数
		pc->show();
		pc++;
	}

#if 0
	//父类指针指向子类对象数组
	Parent* pp = carr;
	for (int i = 0; i < 3; i++)
	{
		//调用子类重写的函数
		pp->show();
		pp++;
	}

	//此时因为：父类空间 = 子类空间 所以 pp++ ： pp + = sizeof(Parent); pp+=8;
	//如果子类空间与父类不一样，就不能用父类指针遍历子类对象了
#endif // 0

	cout << "--------------------------" << endl;

}