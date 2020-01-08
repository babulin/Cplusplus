#include <iostream>
using namespace std;


//丢出int 类型
void func1() {
	throw 1;
}

//丢出char* 类型
void func2() {
	throw "exception";
}

class MyException {
protected:
	char* m_errMsg;
public:
	MyException(const char* errMsg) {
		//拷贝
		int len = strlen(errMsg) + 1;
		m_errMsg = new char[len];
		//strcpy_s(目标指针,源数据长度,源数据指针)
		strcpy_s(m_errMsg, len, errMsg);
		cout << "MyException()构造函数" << endl;
	}

	//拷贝构造
	MyException(const MyException& ex) {
		//拷贝
		int len = strlen(ex.m_errMsg) + 1;
		m_errMsg = new char[len];
		//strcpy_s(目标指针,源数据长度,源数据指针)
		strcpy_s(m_errMsg, len, ex.m_errMsg);
		cout << "MyException()拷贝构造" << endl;
	}

	~MyException() {
		if (m_errMsg != nullptr)
		{
			delete[] m_errMsg;
			m_errMsg = nullptr;
		}

		cout << "~MyException()析构:error = " << &m_errMsg << endl;
	}

	void show() {
		cout << "异常信息:" << m_errMsg << endl;
	}
};


//丢出对象类型
void func3() {
	//丢出匿名对象 给 e是拷贝构造
	throw MyException("对象异常错误类型");
}

//p29-2-13异常生命周期
int main() {

	try
	{
		func3();
	}
	//catch (MyException e)
	//{
	//	//普通对象
	//	e.show();
	//}
	catch (MyException & e)
	{
		//引用对象
		e.show();
	}
	//catch (MyException * e)
	//{
	//	//引用对象
	//	e->show();
	//}
	
}