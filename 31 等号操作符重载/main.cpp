#include <iostream>
using namespace std;

class A {
private:
	int m_a;
	char name[64];
	char* desc;

public:
	//默认无参数构造
	A() {
		m_a = 0;
		strcpy_s(name, "");//字符串操作
		desc = new char[1];
		strcpy_s(desc, 1, "");
	}

	//有参数构造函数
	A(int a,const char* name, const char* desc) {
		m_a = a;
		strcpy_s(this->name, name);

		int len = strlen(desc) + 1;//还有一个 \0 结束符号
		this->desc = new char[len];
		strcpy_s(this->desc, len, desc);
	}

	//拷贝构造 [指针深拷贝]
	A(const A& other) {
		m_a = other.m_a;
		strcpy_s(this->name, other.name);

		int len = strlen(other.desc) + 1;//还有一个 \0 结束符号
		this->desc = new char[len];
		strcpy_s(this->desc, len, other.desc);
	}

	//等号操作符重载 a3 = a2
	A& operator=(const A& other) {

		//防止自身拷贝
		if (this == &other)
		{
			//对象一样
			return *this;
		}

		//清除垃圾
		if (desc != NULL)
		{
			delete[] desc;
			desc = NULL;
			m_a = 0;
			strcpy_s(name, "");
		}

		//深赋值
		m_a = other.m_a;
		strcpy_s(this->name, other.name);

		int len = strlen(other.desc) + 1;//还有一个 \0 结束符号
		this->desc = new char[len];
		strcpy_s(this->desc, len, other.desc);

		return *this;
	}

	void show() {
		cout << "m_a = " << m_a << endl;
		cout << "name = " << name << endl;
		cout << "desc = " << desc << endl;
	}

	~A() {
		if (desc != NULL)
		{
			delete[] desc;
			desc = NULL;
		}
	}
};

int main() {
	A a1;
	a1.show();

	A a2(10, "张三", "我是一个工人");
	a2.show();

	A a3 = a2;
	a3.show();

	//=号符重载 ，相当于赋值
	A a4(20,"李四","喜欢喝酒");
	A a5(20,"王六","书店老板");
	(a5 = a3) = a4;//返回的是引用 (a5 = a3) (a5 = a4)
	a4.show();

}