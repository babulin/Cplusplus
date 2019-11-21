#include <iostream>
#include <memory>//智能指针头文件
using namespace std;

class A
{
public:
	A(int a){
		m_a = a;
		cout << "A()构造函数" << endl;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
	}


	~A()
	{
		cout << "~A()析构函数" << endl;
	}

private:
	int m_a;
};

//自定义智能指针类
class MAutoPtr {
private:
	A* ptr;
public:
	MAutoPtr(A *pA) {
		ptr = pA; //相当于是把对象地址 给了 ptr变量；
	}

	//重构 是某个对象调用
	A* operator->() {
		return ptr;
	}

	//重构 是某个对象调用
	A& operator*() {
		return *ptr;
	}

	~MAutoPtr() {
		if (ptr != NULL)
		{
			delete ptr;
			ptr = NULL;
		}
	}
};



int main() {
	//普通指针
	int* p = new int;
	delete p;

	//智能指针[模板]
	auto_ptr<int> ptr(new int);
	*ptr = 20;//使用 不需要释放，自动释放


	//类普通指针
	A* a1 = new A(10);
	a1->show();
	(*a1).show();
	delete a1;

	//类智能指针
	auto_ptr<A> pa(new A(20));
	pa->show();
	(*pa).show();
	//不需要主动释放

	//自定义智能指针类
	MAutoPtr mPa(new A(100));
	mPa->show();
	(*mPa).show();

	return 0;
}