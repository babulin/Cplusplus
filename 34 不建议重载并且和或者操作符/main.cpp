#include <iostream>
using namespace std;

class A {
private:
	int m_a;

public:
	A(int a) {
		cout << "A() 构造函数" << endl;
		m_a = a;
	}

	//重载&&
	bool operator&&(A& other) {
		cout << "重载&&()" << endl;

		if (this->m_a && other.m_a)
		{
			return true;
		}

		return false;
	}

	//重载&&
	bool operator||(A& other) {
		cout << "重载&&()" << endl;

		if (this->m_a || other.m_a)
		{
			return true;
		}

		return false;
	}

	//返回一个匿名对象
	A operator+(A& other) {
		A temp(this->m_a + other.m_a);
		return temp;
	}


};

int main() {

	//常规的&&
	int a = 0;
	int b = 20;

	//这里 优先级 && a = 0 就不会执行 && 后面了
	if (a && (a = 10))
	{
		cout << "这里为真" << endl;
	}
	//所以这里为 a=0
	cout << "a=" << a << endl;

	//对象并且判断
	A a1(10);
	A a2(20);
	if (a1 && a2)
	{
		cout << "对象&&为真" << endl;
	}

	A a3(0);
	A a4(20);

	A a5 = (a3 + a4);
	//不允许了
	/*if (a3 && (a3 + a4))
	{
		cout << "对象&&为真" << endl;
	}*/


	//-----------------------------------------
	//-----------------------------------------

	int ia = 1;
	int ib = 20;

	//这里 优先级 ||; a = 1 就不会执行 || 后面了
	if (ia || (ia = 10))
	{
		cout << "这里为真" << endl;
	}
	//所以这里为 a=0
	cout << "ia=" << ia << endl;


	//对象并且判断
	A aa1(0);
	A aa2(20);
	if (aa1 || aa2)
	{
		cout << "对象||为真" << endl;
	}

	A aa3(0);
	A aa4(20);

	A aa5 = (aa3 + aa4);
	//不允许了
	/*if (aa3 || (aa3 + aa4))
	{
		cout << "对象&&为真" << endl;
	}*/
}