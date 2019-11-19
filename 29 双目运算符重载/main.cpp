#include <iostream>
using namespace std;

class A {

private:
	int m_a;

public:
	A(int a) {
		m_a = a;
	}

	//如果要连续 就返回引用！因为不引用就是匿名对象
	A& operator-=(A& a) {
		m_a -= a.m_a;
		return *this;
	}

	A& operator+=(A& a) {
		m_a += a.m_a;
		return *this;
	}

	//默认是前++   ++a
	A& operator++() {
		m_a++;
		return *this;
	}

	//重载的后++   a++
	const A operator++(int) {
		m_a++;
		return *this;
	}

	//默认是前--   --a
	A& operator--() {
		m_a--;
		return *this;
	}

	//重载的后--   a--
	const A operator--(int) {
		m_a--;
		return *this;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
	}


};

int main() {

	A a1(1);
	A a2(5);

	//自然优先级：+= -= 从左往右优先级
	//(a1 += a2) += a2;
	//a1.show();

	//(a1 -= a2) -= a2; //1-5-5 
	//a1.show();

	//++
	int a = 10;
	++a;//可以
	++++a;//可以
	a++;//可以
	//a++++;//不可以 

	//++a1;
	//a1.show();

	//a1++++;
	//a1.show();

	//实现a++++ 不可以的方式
	//a1++;
	//a1.show();

	--a1;
	(--a1).show();

	a1--;
	a1.show();
}