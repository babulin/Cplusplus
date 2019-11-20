#include <iostream>
using namespace std;

class A {
private:
	int m_a;
public:
	A() {
		cout << "A() 构造函数" << endl;
		m_a = 0;
	}

	A(int a) {
		cout << "A(int a) 构造函数" << endl;
		m_a = a;
	}

	//重载new 其实是开辟空间大小 返回万能指针
	void * operator new(size_t size) {
		cout << "调用了new重载" << endl;
 		return malloc(size);
	}

	//重载new[] 还是使用的malloc 空间大小
	void* operator new[](size_t size) {
		cout << "调用了new重载" << endl;
		return malloc(size);
	}

	//重载delete 其实是开辟空间大小 返回万能指针
	void operator delete(void * p) {
		cout << "调用了delete重载" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}

	//重载delete 其实是开辟空间大小 返回万能指针
	void operator delete[](void* p) {
		cout << "调用了delete重载" << endl;
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
	}

	~A() {
		cout << "~A() 析构函数" << endl;
	}
};


int main() {

	//总结： 重载new操作 -> 构造函数 -> 析构函数 -> 重载delete操作符

	A* a3 = new A[5];//a3->operator new[](sizeof(A[5]));A[5] 大小
	delete[] a3;
	

	//会先调重载，在调构造
	A* a2 = new A(5);//a2->operator new(sizeof(A)); A的大小
	delete a2;
}